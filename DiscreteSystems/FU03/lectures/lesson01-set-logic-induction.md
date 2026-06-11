# Lesson 01: Set Theory, Logic and Induction

作成: 2026-06-08  
元資料: `DiscreteSystems/FU03/lectures/Lesson 01.pdf`

## 今日の範囲

Lesson 01は次の3つ。

1. Elementary set theory
2. Propositional logic
3. Mathematical induction

日本語で言うと、

1. 集合
2. 命題論理
3. 数学的帰納法

## 1. 集合とは

集合とは、ものの集まり。

集合の中の1つ1つを element という。

| 記号 | 読み方 | 意味 |
|---|---|---|
| a ∈ S | a is in S | aはSの要素 |
| b ∉ S | b is not in S | bはSの要素ではない |

集合の書き方は2通り。

### 要素を列挙する

```text
S = {1, 3, 5, 7, 9}
```

### 条件で書く

```text
S = {x | x is an odd integer, 0 <= x <= 10}
```

これは「0以上10以下の奇数全体」という意味。

## 集合で大事な注意

集合では順番と重複は無視する。

だから次は全部同じ集合。

```text
{1, 2, 3}
{2, 3, 1}
{1, 2, 2, 3}
{3, 2, 1, 3, 2, 1}
```

## 有限集合と無限集合

有限個の要素を持つ集合を finite set という。

集合Sの要素数は次のように書く。

```text
#S
|S|
```

例:

```text
|{1, 2, 3, 4, 5}| = 5
|{2, 2, 2, 2, 1, 4}| = 3
```

2つ目が3になるのは、重複を数えないから。

空集合:

```text
∅ = {}
|∅| = 0
```

代表的な無限集合:

| 記号 | 意味 |
|---|---|
| N | 自然数 |
| Z | 整数 |
| Q | 有理数 |
| R | 実数 |

関係:

```text
N ⊆ Z ⊆ Q ⊆ R
```

## 部分集合

Aのすべての要素がBにも入っているとき、

```text
A ⊆ B
```

と書く。

意味:

```text
a ∈ A ならば a ∈ B
```

重要:

```text
A = B  ⇔  A ⊆ B かつ B ⊆ A
```

## 集合の演算

| 記号 | 名前 | 意味 |
|---|---|---|
| A ∪ B | union | AまたはBに入っている |
| A ∩ B | intersection | AにもBにも入っている |
| A \ B | difference | Aに入っていてBに入っていない |
| A ⊕ B | symmetric difference | AかBの片方だけに入っている |
| Ā | complement | Aに入っていない |

universal set U は、今考えている全体集合。

## 集合の法則

最低限覚えるもの。

### DeMorgan's laws

```text
A ∪ B の補集合 = Aの補集合 ∩ Bの補集合
A ∩ B の補集合 = Aの補集合 ∪ Bの補集合
```

直感:

「AまたはBではない」は「AでもないしBでもない」。

「AかつBではない」は「Aではない、またはBではない」。

### duality

集合の式では、次を入れ替えても対応する正しい式が出る。

```text
∪ ↔ ∩
∅ ↔ U
```

## partition, product, power set

### partition

集合Sを、重ならない空でない部分集合に分けたもの。

条件:

```text
S = A1 ∪ A2 ∪ A3 ∪ ...
Ai ∩ Aj = ∅  (i ≠ j)
```

### set product

A × B は、a ∈ A, b ∈ B から作るペア全体。

例:

```text
A = {a, b, c}
B = {a, d}

A × B = {
  (a, a), (a, d),
  (b, a), (b, d),
  (c, a), (c, d)
}
```

要素数:

```text
|A × B| = |A| |B|
```

### power set

P(S) はSのすべての部分集合の集合。

例:

```text
S = {1, 2, 3}

P(S) = {
  ∅,
  {1}, {2}, {3},
  {1, 2}, {1, 3}, {2, 3},
  {1, 2, 3}
}
```

要素数:

```text
|S| = n なら |P(S)| = 2^n
```

## 2. 命題と述語

### proposition

propositionは、trueかfalseが決まる文。

