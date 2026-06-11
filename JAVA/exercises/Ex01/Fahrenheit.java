import java.util.Scanner;
public class Fahrenheit {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int F = sc.nextInt();
        double Celsius = (5.0/9)*(F-32);
        if(Celsius - (int)Celsius == 0){
            System.out.println(Celsius);
        }else{
            System.out.printf("%.4f%n",Celsius);
        }
    }
}