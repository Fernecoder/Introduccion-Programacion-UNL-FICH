// TP_Final_Florentin_Frogger.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <deque>
#include <vector>

using namespace std;

class Jugador{

public:
	int x, y;
	Jugador(int width) { x = width / 2, y = 0; }

};

class Linea {

private:
	deque<bool> autos;

public:
	Linea(int width) {
		for (int i = 0; i < width; i++) {
			autos.push_front(false);
		}
	}
	void Mover() {
		if (rand() % 10 == 1) {
			autos.push_front(true);
		}
		else {
			autos.push_front(false);
		}
		autos.push_back(true);
	}
	bool CheckPos(int pos) { return autos[pos]; }

};

class Game {

private:
	bool quit;
	int numeroLineas;
	int width;
	int score;
	Jugador* jugador;
	vector<Linea*> mapa;

public:
	Game(int w = 20, int h = 10) {
		numeroLineas = h;
		width = w;
		quit = false;
	}
	void Dibujar() {

	}

	void Entrada() {

	}

	void Logica() {

	}

	void Run() {
		while (!quit) {
			Entrada();
			Dibujar();
			Logica();
		}
	}
};



int main() {
	poasd
}



