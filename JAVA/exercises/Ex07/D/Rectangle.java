public class Rectangle implements Relatable {
    private Point p1, p3;

    public Rectangle(Point p1, Point p3){
        this.p1 = p1;
        this.p3 = p3;
    }

    public int getArea(){
        int width = Math.abs(p3.getX() - p1.getX());
        int height = Math.abs(p3.getY() - p1.getY());
        return width * height;
    }

    public boolean isSmallerThan(Relatable other){
        Rectangle r = (Rectangle)other;
        return this.getArea() < r.getArea();
    }
}
