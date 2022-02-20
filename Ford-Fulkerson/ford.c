#include "functions.h"

int main(int argc, char *argv[]){
    int initV = 0, lastV = 0, soluc = 0, inFile = 0, outFile = 0; 

    for(int i=0; i<argc; i++){
        if(strcmp(argv[i], "-i") == 0) sscanf(argv[i+1], "%d", &initV);
        if(strcmp(argv[i], "-l") == 0) sscanf(argv[i+1], "%d", &lastV);
        if(strcmp(argv[i], "-s") == 0) soluc = 1;
        if(strcmp(argv[i], "-o") == 0) outFile = i+1;
        if(strcmp(argv[i], "-f") == 0){
            if(strcmp(argv[i+1], "-s") == 0) inFile = i+2;
            else inFile = i+1;
        }

        if(strcmp(argv[i], "-h") == 0){
            help();
            return 0;
        }
    }

    initV -= 1;
    lastV -= 1;

    FILE *ptr = fopen(argv[inFile], "r");
    if(ptr == NULL) return 0;

    //Recebendo do arquivo
    int nVertex, nEdges;
    fscanf(ptr, "%d %d", &nVertex, &nEdges);
    //printf("%d %d\n", nVertex, nEdges);
    //Array de visitados
    int visited[nVertex];
    zerar(visited, nVertex);

    //Grafo
    int grafo[nVertex][nVertex];

    for(int i=0; i<nVertex; i++){
        for(int j=0; j<nVertex; j++){
            grafo[i][j] = 0;
        } 
    }

    
    for(int i=0; i<nEdges; i++){
        int v1, v2, aresta;
        char coluna;

        fscanf(ptr, "%d %d", &v1, &v2);
        fscanf(ptr, "%c", &coluna);

        if(coluna == ' ') fscanf(ptr, "%d", &aresta);
        else aresta = 1;

        grafo[v1-1][v2-1] = aresta;
    }

    if(fonte_sumidouro(initV, lastV, nVertex, grafo) == 1){
        int flow = max_flow(initV, lastV, visited, nVertex, grafo);
        
        if(outFile != 0){
            FILE *saida = fopen(argv[outFile], "w");
            if(soluc == 0) fprintf(saida, "%d", flow);
            else{
                for(int i=0; i<nVertex; i++){
                    for(int j=0; j<nVertex; j++){
                        if(grafo[i][j] == 0) continue;
                        fprintf(saida, "(%d, %d) %d\n", i+1, j+1, grafo[i][j]);
                    }
                }
            }
        } else{
            if(soluc == 0) printf("%d", flow);
                else{
                    for(int i=0; i<nVertex; i++){
                        for(int j=0; j<nVertex; j++){
                            if(grafo[i][j] == 0) continue;
                            printf("(%d, %d) %d\n", i+1, j+1, grafo[i][j]);
                        }
                    }
                }
        }
        
        
    } 
    
    else{
        printf("Destino ou origem errados");
        return 0;
    }
}
