import java.util.Scanner;
class PrimeFactorizer {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.print(n+":");

        int i=2;
        while(n>1){
            while(n%i == 0){
                System.out.print(" " + i);
                n=n/i;
            }
            i++;
        }
        System.out.println();
    }
}
