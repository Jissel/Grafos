#ifndef GRAFO_H_
#define GRAFO_H_
#include "Nodo_vert.h"
#include "Lista.h"
#include <iostream>


using namespace std;

template<class vertice >
class Grafo
{
     private:
        Nodo_vert<vertice> *g;
         int orden;
       public:
         Grafo();
	     ~Grafo();
	     void set_g(Nodo_vert<vertice>*a);
	     Nodo_vert<vertice>* get_g();
	     bool es_vacio();
	     bool existe_vertice(vertice v);
	     bool existe_arco(vertice v, vertice w);
         float costo_arco(vertice v, vertice w);
         int orden_grafo();
         void predecesores(vertice v,Lista<vertice>&b);
         void sucesores(vertice v,Lista<vertice> &c);
		 void vertices(Lista<vertice> &vert);
         void agregar_vertice(vertice v);
	     void agregar_arco(vertice v, vertice w, float cost);// pre: existe(v) , existe(w);***
         void agregar_arco(vertice v, vertice w);
         void eliminar_vertice(vertice v);
         void eliminar_arco(vertice v, vertice w);// pre: existe(v) , existe(w);***
};

/////////////////// IMPLEMENTACION//////////////////////////////

// constructor
template< class vertice>
Grafo<vertice>::Grafo()
{
	orden=0;
     g=NULL;
}


template< class vertice>
Grafo<vertice>::~Grafo()
{
    Nodo_vert<vertice> *antv,*p;
	Nodo_ady<vertice> *anta,*k;
	     	    
	       p=get_g();
	       antv=p;
	       while(p!=NULL)
		          {
					    k=p->get_ady();
					    anta=k;
					    while(k!=NULL )
					         {  
                                 anta=k;
								 k=k->get_proxady();
								 delete anta;
							}
							 
							
					     antv=p;
					     p=p->get_proxvert();
				   	     delete antv;
				  } 
}






// set_g()
template< class vertice>
void Grafo<vertice>:: set_g(Nodo_vert<vertice> *a)
{
   g=a;
}


// get_g()
template<class vertice>
Nodo_vert<vertice>* Grafo<vertice>::get_g()
{
   return g;
}


//es_vacio()
template<class vertice>
bool Grafo<vertice>::es_vacio()
{
    if(g==NULL) {  return true; }
	   
	   else {return false;}
}

//existe_vertice(vertice v)
template<class vertice>
bool Grafo<vertice>::existe_vertice(vertice v)
{
     Nodo_vert<vertice>*k;
     
	k=get_g();
	
	while(k!=NULL && k->get_infovert()!=v )
	     {
		       k=k->get_proxvert();
		 }
		 
		 if(k!=NULL && k->get_infovert()==v) 
		 	
		 {
			 return true;
			 }
		   
		    else{return false;}
}


//existe_arco(vertice v, vertice w)
template<class vertice>
bool Grafo<vertice>::existe_arco(vertice v,vertice w)
{
	   Nodo_vert<vertice>*k;
	   Nodo_ady<vertice>*p;
       k=get_g();
	
	while(k!=NULL && k->get_infovert()!=v )
	     {
		       k=k->get_proxvert();
		 }
       
		 if(k!=NULL && k->get_infovert()==v)
		 {
			 p=k->get_ady();
			 
			 while(p!=NULL && p->get_infoady()!=w)
			      {
					  p=p->get_proxady();
					  
				   }
			 
			      if(p!=NULL && p->get_infoady()==w) {
					  return true;
					  } else{
					  return false;
						 }	  
		 }         	  
}


//costo_arco(vertice v, vertice w)
template<class vertice>
float Grafo<vertice>::costo_arco(vertice v, vertice w)
{
	 Nodo_vert<vertice>*k;
	   Nodo_ady<vertice>*p;
       k=get_g();
	
	while(k!=NULL && k->get_infovert()!=v )
	     {
		       k=k->get_proxvert();
		 }
       
		 if(k!=NULL && k->get_infovert()==v)
		 {
			 p=k->get_ady();
			 
			 while(p!=NULL && p->get_infoady()!=w)
			      {
					  p=p->get_proxady();
					  
				   }
			 
			      if(p!=NULL && p->get_infoady()==w)
				    {
						return p->get_costo();						
					}
				     
				  
		 }         
		  
	
	
}


