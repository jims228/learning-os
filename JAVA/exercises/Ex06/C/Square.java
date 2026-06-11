class Square extends Rectangle {
    public Square(Point p1, int width){
        super(p1, new Point(p1.getX() + width, p1.getY() + width));
    }
}
