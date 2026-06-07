# Java 期末 30点突破ルート

作成日: 2026-06-08

## 方針

目的は満点ではなく、まず 30 点以上を取りに行くこと。

過去問 `Java2.pdf` は、ほぼ次の2種類だった。

1. 出力を答える問題
2. 空欄補充問題

0から始めるなら、講義を全部読むよりも、過去問で出ている型に対応する講義・演習だけを集中して練習する。

## 参照した資料

過去問:

```text
/mnt/c/Users/shing/Downloads/Java2.pdf
```

講義:

```text
JAVA/lectures/Ch03_LanguageBasics.md
JAVA/lectures/Ch04_ClassesAndObjects.md
JAVA/lectures/Ch05_Inheritance.md
JAVA/lectures/Ch06_InheritancePart2.md
JAVA/lectures/Ch07_Interfaces.md
JAVA/lectures/Ch08_Polymorphism_Part1.md
JAVA/lectures/Ch09_Polymorphism_Part2.md
JAVA/lectures/Ch11_Exceptions.md
JAVA/lectures/Ch12_NumbersAndStrings.md
JAVA/lectures/Ch13_BasicIO.md
```

演習:

```text
JAVA/exercises/Exercise03.md
JAVA/exercises/Exercise04.md
JAVA/exercises/Exercise07.md
JAVA/exercises/Exercise08.md
JAVA/exercises/Exercise09.md
JAVA/exercises/Exercise10.md
```

既存まとめ:

```text
JAVA/study-guide-ex07-08.md
```

## 過去問と講義・演習の対応

| 過去問 | 主題 | 対応講義 | 対応演習 | 優先 |
|---|---|---|---|---|
| Q01 | overload | Ch04 | なし | A |
| Q02 | override / dynamic binding | Ch05, Ch08 | Exercise08 | A |
| Q03 | static field hiding | Ch04, Ch05, Ch08, Ch09 | Exercise03 | A |
| Q04 | `==` と `equals` | Ch06, Ch12 | Exercise06 | A |
| Q05 | primitive / reference passing | Ch04 | Exercise04 | B |
| Q06 | try/catch/finally | Ch11 | Ex11 実装ファイル | B |
| Q07 | static vs instance fields | Ch03, Ch04 | Exercise03 | A |
| Q08 | getter / setter | Ch04 | Exercise02, Exercise04 | B |
| Q09 | constructor chain | Ch05, Ch09 | Exercise05 | A |
| Q10 | dynamic binding | Ch08, Ch09 | Exercise08 | A |
| Q11 | String immutable / argument | Ch03, Ch12 | Ex12 実装ファイル | A |
| Q12 | polymorphic array | Ch08, Ch09 | Exercise08 | B |
| Q13 | 2D array and reference | Ch03, Ch04 | Exercise03, Exercise04 | A |
| Q14 | interface / implements | Ch07 | Exercise07 | A |
| Q15 | `super(...)` | Ch05 | Exercise05 | A |
| Q16 | `this.x = x` | Ch04 | Exercise04 | A |
| Q17 | interface variable | Ch07, Ch08 | Exercise07, Exercise08 | A |
| Q18 | downcast | Ch05, Ch08 | Exercise08 | B |
| Q19 | object array | Ch03 | Exercise04 | A |
| Q20 | abstract class | Ch06, Ch09 | Exercise06, Exercise10 | A |
| Q21 | Strategy pattern | Ch07, Ch08, Ch09 | Exercise09 | B |
| Q22 | IS-A / extends | Ch05, Ch06 | Exercise06 | B |
| Q23 | overload + cast | Ch07, Ch08 | Exercise07 | B |
| Q24 | exception hierarchy | Ch11 | Ex11 実装ファイル | B |

## 30点突破の最短セット

過去問は 4 点問題が多い。
8 問取れれば 32 点。

まずは次の8問型を取りに行く。

| 順 | 型 | 覚えること |
|---|---|---|
| 1 | Q01 overload | 引数の型で呼ばれるメソッドが決まる |
| 2 | Q02 override | 実体のクラスでメソッドが決まる |
| 3 | Q03 static | static は参照型・クラス名で決まる |
| 4 | Q04 equals | `==` は同一参照、`equals` は中身比較 |
| 5 | Q11 String | `String` を引数内で代入しても元は変わらない |
| 6 | Q13 配列 | 配列の中身変更は呼び出し元にも残る |
| 7 | Q15 super | 子コンストラクタで `super(b);` |
| 8 | Q16 this | フィールド代入は `this.x = x;` |

これに Q17, Q19, Q20 を足すとかなり安定する。

