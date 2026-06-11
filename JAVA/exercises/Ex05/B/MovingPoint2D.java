public class MovingPoint2D {
    private Point2D p;
    private double vx, vy;

    public MovingPoint2D(double x, double y, double vx, double vy){
        p = new Point2D(x, y);
        this.vx = vx;
        this.vy = vy;
    }

    void setVelocity(double a, double b){
        vx = a;
        vy = b;
    }

    void move(){
        p.setX(p.getX() + vx);
        p.setY(p.getY() + vy);
    }

    double distance(MovingPoint2D other){
        return p.distance(other.p);
    }

    public String toString(){
        return p.toString();
    }
}
