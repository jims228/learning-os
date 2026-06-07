# Lecture 3 Example 3.1: \(f(x)=x\) の半区間展開

作成日: 2026-06-08

## 問題

次の関数の半区間展開を求める。

\[
f(x)=x
\qquad
(0<x<1)
\]

半区間展開なので、次の 2 種類を考える。

1. cosine series expansion
2. sine series expansion

## 最初に見るポイント

区間は、

\[
0<x<1
\]

なので、

\[
p=1
\]

である。

したがって、

\[
\cos\frac{n\pi x}{p}
=
\cos n\pi x
\]

\[
\sin\frac{n\pi x}{p}
=
\sin n\pi x
\]

を使う。

## 1. Cosine series expansion

cos 展開では、

\[
f(x)
\sim
a_0+
\sum_{n=1}^{\infty}
a_n\cos n\pi x
\]

と書く。

係数は、

\[
a_0=
\int_0^1 x\,dx
\]

\[
a_n=
2\int_0^1 x\cos n\pi x\,dx
\]

である。

### Step 1: \(a_0\)

\[
a_0=
\int_0^1 x\,dx
\]

\[
=
\left[
\frac{x^2}{2}
\right]_0^1
=
\frac{1}{2}
\]

したがって、

\[
a_0=\frac{1}{2}
\]

### Step 2: \(a_n\)

\[
a_n=
2\int_0^1 x\cos n\pi x\,dx
\]

中の積分を計算する。

\[
I=
\int_0^1 x\cos n\pi x\,dx
\]

部分積分を使う。

\[
u=x,
\qquad
dv=\cos n\pi x\,dx
\]

と置く。

すると、

\[
du=dx,
\qquad
v=\frac{\sin n\pi x}{n\pi}
\]

である。

部分積分の公式より、

\[
\int u\,dv
=
uv-\int v\,du
\]

だから、

\[
I=
\left[
\frac{x\sin n\pi x}{n\pi}
\right]_0^1
-
\int_0^1
\frac{\sin n\pi x}{n\pi}
\,dx
\]

ここで、

\[
\sin n\pi=0,
\qquad
\sin0=0
\]

なので、最初の項は 0 になる。

\[
I=
-
\frac{1}{n\pi}
\int_0^1
\sin n\pi x\,dx
\]

\[
\int \sin n\pi x\,dx
=
-\frac{\cos n\pi x}{n\pi}
\]

なので、

\[
I=
-
\frac{1}{n\pi}
\left[
-\frac{\cos n\pi x}{n\pi}
\right]_0^1
\]

\[
=
\frac{1}{n^2\pi^2}
\left[
\cos n\pi x
\right]_0^1
\]

\[
=
\frac{\cos n\pi-\cos0}{n^2\pi^2}
\]

\[
=
\frac{(-1)^n-1}{n^2\pi^2}
\]

したがって、

\[
a_n=
2I
=
\frac{2\{(-1)^n-1\}}{n^2\pi^2}
\]

### 偶数・奇数で見る

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
\frac{2(-1-1)}{n^2\pi^2}
=
-\frac{4}{n^2\pi^2}
\]

つまり、

\[
a_n=
\begin{cases}
0 & n\text{ が偶数}\\
-\dfrac{4}{n^2\pi^2} & n\text{ が奇数}
\end{cases}
\]

### Cosine series の答え

\[
x
=
\frac{1}{2}
-
\frac{4}{\pi^2}
\left(
\cos\pi x
+
\frac{1}{3^2}\cos3\pi x
+
\frac{1}{5^2}\cos5\pi x
+\cdots
\right)
\]

総和記号で書くと、

\[
x
=
\frac{1}{2}
-
\frac{4}{\pi^2}
\sum_{k=0}^{\infty}
\frac{\cos(2k+1)\pi x}{(2k+1)^2}
\qquad
(0<x<1)
\]

## 2. Sine series expansion

sin 展開では、

