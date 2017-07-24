package Sources;

import java.io.PrintWriter;
import java.util.Scanner;

public class range_palindrome{
    public static void main(String [] args){
        Scanner bt = new Scanner( System.in );
        PrintWriter w = new PrintWriter( System.out,true );
        int lower = bt.nextInt();int upper = bt.nextInt();
        
        String limit = upper + "";
        int upperDigits = limit.length();
        limit = lower + "";
        int lowerDigits = limit.length();
        
        for(int i = lowerDigits;i <= upperDigits;i++){
            if(i%2 == 0) even(i,lower,upper);
            else odd(i,lower,upper);
        }
        
        w.println();
        
        bt.close();
        w.close();
    }
    
    public static void even(int digits,int lower,int upper){
        int half = digits / 2;
        int lowerLimit,upperLimit;
        lowerLimit = (int)Math.pow(10,half - 1);
        upperLimit = (int)(Math.pow(10,half) - 1);
        
        for(int i = lowerLimit;i <= upperLimit;i++){     
            String number = i + "";
            StringBuffer sb = new StringBuffer(number).reverse();
            number += sb.toString();
            int num = Integer.parseInt(number);
            if(num >= lower && num <= upper) System.out.print(num + " ");
            if(num > upper) break;
        }
    }
    
    public static void odd(int digits,int lower,int upper){
        int half = (int)(digits / 2);
        int lowerLimit,upperLimit;
        lowerLimit = (int)Math.pow(10,half - 1);
        upperLimit = (int)(Math.pow(10,half) - 1);
        
        for(int i = lowerLimit;i <= upperLimit;i++){
            for(int middle = 0;middle <= 9;middle++){
                String number = i + "";
                StringBuffer sb = new StringBuffer(number).reverse();
                number += middle + "";
                number += sb.toString();
                int num = Integer.parseInt(number);
                if(num >= lower && num <= upper) System.out.print(num + " ");
                if(num > upper) break;
            }
        }
    }
}