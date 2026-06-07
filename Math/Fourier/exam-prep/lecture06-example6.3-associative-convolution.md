# Lecture 6 Example 6.3: 畳み込みの結合法則

作成日: 2026-06-08

## 問題

畳み込みが結合法則を満たすことを示す。

\[
f*(g*h)
=
(f*g)*h
\]

## 先に結論

この問題は、畳み込みを直接計算しない。

Theorem 6.1 を使って、両辺をフーリエ変換する。

左辺も右辺も、フーリエ変換すると

\[
\mathcal{F}[f]\mathcal{F}[g]\mathcal{F}[h]
\]

になる。

だから、

\[
f*(g*h)
=
(f*g)*h
\]

である。

## 使う公式

畳み込み定理より、

\[
\mathcal{F}[f*g]
=
\mathcal{F}[f]\mathcal{F}[g]
\]

である。

つまり、

\[
\text{畳み込みは、フーリエ変換するとかけ算になる}
\]

ということ。

## 証明

左辺を

\[
u=f*(g*h)
\]

右辺を

\[
v=(f*g)*h
\]

とおく。

目標は、

\[
u=v
\]

を示すことである。

## Step 1: 左辺をフーリエ変換する

\[
u=f*(g*h)
\]

なので、

\[
\mathcal{F}[u]
=
\mathcal{F}[f*(g*h)]
\]

畳み込み定理を使うと、

\[
\mathcal{F}[f*(g*h)]
=
\mathcal{F}[f]\mathcal{F}[g*h]
\]

さらに、もう一度畳み込み定理を使う。

\[
\mathcal{F}[g*h]
=
\mathcal{F}[g]\mathcal{F}[h]
\]

したがって、

\[
\mathcal{F}[u]
=
\mathcal{F}[f]\mathcal{F}[g]\mathcal{F}[h]
\]

となる。

## Step 2: 右辺をフーリエ変換する

\[
v=(f*g)*h
\]

なので、

\[
\mathcal{F}[v]
=
\mathcal{F}[(f*g)*h]
\]

畳み込み定理より、

\[
\mathcal{F}[(f*g)*h]
=
\mathcal{F}[f*g]\mathcal{F}[h]
\]

さらに、

\[
\mathcal{F}[f*g]
=
\mathcal{F}[f]\mathcal{F}[g]
\]

なので、

\[
\mathcal{F}[v]
=
\mathcal{F}[f]\mathcal{F}[g]\mathcal{F}[h]
\]

となる。

## Step 3: 比べる

左辺側は、

\[
\mathcal{F}[u]
=
\mathcal{F}[f]\mathcal{F}[g]\mathcal{F}[h]
\]

右辺側も、

\[
\mathcal{F}[v]
=
\mathcal{F}[f]\mathcal{F}[g]\mathcal{F}[h]
\]

である。

したがって、

\[
\mathcal{F}[u]
=
\mathcal{F}[v]
\]

フーリエ変換した結果が同じなので、元の関数も同じと考える。

\[
u=v
\]

つまり、

\[
f*(g*h)
=
(f*g)*h
\]

である。

## 口頭説明

畳み込みの結合法則は、直接積分を展開せずにフーリエ変換で示す。
左辺 \(f*(g*h)\) をフーリエ変換すると、

\[
\mathcal{F}[f]\mathcal{F}[g]\mathcal{F}[h]
\]

になる。
右辺 \((f*g)*h\) をフーリエ変換しても、

\[
\mathcal{F}[f]\mathcal{F}[g]\mathcal{F}[h]
\]

になる。
両方のフーリエ変換が同じなので、元の関数も同じ。
よって、

\[
f*(g*h)=(f*g)*h
\]

である。

## チートシートに書くなら

\[
\mathcal{F}[f*g]
=
\mathcal{F}[f]\mathcal{F}[g]
\]

\[
\mathcal{F}[f*(g*h)]
=
\mathcal{F}[f]\mathcal{F}[g]\mathcal{F}[h]
\]

\[
\mathcal{F}[(f*g)*h]
=
\mathcal{F}[f]\mathcal{F}[g]\mathcal{F}[h]
\]

\[
\therefore
f*(g*h)=(f*g)*h
\]

## 次にやること

Lecture 6 Example 6.4 へ進む。
