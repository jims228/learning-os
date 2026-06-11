// Ex12-C: Ring (AOJ ITP1_8_D)
// リング状の文字列 s の中にパターン p が存在するか判定する。
// s を 2 回つなげれば全ての回転（循環）パターンを含むので、
// (s + s) の中に p が部分文字列として現れるかを調べればよい。
// 注: AOJ 提出時のクラス名は Main。
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        String p = sc.next();
        String ring = s + s;
        System.out.println(ring.contains(p) ? "Yes" : "No");
    }
}
