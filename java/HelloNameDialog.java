package javalearning;
import javax.swing.JOptionPane;
public class HelloNameDialog {
    public static void main(String agrs[]){
        String result;
        result = JOptionPane.showInputDialog("Hay nhap ten ban!");
        JOptionPane.showMessageDialog(null, "Xin chao "+ result);
        System.exit(0);
    }
}
