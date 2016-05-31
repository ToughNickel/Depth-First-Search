#include <iostream.h>
#include <conio.h>
#include <timer.h>
#include <stdlib.h>
#include <limits.h>

int floor(float num)
{
    return ( (int)num );
}

class ArrayList
{
    int n,*a;
    void makeHeap(int);
  public :
    ArrayList()
    {
	n = 0;
    }
    void input();
    void heapsort();
    void print();
    void randomize();
};

void ArrayList :: input()
{
    cout << "\nGive the size of the array : ";cin >> n;
    a = new int [n + 1];a[0] = 999;
    cout << "\nNow give the elements one-by-one\n";
    for(int i = 1;i <= n;i++) cin >> a[i];
}

void ArrayList :: makeHeap(int size)
{
    for(int i = floor(size / 2);i >= 1;i--)
    {
	int k = i;int v = a[k];
	int heap = 0;

	while(!heap && (2*k) <= size)
	{
	    int j = 2 * k;
	    if(j < size)
	       if(a[j] < a[j + 1]) j ++;

	    if(v >= a[j]) heap = 1;
	    else
	    {
	       a[k] = a[j];k = j;
	    }
	}

	a[k] = v;
    }
}

void ArrayList :: heapsort()
{
    for(int i = n;i >= 1;i--)
    {
	makeHeap(i);
	int tmp = a[1];
	a[1] = a[i];
	a[i] = tmp;
    }
}

void ArrayList :: print()
{
    cout << "\nThe array after sorting is : \n";
    cout << "\n[ " << a[1];
    for(int i = 2;i <= n;i++) cout << " , " << a[i];
    cout << " ]\n";
}

void ArrayList :: randomize()
{
    Timer t;
    for(int i = 1000;i <= 5000;i += 1000)
    {
       n = i; a = new int [n + 1];a[0] = INT_MAX;
       for(int j = 1;j <= n;j++) a[j] = i - j;
       t.start();heapsort();t.stop();
       cout << "\nFor operation : " << n;
       cout << " time taken is : " << t.time() << " seconds";
       t.reset();
    }
}

int main()
{
    clrscr();
    Timer t;
    ArrayList obj;
    obj.input();
    t.start();obj.heapsort();t.stop();
    obj.print();
    cout << "\nTime taken for this is : " << t.time() << " seconds\n";
    //obj.randomize();       //uncomment this only for bulk operation
    getch();
    return 0;
}
