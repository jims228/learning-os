# Chapter 5: Inheritance Part 1

## キー定義
- **サブクラス（subclass）**: 別のクラスから派生したクラス（derived class, child class）
- **スーパークラス（superclass）**: サブクラスの元となるクラス（base class, parent class）
- Javaは単一継承（1つのクラスは1つの直接スーパークラスのみ持つ）
- すべてのクラスは暗黙的に`Object`のサブクラス

## 継承の構文
```java
public class MountainBike extends Bicycle {
    protected int seatHeight;
    public MountainBike(int startHeight, int startCadence, int startSpeed, int startGear) {
        super(startCadence, startSpeed, startGear); // スーパークラスのコンストラクタ呼び出し
        seatHeight = startHeight;
    }
    public void setHeight(int newValue) { seatHeight = newValue; }
}
```

## サブクラスでできること
- 継承したフィールド・メソッドをそのまま使う
- 新しいフィールド・メソッドを追加
- インスタンスメソッドをオーバーライド（同じシグネチャで再定義）
- スタティックメソッドをハイド（同じシグネチャで再定義）
- `super`でスーパークラスのメンバにアクセス

## アクセス制御
- `private`フィールド・メソッドはサブクラスからアクセス不可
- `public`/`protected`はサブクラスからアクセス可能

## オーバーライド vs ハイド
| | スーパークラスのインスタンスメソッド | スーパークラスのstaticメソッド |
|---|---|---|
| **サブクラスのインスタンスメソッド** | オーバーライド | コンパイルエラー |
| **サブクラスのstaticメソッド** | コンパイルエラー | ハイド |

- オーバーライド: **サブクラスのメソッド**が呼ばれる
- ハイド: **どちらのクラスから呼ぶかで**決まる

```java
// 例
Animal myAnimal = new Cat();
Animal.testClassMethod();      // → Animal（hide: クラスで決まる）
myAnimal.testInstanceMethod(); // → Cat（override: インスタンスの実際の型で決まる）
```

## super キーワード
```java
// メソッド内でスーパークラスのメソッドを呼ぶ
super.method();

// コンストラクタでスーパークラスのコンストラクタを呼ぶ（必ず最初の行）
super(引数);
```

## コンストラクタチェーン
- サブクラスのコンストラクタは必ず（暗黙的または明示的に）スーパークラスのコンストラクタを呼ぶ
- `Object`まで遡って順番にコンストラクタが実行される

```java
// 出力順: Art → Drawing → Cartoon
class Art { Art() { System.out.println("Art constructor"); } }
class Drawing extends Art { Drawing() { System.out.println("Drawing constructor"); } }
class Cartoon extends Drawing { Cartoon() { System.out.println("Cartoon constructor"); } }
```

## キャスティング
```java
Object obj = new MountainBike(); // 暗黙的キャスト（OK）
MountainBike myBike = obj;       // コンパイルエラー
MountainBike myBike = (MountainBike)obj; // 明示的キャスト（実行時エラーの可能性）

// 安全なキャスト
if (obj instanceof MountainBike) {
    MountainBike myBike = (MountainBike)obj;
}
```

## コンポジション vs 継承
- **継承**: 「is-a」関係（MountainBike is a Bicycle）
- **コンポジション**: 「has-a」関係（Rectangle has a Point）
- 継承はクラス間の密結合を生む → 基本はコンポジションを優先
