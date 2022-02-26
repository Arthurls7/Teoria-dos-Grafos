#include "functions.h"

int main(int argc, char *argv[])
{
  int initV = 0, lastV = 0, in = 0, out = 0;
  bool soluc = false;

  for (int i = 0; i < argc; i++)
  {
    if (strcmp(argv[i], "-i") == 0)
      sscanf(argv[i + 1], "%d", &initV);
    if (strcmp(argv[i], "-l") == 0)
      sscanf(argv[i + 1], "%d", &lastV);
    if (strcmp(argv[i], "-s") == 0)
      soluc = 1;
    if (strcmp(argv[i], "-o") == 0)
      out = i + 1;
    if (strcmp(argv[i], "-f") == 0)
    {
      if (strcmp(argv[i + 1], "-s") == 0)
        in = i + 2;
      else
        in = i + 1;
    }

    if (strcmp(argv[i], "-h") == 0)
    {
      help();
      return 0;
    }
  }

  FILE *ptr = fopen(argv[in], "r");
  if (ptr == NULL)
  {
    printf("Problema no arquivo de entrada.");
    return 0;
  }

  int nmr_vertices, nmr_arestas;
  fscanf(ptr, "%d %d", &nmr_vertices, &nmr_arestas);
  int matriz_adj[nmr_vertices][nmr_vertices];
  // printf("Numero de ver %d \n", nmr_vertices);
  grafo(nmr_vertices, nmr_arestas, matriz_adj, ptr);

  int pai[nmr_vertices], distancia[nmr_vertices];
  Menor_Caminho(nmr_vertices, initV - 1, pai, distancia, matriz_adj);

  // ============ Saída ===========

  if (out != 0)
  {
    output(argv[out], lastV, initV, distancia, nmr_vertices);
  }
  else
  {

    printf("\nRESPOSTA: \n\n");
    if (lastV != 0)
    {
      printf("%d\n", distancia[lastV - 1]);
    }
    if (lastV == 0 && initV != 0)
    {
      for (int i = 0; i < nmr_vertices; i++)
      {
        printf("%d:%d ", i + 1, distancia[i]);
        if (i == nmr_vertices - 1)
        {
          printf("\n");
        }
      }
    }

    printf("\n\n");
  }

  return 0;
}
