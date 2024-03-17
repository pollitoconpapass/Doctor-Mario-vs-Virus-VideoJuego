#pragma once
#include "Entidad.h"

class Medicamento {
private:
	int x, y;
	int dx, dy;
	int indicex, indicey;
	int ancho, alto;
	int direccion;
	bool visibility;
public:
	Medicamento(int w, int h) {

		x = 300 + rand() % (901 - 300);
		y = 0 + rand() % (600 - 0);
		indicex = 0;
		indicey = 0;
		ancho = w;
		alto = h;
		visibility = true;
	}

	// --- MOSTRAR --- 
	void mostrar(Graphics^ g, Bitmap^ bmpMedicamento) {
		Rectangle sectionShow = Rectangle(indicex * ancho * 0.1, indicey * alto * 0.1, ancho, alto);
		Rectangle zoom = Rectangle(x, y, ancho * 0.1, alto * 0.1);
		g->DrawImage(bmpMedicamento, zoom, sectionShow, GraphicsUnit::Pixel);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 0.1, alto * 0.1);
	}
	void setvisibility(bool n) {
		visibility = n;
	}
	bool getVisible() {
		return visibility;
	}
};

