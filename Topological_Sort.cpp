#include <iostream.h>
#include <conio.h>
#include <timer.h>
#include <stdlib.h>

class Stack
{
    int top;
    int a[800];
  public :
    Stack()
    {
       top = -1;
       for(int i = 0;i < 800;i++) a[i] = 0;
    }
    void push(int ele)
    {
	a[++top] = ele;
    }
    int getTop()
    {
       return a[top];
    }
    void pop()
    {
       top--;
    }

    int isEmpty()
    {
	return(top == -1);
    }

    void clear()
    {
	top = -1;
    }
};

class Graph
{
    int *visited;
    int nodes,sides;
    int **edges;
    Stack stck;
  public :
    Graph()
    {
       nodes = sides = 0;
    }
    void input()
    {
	cout << "\nGive the number of nodes : ";cin >> nodes;
	visited = new int [nodes];
	*edges = new int [nodes];
	for(int i = 0;i < nodes;i++) edges[i] = new int [nodes];

	for(int row = 0;row < nodes;row++)
	    for(int col = 0;col < nodes;col++)
		visited[row] = edges[row][col] = 0;

	cout << "\nGive the number of edges : ";cin >> sides;
	while(sides--)
	{
	    int start,end;
	    cout << "From : ";cin >> start;
	    cout << "To : ";cin >> end;cout << "\n";
	    edges[start  - 1][end - 1] = 1;
	}
    }

    void dfs(int source)
    {
	visited[source] = 1;
	for(int i = 0;i < nodes;i++)
	    if((edges[source][i] > 0) && !visited[i])
	       dfs(i);

	stck.push(source + 1);
    }

    void topo_sort()
    {
       for(int i = 0;i < nodes;i++)
	   if(!visited[i])
	      dfs(i);
    }

    void print()
    {
	cout << "\nThe topologically sorted order is : \n";
	cout << "\n[ " << stck.getTop();stck.pop();
	while(!stck.isEmpty())
	{
	    cout << " , " << stck.getTop();
	    stck.pop();
	}
	cout << " ]\n";
    }

    void randomize()
    {
	Timer t;
	for(int i = 1;i < 20;i++)
	{
	   cout << "\nFor operation : " << i;
	   nodes = i;

	   //general initializations
	   visited = new int [nodes];
	   *edges = new int [nodes];
	   for(int i = 0;i < nodes;i++) edges[i] = new int [nodes];
	   for(int row = 0;row < nodes;row++)
	       for(int col = 0;col < nodes;col++)
	       {   visited[row] = 0;
		   edges[row][col] = -1;
	       }
	   //-----------------------

	   for(int k = 0;k < nodes;k++)
	      for(int l = 0;l < nodes;l++)
	      {
		  if(edges[k][l] != -1) continue;
		  edges[k][l] = rand() % 2;
		  edges[l][k] = 0;
	      }

	  t.start();topo_sort();t.stop();stck.clear();
	  cout << " time taken is : " << t.time() << " seconds";
	}
    }
};

int main()
{
    clrscr();
    Timer t;
    Graph G;
    G.input();
    t.start();G.topo_sort();t.stop();
    G.print();
    cout << "\nTime taken for this is : " << t.time() << " seconds\n";
    //G.randomize();      //uncomment this only for bulk operation(by commenting from G.input() to jus before G.randomize())
    getch();
    return 0;
}
