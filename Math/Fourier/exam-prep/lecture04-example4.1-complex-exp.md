# Lecture 4 Example 4.1: \(f(x)=e^{ax}\) の複素フーリエ級数

作成日: 2026-06-08

## 問題

次の \(2\pi\)-周期関数の複素フーリエ級数を求める。

\[
f(x)=e^{ax}
\qquad
(-\pi<x<\pi)
\]

ただし、

\[
a\ne 0,\ \pm i,\ \pm2i,\ \pm3i,\ldots
\]

である。

また、

\[
x=\pm\pi
\]

でフーリエ級数がどの値に収束するかも求める。

## 使う公式

複素フーリエ級数は、

\[
f(x)
\sim
\sum_{n=-\infty}^{\infty}
c_n e^{inx}
\]

である。

係数は、

\[
c_n=
\frac{1}{2\pi}
\int_{-\pi}^{\pi}
f(x)e^{-inx}\,dx
\]

で求める。

今回、

\[
f(x)=e^{ax}
\]

なので、

\[
c_n=
\frac{1}{2\pi}
\int_{-\pi}^{\pi}
e^{ax}e^{-inx}\,dx
\]

となる。

## Step 1: 指数をまとめる

\[
e^{ax}e^{-inx}
=
e^{(a-in)x}
\]

なので、

\[
c_n=
\frac{1}{2\pi}
\int_{-\pi}^{\pi}
e^{(a-in)x}\,dx
\]

である。

## Step 2: 積分する

\[
\int e^{(a-in)x}\,dx
=
\frac{e^{(a-in)x}}{a-in}
\]

なので、

\[
c_n=
\frac{1}{2\pi}
\left[
\frac{e^{(a-in)x}}{a-in}
\right]_{-\pi}^{\pi}
\]

\[
=
\frac{1}{2\pi}
\frac{
e^{(a-in)\pi}
-
e^{-(a-in)\pi}
}{a-in}
\]

## Step 3: 端点を整理する

まず、

\[
e^{(a-in)\pi}
=
e^{a\pi}e^{-in\pi}
\]

である。

ここで、

\[
e^{-in\pi}=(-1)^n
\]

だから、

\[
e^{(a-in)\pi}
=
(-1)^n e^{a\pi}
\]

同じように、

\[
e^{-(a-in)\pi}
=
e^{-a\pi}e^{in\pi}
=
(-1)^n e^{-a\pi}
\]

したがって、分子は

\[
e^{(a-in)\pi}
-
e^{-(a-in)\pi}
=
(-1)^n
\left(
e^{a\pi}-e^{-a\pi}
\right)
\]

である。

## Step 4: \(\sinh\) を使う

双曲線正弦は、

\[
\sinh x=
\frac{e^x-e^{-x}}{2}
\]

である。

したがって、

\[
e^{a\pi}-e^{-a\pi}
=
2\sinh(a\pi)
\]

なので、

\[
c_n=
\frac{1}{2\pi}
\frac{
(-1)^n
2\sinh(a\pi)
}{a-in}
\]

よって、

\[
c_n=
\frac{(-1)^n\sinh(a\pi)}
{\pi(a-in)}
\]

これが複素フーリエ係数である。

## 係数の別表現

分母を少し整理したいときは、

\[
\frac{1}{a-in}
\]

に

\[
\frac{a+in}{a+in}
\]

をかける。

すると、

\[
\frac{1}{a-in}
=
\frac{a+in}{a^2+n^2}
\]

なので、

\[
c_n=
\frac{\sinh(a\pi)}{\pi}
\frac{(-1)^n(a+in)}{a^2+n^2}
\]

とも書ける。

## 答え

したがって、複素フーリエ級数は、

\[
e^{ax}
\sim
\frac{\sinh(a\pi)}{\pi}
\sum_{n=-\infty}^{\infty}
\frac{(-1)^n}{a-in}
e^{inx}
\]

または、

\[
e^{ax}
\sim
\frac{\sinh(a\pi)}{\pi}
\sum_{n=-\infty}^{\infty}
\frac{(-1)^n(a+in)}{a^2+n^2}
e^{inx}
\]

である。

## \(x=\pm\pi\) での値

この関数は、もとの区間では

\[
-\pi<x<\pi
\]

で

\[
f(x)=e^{ax}
\]

である。

しかし \(2\pi\)-周期にすると、端点 \(x=\pi\) と \(x=-\pi\) でジャンプが起きる。

フーリエ級数は不連続点では、左右の値の平均に収束する。

\[
\frac{f(x-)+f(x+)}{2}
\]

\(x=\pi\) では、左から近づくと

\[
e^{a\pi}
\]

右から近づくと、周期で戻って

\[
e^{-a\pi}
\]

になる。

したがって、

\[
\frac{e^{a\pi}+e^{-a\pi}}{2}
\]

に収束する。

これは双曲線余弦を使って、

\[
\cosh(a\pi)
\]

と書ける。

よって、

\[
x=\pm\pi
\]

での収束値は、

\[
\cosh(a\pi)
\]

である。

## ここで使った指数の事実

\[
e^{in\pi}=(-1)^n
\]

\[
e^{-in\pi}=(-1)^n
\]

これは、オイラーの公式

\[
e^{i\theta}=\cos\theta+i\sin\theta
\]

から分かる。

\[
e^{in\pi}
=
\cos n\pi+i\sin n\pi
=
(-1)^n+0i
=
(-1)^n
\]

である。

## 英語で出たとき

問題文の

```text
Find the complex form of the Fourier series
```

は、

\[
c_n
\]

を求めて、

\[
\sum_{n=-\infty}^{\infty}c_n e^{inx}
\]

に入れる、という意味である。

問題文の

```text
Determine the values of the Fourier series at x = ±π
```

は、不連続点で左右の平均を求める、という意味である。

## 口頭説明用

この問題では、複素フーリエ係数

\[
c_n=
\frac{1}{2\pi}
\int_{-\pi}^{\pi}f(x)e^{-inx}\,dx
\]

を使う。
今回 \(f(x)=e^{ax}\) なので、

\[
e^{ax}e^{-inx}=e^{(a-in)x}
\]

として積分する。
端点で \(e^{\pm in\pi}=(-1)^n\) を使うと、

\[
c_n=
\frac{(-1)^n\sinh(a\pi)}{\pi(a-in)}
\]

となる。
したがって複素フーリエ級数は

\[
e^{ax}
\sim
\frac{\sinh(a\pi)}{\pi}
\sum_{n=-\infty}^{\infty}
\frac{(-1)^n}{a-in}e^{inx}
\]

である。
また \(x=\pm\pi\) ではジャンプしているので、左右の平均

\[
\frac{e^{a\pi}+e^{-a\pi}}{2}
=
\cosh(a\pi)
\]

に収束する。
