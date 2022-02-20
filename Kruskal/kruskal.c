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

    //Comecou a bagaca
    FILE *ptr = fopen(argv[inFile], "r");
    if (ptr == NULL){
        printf("Problema no arquivo de entrada.");
        return 0;
    }

    //Pegando as entradas
    int nVertex, nEdges;
    fscanf(ptr, "%d %d", &nVertex, &nEdges);
    
    edge edges[nEdges];
    for(int i=0; i<nEdges; i++){
        fscanf(ptr, "%d %d", &edges[i].v1, &edges[i].v2);
        
        char coluna;
        fscanf(ptr, "%c", &coluna);
        //printf("Coluna: %c", coluna);

        if(coluna == ' '){
            fscanf(ptr, "%d", &edges[i].distance);
        } else{
            edges[i].distance = 1;
        }
    } 
    
    //Definindo as arvores individuais como pai de si mesmos
    for(int i=0; i<=nVertex; i++) father[i] = i;
    
    //Ordenando o array de arestas
    qsort(edges, nEdges, sizeof(edge), compareDistance);
    
    //Guardando resultados
    int results[nEdges][3];
    int totalCost = 0, x = 0;
    
    //Agora comparando as arestas da menor pra maior e ligando elas
    for(int i=0; i<nEdges; i++){
        int f1 = compareFather(edges[i].v1);
        int f2 = compareFather(edges[i].v2);
            
        //Verifica se sao independentes pra evitar de fazer um ciclo
        if(f1 != f2){
            //printf("%d <-> %d, distance: %d\n", edges[i].v1, edges[i].v2, edges[i].distance);
            //agora colocamos na mesma arvore
            unionTree(edges[i].v1, edges[i].v2);
                
            //armazenando custo total e pares
            totalCost += edges[i].distance;
            results[x][0] = edges[i].v1;
            results[x][1] = edges[i].v2;
            results[x][2] = edges[i].distance;
            x++;
        }
    }


    if(outFile == 0){
        if(soluc != 0) imprimirS(x, results);
        else printf("%d", totalCost);
    } else{
        imprimirA(argv[outFile], x, results, soluc, totalCost);
    }
}
