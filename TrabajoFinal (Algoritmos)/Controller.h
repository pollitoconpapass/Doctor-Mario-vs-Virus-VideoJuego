#pragma once
#include"Mario.h"
#include"Ayudante.h"
#include"Enemy.h"
#include"JefeFinal.h"
#include "Medicamentos.h"
#include "Bullets.h"
#include<vector> 
using namespace std;

class Controller {
private:
	vector<Ayudante*>ayudante;
	vector<Enemy*>enemies;
	vector<Enemy*>enemies2;
	vector<Medicamento*>medicamentos;
	vector<Bullets*> bullets;
	JefeFinal* jefeFinal;
	Mario* mario;
	int numberOfEnemies;
	int num_medics;
	bool disparar;
public:
	Controller() {
		numberOfEnemies = 2;
		num_medics = 20;
		disparar = false;
	}
	~Controller() {}

	// -- NIVEL 1 --  
	void createAyudante(Ayudante* a) {
		ayudante.push_back(a);
	}
	void createEnemies(int width, int height) {
		for (int i = 0; i < numberOfEnemies; i++)
		{
			Enemy* e = new Enemy(width, height);
			enemies.push_back(e);
		}
	}
	void CreateMedicamento(int width, int height) {
		for (int i = 0; i < num_medics; i++) {
			Medicamento* meds = new Medicamento(width, height);
			medicamentos.push_back(meds);
		}
	}
	void createJefeFinal(int w, int h) {
		jefeFinal = new JefeFinal(w, h);

	}
	void drawEveryThing(Graphics^ g, Bitmap^ bmpAyudante, Bitmap^ bmpEnemy, Bitmap^ bmpJefe, Bitmap^ bmpHero, Bitmap^ bmpmeds) {
		mario = new Mario(bmpHero->Width / 4, bmpHero->Height / 4);
		for (int i = 0; i < ayudante.size(); i++)
		{
			ayudante[i]->mostrar(g, bmpAyudante);
		}
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i]->draw(g, bmpEnemy);
		}
		for (int i = 0; i < medicamentos.size(); i++)
		{
			medicamentos[i]->mostrar(g, bmpmeds);
		}
		jefeFinal->mostrar(g, bmpJefe);

	}

	void setvisibleA(bool n) {
		for (int i = 0; i < ayudante.size(); i++) {
			ayudante[i]->setvisibility(true);
		}
	}
	bool getvisibleA(int i) {
		return ayudante[i]->getvisibility();
	}
	void moveEveryThing(Graphics^ g, int m) {
		for (int i = 0; i < enemies.size(); i++)
		{
			if (enemies[i]->getx() > i) {
				enemies[i]->move(g);
			}
			else if (enemies[i]->getx() < i) {
				enemies[i]->move(g);
			}
		}

		for (int i = 0; i < ayudante.size(); i++) {
			if (ayudante[i]->getx() > m) {
				ayudante[i]->mover(g, Direcciones::Izquierda);
			}
			else if (ayudante[i]->getx() < m) {
				ayudante[i]->mover(g, Direcciones::Derecha);
			}
		}
		if (jefeFinal->getx() < m) {
			jefeFinal->mover(g, Direcciones::Derecha);
		}
		else {
			if (jefeFinal->getx() > m) {
				jefeFinal->mover(g, Direcciones::Izquierda);
			}
		}
	}

	void Colisiones(Graphics^ g, Mario* mario) {
		//medicamentos - set 
		for (int i = 0; i < medicamentos.size(); i++) {
			if (mario->getRectangle().IntersectsWith(medicamentos.at(i)->getRectangle())) {
				medicamentos.at(i)->setvisibility(false);
				mario->aumenta_medicamentos();
			}
		}
		for (int i = 0; i < medicamentos.size(); i++)
		{
			if (!medicamentos[i]->getVisible()) {
				medicamentos.erase(medicamentos.begin() + i);
			}
		}
		//colisión mario - enemigo
		for (int i = 0; i < enemies.size(); i++) {
			if (mario->getRectangle().IntersectsWith(enemies.at(i)->getRectangle())) {
				mario->setx(mario->getInicioX());
				mario->sety(mario->getInicioY());
				mario->disminuyevidas();
				jefeFinal->setx(jefeFinal->getInicioX());
				jefeFinal->sety(jefeFinal->getInicioY());

			}

		}
		////colision enemigos con bullets
		//for (int i = 0; i < bullets.size(); i++) {
		//	if (bullets[i]->getX() < 0 || bullets[i]->getXAncho() > g->VisibleClipBounds.Width) { bullets[i]->setVisible(false); }
		//	for (int j = 0; j< enemies2.size() + 3; j++) {
		//		if(!bullets[i]->getRectangle().IntersectsWith(enemies2[j]->getRectangle())){
		//			enemies2[j]->setVisibility(false);
		//		}
		//}
		//}
		//for (int i = 0; i < enemies2.size()+3; i++) {
		//	if (!enemies2[i]->getVisibility()) {
		//		enemies2.erase(enemies2.begin() + i);
		//	}
		//}
		//for (int i = 0; i < bullets.size(); i++) {
		//	if (!bullets[i]->getVisble()) { bullets.erase(bullets.begin() + 1); }
		//}
		if (mario->getRectangle().IntersectsWith(jefeFinal->getRectangle())) {
			mario->setvisibility(false);
			mario->setx(mario->getInicioX());
			mario->sety(mario->getInicioY());
			mario->disminuyevidas();
			jefeFinal->setx(jefeFinal->getInicioX());
			jefeFinal->sety(jefeFinal->getInicioY());
		}
	}
	// ---- NIVEL 2 -> con balas ---- 
	void agregar_disparo(Bullets* b) {
		bullets.push_back(b);
	}
	void createEnemy2(int w, int h) {
		for (int i = 0; i < numberOfEnemies + 3; i++) {
			Enemy* a = new Enemy(w, h);
			enemies2.push_back(a);
		}
	}

	// aprende a declarar lo que inicializassjskdofie
	void drawEveryThingNiv2(Graphics^ g, Bitmap^ bmpJefe, Bitmap^ bmpHero, Bitmap^ bmpenemy) {
		mario = new Mario(bmpHero->Width / 4, bmpHero->Height / 4);
		jefeFinal->mostrar(g, bmpJefe);
		for (int i = 0; i < bullets.size(); i++) {
			bullets[i]->dibujar(g);
		}
		for (int i = 0; i < enemies2.size(); i++) {
			enemies2[i]->draw(g, bmpenemy);
		}
	}
	void moveEveryThingNiv2(Graphics^ g, int x) {
		for (int i = 0; i < bullets.size(); i++)
		{
			bullets[i]->mover(g);
		}

		if (jefeFinal->getx() < x) {
			jefeFinal->mover(g, Direcciones::Derecha);
		}
		else {
			if (jefeFinal->getx() > x) {
				jefeFinal->mover(g, Direcciones::Izquierda);
			}
		}
		for (int i = 0; i < enemies2.size(); i++) {
			enemies2[i]->move(g);
		}
		jefeFinal->setdx(10);
	}

	//Colisiones para el Nivel 2
	void ColisionesNiv2(Graphics^ g, Mario* mario2) {
		// Colision Mario - JefeFinal
		if (mario2->getRectangle().IntersectsWith(jefeFinal->getRectangle())) {
			mario2->setvisibility(false);
			mario2->setx(mario2->getInicioX());
			mario2->sety(mario2->getInicioY());
			mario2->disminuyevidas();
			jefeFinal->setx(jefeFinal->getInicioX());
			jefeFinal->sety(jefeFinal->getInicioY());
		}

		// Colision balas Jefe Final niv. 2
		for (int i = 0; i < bullets.size(); i++) {
			if (bullets[i]->getRectangle().IntersectsWith(jefeFinal->getRectangle())) {
				jefeFinal->disminuyevidas();
				bullets[i]->setVisible(false);
			}
		}

		//Colision enemigo vs mario
		for (int i = 0; i < enemies2.size(); i++) {
			if (mario2->getRectangle().IntersectsWith(enemies2.at(i)->getRectangle())) {
				mario2->setvisibility(false);
				mario2->setx(mario2->getInicioX());
				mario2->sety(mario2->getInicioY());
				mario2->disminuyevidas();
				jefeFinal->setx(jefeFinal->getInicioX());
				jefeFinal->sety(jefeFinal->getInicioY());
			}
		}
		//Colision bullets vs enemigo
		for (int i = 0; i < bullets.size(); i++) {
			for (int j = 0; j < enemies2.size(); j++) {
				if (bullets[i]->getRectangle().IntersectsWith(enemies2.at(j)->getRectangle())) {
					enemies2.at(j)->setVisibility(false);
					bullets[i]->setVisible(false);
				}
			}
		}
		for (int i = 0; i < enemies2.size(); i++) {
			if (!enemies2[i]->getVisibility()) {
				enemies2.erase(enemies2.begin() + i);
			}
		}
		for (int i = 0; i < bullets.size(); i++) {
			if (!bullets[i]->getVisble()) {
				bullets.erase(bullets.begin() + i);
			}
		}
	}

	bool VidasJefeFinal() {
		if (jefeFinal->getvidas() == 0) {
			return true;
		}
		else {
			return false;
		}
	}

	bool getDisparar() { return disparar; }
	void setDisparar(bool v) { disparar = v; }
	Mario* getMario() { return mario; }

	//void ColisionMarioMedicamento() {
	//	for (int i = 0; i < medicamentos.size(); i++) {
	//		if (mario->getRectangle().IntersectsWith(medicamentos.at(i)->getRectangle())) {
	//			mario->aumenta_medicamentos();
	//			medicamentos[i]->setvisibility(false);
	//			break;
	//		}
	//		if (!medicamentos[i]->getvisibility()) {
	//			medicamentos.erase(medicamentos.begin() + i);
	//			break;
	//		}
	//	}
	//}
	//bool ColisionMarioJefe() {
	//	if (mario->getRectangle().IntersectsWith(jefeFinal->getRectangle())) {
	//		return true;
	//	}
	//}
};


