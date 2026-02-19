#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#ifndef UTILITARIOS_H
  #include "Utilitarios.h"
#endif
#ifndef VETERINARIO_H
  #include "Veterinario.h"
#endif
using namespace std;

class Cita
{
private:
  int numCita = 0;
  char fecha[12] = "";
  char hora[7] = "";
  double precio = 0.0;
  Veterinario veterinario;

public:
  int tam = sizeof(Cita) / 2 - 20;

  Cita getRegistroCita(int numCita)
  {
    fstream _archivo("Cita.dat", ios::out | ios::in | ios::binary);
    Cita aux;
    if (_archivo.is_open())
    {
      _archivo.seekg((numCita - 1) * sizeof(Cita));
      _archivo.read((char *)&aux, sizeof(Cita));
      _archivo.close();
    }
    return aux;
  }

  void verificarExiste()
  {
    fstream archivo("Cita.dat", ios::out | ios::in | ios::binary);
    if (!archivo.is_open())
    {
      fopen("Cita.dat", "w");
    }
  }

  void agregarCita()
  {
    system("cls");
    Veterinario veterinario;
    Utilitarios util;
    int codigo, numCita, fecha, hora, precio;
    util.dibujarRaya(3, 3, 75);
    util.gotoxy(4, 4);
    verificarExiste();
    cout << "Cita";
    util.dibujarRaya(3, 5, 75);
    util.gotoxy(4, 6);
    cout << "Escriba codigo del veterinario para la cita (0 para salir): ";
    cin >> codigo;
    Veterinario veterinario;
    veterinario = obtenerVeterinario(codigo);
    util.gotoxy(4, 7);
    if (veterinario.codigoVet == 0)
    {
      return;
    }
    else
    {
      util.limpiarLinea(4, 4, 80);
      util.gotoxy(4, 8);
      cout << "Veterinario: [" << veterinario.codigoVet << "] Nombre: [" << veterinario.nombre
           << " " << veterinario.apellido1 << " " << veterinario.apellido2 << "]";
    }
    util.gotoxy(4, 9);
    cout << "Digite el número de Cita: ";
    cin >> numCita;
    Cita cita;
    cita = getRegistroCita(numCita);

    if (cita.numCita > 0 && cita.fecha != "" && cita.hora != "")
    { // el registro fue encontrado
      util.gotoxy(4, 22);
      cout << "La Cita " << cita.numCita
           << " con fecha " << cita.fecha << " y hora " << cita.hora <<" ya existe ";
      util.gotoxy(4, 23);
      
      system("pause");
    }
    else
    {
      cin.ignore();
      int fila = 13;
      util.dibujarRaya(3, 10, 75);
      util.gotoxy(4, 11);
      cout << "Código";
      util.gotoxy(20, 11);
      cout << "Fecha";
      util.gotoxy(40, 11);
      cout << "Hora";
      util.gotoxy(50, 11);
      cout << "Precio";
      util.dibujarRaya(3, 12, 75);
      int i = 0;
      do
      {
        util.gotoxy(4, fila);
        cin >> codigo;
        if (codigo == 99)
        {
          try
          {
            fstream archivo("Cita.dat", ios::out | ios::in | ios::binary);
            if (archivo.is_open())
            {
              archivo.seekp((cita.numCita - 1) * sizeof(cita));
              archivo.write((char *)&cita, sizeof(cita));
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

      } while (codigo > 0);   
  }
}};
