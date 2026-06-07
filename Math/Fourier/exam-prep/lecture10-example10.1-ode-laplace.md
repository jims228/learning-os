# Lecture 10 Example 10.1: ラプラス変換でODEを解く

作成日: 2026-06-07

## 問題

次の初期値問題を解く。

$$
y''+y=2,\qquad y(0)=0,\qquad y'(0)=1
$$

## 使う公式

未知関数を \(y(t)\) とし、

$$
Y(s)=\mathcal{L}\{y(t)\}
$$

と置く。

微分のラプラス変換は、

$$
\mathcal{L}\{y''\}
=
s^2Y(s)-sy(0)-y'(0)
$$

である。

また、

$$
\mathcal{L}\{2\}=\frac{2}{s}
$$

である。

## Step 1: 両辺をラプラス変換する

元の式は、

$$
y''+y=2
$$

両辺をラプラス変換すると、

$$
\mathcal{L}\{y''\}
+
\mathcal{L}\{y\}
=
\mathcal{L}\{2\}
$$

ここで、

$$
\mathcal{L}\{y''\}
=
s^2Y(s)-sy(0)-y'(0)
$$

初期条件は、

$$
y(0)=0,\qquad y'(0)=1
$$

なので、

$$
\mathcal{L}\{y''\}
=
s^2Y(s)-1
$$

したがって、

$$
s^2Y(s)-1+Y(s)=\frac{2}{s}
$$

## Step 2: \(Y(s)\) について解く

左辺をまとめる。

$$
(s^2+1)Y(s)-1=\frac{2}{s}
$$

両辺に \(1\) を足す。

$$
(s^2+1)Y(s)=\frac{2}{s}+1
$$

したがって、

$$
Y(s)=\frac{\frac{2}{s}+1}{s^2+1}
$$

これを分ける。

$$
Y(s)=\frac{1}{s^2+1}
+
\frac{2}{s(s^2+1)}
$$

さらに、

$$
\frac{2}{s(s^2+1)}
=
\frac{2}{s}
-
\frac{2s}{s^2+1}
$$

なので、

$$
Y(s)
=
\frac{1}{s^2+1}
+
\frac{2}{s}
-
\frac{2s}{s^2+1}
$$

## Step 3: 逆ラプラス変換する

基本公式:

$$
\mathcal{L}^{-1}\left\{\frac{1}{s^2+1}\right\}
=
\sin t
$$

$$
\mathcal{L}^{-1}\left\{\frac{1}{s}\right\}
=
1
$$

$$
\mathcal{L}^{-1}\left\{\frac{s}{s^2+1}\right\}
=
\cos t
$$

したがって、

$$
\begin{aligned}
y(t)
&=
\mathcal{L}^{-1}\left\{
\frac{1}{s^2+1}
+
\frac{2}{s}
-
\frac{2s}{s^2+1}
\right\}\\
&=
\sin t+2-2\cos t
\end{aligned}
$$

答え:

$$
\boxed{
y(t)=\sin t+2-2\cos t
}
$$

## 口頭説明

まず \(Y(s)=\mathcal{L}\{y(t)\}\) と置きます。微分の公式より、\(\mathcal{L}\{y''\}=s^2Y(s)-sy(0)-y'(0)\) です。初期条件 \(y(0)=0\), \(y'(0)=1\) を入れると、\(\mathcal{L}\{y''\}=s^2Y(s)-1\) になります。元の式 \(y''+y=2\) をラプラス変換して \(Y(s)\) について解き、部分分数に分けて逆ラプラス変換すると、答えは \(\sin t+2-2\cos t\) です。
