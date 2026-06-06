# 2026-06-06〜06-07 JAVA + フーリエ 2日間スプリント

作成日: 2026-06-06
試験日: 2026-06-08

## 結論

満点狙いではなく、単位を取りつつ得点源を固めるなら2日で間に合う。

ただし、全部をきれいに理解するのではなく、次の型に絞る。

- JAVA: interface / polymorphism / abstract class / exception / 典型コードの読み書き
- フーリエ: DFT / FFT / ラプラス変換 / 単位ステップ / 時間シフト

## 優先順位

### JAVA

1. Ex07: Interface
2. Ex08: Polymorphism Part 1
3. Ch09: Polymorphism Part 2
4. Ch11: Exceptions
5. 余力: Ch10 Packages, Ch12 Numbers and Strings, Ch13 Basic IO

### フーリエ

1. Lecture 8: DFT / IDFT
2. Lecture 9: FFT
3. Lecture 7, 10: ラプラス変換、単位ステップ、時間シフト
4. Lecture 1〜4: フーリエ級数の係数計算と直交性
5. Lecture 5〜6: フーリエ変換、畳み込みは公式表ベース

## 今日 2026-06-06

### 前半: JAVA

- `JAVA/study-guide-ex07-08.md` を使って Ex07, Ex08 を確認する。
- interface / implements / dynamic binding / comparator / iterator を説明できるようにする。
- Stack, Queue, SimpleList の典型コードを白紙で書けるようにする。

### 後半: フーリエ

- Lecture 8 Example 8.4 まで確認済み。
- Lecture 9 Example 9.1, 9.2 を解く。
- Assignment 8, 9 のDFT/FFTを1問ずつ解き直す。

## 明日 2026-06-07

### 前半: フーリエ

- Lecture 7, 10 のラプラス変換を固める。
- 単位ステップ関数と時間シフトを重点的に練習する。
- フーリエ級数・フーリエ変換は、レビュー資料に載っている Example / Theorem だけ拾う。

### 後半: JAVA

- Ch09 Polymorphism Part 2 を復習する。
- Ch11 Exceptions を復習する。
- 直前5分リストを作り、暗記する。

## 捨てるもの

時間が足りない場合は、次は深追いしない。

- フーリエの証明の細部
- フーリエ変換・畳み込みの難しい理論
- JAVAの細かいライブラリ仕様
- きれいな設計の一般論

## 合格ラインの作戦

「公式を見て典型問題に代入できる」「JAVAコードの出力を追える」「interface / polymorphism / exception を言葉で説明できる」状態を目標にする。
