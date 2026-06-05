# Lecture 8 Example 8.4: 4点IDFT

作成日: 2026-06-05

## 問題

次の列の Inverse Discrete Fourier Transform, IDFT を求める。

$$
\{F(0),F(1),F(2),F(3)\}=\{1,-i,-1,i\},\qquad N=4
$$

## 何をする計算か

DFT は、もとの列を「周波数ごとの成分」に分解する計算。

IDFT はその逆で、周波数成分からもとの列を復元する計算。

この問題では、前回の Example 8.2 で得た

$$
\{1,-i,-1,i\}
$$

から、もとの

$$
\{0,1,0,0\}
$$

に戻ることを確認する。

## 使う公式

4点IDFTでは、次の公式だけを使う。

$$
f(n)=\frac{1}{4}\sum_{k=0}^{3}F(k)e^{i2\pi nk/4}
$$

ここで

$$
e^{i2\pi/4}=e^{i\pi/2}=i
$$

なので、

$$
f(n)=\frac{1}{4}\sum_{k=0}^{3}F(k)i^{nk}
$$

として計算できる。

## べき乗表

$$
\begin{array}{c|cccc}
m & 0 & 1 & 2 & 3 \\
\hline
i^m & 1 & i & -1 & -i
\end{array}
$$

## 計算

### n=0

$$
\begin{aligned}
f(0)
&=\frac{1}{4}\{1+(-i)+(-1)+i\}\\
&=\frac{1}{4}\cdot 0\\
&=0
\end{aligned}
$$

### n=1

$$
\begin{aligned}
f(1)
&=\frac{1}{4}\{1\cdot1+(-i)\cdot i+(-1)\cdot(-1)+i\cdot(-i)\}\\
&=\frac{1}{4}\{1+1+1+1\}\\
&=1
\end{aligned}
$$

### n=2

$$
\begin{aligned}
f(2)
&=\frac{1}{4}\{1\cdot1+(-i)\cdot(-1)+(-1)\cdot1+i\cdot(-1)\}\\
&=\frac{1}{4}\{1+i-1-i\}\\
&=0
\end{aligned}
$$

### n=3

$$
\begin{aligned}
f(3)
&=\frac{1}{4}\{1\cdot1+(-i)\cdot(-i)+(-1)\cdot(-1)+i\cdot i\}\\
&=\frac{1}{4}\{1-1+1-1\}\\
&=0
\end{aligned}
$$

## 答え

$$
\{f(0),f(1),f(2),f(3)\}=\{0,1,0,0\}
$$

## 口頭説明

IDFTはDFTの逆変換なので、周波数成分からもとの列を戻す計算です。4点の場合は、指数の部分が \(i^{nk}\) になるので、\(1,i,-1,-i\) の表を使って計算します。各 \(n\) について4つの項を足し、最後に \(1/4\) をかけると、\(\{0,1,0,0\}\) に戻ります。
