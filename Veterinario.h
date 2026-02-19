#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#ifndef UTILITARIOS_H
  #include "Utilitarios.h"
#endif

using namespace std;

class Veterinario
{
  public:
    int  codigoVet = 0;
    char nombre[20] = "";
    char apellido1[20] = "";
    char apellido2[20] = "";
    char telefono[10] = "";

  Veterinario(){}
  Utilitarios util;
  int tam = sizeof(Veterinario) / 2 - 20;
  Veterinario obtenerVeterinario(int codigo)
  {
    fstream _archivo("veterinario.dat", ios::out | ios::in | ios::binary);
    Veterinario aux;
    if (_archivo.is_open())
    {
      _archivo.seekg((codigo - 1) * sizeof(aux));
      _archivo.read((char *)&aux, sizeof(Veterinario));
      _archivo.close();
    }
    return aux;
  }

  void verificarExiste()
  {
    fstream archivo("Veterinario.dat", ios::out | ios::in | ios::binary);
    if (!archivo.is_open())
    {
      fopen("Veterinario.dat", "w");
    }
  }
  void agregarVeterinario()
  {
    system("cls");
    Veterinario veterinario;
  
    int codigo;
    util.dibujarRaya(3, 3, 75);
    util.gotoxy(4, 4);
    verificarExiste();
    cout << "Inclusion de Veterinarios";
    util.dibujarRaya(3, 5, 75);
    util.gotoxy(4, 6);
    cout << "Escriba codigo del Veterinario (0 para salir): ";
    cin >> codigo;
    util.gotoxy(4, 7);
    if (codigo == 0)
    {
      return;
    }
    veterinario = obtenerVeterinario(codigo);

    if (veterinario.codigoVet != 0)
    { // el registro fue encontrado
      util.gotoxy(4, 21);
      cout << "El Veterinario " << veterinario.nombre
           << " " << veterinario.apellido1 << " " << veterinario.apellido2 << " ya existe ";
      util.gotoxy(4, 23);
      system("pause");
    }
    else
    {
      veterinario.codigoVet
 = codigo;
      fflush(stdin);
      cout << "Escriba nombre del veterinario: ";
      cin.getline(veterinario.nombre, 20);
      cout << endl;
      util.gotoxy(4, 8);
      cout << "Escriba apellido 1 del veterinario: ";
      cin.getline(veterinario.apellido1, 20);
      cout << endl;
      util.gotoxy(4, 9);
      cout << "Escriba apellido 2 del veterinario: ";
      cin.getline(veterinario.apellido2, 20);
      cout << endl;
      util.gotoxy(4, 10);
      cout << "Escriba telefono del veterinario: ";
      cin.getline(veterinario.telefono, 10);
      cout << endl;

      try
      {
        fstream archivo("Veterinario.dat", ios::out | ios::in | ios::binary);
        if (archivo.is_open())
        {
          archivo.seekp((veterinario.codigoVet
     - 1) * sizeof(veterinario));
          archivo.write((char *)&veterinario, sizeof(veterinario));
          archivo.close();
          util.gotoxy(4, 21);
          cout << "El registro fue exitosamente agregado!";
          util.gotoxy(4, 23);
          system("pause");
        }
        else
        {
          util.gotoxy(4, 21);
          cout << "El archivo no pudo ser abierto!";

          util.gotoxy(4, 23);
          system("pause");
          return;
        }
      }
      catch (string x)
      {
        util.gotoxy(4, 21);
        cout << "Ocurrio un error en el proceso " << x;
        util.gotoxy(4, 23);
        system("pause");
      }
    }
  }
  void titulos()
  {
    util.dibujarRaya(4, 3, 95);
    util.gotoxy(tam, 4);
    cout << "Listado de Veterinarios";
    util.dibujarRaya(4, 5, 95);
    util.gotoxy(5, 6);
    cout << "CODIGO";
    util.gotoxy(17, 6);
    cout << "NOMBRE";
    util.gotoxy(37, 6);
    cout << "APELLIDO 1";
    util.gotoxy(50, 6);
    cout << "APELLIDO 2";
    util.gotoxy(65, 6);
    cout << "TELEFONO";
    util.dibujarRaya(4, 7, 95);
  }
  void listarVeterinario()
  {
    system("cls");
    int fila = 8;
    titulos();
    ifstream archivo("Veterinario.dat");
    Veterinario veterinario;
    if (archivo.is_open())
    {
      archivo.read((char *)&veterinario, sizeof(veterinario));
      while (!archivo.eof())
      {
        if (veterinario.codigoVet
   != 0)
        {
          util.gotoxy(5, fila);
          cout << veterinario.codigoVet
    ;
          util.gotoxy(17, fila);
          cout << veterinario.nombre;
          util.gotoxy(37, fila);
          cout << veterinario.apellido1;
          util.gotoxy(50, fila);
          cout << veterinario.apellido2;
          util.gotoxy(65, fila);
          cout << veterinario.telefono;
          fila++;
          if (fila == 20)
          {
            util.dibujarRaya(4, 20, 95);
            util.gotoxy(4, 21);
            cout << "Final de pagina, ENTER para ir a la siguiente!";
            util.gotoxy(4, 23);
            system("pause");
            system("cls");
            titulos();
            fila = 8;
          }
        }
        archivo.read((char *)&veterinario, sizeof(veterinario));
      }
      archivo.close();
    }
    util.dibujarRaya(4, fila, 95);
    util.gotoxy(tam, fila + 1);
    cout << "----Fin del listado----";
    util.gotoxy(4, fila + 2);
    system("pause");
  }
  void buscarVeterinario()
  {
    Veterinario veterinario;
    system("cls");
  util.dibujarRaya(3, 3, 75);
  util.gotoxy(4, 4);
    cout << "Busqueda del Veterinario";
    util.dibujarRaya(3, 5, 75);
    util.gotoxy(4, 6);
    cout << "Escriba código del veterinario a buscar (0 para salir): ";
    cin >> veterinario.codigoVet;
    util.gotoxy(4, 7);
    if (veterinario.codigoVet == 0)
    {
      return;
    }
    cin.ignore();
    Veterinario estAux = obtenerVeterinario(veterinario.codigoVet);
    if (estAux.codigoVet != 0)
    { // el registro fue encontrado
      util.gotoxy(4, 8);
      cout << "Código: " << estAux.codigoVet
;
      util.gotoxy(4, 9);
      cout << "Nombre: " << estAux.nombre;
      util.gotoxy(4, 10);
      cout << "Apellidos: " << estAux.apellido1 << " " << estAux.apellido2;
      util.gotoxy(4, 11);
      cout << "Telefono: " << estAux.telefono;
    }
    else
    {
      util.gotoxy(4, 21);
      cout << "El veterinario no se encuentra registrado!!";
    }
    util.gotoxy(4, 23);
    system("pause");
  }

