# 中間試験 A4 チートシート (Ch1-3)

印刷想定: A4 一枚に詰め込む構成。式の網羅性 > 体裁。

---

## 1. 記述統計 (Ch1)

### 代表値

$$
\bar{x}=\frac{1}{n}\sum_{i=1}^n x_i \qquad
\text{中央値} = \text{昇順で真ん中 (偶数 } n \text{ なら 2 つの平均)}
$$

### 散布度

$$
s^2=\frac{1}{n}\sum_{i=1}^n (x_i-\bar{x})^2 \quad\text{(標本分散)} \qquad
s=\sqrt{s^2}
$$

不偏分散は $1/(n-1)$。問題文「標本分散」なら $1/n$。

### 四分位数

下半分の中央値 = $Q_1$、上半分の中央値 = $Q_3$、$\mathrm{IQR}=Q_3-Q_1$

### 歪度の見方 (図で判断)

| 形 | 歪度 | 平均 vs 中央値 |
|---|---|---|
| 左右対称 | $\approx 0$ | $\bar{x}\approx \text{med}$ |
| 右に裾長 (右偏) | $> 0$ | $\bar{x} > \text{med}$ |
| 左に裾長 (左偏) | $< 0$ | $\bar{x} < \text{med}$ |

### 共分散・相関係数

$$
s_{xy}=\frac{1}{n}\sum (x_i-\bar{x})(y_i-\bar{y})
$$

$$
r=\frac{\sum (x_i-\bar{x})(y_i-\bar{y})}{\sqrt{\sum(x_i-\bar{x})^2}\sqrt{\sum(y_i-\bar{y})^2}}
\quad,\quad -1\le r\le 1
$$

### 最小二乗回帰直線 $y=ax+b$

$$
a=\frac{\sum(x_i-\bar{x})(y_i-\bar{y})}{\sum(x_i-\bar{x})^2}=r\frac{s_y}{s_x}
\quad,\quad b=\bar{y}-a\bar{x}
$$

標準化 ($\bar{x}=\bar{y}=0$, $s_x=s_y=1$) すると $a=r$, $b=0$。

### 決定係数

$$
R^2 = 1-\frac{\mathrm{RSS}}{\mathrm{TSS}} = r^2 \quad ,\quad 0\le R^2 \le 1
$$

### スピアマン順位相関

データを順位に変換してからピアソン。**単調変換**(増加 or 減少)に対して頑健。
- 完全単調増加なら $\rho_S = 1$
- 完全単調減少なら $\rho_S = -1$
- 山型 ($y=1/(0.01+x^2)$ のような) は単調でないので $\pm 1$ にならない

### よくあるトラップ

- 因果関係 → 相関係数が高い、とは限らない (例: $y=x^2$ は $r\approx 0$)
- 円形分布: $x,y$ に関係はあるが線形でないため $r\approx 0$, $R^2\approx 0$
- 散布図ランダム: $r\approx 0$ かつ関係性も乏しい

---

## 2. 確率 (Ch2)

### 公理と基本

- 標本空間 $\Omega$ = 全結果の集合, 事象 = $\Omega$ の部分集合
- $0\le \mathbb{P}(A)\le 1$, $\mathbb{P}(\Omega)=1$, 排反なら和 = 和の確率

### 主要公式

$$
\mathbb{P}(A^c)=1-\mathbb{P}(A)
$$

$$
\mathbb{P}(A\cup B)=\mathbb{P}(A)+\mathbb{P}(B)-\mathbb{P}(A\cap B)
$$

### 条件付き確率

$$
\mathbb{P}(A\mid B)=\frac{\mathbb{P}(A\cap B)}{\mathbb{P}(B)}\quad(\mathbb{P}(B)>0)
$$

### 独立性

$$
A,B\text{ 独立} \iff \mathbb{P}(A\cap B)=\mathbb{P}(A)\mathbb{P}(B) \iff \mathbb{P}(A\mid B)=\mathbb{P}(A)
$$

### 全確率の公式

