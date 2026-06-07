# Lecture 7 Example 7.3 と Assignment 7: sin/cos のラプラス変換

作成日: 2026-06-07

## 範囲

Review指定:

- Lecture 7 Example 7.3

Assignment 7 で関連する問題:

- \(\mathcal{L}\{2t+3\}\)
- \(\mathcal{L}\{t\sin 4t\}\)
- \(\mathcal{L}^{-1}\left\{\frac{1}{s^2}\right\}\)
- \(\mathcal{L}^{-1}\left\{\frac{s}{s^2+2s+1}\right\}\)

## Example 7.3: \(\cos kt\) と \(\sin kt\)

### 覚える公式

$$
\mathcal{L}\{\cos kt\}
=
\frac{s}{s^2+k^2}
$$

$$
\mathcal{L}\{\sin kt\}
=
\frac{k}{s^2+k^2}
$$

### 例

\(k=4\) なら、

$$
\mathcal{L}\{\cos 4t\}
=
\frac{s}{s^2+16}
$$

$$
\mathcal{L}\{\sin 4t\}
=
\frac{4}{s^2+16}
$$

## なぜこの形になるか

オイラーの公式より、

$$
e^{ikt}=\cos kt+i\sin kt
$$

両辺をラプラス変換すると、

$$
\mathcal{L}\{\cos kt\}
+
i\mathcal{L}\{\sin kt\}
=
\mathcal{L}\{e^{ikt}\}
$$

指数関数の公式

$$
\mathcal{L}\{e^{at}\}
=
\frac{1}{s-a}
$$

に \(a=ik\) を入れると、

$$
\mathcal{L}\{e^{ikt}\}
=
\frac{1}{s-ik}
$$

分母を実数化する。

$$
\frac{1}{s-ik}
=
\frac{s+ik}{(s-ik)(s+ik)}
=
\frac{s+ik}{s^2+k^2}
$$

したがって、

$$
\frac{s+ik}{s^2+k^2}
=
\frac{s}{s^2+k^2}
+
i\frac{k}{s^2+k^2}
$$

実部と虚部を比べると、

$$
\mathcal{L}\{\cos kt\}
=
\frac{s}{s^2+k^2}
$$

$$
\mathcal{L}\{\sin kt\}
=
\frac{k}{s^2+k^2}
$$

になる。

## Assignment 7 問1(a): \(\mathcal{L}\{2t+3\}\)

線形性を使う。

$$
\mathcal{L}\{2t+3\}
=
2\mathcal{L}\{t\}
+
3\mathcal{L}\{1\}
$$

基本公式より、

$$
\mathcal{L}\{t\}=\frac{1}{s^2},
\qquad
\mathcal{L}\{1\}=\frac{1}{s}
$$

したがって、

$$
\boxed{
\mathcal{L}\{2t+3\}
=
\frac{2}{s^2}
+
\frac{3}{s}
}
$$

## Assignment 7 問1(b): \(\mathcal{L}\{t\sin 4t\}\)

ここでは、Lecture 7 の「ラプラス変換の微分」を使う。

$$
\mathcal{L}\{t f(t)\}
=
-\frac{d}{ds}\mathcal{L}\{f(t)\}
$$

まず、

$$
\mathcal{L}\{\sin 4t\}
=
\frac{4}{s^2+16}
$$

なので、

$$
\mathcal{L}\{t\sin 4t\}
=
-\frac{d}{ds}
\left(
\frac{4}{s^2+16}
\right)
$$

微分すると、

$$
\frac{d}{ds}
\left(
\frac{4}{s^2+16}
\right)
=
-\frac{8s}{(s^2+16)^2}
$$

したがって、

$$
\boxed{
\mathcal{L}\{t\sin 4t\}
=
\frac{8s}{(s^2+16)^2}
}
$$

## Assignment 7 問2(a): \(\mathcal{L}^{-1}\left\{\frac{1}{s^2}\right\}\)

基本公式

$$
\mathcal{L}\{t\}=\frac{1}{s^2}
$$

を逆向きに使う。

$$
\boxed{
\mathcal{L}^{-1}\left\{\frac{1}{s^2}\right\}
=
t
}
$$

## Assignment 7 問2(b): \(\mathcal{L}^{-1}\left\{\frac{s}{s^2+2s+1}\right\}\)

まず分母を整理する。

$$
s^2+2s+1=(s+1)^2
$$

したがって、

$$
\frac{s}{s^2+2s+1}
=
\frac{s}{(s+1)^2}
$$

ここで、分子の \(s\) を \(s+1-1\) と書き換える。

$$
s=(s+1)-1
$$

よって、

$$
\frac{s}{(s+1)^2}
=
\frac{s+1}{(s+1)^2}
-
\frac{1}{(s+1)^2}
$$

つまり、

$$
\frac{s}{(s+1)^2}
=
\frac{1}{s+1}
-
\frac{1}{(s+1)^2}
$$

公式を逆向きに使う。

$$
\mathcal{L}^{-1}\left\{\frac{1}{s+1}\right\}
=
e^{-t}
$$

$$
\mathcal{L}^{-1}\left\{\frac{1}{(s+1)^2}\right\}
=
te^{-t}
$$

したがって、

$$
\boxed{
\mathcal{L}^{-1}\left\{\frac{s}{s^2+2s+1}\right\}
=
e^{-t}-te^{-t}
=
(1-t)e^{-t}
}
$$

## 口頭説明

\(\sin kt\) と \(\cos kt\) のラプラス変換は公式として覚えてよいです。\(\cos kt\) は \(\frac{s}{s^2+k^2}\)、\(\sin kt\) は \(\frac{k}{s^2+k^2}\) です。Assignment 7 の \(t\sin 4t\) は、まず \(\mathcal{L}\{\sin 4t\}=\frac{4}{s^2+16}\) を作り、それを \(s\) で微分してマイナスをつけます。だから答えは \(\frac{8s}{(s^2+16)^2}\) です。
