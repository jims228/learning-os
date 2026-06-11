# Exercise 5 — Inheritance Part 1

## 演習日（C3クラス）
- 講義: 04/21
- 演習: 04/21
- 締切: 04/28（演習終了から1週間後）

---

## Problem A: Inheritance: MovingPoint2D [2 pt]
Ex02のPoint2Dクラスを拡張し、`distance()`と`toString()`を追加。
さらに`MovingPoint2D`クラスをPoint2Dの**継承**で作成。

**Point2Dへの追加メソッド:**
| メソッド | 詳細 |
|---|---|
| `distance(Point2D other)` | 2点間の距離を返す |
| `toString()` | `(x, y)` の形式で返す（Objectのtoustringをオーバーライド） |

**MovingPoint2Dのフィールド:**
| フィールド | 詳細 |
|---|---|
| `vx` | x方向の速度 |
| `vy` | y方向の速度 |

**MovingPoint2Dのメソッド:**
| メソッド | 詳細 |
|---|---|
| `setVelocity(double a, double b)` | vx, vyを更新 |
| `move()` | x += vx, y += vy |

コンストラクタ: `MovingPoint2D(x, y, vx, vy)`

テスト用クラス:
```java
class MovingPoint2DApplication{
    public static void main(String[] args){
        MovingPoint2D p1 = new MovingPoint2D(0, 0, 3, 4);
        MovingPoint2D p2 = new MovingPoint2D(0, 0, 0, -1);
        for ( int i = 0; i < 10; i++ ) {
            p1.move();
            p2.move();
        }
        System.out.println(p1 + "-" + p2 + ": " + p1.distance(p2));
        p2.setVelocity(30, 0);
        p2.move();
        System.out.println(p1 + "-" + p2 + ": " + p1.distance(p2));
    }
}
```

| Output |
|--------|
| (30.0, 40.0)-(0.0, -10.0): 58.309518948453004 |
| (30.0, 40.0)-(30.0, -10.0): 50.0 |

**Submit:** `A/Point2D.java`, `A/MovingPoint2D.java`, `A/MovingPoint2DApplication.java`

---

## Problem B: Composition: MovingPoint2D [2 pt]
A問題と同じMovingPoint2Dを今度は**コンポジション**で実装する。
- MovingPoint2DはPoint2Dを継承せず、Point2Dオブジェクトをフィールドとして持つ
- MovingPoint2DApplicationはA問題と同じものを使う（変更不可）
- 同じ出力になればOK

**Submit:** `B/Point2D.java`, `B/MovingPoint2D.java`, `B/MovingPoint2DApplication.java`

---

## Problem C: Constructor Chain: Trees [2 pt]
以下のクラス階層を実装する（各クラスはデフォルトコンストラクタでクラス名を出力するだけ）。

```
Tree
└── RootedTree
    └── BinaryTree
        └── OrderedTree
```

テスト用クラス:
```java
class ConstructorChainApplication{
    public static void main(String[] args){
        new BinaryTree();
    }
}
```

出力（コンストラクタが呼ばれた順）:
```
Tree
RootedTree
BinaryTree
```

**Submit:** `C/Tree.java`, `C/RootedTree.java`, `C/BinaryTree.java`, `C/OrderedTree.java`, `C/ConstructorChainApplication.java`

---

## Problem D: Overriding: ModInt [2 pt]
`Int`クラスと`MInt`クラスを実装する。

**Intクラス:**
| フィールド/メソッド | 詳細 |
|---|---|
| `int x` | 保持する整数 |
| `INT_MAX = 1024` | 最大値（static） |
| `add(Int a)` | 加算した新しいIntを返す |
| `mul(Int a)` | 乗算した新しいIntを返す |
| `setValue(int a)` | xを更新 |
| `getValue()` | xを返す |
| `toString()` | xの値を文字列で返す |

**MIntクラス（Intを継承）:**
- `MOD = 107`（static）
- `add`, `mul`は結果をMODで割った余りを返す

テスト用クラス（変更不可）:
```java
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
```

| Output |
|--------|
| 0 (1024) |
| 0 (1024) |
| 1 (1024) |
| MOD = 107 |
| 900 |
| 44 |
| 44 |

**Submit:** `D/Int.java`, `D/MInt.java`, `D/IntApplication.java`