$$
\mathbb{P}(B)=\mathbb{P}(B\mid A)\mathbb{P}(A)+\mathbb{P}(B\mid A^c)\mathbb{P}(A^c)
$$

### ベイズの定理

$$
\mathbb{P}(A\mid B)=\frac{\mathbb{P}(B\mid A)\mathbb{P}(A)}{\mathbb{P}(B)}
$$

### カウント問題テンプレ (1〜N の自然数)

- $k$ の倍数の個数 = $\lfloor N/k \rfloor$
- $k_1$ かつ $k_2$ の倍数 = $\mathrm{lcm}(k_1,k_2)$ の倍数
- 例: 1〜100 で 5 の倍数 20 個, 2 の倍数 50 個, 10 の倍数 10 個

---

## 3. 期待値と分散 (Ch3)

### 期待値

離散: $\mathbb{E}[X]=\sum_k k\cdot\mathbb{P}(X=k)$

連続: $\mathbb{E}[X]=\int x f(x)\,dx$

### 分散

$$
\mathbb{V}[X]=\mathbb{E}[(X-\mathbb{E}[X])^2]=\mathbb{E}[X^2]-(\mathbb{E}[X])^2
$$

### 線形性

$$
\mathbb{E}[aX+bY+c]=a\mathbb{E}[X]+b\mathbb{E}[Y]+c \quad\text{(常に成立)}
$$

$$
\mathbb{V}[aX+b]=a^2\mathbb{V}[X]
$$

$$
\mathbb{V}[aX+bY]=a^2\mathbb{V}[X]+b^2\mathbb{V}[Y]+2ab\,\mathrm{Cov}(X,Y)
$$

$X,Y$ 独立なら $\mathrm{Cov}=0$ で

$$
\mathbb{V}[X+Y]=\mathbb{V}[X]+\mathbb{V}[Y]
$$

### 共分散・相関

$$
\mathrm{Cov}(X,Y)=\mathbb{E}[XY]-\mathbb{E}[X]\mathbb{E}[Y]
$$

$$
\rho_{X,Y}=\frac{\mathrm{Cov}(X,Y)}{\sqrt{\mathbb{V}[X]\mathbb{V}[Y]}}\in[-1,1]
$$

### 主要分布

| 分布 | 表記 | $\mathbb{E}$ | $\mathbb{V}$ | PMF/PDF |
|---|---|---|---|---|
| ベルヌーイ | $\mathrm{Bern}(p)$ | $p$ | $p(1-p)$ | $p^k(1-p)^{1-k}$ |
| 二項 | $\mathrm{Bin}(n,p)$ | $np$ | $np(1-p)$ | $\binom{n}{k}p^k(1-p)^{n-k}$ |
| ポアソン | $\mathrm{Po}(\lambda)$ | $\lambda$ | $\lambda$ | $\lambda^k e^{-\lambda}/k!$ |
| 一様 | $U(a,b)$ | $(a+b)/2$ | $(b-a)^2/12$ | $1/(b-a)$ |
| 指数 | $\mathrm{Exp}(\lambda)$ | $1/\lambda$ | $1/\lambda^2$ | $\lambda e^{-\lambda x}$ |
| 正規 | $N(\mu,\sigma^2)$ | $\mu$ | $\sigma^2$ | $\frac{1}{\sqrt{2\pi}\sigma}e^{-(x-\mu)^2/2\sigma^2}$ |

### コイン問題テンプレ (重要)

5円 $a$ 枚, 1円 $b$ 枚を投げる, 表枚数 $X\sim\mathrm{Bin}(a,1/2)$, $Y\sim\mathrm{Bin}(b,1/2)$, 合計金額 $Z=5X+Y$:

$$
\mathbb{E}[Z]=5\cdot\frac{a}{2}+\frac{b}{2}
$$

$$
\mathbb{V}[Z]=25\cdot\frac{a}{4}+\frac{b}{4}\quad(X,Y\text{ 独立})
$$

同時確率 (独立):

$$
\mathbb{P}(X=i,\,Y=j)=\binom{a}{i}\left(\tfrac12\right)^a\binom{b}{j}\left(\tfrac12\right)^b
$$

