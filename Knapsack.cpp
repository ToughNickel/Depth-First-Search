#include <iostream.h>
#include <conio.h>
#include <timer.h>
#include <stdlib.h>

int max(int a,int b)
{
    if(a > b) return a;
    else return b;
}

class Knapsack
{
    int *weight,*value,**table,*final,n,Mval,Mwt,capacity;
    int prepareTable(int,int);
  public :
    Knapsack()
    {
       n = Mval = Mwt = capacity = 0;
    }
    void input();
    void BestSet();
};

void Knapsack :: input()
{
    cout << "\nGive the number of items : ";cin >> n;
    weight = new int [n + 1];value = new int [n + 1];
    *table = new int [n + 1]; final = new int [n];
    weight[0] = 0;value[0] = 0;
    cout << "\nNow give the item's values and its weights\n";
    for(int s = 1;s <= n;s++)
    {
       cout << "Value : ";cin >> value[s];
       cout << "its Weight : ";cin >> weight[s];cout << "\n";
    }

    cout << "\nGive Knapsack's maximum capacity : ";cin >> capacity;
    for(int w = 0;w <= n;w++) table[w] = new int [capacity + 1];

    for(int i = 0;i <= n;i++)
	for(int j = 0;j <= capacity;j++)
	{
	    if(!i || !j) table[i][j] = 0;
	    else table[i][j] = -1;
	}
}

int Knapsack :: prepareTable(int i,int j)
{
    int v = 0,p1 = 0,p2 = 0;
    if(table[i][j] < 0)
    {
	if(j < weight[i]) v = prepareTable(i - 1,j);
	else
	{
	    p1 = prepareTable(i - 1,j);
	    p2 = prepareTable(i - 1,j - weight[i]) + value[i];
	    v = max( p1 , p2 );
	}

	table[i][j] = v;
    }
    return table[i][j];
}

void Knapsack :: BestSet()
{
    int items = n,mass = capacity,x = -1;
    Mval = prepareTable(n,capacity);

    while(items && mass)
    {
	if(table[items][mass] != table[items - 1][mass])
	{
	   mass -=  weight[items];
	   final[++x] = items;
	}
	items--;
    }

    cout << "\nThe optimal knapsack configuration is \n";
    cout << "\n[ " << final[0];Mwt += weight[ final[0] ];
    for(int i = 1;i <= x;i++)
    {
       cout << " , " << final[i];
       Mwt += weight[ final[i] ];
    }
    cout << " ]\n";
    cout << "The maximum value possible is : " << Mval;
    cout << "\nWith maximum weight : " << Mwt;cout << "\n";
}

int main()
{
    clrscr();
    Knapsack K;
    K.input();
    K.BestSet();
    getch();
    return 0;
}
