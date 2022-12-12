#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

constexpr int MAXN = 50;

char rec[MAXN][MAXN];  // Se almacenara la matriz de entrada
bool g[MAXN*MAXN][MAXN*MAXN];  // Se almacenara la matriz de adyacencia
bool b[MAXN*MAXN];  // Se almacenara el estado de los nodos si son visitados o no
int h, w, ans, total;  
int mylink[MAXN*MAXN]; // Se almacenara el enlace de cada nodo
int r[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};  // Se almacenara las direcciones de los nodos

// Se busca un camino aumentante
bool find(int a)
{
	for(int i = 0; i < h * w; i++) // Se recorren todos los nodos
	{
		if(g[a][i] == true && !b[i]) // Si el nodo esta conectado y no ha sido visitado
		{
			b[i] = true; // Se marca como visitado
			if(mylink[i] == 0 || find(mylink[i]) ) // Si el nodo no esta enlazado o se puede encontrar un camino aumentante
			{
				mylink[i] = a;  // Se enlaza el nodo
				return true;  // Se retorna verdadero
			}
		}
	}
	return false; 
}

int main()
{
	int cas, total;
	scanf("%d", &cas);
	while(cas --) // Se Itera por cada caso
	{ 
		memset(g, false, sizeof(g));
		memset(mylink, 0, sizeof(mylink));
		total = ans = 0;
		scanf("%d%d", &h, &w);
		getchar();
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				rec[i][j] = getchar();   // Se lee la matriz de entrada
				if(rec[i][j] == '*') total++;  // Se cuenta el numero de nodos
			}
			getchar();
		}
		for(int i = 0; i < h; i++)
			for(int j = 0;  j < w; j++)
				for(int k = 0; k < 4; k++) // Se recorren las direcciones
				{
					int xx = i + r[k][0]; // Se calcula la posicion de la siguiente casilla
					int yy = j + r[k][1]; // Se calcula la posicion de la siguiente casilla
					if(rec[i][j] == '*' && rec[xx][yy] == '*' &&  xx >= 0 && yy >= 0 && xx < h && yy < w) // Se verifica que las casillas sean validas
						g[i * w + j][xx * w + yy] = g[xx * w +yy][i * w + j] = true; // Se crea la matriz de adyacencia
				}
		for(int i = 0; i < h * w; i++) // Se busca el emparejamiento maximo
		{
			memset(b, false, sizeof(b)); // Se inicializa el estado de los nodos
			if(find(i)) ans++;  // Se busca el emparejamiento maximo
		}
		ans /= 2;  // Se divide entre dos porque se cuenta dos veces el mismo enlace
		printf("%d\n", total - ans);  // Se imprime el resultado
	}
    return 0;
}