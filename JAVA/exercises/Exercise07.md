# Exercise 7 — Interfaces

## 演習日（C3クラス・公式スケジュール表確定）
- 講義+演習: 04/28 (火) ※ 講義と演習は同日実施
- 締切: 05/05 (月) ※ 演習日から1週間以内

(過去 Exercise01-06.md に「講義/演習別日」と書いていたが誤記、実際は同日)
(C5C6 クラスは 04/30 が演習日、別日程)

---

## Problem A: Container Interface [2 pt]

ex3 Problem D で実装した `Stack` クラスを `Container` インターフェース実装に書き直す。

`Container` インターフェースが要求するメソッド:

| Method | Details |
|---|---|
| `size()` | コンテナ内の要素数を返す |
| `isEmpty()` | 空なら true |
| `isFull()` | 満杯なら true |

`new Stack(5)` で容量 5 の Stack を作り、push/pop しながら状態 (`empty`/数値/`full`) を表示する `ContainerApplication` で動作確認。

| Sample Output |
|---|
| empty / 1 / 2 / 3 / 4 / full / 4 / 3 / 2 / 1 / empty |

**Submit:** `Container.java` (interface), `Stack.java`, `ContainerApplication.java`

---

## Problem B: Relatable Interface [2 pt]

2 点の位置を比較する `Relatable` インターフェースを実装した `Point` クラスを作る。

```java
public interface Relatable {
    public boolean isSmallerThan(Relatable other);
}
```

比較基準:
- x が小さい方が smaller
- x が同じなら y が小さい方が smaller

| Sample Input | Sample Output |
|---|---|
| 1 2 / 3 4 | (1, 2) is smaller than (3, 4) |
| 5 4 / 3 2 | (5, 4) is not smaller than (3, 2) |
| 5 7 / 5 8 | (5, 7) is smaller than (5, 8) |
| 1 2 / 1 2 | (1, 2) is not smaller than (1, 2) |

**Submit:** `Point.java`, `Relatable.java`, `RelatableApplication.java`

---

## Problem C: Sorting Relatable Objects I [2 pt]

`Relatable[]` を昇順にソートする `SortingMachine` クラスを作る。
`SortingPointApplication` は `Point[]` を読み取り、`machine.sort(p)` でソートして `print()` する。

| Sample Input | Sample Output |
|---|---|
| 8 / 7 5 / 3 5 / 1 2 / 4 8 / 4 1 / 11 9 / 6 6 / 2 1 | (1, 2) / (2, 1) / (3, 5) / (4, 1) / (4, 8) / (6, 6) / (7, 5) / (11, 9) |

**Submit:** `SortingMachine.java`, `SortingPointApplication.java`

---

## Problem D: Sorting Relatable Objects II [2 pt]

`Relatable` を実装した `Rectangle` クラスを作り、面積 (`getArea()`) で昇順ソートする。
- `Rectangle(Point p1, Point p3)` 対角線上の 2 点でコンストラクト
- `SortingMachine` は変更せずに `Rectangle[]` もソート可能 (interface の威力)

| Sample Input | Sample Output |
|---|---|
| 8 / 0 0 3 2 / 0 0 4 6 / 0 0 8 2 / 0 0 6 4 / 0 0 1 1 / 0 0 12 8 / 0 0 4 9 / 0 0 22 1 | 1 / 6 / 16 / 22 / 24 / 24 / 36 / 96 |

**Submit:** `SortingRectangleApplication.java`, `Rectangle.java`

---

## Summary
- Interface = メソッド署名のみの「契約」、フィールドや実装は持たない (constants は除く)
- 1 つの `SortingMachine` で `Point[]` も `Rectangle[]` もソートできる = 多態性の典型例
- Java は単一継承だが、interface は複数実装可能 → 「多重継承」の代替

## 提出ファイル一覧 (zip 化)
- A: `Container.java` + `Stack.java` + `ContainerApplication.java`
- B: `Point.java` + `Relatable.java` + `RelatableApplication.java`
- C: `SortingMachine.java` + `SortingPointApplication.java` (+ Point/Relatable コピー)
- D: `Rectangle.java` + `SortingRectangleApplication.java` (+ Point/Relatable/SortingMachine コピー)

zip 名 (慣例): `s1330096_ex07.zip`
