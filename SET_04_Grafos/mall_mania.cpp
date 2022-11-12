#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

// Mall Mania

const int EMPTY = -1;  // nodo vacío
const int GOAL = -2;   // nodo objetivo
const int MAXSIZE = 2010;  // tamaño máximo del laberinto
vector<vector<int>> grid;   // el laberinto

vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};  // directions

int main() {
    int p;  // número de casos de prueba
    while (cin >> p, p) {  // para cada caso de prueba
        grid.assign(MAXSIZE, vector<int>(MAXSIZE, EMPTY)); // inicializar el laberinto ¿?

        int a, s;  // número de filas y columnas
        queue<pair<int, int>> q;  // cola de celdas a procesar
        while (p--) {  // para cada persona
            cin >> a >> s; // leer el número de filas y columnas
            grid[a][s] = 0; // marcar la celda como visitada
            q.push({a, s}); // añadir la celda a la cola
        }
        cin >> p; // leer el número de objetivos
        while (p--) { // para cada objetivo
            cin >> a >> s; // leer las coordenadas de la meta
            grid[a][s] = GOAL;  // marcar la celda como objetivo
        }

        int distance;   // distancia de la célula inicial
        bool found_path = false;  // para indicar si se ha encontrado una ruta
        while (!q.empty() && !found_path) {  // mientras la cola no esté vacía y no se haya encontrado ninguna ruta
            pair<int, int> u = q.front();  // obtener la primera celda de la cola
            q.pop();  // eliminar la célula de la cola

            for (auto&& d : dirs) {  // para cada dirección
                pair<int, int> v = {u.first + d.first, u.second + d.second};  // obtener la siguiente celda

                //¿? 
                if (0 <= v.first && v.first < MAXSIZE &&   // si la celda está dentro del laberinto
                    0 <= v.second && v.second < MAXSIZE) {  // y no ha sido visitada
                        if (grid[v.first][v.second] == EMPTY) {  // si la celda está vacía
                            grid[v.first][v.second] = grid[u.first][u.second] + 1;  // marcar la celda como visitada
                            q.push(v);     // añadir la celda a la cola
                        } else if (grid[v.first][v.second] == GOAL) {  // si la celda es un objetivo
                            distance = grid[u.first][u.second] + 1;  // obtener la distancia
                            found_path = true;    // marcar que se ha encontrado una ruta
                        }
                    }
            }
        }
        cout << distance << endl;  // imprimir la distancia
    }
}