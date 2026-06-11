class MovingPoint2DApplication{
    public static void main(String[] args){
        MovingPoint2D p1 = new MovingPoint2D(0, 0, 3, 4);
        MovingPoint2D p2 = new MovingPoint2D(0, 0, 0, -1);
        for ( int i = 0; i < 10; i++ ) {
            p1.move();
            p2.move();
        }
        System.out.println(p1 + "-" + p2 + ": " + p1.distance(p2));
        p2.setVelocity(30, 0);
        p2.move();
        System.out.println(p1 + "-" + p2 + ": " + p1.distance(p2));
    }
}
