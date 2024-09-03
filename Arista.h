#ifndef ARISTA_H_
#define ARISTA_H_
#include <iostream>

using namespace std;
using std::string;

class Arista
{
protected:
	string v;
	string w;
public:
	Arista();
	Arista(string  v, string w);
	~Arista();
	void setV(string v);
	void setW(string w);
	string getV();
	string getW();
};



Arista::Arista(){
		v="";
		w="";
		}
		
Arista::Arista(string  v1, string w1){
		v=v1;
		w=w1;
		}
		
Arista::~Arista(){
	}
	
void Arista::setV(string v1){
	v=v1;
	}
void Arista::setW(string w1){
	w=w1;
	}

string Arista::getV(){
	return v;
	}
string Arista::getW(){
	return w;
	}

#endif 