\[
f(x)
\sim
\sum_{n=1}^{\infty}
b_n\sin n\pi x
\]

と書く。

係数は、

\[
b_n=
2\int_0^1 x\sin n\pi x\,dx
\]

である。

### Step 1: \(b_n\)

\[
b_n=
2\int_0^1 x\sin n\pi x\,dx
\]

中の積分を

\[
J=
\int_0^1 x\sin n\pi x\,dx
\]

とする。

部分積分を使う。

\[
u=x,
\qquad
dv=\sin n\pi x\,dx
\]

と置く。

すると、

\[
du=dx,
\qquad
v=-\frac{\cos n\pi x}{n\pi}
\]

である。

部分積分より、

\[
J=
\left[
-\frac{x\cos n\pi x}{n\pi}
\right]_0^1
+
\int_0^1
\frac{\cos n\pi x}{n\pi}
\,dx
\]

まず、

\[
\left[
-\frac{x\cos n\pi x}{n\pi}
\right]_0^1
=
-\frac{\cos n\pi}{n\pi}
\]

である。

次に、

\[
\int_0^1
\frac{\cos n\pi x}{n\pi}
\,dx
=
\frac{1}{n\pi}
\left[
\frac{\sin n\pi x}{n\pi}
\right]_0^1
=0
\]

なぜなら、

\[
\sin n\pi=0,
\qquad
\sin0=0
\]

だからである。

したがって、

\[
J=
-\frac{\cos n\pi}{n\pi}
\]

\[
=
-\frac{(-1)^n}{n\pi}
\]

\[
=
\frac{(-1)^{n+1}}{n\pi}
\]

よって、

\[
b_n=
2J
=
\frac{2(-1)^{n+1}}{n\pi}
\]

### Sine series の答え

\[
x
=
\sum_{n=1}^{\infty}
\frac{2(-1)^{n+1}}{n\pi}
\sin n\pi x
\]

つまり、

\[
x
=
\frac{2}{\pi}
\left(
\sin\pi x
-
\frac{1}{2}\sin2\pi x
+
\frac{1}{3}\sin3\pi x
-
\frac{1}{4}\sin4\pi x
+\cdots
\right)
\]

である。

## なぜ答えが 2 つあるのか

半区間展開では、\(0<x<1\) の右側だけが与えられている。

左側をどう作るかは、こちらで選べる。

偶関数として左側を作ると、cos 展開になる。

\[
f(-x)=f(x)
\]

奇関数として左側を作ると、sin 展開になる。

\[
f(-x)=-f(x)
\]

元の \(0<x<1\) の範囲では、どちらも同じ \(x\) を表す。

## 試験でのポイント

この問題では、まず

\[
p=1
\]

を確認する。

そのため、

\[
\cos\frac{n\pi x}{p}=\cos n\pi x
\]

\[
\sin\frac{n\pi x}{p}=\sin n\pi x
\]

である。

cos 展開なら、

\[
a_0,\quad a_n
\]

を計算する。

sin 展開なら、

\[
b_n
\]

を計算する。

## 口頭説明用

Example 3.1 は、\(0<x<1\) で \(f(x)=x\) の半区間展開を求める問題である。
区間が \(0<x<1\) なので \(p=1\)。
cos 展開では偶関数として延長し、

\[
x
=
\frac{1}{2}
-
\frac{4}{\pi^2}
\left(
\cos\pi x
+
\frac{1}{3^2}\cos3\pi x
+
\frac{1}{5^2}\cos5\pi x
+\cdots
\right)
\]

となる。
sin 展開では奇関数として延長し、

\[
x
=
\frac{2}{\pi}
\left(
\sin\pi x
-
\frac{1}{2}\sin2\pi x
+
\frac{1}{3}\sin3\pi x
-\cdots
\right)
\]

となる。
同じ \(f(x)=x\) でも、偶延長なら cos、奇延長なら sin の級数になる。
