# Java2.pdf 2023 過去問 読み取りメモ

作成日: 2026-06-08

## 元資料

Windows:

```text
C:\Users\shing\Downloads\Java2.pdf
```

WSL:

```text
/mnt/c/Users/shing/Downloads/Java2.pdf
```

## 読み取り状況

PDF はテキスト抽出できないスキャン画像だった。
全 7 ページ。

最後のページはかなりぼやけているため、Q05〜Q08 は一部低信頼。
ただし、手書き答えとコードの形から、出題テーマはかなり読み取れる。

## 試験形式

見える範囲では、ほぼ次の2形式で構成されている。

1. プログラムの出力を書け。
2. 指定された出力になるように空欄を埋めよ。

満点を狙う試験というより、Java の典型挙動を追えるかを見る試験。
30点以上狙いなら、頻出パターンを固めれば十分勝負できる。

## 30点以上の最短ルート

まずは次の8問タイプを優先する。

| 優先 | 対象 | 理由 |
|---|---|---|
| A | Q01 overload | 型で呼ばれるメソッドが決まるだけ |
| A | Q02 override / dynamic binding | 継承の基本で出やすい |
| A | Q03 static field hiding | ルールを知っていれば一瞬 |
| A | Q04 `==` と `equals` | 頻出、簡単 |
| A | Q11 String と引数渡し | `String` は差し替えても元が変わらない |
| A | Q13 配列参照 | 参照渡しっぽい動きの典型 |
| A | Q15 `super(...)` | コンストラクタ穴埋めの定番 |
| A | Q16 `this.x = x` | フィールド代入の定番 |

この8問を取れると、各4点なら32点に届く。
保険として Q17, Q19, Q20, Q21 もかなり取りやすい。

## 問題別メモ

### Q01: overload

テーマ:

```text
同じ名前のメソッドが複数あるとき、引数の型で呼ばれるものが決まる。
```

見える呼び出し:

```java
c.f(2.0, 3, 4.0)
```

優先される形:

```java
double f(double a, int b, double c)
```

計算:

```java
f(2.0, 3) * 4.0
= 6.0 * 4.0
= 24.0
```

答え:

```text
24.0
```

### Q02: override / dynamic binding

テーマ:

```text
変数の型が A でも、実体が B なら override された call() が動く。
```

答え:

```text
ABB
```

ポイント:

```java
A ab = new B();
ab.play();
```

`play()` は A のものでも、中で呼ぶ `call()` は実体 B の `call()` になる。

### Q03: static final field hiding

テーマ:

```text
static field は override されない。
参照変数のコンパイル時の型で決まる。
```

答え:

```text
foobarfoobarfoo
```

内訳:

```java
Base.FOO        // foo
Sub.FOO         // bar
b.FOO           // foo  b は Base 型
s.FOO           // bar  s は Sub 型
((Base)s).FOO   // foo
```

### Q04: `==` と `equals`

テーマ:

```text
== は同じオブジェクトかを見る。
equals は中身を比較するように自作されている。
```

答え:

```text
CEF
```

ポイント:

```java
s1 == s4      // true, 同じ参照
s1.equals(s3) // true, id が同じ
s1.equals(s4) // true, 同じ参照なので id も同じ
```

### Q05: swap / primitive と参照

読み取り信頼度: 低め。

テーマ:

```text
メソッドに渡した primitive は呼び出し元を変えない。
オブジェクトのフィールド変更は残る。
参照そのものの入れ替えは呼び出し元を変えない。
```

見える手書き答え:

```text
3 5
5 3
5 3
```

### Q06: try / catch / finally

読み取り信頼度: 低め。

テーマ:

```text
例外が起きると catch に入り、その後 finally は必ず実行される。
```

見える手書き答え:

```text
T321AF
```

### Q07: static 変数と instance 変数

テーマ:

```text
static 変数はインスタンス間で共有される。
instance 変数は各オブジェクトごとに別。
```

見える答え:

```text
3:2
5:2
```

ポイント:

```java
Part nut = new Part(3);
Part bolt = new Part(5);
nut.cnt++;
bolt.cnt++;
nut.print();
bolt.print();
```

`cnt` が static なので、2個のオブジェクトで共有され、最終的に 2 になる。

### Q08: getter / setter

読み取り信頼度: 中。

テーマ:

```text
private field は getter / setter 経由で扱う。
```

空欄例:

```java
a = x;
return a;
x.getA()
```

見える答え:

```text
710
```

### Q09: constructor chain / field initialization

テーマ:

```text
親コンストラクタ、フィールド初期化、自分のコンストラクタの順番。
```

答え:

```text
AXBC
```

流れ:

1. `new C()`
2. `A()` が動く → `A`
3. `B` のフィールド `X x = new X()` → `X`
4. `B()` → `B`
5. `C()` → `C`

### Q10: dynamic binding

テーマ:

```text
変数の型ではなく、実体のクラスで override メソッドが決まる。
```

答え:

```text
BBDacd
```

内訳:

```java
A a = new B();  a.x(); // B
C c = new C();  c.x(); // B
D d = new D();  d.x(); // D
a.y();                 // a
c.y();                 // c
d.y();                 // d
```

