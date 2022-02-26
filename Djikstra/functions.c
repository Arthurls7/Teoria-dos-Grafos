#include "functions.h"
void help()
{
  printf("\n\n\n----------- Algoritmo de Dijkstra ------------\n");
  printf("No diretorio temos um arquivo no formato \".txt\" com o exemplo da entrada\n");
  printf("Nosso algoritmo funciona do modo a seguir:\n\n");
  printf("Consideramos o vertice inicial na arvore com distancia 0 e o restante dos vertices com -1. Recupera vertice com menor distancia ainda nao visitado e marca como vertice visitado, ate preencher o vetor que marca as menores distancias da origem ate cada vertice\n\n");
  printf("- Estrutura do grafo feito com matriz de adjacencia.\n\n");
  printf("- Consideramos que os vertices comecam com 1 e pesos com numeros inteiros.\n\n");
  printf("- ACEITA GRAFOS NAO DIRECIONADOS (pelo fato de ser feito com matriz de adjacencia, portanto, escolhemos que a entrada fosse com grafos nao dirigidos, caso queira entroduzir GRAFO DIRECIONADO na entrada eh so comentar a linha 52 do codigo)\n\n");
  printf("Erros possiveis:\n\n");
  printf("- Problema no arquivo de entrada -> provavelmente foi passado o caminho errado, ou o arquivo errado para o programa ler\n\n");
  printf("- Grafo nao conexo -> o algoritmo nao tera solucao\n\n");
  printf("- Caso a entrada seja com grafos direcionados o resultado pode sair diferente, pois a matriz ira transforma-lo em grafo nao dirigido.\n\n\n");
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

//=========== Algoritmo de Dijkstra ============

// Procura menor vértice com menor distância e que não tenha sido visitado
int Menor_Distancia(int distancia[], int visitado[], int nmr_vertices)
{
  int i, menor = -1;
  bool primeiro = true;
  for (i = 0; i < nmr_vertices; i++)
  {
    if (distancia[i] >= 0 && visitado[i] == 0)
    {
      if (primeiro = true)
      {
        menor = i;
        primeiro = false;
      }
      else
      {
        if (distancia[menor] > distancia[i])
        {
          menor = i;
        }
      }
    }
  }
  return menor;
}

void Menor_Caminho(int nmr_vertices, int origem, int pai[], int distancia[], int matriz[][nmr_vertices])
{

  int i, contador, u;
  contador = nmr_vertices;
  bool visitado[nmr_vertices];
  // inicializando distancia e pai com -1
  for (int i = 0; i < nmr_vertices; i++)
  {
    pai[i] = -1;
    distancia[i] = -1;
    visitado[i] = false;
  }
  distancia[origem] = 0;
  // Procura vertice com menor distancia e marca como visitado
  while (contador > 0)
  {
    // printf("Foi procurar a menor distancia\n");
    u = Menor_Distancia(distancia, visitado,
                        nmr_vertices);
    // printf("Menor distancia: %d\n", u);

    if (u == -1)
    {
      printf("Grafo não conexo!\n");
      break;
    }
    // printf("O vertice %d foi visitado\n", u);
    visitado[u] = true;
    contador--;
    // printf("Linha 5 coluna 0: %d \n", matriz[4][0]);
    for (int j = 0; j < nmr_vertices; j++)
    {
      // printf("Entrou no for\n");
      // printf(" entrando no v1: %d e v2: %d\n", u, j);
      if (matriz[u][j] != -1)
      {
        // printf("Achou vizinho\n");

        if (distancia[j] < 0)
        {
          distancia[j] = distancia[u] + matriz[u][j];
          pai[j] = u;
        }
        else
        {
          if (distancia[j] > distancia[u] + matriz[u][j])
          {
            distancia[j] = distancia[u] + matriz[u][j];
          }
          pai[j] = u;
        }
      }
    }
  }
}

void output(char arquivo[], int LastV, int InitV, int distancia[], int nmr_vertices)
{

  FILE *ptr = fopen(arquivo, "w");
  if (LastV != 0)
  {
    fprintf(ptr, "%d\n", distancia[LastV - 1]);
    return;
  }
  if (LastV == 0 && InitV != 0)
  {
    for (int i = 0; i < nmr_vertices; i++)
    {
      fprintf(ptr, "%d:%d ", i + 1, distancia[i]);
      if (i == nmr_vertices - 1)
      {
        fprintf(ptr, "\n");
      }
    }
  }
  fclose(ptr);
}
