class IntApplication{
    public static void main(String[] args){
        Int a = new Int(0);
        Int b = new MInt(0);
        MInt c = new MInt(0);
        c.setValue(1);
        System.out.println(a.getValue() + " (" + a.INT_MAX + ")");
        System.out.println(b.getValue() + " (" + b.INT_MAX + ")");
        System.out.println(c.getValue() + " (" + c.INT_MAX + ")");
        System.out.println("MOD = " + c.MOD);
        Int resA = a.add(new MInt(10)).add(new MInt(20)).mul(new MInt(30));
        Int resB = b.add(new MInt(10)).add(new MInt(20)).mul(new MInt(30));
        Int resC = c.mul(new MInt(10)).add(new MInt(20)).mul(new MInt(30));
        System.out.println(resA);
        System.out.println(resB);
        System.out.println(resC);
    }
}
