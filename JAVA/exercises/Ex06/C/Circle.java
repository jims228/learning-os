class Circle extends Shape {
    private Point center;
    private int radius;

    public Circle(Point center, int radius){
        this.center = center;
        this.radius = radius;
    }

    public void move(int dx, int dy){
        center.move(dx, dy);
    }

    public void print(){
        super.print();
        System.out.println("(" + center.getX() + ", " + center.getY() + ") radius = " + radius);
    }
}
