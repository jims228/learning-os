# Lecture 5 Theorem 5.3: 導関数のフーリエ変換

作成日: 2026-06-08

## 何の定理か

Theorem 5.3 は、微分した関数のフーリエ変換についての公式である。

結論だけ言うと、微分はフーリエ変換の世界では

\[
i\omega
\]

をかける操作になる。

## 一番大事な公式

\[
\mathcal{F}[f'](\omega)
=
i\omega\mathcal{F}[f](\omega)
\]

つまり、

\[
\widehat{f'}(\omega)
=
i\omega\widehat f(\omega)
\]

である。

## 2階微分の場合

もう一度微分すると、

\[
\mathcal{F}[f''](\omega)
=
(i\omega)^2\widehat f(\omega)
\]

ここで、

\[
i^2=-1
\]

なので、

\[
(i\omega)^2
=
-\omega^2
\]

したがって、

\[
\mathcal{F}[f''](\omega)
=
-\omega^2\widehat f(\omega)
\]

である。

## 一般形

\(n\) 回微分なら、

\[
\mathcal{F}[f^{(n)}](\omega)
=
(i\omega)^n\widehat f(\omega)
\]

となる。

## 使う条件

厳密には、次のような条件が必要である。

\[
f(x)\to0
\qquad
(|x|\to\infty)
\]

かつ、\(f\) やその導関数が積分できること。

試験で大事なのは、

\[
\text{端で 0 になるから、境界項が消える}
\]

という点である。

## 証明の流れ

公式

\[
\mathcal{F}[f'](\omega)
=
i\omega\widehat f(\omega)
\]

を証明する。

フーリエ変換の定義から、

\[
\mathcal{F}[f'](\omega)
=
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f'(x)e^{-i\omega x}\,dx
\]

である。

ここで部分積分を使う。

\[
u=e^{-i\omega x},
\qquad
dv=f'(x)\,dx
\]

と置く。

すると、

\[
du=-i\omega e^{-i\omega x}\,dx
\]

\[
v=f(x)
\]

である。

部分積分より、

\[
\int u\,dv
=
uv-\int v\,du
\]

なので、

\[
\int_{-\infty}^{\infty}
f'(x)e^{-i\omega x}\,dx
=
\left[
f(x)e^{-i\omega x}
\right]_{-\infty}^{\infty}
-
\int_{-\infty}^{\infty}
f(x)(-i\omega e^{-i\omega x})\,dx
\]

第1項は、\(f(x)\to0\) なので消える。

\[
\left[
f(x)e^{-i\omega x}
\right]_{-\infty}^{\infty}
=
0
\]

したがって、

\[
\int_{-\infty}^{\infty}
f'(x)e^{-i\omega x}\,dx
=
i\omega
\int_{-\infty}^{\infty}
f(x)e^{-i\omega x}\,dx
\]

両辺に

\[
\frac{1}{\sqrt{2\pi}}
\]

をつけると、

\[
\mathcal{F}[f'](\omega)
=
i\omega
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x)e^{-i\omega x}\,dx
\]

ここで、

\[
\frac{1}{\sqrt{2\pi}}
\int_{-\infty}^{\infty}
f(x)e^{-i\omega x}\,dx
=
\widehat f(\omega)
\]

なので、

\[
\mathcal{F}[f'](\omega)
=
i\omega\widehat f(\omega)
\]

となる。

## どう使うか

たとえば、

\[
\widehat f(\omega)
=
\frac{1}{1+\omega^2}
\]

が分かっているとする。

このとき、

\[
\mathcal{F}[f'](\omega)
=
i\omega
\frac{1}{1+\omega^2}
\]

である。

また、

\[
\mathcal{F}[f''](\omega)
=
-\omega^2
\frac{1}{1+\omega^2}
\]

となる。

## 微分方程式での意味

この定理は、微分方程式をフーリエ変換で解くときに重要である。

たとえば、

\[
f''(x)-f(x)=g(x)
\]

のような式をフーリエ変換すると、

\[
-\omega^2\widehat f(\omega)-\widehat f(\omega)
=
\widehat g(\omega)
\]

のように、微分が \(\omega\) の掛け算に変わる。

つまり、微分方程式が代数方程式のように扱える。

## 試験での出方

英語では、次のように出る可能性がある。

```text
State the Fourier transform of derivatives.
```

この場合は、

\[
\mathcal{F}[f'](\omega)=i\omega\widehat f(\omega)
\]

\[
\mathcal{F}[f''](\omega)=-\omega^2\widehat f(\omega)
\]

を書けばよい。

また、

```text
Prove the formula for \(\mathcal{F}[f']\).
```

と出たら、部分積分で証明する。

## ラプラス変換との違い

ラプラス変換では、

\[
\mathcal{L}[f']
=
sF(s)-f(0)
\]

のように初期値が出てきた。

一方、フーリエ変換では、

\[
\mathcal{F}[f']
=
i\omega\widehat f
\]

である。

これは、\(-\infty\) から \(\infty\) まで考えて、端で \(f(x)\to0\) としているため、境界項が消えるからである。

## 覚える形

\[
f'
\quad\Longrightarrow\quad
i\omega\widehat f
\]

\[
f''
\quad\Longrightarrow\quad
-\omega^2\widehat f
\]

\[
f^{(n)}
\quad\Longrightarrow\quad
(i\omega)^n\widehat f
\]

## 口頭説明用

Theorem 5.3 は、導関数のフーリエ変換の公式である。
微分はフーリエ変換すると \(i\omega\) をかける操作になる。
したがって、

\[
\mathcal{F}[f'](\omega)=i\omega\widehat f(\omega)
\]

であり、2階微分なら

\[
\mathcal{F}[f''](\omega)=-\omega^2\widehat f(\omega)
\]

である。
証明は部分積分を使う。
端で \(f(x)\to0\) なので境界項が消え、残った積分が \(i\omega\widehat f(\omega)\) になる。
