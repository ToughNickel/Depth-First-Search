#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <timer.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 20

class Graph
{
     int edges[MAX][MAX],nodes,sides,x,v,Wsum;
     int *d,*sptSet;
     int minDistance();
    public :
     Graph()
     {
	nodes = sides = Wsum = 0;
	x = v = -1;
     }
     void input();
     void shortest_path_frm(int);
     void print();
     void randomize();
};

void Graph :: input()
{
     while(1)
     {
	 cout << "\nGive the number of nodes : ";cin >> nodes;
	 if(nodes >= MAX) cout << "Give number of nodes less than 20\n";
	 else break;
     }
     d = new int [nodes];
     sptSet = new int [nodes];

     for(int k = 0;k < nodes;k++)
	 for(int l = 0;l < nodes;l++)
	 {
             d[k] = INT_MAX;
	     sptSet[k] = 0;
	     edges[k][l] = 999;
	 }

     cout << "Give the number of edges : ";cin >> sides;
     cout << "\nNow give edges one-by-one\n";
     while(sides--)
     {
	 int start,end,weight;
	 cout << "From : ";cin >> start;
	 cout << "To : ";cin >> end;
	 cout << "Distance : ";cin >> weight;cout << "\n";
	 edges[start - 1][end - 1] = weight;edges[end - 1][start - 1] = weight;
     }
}

int Graph :: minDistance()
{
     int min = INT_MAX, min_index = 999;
 
     for (int v = 0; v < nodes; v++)
	 if (!sptSet[v] && d[v] <= min)
	 {
	     min = d[v];
	     min_index = v;
	 }

     return min_index;
}

void  Graph :: shortest_path_frm(int source)
{
     d[source - 1] = 0;
     for (int count = 0; count < nodes-1; count++)
     {
       int u = minDistance();
       sptSet[u] = 1;
       for (int v = 0; v < nodes; v++)
	 if (!sptSet[v] && edges[u][v] && d[u] != INT_MAX && d[u]+edges[u][v] < d[v])
	     d[v] = d[u] + edges[u][v];
     }
}

void Graph :: print()
{
     printf("Vertex \tDistance from Source\n");

   for (int i = 0; i < nodes; i++)
      printf("%d \t\t %d\n", i + 1, d[i]);
}

void Graph :: randomize()
{
    Timer t;
    for(int i = 1;i < MAX;i++)
    {
	nodes = i;
	visited = new int [nodes];counter = new int [nodes];
	x = v = -1;
	for(int k = 0;k < nodes;k++)  visited[k] = 0;
	for(int row = 0;row < nodes;row++)
	    for(int col = 0;col < nodes;col++)
		edges[row][col] = -1;

	for(int w = 0;w < nodes;w++)
	    for(int s = 0;s < nodes;s++)
	    {
		int tmp = (rand() % 999) + 1;
		if(edges[w][s] != -1) continue;
		else  edges[w][s] = edges[s][w] = tmp;
	    }

	t.start();shortest_path_frm(1);t.stop();
	cout << "\nFor operation : " << nodes;
	cout << " time taken is : " << t.time() << " seconds";
	t.reset();
    }
}

int main()
{
    Graph G;int src = 1;
    Timer t;clrscr();
    G.input();
    cout << "Give the source node (where to start) : ";cin >> src;
    t.start();G.shortest_path_frm(src);t.stop();
    G.print();
    cout << "\nTime taken for this is : " << t.time() << " seconds\n";
    //G.randomize();
    getch();
    return 0;
}
