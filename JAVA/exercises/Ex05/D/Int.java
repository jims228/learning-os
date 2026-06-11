public class Int {
    protected int x;
    public static int INT_MAX = 1024;

    public Int(int v){
        x = v;
    }

    public Int add(Int a){
        return new Int(x + a.x);
    }

    public Int mul(Int a){
        return new Int(x * a.x);
    }

    public void setValue(int a){
        x = a;
    }

    public int getValue(){
        return x;
    }

    public String toString(){
        return "" + x;
    }
}
