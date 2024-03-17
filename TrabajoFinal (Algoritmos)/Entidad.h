#pragma once
#include<iostream>
#include <conio.h>
using namespace System::Drawing;
using namespace System;

enum Direcciones { Derecha, Izquierda, Arriba, Abajo };

class Entidad {
protected:
	int x, y;
	int dx, dy;
	int indicey, indicex;
	int ancho, alto;
	int index;
	bool visibility;
public:
	Entidad(int w, int h) {}
	~Entidad() {}

	// --- GET ---
	int getx() { return x; }
	int gety() { return y; }
	int getdx() { return dx; }
	int getdy() { return dy; }
	int getindicex() { return indicex; }
	int getindicey() { return indicey; }
	int getancho() { return ancho; }
	int getalto() { return alto; }
	int getindex() { return index; }
	bool getvisibility() { return visibility; }
	/*Rectangle getRectangle() { return Rectangle(x, y, ancho * 1.0, alto * 1.0); }*/

	// --- SET --- 
	void setx(int n) { x = n; }
	void sety(int n) { y = n; }
	void setdx(int n) { dx = n; }
	void setdy(int n) { dy = n; }
	void setindicey(int n) { indicey = n; }
	void setindicex(int n) { indicex = n; }
	void setvisibility(bool n) { visibility = n; }

	// --- FUNCIONES PARA EL JUEGO ---
	virtual void mostrar() {};
	virtual void mover() {};
};

