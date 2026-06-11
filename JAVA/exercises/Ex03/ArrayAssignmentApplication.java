class ArrayAssignmentApplication{
    public static void main(String[] args){
        new ArrayAssignmentApplication().run();
    }
    void run(){
        int[] a = {1, 2, 3};
        int[] b = {4, 5, 6};
        int[] c = {7, 8, 9};
        print(a, b, c);
        b = a;
        print(a, b, c);
        a[0] = 0;
        print(a, b, c);
        a = c;
        print(a, b, c);
        c = b;
        b = a;
        print(a, b, c);
    }
    void print(int[] a, int[] b, int[] c){
        System.out.println(a[0] + " " + a[1] + " " + a[2]);
        System.out.println(b[0] + " " + b[1] + " " + b[2]);
        System.out.println(c[0] + " " + c[1] + " " + c[2]);
        System.out.println();
    }
}
