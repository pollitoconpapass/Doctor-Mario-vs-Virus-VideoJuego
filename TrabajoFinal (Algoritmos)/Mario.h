#pragma once
#include "Entidad.h"

class Mario : public Entidad {
private:

	int cant_medicamentos = 0;// es lo q va a recolectar a lo largo del juego
	int vidas = 3;
	int inicioX, inicioY;
public:
	Mario(int w, int h) :Entidad(w, h) {
		x = 250;
		y = 530;
		dx = 10;
		dy = 10;
		indicex = indicey = 0;
		ancho = w;
		alto = h;
		inicioX = 100;
		inicioY = 500;

	}
	void mover(Graphics^ g, char i, Bitmap^ bmpMario) {
		switch (i)
		{
		case 'A': // izq
			if (x > 0) {
				indicey = 2;
				x -= dx;
				index = 'A';
			}
			break;
		case 'D': // der
			if (x + ancho * 1.0 < g->VisibleClipBounds.Width) {
				indicey = 6;
				x += dx;
				index = 'D';
			}
			break;
		case ' ': // saltar
			if (x > 0 && x + ancho * 1.0 < g->VisibleClipBounds.Width || y > 0 && y + alto * 1.0 < g->VisibleClipBounds.Height) {
				indicey = 5;
				y = y - 500;
				x = x + 10;

			}
			y = y + 500; // llevarlo para abajo con el mimo numero en y pero +
			break;

		case 'W': // Arriba
			if (y > 0) {
				indicey = 3;
				y -= dy;
				index = 'W';
			}
			break;
		case 'S': // Abajo
			if (y + alto * 1.0 < g->VisibleClipBounds.Height) {
				indicey = 3;
				y += dy;
				index = 'S';
			}
			break;

		}

		indicex++;
		if (indicex > 7) indicex = 0;
	}

	void mostrar(Graphics^ g, Bitmap^ bmpMario) {
		ancho = bmpMario->Width / 8.07;
		alto = bmpMario->Height / 8.07;
		Rectangle molde = Rectangle(indicex * ancho, indicey * alto, ancho, alto);
		g->DrawImage(bmpMario, x, y, molde, GraphicsUnit::Pixel);
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, ancho * 1.0, alto * 1.0);
	}
	void aumenta_medicamentos() {
		cant_medicamentos++;
	}
	void disminuyevidas() { vidas--; }
	// -- GETS ---
	int getCant_medicamentos() { return cant_medicamentos; }
	int getVidas() { return vidas; }
	int getInicioX() { return inicioX; }
	char getDireccion() { return index; }
	void setDireccion(char n) { index = n; }
	int getInicioY() { return inicioY; }

};

