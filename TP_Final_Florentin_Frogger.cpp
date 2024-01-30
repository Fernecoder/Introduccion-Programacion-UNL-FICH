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

class Iniciales {
public:
	int x, y;
	Iniciales(int inicialX, int inicialY):x(inicialX), y(inicialY){}
};

class Jugador : public Iniciales{

public:
	Jugador(int width) : Iniciales(width / 2, 0) {}

};

class Linea : public Iniciales {

private:
	deque<bool> autos;
	bool sentDerecho;
public:
	Linea(int width) : Iniciales(0,0) {
		for (int i = 0; i < width; i++) {
			autos.push_front(true);
		}
		sentDerecho = rand() % 2;
	}
	void Mover() {
		if (sentDerecho) {
			if (rand() % 10 == 1) {
				autos.push_front(true);
			}
			else {
				autos.push_front(false);
			}
			autos.pop_back();
		}
		else {
			if (rand() % 10 == 1) {
				autos.push_back(true);
			}
			else {
				autos.push_back(false);
			}
			autos.pop_front();
		}
		
	}
	bool CheckPos(int pos) { return autos[pos]; }

};

class Game {

private:
	bool quit;
	int numeroLineas;
	int width;
	int score=0;
	Jugador* jugador;
	vector<Linea*> mapa;

public:
	
	Game() {
		srand(time(NULL));
		numeroLineas = 10;
		width = 20;
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
		cout << endl << "Score:" << score << endl;
		cout << endl << "INSTRUCCIONES:" << endl;
		cout << endl << "La letra 'W' representa la rana, para moverla usa las siguentes teclas:" << endl;
		cout << "W para subir" << endl << "S para bajar" << endl << "A para moverse a la izquierda" << endl << "D para moverse a la derecha" << endl << "Con la letra Q salis del juego" << endl;
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
		
		for (int i = 1; i < numeroLineas - 1; i++) {
			if (rand() % 10 > 5) {
				mapa[i]->Mover();
			}
			if (mapa[i]->CheckPos(jugador->x) && jugador->y == i) {
				cout << endl << "Juego terminado!" << endl;
				cout << endl << "Tu puntaje final es:" << score << endl;
				quit = true;
			}
		}
		if (jugador->y == numeroLineas - 1) {
			score+=10;
			jugador->y = 0;
		}
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
	Game game;
	game.Run();
	return 0;
}


