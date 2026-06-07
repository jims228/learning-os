# Lecture 2 Example 2.4: フーリエ級数の線形結合

作成日: 2026-06-08

## 問題

次の \(2\pi\)-周期関数 \(h(x)\) のフーリエ級数を求める。

\[
h(x)=
\begin{cases}
\pi-x & (0<x\le \pi)\\
0 & (\pi<x<2\pi)
\end{cases}
\]

講義資料では、この関数が Example 1.3 の \(f(x)\) と Example 2.2 の \(g(x)\) を使って、

\[
h(x)=f(x)+\frac{1}{2}g(x)
\]

と書けることを使う。

## 使う考え方

フーリエ級数は足し算と定数倍ができる。

つまり、

\[
h(x)=f(x)+\frac{1}{2}g(x)
\]

なら、

\[
h(x)\text{ のフーリエ級数}
=
f(x)\text{ のフーリエ級数}
+
\frac{1}{2}
g(x)\text{ のフーリエ級数}
\]

としてよい。

これは、積分を最初からやり直さなくてよい、という意味である。

## すでに求めた結果

Example 1.3 より、

\[
f(x)=
\sum_{n=1}^{\infty}
\frac{\sin nx}{n}
\]

Example 2.2 より、

\[
g(x)=
\frac{\pi}{2}
+
\sum_{n=1}^{\infty}
\frac{2}{\pi n^2}
\{1-(-1)^n\}
\cos nx
\]

## Step 1: \(\frac{1}{2}g(x)\) を作る

\[
g(x)=
\frac{\pi}{2}
+
\sum_{n=1}^{\infty}
\frac{2}{\pi n^2}
\{1-(-1)^n\}
\cos nx
\]

なので、全体に \(\frac{1}{2}\) をかける。

\[
\frac{1}{2}g(x)
=
\frac{\pi}{4}
+
\sum_{n=1}^{\infty}
\frac{1}{\pi n^2}
\{1-(-1)^n\}
\cos nx
\]

ここで、

\[
\frac{1}{2}\cdot \frac{\pi}{2}
=
\frac{\pi}{4}
\]

かつ、

\[
\frac{1}{2}
\cdot
\frac{2}{\pi n^2}
=
\frac{1}{\pi n^2}
\]

である。

## Step 2: \(f(x)\) と \(\frac{1}{2}g(x)\) を足す

\[
h(x)=f(x)+\frac{1}{2}g(x)
\]

だから、

\[
h(x)=
\sum_{n=1}^{\infty}
\frac{\sin nx}{n}
+
\frac{\pi}{4}
+
\sum_{n=1}^{\infty}
\frac{1}{\pi n^2}
\{1-(-1)^n\}
\cos nx
\]

見やすく並べると、

\[
h(x)=
\frac{\pi}{4}
+
\sum_{n=1}^{\infty}
\frac{\sin nx}{n}
+
\frac{1}{\pi}
\sum_{n=1}^{\infty}
\frac{1-(-1)^n}{n^2}
\cos nx
\]

これが答えである。

## 奇数番目だけで書く形

\[
1-(-1)^n
\]

は、\(n\) が偶数なら 0、奇数なら 2 である。

したがって cos の部分は奇数番目だけ残る。

\[
\frac{1}{\pi}
\sum_{n=1}^{\infty}
\frac{1-(-1)^n}{n^2}
\cos nx
=
\frac{2}{\pi}
\left(
\cos x
+
\frac{\cos 3x}{3^2}
+
\frac{\cos 5x}{5^2}
+\cdots
\right)
\]

よって、

\[
h(x)=
\frac{\pi}{4}
+
\sum_{n=1}^{\infty}
\frac{\sin nx}{n}
+
\frac{2}{\pi}
\left(
\cos x
+
\frac{\cos 3x}{3^2}
+
\frac{\cos 5x}{5^2}
+\cdots
\right)
\]

## 最初の数項で見る

\[
h(x)=
\frac{\pi}{4}
+
\sin x
+
\frac{\sin 2x}{2}
+
\frac{\sin 3x}{3}
+\cdots
+
\frac{2}{\pi}\cos x
+
\frac{2}{9\pi}\cos 3x
+
\frac{2}{25\pi}\cos 5x
+\cdots
\]

sin の部分は Example 1.3 から来ている。

cos の部分は \(\frac{1}{2}\) Example 2.2 から来ている。

## 不連続点での注意

この関数 \(h(x)\) は \(x=0, 2\pi, 4\pi,\ldots\) でジャンプする。

フーリエ級数は、ジャンプしている点では左右の値の平均に収束する。

\(x=0\) では、右側の値は \(\pi\)、左側の値は 0 なので、

\[
\frac{\pi+0}{2}
=
\frac{\pi}{2}
\]

に収束する。

これは Gibbs phenomenon と関係する。

## 口頭説明用

この問題では、\(h(x)\) を直接積分するのではなく、

\[
h(x)=f(x)+\frac{1}{2}g(x)
\]

と分解して考える。
フーリエ級数は足し算と定数倍ができるので、Example 1.3 の答えと Example 2.2 の答えをそのまま足せばよい。
Example 1.3 から sin の和が出て、Example 2.2 の半分から定数項 \(\pi/4\) と cos の奇数番目が出る。
したがって、

\[
h(x)=
\frac{\pi}{4}
+
\sum_{n=1}^{\infty}
\frac{\sin nx}{n}
+
\frac{1}{\pi}
\sum_{n=1}^{\infty}
\frac{1-(-1)^n}{n^2}
\cos nx
\]

となる。
