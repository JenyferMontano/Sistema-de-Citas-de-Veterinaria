#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
// #ifndef UTILITARIOS_H
//   #include "Utilitarios.h"
// #endif

using namespace std;

class Paquetes: public Utilitarios
{
  public:
    int idPaquete = 0;
    char descripcion[20] = "";
    double precioGramo=0.0;

  Paquetes(){}
  Utilitarios util;
  int tam = sizeof(Paquetes) / 2 - 20;

  Paquetes getRegistro(int idPaquete)
  {
    fstream _archivo("Paquetes.dat", ios::out | ios::in | ios::binary);
    Paquetes aux;
    if (_archivo.is_open())
    {
      _archivo.seekg((idPaquete - 1) * sizeof(Paquetes));
      _archivo.read((char *)&aux, sizeof(Paquetes));
      _archivo.close();
    }
    return aux;
  }
  void verificarExiste()
  {
    fstream archivo("Paquetes.dat", ios::out | ios::in | ios::binary);
    if (!archivo.is_open())
    {
      fopen("Paquetes.dat", "w");
    }
  }
  void agregarPaquete()
  {
    system("cls");
    Paquetes paquete;
    int paqueteId;
    util.dibujarRaya(3, 3, 75);
    util.gotoxy(4, 4);
    verificarExiste();
    cout << "Inclusion de Paquetes";
    util.dibujarRaya(3, 5, 75);
    util.gotoxy(4, 6);
    cout << "Escriba codigo del Paquete (0 para salir): ";
    cin >> paqueteId;
    util.gotoxy(4, 7);
    if (paqueteId == 0)
    {
      return;
    }
    paquete = getRegistro(paqueteId);

    if (paquete.idPaquete != 0)
    { // el registro fue encontrado
      util.gotoxy(4, 21);
      cout << "El Paquete " << paquete.descripcion << " ya existe ";
      util.gotoxy(4, 23);
      system("pause");
    }
    else
    {
      paquete.idPaquete = paqueteId;
      fflush(stdin);
      cout << "Escriba una descripcion del paquete: ";
      cin.getline(paquete.descripcion, 20);
      cout << endl;
      util.gotoxy(4, 8);
      cout << "Escriba precio del gramo del paquete: ";
      cin >> paquete.precioGramo;
      try
      {
        fstream archivo("Paquetes.dat", ios::out | ios::in | ios::binary);
        if (archivo.is_open())
        {
          archivo.seekp((paquete.idPaquete - 1) * sizeof(paquete));
          archivo.write((char *)&paquete, sizeof(paquete));
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
    cout << "Listado de Paquetes";
    util.dibujarRaya(4, 5, 95);
    util.gotoxy(5, 6);
    cout << "ID PAQUETE";
    util.gotoxy(17, 6);
    cout << "DESCRIPCION";
    util.gotoxy(37, 6);
    cout << "PRECIO GRAMO";
    util.dibujarRaya(4, 7, 95);
  }
  void listarPaquetes()
  {
    system("cls");
    int fila = 8;
    titulos();
    ifstream archivo("Paquetes.dat");
    Paquetes paquete;
    if (archivo.is_open())
    {
      archivo.read((char *)&paquete, sizeof(paquete));
      while (!archivo.eof())
      {
        if (paquete.idPaquete != 0)
        {
          util.gotoxy(5, fila);
          cout << paquete.idPaquete;
          util.gotoxy(17, fila);
          cout << paquete.descripcion; 
          util.gotoxy(37, fila);
          cout << paquete.precioGramo;
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
        archivo.read((char *)&paquete, sizeof(paquete));
      }
      archivo.close();
    }
    util.dibujarRaya(4, fila, 95);
    util.gotoxy(tam, fila + 1);
    cout << "----Fin del listado----";
    util.gotoxy(4, fila + 2);
    system("pause");
  }
  void buscarPaquete()
  {
    Paquetes paquete;
    system("cls");
    util.dibujarRaya(3, 3, 75);
    util.gotoxy(4, 4);
    cout << "Busqueda de Producto";
    util.dibujarRaya(3, 5, 75);
    util.gotoxy(4, 6);
    cout << "Escriba código del paquete a buscar (0 para salir): ";
    cin >> paquete.idPaquete;
    util.gotoxy(4, 7);
    if (paquete.idPaquete == 0)
    {
      return;
    }
    cin.ignore();
    Paquetes estAux = getRegistro(paquete.idPaquete);
    if (estAux.idPaquete != 0)
    { // el registro fue encontrado
      util.gotoxy(4, 8);
      cout << "Id Paquete: " << estAux.idPaquete;
      util.gotoxy(4, 9);
      cout << "Descripcion: " << estAux.descripcion; 
      util.gotoxy(4, 10);
      cout << "Precio del gramo: " << estAux.precioGramo;
    }
    else
    {
      util.gotoxy(4, 21);
      cout << "El paquete no se encuentra registrado!!";
    }
    util.gotoxy(4, 23);
    system("pause");
  }

  void modificarPaquete()
  {
    Paquetes paquete;
    system("cls");
    util.dibujarRaya(3, 3, 75);
    util.gotoxy(4, 4);
    cout << "Modificacion de paquete";
    util.dibujarRaya(3, 5, 75);
    util.gotoxy(4, 6);
    cout << "Escriba código del paquete a modificar (0 para salir): ";
    cin >> paquete.idPaquete;
    if (paquete.idPaquete == 0)
    {
      return;
    }
    cin.ignore();
    Paquetes estAux = getRegistro(paquete.idPaquete);
    if (estAux.idPaquete != 0)
    {
      paquete.idPaquete = estAux.idPaquete;
      fflush(stdin);
      util.gotoxy(4, 7);
      cout << "Escriba la nueva descripcion para " << estAux.descripcion
           << " [ENTER] para no modificarlo: ";
      cin.getline(paquete.descripcion, 20);
      if (strlen(paquete.descripcion) == 0)
      {
        strcpy(paquete.descripcion, estAux.descripcion);
        util.limpiarLinea(4, 7, 80);
        util.gotoxy(4, 7);
        cout << "Descripción anterior: " << estAux.descripcion<<endl
             << ". Nueva descripción: " << paquete.descripcion;
      }
      util.gotoxy(4, 8);
      cout << "Escriba nuevo precio por gramo: " << estAux.precioGramo;
      cin >> paquete.precioGramo; 
      if (paquete.precioGramo > 0)
      {
        util.limpiarLinea(4, 8, 80);
        util.gotoxy(4, 8);
        cout << "Precio por gramo anterior: " << estAux.precioGramo 
             << ". Nuevo precio por gramo: " << paquete.precioGramo;
      }
 
      try
      {
        fstream archivo("Paquetes.dat", ios::out | ios::in | ios::binary);
        if (archivo.is_open())
        {
          archivo.seekp((paquete.idPaquete - 1) * sizeof(paquete));
          archivo.write((char *)&paquete, sizeof(paquete));
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
      cout << "El Producto no se encuentra registrado!!";

      util.gotoxy(4, 23);
      system("pause");
    }
  }
  void eliminar(int paqueteId)
  {
    fstream archivo("Paquetes.dat", ios::out | ios::in | ios::binary);
    Paquetes aux;
    if (archivo.is_open())
    {
      archivo.seekg((paqueteId - 1) * sizeof(aux));
      archivo.write((char *)&aux, sizeof(Paquetes));
      archivo.close();
    }
  }

  void eliminarPaquete()
  {
    Paquetes paquete;
    system("cls");
    util.dibujarRaya(3, 3, 75);
    util.gotoxy(4, 4);
    cout << "Eliminacion registro de Paquete";
    util.dibujarRaya(3, 5, 75);
    util.gotoxy(4, 6);
    cout << "Escriba codigo del paquete a eliminar (0 para salir): ";
    cin >> paquete.idPaquete;
    if (paquete.idPaquete == 0)
    {
      return;
    }
    Paquetes estAux = getRegistro(paquete.idPaquete);
    if (estAux.idPaquete != 0)
    { // el registro fue encontrado
      char resp = 'N';
      util.gotoxy(4, 12);
      cout << "¿Esta seguro de eliminar el registro de "
           << estAux.descripcion << " ? S/N ";
      cin >> resp;
      if (toupper(resp) == 'S')
      {
        eliminar(estAux.idPaquete);
        util.gotoxy(4, 18);
        cout << "El registro del paquete "
             << estAux.descripcion << " fue eliminado!";
      }
      else
      {
        util.gotoxy(4, 18);
        cout << "El registro del paquete "
             << estAux.descripcion << " NO fue eliminado!";
      }
    }
    else
    {
      util.gotoxy(4, 18);
      cout << "El registro del Producto no existe! ";
    }
    util.gotoxy(4, 20);
    system("pause");
  }
};
