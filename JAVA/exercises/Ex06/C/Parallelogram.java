class Parallelogram extends Quadrangle {
    public Parallelogram(Point p1, Point p3, int width){
        super(
            p1,
            new Point(p1.getX() + width, p1.getY()),
            p3,
            new Point(p3.getX() - width, p3.getY())
        );
    }
}
