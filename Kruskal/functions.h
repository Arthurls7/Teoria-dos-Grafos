#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define lenFather 1000

typedef struct{
    int v1, v2;
    int distance;
} edge;

int father[lenFather];

int compareDistance(const void *v1, const void *v2);

int compareFather(int vertex);

void unionTree(int v1, int v2);

void help();

void imprimirS(int x, int results[x][3]);

void imprimirA(char arquivo[], int x, int results[x][3], int soluc, int total);

#endif
