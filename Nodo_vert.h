#ifndef NODO_VERT_H_
#define NODO_VERT_H_
#include "Nodo_ady.h"


template<class vertice>
class Nodo_vert
{
    private:
       vertice info;
       Nodo_vert<vertice> *prox;
      Nodo_ady<vertice>*ady;
       //noc si es lista o pinter
	
	public:
              Nodo_vert();
       void set_infovert(vertice a);
       void set_proxvert(Nodo_vert<vertice>* b);
	   void set_ady(Nodo_ady<vertice>* c);
       vertice get_infovert();
	   Nodo_vert<vertice>* get_proxvert();
	    Nodo_ady<vertice>* get_ady();
	 
};

// implementacion//


//  constructor
template<class vertice>
Nodo_vert<vertice>::Nodo_vert()
{
    prox=NULL;
}


//set_info(vertice a)
template<class vertice>
void Nodo_vert<vertice>:: set_infovert(vertice a)
{
    info=a;
}


	
//set_prox(Nodo_vert<vertice>* b)
template<class vertice>
 void Nodo_vert<vertice>:: set_proxvert(Nodo_vert<vertice>* b)
{
      prox=b;
}




template<class vertice>
 void Nodo_vert<vertice>:: set_ady(Nodo_ady<vertice>* c)
{
      ady=c;
}
	


//get_info()
template<class vertice>
vertice Nodo_vert<vertice>::get_infovert()
{
    return info;
}


	
	
// get_prox()
template<class vertice>
Nodo_vert<vertice>* Nodo_vert<vertice>:: get_proxvert()
{
     return prox;
}

// get_ady()
template<class vertice>
Nodo_ady<vertice>* Nodo_vert<vertice>:: get_ady( )
{
      return ady;
}
	


#endif
