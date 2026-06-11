public class Point2D {
    protected double x, y;

    public Point2D(){}
    public Point2D(double x, double y){
        this.x = x;
        this.y = y;
    }

    void setX(double newX){ x = newX; }
    void setY(double newY){ y = newY; }
    void add(Point2D v){ x += v.x; y += v.y; }
    void scale(double f){ x *= f; y *= f; }
    double length(){ return Math.sqrt(x*x + y*y); }
    double dotProduct(Point2D v){ return x*v.x + y*v.y; }
    double crossProduct(Point2D v){ return x*v.y - y*v.x; }
    double getX(){ return x; }
    double getY(){ return y; }

    double distance(Point2D other){
        double dx = x - other.x;
        double dy = y - other.y;
        return Math.sqrt(dx*dx + dy*dy);
    }

    public String toString(){
        return "(" + x + ", " + y + ")";
    }
}