//orden_grafo();
template<class vertice>
int Grafo<vertice>::orden_grafo()
{
	return orden;
}


//predecesores(vertice v,Lista<vertice>&b)
template<class vertice>
void Grafo<vertice>::predecesores(vertice v,Lista<vertice>&b)
{
	      Nodo_vert<vertice>*p;
	      Nodo_ady<vertice>*k;
	      int pos = 0;
		  	    
	       p=get_g();
	       while(p!=NULL)
		          {
					    k=p->get_ady();
					    while(k!=NULL && k->get_infoady()!=v)
					         {
								 		k=k->get_proxady();
							}
							 
							 if(k!=NULL && k->get_infoady()==v)
							    {
									b.insertar(pos+1,p->get_infovert());
								}
						p=p->get_proxvert();		
				  }
}

//sucesores(vertice v,Lista<vertice>&c)

template<class vertice>
void Grafo<vertice>::sucesores(vertice v,Lista<vertice> &c)
{
	      Nodo_vert<vertice>*p;
	      Nodo_ady<vertice>*k;
	
	       p=get_g();
	       while(p!=NULL && p->get_infovert()!=v)
		          {
					  p=p->get_proxvert();
				  }
				  
				  if(p!=NULL && p->get_infovert()==v)
				    {
						 k=p->get_ady();
						while(k!=NULL)
						       {
								   c.insertar(1,k->get_infoady());
								   k=k->get_proxady();
							   }
					}
}

//vertices(Lista<vertice> &vert)

template<class vertice>
void Grafo<vertice>::vertices(Lista<vertice> &vert)
{
int i =0;
Nodo_vert<vertice> *aux;
	if(g!=NULL)
	{
	aux=get_g();
		while(aux->get_proxvert() !=  NULL)
		{
			vert.insertar(i+1,aux->get_infovert());
		}
	
	}	
	
}



//agregar_vertice(vertice v)
template<class vertice>
void Grafo<vertice>::agregar_vertice(vertice v)
{
	 Nodo_vert<vertice>*k, *aux;
	   
	   aux=new Nodo_vert<vertice>;
	   aux->set_infovert(v);   
		
       k=get_g();
	
	if(k==NULL)
	  { set_g(aux); orden++;}
	  
	  else
	  {
	      while(k->get_proxvert()!=NULL)
	           {
		          k=k->get_proxvert();
		       }
			   
			   k->set_proxvert(aux);
			   orden++;
	  }
}


//agregar_arco(vertice v, vertice w, float cost)
template<class vertice>
void Grafo<vertice>::agregar_arco(vertice v, vertice w, float cost)
{
	  Nodo_vert<vertice>*p;
	  Nodo_ady<vertice>*k, *aux;
	  
	   aux=new Nodo_ady<vertice>;
	   aux->set_infoady(w);
	   aux->set_costo(cost);
	
	     p=get_g();
	 // buscamos el nodo en la lista de de nodos principal
	   
	    while(p!=NULL && p->get_infovert()!=v)
		       {
				     p=p->get_proxvert();
				}
	   
	   
          // buscamos para insertar el arco entre el vertic e v - w
         if(p!=NULL && p->get_infovert()==v)
		  {
			   
                
                 if( p->get_ady()==NULL)
				  {
					   p->set_ady(aux);
				  }
			  
				   else
				      {
						  k=p->get_ady();
						  
						  while(k->get_proxady()!=NULL)
						       {
								   k=k->get_proxady();
								}
								
							if(k->get_proxady()==NULL)
							  {
								  k->set_proxady(aux);
							  }
                              
							
					  }
		  }

		 
}




