import java.util.Scanner;
class StackApplication{
    public static void main(String[] args){
        Stack st = new Stack();
        Scanner sc = new Scanner(System.in);
        while( true ){
            int x = sc.nextInt();
            if ( x < 0 ) break;
            if ( x == 0 ){
                System.out.println(st.pop());
            } else {
                st.push(x);
            }
        }
    }
}
