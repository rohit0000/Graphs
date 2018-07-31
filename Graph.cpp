#include <stdio.h>
#include <stdlib.h>
#include "GRAPH.h"
 
 
struct graph{
   int V;
   int E;
   int **adj;
}; 
 
 
Edge EDGE(int x, int y){ // edge constructor
   Edge *E = malloc(sizeof *E);
   E->v1 = x;
   E->v2 = y;
   return *E;
}
 
// Adjacency Matrix initialized with zero
int **zeros(int V){
   int i, j;
   int **temp = malloc(V * sizeof(int *));
   
   for(i = 0; i < V; i++)
       temp[i] = malloc(V * sizeof(int *));
 
   for(i = 0; i < V; i++)
       for(j = 0; j < V; j++)
           temp[i][j] = 0;
 
   return temp;   
}
 
 
 
Graph init(int V){
   Graph G = malloc(sizeof *G);
   G->V = V;
   G->E = 0;
   G->adj = zeros(V);
   return G;
}
 
 
void insertE(Graph G, Edge e){
   int v1 = e.v1;
   int v2 = e.v2;
   
   if(G->adj[v1][v2] == 0)
      G->E++;
 
   G->adj[v1][v2] = 1;
   G->adj[v2][v1] = 1; 
}
 
 
void removeE(Graph G, Edge e){
   int v1 = e.v1;
   int v2 = e.v2;
   if(G->adj[v1][v2] == 1)
	G->E--;
 
   G->adj[v1][v2] = 0;
   G->adj[v2][v1] = 0;
}
 
 
int edges(Edge a[], Graph G){
   int v1, v2, E = 0;
   for(v1 = 0; v1 < G->V; v1++)
       for(v2 = v1+1; v2 < G->V; v2++)
           if(G->adj[v1][v2] == 1)
              a[E++] = EDGE(v1, v2);
   return E; 
}
 
 
void destroy(Graph G){
   int i;
   for (i = 0; i < (G->V); i++)
  	{
  		free(G->adj[i]);
  	}
	free(G);
}
 
 
void show(Graph G){
    int i, j;
    printf("\nThe graph has %d nodes and %d edges.\n", G->V, G->E);
    for(i = 0; i < G->V; i++){
	printf("%3d: ", i);
        for(j = 0; j < G->V; j++)
           if(G->adj[i][j] == 1)
              printf(" %3d", j);
        printf("\n");  
    }
}
