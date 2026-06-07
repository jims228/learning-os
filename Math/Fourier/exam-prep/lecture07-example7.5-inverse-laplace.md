# Lecture 7 Example 7.5: 逆ラプラス変換

作成日: 2026-06-07

## 問題

次を求める。

$$
\text{(a)}\quad
\mathcal{L}^{-1}\left\{
\frac{2}{4+(s-1)^2}
\right\}
$$

$$
\text{(b)}\quad
\mathcal{L}^{-1}\left\{
\frac{1}{s^2+2s+3}
\right\}
$$

## 使う公式

まず、基本公式。

$$
\mathcal{L}\{\sin kt\}
=
\frac{k}{s^2+k^2}
$$

次に、\(s\)-軸シフト。

$$
\mathcal{L}\{e^{at}f(t)\}=F(s-a)
$$

逆向きに見ると、

$$
\mathcal{L}^{-1}\{F(s-a)\}=e^{at}f(t)
$$

## (a)

$$
\mathcal{L}^{-1}\left\{
\frac{2}{4+(s-1)^2}
\right\}
$$

分母を見やすく書く。

$$
4+(s-1)^2
=
(s-1)^2+2^2
$$

したがって、

$$
\frac{2}{4+(s-1)^2}
=
\frac{2}{(s-1)^2+2^2}
$$

基本形

$$
\mathcal{L}\{\sin 2t\}
=
\frac{2}{s^2+2^2}
$$

と比べる。

問題では \(s\) が \(s-1\) に変わっている。

$$
s-1=s-(1)
$$

なので、

$$
a=1
$$

時間側では \(e^t\) がつく。

答え:

$$
\boxed{
\mathcal{L}^{-1}\left\{
\frac{2}{4+(s-1)^2}
\right\}
=
e^t\sin 2t
}
$$

## (b)

$$
\mathcal{L}^{-1}\left\{
\frac{1}{s^2+2s+3}
\right\}
$$

まず分母を平方完成する。

$$
s^2+2s+3
=
(s+1)^2+2
$$

ここで、

$$
2=(\sqrt2)^2
$$

なので、

$$
\frac{1}{s^2+2s+3}
=
\frac{1}{(s+1)^2+(\sqrt2)^2}
$$

\(\sin kt\) の基本形は、

$$
\mathcal{L}\{\sin kt\}
=
\frac{k}{s^2+k^2}
$$

分子に \(k\) が必要。

今回は \(k=\sqrt2\) なので、

$$
\frac{1}{(s+1)^2+(\sqrt2)^2}
=
\frac{1}{\sqrt2}
\cdot
\frac{\sqrt2}{(s+1)^2+(\sqrt2)^2}
$$

基本形より、

$$
\frac{\sqrt2}{s^2+(\sqrt2)^2}
\quad\Longleftrightarrow\quad
\sin(\sqrt2 t)
$$

問題では \(s\) が \(s+1\) に変わっている。

$$
s+1=s-(-1)
$$

なので、

$$
a=-1
$$

時間側では \(e^{-t}\) がつく。

答え:

$$
\boxed{
\mathcal{L}^{-1}\left\{
\frac{1}{s^2+2s+3}
\right\}
=
\frac{1}{\sqrt2}e^{-t}\sin(\sqrt2 t)
}
$$

## 口頭説明

Example 7.5 は、まず分母を \((s-a)^2+k^2\) の形に直す問題です。(a) は \((s-1)^2+2^2\) なので、\(\sin 2t\) に \(e^t\) がついて \(e^t\sin2t\) になります。(b) は平方完成して \((s+1)^2+(\sqrt2)^2\) に直し、分子を \(\sqrt2\) に合わせるために \(\frac{1}{\sqrt2}\) を外へ出します。\(s+1=s-(-1)\) なので \(e^{-t}\) がつき、答えは \(\frac{1}{\sqrt2}e^{-t}\sin(\sqrt2 t)\) です。
