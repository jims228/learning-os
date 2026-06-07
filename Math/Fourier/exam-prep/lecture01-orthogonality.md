# Lecture 1: 三角関数系の直交性

作成日: 2026-06-07

## 範囲

Review指定:

- Orthogonality properties of the trigonometric system

テーマ:

- フーリエ係数計算の土台
- \(\sin\) と \(\cos\) の積分がいつ0になるか

## 直交とは

2つの関数 \(f(x)\), \(g(x)\) について、

$$
\int_a^b f(x)g(x)\,dx=0
$$

なら、\(f\) と \(g\) は区間 \([a,b]\) で直交するという。

ベクトルでいう「内積が0なら直角」と同じ考え方。

## 三角関数系

フーリエ級数では、次の関数たちを部品として使う。

$$
1,\quad
\cos x,\quad
\cos 2x,\quad
\cos 3x,\quad \ldots
$$

$$
\sin x,\quad
\sin 2x,\quad
\sin 3x,\quad \ldots
$$

これらは、区間 \([-\pi,\pi]\) で直交する。

## 覚える公式

### 1. cos と cos

\(m\ne n\) のとき、

$$
\int_{-\pi}^{\pi}\cos(mx)\cos(nx)\,dx=0
$$

同じ番号なら、

$$
\int_{-\pi}^{\pi}\cos^2(mx)\,dx=\pi
\qquad (m\ne0)
$$

### 2. sin と sin

\(m\ne n\) のとき、

$$
\int_{-\pi}^{\pi}\sin(mx)\sin(nx)\,dx=0
$$

同じ番号なら、

$$
\int_{-\pi}^{\pi}\sin^2(mx)\,dx=\pi
\qquad (m\ne0)
$$

### 3. cos と sin

すべての \(m,n\) について、

$$
\int_{-\pi}^{\pi}\cos(mx)\sin(nx)\,dx=0
$$

## なぜ大事か

フーリエ級数では、関数を

$$
f(x)=a_0+\sum_{n=1}^{\infty}\{a_n\cos(nx)+b_n\sin(nx)\}
$$

のように表す。

このとき、係数 \(a_n\), \(b_n\) を求めるために、両辺に \(\cos(mx)\) や \(\sin(mx)\) をかけて積分する。

直交性のおかげで、関係ない項が全部0になり、欲しい係数だけが残る。

## 例1

次を求める。

$$
\int_{-\pi}^{\pi}\cos(2x)\cos(3x)\,dx
$$

番号が違う。

$$
2\ne3
$$

したがって、直交性より、

$$
\boxed{
\int_{-\pi}^{\pi}\cos(2x)\cos(3x)\,dx=0
}
$$

## 例2

次を求める。

$$
\int_{-\pi}^{\pi}\sin(4x)\sin(4x)\,dx
$$

これは同じ番号なので、

$$
\int_{-\pi}^{\pi}\sin^2(4x)\,dx=\pi
$$

答え:

$$
\boxed{
\int_{-\pi}^{\pi}\sin^2(4x)\,dx=\pi
}
$$

## 例3

次を求める。

$$
\int_{-\pi}^{\pi}\cos(5x)\sin(2x)\,dx
$$

\(\cos\) と \(\sin\) の組み合わせは、番号に関係なく0。

したがって、

$$
\boxed{
\int_{-\pi}^{\pi}\cos(5x)\sin(2x)\,dx=0
}
$$

## 口頭説明

三角関数系の直交性とは、\(\sin\) や \(\cos\) の違う周波数どうしを掛けて \([-\pi,\pi]\) で積分すると0になる性質です。同じ種類で同じ番号のときだけ \(\pi\) が残ります。この性質のおかげで、フーリエ級数の係数を求めるときに、関係ない項が全部消えて、欲しい係数だけを取り出せます。
