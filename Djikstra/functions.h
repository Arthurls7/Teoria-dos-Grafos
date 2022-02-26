#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define true 1
#define false 0

typedef int bool;

void help();
void grafo(int nmr_vertices, int nmr_arestas, int matriz_adj[][nmr_vertices], FILE *ptr);
int Menor_Distancia(int distancia[], int visitado[], int nmr_vertices);
void Menor_Caminho(int nmr_vertices, int origem, int pai[], int distancia[], int matriz[][nmr_vertices]);
void output(char arquivo[], int LastV, int InitV, int distancia[], int nmr_vertices);

#endif
