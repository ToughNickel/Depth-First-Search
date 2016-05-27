#include <iostream.h>
#include <conio.h>
#include <timer.h>
#include <stdlib.h>

#define MAX 20

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
	 cout << "From  " << start << " To  " << end << "  (wt : "<< weight<<")\n";
     }
};

class Graph
{
     int edges[MAX][MAX],nodes,sides,x,*visited,v,Wsum,*counter;
     Edge *e;
    public :
     Graph()
     {
	 nodes = sides = Wsum = 0;
	 x = v = -1;
     }
     void input();
     void start_PRIMS_frm(int);
     void printTree();
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
     visited = new int [nodes];counter = new int [nodes];

     for(int k = 0;k < nodes;k++)
	 for(int l = 0;l < nodes;l++)
	 {
	     visited[k] = 0;
	     edges[k][l] = 999;
	 }

     cout << "Give the number of edges : ";cin >> sides;
     e = new Edge [sides];
     cout << "\nNow give edges one-by-one\n";
     while(sides--)
     {
	 int start,end,weight;
	 cout << "From : ";cin >> start;
	 cout << "To : ";cin >> end;
	 cout << "Weight : ";cin >> weight;cout << "\n";
	 edges[start - 1][end - 1] = weight;edges[end - 1][start - 1] = weight;
     }
}

void  Graph :: start_PRIMS_frm(int source)
{
     int min = 999,st,en;
     counter[++v] = source - 1;visited[source - 1] = 1;
     while(x < nodes - 2)
     {
	  for(int i = 0;i <= v;i++)
	     for(int j = 0;j < nodes;j++)
	     {
		 if(visited[j]) continue;
		 if(edges[counter[i]][j] < min)
		 {
		    min =  edges[counter[i]][j];
		    st = counter[i] + 1;en = j + 1;
		 }
	     }
	  e[++x].start = st;e[x].end = en;e[x].weight = min;
	  Wsum += min;min = 999;
	  counter[++v] = en - 1;visited[en - 1] = 1;
     }
}

void Graph :: printTree()
{
     cout << "\nWrite all the nodes first\n";
     for(int i = 0;i <= x;i++)
     {
	 cout << "Then draw ";
	 e[i].print();cout << "\n";
     }
     cout << "\nWeight of the minimum spanning tree thus formed : " << Wsum;
     cout << "\n";Wsum = 0;
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
		edges[row][col] = (rand() % 999) + 1;

	t.start();start_PRIMS_frm(1);t.stop();
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
    t.start();G.start_PRIMS_frm(src);t.stop();
    G.printTree();
    cout << "\nTime taken for this is : " << t.time() << " seconds\n";
    G.randomize();
    getch();
    return 0;
}
