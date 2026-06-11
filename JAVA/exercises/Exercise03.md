# Exercise 3 — Language Basics

## 演習日（C3クラス）
- 講義: 04/14
- 演習: 04/16
- 締切: 04/23（演習終了から1週間後）

---

## Problem A: Static Fields [1 pt]
`Point`クラスを拡張し、`X_MIN`, `Y_MIN`, `X_MAX`, `Y_MAX` を静的フィールドとして追加する。
`move`メソッドは移動後の座標が範囲外になる場合は無視する。

テスト用クラス（変更不可）:
```java
class RangingPointApplication{
    public static void main(String[] args){
        Point p1 = new Point();
        Point p2 = new Point();
        Point.X_MIN = -100;
        Point.X_MAX = 100;
        Point.Y_MIN = -100;
        Point.Y_MAX = 100;
        p1.move(50, 50);
        p1.move(100, 100);
        p2.move(-100, -100);
        System.out.println("(" + p1.getX() + ", " + p1.getY() + ")");
        System.out.println("(" + p2.getX() + ", " + p2.getY() + ")");
        p2.X_MAX = 200;
        p2.Y_MAX = 200;
        p1.X_MIN = -200;
        p1.Y_MIN = -200;
        p1.move(100, 100);
        p2.move(-100, -100);
        System.out.println("(" + p1.getX() + ", " + p1.getY() + ")");
        System.out.println("(" + p2.getX() + ", " + p2.getY() + ")");
    }
}
```

| Output |
|--------|
| (50, 50) |
| (-100, -100) |
| (150, 150) |
| (-200, -200) |

**Submit:** `Point.java`

---

## Problem B: Array Assignment [1 pt]
5つの空欄を埋めて `ArrayAssignmentApplication` を完成させる。各空欄には代入演算が1つ。

```java
class ArrayAssignmentApplication{
    public static void main(String[] args){
        new ArrayAssignmentApplication().run();
    }
    void run(){
        int[] a = {1, 2, 3};
        int[] b = {4, 5, 6};
        int[] c = {7, 8, 9};
        print(a, b, c);
        ________________;
        print(a, b, c);
        ________________;
        print(a, b, c);
        ________________;
        print(a, b, c);
        ________________;
        ________________;
        print(a, b, c);
    }
    void print(int[] a, int[] b, int[] c){
        System.out.println(a[0] + " " + a[1] + " " + a[2]);
        System.out.println(b[0] + " " + b[1] + " " + b[2]);
        System.out.println(c[0] + " " + c[1] + " " + c[2]);
        System.out.println();
    }
}
```

| Output |
|--------|
| 1 2 3 |
| 4 5 6 |
| 7 8 9 |
| (空行) |
| 1 2 3 |
| 1 2 3 |
| 7 8 9 |
| (空行) |
| 0 2 3 |
| 0 2 3 |
| 7 8 9 |
| (空行) |
| 7 8 9 |
| 0 2 3 |
| 7 8 9 |
| (空行) |
| 7 8 9 |
| 7 8 9 |
| 0 2 3 |
| (空行) |

**Submit:** `ArrayAssignmentApplication.java`

---

## Problem C: Array Manipulation: Sorting Arrays [1 pt]
`SortingArraysApplication`クラスに`sort`メソッドを実装する。配列を昇順に並べ替える。

```java
class SortingArraysApplication{
    public static void main(String[] args){
        new SortingArraysApplication().run();
    }
    void run(){
        int[][] arrays = {
            {3, 2, 1},
            {9, 7, 10, 4, 8, 2, 5, 3, 1, 6},
            {7, 2, 3, 2, 2, 1, 1, 1},
            {2, 1},
            {100},
            {888888888, -888888888}
        };
        for ( int t = 0; t < arrays.length; t++ ) sort(arrays[t]);
        for ( int i = 0; i < arrays.length; i++ ){
            for ( int j = 0; j < arrays[i].length; j++ ){
                System.out.print(" " + arrays[i][j]);
            }
            System.out.println();
        }
    }
    // ここを実装する
    void sort(int[] a){ /* your code */ }
}
```

| Output |
|--------|
| 1 2 3 |
| 1 2 3 4 5 6 7 8 9 10 |
| 1 1 1 2 2 2 3 7 |
| 1 2 |
| 100 |
| -888888888 888888888 |

**Submit:** `SortingArraysApplication.java`

---

## Problem D: Container Object: Stack [2 pt]
LIFOデータ構造の`Stack`クラスを作成する。要素はint、配列（容量100）で保持。
- `push(int)`: 要素を追加
- `pop()`: 要素を取り出して返す

テスト用クラス（テンプレート）:
```java
import java.util.Scanner;
class StackApplication{
    public static void main(String[] args){
        Stack st = new Stack();
        Scanner sc = new Scanner(System.in);
        while( true ){
            int x = sc.nextInt();
            if ( x < 0 ) break;
            // your code ...
        }
    }
}
```

ルール:
- `a_i >= 1`: スタックにpush
- `a_i == 0`: スタックからpopして出力
- `a_i < 0`: プログラム終了

| Sample Input | Sample Output |
|---|---|
| 8 7 5 3 9 8 11 0 0 10 21 8 6 4 0 0 0 7 | 11 |
| 2 3 0 9 0 0 0 0 15 17 0 -1 | 8 |
| | 4 |
| | 6 |
| | 8 |
| | 3 |
| | 9 |
| | 2 |
| | 7 |
| | 21 |
| | 17 |

**Submit:** `Stack.java`, `StackApplication.java`
