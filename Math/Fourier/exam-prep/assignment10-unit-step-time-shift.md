# Assignment 10: 単位ステップ関数と時間シフト

作成日: 2026-06-07

## 範囲

Assignment 10 の問題:

1. 次をラプラス変換する。
   - \(f(t)=u(t-1)-t+1\)
   - \(f(t)=e^{2t}u(t-2)\)
2. 次を逆ラプラス変換する。
   - \(\mathcal{L}^{-1}\left\{\frac{e^{-s}}{s^2}\right\}\)

## 使う公式

### 単位ステップ関数

$$
u(t-a)=
\begin{cases}
0, & t<a\\
1, & t\ge a
\end{cases}
$$

ラプラス変換:

$$
\mathcal{L}\{u(t-a)\}
=
\frac{e^{-as}}{s}
$$

### 第2移動定理

$$
\mathcal{L}\{u(t-a)g(t-a)\}
=
e^{-as}G(s)
$$

ただし、

$$
G(s)=\mathcal{L}\{g(t)\}
$$

逆向き:

$$
\mathcal{L}^{-1}\{e^{-as}F(s)\}
=
u(t-a)f(t-a)
$$

## 問1(a): \(f(t)=u(t-1)-t+1\)

線形性で分ける。

$$
\mathcal{L}\{u(t-1)-t+1\}
=
\mathcal{L}\{u(t-1)\}
-
\mathcal{L}\{t\}
+
\mathcal{L}\{1\}
$$

それぞれ、

$$
\mathcal{L}\{u(t-1)\}
=
\frac{e^{-s}}{s}
$$

$$
\mathcal{L}\{t\}
=
\frac{1}{s^2}
$$

$$
\mathcal{L}\{1\}
=
\frac{1}{s}
$$

したがって、

$$
\boxed{
\mathcal{L}\{u(t-1)-t+1\}
=
\frac{e^{-s}}{s}
-
\frac{1}{s^2}
+
\frac{1}{s}
}
$$

順番を整えると、

$$
\boxed{
\frac{e^{-s}}{s}
+
\frac{1}{s}
-
\frac{1}{s^2}
}
$$

## 問1(b): \(f(t)=e^{2t}u(t-2)\)

第2移動定理を使うには、

$$
u(t-a)g(t-a)
$$

の形に直したい。

今回は \(a=2\)。

そこで、\(e^{2t}\) を \(t-2\) の形に直す。

$$
e^{2t}
=
e^{2(t-2)+4}
=
e^4e^{2(t-2)}
$$

したがって、

$$
e^{2t}u(t-2)
=
e^4e^{2(t-2)}u(t-2)
$$

ここで、

$$
g(t)=e^{2t}
$$

と見れば、

$$
G(s)=\mathcal{L}\{e^{2t}\}
=
\frac{1}{s-2}
$$

第2移動定理より、

$$
\mathcal{L}\{e^4e^{2(t-2)}u(t-2)\}
=
e^4e^{-2s}\frac{1}{s-2}
$$

したがって、

$$
\boxed{
\mathcal{L}\{e^{2t}u(t-2)\}
=
\frac{e^{4-2s}}{s-2}
}
$$

## 問2: \(\mathcal{L}^{-1}\left\{\frac{e^{-s}}{s^2}\right\}\)

まず、

$$
\frac{1}{s^2}
$$

だけを見る。

$$
\mathcal{L}^{-1}\left\{\frac{1}{s^2}\right\}
=
t
$$

つまり、

$$
F(s)=\frac{1}{s^2}
\quad\Longleftrightarrow\quad
f(t)=t
$$

問題では、

$$
e^{-s}F(s)
$$

になっている。

これは、

$$
e^{-as}
$$

の形で、\(a=1\)。

逆向きの第2移動定理より、

$$
\mathcal{L}^{-1}\{e^{-as}F(s)\}
=
u(t-a)f(t-a)
$$

だから、

$$
\boxed{
\mathcal{L}^{-1}\left\{\frac{e^{-s}}{s^2}\right\}
=
u(t-1)(t-1)
}
$$

普通は次のようにも書く。

$$
\boxed{
(t-1)u(t-1)
}
$$

## 口頭説明

Assignment 10 は、単位ステップ関数と時間シフトの問題です。\(u(t-a)\) は \(t=a\) から始まるスイッチで、\(\mathcal{L}\{u(t-a)\}=\frac{e^{-as}}{s}\) です。\(u(t-a)g(t-a)\) の形なら、ラプラス変換は \(e^{-as}G(s)\) になります。\(e^{2t}u(t-2)\) はそのままだと \(g(t-2)\) の形ではないので、\(e^{2t}=e^4e^{2(t-2)}\) と直してから第2移動定理を使います。逆変換では、\(e^{-s}\) があるので1だけ右にずれ、\(\frac{1}{s^2}\) に対応する \(t\) が \((t-1)u(t-1)\) になります。