### 二項係数 (頻出)

$\binom{3}{0}=1,\binom{3}{1}=3,\binom{3}{2}=3,\binom{3}{3}=1$

$\binom{4}{0..4}=1,4,6,4,1$

$\binom{5}{0..5}=1,5,10,10,5,1$

$\binom{6}{0..6}=1,6,15,20,15,6,1$

---

## 4. 試験テクニック・落とし穴

- 「標本サイズ」と「サンプル数」の用語ぶれ → 統計的に厳密でないと × 評価される (問1の傾向)
- 「標本空間」は確率試行の用語、カテゴリ集合は「水準/カテゴリ」と区別
- $R^2 \in [0,1]$, $r \in [-1,1]$ — 値域を混同しない
- 標本分散 ($1/n$) と不偏分散 ($1/(n-1)$) — 問題文を見て使い分け
- $\mathbb{V}[aX+b]$ で $b$ は消える、$a$ は二乗
- 独立じゃないと $\mathbb{V}[X+Y]\ne \mathbb{V}[X]+\mathbb{V}[Y]$
- $R^2=r^2$ なので符号情報は失われる

---

## 5. 計算のショートカット

- 平均 → $\sum x_i / n$
- 分散 (高速版) → $\dfrac{1}{n}\sum x_i^2 - \bar{x}^2$ (偏差を出さずに済む)
- $Q_1$ → 下半分の中央値 (n 偶数なら下 n/2 個の中央)
- 二項分布: $\mathbb{E}=np$, $\mathbb{V}=np(1-p)$ (秒で出る)
- 標準化したら $a=r$, $b=0$ (即答)
- 1〜N の倍数カウント: 10 の倍数なら $\lfloor N/10\rfloor$
- $\mathbb{E}[X^2] = \mathbb{V}[X] + (\mathbb{E}[X])^2$ (分散の式を逆に使う)

---

## 6. 用語の正確な区別 (◯× 対策の核)

| 似た用語 | 正しい意味 |
|---|---|
| 記述統計 | データを集計・要約する手法 (平均・分散・図) |
| 推測統計 | 標本から母集団を推測する手法 (信頼区間・検定) |
| 母集団 | 興味のある全体集合 (パラメータ $\mu, \sigma^2$) |
| 標本 | 母集団から抽出された一部 (統計量 $\bar{x}, s^2$) |
| サンプルサイズ | 1 つの標本に含まれる観測値の個数 ($n$) |
| サンプル数 | 文脈で揺れる (標本の本数のことも) → 厳密には曖昧 |
| 標本空間 | 確率試行で起こり得る結果全体 (確率の用語) |
| カテゴリ/水準 | 質的データの取り得る値 (A,B,C など) |
| 状態空間 | 確率過程の文脈で使う (本問では出にくい) |
| 標本誤差 | 有限標本ゆえの真値からのずれ |
| 質的 (カテゴリカル) | カテゴリ・順序データ (色, 評価) |
| 量的 (数値) | 連続値・離散カウント (身長, 個数) |

「サンプル**サイズ**」と書いてあれば $n$ で正解、「サンプル**数**」は文脈で判断。両方並列で書かれてたら × にされやすい。

---

## 7. 包除原理 (確率の和)

$$
\mathbb{P}(A\cup B)=\mathbb{P}(A)+\mathbb{P}(B)-\mathbb{P}(A\cap B)
$$

3 事象の場合:

$$
\mathbb{P}(A\cup B\cup C)=\sum\mathbb{P}-\sum\mathbb{P}(\cap)+\mathbb{P}(A\cap B\cap C)
$$

例: 1〜100 で「2 または 3 の倍数」 = $50+33-16=67$ 個 (16 = 6 の倍数の個数)

---

## 8. 標準化と z 値

$$
z=\frac{x-\mu}{\sigma} \implies \mathbb{E}[z]=0,\ \mathbb{V}[z]=1
$$

正規分布なら $X\sim N(\mu,\sigma^2) \Rightarrow Z=(X-\mu)/\sigma\sim N(0,1)$

