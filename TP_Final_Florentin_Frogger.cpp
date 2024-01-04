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
			autos.push_front(true);
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
		for (int i = 0; i < numeroLineas; i++) {
			mapa.push_back(new Linea(width));
		}
		jugador = new Jugador(width);
	}
	void Dibujar() {
		system("cls");
		for (int i = 0; i < numeroLineas; i++) {
			for (int j = 0; j < width; j++) {
				if (mapa[i]->CheckPos(j)&& i !=0 && i != numeroLineas -1) {
					cout << "*";
				}
				else if (jugador->x == j && jugador->y == i) {
					cout << "W";
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}
	}

	void Entrada() {
		if (_kbhit()) {
			char tecla = _getch();
			switch (tecla) {
			case 'a':
				jugador->x--;
				break;
			case 'd':
				jugador->x++;
				break;
			case 'w':
				jugador->y--;
				break;
			case 's':
				jugador->y++;
				break;
			case 'q':
				quit = true;
				break;
			} 
		}
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
	Game game(15, 10);
	game.Run();
	return 0;
}



