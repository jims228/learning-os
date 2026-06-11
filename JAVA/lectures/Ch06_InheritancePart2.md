# Chapter 6: Inheritance Part 2

## Object クラス
- すべてのクラスの暗黙の親
- 主なメソッド: `equals()`, `hashCode()`, `toString()`, `getClass()`

### equals メソッド
- デフォルトでは参照（==）と同じ動作
- 内容比較したい場合はオーバーライド

```java
public boolean equals(Object o){
    if(!(o instanceof Point)) return false;
    Point p = (Point) o;
    return this.x == p.x && this.y == p.y;
}
```

## 抽象クラス（abstract class）
- インスタンス化できない
- 抽象メソッド（実装なし）を持てる
- サブクラスで具体的に実装する必要がある

```java
abstract class Shape {
    public void print(){ ... }              // 通常のメソッド
    public abstract void move(int, int);    // 抽象メソッド
}
```

## IS-A 関係 vs HAS-A 関係
- **IS-A**: 継承（extends） — Quadrangle is a Shape
- **HAS-A**: コンポジション — Quadrangle has Points

| 関係 | 表現 | 例 |
|---|---|---|
| IS-A | `class B extends A` | `Square extends Rectangle` |
| HAS-A | フィールドとして保持 | `class Quadrangle { Point[] P; }` |

## コンポジットパターン（Composite Pattern）
- 木構造を統一的に扱うデザインパターン
- 葉（File）と複合オブジェクト（Directory）を共通の親（Entity）で扱う

```
Entity (abstract)
├── File         (leaf)
└── Directory    (composite, has Entity[])
```

メリット:
- クライアントコードが File / Directory を区別する必要がない
- 新しい型（例: Shortcut）を追加しても既存コードを変更不要

## getClass().getName()
- 実行時の実際の型名を返す
- ポリモーフィズムを利用したクラス名取得に便利

```java
public void print(){
    System.out.print(this.getClass().getName() + ": ");
    // Square インスタンスなら "Square" が表示される
}
```
