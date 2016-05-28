#include <iostream.h>
#include <conio.h>
#include <timer.h>
#include <stdlib.h>

#define MAX 20
/*---------------------------------------------------------------------
for general purpose comment the randomize() statement in main() i.e., G.randomize()
and for getting the bulk data...comment all except G.randomize

telling this just for clarity
---------------------------------------------------------------------*/

class Edge
{
    public :
       int start,end,weight;
    Edge()
    {
       start = end = weight = 0;
    }
    void print()
    {
	cout << "From " << start << " To " << end << " (wt : " << weight << ")\n";
    }
};

class Graph
{
   int **edges,nodes,sides,x,*parent,Wsum;
   Edge *e;
   public :
      Graph()
      {
	  nodes = sides = Wsum = 0;
	  x = -1;
      }
      void input();
      void start_Kruskal();
      void printTree();
      void randomize();
};

void Graph :: input()
{
   while(1)
   {
       cout << "\nGive the number of nodes : ";cin >> nodes;
       if(nodes >= MAX) cout << "Give the number lesser than 22\n";
       else break;
   }

   //General initialisation
   parent = new int [nodes];
   *edges = new int [nodes];
   for(int j = 0;j < nodes;j++) edges[j] = new int [nodes];

   for(int row = 0;row < nodes;row++)
      for(int col = 0;col < nodes;col++)
      {
	  parent[row] = -1;
	  edges[row][col] = 999;
      }
  //--------------------------

  cout << "\nGive the number of edges : ";cin >> sides;
  e = new Edge [sides];
  cout << "\nGive the edges one-by-one\n";
  while(sides--)
  {
      int start,end,weight;
      cout << "From : ";cin >> start;
      cout << "To : ";cin >> end;
      cout << "Weight : ";cin >> weight;cout << endl;
      edges[start - 1][end - 1] = weight;edges[end - 1][start - 1] = weight;
  }
}

void Graph :: start_Kruskal()
{
    while(x < nodes - 2)
    {
	 int min = 999,start,end,u,v;
	 for(int i = 0;i < nodes;i++)           //finding the minimum
	     for(int j = 0;j < nodes;j++)
		if(edges[i][j] < min)
		{
		   min = edges[i][j];
		   start = u = i;
		   end = v = j;
		}

	 //checking for cycles 
	 while(parent[u] != -1) u = parent[u];
	 while(parent[v] != -1) v = parent[v];

	 if(u != v)
	 {
	    e[++x].start = start + 1;
	    e[x].end = end + 1;
	    e[x].weight = min;
	    Wsum += min;
	    parent[v] = u;
	 }
	 edges[start][end] = 999;edges[end][start] = 999;
    }
}

void Graph :: printTree()
{
   cout << "\nFirst of all .. draw all the nodes without any edges\n";
   for(int i = 0;i <= x;i++)
   {
       cout << "then draw ";
       e[i].print();
       cout << "\n";
   }
   cout << "\nThe weight of the minimum spanning tree thus formed : " << Wsum;
   Wsum = 0;
}

void Graph :: randomize()
{
   Timer t;e = new Edge [MAX];
   for(int i = 1;i < MAX;i++)
   {
       nodes = i;

       parent = new int [nodes];
       *edges = new int [nodes];
       for(int j = 0;j < nodes;j++) edges[j] = new int [nodes];
       x = -1;

       for(int row = 0;row < nodes;row++)
	   for(int col = 0;col < nodes;col++)
	       edges[row][col] = -1;
	       
       for(int k = 0;k < nodes;k++)
           for(int l = 0;l < nodes;l++)
           {
           	int tmp = (rand() % 999) + 1;
           	if(edges[k][l] != -1) continue;
           	else edges[k][l] = edges[l][k] = tmp;
           }
  
       t.start();start_Kruskal();t.stop();
       cout << "\nFor operation " << nodes;
       cout << " time taken is : " << t.time() << " seconds";
       t.reset();
   }
}

int main()
{
    Graph G;
    Timer t;
    clrscr();

    G.input();
    t.start();G.start_Kruskal();t.stop();
    G.printTree();
    cout << "\nTime taken for this is : " << t.time() << " seconds\n";
    //G.randomize();                   //uncomment this only for bulk operation..,otherwise its gonna mess up the screen

    getch();
    return 0;
}
