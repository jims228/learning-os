# Lecture 3 Theorem 3.1: 半区間展開

作成日: 2026-06-08

## 何の定理か

Theorem 3.1 は、関数が

\[
0<x<p
\]

の範囲だけで与えられているときに使う。

このような関数を、

\[
\cos\text{ だけ}
\]

または、

\[
\sin\text{ だけ}
\]

で表す方法である。

これを半区間展開という。

## なぜ「半区間」なのか

普通のフーリエ級数では、

\[
-p<x<p
\]

のような左右両側の区間で考える。

しかし半区間展開では、

\[
0<x<p
\]

だけが与えられている。

つまり、右半分だけ分かっている状態でフーリエ級数を作る。

そこで、関数を左側にも延長して考える。

偶関数として延長すれば cos 級数、
奇関数として延長すれば sin 級数になる。

## 1. Cosine series expansion

関数 \(f(x)\) を cos だけで表すと、

\[
f(x)
\sim
a_0+
\sum_{n=1}^{\infty}
a_n\cos\frac{n\pi x}{p}
\qquad
(0<x<p)
\]

となる。

係数は、

\[
a_0=
\frac{1}{p}
\int_0^p f(x)\,dx
\]

\[
a_n=
\frac{2}{p}
\int_0^p
f(x)
\cos\frac{n\pi x}{p}
\,dx
\qquad
(n\ge 1)
\]

である。

## 2. Sine series expansion

関数 \(f(x)\) を sin だけで表すと、

\[
f(x)
\sim
\sum_{n=1}^{\infty}
b_n\sin\frac{n\pi x}{p}
\qquad
(0<x<p)
\]

となる。

係数は、

\[
b_n=
\frac{2}{p}
\int_0^p
f(x)
\sin\frac{n\pi x}{p}
\,dx
\qquad
(n\ge 1)
\]

である。

## Cosine と Sine の違い

cos 級数は、偶関数として延長したもの。

\[
f(-x)=f(x)
\]

の形で左側に広げる。

sin 級数は、奇関数として延長したもの。

\[
f(-x)=-f(x)
\]

の形で左側に広げる。

## 試験での使い分け

問題文に、

\[
\text{cosine series}
\]

と書かれていたら、cos だけを使う。

\[
f(x)
\sim
a_0+
\sum_{n=1}^{\infty}
a_n\cos\frac{n\pi x}{p}
\]

問題文に、

\[
\text{sine series}
\]

と書かれていたら、sin だけを使う。

\[
f(x)
\sim
\sum_{n=1}^{\infty}
b_n\sin\frac{n\pi x}{p}
\]

問題文に指定がない場合は、両方求める問題の可能性がある。

## 前の公式との関係

Lecture 2 の Theorem 2.2 では、\(2p\)-周期の関数を

\[
a_0+
\sum_{n=1}^{\infty}
\left(
a_n\cos\frac{n\pi x}{p}
+
b_n\sin\frac{n\pi x}{p}
\right)
\]

と書いた。

半区間展開では、最初から

\[
0<x<p
\]

だけで考える。

そのため、cos だけ、または sin だけで展開できる。

## 係数の前につく数字に注意

半区間展開では、

\[
a_0=
\frac{1}{p}
\int_0^p f(x)\,dx
\]

である。

一方、Lecture 2 の \(2p\)-周期公式では、

\[
a_0=
\frac{1}{2p}
\int_{-p}^{p}f(x)\,dx
\]

だった。

ここを混同しやすい。

半区間展開では区間が \(0\) から \(p\) なので、

\[
a_0\text{ は }\frac{1}{p}
\]

\[
a_n,b_n\text{ は }\frac{2}{p}
\]

を前につける。

## 収束先

\(0<x<p\) の中で \(f(x)\) が連続なら、級数は

\[
f(x)
\]

に収束する。

不連続点では、左右の値の平均に収束する。

\[
\frac{f(x-)+f(x+)}{2}
\]

## 解く手順

半区間展開の問題が出たら、次の順で進める。

1. 区間 \(0<x<p\) から \(p\) を確認する。
2. cos 級数か sin 級数かを確認する。
3. cos 級数なら \(a_0,a_n\) を計算する。
4. sin 級数なら \(b_n\) を計算する。
5. \(\cos(n\pi x/p)\) または \(\sin(n\pi x/p)\) を忘れない。

## 例: 周期の読み替え

もし区間が

\[
0<x<\pi
\]

なら、

\[
p=\pi
\]

なので、

\[
\cos\frac{n\pi x}{p}
=
\cos nx
\]

\[
\sin\frac{n\pi x}{p}
=
\sin nx
\]

になる。

もし区間が

\[
0<x<1
\]

なら、

\[
p=1
\]

なので、

\[
\cos n\pi x,
\qquad
\sin n\pi x
\]

を使う。

## 口頭説明用

Theorem 3.1 は半区間展開の公式である。
関数が \(0<x<p\) だけで与えられているとき、cos だけの級数、または sin だけの級数で表す。
cos 級数は偶関数として延長する考え方で、sin 級数は奇関数として延長する考え方である。
cos 級数では

\[
a_0=
\frac{1}{p}\int_0^p f(x)\,dx,
\qquad
a_n=
\frac{2}{p}\int_0^p f(x)\cos\frac{n\pi x}{p}\,dx
\]

を使う。
sin 級数では

\[
b_n=
\frac{2}{p}\int_0^p f(x)\sin\frac{n\pi x}{p}\,dx
\]

を使う。
試験では、まず \(p\) を確認してから、cos か sin かを選ぶ。
