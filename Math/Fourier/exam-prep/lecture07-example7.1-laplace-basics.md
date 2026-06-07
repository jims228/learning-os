# Lecture 7 Example 7.1: ラプラス変換の基本

作成日: 2026-06-07

## 問題

次のラプラス変換を求める。

$$
\mathcal{L}\{1\},\qquad
\mathcal{L}\{t\},\qquad
\mathcal{L}\{e^{at}\}
$$

## ラプラス変換とは

ラプラス変換は、時間 \(t\) の関数を、\(s\) の式に変える計算。

試験では、微分方程式や時間シフトを扱いやすくするための変換として使う。

## 使う公式

ラプラス変換の定義は、

$$
\mathcal{L}\{f(t)\}
=
\int_0^\infty f(t)e^{-st}\,dt
$$

である。

## 1. \(\mathcal{L}\{1\}\)

定義に \(f(t)=1\) を入れる。

$$
\begin{aligned}
\mathcal{L}\{1\}
&=\int_0^\infty 1\cdot e^{-st}\,dt\\
&=\int_0^\infty e^{-st}\,dt
\end{aligned}
$$

積分すると、

$$
\int e^{-st}\,dt=-\frac{1}{s}e^{-st}
$$

したがって、

$$
\begin{aligned}
\mathcal{L}\{1\}
&=\left[-\frac{1}{s}e^{-st}\right]_0^\infty\\
&=0-\left(-\frac{1}{s}\right)\\
&=\frac{1}{s}
\end{aligned}
$$

答え:

$$
\mathcal{L}\{1\}=\frac{1}{s}
$$

## 2. \(\mathcal{L}\{t\}\)

定義に \(f(t)=t\) を入れる。

$$
\mathcal{L}\{t\}
=
\int_0^\infty t e^{-st}\,dt
$$

これは部分積分で計算する。

結果として、

$$
\mathcal{L}\{t\}=\frac{1}{s^2}
$$

試験では、まずこの形を覚えて使えればよい。

## 3. \(\mathcal{L}\{e^{at}\}\)

定義に \(f(t)=e^{at}\) を入れる。

$$
\begin{aligned}
\mathcal{L}\{e^{at}\}
&=\int_0^\infty e^{at}e^{-st}\,dt\\
&=\int_0^\infty e^{-(s-a)t}\,dt
\end{aligned}
$$

ここで、\(e^{at}\) と \(e^{-st}\) をかけると、

$$
e^{at}e^{-st}=e^{(a-s)t}=e^{-(s-a)t}
$$

になる。

したがって、

$$
\begin{aligned}
\mathcal{L}\{e^{at}\}
&=\int_0^\infty e^{-(s-a)t}\,dt\\
&=\frac{1}{s-a}
\end{aligned}
$$

答え:

$$
\mathcal{L}\{e^{at}\}=\frac{1}{s-a}
$$

## まとめ

この3つは暗記してよい。

$$
\mathcal{L}\{1\}=\frac{1}{s}
$$

$$
\mathcal{L}\{t\}=\frac{1}{s^2}
$$

$$
\mathcal{L}\{e^{at}\}=\frac{1}{s-a}
$$

## 口頭説明

ラプラス変換は、時間 \(t\) の関数に \(e^{-st}\) をかけて、\(0\) から \(\infty\) まで積分する変換です。定義に \(1\)、\(t\)、\(e^{at}\) を入れると、それぞれ \(\frac{1}{s}\)、\(\frac{1}{s^2}\)、\(\frac{1}{s-a}\) になります。この3つはラプラス変換の基本公式として覚えて使います。