---

## 9. 共分散・相関のテクニック

- $\mathrm{Cov}(X,Y)=\mathbb{E}[XY]-\mathbb{E}[X]\mathbb{E}[Y]$
- $X,Y$ 独立 $\Rightarrow \mathrm{Cov}=0$ (逆は不成立)
- $\mathrm{Cov}(aX+b,\,cY+d)=ac\,\mathrm{Cov}(X,Y)$ (定数で平行移動しても変わらない)
- $\mathrm{Cov}(X,X)=\mathbb{V}[X]$
- 相関係数 $\rho$ は単位に依存しない (スケール不変)

---

## 10. 計算ミス防止チェックリスト

- 偏差の合計 $\sum (x_i-\bar{x})$ は **常に 0** → 検算に使える
- $s^2$ の分母を $n$ にしたか $n-1$ にしたか問題文を再確認
- 平方完成: $(x-\bar{x})^2$ を計算したら**符号は気にしない** (二乗するから)
- 確率の答えは $0\le P\le 1$ の範囲か?
- 既約分数になっているか? (例: $20/100 \ne 1/5$ の形で出すと減点リスク)
- 期待値 $\mathbb{E}$ は線形 (常に和が分けられる), 分散 $\mathbb{V}$ は独立じゃないと分けられない
- 二項係数: $\binom{n}{k}=\binom{n}{n-k}$ (対称性で計算楽になる)

---

## 11. ヒストグラム形と統計量の対応 (図で覚える)

```
左右対称 (A型):  ┌─┴─┐    平均 ≈ 中央値,   歪度 ≈ 0
                ┘    └

右に裾長 (B型):  ┌┐         平均 > 中央値,   歪度 > 0  (正の歪み)
                │└──___

左に裾長 (C型):     ___──┐│  平均 < 中央値,   歪度 < 0  (負の歪み)
                       └┘
```

順序: **歪度 C < A < B**, **$Q_1$ も C < A < B** (左に裾あるほど Q1 小), **平均-中央値 も C < A < B**

---

## 12. 散布図と相関係数の対応

| 形 | $r$ | $R^2$ | xy 関係 |
|---|---|---|---|
| 右上がり直線 | $\to +1$ | $\to 1$ | 正の線形 |
| 右下がり直線 | $\to -1$ | $\to 1$ | 負の線形 |
| ランダム雲 | $\approx 0$ | $\approx 0$ | 関係なし |
| 円形・$y=x^2$ 型 | $\approx 0$ | $\approx 0$ | **関係あるが線形ではない** |
| 楕円 (右上向き) | 正で中程度 | $r^2$ | 正の弱〜中相関 |

スピアマン $\rho_S$ は順位ベース → 単調変換に強い:
- $y=e^x, y=\log x$ 系は単調 → $\rho_S = \pm 1$
- $y=1/(0.01+x^2), y=x^2$ 系は山型 → 単調でない → $\rho_S\ne \pm 1$

---

## 13. 過去問頻出パターン早見

| パターン | 解法 |
|---|---|
| $\{x_1,...,x_n\}$ の平均/分散 | $\bar{x}=\sum/n$, $s^2=\sum x_i^2/n - \bar{x}^2$ |
| Q1, Q3 | データを並べて、半分に切って中央値 |
| 1〜N で k の倍数の確率 | $\lfloor N/k\rfloor / N$ |
| $A\cap B$ の確率 (倍数) | lcm の倍数を数える |
| コイン $n$ 枚の表枚数 | $\mathrm{Bin}(n, 1/2)$ |
| $aX+bY$ の期待値 | $a\mathbb{E}[X]+b\mathbb{E}[Y]$ (常に) |
| $aX+bY$ の分散 (独立) | $a^2\mathbb{V}[X]+b^2\mathbb{V}[Y]$ |
| $X=i, Y=j$ 同時確率 (独立) | $\mathbb{P}(X=i)\cdot\mathbb{P}(Y=j)$ |
| 二項の点確率 | $\binom{n}{k}p^k(1-p)^{n-k}$ |
