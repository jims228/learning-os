# Chapter 3: Language Basics

## 範囲

- Variables
- Operators
- Expressions, Statements, and Blocks
- Control Flow Statements

## 変数

Javaの変数は「値が入ったカップ」のように考える。

```java
int x = 3;
int y = x;
```

この場合、`y` には `x` の値である `3` がコピーされる。

## 変数の種類

### Instance variables

オブジェクトごとに持つフィールド。non-static fields とも呼ぶ。

```java
class Bicycle {
    int cadence = 0;
    int speed = 0;
    int gear = 1;
}
```

### Class variables

クラス全体で1つだけ共有される変数。`static` fields とも呼ぶ。

```java
class Bicycle {
    static int numGears = 6;
}
```

### Local variables

メソッド内で一時的に使う変数。

```java
void method() {
    int localVariable = 0;
}
```

### Parameters

メソッドに渡される変数。

```java
void changeGear(int newValue) {
    gear = newValue;
}
```

## 命名規則

| 種類 | ルール | 例 |
|---|---|---|
| 変数 | lower camel case | `myWidth` |
| 定数 | 全大文字、単語は `_` 区切り | `MAX_WIDTH` |
| メソッド | 動詞、lower camel case | `runFast()` |
| クラス | 名詞、Upper camel case | `ImageSprite` |
| インターフェース | クラスと同様 | `Storing` |
| パッケージ | 小文字 | `edu.cmu.cs` |

## Primitive Data Types

Javaは strongly typed language。

- 変数は使用前に型と名前を宣言する必要がある。
- フィールドにはデフォルト値が入る。
- ローカル変数にはデフォルト値が入らない。
- 初期化していないローカル変数を使うとコンパイルエラー。

| 型 | 内容 | フィールドのデフォルト値 |
|---|---|---|
| `boolean` | `true` or `false` | `false` |
| `byte` | 8-bit signed integer | `0` |
| `char` | 16-bit Unicode character | `'\u0000'` |
| `short` | 16-bit signed integer | `0` |
| `int` | 32-bit signed integer | `0` |
| `long` | 64-bit signed integer | `0L` |
| `float` | 32-bit floating point | `0.0F` |
| `double` | 64-bit floating point | `0.0D` |

## String

`String` は `java.lang.String` で定義される文字列クラス。

```java
String s1 = new String("this is a String");
String s2 = "this is another String";
String s3 = null;
```

`String` は immutable。作成後に中身は変更できない。

## Literals

ソースコード上に直接書かれた固定値。

```java
boolean result = true;
char capitalC = 'C';
int decVal = 26;
int octVal = 032;
int hexVal = 0x1a;
double d1 = 123.4;
double d2 = 1.234e2;
float fl = 123.4f;
```

Escape sequences:

| 表記 | 意味 |
|---|---|
| `\b` | backspace |
| `\t` | tab |
| `\n` | line feed |
| `\f` | form feed |
| `\r` | carriage return |
| `\"` | double quote |
| `\'` | single quote |
| `\\` | backslash |

`null` は primitive 以外の参照型に代入できる。

```java
String s = null;
// byte b = null; // error
```

## Arrays

配列は同じ型の値を固定個数だけ持つコンテナ。

```java
int[] a1 = new int[5];
int[] a2 = {1, 2, 3, 4, 5};
int len = a1.length;
```

注意:

- index は `0` から `length - 1`
- `length` は変更できない
- `a1[5]` や `a2[-1]` は範囲外エラー

### 配列変数は参照を持つ

```java
int[] a = {1, 2, 3, 4, 5};
int[] b = {15, 16, 17, 18, 19};
b = a;
```

`b = a;` は配列の中身をコピーするのではなく、`b` が `a` と同じ配列を指すようになる。

中身をコピーするには `System.arraycopy` を使える。

```java
System.arraycopy(copyFrom, 2, copyTo, 0, 7);
```

### Arrays of Objects

```java
String[] a1 = new String[5];
String[] a2 = {"1", "2"};
String[] a3 = {new String("1"), "2"};
```

配列の要素は同じ型でなければならない。

### Multidimensional Arrays

