#include <iostream.h>
#include <conio.h>
#include <timer.h>
#include <stdlib.h>

#define vacant ' '
#define restricted 'X'

typedef enum bool {false = 0,true} boolean;

class Game_of_Queens
{
    char **board;
    boolean *placed;
    int n,**pos;
    void debard(int,int);
    void clear(int);
   public :
     Game_of_Queens()
     {
	 n = 0;
     }
     void play();
     void resolve();
     void solution();
};

void Game_of_Queens :: play()
{
    cout << "\nHow many queens are there : ";cin >> n;
    
    *board = new char [n];
    *pos = new int [n];
    placed = new boolean [n];

    for(int i = 0;i < n;i++)
    {
       pos[i] = new int [n];
       board[i] = new char [n];
    }

    for(int row = 0;row < n;row++)
	for(int col = 0;col < n;col++)
	{
	    pos[row][col] = 0;
	    placed[row] = false;
	    board [row][col] = vacant;
	}
}

void Game_of_Queens :: resolve ()
{
    int i,j,k,cand;
    if(n == 1 || n == 2 || n == 3)   {cand = 1;}
    else
    {
	for(cand = 0;cand < n;)
	{
		for(i = 0;i < n && !placed[cand];i++)
			if(board[cand][i] != restricted && !pos[cand][i])
			{
				board[cand][i] = 'Q';
				debard(cand,i);
				pos[cand][i] = 1;
				placed[cand] = true;
			}

		if(!placed[cand])
		{
			placed[--cand] = false;
			clear(cand);

			for(k = 0;k < n;k++)
			    if(board[cand][k] == 'Q')
			    {
				   board[cand][k] = 'X';
				   break;
			    }
		}
		else cand++;
	}

	for(i = 0;i < n;i++)
	    for(j = 0;j < n;j++)
		if(board[i][j] == 'X' || board[i][j] == ' ')
		  board[i][j] = 'X';
    }
}

void Game_of_Queens :: debard(int cand,int p)
{
    int i,j;

    //vertical one
    for(i = cand + 1;i < n;i++) board[i][p] = restricted;

    //right diagonal down
    for(i = cand + 1,j = p + 1;i < n && j < n;j++,i++)
	board[i][j] = restricted;

    //left diagonal down
    for(i = cand  + 1,j = p - 1;i < n && j >= 0;i++,j--)
       board[i][j] = restricted;
}

void Game_of_Queens :: clear(int cand)
{
   int p = -1,i,j;
   for(i = 0;i < n && p == -1;i++)
       if(board[cand][i] == 'Q') p = i;

   //vertical one
    for(i = cand + 1;i < n;i++) board[i][p] = vacant;

    //right diagonal down
    for(i = cand + 1,j = p + 1;i < n && j < n;j++,i++)
	board[i][j] = vacant;

    //left diagonal down
    for(i = cand  + 1,j = p - 1;i < n && j >= 0;i++,j--)
       board[i][j] = vacant;

   int curr = cand + 1;
   for(i = 0;i < n;i++) pos[curr][i] = 0;
}

void Game_of_Queens :: solution()
{
    int i,j;
    if(n == 1) cout << "\nSeriously ?\nplace the queen in the cell\n";
    else if(n == 2 || n == 3) cout << "\nSolution doesn't exist...they have to fight\n";
    else
    {
	cout << "\nThe solution is\n";
	for(i = 0;i < n;i++)
	{
		for(j = 0;j < n;j++)
		{
			if(board[i][j] == ' ')  board[i][j] = 'X';
			
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
    }
}

int main()
{
    clrscr();
    Timer t;
    Game_of_Queens Cersei;
    Cersei.play();
    t.start();Cersei.resolve();t.stop();
    Cersei.solution();
    cout << "\nBy the way.., it took the machine " <<t.time() << " seconds\n";
    getch();
    return 0;
}
