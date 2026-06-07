# Lecture 5 Theorem 5.2: フーリエ変換の線形性

作成日: 2026-06-08

## 何の定理か

Theorem 5.2 は、フーリエ変換が線形であることを言っている。

線形とは、ざっくり言うと、

\[
\text{足し算と定数倍をそのまま外に出せる}
\]

という意味である。

## 定理

\(f(x)\), \(g(x)\) をフーリエ変換できる関数とする。

また、\(\alpha,\beta\) を定数とする。

このとき、

\[
\mathcal{F}[\alpha f+\beta g]
=
\alpha\mathcal{F}[f]
+
\beta\mathcal{F}[g]
\]

が成り立つ。

つまり、

\[
\widehat{\alpha f+\beta g}(\omega)
=
\alpha\widehat f(\omega)
+
\beta\widehat g(\omega)
\]

である。

## 使う公式

この授業のフーリエ変換は、

\[
\widehat f(\omega)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x)e^{-i\omega x}\,dx
\]

である。

## 証明

左辺から始める。

\[
\mathcal{F}[\alpha f+\beta g](\omega)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
\{\alpha f(x)+\beta g(x)\}
e^{-i\omega x}\,dx
\]

積分の中を分ける。

\[
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
\alpha f(x)e^{-i\omega x}\,dx
+
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
\beta g(x)e^{-i\omega x}\,dx
\]

定数 \(\alpha,\beta\) は積分の外に出せる。

\[
=
\alpha
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x)e^{-i\omega x}\,dx
+
\beta
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
g(x)e^{-i\omega x}\,dx
\]

ここで、

\[
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x)e^{-i\omega x}\,dx
=
\widehat f(\omega)
\]

\[
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
g(x)e^{-i\omega x}\,dx
=
\widehat g(\omega)
\]

なので、

\[
\mathcal{F}[\alpha f+\beta g](\omega)
=
\alpha\widehat f(\omega)
+
\beta\widehat g(\omega)
\]

したがって、

\[
\mathcal{F}[\alpha f+\beta g]
=
\alpha\mathcal{F}[f]
+
\beta\mathcal{F}[g]
\]

である。

## 何がうれしいか

複雑な関数が、

\[
h(x)=3f(x)-2g(x)
\]

のように分解できるとする。

もし

\[
\mathcal{F}[f]
\]

と

\[
\mathcal{F}[g]
\]

が分かっていれば、

\[
\mathcal{F}[h]
=
3\mathcal{F}[f]
-
2\mathcal{F}[g]
\]

とすぐ出せる。

最初から全部積分し直さなくてよい。

## 例

もし、

\[
\mathcal{F}[f](\omega)=A(\omega)
\]

\[
\mathcal{F}[g](\omega)=B(\omega)
\]

が分かっているなら、

\[
\mathcal{F}[2f-5g](\omega)
=
2A(\omega)-5B(\omega)
\]

である。

## フーリエ級数とのつながり

Lecture 2 Example 2.4 で、

\[
h(x)=f(x)+\frac{1}{2}g(x)
\]

なら、フーリエ級数も同じように足せる、という話を使った。

フーリエ変換でも同じである。

\[
\mathcal{F}\left[f+\frac{1}{2}g\right]
=
\mathcal{F}[f]
+
\frac{1}{2}\mathcal{F}[g]
\]

となる。

## 試験での出方

英語では、次のように出る可能性がある。

```text
State and prove the linearity of the Fourier transform.
```

この場合は、

\[
\mathcal{F}[\alpha f+\beta g]
=
\alpha\mathcal{F}[f]
+
\beta\mathcal{F}[g]
\]

を書いてから、定義に代入して積分を分ければよい。

また、

```text
Use linearity to find the Fourier transform.
```

と出た場合は、関数を足し算と定数倍に分けて、既知の変換を組み合わせる。

## 間違えやすいこと

線形性で言えるのは、

\[
\mathcal{F}[\alpha f+\beta g]
=
\alpha\mathcal{F}[f]+\beta\mathcal{F}[g]
\]

である。

掛け算について、

\[
\mathcal{F}[fg]
=
\mathcal{F}[f]\mathcal{F}[g]
\]

とは言えない。

掛け算や畳み込みは別の定理で扱う。

## 口頭説明用

フーリエ変換の線形性とは、関数の定数倍と足し算が、フーリエ変換の後でもそのまま保たれるという性質である。
つまり、

\[
\mathcal{F}[\alpha f+\beta g]
=
\alpha\mathcal{F}[f]+\beta\mathcal{F}[g]
\]

である。
証明は、フーリエ変換の定義に \(\alpha f+\beta g\) を代入して、積分を分け、定数を外に出すだけでよい。
この性質を使うと、複雑な関数を簡単な関数の和として分解してから、変換を足し合わせられる。
