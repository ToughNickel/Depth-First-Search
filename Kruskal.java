import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

//this program just gonna give the weight of the minimum spanning tree created

/*-------------------------------
Sample input as to how to give input for this program

4 6            
1 2 5
1 3 3
4 1 6
2 4 7
3 2 4
3 4 5
1
output
12

8 12
1 2 3
2 3 3
1 3 2
2 4 6
3 6 5
3 5 5
5 6 4
6 7 4
5 7 3
4 5 2
4 8 2
7 8 6
1
output
21
------------------------------*/

public class Solution 
{
    static int n;
    public static void main(String[] args) throws Exception
    {
        Scanner bt = new Scanner( System.in );
        PrintWriter exe = new PrintWriter( System.out,true );
        n = bt.nextInt();int m = bt.nextInt();
        List<Integer> s = new ArrayList<>();
        List<Integer> e = new ArrayList<>();
        List<Integer> w = new ArrayList<>();
        
        //various initialisations 
        Integer min  = 0,Wsum = 0;
        int start,end;
        List<Integer> w1 = new ArrayList<>();
        List<Integer> tmpE = new ArrayList<>();
        List<Integer> tmpW = new ArrayList<>();
        List<Integer> q = new ArrayList<>();        
        int [][] matrix = new int [n][n]; 
        
        //reading the values
        while(m-- > 0)
        {
            int a = bt.nextInt();int b = bt.nextInt();int c = bt.nextInt();
            s.add( a );e.add( b );w.add( c );
        }
        start = bt.nextInt();
        //------------------
        
        //choosing an edge from the start
        for(int i = 0;i < s.size();i++)
            if(s.get(i) == start) 
            {
                tmpW.add( w.get(i) );
                tmpE.add( e.get(i) );
            }
        min = Collections.min( tmpW );
        if(Collections.frequency( tmpW,min ) == 1) end = tmpE.get( tmpW.indexOf(min) );
        else 
        {
            for(int i = 0;i < tmpE.size();i++)
                if(Objects.equals(tmpW.get(i), min)) q.add( tmpE.get(i) );
            end = Collections.min( q );
        }
        w1.add(min);Add(start,end,matrix);
        clear( s,e,w,start,end );tmpE.clear();tmpW.clear();q.clear();
        //-------------------------------
        
        //real operation
        while(w1.size() < n-1)
        {
            int l = 0;
            min = Collections.min( w );
            
            //selection of start & end
            if(Collections.frequency(w, min) == 1) 
            {
                end = e.get( w.indexOf(min) );
                start = s.get( w.indexOf(min) );
            }
            else
            {
                for(int i = 0;i < w.size();i++)
                    if(w.get(i) == min) 
                    {
                        q.add( s.get(i) + e.get(i) + w.get(i) );
                        tmpE.add( s.get(i) );tmpW.add( e.get(i) );
                    }
                l = Collections.min(q);
                start = tmpE.get( q.indexOf(l) );
                end = tmpW.get( q.indexOf(l) ); 
            }
            //-------------------------
            
            if(matrix[start - 1][end - 1] == 0) 
            {
                w1.add(min);Add(start,end,matrix);
            }
            clear(s,e,w,start,end);tmpE.clear();tmpW.clear();q.clear();
        }
        //--------------
        for(int i = 0;i < w1.size();i++) Wsum += w1.get(i);
        exe.println(Wsum);
    }
    public static void clear(List<Integer> s,List<Integer> e,List<Integer> w,int start,int end)
    {
        List<Integer> remo = new ArrayList<>();remo.add( -999 );
        for(int i = 0;i < s.size();i++)
            if(s.get(i) == start && e.get(i) == end)
            {
                s.set(i,-999);e.set(i,-999);w.set(i,-999);
            }
        s.removeAll(remo);e.removeAll(remo);w.removeAll(remo);
    }
    public static void Add(int start,int end,int [][] matrix)
    {
        matrix[start - 1][end - 1] = 1;
        for(int i = 0;i < n;i++) 
        {
            if(matrix[start - 1][i] == 1)
            {
               matrix[i][start - 1] = 1;matrix[i][i] = 1; 
               matrix[end - 1][i] = 1;matrix[i][end - 1] = 1;
            }
            if(matrix[end - 1][i] == 1)
            {
               matrix[i][end - 1] = 1;matrix[i][i] = 1; 
               matrix[start - 1][i] = 1;matrix[i][start - 1] = 1;
            }
        }
    }
}
