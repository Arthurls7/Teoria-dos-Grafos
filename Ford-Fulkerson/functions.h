#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max_flow(int s, int t, int visited[], int nVertex, int grafo[][nVertex]);

int DFS(int s, int t, int visited[], int nVertex, int grafo[][nVertex], int minFlow);

int fonte_sumidouro(int s, int t, int nVertex, int grafo[][nVertex]);

int min(int a, int b);

void help();

void zerar(int array[], int tam);

#endif
