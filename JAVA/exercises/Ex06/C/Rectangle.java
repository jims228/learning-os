class Rectangle extends Parallelogram {
    public Rectangle(Point p1, Point p3){
        super(p1, p3, p3.getX() - p1.getX());
    }
}