### Q11: String とメソッド引数

テーマ:

```text
メソッド内で引数 str に別の String を代入しても、呼び出し元の str は変わらない。
```

答え:

```text
Yes
Yes
```

### Q12: polymorphism

テーマ:

```text
配列の型は Link[] でも、実体の class に応じて override メソッドが動く。
```

答え:

```text
Link A Button B Link [C]
```

スペース込みでは、各出力の後ろに空白が入る。

### Q13: 2次元配列と参照

テーマ:

```text
2次元配列の一部をメソッドに渡すと、その配列本体が変更される。
```

見えるコード:

```java
int[][] a = {
    {0, 1, 2},
    {3, 4},
    {5}
};
int[][] b = a;
argument(b[1]);
System.out.println(sum(a));
```

`argument` は各要素を2倍している。
つまり `{3,4}` が `{6,8}` になる。

答え:

```text
22
```

### Q14: interface / implements

テーマ:

```text
interface 型の変数に、implements したクラスのオブジェクトを入れられる。
```

空欄:

```java
interface A
class S implements A
```

答え:

```text
4
```

### Q15: constructor and `super`

テーマ:

```text
子クラスのコンストラクタから親クラスのコンストラクタを呼ぶ。
```

空欄:

```java
super(b);
```

出力:

```text
100
80
```

### Q16: `this`

テーマ:

```text
引数 x とフィールド x を区別する。
```

空欄:

```java
this.x = x;
```

出力:

```text
100
80
```

### Q17: interface and polymorphism

テーマ:

```text
interface 型の変数に Button / Icon を入れて、同じ click() を呼ぶ。
```

空欄:

```java
interface Clickable
class Button implements Clickable
class Icon implements Clickable
Clickable target;
target = new Button();
target = new Icon();
```

出力:

```text
Button
Icon
```

### Q18: downcast

テーマ:

```text
親型の変数に入っている実体が子クラスなら、子クラスへキャストできる。
```

空欄:

```java
(BinaryTree)t1
```

出力:

```text
Rooted Tree
```

### Q19: object array

テーマ:

```text
オブジェクト配列は、配列を作っただけでは中身のオブジェクトは作られない。
各要素に new が必要。
```

空欄:

```java
new MyInteger[10]
new MyInteger(i)
```

出力:

```text
0123456789
```

### Q20: abstract class

テーマ:

```text
abstract class は未実装メソッドを持てる。
実体は子クラス X / Y。
```

空欄:

```java
abstract class A
abstract void call();
A p = new X();
A q = new Y();
```

出力:

```text
XY
```

### Q21: Strategy pattern

テーマ:

```text
interface 型のフィールドに処理方法を入れ替える。
Adder なら足し算、Multiplier なら掛け算。
```

空欄:

```java
interface Service
implements Service
Service stg;
Context(Service a)
void setService(Service a)
return stg.calc(a, b);
new Adder()
new Multiplier()
```

出力:

```text
8
15
```

### Q22: IS-A relationship

テーマ:

```text
extends で「A is a B」の関係を作る。
```

空欄例:

```java
class Square extends Rectangle {}
class Rectangle extends Parallelogram {}
class Quadrangle extends Shape {}
class Parallelogram extends Quadrangle {}
```

関係:

```text
Square -> Rectangle -> Parallelogram -> Quadrangle -> Shape
```

### Q23: overload and cast

テーマ:

```text
overload は実行時の型ではなく、コンパイル時の引数型で決まる。
```

空欄:

```java
class D implements A, B, C
fx((A)d);
fx((B)d);
fx((C)d);
fx(d);
```

出力:

```text
ABCD
```

### Q24: exception hierarchy

テーマ:

```text
catch は上から順に判定される。
finally は必ず実行される。
```

継承関係:

```java
class A extends Exception {}
class B extends A {}
class C extends B {}
class D extends Exception {}
```

答え:

```text
AFBFBFEFF
```

内訳:

| p | throw | catch | 出力 |
|---|---|---|---|
| 1 | A | A | AF |
| 2 | B | B | BF |
| 3 | C | B | BF |
| 4 | D | Exception | EF |
| 5 | なし | なし | F |

## まず覚えるべき型

### 出力問題

1. overload: 引数の型で決まる。
2. override: 実体のクラスで決まる。
3. static field: 変数の型で決まる。
4. `==`: 同じオブジェクトか。
5. `equals`: 中身比較。ただし自作実装を見る。
6. `String`: メソッド内で代入しても呼び出し元は変わらない。
7. 配列: 中身を書き換えると呼び出し元にも残る。
8. 例外: catch は上から、finally は必ず。

### 空欄補充

1. interface
2. implements
3. abstract
4. extends
5. super(...)
6. this.x = x
7. new Type[n]
8. new Type(...)
9. キャスト `(Child)parent`
10. interface 型のフィールド・引数

## 次にやること

30点以上を最短で狙うなら、次から解く。

1. Q01〜Q04: 出力追跡の基本
2. Q11, Q13, Q15, Q16: 取りやすい4問
3. Q17, Q19, Q20, Q21: 空欄補充の得点源
4. Q24: 例外処理。少し重いが出たら得点差になる
