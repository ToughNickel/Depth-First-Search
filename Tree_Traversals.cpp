#include <iostream.h>
#include <conio.h>
#include <timer.h>
#include <stdlib.h>

class Node
{
  public:
    Node *right,*left;
    int data;
    Node()
    {
	right = left = NULL;
	data = 0;
    }
};

class Tree
{
     Node *root;
     int count,*order,x;
     void post(Node *);
     void in(Node *);
     void pre(Node *);
  public :
     Tree()
     {
	 root = NULL;
	 count = 0;
	 x = -1;
     }
     int isEmpty()
     {
	 return(root == NULL);
     }
     void grow(int);
     void inorder();
     void preorder();
     void postorder();
     void randomize(int);
};

void Tree :: grow(int item)
{
    Node *parent,*ptr,*tmp;
    tmp = new Node;
    tmp -> data = item;

    if(root == NULL) root = tmp;
    else
    {
	ptr = root;
	while(ptr != NULL)
	{
	    parent = ptr;
	    if(item > ptr -> data)  ptr = ptr -> right;
	    else ptr = ptr -> left;
	}

	if(parent->data > item) parent -> left = tmp;
	else parent -> right = tmp;
    }
    count++;
}

void Tree :: inorder()
{
    Timer t;
    order = new int [count];x = -1;
    t.start();in(root);t.stop();

    cout << "\n[ " << order[0];
    for(int i = 1;i <= x;i++) cout << " , " << order[i];
    cout << " ]\n";
    cout << "Time taken inorder : " << t.time() << " seconds\n";
    x = -1;
    delete order;
}

void Tree :: in(Node *root)
{
     if(root == NULL) return;
     in(root -> left);
     order[++x] = root -> data;
     in(root -> right);
}

void Tree :: preorder()
{
    Timer t;
    order = new int [count];
    x = -1;
    t.start();pre(root);t.stop();

    cout << "\n[ " << order[0];
    for(int i = 1;i <= x;i++) cout << " , " << order[i];
    cout << " ]\n";
    cout << "Time taken for preorder : " << t.time() << " seconds\n";
    x = -1;
    delete order;
}

void Tree :: pre(Node *root)
{
    if(root == NULL) return;
    order[++x] = root -> data;
    pre(root -> left);
    pre(root -> right);
}

void Tree :: postorder()
{
     Timer t;
     order = new int [count];
     x = -1;
     t.start();post(root);t.stop();

     cout << "\n[ " << order[0];
     for(int i = 1;i <= x;i++) cout << " , " << order[i];
     cout << " ]\n";
     cout << "Time taken for postorder : " << t.time() << " seconds\n";
     x = -1;
     delete order;
}

void Tree :: post(Node *root)
{
     if(root == NULL) return;
     post(root -> left);
     post(root -> right);
     order[++x] = root -> data;
}

void Tree :: randomize(int size)
{
     order = new int [size];
     Timer t;
     root = NULL;
     for(int i = 0;i < size;i++) grow((rand() % 1000) + 1);

     cout << "\nFor operation : " << size;

     x = -1;t.start();in(root);t.stop();
     cout << "\n\tinorder : " << t.time() << " seconds";t.reset();

     x = -1;t.start();pre(root);t.stop();
     cout << "\n\tpreorder : " << t.time() << " seconds";t.reset();

     x = -1;t.start();post(root);t.stop();
     cout << "\n\tpostorder : " << t.time() << " seconds";
     delete order;
}

int main()
{
    clrscr();
    Tree mango;
    int ch = 1;

    while(ch)
    {
       int choice,m,item;
       cout << "\nWant to insert or traverse i.e., (1/2) : ";
       cin >> choice;
       if(choice == 1)
       {
	   cout << "\nGive the data to be inserted : ";
	   cin >> item;
	   mango.grow(item);
       }
       else
       {
	  if(mango.isEmpty()) cout << "\nNothing to traverse\n";
	  else
	  {
		cout << "\nAnd which traversal\n1) Inorder\n2) Preorder\n3) Postorder\nchoice : ";
		cin >> m;
		switch(m)
		{
		   case 1: mango.inorder();break;
		   case 2: mango.preorder();break;
		   case 3: mango.postorder();break;
		}
	   }
       }
       cout << "\nWant to continue ? (yes -> 1/no -> 0) : ";
       cin >> ch;
    }
    
    //for(int i = 350;i <= 500;i += 50) mango.randomize(i);          //uncomment this only for bulk operation
    getch();
    return 0;
}
