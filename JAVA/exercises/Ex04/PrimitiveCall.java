import java.util.Scanner;
public class PrimitiveCall{
    public void test(){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        System.out.println("(x, y) = (" + x + ", " + y + ")");
        movePoint(x, y);
        System.out.println("(x, y) = (" + x + ", " + y + ")");
    }
    private void movePoint(int x, int y){
        System.out.println("(x, y) = (" + x + ", " + y + ")");
        x = 100;
        y = 120;
        System.out.println("(x, y) = (" + x + ", " + y + ")");
    }
    public static void main(String[] args){
        new PrimitiveCall().test();
    }
}