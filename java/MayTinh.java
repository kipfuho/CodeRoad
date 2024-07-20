package javalearning;
import java.util.Scanner;
public class MayTinh {
    public static void main(String args[]){
        Scanner s = new Scanner(System.in);
        System.out.print("Nhap x = ");
        int x = s.nextInt();
        System.out.print("Nhap y = ");
        int y = s.nextInt();
        System.out.println("x + y = " + (x+y));
        System.out.println("x - y = " + (x-y));
        System.out.println("x * y = " + (x*y));
        if(y==0) System.out.println("Error");
        else System.out.print("x / y = " + ((double)x/y));
        s.close();
        System.exit(0);
    }
}
