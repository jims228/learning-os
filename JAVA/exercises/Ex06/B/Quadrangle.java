class Quadrangle extends Shape {
    protected Point[] P;

    public Quadrangle(Point p1, Point p2, Point p3, Point p4){
        P = new Point[]{p1, p2, p3, p4};
    }

    public void print(){
        super.print();
        for(int i = 0; i < 4; i++){
            if(i > 0) System.out.print("-");
            System.out.print("(" + P[i].getX() + ", " + P[i].getY() + ")");
        }
        System.out.println();
    }

    public void move(int dx, int dy){
        for(int i = 0; i < 4; i++) P[i].move(dx, dy);
    }
}
