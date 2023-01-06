package javalearning;

public class Sum {
    public static int sum(int... arr){
        int res = 0;
        for(int i : arr){
            res += i;
        }
        return res;
    }
    public static void main(String[] args){
        System.out.println(sum(1,2,3,4,5));
    }
}
