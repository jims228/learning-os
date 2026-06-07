# Lecture 3 Example 3.2: \(f(x)=\sin x\) の半区間展開

作成日: 2026-06-08

## 問題

次の関数の半区間展開を求める。

\[
f(x)=\sin x
\qquad
(0\le x\le \pi)
\]

半区間展開なので、次の 2 種類を考える。

1. sine series expansion
2. cosine series expansion

## 最初に見るポイント

区間は、

\[
0\le x\le \pi
\]

なので、

\[
p=\pi
\]

である。

したがって、

\[
\sin\frac{n\pi x}{p}
=
\sin nx
\]

\[
\cos\frac{n\pi x}{p}
=
\cos nx
\]

を使う。

## 1. Sine series expansion

sin 展開では、奇関数として延長する。

今回の関数は、

\[
0\le x\le \pi
\]

で

\[
f(x)=\sin x
\]

である。

これを奇関数として延長すると、普通の \(\sin x\) そのものになる。

したがって、sine series expansion はそのまま

\[
f(x)=\sin x
\]

である。

係数で書くなら、

\[
b_1=1
\]

で、

\[
b_n=0
\qquad
(n\ne 1)
\]

である。

つまり、

\[
\sin x
=
\sin x
\]

という、かなりそのままの答えになる。

## 2. Cosine series expansion

cos 展開では、偶関数として延長する。

\[
f(x)=\sin x
\qquad
(0\le x\le \pi)
\]

を偶関数として延長すると、

\[
|\sin x|
\]

になる。

したがって、cos 展開では

\[
|\sin x|
\]

のフーリエ級数を考える。

ただし、元の区間 \(0\le x\le \pi\) では

\[
|\sin x|=\sin x
\]

なので、この級数は元の \(f(x)=\sin x\) の半区間 cos 展開として使える。

## Cos 展開の公式

\[
f(x)
\sim
a_0+
\sum_{n=1}^{\infty}
a_n\cos nx
\]

ここで、

\[
a_0=
\frac{1}{\pi}
\int_0^\pi
\sin x\,dx
\]

\[
a_n=
\frac{2}{\pi}
\int_0^\pi
\sin x\cos nx\,dx
\]

である。

## Step 1: \(a_0\)

\[
a_0=
\frac{1}{\pi}
\int_0^\pi
\sin x\,dx
\]

\[
=
\frac{1}{\pi}
\left[
-\cos x
\right]_0^\pi
\]

\[
=
\frac{1}{\pi}
\{-\cos\pi-(-\cos0)\}
\]

\[
=
\frac{1}{\pi}
\{1+1\}
=
\frac{2}{\pi}
\]

したがって、

\[
a_0=\frac{2}{\pi}
\]

## Step 2: \(a_n\)

\[
a_n=
\frac{2}{\pi}
\int_0^\pi
\sin x\cos nx\,dx
\]

ここでは、積和公式を使う。

\[
\sin A\cos B
=
\frac{1}{2}
\{\sin(A-B)+\sin(A+B)\}
\]

今回、

\[
A=x,
\qquad
B=nx
\]

なので、

\[
\sin x\cos nx
=
\frac{1}{2}
\{\sin(1-n)x+\sin(1+n)x\}
\]

したがって、

\[
a_n=
\frac{2}{\pi}
\int_0^\pi
\frac{1}{2}
\{\sin(1-n)x+\sin(1+n)x\}
\,dx
\]

\[
=
\frac{1}{\pi}
\int_0^\pi
\{\sin(1-n)x+\sin(1+n)x\}
\,dx
\]

この計算をすると、結果は次のようになる。

\[
a_n=
\begin{cases}
0 & n\text{ が奇数}\\
\dfrac{4}{\pi(1-n^2)} & n\text{ が偶数}
\end{cases}
\]

特に \(n=1\) のときも、

\[
a_1=0
\]

である。

## 偶数番目だけで書く

\(n\) が偶数のときだけ残るので、

\[
n=2k
\]

と置く。

すると、

\[
a_{2k}
=
\frac{4}{\pi(1-(2k)^2)}
\]

である。

分母を見やすくするためにマイナスを外に出すと、

\[
a_{2k}
=
-\frac{4}{\pi((2k)^2-1)}
\]

となる。

## Cosine series の答え

\[
\sin x
=
\frac{2}{\pi}
-
\frac{4}{\pi}
\sum_{k=1}^{\infty}
\frac{\cos 2kx}{(2k)^2-1}
\qquad
(0\le x\le \pi)
\]

最初の数項で書くと、

\[
\sin x
=
\frac{2}{\pi}
-
\frac{4}{\pi}
\left(
\frac{\cos 2x}{3}
+
\frac{\cos 4x}{15}
+
\frac{\cos 6x}{35}
+\cdots
\right)
\]

である。

## Sine series と Cosine series の答えまとめ

sine series は、

\[
\sin x
\]

そのもの。

cosine series は、

\[
\sin x
=
\frac{2}{\pi}
-
\frac{4}{\pi}
\sum_{k=1}^{\infty}
\frac{\cos 2kx}{(2k)^2-1}
\]

である。

## なぜ sine series は簡単なのか

もともと \(\sin x\) は奇関数である。

半区間 \(0\le x\le \pi\) の \(\sin x\) を奇関数として延長すると、普通の \(\sin x\) に戻る。

だから、sin 展開では余計な計算がいらない。

## なぜ cosine series は \(|\sin x|\) なのか

cos 展開では偶関数として延長する。

偶関数では、

\[
f(-x)=f(x)
\]

でなければならない。

\(\sin x\) の右半分を左側へ左右対称にコピーすると、下には行かず、全部上側に出る。

その形が

\[
|\sin x|
\]

である。

## 試験でのポイント

この問題では、まず

\[
p=\pi
\]

を確認する。

すると、

\[
\sin\frac{n\pi x}{p}=\sin nx,
\qquad
\cos\frac{n\pi x}{p}=\cos nx
\]

になる。

sin 展開は、答えがそのまま

\[
\sin x
\]

でよい。

cos 展開では、

\[
a_0=\frac{2}{\pi}
\]

で、

\[
a_n=0
\quad(n\text{ が奇数})
\]

\[
a_n=\frac{4}{\pi(1-n^2)}
\quad(n\text{ が偶数})
\]

となる。

## 口頭説明用

Example 3.2 は、\(0\le x\le \pi\) で \(f(x)=\sin x\) の半区間展開を求める問題である。
区間から \(p=\pi\) と分かるので、\(\sin nx\), \(\cos nx\) を使う。
奇関数として延長すると普通の \(\sin x\) になるため、sine series はそのまま \(\sin x\) である。
偶関数として延長すると \(|\sin x|\) になるため、cosine series を計算する。
その結果、

\[
\sin x
=
\frac{2}{\pi}
-
\frac{4}{\pi}
\sum_{k=1}^{\infty}
\frac{\cos 2kx}{(2k)^2-1}
\]

となる。
