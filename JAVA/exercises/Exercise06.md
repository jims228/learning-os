# Exercise 6 — Inheritance Part 2

## 演習日（C3クラス）
- 講義: 04/24
- 演習: 04/27
- 締切: 05/04（演習終了から1週間後）

---

## Problem A: Equals [1 pt]
`Point`クラスに`equals`メソッドをオーバーライドして、x, yが同じなら等しいと判定するようにする。

| Output |
|--------|
| p1 != p2 |
| p1 and p2 is equal |

**Submit:** `Point.java`

---

## Problem B: HAS-A and IS-A Relations [1 pt]
- `Quadrangle` IS-A `Shape`
- `Quadrangle` HAS-A 4つの`Point`

`Shape`は抽象クラスで`print()`と`abstract void move(int dx, int dy)`を持つ。
`Point`にはgetX, getY, moveを追加。

| Output |
|--------|
| Quadrangle: (8, 5)-(12, 8)-(9, 10)-(8, 7) |

**Submit:** `Point.java`, `Shape.java`, `Quadrangle.java`, `QuadrangleApplication.java`

---

## Problem C: Hierarchy of Shapes [2 pt]
クラス階層（is-a関係）:
```
Shape (abstract)
├── Circle
└── Quadrangle
    └── Parallelogram
        └── Rectangle
            └── Square
```

各クラスのコンストラクタ:
- `Circle(Point center, int radius)`
- `Quadrangle(Point p1, Point p2, Point p3, Point p4)`
- `Parallelogram(Point p1, Point p3, int width)` (p1, p3は対角)
- `Rectangle(Point p1, Point p3)` (p1, p3は対角)
- `Square(Point p1, int width)`

| Output |
|--------|
| Circle: (8, 5) radius = 3 |
| Quadrangle: (8, 5)-(12, 8)-(9, 10)-(8, 7) |
| Parallelogram: (13, 9)-(18, 9)-(20, 12)-(15, 12) |
| Rectangle: (11, 7)-(15, 7)-(15, 10)-(11, 10) |
| Square: (13, 11)-(15, 11)-(15, 13)-(13, 13) |

**Submit:** `Point.java`, `Circle.java`, `Quadrangle.java`, `Parallelogram.java`, `Rectangle.java`, `Square.java`, `Shape.java`, `ShapeApplication.java`

---

## Problem D: Composite Pattern: File Management System [4 pt]
`File`と`Directory`を抽象クラス`Entity`から継承する設計に変更。

```
Entity (abstract)
├── File
└── Directory (entities: Entity[])
```

`Directory.add(Entity)`で File も Directory も統一的に扱える。

| Output |
|--------|
| memo Ex01 Ex02 |
| 1589 bytes |
| Robot.java RobotSimulator.java BACKUP |
| 1509 bytes |
| memo Ex01 Ex02 score |
| 1689 bytes |
| SuperRobot.java RobotSimulator.java BACKUP |
| 1509 bytes |

**Submit:** `Entity.java`, `File.java`, `Directory.java`, `FileManagerApplication.java`
