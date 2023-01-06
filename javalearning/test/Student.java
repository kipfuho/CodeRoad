package javalearning.test;
public class Student {
    private String name;
    private int year;   
    public Student(String name, int year){
        this.name = name;
        this.year = year;
    }
    public String get_name(){
        return name;
    }
    public int get_year(){
        return year;
    }
    public void set_name(String name){
        this.name = name;
    }
    public void set_year(int year){
        this.year = year;
    }
}
