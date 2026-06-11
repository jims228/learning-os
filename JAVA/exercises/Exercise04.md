# Exercise 4 — Classes and Objects

## 演習日（C3クラス）
- 講義: 04/17
- 演習: 04/20
- 締切: 04/27（演習終了から1週間後）

---

## Problem A: Passing Primitive Parameters to a Method [1 pt]
空欄を埋めて `PrimitiveCall` を完成させる。

テンプレート:
```java
import java.util.Scanner;
public class PrimitiveCall{
    public void test(){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        System.out.println("(x, y) = (" + x + ", " + y + ")");
        ___________________;  // ← ここを埋める
        System.out.println("(x, y) = (" + x + ", " + y + ")");
    }
    private void movePoint(int x, int y){
        System.out.println("(x, y) = (" + x + ", " + y + ")");
        x = 100;
        y = 120;
        System.out.println("(x, y) = (" + x + ", " + y + ")");
    }
    public static void main(String[] args){
        new PrimitiveCall().test();
    }
}
```

| Sample Input | Sample Output |
|---|---|
| 8 5 | (x, y) = (8, 5) |
| | (x, y) = (8, 5) |
| | (x, y) = (100, 120) |
| | (x, y) = (8, 5) |

**ポイント**: プリミティブ型は値渡し → メソッド内で変更してもxとyは元のまま。

**Submit:** `PrimitiveCall.java`

---

## Problem B: Passing References to a Method [1 pt]
3か所の空欄を埋めて `ReferenceCall` を完成させる。

Point.java（別途作成）:
```java
public class Point{
    private int x, y;
    public Point(int x, int y){ this.x = x; this.y = y; }
    public void setX(int x){ this.x = x; }
    public void setY(int y){ this.y = y; }
    public int getX(){ return x; }
    public int getY(){ return y; }
}
```

ReferenceCall.javaのテンプレート:
```java
import java.util.Scanner;
public class ReferenceCall{
    public void test(){
        Scanner sc = new Scanner(System.in);
        Point p = new Point(sc.nextInt(), sc.nextInt());
        System.out.println("(x, y) = (" + p.getX() + ", " + p.getY() + ")");
        ___________________;  // 1つ目の空欄
        System.out.println("(x, y) = (" + p.getX() + ", " + p.getY() + ")");
        ___________________;  // 2つ目の空欄
        System.out.println("(x, y) = (" + p.getX() + ", " + p.getY() + ")");
        ___________________;  // 3つ目の空欄
        System.out.println("(x, y) = (" + p.getX() + ", " + p.getY() + ")");
    }
    private void movePoint(Point o, int dx, int dy){
        o.setX(dx);
        o.setY(dy);
    }
    private void initPoint(Point o){
        o.setX(0);
        o.setY(0);
    }
    private void resetPoint(Point o){
        o = new Point(0, 0);  // 参照のコピーを変えるだけ → 元のpは変わらない
    }
    public static void main(String[] args){
        new ReferenceCall().test();
    }
}
```

| Sample Input | Sample Output |
|---|---|
| 8 5 | (x, y) = (8, 5) |
| | (x, y) = (0, 0) |
| | (x, y) = (100, 120) |
| | (x, y) = (100, 120) |

**Submit:** `ReferenceCall.java`（Point.javaも必要）

---

## Problem C: Container Object: Doubly Linked List [2 pt]
`SimpleNode` クラスと `SimpleList` クラスを実装する。

`SimpleList` のメソッド:
- `insert(int key)`: リストの先頭に挿入
- `delete(int key)`: 最初に見つかった要素を削除
- `printList()`: リストの要素を順番に出力

テンプレート（SimpleList）:
```java
class SimpleList{
    private SimpleNode nil;
    SimpleList(){ init(); }
    void init(){
        nil = new SimpleNode();
        nil.setNext(nil);
        nil.setPrev(nil);
    }
    SimpleNode listSearch(int key){ /* your code */ }
    void printList(){ /* your code */ }
    void delete(int key){ /* your code */ }
    void insert(int key){ /* your code */ }
}
```

テスト用クラス（SimpleListApplication）:
```java
import java.util.Scanner;
class SimpleListApplication{
    public static void main(String[] args){
        new SimpleListApplication().run();
    }
    void run(){
        SimpleList list = new SimpleList();
        Scanner sc = new Scanner(System.in);
        int Q = sc.nextInt();
        for (int i = 0; i < Q; i++){
            String command = sc.next();
            if (command.equals("insert")){
                int key = sc.nextInt();
                list.insert(key);
            } else if (command.equals("delete")){
                int key = sc.nextInt();
                list.delete(key);
            } else if (command.equals("print")){
                list.printList();
            }
        }
    }
}
```

| Sample Input | Sample Output |
|---|---|
| 10 / insert 8 / insert 5 / insert 2 / insert 11 / insert 6 / delete 2 / print / insert 15 / delete 6 / print | 6 11 5 8 / 15 11 5 8 |

**Submit:** `SimpleNode.java`, `SimpleList.java`, `SimpleListApplication.java`

---

## Problem D: Array of Objects: Multiple Queues [2 pt]
N個のレーンがあるガソリンスタンドのシミュレーション。

ルール:
- 車が来たら最も少ない台数のレーンに並ぶ（同数なら番号が小さいレーン）
- `0 lane`: レーン番号`lane`の先頭の車が給油完了 → その車番号を出力
- `1 car`: 車番号`car`が入場

| Sample Input | Sample Output |
|---|---|
| 2 7 / 1 999 / 1 1000 / 0 2 / 1 1001 / 1 1002 / 0 1 / 0 1 | 1000 / 999 / 1002 |

- AOJで検証可能: https://onlinejudge.u-aizu.ac.jp/beta/ice/?problemId=0417
- AOJ提出時はmainを含むクラス名を `Main` にすること

**Submit:** 実装した全クラス
