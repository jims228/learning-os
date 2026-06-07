# Lecture 10 Theorem 10.2: 畳み込みとラプラス変換

作成日: 2026-06-07

## 範囲

Review指定:

- Theorem 10.2 and its Proof

関連例題:

- Example 10.6: 畳み込み形の積分をラプラス変換する
- Example 10.7: ODEの解を畳み込みで表す

## 畳み込みの定義

2つの関数 \(f(t)\), \(g(t)\) の畳み込みを、

$$
(f*g)(t)
=
\int_0^t f(t-\tau)g(\tau)\,d\tau
$$

で定義する。

見分けるポイントは、

$$
\int_0^t f(t-\tau)g(\tau)\,d\tau
$$

という形になっていること。

## Theorem 10.2

もし、

$$
F(s)=\mathcal{L}\{f(t)\},
\qquad
G(s)=\mathcal{L}\{g(t)\}
$$

なら、

$$
\mathcal{L}\{(f*g)(t)\}
=
F(s)G(s)
$$

つまり、

$$
\boxed{
\mathcal{L}\{f*g\}
=
\mathcal{L}\{f\}\mathcal{L}\{g\}
}
$$

である。

逆向きには、

$$
\mathcal{L}^{-1}\{F(s)G(s)\}
=
f*g
$$

となる。

## 証明の要点

定義から、

$$
\mathcal{L}\{f*g\}
=
\int_0^\infty
\left(
\int_0^t f(t-\tau)g(\tau)\,d\tau
\right)
e^{-st}\,dt
$$

である。

積分の順番を入れ替え、\(u=t-\tau\) と置くと、

$$
e^{-st}=e^{-s(u+\tau)}=e^{-su}e^{-s\tau}
$$

に分かれる。

その結果、

$$
\int_0^\infty f(u)e^{-su}\,du
\cdot
\int_0^\infty g(\tau)e^{-s\tau}\,d\tau
$$

となり、

$$
\mathcal{L}\{f\}\mathcal{L}\{g\}
$$

になる。

## Example 10.6

次を求める。

$$
\mathcal{L}
\left\{
\int_0^t (t-\tau)\sin \tau\,d\tau
\right\}
$$

積分の中を見る。

$$
(t-\tau)\sin \tau
$$

これは、

$$
f(t-\tau)g(\tau)
$$

の形で、

$$
f(t)=t,
\qquad
g(t)=\sin t
$$

である。

したがって、

$$
\int_0^t (t-\tau)\sin \tau\,d\tau
=
(t*\sin t)(t)
$$

Theorem 10.2 より、

$$
\mathcal{L}\{t*\sin t\}
=
\mathcal{L}\{t\}\mathcal{L}\{\sin t\}
$$

基本公式を使う。

$$
\mathcal{L}\{t\}=\frac{1}{s^2}
$$

$$
\mathcal{L}\{\sin t\}=\frac{1}{s^2+1}
$$

したがって、

$$
\boxed{
\mathcal{L}
\left\{
\int_0^t (t-\tau)\sin \tau\,d\tau
\right\}
=
\frac{1}{s^2(s^2+1)}
}
$$

## Example 10.7 の見方

Lecture 10 では、ODEの解を畳み込みで表す例も扱う。

問題:

$$
y''-2y'+5y=f(t),
\qquad
y(0)=0,\qquad
y'(0)=0
$$

ラプラス変換すると、

$$
(s^2-2s+5)Y(s)=L(s)
$$

ここで、

$$
L(s)=\mathcal{L}\{f(t)\}
$$

である。

したがって、

$$
Y(s)
=
L(s)\frac{1}{s^2-2s+5}
$$

分母を平方完成する。

$$
s^2-2s+5=(s-1)^2+2^2
$$

よって、

$$
\frac{1}{s^2-2s+5}
=
\frac{1}{2}\frac{2}{(s-1)^2+2^2}
$$

逆ラプラス変換すると、

$$
\frac{1}{2}e^t\sin 2t
$$

なので、Theorem 10.2 より、

$$
y(t)
=
f(t)*\frac{1}{2}e^t\sin 2t
$$

すなわち、

$$
\boxed{
y(t)
=
\frac{1}{2}
\int_0^t
e^{t-\tau}\sin 2(t-\tau)f(\tau)\,d\tau
}
$$

## 口頭説明

畳み込みは \(\int_0^t f(t-\tau)g(\tau)\,d\tau\) の形の積分です。Theorem 10.2 により、畳み込みのラプラス変換は、それぞれのラプラス変換の積になります。Example 10.6 では、\((t-\tau)\sin\tau\) を \(f(t-\tau)g(\tau)\) と見て、\(f(t)=t\)、\(g(t)=\sin t\) と置きます。したがって答えは \(\mathcal{L}\{t\}\mathcal{L}\{\sin t\}=\frac{1}{s^2(s^2+1)}\) です。