  void modificarVeterinario(){
    Veterinario veterinario;
    system("cls");
    util.dibujarRaya(3, 3, 75);
    util.gotoxy(4, 4);
    cout << "Modificacion de Veterinario";
    util.dibujarRaya(3, 5, 75);
    util.gotoxy(4, 6);
    cout << "Escriba código del veterinario a modificar (0 para salir): ";
    cin >> veterinario.codigoVet;
    if (veterinario.codigoVet == 0)
    {
      return;
    }
    cin.ignore();
    Veterinario estAux = obtenerVeterinario(veterinario.codigoVet);
    if (estAux.codigoVet != 0)
    {
      veterinario.codigoVet
 = estAux.codigoVet
;
      fflush(stdin);
      util.gotoxy(4, 7);
      cout << "Escriba nuevo nombre para " << estAux.nombre
           << " [ENTER] para no modificarlo: ";
      cin.getline(veterinario.nombre, 20);
      if (strlen(veterinario.nombre) == 0)
      {
        strcpy(veterinario.nombre, estAux.nombre);
        util.limpiarLinea(4, 7, 80);
        util.gotoxy(4, 7);
        cout << "Nombre anterior: " << estAux.nombre
             << ". Nuevo nombre: " << veterinario.nombre;
      }
      util.gotoxy(4, 8);
      cout << "Escriba nuevo apellido 1 para " << estAux.apellido1
           << " [ENTER] para no modificarlo: ";
      cin.getline(veterinario.apellido1, 20);
      
      if (strlen(veterinario.apellido1) == 0)
      {
        strcpy(veterinario.apellido1, estAux.apellido1);
        util.limpiarLinea(4, 8, 80);
        util.gotoxy(4, 8);
        cout << "Apellido 1 anterior: " << estAux.apellido1
             << ". Nuevo apellido 1: " << veterinario.apellido1;
      }
       util.gotoxy(4, 9);
      cout << "Escriba nuevo apellido 2 para " << estAux.apellido2
           << " [ENTER] para no modificarlo: ";
      cin.getline(veterinario.apellido2, 20);
      cout << endl;
      if (strlen(veterinario.apellido2) == 0)
      {
        strcpy(veterinario.apellido2, estAux.apellido2);
        util.limpiarLinea(4, 9, 80);
        util.gotoxy(4, 9);
        cout << "Apellido 2 anterior: " << estAux.apellido2
             << ". Nuevo apellido 1: " << veterinario.apellido2;
      }
      util.gotoxy(4, 10);
      cout << "Escriba nuevo telefono para " << estAux.telefono
           << " [ENTER] para no modificarlo: ";
      cin.getline(veterinario.telefono, 10);
      cout << endl;
      if (strlen(veterinario.telefono) == 0)
      {
        strcpy(veterinario.telefono, estAux.telefono);
        util.limpiarLinea(4, 10, 80);
        util.gotoxy(4, 10);
        cout << "Telefono anterior: " << estAux.telefono
             << ". Nuevo apellido 1: " << veterinario.telefono;
      }
      try
      {
        fstream archivo("Veterinario.dat", ios::out | ios::in | ios::binary);
        if (archivo.is_open())
        {
          archivo.seekp((veterinario.codigoVet
     - 1) * sizeof(veterinario));
          archivo.write((char *)&veterinario, sizeof(veterinario));
          archivo.close();
          util.gotoxy(4, 21);
          cout << "El registro fue exitosamente modificado!";
          util.gotoxy(4, 23);
          system("pause");
        }
        else
        {
          util.gotoxy(4, 21);
          cout << "El archivo no pudo ser abierto!";
          util.gotoxy(4, 23);
          system("pause");
          return;
        }
      }
      catch (string x)
      {
        util.gotoxy(4, 21);
        cout << "Ocurrio un error en el proceso " << x;
        util.gotoxy(4, 23);
        system("pause");
 
      }
    }

    else
    {
      util.gotoxy(4, 21);
      cout << "El veterinario no se encuentra registrado!!";

      util.gotoxy(4, 23);
      system("pause");
    }
  }
  void eliminar(int codigo)
  {
    fstream archivo("Veterinario.dat", ios::out | ios::in | ios::binary);
    Veterinario aux;
    if (archivo.is_open())
    {
      archivo.seekg((codigo - 1) * sizeof(aux));
      archivo.write((char *)&aux, sizeof(Veterinario));
      archivo.close();
    }
  }