Javaの多次元配列は「配列の配列」。

```java
String[][] names = {
    {"Mr. ", "Mrs. ", "Ms. "},
    {"Smith", "Jones"}
};
```

行ごとに長さが違う ragged arrays も可能。

## Operators

優先順位はおおむね次の順。

1. postfix: `expr++`, `expr--`
2. unary: `++expr`, `--expr`, `+`, `-`, `~`, `!`
3. multiplicative: `*`, `/`, `%`
4. additive: `+`, `-`
5. shift: `<<`, `>>`, `>>>`
6. relational: `<`, `>`, `<=`, `>=`, `instanceof`
7. equality: `==`, `!=`
8. bitwise AND: `&`
9. bitwise XOR: `^`
10. bitwise OR: `|`
11. logical AND: `&&`
12. logical OR: `||`
13. ternary: `? :`
14. assignment: `=`, `+=`, `-=`, etc.

## Assignment

```java
int x = 3;
int y = x;
boolean b = true;
float speed = 120.0f;
```

配列の場合、代入は参照のコピー。

## Arithmetic Operators

| 演算子 | 意味 |
|---|---|
| `+` | addition / string concatenation |
| `-` | subtraction |
| `*` | multiplication |
| `/` | division |
| `%` | remainder |

## Unary Operators

```java
int result = -1;
result++;
--result;
boolean b = true;
b = !b;
```

## Equality and Relational Operators

```java
==  !=  >  >=  <  <=
```

## Conditional Operators

```java
&&  ||  ?:
```

```java
boolean b = 1 > 0 ? true : false;
```

## instanceof

オブジェクトが指定クラスまたはそのサブクラス、またはインターフェース実装クラスかを調べる。

```java
String str = new String("123");
if (str instanceof String) {
    System.out.println("The type of str is String");
}
```

## Bitwise and Bit Shift Operators

| 演算子 | 意味 |
|---|---|
| `&` | bitwise AND |
| `^` | bitwise XOR |
| `|` | bitwise OR |
| `~` | complement |
| `<<` | left shift |
| `>>` | signed right shift |
| `>>>` | unsigned right shift |

## Expressions, Statements, Blocks

Expression:

```java
int c = a * b + 3;
```

Statement:

```java
aValue = 4;
Car c = new Car();
double db = 4.;
```

Block:

```java
if (condition) {
    System.out.println("Condition is true.");
} else {
    System.out.println("Condition is false.");
}
```

## Control Flow Statements

| 種類 | 文 |
|---|---|
| decision making | `if`, `if-else`, `switch` |
| looping | `for`, `while`, `do-while` |
| branching | `break`, `continue`, `return` |

## if / if-else

```java
if (a < 5) {
    a++;
} else {
    a--;
}
```

## switch

`switch` は `byte`, `short`, `char`, `int`、wrapper、enum、`String` などで使える。

```java
switch (month) {
    case 1:
        name = "january";
        break;
    case 2:
        name = "february";
        break;
    default:
        name = "";
        break;
}
```

`break` がないと fall-through する。

## while

```java
while (condition) {
    // statements
}
```

条件が最初から false なら一度も実行されない。

## do-while

```java
do {
    // statements
} while (condition);
```

少なくとも1回は実行される。

## for

```java
for (int i = 0; i < 10; ++i) {
    System.out.println(i);
}
```

無限ループ:

```java
for (;;) {
}
```

## break

- loop または `switch` を終了する。
- labeled break は外側の文を終了する。

## continue

- 現在のループ反復をスキップする。
- labeled continue は指定した外側ループの次の反復へ進む。

## return

現在のメソッドを終了し、呼び出し元へ戻る。

```java
return;
return 5;
```

## 試験で出そうな注意点

- フィールドはデフォルト値あり、ローカル変数はデフォルト値なし。
- `String` は参照型なので `null` を代入できる。
- primitive には `null` を代入できない。
- 配列代入は中身コピーではなく参照コピー。
- `array.length` は変更不可。
- `switch` は `break` がないと fall-through する。
- `while` は0回実行の可能性、`do-while` は最低1回実行。
- `return` はメソッドを終了する。
