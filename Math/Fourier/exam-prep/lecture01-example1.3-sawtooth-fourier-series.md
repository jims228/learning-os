# Lecture 1 Example 1.3: のこぎり波のフーリエ級数

作成日: 2026-06-07

## 問題

次の \(2\pi\)-周期関数のフーリエ級数を求める。

$$
f(x)=\frac{1}{2}(\pi-x)
\qquad
(0<x\le 2\pi)
$$

かつ、

$$
f(x+2\pi)=f(x)
$$

である。

## 使う公式

\(2\pi\)-周期関数のフーリエ級数を、

$$
f(x)=a_0+\sum_{n=1}^{\infty}\{a_n\cos nx+b_n\sin nx\}
$$

と書く。

係数は、区間 \(0\le x\le 2\pi\) で計算してよい。

$$
a_0=
\frac{1}{2\pi}\int_0^{2\pi}f(x)\,dx
$$

$$
a_n=
\frac{1}{\pi}\int_0^{2\pi}f(x)\cos nx\,dx
$$

$$
b_n=
\frac{1}{\pi}\int_0^{2\pi}f(x)\sin nx\,dx
$$

## Step 1: \(a_0\)

$$
a_0=
\frac{1}{2\pi}\int_0^{2\pi}\frac{1}{2}(\pi-x)\,dx
$$

計算すると、

$$
\begin{aligned}
a_0
&=
\frac{1}{4\pi}\int_0^{2\pi}(\pi-x)\,dx\\
&=
\frac{1}{4\pi}
\left[
\pi x-\frac{x^2}{2}
\right]_0^{2\pi}\\
&=
\frac{1}{4\pi}
(2\pi^2-2\pi^2)\\
&=0
\end{aligned}
$$

したがって、

$$
a_0=0
$$

## Step 2: \(a_n\)

$$
a_n=
\frac{1}{\pi}\int_0^{2\pi}
\frac{1}{2}(\pi-x)\cos nx\,dx
$$

この積分は部分積分で計算する。

結果として、

$$
\int_0^{2\pi}
\frac{1}{2}(\pi-x)\cos nx\,dx
=
0
$$

したがって、

$$
a_n=0
$$

## Step 3: \(b_n\)

$$
b_n=
\frac{1}{\pi}\int_0^{2\pi}
\frac{1}{2}(\pi-x)\sin nx\,dx
$$

ここは部分積分で計算する。

まず、

$$
u=\frac{1}{2}(\pi-x),
\qquad
dv=\sin nx\,dx
$$

と置く。

すると、

$$
du=-\frac{1}{2}dx,
\qquad
v=-\frac{\cos nx}{n}
$$

部分積分より、

$$
\int u\,dv
=
uv-\int v\,du
$$

なので、

$$
\begin{aligned}
\int_0^{2\pi}
\frac{1}{2}(\pi-x)\sin nx\,dx
&=
\left[
-\frac{\pi-x}{2n}\cos nx
\right]_0^{2\pi}
-
\frac{1}{2n}
\int_0^{2\pi}\cos nx\,dx
\end{aligned}
$$

ここで、

$$
\int_0^{2\pi}\cos nx\,dx=0
$$

である。

また、\(\cos(2\pi n)=1\), \(\cos0=1\) より、

$$
\left[
-\frac{\pi-x}{2n}\cos nx
\right]_0^{2\pi}
=
\frac{\pi}{n}
$$

したがって、

$$
\int_0^{2\pi}
\frac{1}{2}(\pi-x)\sin nx\,dx
=
\frac{\pi}{n}
$$

よって、

$$
b_n=
\frac{1}{\pi}\cdot\frac{\pi}{n}
=
\frac{1}{n}
$$

## 係数まとめ

$$
a_0=0,\qquad
a_n=0,\qquad
b_n=\frac{1}{n}
$$

## 答え

したがって、フーリエ級数は、

$$
\boxed{
f(x)=
\sum_{n=1}^{\infty}\frac{\sin nx}{n}
}
$$

である。

## 口頭説明

この関数は \(2\pi\)-周期なので、\(0\) から \(2\pi\) の区間でフーリエ係数を計算します。\(a_0\) は積分すると0、\(a_n\) も \(\cos nx\) との積分で0になります。\(b_n\) は部分積分で計算すると \(\frac{1}{n}\) になります。したがって、フーリエ級数は \(\sum_{n=1}^{\infty}\frac{\sin nx}{n}\) です。
