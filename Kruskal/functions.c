#include "functions.h"

int compareDistance(const void *v1, const void *v2){
    edge *vertex1 = (edge*) v1;
    edge *vertex2 = (edge*) v2;
    
    if(vertex1->distance > vertex2->distance) return 1;
    else if(vertex1->distance < vertex2->distance) return -1;
    else return 0;
}

int compareFather(int vertex){
    //Caso ele ainda seja pai dele mesmo
    if(father[vertex] == vertex) return vertex;
    
    //Caso nao, verifica o pai do pai ate chegar na raiz
    father[vertex] = compareFather(father[vertex]);
    return father[vertex];
}

void unionTree(int v1, int v2){
    father[compareFather(v1)] = compareFather(v2);
}

void help(){
    printf("Implementamos o Algoritmo de Kruskal\n");
    printf("No diretorio temos um arquivo no formato \".txt\" com o exemplo da entrada\n");
    printf("Nosso algoritmo funciona do modo a seguir:\n");
    printf("Ordenamos o grafo pelas menores distancias de arestas, e apos isso saimos fazendo as ligacoes entre elas (tratando cada no como uma arvore independente) e com isso fazer a arvore maior que representa a arvore geradora minima para a solucao do problema.\n");
    printf("Erros possiveis:\n");
    printf("Problema no arquivo de entrada -> provavelmente foi passado o caminho errado, ou o arquivo errado para o programa ler\n");
    printf("Grafo nao conexo -> o algoritmo nao tera solucao");
}

void imprimirS(int x, int results[x][3]){
    for(int i=0; i<x; i++){
        printf("(%d, %d) = %d\n", results[i][0], results[i][1], results[i][2]);
    }
}

void imprimirA(char arquivo[], int x, int results[x][3], int soluc, int total){
    FILE *ptr = fopen(arquivo, "w"); 

    if(soluc == 0){
        fprintf(ptr, "%d", total);
        fclose(ptr);
        return;
    }

    for(int i=0; i<x; i++){
        fprintf(ptr, "(%d, %d) = %d\n", results[i][0], results[i][1], results[i][2]);
    }
    
    fclose(ptr);
}
