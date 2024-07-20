package javalearning;
import javax.swing.JOptionPane;

interface Shape {
    public int answer = 42;
}

public class FirstDialog{
    public static void main(String[] args){
        JOptionPane.showMessageDialog(null,
        "Xin chao ban!");
        System.exit(0);
    }
}