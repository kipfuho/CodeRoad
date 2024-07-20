package javalearning;
import java.util.Scanner;
public class Demo {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.print("Nhap i = ");
        int i = s.nextInt();
        System.out.println(i);
        System.out.print("Nhap l = ");
        long l = s.nextLong();
        System.out.println(l);
        s.close();
    }
}