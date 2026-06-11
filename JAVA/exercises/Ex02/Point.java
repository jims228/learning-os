public class Point {
    //フィールド
    private int x,y;

    //setXメソッド
    void setX(int newX){
        x = newX;
    }

    //setYメソッド
    void setY(int newY){
        y = newY;
    }

    void move(int dx,int dy){
        if(Math.abs(x + dx) <= 100 && Math.abs(y + dy) <= 100){
            x = x + dx;
            y = y + dy;
        }
    }

    //getXメソッド
    int getX(){
        return x;
    }

    //getYメソッド
    int getY(){
        return y;
    }
}
