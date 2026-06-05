# フーリエ解析 試験対策 Quick Start

作成日: 2026-06-01
更新日: 2026-06-05

## 現状

手元にある確実な資料:

- `Math/Fourier/lectures/MA05_Lecture_1_Slides.pdf` 〜 `MA05_Lecture_10_Slides.pdf`: 講義スライド一式
- `Math/Fourier/references/MA05_Review.pdf`: 期末レビュー資料
- `Math/Fourier/references/Table_of_Fourier_Transforms.pdf`: フーリエ変換表
- `Math/Fourier/references/Table_of_Laplace_Transforms.pdf`: ラプラス変換表
- `Math/Fourier/assignments/downloaded/`: Assignment 1〜10 のZIP
- `Math/Fourier/exercises/A9_FourierAssignment.tex`: DFT / FFT
- `Math/Fourier/exercises/A10_FourierAssignment.tex`: ラプラス変換、単位ステップ関数

まずは `MA05_Review.pdf` に載っている Example / Theorem を、点が取りやすい順に進める。前回は Lecture 8 の Example 8.2 と Example 8.3 を確認済み。

次に進むなら、Lecture 8 の Example 8.4 から再開し、そのあと Lecture 9 の Example 9.1, Example 9.2 で FFT を固める。

## 再開時の目標

1. DFTの定義を使って4点DFTを計算できる。
2. FFTの偶数番目・奇数番目への分割を説明できる。
3. ラプラス変換で単位ステップ関数 `u(t-a)` を扱える。
4. 逆ラプラスで `e^{-as}` が出た時に時間シフトへ戻せる。

## 最重要公式

### DFT

長さ `N` の列 `f(0), ..., f(N-1)` に対して、

```math
F(k)=\sum_{n=0}^{N-1} f(n)W_N^{nk},
\qquad
W_N=e^{-2\pi i/N}
```

4点DFTでは、

```math
W_4=e^{-i\pi/2}=-i,
\quad
W_4^0=1,\quad
W_4^1=-i,\quad
W_4^2=-1,\quad
W_4^3=i
```

### 4点FFT

偶数番目と奇数番目に分ける。

```math
A(k)=f(0)+f(2)W_2^k,\qquad
B(k)=f(1)+f(3)W_2^k
```

合成:

```math
F(k)=A(k)+W_4^kB(k),
\qquad
F(k+2)=A(k)-W_4^kB(k)
\quad (k=0,1)
```

### ラプラス変換

基本:

```math
\mathcal{L}\{1\}=\frac{1}{s},
\qquad
\mathcal{L}\{t\}=\frac{1}{s^2},
\qquad
\mathcal{L}\{e^{at}\}=\frac{1}{s-a}
```

単位ステップ:

```math
\mathcal{L}\{u(t-a)\}=\frac{e^{-as}}{s}
```

第2移動定理:

```math
\mathcal{L}\{u(t-a)g(t-a)\}=e^{-as}G(s),
\qquad
G(s)=\mathcal{L}\{g(t)\}
```

逆変換:

```math
\mathcal{L}^{-1}\{e^{-as}F(s)\}=u(t-a)f(t-a)
```

## 例題1: 4点DFT

`{0, 2, 3, 6}` のDFTを求める。

```math
F(k)=\sum_{n=0}^{3} f(n)W_4^{nk}
```

`W_4=-i` より、

```math
F(0)=0+2+3+6=11
```

```math
F(1)=0+2(-i)+3(-1)+6(i)=-3+4i
```

```math
F(2)=0+2(-1)+3(1)+6(-1)=-5
```

```math
F(3)=0+2(i)+3(-1)+6(-i)=-3-4i
```

答え:

```math
\{11,\ -3+4i,\ -5,\ -3-4i\}
```

実数列なので `F(3)=conj(F(1))` になる。

## 例題2: ラプラス変換

```math
f(t)=e^{2t}u(t-2)
```

第2移動定理を使うため、`t-2` の形に直す。

```math
e^{2t}=e^{2(t-2)+4}=e^4e^{2(t-2)}
```

したがって、

```math
f(t)=e^4e^{2(t-2)}u(t-2)
```

`g(t)=e^{2t}` とすると `G(s)=1/(s-2)` なので、

```math
\mathcal{L}\{e^{2t}u(t-2)\}
=e^4e^{-2s}\frac{1}{s-2}
=\frac{e^{4-2s}}{s-2}
```

## つまずきやすい点

- `u(t-a)` は `t=a` から関数が始まるという意味。
- `e^{-as}` がラプラス領域にあると、時間領域では `a` だけ右にずれる。
- `u(t-a)g(t)` と `u(t-a)g(t-a)` は違う。第2移動定理を使うには `g(t-a)` の形に直す。
- DFTでは `W_N^{nk}` の指数 `nk` を雑に扱うと符号を間違える。
- 4点DFTでは `W_4=-i` を固定して、べき乗表を先に書くとミスが減る。

## 基礎確認問題

### 問1

`{1, 2, 0, 1}` の4点DFTを求めよ。

### 問2

`{4, 0, 2, 0}` の4点DFTをFFTの分割で求めよ。

### 問3

次をラプラス変換せよ。

```math
f(t)=u(t-3)
```

### 問4

次をラプラス変換せよ。

```math
f(t)=e^{t}u(t-2)
```

### 問5

次を逆ラプラス変換せよ。

```math
\mathcal{L}^{-1}\left\{\frac{e^{-3s}}{s^2}\right\}
```
