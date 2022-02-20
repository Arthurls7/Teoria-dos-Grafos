#include "functions.h"

int max_flow(int s, int t, int visited[], int nVertex, int grafo[][nVertex]){
    int flow = 0;
    int i = 0;
    while(i < 50){
        zerar(visited, nVertex);
        int result = DFS(s, t, visited, nVertex, grafo, -1);
        flow += result;
        if(result == 0) return flow;
        //printf("%d: %d\n", i++, result);
    }
    
    return 0;
}

int DFS(int s, int t, int visited[], int nVertex, int grafo[][nVertex], int minFlow){

    if(s == t) return minFlow;

    //printf("%d", s+1);
    visited[s] = 1;
    for(int i=0; i<nVertex; i++){
        if(grafo[s][i] > 0 && visited[i] == 0){
            if(minFlow == -1) minFlow = grafo[s][i];
            //printf(" -> ");
            int flow = DFS(i, t, visited, nVertex, grafo, min(minFlow, grafo[s][i]));
            if(flow>0){
                grafo[s][i] -= flow;
                grafo[i][s] += flow;
                return flow;
            }
        } 
    }

    return 0;
}

int fonte_sumidouro(int s, int t, int nVertex, int grafo[][nVertex]){
    //printf("%d %d\n", s, t);
    if(s > nVertex || s < 0) return 0;
    if(t > nVertex || t < 0) return 0;

    for(int i=0; i<nVertex; i++){
        if(grafo[i][s] > 0){
            //printf("a1 %d\n", grafo[i][s]);
            return 0;
        } 
        if(grafo[t][i] > 0){
            //printf("a2 %d\n", grafo[t][i]);
            return 0;
        } 
    }

    return 1;
}

int min(int a, int b){
    return a > b ? b : a; 
}

void help(){
    printf("Implementamos o Algoritmo de Ford-Fulkerson utilizando DFS\n");
    printf("No diretorio temos um arquivo no formato \".txt\" com o exemplo da entrada\n");
    printf("Nesse algoritmo eh necessario um vertice inicial -i e um vertice final -l\n");
    printf("Obs: o vertice -i deve ser uma fonte, e o vertice -l deve ser um sumidouro\n");
    printf("Nosso algoritmo funciona do modo a seguir:\n");
    printf("Realizamos o dfs e vamos diminuindo o valor de capacidade de cada aresta ao chegar no vertice -l\n");
    printf("Essa reducao da capacidade eh dada pela menor capacidade possivel percorrida");
    printf("Erros possiveis:\n");
    printf("Problema no arquivo de entrada -> provavelmente foi passado o caminho errado, ou o arquivo errado para o programa ler\n");
    printf("Destino ou origem errado -> vertice -i nao eh fonte ou vertice -l nao eh sumidouro");
    return;
}

void zerar(int array[], int tam){
    for(int i=0; i<tam; i++) array[i] = 0;
}
