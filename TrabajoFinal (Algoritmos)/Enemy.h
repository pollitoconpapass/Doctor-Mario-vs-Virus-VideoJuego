#pragma once
#include <iostream>

using namespace System::Drawing;
using namespace System;

class Enemy {
private:
	int x, y;
	int dx, dy;
	int idX, idY;
	int width, height;
	int direccion;
	bool visibility;

public:
	Enemy(int w, int h) {
		width = w;
		height = h;
		direccion = 1;
		dx = dy = 11;
		x = 600 + rand() % (900 - 600);
		y = 500 + rand() % (601 - 500);
		idX = idY = 0;
		visibility = true;
	}
	~Enemy() {}

	void draw(Graphics^ g, Bitmap^ bmp) {
		Rectangle sectionShow = Rectangle(idX * width, idY * height, width, height);
		Rectangle zoom = Rectangle(x, y, width, height);
		g->DrawImage(bmp, zoom, sectionShow, GraphicsUnit::Pixel);
	}

	void move(Graphics^ g) {
		if (direccion == 1) { // los enemigos se mueven de arriba a abajo
			if (y + height * 1.0 > g->VisibleClipBounds.Height || y < 0) dy *= -1;
			if (dy > 0) { //dx=20
				idY = 0;
			}
			else
				idY = 1;
			y += dy;
		}

		idX++;
		if (idX > 9)
			idX = 0;
	}
	Rectangle getRectangle() {
		return Rectangle(x, y, width * 1.0, height * 1.0);
	}

	void setVisibility(bool v) { visibility = v; }
	int getx() { return x; }
	bool getVisibility() { return visibility; }

};