例:

```text
There are 7 days in a week.  true
London is the capital of France.  false
```

### predicate

predicateは、変数を含む文。

値を入れるとtrue/falseが決まる。

例:

```text
p(x): x > 3

p(5) = true
p(2) = false
```

## 論理演算

| 記号 | 名前 | 読み方 |
|---|---|---|
| ¬p | negation | not p |
| p ∧ q | conjunction | p and q |
| p ∨ q | disjunction | p or q |
| p → q | implication | if p then q |
| p ↔ q | coimplication | p if and only if q |

## 真理値表

### not

| p | ¬p |
|---|---|
| T | F |
| F | T |

### and / or

| p | q | p ∧ q | p ∨ q |
|---|---|---|---|
| T | T | T | T |
| T | F | F | T |
| F | T | F | T |
| F | F | F | F |

### implication

| p | q | p → q |
|---|---|---|
| T | T | T |
| T | F | F |
| F | T | T |
| F | F | T |

重要:

```text
p → q  ≡  ¬p ∨ q
```

## tautology and contradiction

| 名前 | 意味 |
|---|---|
| tautology | 必ずtrueになる命題 |
| contradiction | 必ずfalseになる命題 |

例:

```text
p ∨ ¬p  は tautology
p ∧ ¬p  は contradiction
```

## quantifiers

| 記号 | 名前 | 意味 |
|---|---|---|
| ∃x | existential | あるxが存在する |
| ∀x | universal | すべてのxについて |

例:

```text
∃x ∈ N, x > 10
```

これはtrue。例えばx = 11。

```text
∀x ∈ N, x > 10
```

これはfalse。例えばx = 1。

量化子のDeMorgan:

```text
¬∃x, p(x)  ≡  ∀x, ¬p(x)
¬∀x, p(x)  ≡  ∃x, ¬p(x)
```

## 3. 数学的帰納法

数学的帰納法は、「すべての自然数nについて成り立つ」ことを証明する型。

基本形:

```text
P(n)をすべてのn ∈ Nで証明したい。

1. Basis step:
   P(1)を直接証明する。

2. Inductive step:
   P(k)が成り立つと仮定する。
   その仮定を使ってP(k+1)を証明する。

これでP(n)はすべてのn ∈ Nで成り立つ。
```

例:

```text
2^0 + 2^1 + 2^2 + ... + 2^(n-1) = 2^n - 1
```

### Basis step

n = 1 のとき、

```text
左辺 = 2^0 = 1
右辺 = 2^1 - 1 = 1
```

だから成り立つ。

### Inductive step

n = kで成り立つと仮定する。

```text
2^0 + 2^1 + ... + 2^(k-1) = 2^k - 1
```

n = k + 1を示す。

```text
2^0 + 2^1 + ... + 2^(k-1) + 2^k
= (2^k - 1) + 2^k
= 2 * 2^k - 1
= 2^(k+1) - 1
```

よってn = k + 1でも成り立つ。

したがって、すべてのn ∈ Nで成り立つ。

## Lesson 01の演習候補

資料の最後に、数学的帰納法で証明する問題がある。

優先して解けるようにするもの:

1. 1 + 3 + 5 + ... + (2n - 1) = n^2
2. 1 + 2 + 3 + ... + n = n(n+1)/2
3. 1^2 + 2^2 + ... + n^2 = n(n+1)(2n+1)/6
4. n^2 + n is an even number
5. n^3 + 2n is a multiple of 3
6. |S| = n なら |P(S)| = 2^n

最後のright triomino問題は発展寄り。余裕がなければ後回し。

## 最初に覚えるべきこと

このLessonで最低限言えるようにする。

```text
A set is a collection of elements.
A proposition is a statement that is either true or false.
A predicate becomes a proposition when variables are assigned.
Mathematical induction has a basis step and an inductive step.
```

日本語:

```text
集合は要素の集まり。
命題は真か偽が決まる文。
述語は変数を入れると命題になる文。
数学的帰納法は、最初の1個を示して、kからk+1へ進めることを示す証明法。
```
