package javalearning;
import java.util.Scanner;
public class MaTranVuong {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int n;
        System.out.print("Nhap h = ");
        n = s.nextInt();
        while(n < 3 || n > 8){
            System.out.println("n khong thoa man, nhap lai:");
            n = s.nextInt();
        }
        int[][] arr = new int[n][n];
        int l = 0, r = n-1, u = 0, d = n-1, i = 1, j = 0, k = 0, mode = 0, t = 1;
        while(i <= n*n){
            if(mode % 2 ==0){
                arr[k][j] = i++;
                if(mode == 0 && j == r){
                    mode = 1;
                    k = ++u;
                    continue;
                }
                else if(mode == 2 && j == l){
                    mode = 3;
                    k = --d;
                    continue;
                }
                j += t;
            }
            else{
                arr[k][j] = i++;
                if(mode == 1 && k == d){
                    mode = 2;
                    j = --r;
                    t = -1;
                    continue;
                }
                else if(mode ==3 && k==u){
                    mode = 0;
                    j = ++l;
                    t = 1;
                    continue;
                }
                k += t;
            }
        }
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                System.out.printf("%-4d", arr[i][j]);
            }
            System.out.println("");
        }
        s.close();
        System.exit(0);
    }
}
