# Lecture 6 Example 6.4: 長方形関数の畳み込み

作成日: 2026-06-08

## 問題

次の関数を考える。

\[
f(x)=
\begin{cases}
1 & (|x|<1)\\
0 & (\text{otherwise})
\end{cases}
\]

このとき、

\[
f*f
\]

を求める。

## 先に結論

答えは三角形の関数になる。

\[
(f*f)(x)
=
\begin{cases}
\sqrt{\frac{2}{\pi}}
\left(1-\frac{|x|}{2}\right)
& (|x|<2)\\
0 & (|x|>2)
\end{cases}
\]

端点 \(x=\pm2\) の値は試験ではあまり重要ではない。

## 何をしている問題か

\(f(x)\) は、\(-1<x<1\) だけ高さ 1 の長方形である。

\[
f*f
\]

は、長方形を自分自身と畳み込む計算である。

イメージとしては、

\[
\text{長方形をずらして、どれくらい重なるかを見る}
\]

という問題。

重なりが最大のときは \(x=0\)。
ずらしていくと重なりが減っていき、\(|x|=2\) で重なりが 0 になる。

そのため、答えは三角形になる。

## 使う公式

この授業の畳み込みは、

\[
(f*g)(x)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x-t)g(t)\,dt
\]

である。

また、畳み込み定理より、

\[
\mathcal{F}[f*g](\omega)
=
\mathcal{F}[f](\omega)\mathcal{F}[g](\omega)
\]

である。

今回 \(g=f\) なので、

\[
\mathcal{F}[f*f](\omega)
=
\{\mathcal{F}[f](\omega)\}^2
\]

となる。

## Step 1: \(f\) のフーリエ変換を使う

Example 5.3 より、

\[
\widehat f(\omega)
=
\sqrt{\frac{2}{\pi}}
\frac{\sin\omega}{\omega}
\]

である。

これは、\(-1<x<1\) の長方形関数のフーリエ変換である。

## Step 2: 畳み込み定理を使う

畳み込み定理より、

\[
\mathcal{F}[f*f](\omega)
=
\widehat f(\omega)\widehat f(\omega)
\]

つまり、

\[
\mathcal{F}[f*f](\omega)
=
\{\widehat f(\omega)\}^2
\]

である。

ここに、

\[
\widehat f(\omega)
=
\sqrt{\frac{2}{\pi}}
\frac{\sin\omega}{\omega}
\]

を代入する。

\[
\mathcal{F}[f*f](\omega)
=
\left(
\sqrt{\frac{2}{\pi}}
\frac{\sin\omega}{\omega}
\right)^2
\]

よって、

\[
\mathcal{F}[f*f](\omega)
=
\frac{2}{\pi}
\frac{\sin^2\omega}{\omega^2}
\]

となる。

## Step 3: 逆フーリエ変換で戻す

フーリエ変換表を見ると、

\[
\frac{2}{\pi}
\frac{\sin^2\omega}{\omega^2}
\]

に対応する関数は、三角形の関数である。

したがって、

\[
(f*f)(x)
=
\begin{cases}
\sqrt{\frac{2}{\pi}}
\left(1-\frac{|x|}{2}\right)
& (|x|<2)\\
0 & (|x|>2)
\end{cases}
\]

となる。

## 重なりで見る説明

公式だけだと見えにくいので、直感でも確認する。

この授業の定義では、

\[
(f*f)(x)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x-t)f(t)\,dt
\]

である。

\(f(t)\) は、

\[
-1<t<1
\]

で 1 になる。

また、\(f(x-t)\) も、ある範囲で 1 になる。

積

\[
f(x-t)f(t)
\]

は、両方が 1 のところだけ 1 になる。

つまり、積分しているものは

\[
\text{2つの長方形が重なっている長さ}
\]

を表している。

その重なりの長さは、

\[
2-|x|
\]

である。ただし、これは

\[
|x|<2
\]

のときだけ。

\(|x|>2\) では重ならないので 0。

したがって、

\[
(f*f)(x)
=
\frac{1}{\sqrt{2\pi}}(2-|x|)
\qquad (|x|<2)
\]

である。

これを少し変形すると、

\[
\frac{1}{\sqrt{2\pi}}(2-|x|)
=
\sqrt{\frac{2}{\pi}}
\left(1-\frac{|x|}{2}\right)
\]

となる。

## 試験での書き方

まず Example 5.3 より、

\[
\widehat f(\omega)
=
\sqrt{\frac{2}{\pi}}
\frac{\sin\omega}{\omega}
\]

である。

畳み込み定理より、

\[
\mathcal{F}[f*f](\omega)
=
\{\widehat f(\omega)\}^2
\]

だから、

\[
\mathcal{F}[f*f](\omega)
=
\frac{2}{\pi}
\frac{\sin^2\omega}{\omega^2}
\]

である。

これを逆フーリエ変換すると、

\[
(f*f)(x)
=
\begin{cases}
\sqrt{\frac{2}{\pi}}
\left(1-\frac{|x|}{2}\right)
& (|x|<2)\\
0 & (|x|>2)
\end{cases}
\]

となる。

## チートシートに書くなら

\[
f(x)=1\quad(|x|<1)
\]

\[
\widehat f(\omega)
=
\sqrt{\frac{2}{\pi}}
\frac{\sin\omega}{\omega}
\]

\[
\mathcal{F}[f*f]
=
(\widehat f)^2
\]

\[
(f*f)(x)
=
\begin{cases}
\sqrt{\frac{2}{\pi}}
\left(1-\frac{|x|}{2}\right)
& (|x|<2)\\
0 & (|x|>2)
\end{cases}
\]

## 証明問題を捨てる場合の方針

証明問題を全部深追いするより、次のように優先する。

1. 計算問題を最優先する。
2. 証明は、Theorem 6.1 や Example 6.3 のような短いテンプレだけ覚える。
3. 長い積分証明は、時間がなければ後回しにする。

Example 6.4 は計算問題として出やすいので、捨てないほうがよい。

## 次にやること

Review 指定範囲は一周完了。
次は、試験で点にしやすい順に総復習する。
