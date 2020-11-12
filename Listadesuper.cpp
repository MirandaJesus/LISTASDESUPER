#include <iostream>     //Jesus Miranda Moreno :*
#include <stdlib.h>
#include<string>
#include<iomanip>
using namespace std;
 
struct nodo{
       string Noarticulo;//Lista de super
       int cantidad; //cantidad de porciones
       bool falta(); //faltante de articulos
	   	   struct nodo *sgte;
};
 
typedef struct nodo *Tlista;
 
void HacerlistaI(Tlista &lista,string art, int can)
{
    Tlista q;
    q = new(struct nodo);
    q->Noarticulo = art;
    q->cantidad = can;
    q->sgte = lista;
    lista  = q;
}
 
void Hacerlistaf(Tlista &lista, string art, int can)
{
    Tlista t, q = new(struct nodo);
 
    q->Noarticulo = art;
    q->cantidad = can;
    q->sgte = lista;
    q->sgte = NULL;
 
    if(lista==NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
    }
 
}

bool falta(Tlista lista)
{
	if(lista->cantidad < 10){
		return true;
	}
	return false;
}

void reportarLista(Tlista lista)
{
     int i = 0;
 	cout<< "+---------------------------+---------------------------+\n";
     while(lista != NULL)
     {
          cout << "|" <<"Articulo"<< i+1 <<": " << left << setw(16)<< lista->Noarticulo << "|Cantidad: "<< setw(21)<<lista->cantidad<< endl;
          lista = lista->sgte;
          i++;
     }
     cout<< "+---------------------------+---------------------------+\n";
}

void reportarFaltante(Tlista lista)
{
int i = 0;
cout<< "+---------------------------+---------------------------+\n";

 while(lista != NULL){
		{if(falta(lista)){
		
          cout << "|" <<"Articulo"<< i+1 <<": "<< left << setw(16)<< lista->Noarticulo << "|Faltante: "<< setw(21)<<10-lista->cantidad  << endl;
          lista = lista->sgte;
          i++;
     }}}
cout<< "+---------------------------+---------------------------+\n";
}

void menu1()
{
    cout<<"\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. INSERTAR AL INICIO               "<<endl;
    cout<<" 2. INSERTAR AL FINAL                "<<endl;
    cout<<" 3. REPORTAR LISTA                   "<<endl;
    cout<<" 4. REPORTAR FALTANTE                "<<endl;
    cout<<" 8. SALIR                            "<<endl;

    cout<<"\n INGRESE OPCION: ";
}
 
/*                        Funcion Principal
---------------------------------------------------------------------*/
 
int main()
{
    Tlista lista = NULL;
    int op;     // opcion del menu
    string _dato;    //elemento a ingresar
    int _dato2;  // elemenento a ingresar
 
    system("color 0b");
 
    do
    {
        menu1();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n Articulo: ";
				fflush(stdin); 
				getline(cin,_dato);
                 fflush(stdin);
                 cout<< "\n Cantidad: "; cin>> _dato2;
                 HacerlistaI(lista, _dato,_dato2);
            break;
 
 
            case 2:
 
                 cout<< "\n Articulo: ";
                 fflush(stdin);
				  getline(cin,_dato);
                 cout<< "\n Cantidad: "; cin>> _dato2;
                 Hacerlistaf(lista, _dato,_dato2 );
            break;
 
 
            case 3:
 
                 cout << "\n\n MOSTRANDO LISTA\n\n";
                 reportarLista(lista);
            break;

            case 4:
 
                 cout << "\n\n MOSTRANDO FALTANTE DE LISTA\n\n";
                 reportarFaltante(lista);
            break;			 
		}
		
        cout<<endl<<endl;
        system("pause"); system("cls");
 
    }while(op!=8);
 
 
   system("pause");
   return 0;
}
