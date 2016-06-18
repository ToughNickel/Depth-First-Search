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
    void randomize();
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

void Case :: randomize()
{
    Timer t;
    for(int i = 1000;i <= 10000;i += 1000)
    {
       pattern[1] = '\0';
       cout << "\nFor operation : " << i;
       textlen = i;patternlen = (int)( textlen / ((rand() % 10) + 1) );
       for(int j = 0;j < textlen - 1;j++) text[j] = (rand() % 26) + 'a';
 
       strrev(text);
       strncpy(pattern,text,patternlen);
       strrev(pattern);
       strrev(text);
 
        t.start();Horspool_Machine();t.stop();
        cout << " time taken : " << t.time() << " seconds";t.reset();
    }
}

int main()
{
   clrscr();
   Timer t;
   int index;
   Case C;
   C.input();
   t.start();index = C.Horspool_Machine();t.stop();

   if(index == -1) cout << "\nMatch couldn't be found\n";
   else cout << "\nMatch found at position "<< (index + 1) <<"\n";
   
   cout << "\nTime taken for this is : "<< t.time() <<" seconds\n";

   getch();
   return 0;
}
