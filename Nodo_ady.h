#ifndef NODO_ADY_H_
#define NODO_ADY_H_


template<class vertice>
class Nodo_ady
{
    private:
       vertice info;
       float costo;
       Nodo_ady<vertice>*prox;
	
	public:
              Nodo_ady();
       void set_infoady(vertice a);
       void set_costo(float b);
	   void set_proxady(Nodo_ady<vertice>*c);
       vertice get_infoady();
	   float   get_costo();
	  Nodo_ady<vertice>* get_proxady();
       
};

// implementacion//


//  constructor
template<class vertice>
Nodo_ady<vertice>::Nodo_ady()
{
    costo=0;
    
}


//set_info(vertice a)
template<class vertice>
void  Nodo_ady<vertice>:: set_infoady(vertice a)
{
    info=a;
}

//set_costo(floar b)
template<class vertice>
void Nodo_ady<vertice>::set_costo(float b)
{
    costo=b;
}


template<class vertice>
void Nodo_ady<vertice>::set_proxady(Nodo_ady<vertice>*c)
{
    prox=c;
}




//get_info()
template<class vertice>
vertice Nodo_ady<vertice>::get_infoady()
{
    return info;
}

	
// get_costo()
template<class vertice>
float Nodo_ady<vertice>:: get_costo()
{
    return costo;
}



template<class vertice>
Nodo_ady<vertice>* Nodo_ady<vertice>:: get_proxady()
{
    return prox;
}


#endif
