package javalearning.test1;

public class NhanVien {
    private String tenNhanVien;
    private double luongCoBan;
    private double heSoLuong;
    private double LUONG_MAX = 10000; //$
    public NhanVien(String a, double b, double c){
        this.tenNhanVien = a;
        this.luongCoBan = b;
        this.heSoLuong = c;
    }
    public void set_tenNhanVien(String a){
        this.tenNhanVien = a;
    }
    public void set_luongCoBan(double b){
        this.luongCoBan = b;
    }
    public void set_heSoLuong(double c){
        this.heSoLuong = c;
    }
    public String get_tenNhanVien(){
        return this.tenNhanVien;
    }
    public double get_luongCoBan(){
        return this.luongCoBan;
    }
    public double get_heSoLuong(){
        return this.heSoLuong;
    }
    public boolean tangLuong(double luong){
        if(this.luongCoBan * (this.heSoLuong + luong) > LUONG_MAX){
            return false;
        }
        this.heSoLuong += luong;
        return true;
    }
    public double tinhLuong(){
        return this.luongCoBan * this.heSoLuong;
    }
    public void inTTin(){
        System.out.println("Ten nhan vien: " + this.tenNhanVien);
        System.out.println("Luong co ban: " + this.luongCoBan);
        System.out.println("He so luong: " + this.heSoLuong);
    }
}
