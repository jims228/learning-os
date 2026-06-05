# フーリエ解析 再開メモ

作成日: 2026-06-05

## 目的

期末で点を取るため、深い理論理解よりも、レビュー資料に載っている Example / Theorem を説明できる状態にする。

## 資料の管理場所

元資料:

- `C:\Users\shing\Downloads\フーリエダウンロード資料`

Ubuntu 22.04 側の管理場所:

- `/home/jimjace/learning-os/Math/Fourier`

repo 内の主な整理:

- `lectures/`: Lecture 1〜10 のPDF
- `references/`: `MA05_Review.pdf`、フーリエ変換表、ラプラス変換表
- `assignments/downloaded/`: Assignment 1〜10 のZIP
- `exercises/`: 手元にある提出・解答用 TeX
- `exam-prep/`: 試験対策の整理メモ

## 前回まで

Lecture 8 の DFT から開始。

- Example 8.2: `{0, 1, 0, 0}` の4点DFTを確認済み。
- Example 8.3: `{1, 2-i, -i, -1+2i}` の4点DFTを確認済み。

## 次にやること

1. Lecture 8 Example 8.4 を解く。
2. Lecture 9 Example 9.1, Example 9.2 で FFT を確認する。
3. Assignment 8, 9 の4点DFT/FFT問題を解き直す。
4. Lecture 7, 10 のラプラス変換に進む。
5. Lecture 1〜4 のフーリエ級数は、係数計算と直交性を中心に拾う。
6. Lecture 5〜6 のフーリエ変換・畳み込みは、公式表を使う典型問題だけ優先する。

## 得点源の優先順

1. DFT / FFT
2. ラプラス変換、単位ステップ、時間シフト
3. 複素形フーリエ級数
4. フーリエ級数の係数計算
5. 畳み込み
6. フーリエ変換

## 方針

1問ずつ、公式を1つに絞って、計算過程を口頭説明できる形で進める。途中で間違えた場合はすぐ答えを出さず、どこでずれたかをヒントで確認する。
