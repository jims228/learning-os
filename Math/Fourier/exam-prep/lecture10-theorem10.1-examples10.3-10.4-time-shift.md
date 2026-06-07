# Lecture 10 Theorem 10.1 / Example 10.3 / Example 10.4

作成日: 2026-06-07

## 範囲

Review指定:

- Theorem 10.1
- Example 10.3
- Example 10.4

テーマ:

- 単位ステップ関数 \(u(t-a)\)
- \(t\)-軸シフト
- 区間だけ値を持つ関数
- ランプ関数

## Theorem 10.1: \(t\)-軸シフト

もし、

$$
L(s)=\mathcal{L}\{f(t)\}
$$

なら、

$$
\mathcal{L}\{u(t-a)f(t-a)\}
=
e^{-as}L(s)
$$

である。

逆向きには、

$$
\mathcal{L}^{-1}\{e^{-as}L(s)\}
=
u(t-a)f(t-a)
$$

になる。

## 覚え方

\(e^{-as}\) があるとき、時間側では \(a\) だけ右にずれる。

つまり、

$$
e^{-as}
\quad\Longleftrightarrow\quad
u(t-a)f(t-a)
$$

である。

## Example 10.3(a): \(\mathcal{L}\{u(t-a)\}\)

\(u(t-a)\) は、\(t<a\) では0、\(t\ge a\) では1。

したがって、

$$
\mathcal{L}\{u(t-a)\}
=
\frac{e^{-as}}{s}
$$

答え:

$$
\boxed{
\mathcal{L}\{u(t-a)\}
=
\frac{e^{-as}}{s}
}
$$

## Example 10.3(b): 区間だけ値を持つ関数

問題:

$$
f(t)=
\begin{cases}
2, & 1\le t<4\\
0, & \text{otherwise}
\end{cases}
$$

これは、\(t=1\) で高さ2に上がり、\(t=4\) で0に戻る関数。

単位ステップで書くと、

$$
f(t)=2\{u(t-1)-u(t-4)\}
$$

なぜなら、

- \(t<1\): \(u(t-1)=0\), \(u(t-4)=0\) なので \(0\)
- \(1\le t<4\): \(u(t-1)=1\), \(u(t-4)=0\) なので \(2\)
- \(t\ge4\): \(u(t-1)=1\), \(u(t-4)=1\) なので \(0\)

ラプラス変換する。

$$
\begin{aligned}
\mathcal{L}\{f(t)\}
&=
2\left(
\mathcal{L}\{u(t-1)\}
-
\mathcal{L}\{u(t-4)\}
\right)\\
&=
2\left(
\frac{e^{-s}}{s}
-
\frac{e^{-4s}}{s}
\right)
\end{aligned}
$$

答え:

$$
\boxed{
\mathcal{L}\{f(t)\}
=
\frac{2}{s}\left(e^{-s}-e^{-4s}\right)
}
$$

## Example 10.4: ランプ関数

図の関数は、

$$
f(t)=
\begin{cases}
t, & 0\le t<1\\
1, & t\ge 1
\end{cases}
$$

である。

これは、最初は \(t\) として増え、\(t=1\) からは1で止まる関数。

ステップ関数で書くと、

$$
f(t)=t\{u(t)-u(t-1)\}+u(t-1)
$$

ここで、\(u(t)=1\) と見てよいので、次のように変形する。

$$
\begin{aligned}
f(t)
&=t-t\,u(t-1)+u(t-1)\\
&=t-(t-1)u(t-1)
\end{aligned}
$$

したがって、

$$
\mathcal{L}\{f(t)\}
=
\mathcal{L}\{t\}
-
\mathcal{L}\{(t-1)u(t-1)\}
$$

基本公式より、

$$
\mathcal{L}\{t\}=\frac{1}{s^2}
$$

また、Theorem 10.1より、

$$
\mathcal{L}\{(t-1)u(t-1)\}
=
e^{-s}\mathcal{L}\{t\}
=
\frac{e^{-s}}{s^2}
$$

したがって、

$$
\boxed{
\mathcal{L}\{f(t)\}
=
\frac{1}{s^2}
-
\frac{e^{-s}}{s^2}
=
\frac{1-e^{-s}}{s^2}
}
$$

## 口頭説明

Theorem 10.1 は、\(u(t-a)f(t-a)\) のラプラス変換が \(e^{-as}L(s)\) になるという時間シフトの公式です。Example 10.3 では、区間 \(1\le t<4\) だけ高さ2の関数を \(2(u(t-1)-u(t-4))\) と書きます。したがってラプラス変換は \(\frac{2}{s}(e^{-s}-e^{-4s})\) です。Example 10.4 のランプ関数は、\(f(t)=t-(t-1)u(t-1)\) と直して、\(\frac{1}{s^2}-\frac{e^{-s}}{s^2}\) を得ます。
