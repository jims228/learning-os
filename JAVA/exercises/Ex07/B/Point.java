public class Point implements Relatable {
    private int x, y;

    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int getX(){ return x; }
    public int getY(){ return y; }

    public boolean isSmallerThan(Relatable other){
        Point p = (Point)other;
        if ( this.x < p.x ) return true;
        if ( this.x > p.x ) return false;
        return this.y < p.y;
    }

    public void print(){
        System.out.println("(" + x + ", " + y + ")");
    }
}
