import java.util.Scanner;
public class ReferenceCall{
    public void test(){
        Scanner sc = new Scanner(System.in);
        Point p = new Point(sc.nextInt(), sc.nextInt());
        System.out.println("(x, y) = (" + p.getX() + ", " + p.getY() + ")");
        initPoint(p);
        System.out.println("(x, y) = (" + p.getX() + ", " + p.getY() + ")");
        movePoint(p, 100, 120);
        System.out.println("(x, y) = (" + p.getX() + ", " + p.getY() + ")");
        resetPoint(p);
        System.out.println("(x, y) = (" + p.getX() + ", " + p.getY() + ")");
    }
    private void movePoint(Point o, int dx, int dy){
        o.setX(dx);
        o.setY(dy);
    }
    private void initPoint(Point o){
        o.setX(0);
        o.setY(0);
    }
    private void resetPoint(Point o){
        o = new Point(0, 0);
    }
    public static void main(String[] args){
        new ReferenceCall().test();
    }
}