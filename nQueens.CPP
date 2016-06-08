#include <iostream.h>
#include <conio.h>
#include <timer.h>
#include <limits.h>

/*--------------------------------------------

This program just gives one solution ..., coz that's what the aim of backtracking(--duhh--)

play() === input function
placement() == function to place queens in their respective places in the row
debard() == function to restrict places with respect to an already placed queen
clear() == function to UN - restrict places with respect to placed queen which is being re - placed
isQueen() == function to check whether the given cell has queen in the board
print_solution() == function to print the board

--------------------------------------------*/

#define MAX 20

typedef enum bo {false = 0,true} boolean;

class Game_of_Queens
{
   int n,s,**board;
   boolean *placed;
   void debard(int,int);
   void clear(int);
   boolean isQueen(int,int);

  public :

    Game_of_Queens()
    {
       n = 0;s = 1;
    }
    void play();
    void placement();
    void print_solution();
};

void Game_of_Queens :: play()
{
    while(1)
    {
       cout << "\nGive the number of queens : ";
       cin >> n;

       if(n >= MAX)
       {
	 cout << "\nrequesting you to give number of queens less than "<< MAX <<"\n";
	 cout << "Its not that it can't compute...,just that the display's gonna mess up\n";
       }
       else break;
    }
    placed = new boolean [n];
    *board = new int [n];
    for(int i = 0;i < n;i++) board[i] = new int [n];

    for(int row = 0;row < n;row++)
       for(int col = 0;col < n;col++)
       {
	  placed[row] = false;
	  board[row][col] = 0;
       }
}

void Game_of_Queens :: placement()
{
    int i,cand;
    for(cand = 0;cand < n && s;)
    {
       for(i = 0;i < n && !placed[cand];i++)
	   if(!board[cand][i])
	   {
	      board[cand][i] = (cand + 1)*10000;
	      placed[cand] = true;
	      debard(cand,i);
	   }

       if(!placed[0])  s = 0;

       if(!placed[cand])
       {
	  placed[--cand] = false;
	  clear(cand);
       }
       else cand++;
    }
}

void Game_of_Queens :: debard(int cand,int col)
{
   int tmp,i,j;
   tmp = ((cand + 1) * 10) + (col + 1);

   //vertical
   for(i = cand + 1;i < n;i++) if(!board[i][col]) board[i][col] = tmp;

   //right down diagonal
   for(i = cand + 1,j = col + 1;i < n && j < n;i++,j++)
       if(!board[i][j])
	  board[i][j] = tmp;

   //left down diagonal
   for(i = cand + 1,j = col - 1;i < n && j >= 0;i++,j--)
       if(!board[i][j])
	  board[i][j] = tmp;
}

void Game_of_Queens :: clear(int cand)
{
    int i,tmp,col = -1,j;

    for(i = 0;i < n && col == -1;i++)
       if(board[cand][i] == ((cand + 1)*10000)) col = i;

    tmp = (10 * (cand + 1)) + (col + 1);

    //vertical
    for(i = cand + 1;i < n;i++) if(board[i][col] == tmp) board[i][col] = 0;

    //right down diagonal
    for(i = cand + 1,j = col + 1;i < n && j < n;i++,j++)
	if(board[i][j] == tmp) board[i][j] = 0;

    //left down diagonal
    for(i = cand + 1,j = col - 1;i < n && j >= 0;i++,j--)
	if(board[i][j] == tmp) board[i][j] = 0;

    board[cand][col] = -1 * (cand + 1);

    if(cand < n - 1)
    {
       for(i = 0;i < n;i++)
	   if(board[cand + 1][i] < 0 || board[cand + 1][i] == INT_MAX)
	      board[cand + 1][i] = 0;
    }
}

boolean Game_of_Queens :: isQueen(int x,int y)
{
   if(board[x][y] == (x + 1)*10000) return true;
   else return false;
}

void Game_of_Queens :: print_solution()
{
    int i,j,cap,dap;
    if(!s) cout << "\nSolution doesn't exist\n";
    else
    {
       cout << "\nThe solution is --> \n";
       for(i = 0;i < n;i++) cout << " ___";
       cout << "\n";

       for(i = 0;i < n;i++)
       {
	   cout << "|";
	   for(j = 0;j < n;j++)
	   {
	      if(isQueen(i,j))  cout << "_Q_|";
	      else cout << "___|";
	   }
	   cout << "\n";
       }
    }
}

int main()
{
    clrscr();
    Timer t;
    Game_of_Queens cersei;
    cersei.play();
    t.start();cersei.placement();t.stop();
    cersei.print_solution();
    cout << "\nBy the way.., it took " << t.time() <<" seconds for the machine\n";
    getch();
    return 0;
}
