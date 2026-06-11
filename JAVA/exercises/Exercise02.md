# Exercise 2 — Object Oriented Programming

## 演習日（C3クラス）
- 講義: 04/10
- 演習: 04/13
- 締切: 04/20（演習終了から1週間後）

## Problem A: Creating Objects: Point [1 pt]
`Point` クラスを作成する。フィールドとして x, y 座標を持ち、setter/getter メソッドを実装する。

テスト用クラス `PointCreationApplication`:
```java
import java.util.Scanner;
class PointCreationApplication{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Point p1 = new Point();
        Point p2 = new Point();
        p1.setX(sc.nextInt()); p1.setY(sc.nextInt());
        p2.setX(sc.nextInt()); p2.setY(sc.nextInt());
        System.out.println("(" + p1.getX() + ", " + p1.getY() + ")");
        System.out.println("(" + p2.getX() + ", " + p2.getY() + ")");
    }
}
```

| Sample Input | Sample Output |
|---|---|
| 1 2 / 3 4 | (1, 2) / (3, 4) |

**Submit:** `Point.java`, `PointCreationApplication.java`

---

## Problem B: Manipulating Objects I: Moving Point [1 pt]
`Point` クラスに `move(dx, dy)` メソッドを追加。初期位置は(0, 0)。

テスト用クラス `PointMovingApplication`:
```java
import java.util.Scanner;
class PointMovingApplication{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Point pt = new Point();
        int Q = sc.nextInt();
        for (int i = 0; i < Q; i++){
            int dx = sc.nextInt();
            int dy = sc.nextInt();
            pt.move(dx, dy);
        }
        System.out.println("(" + pt.getX() + ", " + pt.getY() + ")");
    }
}
```

| Sample Input | Sample Output |
|---|---|
| 5 / 1 2 / 3 4 / 5 6 / 7 8 / 9 10 | (25, 30) |

**Submit:** `Point.java`（AとBを兼用）, `PointMovingApplication.java`

---

## Problem C: Manipulating Objects II: Safe Moving Point [1 pt]
`move` メソッドに制約を追加: 移動後の x または y の絶対値が100を超える場合は移動しない。

テスト用クラスは Problem B と同じ `PointMovingApplication`。

| Sample Input | Sample Output |
|---|---|
| 10 / 20 10 / 35 65 / 10 30 / 0 -15 / 10 30 / -90 10 / -80 0 / 5 -5 / -80 2 / 20 -11 | (-80, 86) |

**Submit:** `Point.java`（A, B, Cを兼用）

---

## Problem D: Manipulating Objects III: Vector [1 pt]
`Point2D` クラスを作成。以下のフィールドとメソッドを実装する。

| フィールド | 詳細 |
|---|---|
| x | double型 x座標 |
| y | double型 y座標 |

| メソッド | 詳細 |
|---|---|
| add(Point2D) | ベクトルの和（自身に加算） |
| scale(F) | ベクトルをF倍にスケール |
| length() | ベクトルの長さを返す |
| dotProduct(Point2D) | 内積を返す: Ax*Bx + Ay*By |
| crossProduct(Point2D) | 外積を返す: Ax*By - Ay*Bx |

公式:
- 長さ: `Math.sqrt(x*x + y*y)`
- 内積: `Ax*Bx + Ay*By`
- 外積: `Ax*By - Ay*Bx`

| Sample Input | Sample Output |
|---|---|
| 3.0 4.0 / 2.0 -2.0 | Length of v1: 5.0 / Length of v2: 2.8284... / Dot product: -2.0 / Cross product: -14.0 / Length of v1: 5.3851... / Length of v2: 282.842... |

テスト用クラス `VectorManipulationApplication`:
```java
import java.util.Scanner;
class VectorManipulationApplication{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Point2D v1 = new Point2D();
        Point2D v2 = new Point2D();
        v1.setX(sc.nextDouble());
        v1.setY(sc.nextDouble());
        v2.setX(sc.nextDouble());
        v2.setY(sc.nextDouble());
        System.out.println("Length of v1: " + v1.length());
        System.out.println("Length of v2: " + v2.length());
        System.out.println("Dot product of v1 and v2: " + v1.dotProduct(v2));
        System.out.println("Cross product of v1 and v2: " + v1.crossProduct(v2));
        v1.add(v2);
        v2.scale(100);
        System.out.println("Length of v1: " + v1.length());
        System.out.println("Length of v2: " + v2.length());
    }
}
```

**Submit:** `Point2D.java`, `VectorManipulationApplication.java`