  void eliminarVeterinario()
  {
    Veterinario veterinario;
    system("cls");
    util.dibujarRaya(3, 3, 75);
    util.gotoxy(4, 4);
    cout << "Eliminacion registro de Cliente";
    util.dibujarRaya(3, 5, 75);
    util.gotoxy(4, 6);
    cout << "Escriba codigo del Cliente a eliminar (0 para salir): ";
    cin >> veterinario.codigoVet;
    if (veterinario.codigoVet == 0)
    {
      return;
    }
   Veterinario estAux = obtenerVeterinario(veterinario.codigoVet);

    if (estAux.codigoVet != 0)
    { // el registro fue encontrado
      char resp = 'N';
      util.gotoxy(4, 12);
      cout << "¿Esta seguro de eliminar el registro de "
           << estAux.nombre << " " << estAux.apellido1
           << " " << estAux.apellido2 << " ? S/N ";
      cin >> resp;
      if (toupper(resp) == 'S')
      {
        eliminar(estAux.codigoVet
  );
        util.gotoxy(4, 18);
        cout << "El registro del Veterinario "
             << estAux.nombre << " " << estAux.apellido1 << " "
             << estAux.apellido2 << " fue eliminado!";
      }
      else
      {
        util.gotoxy(4, 18);
        cout << "El registro del Veterinario "
             << estAux.nombre << " " << estAux.apellido1 << " "
             << estAux.apellido2 << " NO fue eliminado!";
      }
    }
    else
    {
      util.gotoxy(4, 18);
      cout << "El registro del Veterinario no existe! ";
    }
    util.gotoxy(4, 20);
    system("pause");
  }
};
