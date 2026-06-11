# Chapter 12 (講義12): Numbers and Strings

## Number クラス（ラッパークラス）
- プリミティブ型ごとにオブジェクト版（ラッパークラス）がある: `int`→`Integer`, `double`→`Double`, `long`→`Long` など
- すべて `java.lang.Number` のサブクラス（Byte, Short, Integer, Long, Float, Double）
- ラッパーを使う3つの理由:
  1. オブジェクトを期待するメソッドの引数として渡す（コレクションで数値を扱う時など）
  2. クラス定数（`Integer.MIN_VALUE`, `Integer.MAX_VALUE`）を使う
  3. 型変換・進数変換（10進/8進/16進/2進）のクラスメソッドを使う

### オートボクシング / アンボクシング
- **Boxing**: プリミティブ → オブジェクト（オブジェクトが必要な場面で自動変換）
- **Unboxing**: オブジェクト → プリミティブ（プリミティブが必要な場面で自動変換）
```java
Integer x = 12;   // boxing
Integer y = 15;
System.out.println(x + y);  // unboxing して 27
```

### Number 共通メソッド
- `intValue()`, `doubleValue()`, `longValue()` ... 各プリミティブへ変換
- `compareTo(...)`: 比較（>0, 0, <0 を返す）
- `equals(Object)`: 同じ型・同じ値なら true

### Integer の変換メソッド（静的）
- `Integer.parseInt(String)` → int（10進）
- `Integer.parseInt(String, int radix)` → 基数指定（2,8,10,16）
- `Integer.valueOf(...)` → Integer オブジェクト
- `Integer.toString(int)` / `Integer.decode(String)`

## 数値出力のフォーマット
### printf / format
```java
System.out.format("The value is %f, int is %d, str is %s", f, i, s);
```
- 書式指定子 = `%` + コンバータ

### 主なコンバータ / フラグ
| 指定 | 意味 |
|---|---|
| `%d` | 10進整数 |
| `%f` | 浮動小数点 |
| `%s` | 文字列 |
| `%n` | 改行（`\n` より `%n` を使う） |
| `%08d` | 幅8、先頭ゼロ埋め |
| `%+d` | 符号を常に付ける |
| `%,d` | 桁区切り（locale依存） |
| `%-10.3f` | 幅10、左寄せ、小数点以下3桁 |
| `%.3f` | 小数点以下3桁 |
| `%tB %te, %tY` | 日付（月名・日・年） |

### DecimalFormat (java.text)
- 先頭/末尾のゼロ、接頭辞/接尾辞、桁区切り、小数点を細かく制御
```java
DecimalFormat f = new DecimalFormat("###,###.###");
f.format(123456.789);  // "123,456.789"
```
- `0` は必須桁（ゼロ埋め）、`#` は任意桁

## Math クラス (java.lang.Math)
- 定数: `Math.E`, `Math.PI`
- すべて静的メソッド（`Math.sqrt(x)` のようにクラス経由で呼ぶ）

| メソッド | 説明 |
|---|---|
| `abs(x)` | 絶対値 |
| `ceil(d)` | 切り上げ（double で返す） |
| `floor(d)` | 切り捨て（double で返す） |
| `rint(d)` | 最も近い整数（double） |
| `round(d)` | 最も近い long/int |
| `min(a,b)` / `max(a,b)` | 小さい方 / 大きい方 |
| `exp` / `log` / `pow(base,exp)` / `sqrt` | 指数・対数・累乗・平方根 |
| `sin/cos/tan`, `asin/acos/atan`, `atan2(y,x)` | 三角関数 |
| `toDegrees` / `toRadians` | 度⇔ラジアン変換 |
| `random()` | 0.0以上1.0未満の擬似乱数 |

```java
int n = (int)(Math.random() * 10);  // 0〜9 の整数
```

## char と Character
```java
char ch = 'a';
char[] arr = {'a', 'b', 'c'};
Character obj = 'a';  // autoboxing
```
- Character の便利メソッド: `isLetter`, `isDigit`, `isWhitespace`, `isUpperCase`, `isLowerCase`, `toUpperCase`, `toLowerCase`, `toString`

### エスケープシーケンス
`\t` タブ / `\b` バックスペース / `\n` 改行 / `\r` 復帰 / `\f` 改ページ / `\'` `\"` `\\` 引用符・バックスラッシュ

## String
- 文字の並び。**immutable（不変）** — 一度作ると変更不可
- 「変更するように見える」メソッドは実際には新しい String を返している

### 生成と長さ
```java
String s = "Hello world!";
String s2 = new String(charArray);
int len = s.length();   // アクセサメソッド
```

### 連結
- `+` 演算子、または `string1.concat(string2)`

### フォーマット文字列の生成
- `String.format(...)` で書式付き文字列を生成して再利用できる（printf は一度きりの出力）

### 数値 ⇔ 文字列
- 文字列→数値: `Float.parseFloat(s)`, `Integer.parseInt(s)`, `Float.valueOf(s).floatValue()`
- 数値→文字列:
  - `"" + i`（空文字との連結）
  - `String.valueOf(i)`
  - `Integer.toString(i)`, `Double.toString(d)`

### 文字・部分文字列の取得
- `charAt(index)`: 指定位置の文字
- `substring(begin, end)`: begin から end-1 まで（半開区間）
- `substring(begin)`: begin から末尾まで

### 操作系メソッド
- `split(regex)`, `trim()`, `toLowerCase()`, `toUpperCase()`, `subSequence(b,e)`
- `replace(old, new)`, `replaceAll(regex, rep)`, `replaceFirst(regex, rep)`

### 検索メソッド
- `indexOf(ch/str)`, `lastIndexOf(ch/str)`（fromIndex 指定版あり）
- `contains(CharSequence)`

### 比較メソッド
- `equals(Object)` / `equalsIgnoreCase(String)`: 内容が同じか（`==` は参照比較なので使わない）
- `compareTo(String)` / `compareToIgnoreCase(String)`: 辞書順比較（>0, 0, <0）
- `startsWith(prefix)` / `endsWith(suffix)`
- `regionMatches(...)`: 指定領域同士の一致判定
- `matches(regex)`

## StringBuilder
- String と違い **可変**（modifiable）。内部は可変長配列
- `length()`: 文字数 / `capacity()`: 確保済みの領域（length 以上、必要に応じ自動拡張）
- コンストラクタ: `StringBuilder()`（初期容量16）, `StringBuilder(String)`, `StringBuilder(int capacity)`

| メソッド | 説明 |
|---|---|
| `append(...)` | 末尾に追加（各型を文字列化して追加） |
| `insert(offset, ...)` | 指定位置に挿入 |
| `delete(start, end)` / `deleteCharAt(i)` | 削除 |
| `replace(start, end, s)` / `setCharAt(i, c)` | 置換 |
| `reverse()` | 反転 |
| `toString()` | String に変換 |
| `setLength(n)` / `ensureCapacity(n)` | 長さ・容量の調整 |

```java
StringBuilder sb = new StringBuilder("Dot saw I was Tod");
sb.reverse();
System.out.println(sb);  // doT saw I was toD
```
