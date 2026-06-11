// Ex12-D: Transformation (AOJ ITP1_9_D)
// 文字列 str に対して q 個のコマンドを順に実行する。インデックスは 0 始まり。
//   print a b      : a 文字目から b 文字目までを出力
//   reverse a b    : a 文字目から b 文字目までを反転
//   replace a b p  : a 文字目から b 文字目までを p で置換
// StringBuilder で可変文字列として扱う。substring/replace の終端は b+1（半開区間）。
// 注: AOJ 提出時のクラス名は Main。
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder str = new StringBuilder(sc.next());
        int q = Integer.parseInt(sc.next());
        for (int i = 0; i < q; i++) {
            String cmd = sc.next();
            int a = sc.nextInt();
            int b = sc.nextInt();
            if (cmd.equals("print")) {
                System.out.println(str.substring(a, b + 1));
            } else if (cmd.equals("reverse")) {
                String rev = new StringBuilder(str.substring(a, b + 1)).reverse().toString();
                str.replace(a, b + 1, rev);
            } else if (cmd.equals("replace")) {
                String p = sc.next();
                str.replace(a, b + 1, p);
            }
        }
    }
}
