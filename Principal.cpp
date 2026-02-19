#include "iostream"
using namespace std;
#include "Veterinario.h"


Utilitarios util;

void mnuVeterinario(){
	int opcion;
	Veterinario veterinario;
	do{
	system("cls");	 
    util.gotoxy(23,8);
	cout<<"Mantenimiento de Veterinario";
    util.gotoxy(25,10);
	cout<<"1. Agregar veterinario";
    util.gotoxy(25,11);
	cout<<"2. Buscar veterinario"<<endl;
	util.gotoxy(25,12);
	cout<<"3. Modificar veterinario"<<endl;
    util.gotoxy(25,13);
	cout<<"4. Eliminar veterinario"<<endl;
    util.gotoxy(25,14);
	cout<<"5. Listar veterinario"<<endl;
    util.gotoxy(25,15);
	cout<<"6. Regresar ";
	cin>>opcion;
	switch(opcion){
		case 1: veterinario.agregarVeterinario(); break; 
		case 2: veterinario.buscarVeterinario(); break;
		case 3: veterinario.modificarVeterinario(); break; 
		case 4: veterinario.eliminarVeterinario(); break;
		case 5: veterinario.listarVeterinario(); break;
	}
	}while(opcion<5);
}


int main(){
	
  int opcion;
  do{
	
	 system("cls");
	 util.gotoxy(18,8);
	 cout<<"Sistema de Citas de la Veterinaria NOMBRE :/";
	 util.gotoxy(25,10);
	 cout<<"1. Mantenimiento de Veterinarios";
	 util.gotoxy(25,11);
	 cout<<"2. Mantenimiento de paquetes"<<endl;
	 util.gotoxy(25,12);
	 cout<<"3. Facturación"<<endl;
	 util.gotoxy(25,13);
	 cout<<"4. Salir ";
     cin>>opcion;
	 switch(opcion){
		case 1: mnuVeterinario();break;
		//case 2: mnuPaquetes();break;
		//case 3: mnuCita();break;
	 }
  }while (opcion <4);
  return 0;
}

