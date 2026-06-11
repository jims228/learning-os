# Chapter 4: Classes and Objects

## クラスの宣言
```java
class ClassName {
    fields        // フィールド（状態）
    constructors  // コンストラクタ（初期化）
    methods       // メソッド（振る舞い）
}
```

## アクセス修飾子
- `public`: どのクラスからもアクセス可
- `private`: そのクラス内からのみアクセス可
- `protected`: 同パッケージ + サブクラスからアクセス可
- なし（package-private）: 同パッケージのみ

| Modifier | Class | Package | Subclass | World |
|---|---|---|---|---|
| public | Y | Y | Y | Y |
| protected | Y | Y | Y | N |
| no modifier | Y | Y | N | N |
| private | Y | N | N | N |

**Tips**: フィールドは基本 `private` にする。`public` フィールドは避ける（定数を除く）。

## コンストラクタ
- クラス名と同じ名前
- 返り値なし
- オブジェクト生成時に自動で呼ばれる
- コンストラクタを定義しなければデフォルトコンストラクタ（引数なし）が自動生成される

```java
public Bicycle(int startCadence, int startSpeed, int startGear) {
    cadence = startCadence;
    speed = startSpeed;
    gear = startGear;
}
// デフォルトコンストラクタ（引数なし）
public Bicycle() {
    gear = 1; cadence = 10; speed = 0;
}
```

## オブジェクトの生成（3ステップ）
```java
Bicycle bike1 = new Bicycle();
// 1. Declaration（宣言）: Bicycle bike1
// 2. Instantiation（インスタンス化）: new
// 3. Initialization（初期化）: Bicycle()
```

- オブジェクトはヒープ上に作成される
- 変数にはオブジェクトへの参照（リモコン）が入る
- `String str;` はオブジェクトを作らない（宣言のみ）

## オブジェクト生成の順序
1. フィールドのメモリ確保
2. フィールドの初期化
3. コンストラクタ実行
4. 参照を返す

## メソッドの定義
```java
public double methodName(double parameter) {
    // method body
}
```
6つの要素: 修飾子、返り値の型、メソッド名、引数リスト、例外リスト、メソッド本体

## メソッドのオーバーロード
- 同じクラス内で同じ名前・異なる引数リストのメソッドを複数定義できる
- 返り値の型や修飾子では区別されない

```java
void draw(String s) { ... }
void draw(int i) { ... }
void draw(double f) { ... }
void draw(int i, double f) { ... }
```

## this キーワード
- 現在のオブジェクト自身への参照
- フィールド名と引数名が同じ場合に使う

```java
public Point(int x, int y) {
    this.x = x;  // this.x = フィールド、x = 引数
    this.y = y;
}
```

- コンストラクタから別コンストラクタを呼ぶこともできる: `this(0, 0);`

## 引数の渡し方
### プリミティブ型（値渡し）
- コピーが渡されるので、メソッド内で変更しても元の値は変わらない

```java
int x = 3;
passMethod(x);  // x のコピーを渡す
// passMethod内でコピーが変わってもxは3のまま
```

### 参照型（参照のコピーを渡す）
- オブジェクトへの参照のコピーが渡される
- 同じオブジェクトを指しているのでオブジェクトの中身は変更できる
- ただし参照自体（どのオブジェクトを指すか）は変えられない

```java
Cat A = new Cat();
doStuff(A);  // A の参照のコピーBが渡される
void doStuff(Cat B) {
    B.name = "Tama";   // A のCatが変わる
    B = new Cat();     // A は変わらない
}
```

## static（クラス変数・クラスメソッド）
- `static` フィールド: そのクラスの全オブジェクトで1つだけ共有
- `static` メソッド: `ClassName.method()` で呼べる
- `static` メソッド内では `this` は使えない（インスタンスに依存しないため）

## 定数（final）
```java
final int value = 3;  // 初期化済み
value = 5;            // エラー！変更不可
```

## ガベージコレクション
- 参照がなくなったオブジェクトは自動的にメモリが解放される
- `p = null;` とすると参照を切れる
