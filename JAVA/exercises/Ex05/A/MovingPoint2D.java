public class MovingPoint2D extends Point2D {
    protected double vx, vy;

    public MovingPoint2D(double x, double y, double vx, double vy){
        super(x, y);
        this.vx = vx;
        this.vy = vy;
    }

    void setVelocity(double a, double b){
        vx = a;
        vy = b;
    }

    void move(){
        x += vx;
        y += vy;
    }
}
