public class Point {
    private int x, y;
    public static int X_MIN, Y_MIN, X_MAX, Y_MAX;

    void setX(int newX){ x = newX; }
    void setY(int newY){ y = newY; }
    int getX(){ return x; }
    int getY(){ return y; }

    void move(int dx, int dy){
        int newX = x + dx;
        int newY = y + dy;
        if(newX >= X_MIN && newX <= X_MAX && newY >= Y_MIN && newY <= Y_MAX){
            x = newX;
            y = newY;
        }
    }
}
