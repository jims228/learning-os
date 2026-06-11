class Point {
    private int x;
    private int y;
    public Point(int x, int y){
        this.x = x;
        this.y = y;
    }
    public boolean equals(Object o){
        if(!(o instanceof Point)) return false;
        Point p = (Point) o;
        return this.x == p.x && this.y == p.y;
    }
    public int getX(){ return x; }
    public int getY(){ return y; }
    public void move(int dx, int dy){
        x += dx;
        y += dy;
    }
}
