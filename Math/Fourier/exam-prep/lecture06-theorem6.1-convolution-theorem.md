# Lecture 6 Theorem 6.1: 畳み込み定理

作成日: 2026-06-08

## 6章で終わりか

`MA05_Review.pdf` の指定範囲では、残りは次の3つである。

1. Lecture 6 Theorem 6.1
2. Lecture 6 Example 6.3
3. Lecture 6 Example 6.4

この3つが終われば、Review 指定範囲は一通り完了する。
その後は、試験形式に近い問題で復習する。

## 何の定理か

Theorem 6.1 は、畳み込みのフーリエ変換についての定理である。

一言で言うと、

\[
\text{畳み込み}
\]

は、フーリエ変換すると、

\[
\text{かけ算}
\]

になる。

## この授業の畳み込みの定義

この授業では、畳み込みを次のように定義する。

\[
(f*g)(x)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x-t)g(t)\,dt
\]

ここで大事なのは、

\[
\frac{1}{\sqrt{2\pi}}
\]

が前についていることである。

Wikipedia などでは、この係数がない定義もある。
しかし、この授業では上の形を使う。

## Theorem 6.1

\(f\) と \(g\) が積分できる関数なら、

\[
\mathcal{F}[f*g](\omega)
=
\mathcal{F}[f](\omega)
\mathcal{F}[g](\omega)
\]

つまり、

\[
\widehat{f*g}(\omega)
=
\widehat f(\omega)\widehat g(\omega)
\]

である。

## 意味

普通に

\[
f*g
\]

を計算しようとすると、

\[
\int_{-\infty}^{\infty}
f(x-t)g(t)\,dt
\]

という積分が出てくる。

これは面倒である。

しかし、フーリエ変換を使うと、

\[
f*g
\]

のフーリエ変換は、ただの

\[
\widehat f\widehat g
\]

になる。

つまり、

\[
\text{畳み込みを計算する代わりに、変換してかけ算する}
\]

という使い方ができる。

## 証明の流れ

まずフーリエ変換の定義から始める。

\[
\mathcal{F}[f*g](\omega)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
(f*g)(x)e^{-i\omega x}\,dx
\]

畳み込みの定義を代入する。

\[
(f*g)(x)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x-t)g(t)\,dt
\]

なので、

\[
\mathcal{F}[f*g](\omega)
=
\frac{1}{2\pi}
\int_{-\infty}^{\infty}
\int_{-\infty}^{\infty}
f(x-t)g(t)e^{-i\omega x}
\,dt\,dx
\]

ここで、内側で

\[
u=x-t
\]

と置く。
すると、

\[
x=u+t
\]

である。

したがって、

\[
e^{-i\omega x}
=
e^{-i\omega(u+t)}
=
e^{-i\omega u}e^{-i\omega t}
\]

となる。

このため、積分は

\[
\int f(u)e^{-i\omega u}\,du
\]

と

\[
\int g(t)e^{-i\omega t}\,dt
\]

に分かれる。

それぞれはフーリエ変換の定義から、

\[
\int_{-\infty}^{\infty}
f(u)e^{-i\omega u}\,du
=
\sqrt{2\pi}\widehat f(\omega)
\]

\[
\int_{-\infty}^{\infty}
g(t)e^{-i\omega t}\,dt
=
\sqrt{2\pi}\widehat g(\omega)
\]

である。

よって、

\[
\mathcal{F}[f*g](\omega)
=
\frac{1}{2\pi}
\left(\sqrt{2\pi}\widehat f(\omega)\right)
\left(\sqrt{2\pi}\widehat g(\omega)\right)
\]

\[
=
\widehat f(\omega)\widehat g(\omega)
\]

となる。

## 試験での言い方

畳み込みは、関数をずらして重ね、その重なり具合を積分する操作である。
この授業の定義では、

\[
(f*g)(x)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x-t)g(t)\,dt
\]

である。
Theorem 6.1 により、畳み込みはフーリエ変換すると積になる。

\[
\mathcal{F}[f*g](\omega)
=
\mathcal{F}[f](\omega)
\mathcal{F}[g](\omega)
\]

したがって、畳み込みを直接計算する代わりに、フーリエ変換してからかけ算すればよい。

## チートシートに書くなら

\[
(f*g)(x)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x-t)g(t)\,dt
\]

\[
\mathcal{F}[f*g](\omega)
=
\mathcal{F}[f](\omega)\mathcal{F}[g](\omega)
\]

\[
\text{畳み込みは、フーリエ変換するとかけ算になる}
\]

## 注意

もし畳み込みを

\[
(f*g)(x)
=
\int_{-\infty}^{\infty}
f(x-t)g(t)\,dt
\]

と定義する流儀なら、

\[
\mathcal{F}[f*g](\omega)
=
\sqrt{2\pi}
\mathcal{F}[f](\omega)
\mathcal{F}[g](\omega)
\]

になる。

しかし、この授業のスライドでは、教科書型の定義

\[
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x-t)g(t)\,dt
\]

を使うので、

\[
\mathcal{F}[f*g]
=
\mathcal{F}[f]\mathcal{F}[g]
\]

と覚える。

## 次にやること

Lecture 6 Example 6.3 へ進む。
