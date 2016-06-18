#include <iostream.h>
#include <conio.h>
#include <timer.h>

int max(int a,int b)
{
    return ((a > b)?a:b);
}

class Case
{
    int *value,*weight,capacity,MaxValue,*final,x,**table,n;
    void prepareTable();
  public :
    Case()
    {
       capacity = x = -1;
    }
    void read();
    void BestSet();
    void printSolution();
};

void Case :: read()
{
    cout << "\nGive the number of items : ";
    cin >> n;
    weight = new int [n + 1];weight[0] = 0;
    value = new int [n + 1];value[0] = 0;
    *table = new int [n + 1];
    for(int i = 0;i <= n;i++) table[i] = new int [n + 1];

    for(int row = 0;row <= n;row++)
	table[row][0] = 0;

    for(int col = 0;col <= n;col++)
	table[0][col] = 0;

    cout << "\nNow give the item's value and its weights\n";

    for(int j = 1;j <= n;j++)
    {
       cout << "\nItem " << j << "'s value : ";
       cin >> value[j];
       cout << "Its' Weight : "; cin >> weight[j];
    }

    cout << "\nNow give the knapsack's max capacity : ";
    cin >> capacity;
}

void Case :: prepareTable()
{
    for(int row = 1;row <= n;row++)
	for(int col = 1;col <= n;col++)
	{
	    if(weight[row] > col) table[row][col] = table[row - 1][col];
	    else
	    table[row][col] = max(table[row - 1][col],value[row] + table[row - 1][col - weight[row]]);
	}
}

void Case :: BestSet()
{
    int item,mass;
    prepareTable();
    final = new int [n];

    item = n;mass = capacity;

    while(item > 0 && mass > 0)
    {
	if(table[item][mass] != table[item - 1][mass])
	{
	   mass -= weight[item];
	   final[++x] = item;
	}

	item--;
    }
}

void Case :: printSolution()
{
   cout << "\nThe optimal Knapsack configuration is : ";
   cout << "\n[ " << final[0];MaxValue = value[final[0]];

   for(int i = 1;i <= x;i++)
   {
       cout << " , " << final[i];
       MaxValue += value[final[i]];
   }
   cout << " ]\n";

   cout << "The profit is : " << MaxValue << "\n";
}

int main()
{
   clrscr();
   Case obj;
   obj.read();
   obj.BestSet();
   obj.printSolution();
   getch();
   return 0;
}
