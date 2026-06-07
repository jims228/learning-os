# Lecture 4 Theorem 4.1: 複素フーリエ級数

作成日: 2026-06-08

## 何の定理か

Theorem 4.1 は、フーリエ級数を三角関数ではなく、複素指数関数で書く公式である。

普通のフーリエ級数は、

\[
f(x)
=
a_0+
\sum_{n=1}^{\infty}
\{a_n\cos nx+b_n\sin nx\}
\]

のように書いた。

複素フーリエ級数では、これを

\[
e^{inx}
\]

を使って書く。

## 使う元ネタ: オイラーの公式

\[
e^{ix}=\cos x+i\sin x
\]

これより、

\[
\cos x=
\frac{e^{ix}+e^{-ix}}{2}
\]

\[
\sin x=
\frac{e^{ix}-e^{-ix}}{2i}
\]

である。

つまり、\(\cos\) と \(\sin\) は、実は \(e^{ix}\) と \(e^{-ix}\) を使って表せる。

## Theorem 4.1 の形

\(f(x)\) が \(2\pi\)-周期で、区分的になめらかな関数とする。

このとき、複素フーリエ級数は、

\[
f(x)
\sim
\sum_{n=-\infty}^{\infty}
c_n e^{inx}
\]

と書ける。

係数 \(c_n\) は、

\[
c_n=
\frac{1}{2\pi}
\int_{-\pi}^{\pi}
f(x)e^{-inx}\,dx
\qquad
(n=0,\pm1,\pm2,\ldots)
\]

である。

## ここで大事な記号

\[
c_n
\]

は複素フーリエ係数である。

\(n\) は正だけではなく、負も 0 も取る。

\[
n=0,\pm1,\pm2,\ldots
\]

なので、和も

\[
\sum_{n=-\infty}^{\infty}
\]

となる。

ここが普通のフーリエ級数と違う。

## なぜ \(e^{-inx}\) で係数を計算するのか

複素フーリエ級数では、

\[
e^{inx}
\]

たちを「波の部品」として使う。

係数を取り出すときは、対応する

\[
e^{-inx}
\]

をかけて積分する。

これは、三角関数の直交性と同じ考え方である。

ざっくり言えば、

\[
e^{inx}
\]

の成分を取り出すために、

\[
e^{-inx}
\]

をかける。

## 収束先

\(f(x)\) が \(x\) で連続なら、複素フーリエ級数は

\[
f(x)
\]

に収束する。

もし \(x\) でジャンプしているなら、左右の値の平均に収束する。

\[
\frac{f(x-)+f(x+)}{2}
\]

ここは普通のフーリエ級数と同じである。

## 普通の係数との関係

普通のフーリエ級数の係数を

\[
a_0,\quad a_n,\quad b_n
\]

とする。

複素フーリエ係数 \(c_n\) とは、次の関係がある。

\[
c_0=a_0
\]

\[
c_n=
\frac{1}{2}
(a_n-ib_n)
\qquad
(n>0)
\]

\[
c_{-n}=
\frac{1}{2}
(a_n+ib_n)
\qquad
(n>0)
\]

逆に、

\[
a_n=c_n+c_{-n}
\]

\[
b_n=i(c_n-c_{-n})
\]

である。

## 例: \(a_n,b_n\) から \(c_n\) に直す

もし普通のフーリエ級数で、

\[
a_0=0,\qquad a_n=0,\qquad b_n=\frac{1}{n}
\]

なら、

\[
c_0=0
\]

\[
c_n=
\frac{1}{2}
\left(0-i\frac{1}{n}\right)
=
-\frac{i}{2n}
\qquad
(n>0)
\]

\[
c_{-n}=
\frac{1}{2}
\left(0+i\frac{1}{n}\right)
=
\frac{i}{2n}
\qquad
(n>0)
\]

となる。

## 試験で出そうな形

### 1. 定理を書かせる

英語では、次のように聞かれる可能性がある。

```text
State the complex form of the Fourier series.
```

この場合は、

\[
f(x)
\sim
\sum_{n=-\infty}^{\infty}
c_n e^{inx}
\]

\[
c_n=
\frac{1}{2\pi}
\int_{-\pi}^{\pi}
f(x)e^{-inx}\,dx
\]

を書けばよい。

### 2. \(c_n\) を計算させる

英語では、

```text
Find the complex Fourier coefficients.
```

のように出る可能性がある。

この場合は、

\[
c_n=
\frac{1}{2\pi}
\int_{-\pi}^{\pi}
f(x)e^{-inx}\,dx
\]

に代入する。

### 3. 普通のフーリエ係数から変換させる

すでに \(a_n,b_n\) が分かっているときは、

\[
c_n=
\frac{1}{2}
(a_n-ib_n)
\]

\[
c_{-n}=
\frac{1}{2}
(a_n+ib_n)
\]

を使う。

## 英語キーワード

| 英語 | 日本語 |
|---|---|
| complex form | 複素数形式 |
| complex Fourier series | 複素フーリエ級数 |
| Fourier coefficient | フーリエ係数 |
| piecewise smooth | 区分的になめらか |
| continuous | 連続 |
| converges to | に収束する |
| otherwise | そうでなければ |
| complex conjugate | 複素共役 |

## 覚える形

最低限これを覚える。

\[
f(x)
\sim
\sum_{n=-\infty}^{\infty}
c_n e^{inx}
\]

\[
c_n=
\frac{1}{2\pi}
\int_{-\pi}^{\pi}
f(x)e^{-inx}\,dx
\]

普通の係数との関係は、

\[
c_n=
\frac{1}{2}(a_n-ib_n),
\qquad
c_{-n}=
\frac{1}{2}(a_n+ib_n)
\]

である。

## 口頭説明用

Theorem 4.1 は、フーリエ級数を複素指数関数 \(e^{inx}\) で表す公式である。
普通の \(\cos\) と \(\sin\) の級数を、オイラーの公式を使って

\[
\sum_{n=-\infty}^{\infty}c_n e^{inx}
\]

の形に直す。
係数は

\[
c_n=
\frac{1}{2\pi}
\int_{-\pi}^{\pi}f(x)e^{-inx}\,dx
\]

で求める。
連続な点では \(f(x)\) に収束し、不連続な点では左右の値の平均に収束する。
