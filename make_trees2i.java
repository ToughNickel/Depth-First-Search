import java.io.PrintWriter;
import java.util.Scanner;

public class make_trees2i{
    public static void main(String [] args){
        Scanner bt = new Scanner( System.in );
        PrintWriter w = new PrintWriter( System.out,true );
        
        w.println("Give the number of elements : ");
        int length = bt.nextInt();
        
        int [] inorder = new int [length];int [] preorder = new int [length];
        w.println("Give the inorder : -> ");
        for(int i = 0;i < length;i++) inorder[i] = bt.nextInt();
        w.println("Give the preorder : -> ");
        for(int i = 0;i < length;i++) preorder[i] = bt.nextInt();
        
        w.println("\n\nPostorder traversal");
        printSubtree(inorder,preorder);
        w.println();
        
        bt.close();
        w.close();
    }
    
    public static void printSubtree(int [] inorder,int [] preorder){
        int root = preorder[0];
        
        if(preorder.length == 1){
            System.out.print(root + " ");
            return;
        }
        
        //finding the index of the root in the inorder
        int index = -1;
        boolean leftMost = false;
        boolean rightMost = false;
        for(int i = 0;i < inorder.length;i++) if(inorder[i] == root) {index = i;break;}   
        if(index == 0) leftMost = true;
        else if(index == inorder.length - 1) rightMost = true;
        //--------------------------------------------
        
        //left array from inorder and preorder
        int [] leftInorder = new int [index];        
        int [] leftPreorder = new int [index];
        if(!leftMost){            
            System.arraycopy(inorder, 0, leftInorder, 0, index);
            System.arraycopy(preorder, 1, leftPreorder, 0, index);
            printSubtree(leftInorder,leftPreorder);
        }
        
        //right array from inorder
        int [] rightInorder = new int [inorder.length - index - 1];        
        int [] rightPreorder = new int [inorder.length - index - 1];
        if(!rightMost){            
            System.arraycopy(inorder, index + 1, rightInorder, 0, inorder.length - index - 1);
            System.arraycopy(preorder, index + 1, rightPreorder, 0, inorder.length - index - 1);
            printSubtree(rightInorder,rightPreorder);
        }
        
        System.out.print(root + " ");
    }
}    
