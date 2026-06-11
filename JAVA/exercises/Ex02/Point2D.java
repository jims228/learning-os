public class Point2D {
    //フィールド
    private double x,y;

    void setX(double newX){
        x = newX;
    }
    void setY(double newY){
        y = newY;
    }

    void add(Point2D v){
        x += v.x;
        y += v.y;
    }

    void scale(double f){
        x *= f;
        y *= f;
    }

    double length(){
        return Math.sqrt(x*x + y*y);
    }

    double dotProduct(Point2D v){
        return x*v.x + y*v.y;
    }

    double crossProduct(Point2D v){
        return x*v.y - y*v.x;
    }

    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
}
