package javalearning;
import java.util.Scanner;
import java.util.Arrays;
public class SapXep {
    public static void main(String[] args){
        Scanner s = new Scanner(System.in);
        int n, m;
        System.out.print("Nhap n = ");
        n = s.nextInt();
        double[] arr = new double[n];
        for(int i = 0; i < n; i++){
            System.out.printf("Nhap so thu %d = ", i + 1);
            arr[i] = s.nextDouble();
        }
        System.out.println("Sap xep tang dan hay giam dan? (1 hoac 0)");
        m = s.nextInt();
        Arrays.sort(arr);
        if(m == 1){
            for(int i = 0; i < n; i++){
                System.out.printf("%f ", arr[i]);
            }
        }
        else{
            for(int i = n-1; i >= 0; i--){
                System.out.printf("%f ", arr[i]);
            }
        }
        System.exit(0);
        s.close();
    }
}
