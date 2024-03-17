#pragma once
using namespace System::Drawing;

class Bullets {
private:
	int x;
	int y;
	int dx, dy;
	int indicex, indicey;
	int ancho;
	char index;
	bool visibility;
public:
	Bullets(int _x, int _y, char _index) {
		this->x = _x;
		this->y = _y;
		dx = dy = 10;;
		this->index = _index;
		indicex, indicey = 0;
		ancho = 20;
		visibility = true;
	}
	~Bullets() {}

	void dibujar(Graphics^ g) {
		SolidBrush^ sb = gcnew SolidBrush(Color::DarkRed);
		g->FillEllipse(sb, x, y, ancho, ancho);
	}

	void mover(Graphics^ g) {
		if (index == 'A' && x >= 0) {
			x -= dx;
		}
		if (index == 'D' && x + ancho <= g->VisibleClipBounds.Width) {
			x += dx;
		}
		if (index == 'W' && y >= 0) {
			y -= dy;
		}
		if (index == 'S' && y + ancho <= g->VisibleClipBounds.Height) {
			y += dy;
		}

	}

	Rectangle getRectangle() {
		return	Rectangle(x, y, ancho, ancho);
	}
	bool getVisble() { return visibility; }
	void setVisible(bool v) { visibility = v; }
	int getXAncho() { return x + ancho; }
	int getYAlto() { return y + ancho; }
	int getX() { return x; }
	int getY() { return y; }

};

