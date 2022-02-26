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
int prim(int nmr_vertices, int matriz[][nmr_vertices], int origem, int pai[]);
#endif
