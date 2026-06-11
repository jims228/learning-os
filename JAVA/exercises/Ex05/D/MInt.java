public class MInt extends Int {
    public static int MOD = 107;

    public MInt(int v){
        super(v);
    }

    public Int add(Int a){
        return new MInt((x + a.getValue()) % MOD);
    }

    public Int mul(Int a){
        return new MInt((x * a.getValue()) % MOD);
    }
}
