package javalearning;
import java.util.Scanner;
public class TamGiac {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int h;
        System.out.print("Nhap h = ");
        h = s.nextInt();
        while(h < 2 || h > 10){
            System.out.println("h khong thoa man, nhap lai:");
            h = s.nextInt();
        }
        for(int i = 1; i <= h; i++){
            int t = h-i, p = 1 + 2 * (i-1);
            while((t--) != 0) System.out.print("  ");
            while((p--) != 0) System.out.print("* ");
            System.out.println();
        }
        s.close();
        System.exit(0);
    }
}
