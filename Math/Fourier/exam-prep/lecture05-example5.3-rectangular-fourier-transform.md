# Lecture 5 Example 5.3: 長方形関数のフーリエ変換

作成日: 2026-06-08

## 問題

次の関数のフーリエ変換を求める。

\[
f(x)=
\begin{cases}
1 & (|x|<a)\\
0 & (|x|>a)
\end{cases}
\]

また、

\[
\widehat f(0)
\]

を求める。

さらに、\(f\) を逆フーリエ変換で表す。

## 使う公式

この授業のフーリエ変換は、次の形である。

\[
\widehat f(\omega)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x)e^{-i\omega x}\,dx
\]

逆フーリエ変換は、

\[
f(x)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
e^{i\omega x}
\widehat f(\omega)\,d\omega
\]

である。

## Step 1: 積分区間を決める

今回の関数は、

\[
|x|<a
\]

でだけ 1 である。

つまり、

\[
-a<x<a
\]

のところだけ値が 1。

それ以外では 0。

だから、フーリエ変換の積分は、

\[
\int_{-\infty}^{\infty}
f(x)e^{-i\omega x}\,dx
\]

ではなく、実質的には

\[
\int_{-a}^{a}
e^{-i\omega x}\,dx
\]

だけ計算すればよい。

したがって、

\[
\widehat f(\omega)
=
\frac{1}{\sqrt{2\pi}}
\int_{-a}^{a}
e^{-i\omega x}\,dx
\]

である。

## Step 2: 指数関数を積分する

\[
\int e^{-i\omega x}\,dx
=
\frac{e^{-i\omega x}}{-i\omega}
\]

なので、

\[
\widehat f(\omega)
=
\frac{1}{\sqrt{2\pi}}
\left[
\frac{e^{-i\omega x}}{-i\omega}
\right]_{-a}^{a}
\]

\[
=
\frac{1}{\sqrt{2\pi}}
\frac{
e^{-i\omega a}-e^{i\omega a}
}{-i\omega}
\]

ここで、オイラーの公式から、

\[
e^{i\theta}-e^{-i\theta}=2i\sin\theta
\]

である。

したがって、

\[
e^{-i\omega a}-e^{i\omega a}
=
-2i\sin(a\omega)
\]

なので、

\[
\frac{
e^{-i\omega a}-e^{i\omega a}
}{-i\omega}
=
\frac{-2i\sin(a\omega)}{-i\omega}
=
\frac{2\sin(a\omega)}{\omega}
\]

よって、

\[
\widehat f(\omega)
=
\frac{1}{\sqrt{2\pi}}
\frac{2\sin(a\omega)}{\omega}
\]

つまり、

\[
\widehat f(\omega)
=
\sqrt{\frac{2}{\pi}}
\frac{\sin(a\omega)}{\omega}
\qquad
(\omega\ne0)
\]

である。

## Step 3: \(\widehat f(0)\)

\[
\widehat f(0)
\]

は、公式に \(\omega=0\) を入れて考える。

フーリエ変換の定義から、

\[
\widehat f(0)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x)\,dx
\]

である。

今回、\(f(x)\) は \(-a<x<a\) で高さ 1 の長方形なので、面積は

\[
2a
\]

である。

したがって、

\[
\widehat f(0)
=
\frac{1}{\sqrt{2\pi}}\cdot 2a
\]

\[
=
a\sqrt{\frac{2}{\pi}}
\]

である。

## 極限で確認する

\[
\widehat f(\omega)
=
\sqrt{\frac{2}{\pi}}
\frac{\sin(a\omega)}{\omega}
\]

である。

\(\omega\to0\) のとき、

\[
\sin(a\omega)\sim a\omega
\]

なので、

\[
\frac{\sin(a\omega)}{\omega}
\to a
\]

したがって、

\[
\widehat f(0)
=
a\sqrt{\frac{2}{\pi}}
\]

となる。

面積で求めた答えと同じである。

## Step 4: 逆フーリエ変換で表す

逆フーリエ変換は、

\[
f(x)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
e^{i\omega x}
\widehat f(\omega)\,d\omega
\]

である。

ここに、

\[
\widehat f(\omega)
=
\sqrt{\frac{2}{\pi}}
\frac{\sin(a\omega)}{\omega}
\]

を代入する。

\[
f(x)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
e^{i\omega x}
\sqrt{\frac{2}{\pi}}
\frac{\sin(a\omega)}{\omega}
\,d\omega
\]

前の定数をまとめると、

\[
\frac{1}{\sqrt{2\pi}}
\sqrt{\frac{2}{\pi}}
=
\frac{1}{\pi}
\]

なので、

\[
f(x)
=
\frac{1}{\pi}
\int_{-\infty}^{\infty}
e^{i\omega x}
\frac{\sin(a\omega)}{\omega}
\,d\omega
\]

となる。

## 不連続点での注意

\(f(x)\) は、

\[
x=\pm a
\]

でジャンプしている。

逆フーリエ変換では、不連続点では左右の平均に収束する。

今回、

\[
f(a-)=1,
\qquad
f(a+)=0
\]

なので、

\[
x=a
\]

では

\[
\frac{1+0}{2}
=
\frac{1}{2}
\]

に収束する。

同じように、

\[
x=-a
\]

でも

\[
\frac{1}{2}
\]

に収束する。

## グラフの意味

元の \(f(x)\) は、幅 \(2a\)、高さ 1 の長方形である。

そのフーリエ変換は、

\[
\frac{\sin(a\omega)}{\omega}
\]

の形になる。

これは sinc 型の関数で、\(\omega=0\) で一番大きく、左右に波打ちながら小さくなる。

## 試験でのポイント

英語で、

```text
Find the Fourier transform.
```

と出たら、

\[
\widehat f(\omega)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x)e^{-i\omega x}\,dx
\]

に代入する。

今回のような長方形関数なら、積分区間を

\[
-a\le x\le a
\]

に絞る。

英語で、

```text
What is \hat f(0)?
```

と出たら、面積を使えばよい。

\[
\widehat f(0)
=
\frac{1}{\sqrt{2\pi}}
\times
\text{面積}
\]

である。

## 口頭説明用

この問題では、\(f(x)\) が \(-a<x<a\) で 1、それ以外で 0 なので、フーリエ変換の積分は \(-a\) から \(a\) だけ計算すればよい。
公式に代入すると、

\[
\widehat f(\omega)
=
\frac{1}{\sqrt{2\pi}}
\int_{-a}^{a}
e^{-i\omega x}\,dx
\]

となる。
これを積分してオイラーの公式で整理すると、

\[
\widehat f(\omega)
=
\sqrt{\frac{2}{\pi}}
\frac{\sin(a\omega)}{\omega}
\]

である。
また \(\omega=0\) では面積を使って、

\[
\widehat f(0)=a\sqrt{\frac{2}{\pi}}
\]

となる。
