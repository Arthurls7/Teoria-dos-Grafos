#include "functions.h"

void help()
{
  printf("----------- Algoritmo de Prim ------------\n");
  printf("No diretorio temos um arquivo no formato \".txt\" com o exemplo da entrada\n");
  printf("Nosso algoritmo funciona do modo a seguir:\n\n");
  printf("Consideramos um vertice inicial na arvore, e a cada iteracao, o algoritmo procura a aresta de menor peso que conecte um vertice da arvore a outro que ainda nao esteja na arvore.\n\nEsse vertice eh adicionado a arvore e o processo se repete, ate que todos o vertices facam parte da arvore ou quando ache um grafo desconexo.\n\n");
  printf("- Estrutura do grafo feito com matriz de adjacencia.\n\n");
  printf("- Consideramos que os vertices comecam com 1 e pesos com numeros inteiros.\n\n");
  printf("Erros possiveis:\n\n");
  printf("Problema no arquivo de entrada -> provavelmente foi passado o caminho errado, ou o arquivo errado para o programa ler\n\n");
  printf("- Caso a entrada seja com grafos direcionados o resultado pode sair diferente, pois a matriz ira transforma-lo em grafo nao dirigido.\n\n\n");
  printf("Grafo nao conexo -> o algoritmo nao tera solucao\n\n");
}

void grafo(int nmr_vertices, int nmr_arestas, int matriz_adj[][nmr_vertices], FILE *ptr)
{
  // Preencher matriz
  int origem, destino, peso;
  for (int i = 0; i < nmr_vertices; i++)
  {
    for (int j = 0; j < nmr_vertices; j++)
    {
      matriz_adj[i][j] = -1;
    }
  }
  // Preencher arestas
  for (int i = 0; i < nmr_arestas; i++)
  {
    fscanf(ptr, "%d %d", &origem, &destino);

    char terc_coluna;
    fscanf(ptr, "%c", &terc_coluna);
    if (terc_coluna == '\n')
    {
      peso = 1;
    }
    else
    {
      fscanf(ptr, "%d", &peso);
    }
    matriz_adj[origem - 1][destino - 1] = peso;
    matriz_adj[destino - 1][origem - 1] = peso;
  }
}

int prim(int nmr_vertices, int matriz[][nmr_vertices], int origem, int pai[])
{
  int menor_peso, total = 0, destino;

  // criando a árvore geradora
  for (int i = 0; i < nmr_vertices; i++)
  {
    pai[i] = -1;
  }
  pai[origem] = origem;

  while (true)
  {
    bool primeiro = true;
    for (int i = 0; i < nmr_vertices; i++)
    {
      if (pai[i] != -1)
      {
        for (int j = 0; j < nmr_vertices; j++)
        {
          if (pai[j] == -1)
          {
            if (matriz[i][j] != -1)
            {
              if (primeiro == true)
              {
                menor_peso = matriz[i][j];
                origem = i;
                destino = j;
                primeiro = false;
              }
              else
              {
                if (matriz[i][j] < menor_peso)
                {
                  menor_peso = matriz[i][j];
                  origem = i;
                  destino = j;
                }
              }
            }
          }
        }
      }
    }
    if (primeiro == true)
    {
      break;
    }
    pai[destino] = origem;
    total = total + menor_peso;
  }
  return total;
}
