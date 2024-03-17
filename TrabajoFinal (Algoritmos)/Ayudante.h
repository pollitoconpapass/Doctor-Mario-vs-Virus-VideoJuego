#pragma once
#include "Entidad.h"
using namespace System;

class Ayudante : public Entidad {
public:
	Ayudante(int w, int h) :Entidad(w, h) {
		x = 600;
		y = 500;
		dx = dy = 3;
		indicex = indicey = 1;
		ancho = w;
		alto = h;
		visibility = true;
	}
	void mover(Graphics^ g, Direcciones direccion) {
		switch (direccion)
		{
		case Direcciones::Izquierda: // izq
			if (x > 0) {
				indicey = 1;
				x -= dx;
			}
			break;
		case Direcciones::Derecha: // der
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
				indicey = 2;
				x += dx;
			}
			break;
		}
		indicex++;
		if (indicex > 2) indicex = 0;
	}

	void mostrar(Graphics^ g, Bitmap^ bmpAyudante) {
		ancho = bmpAyudante->Width / 12;
		alto = bmpAyudante->Height / 8;
		Rectangle sectionShow = Rectangle(indicex * ancho, indicey * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho, alto);
		g->DrawImage(bmpAyudante, zoom, sectionShow, GraphicsUnit::Pixel);

	}
};

