#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include <timer.h>
#include <string.h>

class Case
{
    char text[10001],pattern[10001];
    int textlen,patternlen,shiftTable[95];
    void prepareShiftTable();
  public :
    Case()
    {
       textlen = patternlen = 0;
    }

    void input();
    int Horspool_Machine();
};

void Case :: input()
{
    cout << "\nGive the text : ";
    cin >> text;
    cout << "\nGive the pattern to be searched : ";
    scanf("%s",pattern);

    textlen = strlen(text);patternlen = strlen(pattern);
}

void Case :: prepareShiftTable()
{
    for(int i = 0;i < 95;i++) shiftTable[i] = patternlen;

    for(int j = 0;j < patternlen - 1;j++)
	shiftTable[pattern[j] - '0'] = patternlen - j - 1;
}

int Case :: Horspool_Machine()
{
    prepareShiftTable();

    int i = patternlen - 1;

    while(i < textlen)
    {
	int k = 0;

	while(k < patternlen && pattern[patternlen - 1 - k] == text[i - k])
	   k++;

	if(k == patternlen) return (i - patternlen + 1);
	else  i += shiftTable[text[i] - '0'];
    }

    return -1;
}

int main()
{
   clrscr();
   int index;
   Case C;
   C.input();
   index = C.Horspool_Machine();

   if(index == -1) cout << "\nMatch couldn't be found\n";
   else cout << "\nMatch found at position "<< (index + 1) <<"\n";

   getch();
   return 0;
}
