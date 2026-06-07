# Lecture 2 Example 2.6: 任意周期の \(f(x)=|x|\)

作成日: 2026-06-08

## 問題

次の \(2p\)-周期関数のフーリエ級数を求める。

\[
f(x)=|x|
\qquad
(-p\le x\le p)
\]

グラフは、\(x=0\) で谷になる V 字型である。

## 最初に見るポイント

\[
f(x)=|x|
\]

は左右対称である。

つまり、

\[
f(-x)=f(x)
\]

なので、偶関数である。

偶関数では、sin の係数は全部 0 になる。

\[
b_n=0
\]

したがって、今回は \(a_0\) と \(a_n\) だけ計算すればよい。

## 使う公式

周期が \(2p\) なので、Theorem 2.2 を使う。

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

係数は、

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

## Step 1: \(a_0\)

\[
a_0=
\frac{1}{2p}
\int_{-p}^{p}
|x|\,dx
\]

\(|x|\) は偶関数なので、

\[
\int_{-p}^{p}|x|\,dx
=
2\int_0^p x\,dx
\]

したがって、

\[
a_0=
\frac{1}{2p}
\cdot
2\int_0^p x\,dx
\]

\[
=
\frac{1}{p}
\left[
\frac{x^2}{2}
\right]_0^p
\]

\[
=
\frac{1}{p}
\cdot
\frac{p^2}{2}
=
\frac{p}{2}
\]

よって、

\[
a_0=\frac{p}{2}
\]

## Step 2: \(b_n\)

\[
b_n=
\frac{1}{p}
\int_{-p}^{p}
|x|
\sin\frac{n\pi x}{p}
\,dx
\]

ここで、

\[
|x|
\]

は偶関数、

\[
\sin\frac{n\pi x}{p}
\]

は奇関数である。

偶関数 \(\times\) 奇関数は奇関数になる。

奇関数を左右対称な区間 \([-p,p]\) で積分すると 0 になる。

したがって、

\[
b_n=0
\]

## Step 3: \(a_n\)

\[
a_n=
\frac{1}{p}
\int_{-p}^{p}
|x|
\cos\frac{n\pi x}{p}
\,dx
\]

\(|x|\) も \(\cos\frac{n\pi x}{p}\) も偶関数である。

したがって、積分を右半分だけにできる。

\[
a_n=
\frac{2}{p}
\int_0^p
x
\cos\frac{n\pi x}{p}
\,dx
\]

ここで、

\[
\alpha=\frac{n\pi}{p}
\]

と置くと、

\[
a_n=
\frac{2}{p}
\int_0^p x\cos \alpha x\,dx
\]

部分積分を使う。

\[
u=x,\qquad dv=\cos\alpha x\,dx
\]

と置く。

すると、

\[
du=dx,\qquad v=\frac{\sin\alpha x}{\alpha}
\]

なので、

\[
\int_0^p x\cos\alpha x\,dx
=
\left[
\frac{x\sin\alpha x}{\alpha}
\right]_0^p
-
\int_0^p
\frac{\sin\alpha x}{\alpha}
\,dx
\]

ここで、

\[
\alpha p
=
\frac{n\pi}{p}p
=
n\pi
\]

だから、

\[
\sin\alpha p=\sin n\pi=0
\]

である。

したがって最初の項は 0 になる。

残りは、

\[
-\frac{1}{\alpha}
\int_0^p \sin\alpha x\,dx
\]

である。

\[
\int \sin\alpha x\,dx
=
-\frac{\cos\alpha x}{\alpha}
\]

なので、

\[
\int_0^p x\cos\alpha x\,dx
=
\left[
\frac{\cos\alpha x}{\alpha^2}
\right]_0^p
\]

\[
=
\frac{\cos\alpha p-\cos0}{\alpha^2}
\]

\[
=
\frac{\cos n\pi-1}{\alpha^2}
\]

ここで、

\[
\cos n\pi=(-1)^n
\]

