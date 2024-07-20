package javalearning.test;
import java.util.Scanner;
public class Test{
    static void reverse(StringBuffer st){
        int len = st.length();
        StringBuffer newSB;
        for(int i = len - 1; i >= 0; i--){
            newSB =  newSB.append(st[i]);
        }
    }

    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int N = s.nextInt();
        Student[] cls = new Student[N];
        for(int i = 0; i < N; i++){
            String name = s.next();
            int year = s.nextInt();
            cls[i] = new Student(name, year);
        }
        int total = 0;
        System.out.println("Danh sach lop:");
        for(int i = 0; i < N; i++){
            System.out.println(cls[i].getName());
            total += (2022-cls[i].getYear());
        }
        System.out.println("Tong so tuoi: " + total);
        s.close();
    }
}