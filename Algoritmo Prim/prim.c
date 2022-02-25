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

  int pai[nmr_vertices];
  int matriz_adj[nmr_vertices][nmr_vertices];
  grafo(nmr_vertices, nmr_arestas, matriz_adj, ptr);

  int TOTAL = prim(nmr_vertices, matriz_adj, initV - 1, pai);

  if (out != 0)
  {
    FILE *saida = fopen(argv[out], "w");
    if (soluc == true)
    {
      for (int i = 0; i < nmr_vertices; i++)
      {
        fprintf(saida, "(%d,%d)", pai[i] + 1, i + 1);
      }
      fprintf(saida, "\n");
    }

    fprintf(saida, "%d\n", TOTAL);
  }
  else
  {
    if (soluc == true)
    {
      for (int i = 0; i < nmr_vertices; i++)
      {
        printf("(%d,%d)", pai[i] + 1, i + 1);
      }
      printf("\n");
    }

    printf("%d\n", TOTAL);
  }

  return 0;
}
