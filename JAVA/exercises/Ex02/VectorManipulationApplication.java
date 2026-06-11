import java.util.Scanner;
class VectorManipulationApplication{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Point2D v1 = new Point2D();
        Point2D v2 = new Point2D();
        v1.setX(sc.nextDouble());
        v1.setY(sc.nextDouble());
        v2.setX(sc.nextDouble());
        v2.setY(sc.nextDouble());
        System.out.println("Length of v1: " + v1.length());
        System.out.println("Length of v2: " + v2.length());
        System.out.println("Dot product of v1 and v2: " + v1.dotProduct(v2));
        System.out.println("Cross product of v1 and v2: " + v1.crossProduct(v2));
        v1.add(v2);
        v2.scale(100);
        System.out.println("Length of v1: " + v1.length());
        System.out.println("Length of v2: " + v2.length());
    }
}