package javalearning.test1;

public class testNV {
    public static void main(String[] args){
        NhanVien a = new NhanVien("Cac to", 500, 1.1);
        NhanVien b = new NhanVien("To rat to", 1000, 0.9);
        if(a.tangLuong(19)){
            System.out.println("Tang luong thanh cong");
        }
        else{
            System.out.println("Tang luong khong thanh cong");
        }
    }
}
