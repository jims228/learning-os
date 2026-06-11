# FU03 離散系論 Quick Start

作成: 2026-06-08

## まず何をするか

Lesson 01は、次の順番で勉強する。

1. 集合記号を読めるようにする。
2. 真理値表を書けるようにする。
3. 数学的帰納法の型を暗記する。
4. 帰納法の基本問題を2問解く。

## 30分でやるなら

| 時間 | 内容 |
|---:|---|
| 10分 | 集合記号の表を読む |
| 10分 | 真理値表 not / and / or / implication を書く |
| 10分 | 帰納法の型を声に出す |

## 90分でやるなら

| 時間 | 内容 |
|---:|---|
| 20分 | Lesson 01ノートを読む |
| 20分 | 集合の演算問題を1つ解く |
| 20分 | 真理値表問題を1つ解く |
| 30分 | 帰納法の基本問題を1つ解く |

## 試験で点になる場所

| 分野 | 出やすい形 |
|---|---|
| 集合 | A ∪ B, A ∩ B, A \ B, A ⊕ Bを図や式で答える |
| 論理 | 真理値表を書く |
| 論理 | p → qを¬p ∨ qに直す |
| 量化子 | ∀, ∃の否定を書く |
| 帰納法 | basis step / inductive stepを書いて証明する |

## 帰納法のテンプレ

```text
We prove the statement by mathematical induction.

Basis step:
For n = 1, ...
Therefore, P(1) is true.

Inductive step:
Assume that P(k) is true for some k in N.
We prove P(k+1).
...
Therefore, P(k+1) is true.

By mathematical induction, P(n) is true for all n in N.
```

## 注意

英語授業なので、用語は英語のまま覚える。

- set
- subset
- union
- intersection
- proposition
- predicate
- truth table
- implication
- quantifier
- induction
