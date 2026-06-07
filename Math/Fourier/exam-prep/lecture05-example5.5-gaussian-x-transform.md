# Lecture 5 Example 5.5: \(xe^{-x^2}\) のフーリエ変換

作成日: 2026-06-08

## 問題

次の関数のフーリエ変換を求める。

\[
xe^{-x^2}
\]

## 先に結論

\[
\mathcal{F}[xe^{-x^2}](\omega)
=
-\frac{i\omega}{2\sqrt{2}}
e^{-\omega^2/4}
\]

## この問題で使う考え方

この問題は、直接積分で解くよりも、次の形に直すと楽である。

\[
xe^{-x^2}
=
-\frac{1}{2}
(e^{-x^2})'
\]

なぜなら、

\[
(e^{-x^2})'
=
-2xe^{-x^2}
\]

だからである。

両辺に

\[
-\frac{1}{2}
\]

をかけると、

\[
-\frac{1}{2}(e^{-x^2})'
=
xe^{-x^2}
\]

となる。

## 使う公式

微分のフーリエ変換は、

\[
\mathcal{F}[f'](\omega)
=
i\omega\mathcal{F}[f](\omega)
\]

である。

また、ガウス関数のフーリエ変換として、

\[
\mathcal{F}[e^{-x^2}](\omega)
=
\frac{1}{\sqrt{2}}
e^{-\omega^2/4}
\]

を使う。

## 計算

まず、

\[
xe^{-x^2}
=
-\frac{1}{2}
(e^{-x^2})'
\]

なので、

\[
\mathcal{F}[xe^{-x^2}](\omega)
=
\mathcal{F}\left[
-\frac{1}{2}
(e^{-x^2})'
\right](\omega)
\]

定数は外に出せるので、

\[
=
-\frac{1}{2}
\mathcal{F}[(e^{-x^2})'](\omega)
\]

ここで微分の公式を使う。

\[
\mathcal{F}[(e^{-x^2})'](\omega)
=
i\omega
\mathcal{F}[e^{-x^2}](\omega)
\]

したがって、

\[
\mathcal{F}[xe^{-x^2}](\omega)
=
-\frac{1}{2}
i\omega
\mathcal{F}[e^{-x^2}](\omega)
\]

あとは、

\[
\mathcal{F}[e^{-x^2}](\omega)
=
\frac{1}{\sqrt{2}}
e^{-\omega^2/4}
\]

を代入する。

\[
\mathcal{F}[xe^{-x^2}](\omega)
=
-\frac{1}{2}
i\omega
\frac{1}{\sqrt{2}}
e^{-\omega^2/4}
\]

よって、

\[
\mathcal{F}[xe^{-x^2}](\omega)
=
-\frac{i\omega}{2\sqrt{2}}
e^{-\omega^2/4}
\]

である。

## どこが点になるか

この問題で一番大事なのは、

\[
xe^{-x^2}
\]

を見たら、

\[
(e^{-x^2})'=-2xe^{-x^2}
\]

を思い出すこと。

つまり、

\[
xe^{-x^2}
=
-\frac{1}{2}(e^{-x^2})'
\]

に直せれば、あとは Theorem 5.3 の公式で進む。

## 口頭説明

この問題は、\(xe^{-x^2}\) をそのまま積分せず、\(e^{-x^2}\) の微分として見る。
実際、\((e^{-x^2})'=-2xe^{-x^2}\) なので、\(xe^{-x^2}=-\frac12(e^{-x^2})'\) と書ける。
微分のフーリエ変換は \(i\omega\) をかける操作だから、

\[
\mathcal{F}[xe^{-x^2}]
=
-\frac12 i\omega\mathcal{F}[e^{-x^2}]
\]

となる。
あとは \(\mathcal{F}[e^{-x^2}]=\frac{1}{\sqrt2}e^{-\omega^2/4}\) を代入して、

\[
-\frac{i\omega}{2\sqrt2}e^{-\omega^2/4}
\]

で終わり。

## チートシートに書くなら

\[
(e^{-x^2})'=-2xe^{-x^2}
\]

\[
xe^{-x^2}
=
-\frac12(e^{-x^2})'
\]

\[
\mathcal{F}[f']
=
i\omega\mathcal{F}[f]
\]

\[
\mathcal{F}[e^{-x^2}]
=
\frac1{\sqrt2}e^{-\omega^2/4}
\]

\[
\mathcal{F}[xe^{-x^2}]
=
-\frac{i\omega}{2\sqrt2}e^{-\omega^2/4}
\]

## 次にやること

Lecture 6 Theorem 6.1 へ進む。
