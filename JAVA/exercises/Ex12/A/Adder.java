// Ex12-A: Adder
// コマンドライン引数で渡された数値をすべて足して合計を出力する。
// 例: java Adder 1 3 2 10  ->  16
class Adder {
    public static void main(String[] args) {
        int sum = 0;
        for (String arg : args) {
            sum += Integer.parseInt(arg);
        }
        System.out.println(sum);
    }
}