## 最初に覚える 10 ルール

### 1. overload はコンパイル時に決まる

```java
f(2.0, 3, 4.0)
```

なら、引数の形が合うメソッドを探す。

```java
double f(double a, int b, double c)
```

があればこれが呼ばれる。

### 2. override は実体で決まる

```java
A x = new B();
x.call();
```

`call()` が override されていれば、実体の `B` の `call()` が動く。

### 3. static は polymorphism しない

```java
Base b = new Sub();
System.out.print(b.FOO);
```

`FOO` が static field なら、変数の型 `Base` で決まる。

### 4. `==` は同じオブジェクトか

```java
s1 == s3
```

は、値が同じかではなく、同じインスタンスを指しているか。

### 5. `equals` は実装を見る

```java
boolean equals(St s) {
    return id == s.id;
}
```

なら、`id` が同じなら true。

### 6. primitive は値のコピー

```java
void f(int x) {
    x = 100;
}
```

メソッド内で変えても呼び出し元は変わらない。

### 7. object / array は参照のコピー

```java
void f(int[] a) {
    a[0] = 100;
}
```

中身を変えると呼び出し元にも残る。

ただし、

```java
a = new int[10];
```

のように参照そのものを差し替えても、呼び出し元の変数は変わらない。

### 8. `String` は immutable

```java
void update(String str) {
    str = "No";
}
```

これは引数 `str` が別の文字列を指すだけ。
呼び出し元の `str` は変わらない。

### 9. 子クラスのコンストラクタでは `super(...)`

```java
class B extends A {
    B(int b) {
        super(b);
    }
}
```

親のコンストラクタに値を渡す。

### 10. フィールドと引数が同名なら `this`

```java
void set(int x) {
    this.x = x;
}
```

`this.x` がフィールド、右の `x` が引数。

## 空欄補充で書けるようにする単語

過去問上部にもキーワード一覧がある。
まず次を確実に書けるようにする。

```java
interface
implements
extends
abstract
super(...)
this.x = x;
new Type[n]
new Type(...)
(Child) parent
try
catch
finally
throw
throws
```

## 講義別に見る優先度

### 最優先

| 講義 | 理由 |
|---|---|
| Ch03 Language Basics | 配列、static、String、基本演算 |
| Ch04 Classes and Objects | overload、this、値渡し、参照渡し |
| Ch05 Inheritance | extends、super、constructor chain、cast |
| Ch07 Interfaces | interface / implements が空欄補充で頻出 |
| Ch08 Polymorphism Part 1 | dynamic binding と static の違い |
| Ch11 Exceptions | Q24 の例外問題対策 |

### 余裕があれば

| 講義 | 理由 |
|---|---|
| Ch06 Inheritance Part 2 | equals、abstract class |
| Ch09 Polymorphism Part 2 | constructor order、abstract、Strategy |
| Ch12 Numbers and Strings | String / equals の補強 |
| Ch13 Basic I/O | 今回の過去問では薄いが finally と関係あり |
| Ch10 Packages | 過去問では今のところ優先度低め |

## 演習別に見る優先度

### 最優先

| 演習 | 過去問との対応 |
|---|---|
| Exercise03 | static field、配列参照、2次元配列 |
| Exercise04 | primitive / reference passing、this、getter/setter |
| Exercise07 | interface / implements |
| Exercise08 | polymorphism、interface 型、dynamic binding |

### 次点

| 演習 | 過去問との対応 |
|---|---|
| Exercise09 | Strategy pattern、interface 型フィールド |
| Exercise10 | abstract / template / package。package は優先度低 |
| Ex11 実装ファイル | exceptions |
| Ex12 実装ファイル | String / wrapper |
| Ex13 実装ファイル | I/O / array utility |

## 今日の進め方

### 1周目: 30点ライン

1. Q01〜Q04 を解く。
2. Q11, Q13, Q15, Q16 を解く。
3. Q17, Q19, Q20 を穴埋めで確認する。

### 2周目: 保険

1. Q07, Q09, Q10 を解く。
2. Q21 Strategy pattern を見る。
3. Q24 exception hierarchy を見る。

### 捨て気味でいいもの

時間がなければ、次は後回し。

1. Q05 の細かい参照渡し追跡
2. Q06 のぼやけている例外問題
3. Q22 の継承階層穴埋め
4. Q23 の overload + cast
5. package / I/O の細部

## 次にやること

まず Q01 から、答えを丸暗記ではなく「なぜその出力か」を追う。
その後、同じ型の小問を連続で解いて 30 点ラインを作る。
