# Lecture 2 Theorem 2.2: 任意周期のフーリエ級数

作成日: 2026-06-08

## 何の定理か

これまでは、主に \(2\pi\)-周期の関数を扱っていた。

しかし実際には、周期が \(2\pi\) ではない関数も出てくる。

Theorem 2.2 は、

\[
2p\text{-周期}
\]

の関数に対するフーリエ級数の公式である。

## 一番大事な形

\(f(x)\) が \(2p\)-周期の関数のとき、フーリエ級数は

\[
f(x)
\sim
a_0
+
\sum_{n=1}^{\infty}
\left(
a_n\cos\frac{n\pi x}{p}
+
b_n\sin\frac{n\pi x}{p}
\right)
\]

と書く。

ここで重要なのは、

\[
\cos nx,\quad \sin nx
\]

ではなく、

\[
\cos\frac{n\pi x}{p},
\qquad
\sin\frac{n\pi x}{p}
\]

になることである。

## 係数の公式

\[
a_0=
\frac{1}{2p}
\int_{-p}^{p}
f(x)\,dx
\]

\[
a_n=
\frac{1}{p}
\int_{-p}^{p}
f(x)
\cos\frac{n\pi x}{p}
\,dx
\]

\[
b_n=
\frac{1}{p}
\int_{-p}^{p}
f(x)
\sin\frac{n\pi x}{p}
\,dx
\]

## 前の公式との違い

前に使っていた \(2\pi\)-周期の公式は、

\[
f(x)
=
a_0+
\sum_{n=1}^{\infty}
(a_n\cos nx+b_n\sin nx)
\]

だった。

これは、今回の公式で

\[
p=\pi
\]

とした場合である。

実際に、

\[
\cos\frac{n\pi x}{p}
\]

に \(p=\pi\) を入れると、

\[
\cos\frac{n\pi x}{\pi}
=
\cos nx
\]

になる。

同じように、

\[
\sin\frac{n\pi x}{\pi}
=
\sin nx
\]

となる。

## なぜ \(\frac{n\pi x}{p}\) になるのか

三角関数の基本周期を思い出す。

\[
\cos \theta
\]

は、\(\theta\) が \(2\pi\) 増えると元に戻る。

つまり、

\[
\theta=\frac{n\pi x}{p}
\]

と置くと、\(x\) が \(2p\) 増えたとき、

\[
\frac{n\pi (x+2p)}{p}
=
\frac{n\pi x}{p}
+
2n\pi
\]

となる。

\[
2n\pi
\]

は三角関数の周期なので、元に戻る。

だから、

\[
\cos\frac{n\pi x}{p}
\]

や

\[
\sin\frac{n\pi x}{p}
\]

は \(2p\)-周期の波になる。

## 積分区間について

基本形は、

\[
\int_{-p}^{p}
\]

である。

ただし、関数が \(2p\)-周期なら、長さが \(2p\) の区間ならどこで積分してもよい。

たとえば、

\[
\int_{-p}^{p}
\]

の代わりに、

\[
\int_0^{2p}
\]

を使ってもよい。

試験では、関数の定義が

\[
0<x<2p
\]

で与えられていたら、\([0,2p]\) で積分する方が楽なことが多い。

## 収束先

関数 \(f(x)\) が \(x\) で連続なら、フーリエ級数は

\[
f(x)
\]

に収束する。

もし \(x\) でジャンプしているなら、左右の値の平均に収束する。

\[
\frac{f(x-)+f(x+)}{2}
\]

ここで、

\[
f(x-)
\]

は左から近づいた値、

\[
f(x+)
\]

は右から近づいた値である。

## 試験での使い方

周期が \(2p\) と言われたら、まず

\[
p=\frac{\text{周期}}{2}
\]

を決める。

たとえば周期が 4 なら、

\[
2p=4
\]

なので、

\[
p=2
\]

である。

その場合、フーリエ級数は

\[
a_0+
\sum_{n=1}^{\infty}
\left(
a_n\cos\frac{n\pi x}{2}
+
b_n\sin\frac{n\pi x}{2}
\right)
\]

となる。

## 覚える形

\[
2p\text{-周期}
\quad\Longrightarrow\quad
\cos\frac{n\pi x}{p},
\quad
\sin\frac{n\pi x}{p}
\]

\[
a_0=
\frac{1}{2p}
\int_{-p}^{p}
f(x)\,dx
\]

\[
a_n=
\frac{1}{p}
\int_{-p}^{p}
f(x)
\cos\frac{n\pi x}{p}
\,dx
\]

\[
b_n=
\frac{1}{p}
\int_{-p}^{p}
f(x)
\sin\frac{n\pi x}{p}
\,dx
\]

## 口頭説明用

Theorem 2.2 は、周期が \(2\pi\) ではなく \(2p\) の関数に対するフーリエ級数の公式である。
周期が \(2p\) なので、基本の波は \(\cos nx\), \(\sin nx\) ではなく、

\[
\cos\frac{n\pi x}{p},
\qquad
\sin\frac{n\pi x}{p}
\]

になる。
係数は \([-p,p]\) で積分し、前の \(2\pi\)-周期の公式の \(\pi\) を \(p\) に置き換えた形になる。
不連続点では関数そのものではなく、左右の値の平均に収束する。