なので、

\[
\int_0^p x\cos\alpha x\,dx
=
\frac{(-1)^n-1}{\alpha^2}
\]

また、

\[
\alpha=\frac{n\pi}{p}
\]

だから、

\[
\alpha^2=\frac{n^2\pi^2}{p^2}
\]

したがって、

\[
\int_0^p x\cos\frac{n\pi x}{p}\,dx
=
\frac{p^2}{n^2\pi^2}
\{(-1)^n-1\}
\]

これを \(a_n\) に戻す。

\[
a_n=
\frac{2}{p}
\cdot
\frac{p^2}{n^2\pi^2}
\{(-1)^n-1\}
\]

よって、

\[
a_n=
\frac{2p}{n^2\pi^2}
\{(-1)^n-1\}
\]

同じことを、次のように書いてもよい。

\[
a_n=
-\frac{2p}{n^2\pi^2}
\{1-(-1)^n\}
\]

## 偶数番目と奇数番目で見る

\(n\) が偶数のとき、

\[
(-1)^n=1
\]

なので、

\[
a_n=0
\]

\(n\) が奇数のとき、

\[
(-1)^n=-1
\]

なので、

\[
a_n=
\frac{2p}{n^2\pi^2}
(-1-1)
=
-\frac{4p}{n^2\pi^2}
\]

つまり、

\[
a_n=
\begin{cases}
0 & n\text{ が偶数}\\
-\dfrac{4p}{\pi^2 n^2} & n\text{ が奇数}
\end{cases}
\]

である。

## 答え

\[
f(x)
=
\frac{p}{2}
-
\frac{4p}{\pi^2}
\left(
\cos\frac{\pi x}{p}
+
\frac{1}{3^2}\cos\frac{3\pi x}{p}
+
\frac{1}{5^2}\cos\frac{5\pi x}{p}
+\cdots
\right)
\]

総和記号で書くと、

\[
f(x)
=
\frac{p}{2}
-
\frac{4p}{\pi^2}
\sum_{k=0}^{\infty}
\frac{1}{(2k+1)^2}
\cos\frac{(2k+1)\pi x}{p}
\]

## \(p=1\) の場合

スライドの図では \(p=1\) の場合も示されている。

\(p=1\) なら、

\[
f(x)=|x|
\qquad
(-1\le x\le 1)
\]

で、

\[
f(x)
=
\frac{1}{2}
-
\frac{4}{\pi^2}
\left(
\cos\pi x
+
\frac{1}{3^2}\cos 3\pi x
+
\frac{1}{5^2}\cos 5\pi x
+\cdots
\right)
\]

となる。

## Example 2.2 との違い

Example 2.2 は、

\[
g(x)=\pi-|x|
\]

のような山型の三角波だった。

今回は、

\[
f(x)=|x|
\]

なので、谷型である。

そのため、cos 係数にマイナスが付く。

ざっくり言うと、

\[
\text{山型はプラス}
\]

\[
\text{谷型はマイナス}
\]

と見ると覚えやすい。

## 口頭説明用

この問題は、周期が \(2p\) の関数 \(f(x)=|x|\) のフーリエ級数を求める問題である。
まず \(|x|\) は偶関数なので、sin の係数 \(b_n\) はすべて 0 になる。
定数項は面積から \(a_0=p/2\)。
cos の係数は、

\[
a_n=
\frac{2}{p}
\int_0^p x\cos\frac{n\pi x}{p}\,dx
\]

を部分積分して求める。
結果は、偶数番目では 0、奇数番目では

\[
-\frac{4p}{\pi^2 n^2}
\]

になる。
したがって、

\[
f(x)
=
\frac{p}{2}
-
\frac{4p}{\pi^2}
\left(
\cos\frac{\pi x}{p}
+
\frac{1}{3^2}\cos\frac{3\pi x}{p}
+
\frac{1}{5^2}\cos\frac{5\pi x}{p}
+\cdots
\right)
\]

である。
