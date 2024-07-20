package javalearning;

class ChuNhat{
    public double chieudai;
    public double chieurong;
    public ChuNhat(double x, double y){
        this.chieudai=x;
        this.chieurong=y;
    }
    public double chuvi(){
        return 2.0*(chieudai+chieurong);
    }
    public double dientich(){
        return chieudai*chieurong;
    }
}

class Vuong extends ChuNhat{
    public Vuong(double x){
        super(x,x);
    }
}

public class TuGiac {
    public static void main(String[] args){
        ChuNhat a = new ChuNhat(2.5, 7.5);
        Vuong b= new Vuong(2.5);
        System.out.println(a.chuvi());
        System.out.println(a.dientich());
        System.out.println(b.chuvi());
        System.out.println(b.dientich());
    } 
}