template<class vertice>
void Grafo<vertice>::agregar_arco(vertice v, vertice w)
{
	  Nodo_vert<vertice>*p;
	  Nodo_ady<vertice>*k, *aux;
	  
	   aux=new Nodo_ady<vertice>;
	   aux->set_infoady(w);
	
	     p=get_g();
	 // buscamos el nodo en la lista de de nodos principal
	   
	    while(p!=NULL && p->get_infovert()!=v)
		       {
				     p=p->get_proxvert();
				}
	   
	   
          // buscamos para insertar el arco entre el vertic e v - w
         if(p!=NULL && p->get_infovert()==v)
		  {
			   
                
                 if( p->get_ady()==NULL)
				  {
					   p->set_ady(aux);
				  }
			  
				   else
				      {
						  k=p->get_ady();
						  
						  while(k->get_proxady()!=NULL)
						       {
								   k=k->get_proxady();
								}
								
							if(k->get_proxady()==NULL)
							  {
								  k->set_proxady(aux);
							  }
                              
							
					  }
		  }

		 
}

//eliminar_vertice(vertice v)
template<class vertice>
void Grafo<vertice>::eliminar_vertice(vertice v)
{
	     Nodo_vert<vertice>*antv,*p;
	     Nodo_ady<vertice>*anta,*k;
	
		//PARTE 1: ELIMINAR EL VERTICE COMO TAL

	            p=get_g();
	
            //busqueda del vertice
            
	         if(p->get_infovert()==v)
			 { 
			     set_g(p->get_proxvert()); 
                 
                  if(p->get_ady()!=NULL)
				   {
					   k=p->get_ady();
					   anta=k;
					   while(k!=NULL)
					         {
								 
								 anta=k;
								  k=k->get_proxady();
								  delete anta;
							 }
					}
					
					
					
			}
                 
              else
				  {
					 
				        while(p!=NULL && p->get_infovert() !=v)
						      {
								  antv=p;
								  p=p->get_proxvert();
							  }
							  
						    if(p!=NULL && p->get_infovert()==v)
							 {
								    antv->set_proxvert( p->get_proxvert() );
								    
								    // borramos los nodos ady internos
								      if(p->get_ady()!=NULL)
				                         {
					                          k=p->get_ady();
											 anta=k;
					                             while(k!=NULL)
					                                  {
								                          anta=k;
							                        	  k=k->get_proxady();
								                          delete anta;
							                          }
					                    }
								  
							 }	
				  }	
	
				  // disminuimos el orden
				    orden--;
				  
	//PARTE 2: BUSCAR EN LAS ADYACENCIAS PARA ELIMINAR EL VERTICE
			
				p=get_g();
		    while(p!=NULL)
			     {
					
					 k=p->get_ady();
					 anta=k;
					 while(k!=NULL && k->get_infoady()!=v)
					       {
							   anta=k;
							   k=k->get_proxady();
							}
							
							if(k!=NULL && k->get_infoady()==v)
							  {
								  anta->set_proxady(k->get_proxady());
								  delete k;
							  }
						p=p->get_proxvert();  
				 }
	
}


//eliminar_arco(vertice v, vertice w)
template<class vertice>
void Grafo<vertice>::eliminar_arco(vertice v, vertice w)
{
	    Nodo_vert<vertice>*p;
	    Nodo_ady<vertice>*anta,*k;
	
	    p=get_g();
	    while(p!=NULL && p->get_infovert()!=v)
		       {
				   p=p->get_proxvert();
			   }
			   
			 
		    if(p!=NULL && p->get_infovert()==v)
			  {
				   k=p->get_ady();
				   anta=k;
				   

				if(p->get_ady()->get_infoady()==k->get_infoady())
				  {
				     p->set_ady(k->get_proxady());
					  delete k;
				  }  
				  
   				  else
					  {
					  
				          while(k!=NULL && k->get_infoady()!=w )
				           {
							  anta=k;
							  k=k->get_proxady();
					        }
						 
						 if (k!=NULL && k->get_infoady()==w )
				   	       {
							anta->set_proxady(k->get_proxady());
							delete k;
					       }
					   }   
			  }
	
}


#endif
