#pragma once
#include"Entidad.h"

class JefeFinal :public Entidad
{
private:
	int InicioX, inicioY;
	int cantvidas;

public:
	JefeFinal(int w, int h) :Entidad(w, h) {
		cantvidas = 500;
		x = -500;
		y = 100;
		dx = dy = 5;
		indicex = indicey = 0;
		ancho = w;
		alto = h;
		visibility = true;
		InicioX = -500;
		inicioY = 100;


	}
	~JefeFinal() {
	}
	void mover(Graphics^ g, Direcciones direccion) {
		switch (direccion)
		{
		case Direcciones::Izquierda: // izq
			if (x > 0) {
				indicey = 0;
				x -= dx;
			}
			break;
		case Direcciones::Derecha: // der
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
				indicey = 0;
				x += dx;
			}
			break;
		}
	}

	void mostrar(Graphics^ g, Bitmap^ bmpJefe) {
		ancho = bmpJefe->Width;
		alto = bmpJefe->Height;
		Rectangle sectionShow = Rectangle(indicex * ancho, indicey * alto, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho, alto);
		g->DrawImage(bmpJefe, zoom, sectionShow, GraphicsUnit::Pixel);

	}
	int getInicioX() {
		return InicioX;
	}
	int getInicioY() {
		return inicioY;
	}

	int getvidas() {
		return cantvidas;
	}

	void disminuyevidas() {
		cantvidas = cantvidas - 10;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho - 100, alto - 100);
	}

};



