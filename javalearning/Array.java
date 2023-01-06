package javalearning;

public class Array {
    public int[] arr;
    Array(int... arr){
        this.arr=arr;
    }
    public void xuat(){
        for(int i=0;i<10;i++){
            System.out.print(arr[i]+" ");
        }
    }
    public int Tong(){
        int sum=0;
        for(int i=0;i<10;i++){
            sum+=arr[i];
        }
        return sum;
    }
    public void xuatle(){
        for(int i=0;i<10;i++){
            if(arr[i]%2!=0){
                System.out.print(arr[i]+" ");
            }
        }
    }
    public static void main(String[] args){
        Array a=new Array(1,2,3,4,5,6,7,2,2,1,2);
        a.xuat();
        System.out.println();
        System.out.println(a.Tong());
        a.xuatle();
    }
}
