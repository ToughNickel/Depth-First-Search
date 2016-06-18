#include <iostream.h>
#include <conio.h>
#include <timer.h>
#include <stdlib.h>
#include <malloc.h>

class ArrayList
{
    int *a,n;
    int median(int,int);
   public :
     void read();
     void quicksort();
     void actual_sort(int,int);
     void print();
     void randomize(int);
};

void ArrayList :: read()
{
    cout << "\nGive the number of elements : ";
    cin >> n;
    a = new int [n];
    cout << "\nNow give elements one - by - one\n";
    for(int i = 0;i < n;i++) cin >> a[i];
}

void ArrayList :: quicksort()
{
    actual_sort(0,n - 1);
}

void ArrayList :: actual_sort(int low,int high)
{
    int l;
    if(low < high)
    {
	l = median(low,high);
	actual_sort(low,l - 1);
	actual_sort(l + 1,high);
    }
}

int ArrayList :: median(int left,int right)
{
    int pivot,l,r;
    l = left;r = right;
    pivot = left;

    while(1)
    {
	int tmp;
	if(pivot == l)
	{
	    while(a[r] > a[pivot] && r > l) r--;

	    if(r > l)
	    {
		tmp = a[pivot];
		a[pivot] = a[r];
		a[r] = tmp;

		pivot = r;
	    }
	    else break;
	}

	if(pivot == r)
	{
	   while(a[l] < a[pivot] && l < r) l++;

	    if(l < r)
	    {
		tmp = a[pivot];
		a[pivot] = a[l];
		a[l] = tmp;

		pivot = l;
	    }
	    else break;
	}
    }

    return pivot;
}

void ArrayList :: print()
{
    cout << "\nThe array after sorting is\n";
    cout << "\n[ " << a[0];

    for(int i = 1;i < n;i++) cout << " , " << a[i];
    cout << " ]\n";
}

void ArrayList :: randomize(int size)
{
    Timer t;
    a = new int [5000];
    for(int i = 0;i < size;i++) a[i] = size - i;

    t.start();actual_sort(0,size - 1);t.stop();
    cout << "For operation " << size << " time taken is : " << t.time();
    cout << " seconds\n";
    free(a);
}

int main()
{
    clrscr();
    Timer t;
    ArrayList obj;
    obj.read();
    t.start();obj.quicksort();t.stop();
    obj.print();
    cout << "\nTime taken for this is : " << t.time() << " seconds\n";

    //uncomment this only for this bulk operation

    //for(int i = 500;i <= 3500;i += 500) obj.randomize(i);

    getch();
    return 0;
}
