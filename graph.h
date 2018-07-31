/// G = {V, E}
 
typedef struct {
   int v1;
   int v2;
} Edge;
Edge EDGE(int, int); // edge constructor
 
typedef struct graph *Graph;
Graph init(int);
void insertE(Graph, Edge);
void removeE(Graph, Edge);
int edges(Edge [], Graph G);
void destroy(Graph);
void show(Graph);
