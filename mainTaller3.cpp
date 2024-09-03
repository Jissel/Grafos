#include <iostream>
#include <stdlib.h>
#include "Nodo.h"
#include "Lista.h"
#include "Grafo.h"
#include "Nodo_ady.h"
#include "Nodo_vert.h"

using namespace std;
using std::string;
int n,m,i;
string vertice1,vertice2;
Lista<string> sol;
Grafo<string> G1;
  
void imprimir(Lista<string>&sol){
	int pos = 0;
		while(sol.esvacia()){
		cout<<sol.consultar(pos+1)<<", "<<endl;
		}
	}
void dfs(string vert, Lista<string> &sol){
	Lista<string> suce;
	string w;
	G1.sucesores(vert,suce);
	int i = 0;
	
	while(suce.esvacia()){
		w=suce.consultar(1);
		suce.eliminar(1);
		if(sol.localizar(w)==0){ 
		sol.insertar(i+1,w);
		dfs(w,sol);
		}
	}
}

int main(int argc, char *argv[])
{	
  do{
		cin>>n;
		cin>>m;
		for(i=1;i<=m;i++){
			cin>>vertice1;
			cin>>vertice2;
		
			if(G1.existe_vertice(vertice1)){
			G1.agregar_vertice(vertice1);}
			
			if(G1.existe_vertice(vertice2)){
			G1.agregar_vertice(vertice2);}
			
			if(G1.existe_arco(vertice1,vertice2)){
			G1.agregar_arco(vertice1,vertice2);}
			
			}
			dfs(vertice1,sol);
			imprimir(sol);
		}while(n!=0&&m!=0);
		
	return EXIT_SUCCESS;
}
