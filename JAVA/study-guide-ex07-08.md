# テスト勉強用ガイド: Ex07 (Interface) + Ex08 (Polymorphism Part 1)

新後さんへ。テスト前にここを読めば、コードを書きながら「なぜこうなっているか」を自分の言葉で説明できるようになります。AI に頼らず自力で書けるよう、思考の道筋を残しています。

---

## 全体マップ

```
Interface (Ex07)              →  Polymorphism (Ex08)
  ↓                                ↓
「契約」を定義する仕組み              「同じ呼び出しが対象次第で違う動きをする」
  ↓                                ↓
複数のクラスが同じ顔を持てる           interface + 動的バインディングで実現
  ↓                                ↓
Container, Relatable             OpenList, PointComparator, Aggregate/Iterator
```

Ex07 で「interface とは何か」を覚えて、Ex08 でそれを使った 3 つのデザインパターンを学ぶ流れ。

---

# Ex07: Interface

## A: Container Interface (2 pt)

### 何を学ぶか
- interface で「メソッド署名のみ」の契約を定義する
- 複数のクラスが同じ interface を実装できる

### 重要なポイント
1. `interface Container { int size(); boolean isEmpty(); boolean isFull(); }`
   - interface のメソッドは中身がない (declaration のみ)
   - public abstract が暗黙、書かなくてもいい
2. `class Stack implements Container` で「このクラスは Container である」と宣言
3. `implements` を書いた瞬間、そのクラスは interface のメソッドを全部実装しないとコンパイル通らない (= 契約)
4. ContainerApplication の `private void showState(Container con)` の引数型は **Container** (interface 型)。Stack を渡しても OK = polymorphism の入り口

### テスト書けるようになるために覚えること
- `Stack(int capacity)` でコンストラクタ引数の capacity を保持
- `top` で要素数管理 → `size()=top`, `isEmpty()=(top==0)`, `isFull()=(top==capacity)`
- `push` で `data[top++]`、`pop` で `data[--top]` (top の前置/後置に注意)

### 出力理解
```
push 0 → top=1 → "1"
push 1 → top=2 → "2"
...
push 4 → top=5 → "full"
pop  → top=4 → "4"
...
pop → top=0 → "empty"
```

---

## B: Relatable Interface (2 pt)

### 何を学ぶか
- interface のメソッド引数が同じ interface 型 ← 自己参照
- 「比較できる」という抽象概念を interface で表現

### 重要なポイント
1. `interface Relatable { boolean isSmallerThan(Relatable other); }`
   - 引数も Relatable 型 = どんな Relatable でも比較できる前提
2. Point で実装するとき `isSmallerThan(Relatable other)` の中で `(Point)other` でキャスト
   - これは「相手は Point のはず」という暗黙の契約
   - 違う型が来たら ClassCastException で落ちる (現状 OK、後で改善余地あり)
3. 比較ロジックは辞書順:
   ```
   x が小さい方が smaller
   x が同値 → y で比較
   ```

### テスト書けるようになるために覚えること
- `if(x1 < x2) return true; if(x1 > x2) return false; return y1 < y2;`
- このロジックを「3 つの if」で書けるようにする (ネストではなく早期 return が綺麗)

---

## C: Sorting Relatable Objects I (2 pt)

### 何を学ぶか
- interface の真価: ★ **同じ SortingMachine が任意の Relatable をソートできる**
- 「型に依存しない汎用ソート」が interface で実現できる

### 重要なポイント
1. `class SortingMachine { void sort(Relatable[] r) {...} }` ← 引数型は Relatable[]
2. ソート中の比較は `r[j].isSmallerThan(r[j-1])` ← interface のメソッド呼ぶだけ
3. これだけで Point[] でも Rectangle[] でも (D 問題) 動く

### テスト書けるようになるために覚えること
- バブルソートで OK: 二重 for + swap
- ★ なぜ Relatable[] にする? → Point[] にしたら Point 専用になり Rectangle で使い回せない
- 「sort は型を知らない」「比較ロジックは Relatable に委譲」 = この設計思想こそが interface の威力

---

## D: Sorting Relatable Objects II (2 pt)

### 何を学ぶか
- ★ **SortingMachine を 1 行も変えずに別の型がソートできる** = Open-Closed Principle
- 異なるクラスが同じ Relatable interface を実装することの意味

### 重要なポイント
1. `class Rectangle implements Relatable` で長方形も Relatable に
2. コンストラクタ `Rectangle(Point p1, Point p3)` ← 対角線上の 2 点
3. `getArea()` = 横幅 × 高さ = `Math.abs(p3.x - p1.x) * Math.abs(p3.y - p1.y)`
4. `isSmallerThan` は面積比較 = `this.getArea() < r.getArea()`

### テスト書けるようになるために覚えること
- なぜ abs?: 2 点の指定順が逆でも面積は同じ (差が負になる場合への対応)
- なぜ SortingMachine を変更不要?: interface の契約だけで動くから (Polymorphism)

---

# Ex08: Polymorphism Part 1

## A: OpenList (3 pt) — Strategy で DFS / BFS 切替

### 何を学ぶか
- ★ 同じアルゴリズム (TreeTraverser.traverse) が、データ構造を差し替えるだけで違う動きをする
- これが polymorphism の典型応用

### 重要なポイント
1. `interface OpenList { void push(int x); int pop(); boolean isEmpty(); }`
2. `Stack` (LIFO = 後入先出) を渡すと **DFS** (深さ優先探索)
3. `Queue` (FIFO = 先入先出) を渡すと **BFS** (幅優先探索)
4. TreeTraverser のコードは 1 行も変えずに、push/pop の挙動だけで結果が変わる

### TreeTraverser の動きを追ってみよう

```
list.push(0) → list = [0]
ループ:
  u = list.pop()
  if u >= N: continue (ノード番号が大きすぎたら skip)
  print u
  list.push(2u+1)  ← 左の子
  list.push(2u+2)  ← 右の子
```

完全 2 分木 (N=15、添字 0〜14):
- 0 の子は 1 と 2
- 1 の子は 3 と 4
- 2 の子は 5 と 6
- ...
- 6 の子は 13 と 14

### Stack (LIFO) のとき = DFS
```
push 0 → [0]
pop 0 → print 0, push 1, push 2 → [1, 2]
pop 2 → print 2, push 5, push 6 → [1, 5, 6]   ← 後入先出で 2 を先に取る
pop 6 → print 6, push 13, push 14 → [1, 5, 13, 14]
pop 14 → print 14, push 29(skip), push 30(skip) → [1, 5, 13]
pop 13 → print 13 → ...
```
出力: `0 2 6 14 13 5 12 11 1 4 10 9 3 8 7` ← 右にどんどん潜る

### Queue (FIFO) のとき = BFS
```
push 0 → [0]
pop 0 → print 0, push 1, push 2 → [1, 2]
pop 1 → print 1, push 3, push 4 → [2, 3, 4]   ← 先入先出で 1 を先に取る
pop 2 → print 2, push 5, push 6 → [3, 4, 5, 6]
pop 3 → print 3, push 7, push 8 → [4, 5, 6, 7, 8]
...
```
出力: `0 1 2 3 4 5 6 7 8 9 10 11 12 13 14` ← 順番に階層を降りる

### テスト書けるようになるために覚えること
- Stack: `push = data[top++]`, `pop = data[--top]`, `isEmpty = (top == 0)`
- Queue: `push = data[tail++]`, `pop = data[head++]`, `isEmpty = (head == tail)`
- Queue は head/tail 別変数、Stack は top 1 つ
- ★ なぜ DFS/BFS が切り替わる?: 「最後に追加した子を先に処理 (深く潜る)」vs「先に追加した子を先に処理 (横に広がる)」

---

## B: Sorting Points by Comparator (3 pt) — Strategy Pattern

### 何を学ぶか
- ★ **Strategy Pattern**: アルゴリズム (比較ロジック) をオブジェクトとして渡せる
- 同じ SortingPointMachine が runtime で比較基準を切替可能 (`setComparator`)

### 重要なポイント
1. `interface PointComparator { int compare(Point p1, Point p2); }` ← compare の戻り値ルール:
   - p1 < p2 なら -1
   - p1 > p2 なら 1
   - 同値なら 0
2. `XYComparator`: x 優先 (x で決まらないとき y)
3. `YXComparator`: y 優先 (y で決まらないとき x)
4. SortingPointMachine の `comparator.compare(a[j], a[mini]) < 0` ← 戻り値 -1 で「より小さい」判定

### Ex07 D との違い
| 項目 | Ex07 D | Ex08 B |
|---|---|---|
| 比較の場所 | Point/Rectangle 内 (`isSmallerThan`) | 外部 (Comparator クラス) |
| 1 つのクラスに複数比較基準 | 不可 (1 種類のみ) | 可 (Comparator 切替) |
| 設計パターン | Comparable | Strategy |

### テスト書けるようになるために覚えること
- compare のロジックは Ex07 B の Point.isSmallerThan と似てるが、戻り値が boolean ではなく int (-1/0/1)
- なぜ int を返す?: 「smaller / equal / greater」3 状態を表現できる (boolean だと smaller か非 smaller の 2 状態のみ)

---

## C: Iterator Pattern (4 pt) — 走査と集合の分離

### 何を学ぶか
- ★ **Iterator Pattern**: 集合 (Aggregate) と走査方法 (Iterator) を別クラスに分ける
- なぜ分ける?: 集合の実装を変えても (List → Array)、Iterator が同じ interface を出力すれば、利用側 (IteratorApplication) は変えなくていい

### 構造を整理
```
Aggregate (interface)        Iterator (interface)
  ├ forwardIterator()         ├ hasNext()
  └ backwardIterator()        └ next()
       ↓                          ↑
SimpleList (Aggregate 実装)   ├ SimpleListForwardIterator
                               └ SimpleListBackwardIterator
```

### 重要なポイント
1. **双方向循環連結リスト** with sentinel:
   - `nil` は番兵ノード、key を持たない
   - 空リスト: `nil.next == nil && nil.prev == nil`
   - 通常: `nil <-> n1 <-> n2 <-> ... <-> nk <-> nil`

2. **insert は head 側 (nil の直後)** に追加:
   ```
   newNode.next = nil.next       ← 元の先頭を新ノードの次に
   newNode.prev = nil
   nil.next.prev = newNode       ← 元の先頭が新ノードを prev 参照
   nil.next = newNode             ← nil の next を更新
   ```
   テストで毎回これを描けるように手で書いて練習。

3. **delete は線形探索 + unlink**:
   ```
   cur.prev.next = cur.next       ← cur をスキップ
   cur.next.prev = cur.prev
   ```

4. **Iterator は cur をフィールドに持って状態管理**:
   - Forward: `cur = nil.getNext()` から start、`cur.getNext()` で進む、`cur != nil` まで継続
   - Backward: `cur = nil.getPrev()` から start、`cur.getPrev()` で進む

### insert/delete の挙動を追う (ケース 1 の最初)
```
insert 2 → nil <-> 2 <-> nil
insert 3 → nil <-> 3 <-> 2 <-> nil  ← 3 が head 側に追加
insert 5 → nil <-> 5 <-> 3 <-> 2 <-> nil
insert 7 → nil <-> 7 <-> 5 <-> 3 <-> 2 <-> nil
insert 11 → nil <-> 11 <-> 7 <-> 5 <-> 3 <-> 2 <-> nil
delete 3 → nil <-> 11 <-> 7 <-> 5 <-> 2 <-> nil
```

forward (nil.next から): 11 → 7 → 5 → 2
backward (nil.prev から): 2 → 5 → 7 → 11

### テスト書けるようになるために覚えること
- 双方向循環連結リスト の絵を白紙に書ける
- insert の 4 行 / delete の 2 行を暗記 (順序が大事!)
- なぜ `Object next()` は Object 型?: Iterator interface は型に依存しない (汎用化)
- 利用側でキャストする: `SimpleNode node = (SimpleNode)it.next();`

---

# テスト直前 5 分復習リスト

## interface 基礎
- [ ] interface はメソッド署名のみ、実装なし
- [ ] `implements` で複数 implement 可、`extends` は class で 1 つだけ
- [ ] interface 型変数に implementing class のインスタンスを代入できる (up-casting)
- [ ] (Type)obj で down-casting、`instanceof` で型チェック

## Ex07 のキー関数
- [ ] Stack: top++/--top
- [ ] Point.isSmallerThan: 3 if で辞書順
- [ ] SortingMachine: 任意の Relatable[] を sort
- [ ] Rectangle.getArea: abs * abs

## Ex08 のキーパターン
- [ ] OpenList: Stack=DFS / Queue=BFS
- [ ] Queue は head/tail 別、Stack は top 1 つ
- [ ] PointComparator.compare: -1/0/1 (boolean ではない)
- [ ] Iterator Pattern: Aggregate と Iterator の分離 = 走査ロジックの差替え可能

## 出題されそうな問題
1. interface 内のメソッドは何 modifier が暗黙? (答: public abstract)
2. interface のフィールドは何 modifier が暗黙? (答: public static final = 定数)
3. なぜ静的バインディング (early) ではなく動的バインディング (late)? (答: runtime まで実際の型が分からないため)
4. `Person p = new Student(...)` で `p.introduction()` を呼ぶと Person/Student どちらの実装が呼ばれる? (答: Student、動的バインディング)
5. Comparable と Comparator の違いを 1 行で (答: Comparable は自分で比較、Comparator は外部から比較ロジック注入)

---

# 解いてみる (テスト前の腕試し)

## Q1: Container interface に「addAll(Container other) で別 Container の中身を全部移す」メソッドを追加するとしたら、Stack の実装はどう書く?

## Q2: Ex08 A の Queue が data[1000] で固定だが、もし 10000 回 push されたらどうなる? どう直す?

## Q3: SimpleList の insert を「tail 側 (nil の直前)」に変えると forward の出力はどう変わる? backward は?

## Q4: PointComparator に第 3 の「ZComparator (z 座標)」を追加できる? Point に z を足す必要はある?

(答えはコード書いて手で確認、または先生に聞く)

---

# 参考: 自分で書く時の手順

1. 問題文を読んで「何を Submit するか」を先に確認
2. interface を先に書く (契約)
3. 実装クラスを書く (compile error が出たら interface の契約を満たしていない)
4. Application (main) を書いて動作確認
5. 期待出力と完全一致するか目視 + diff
6. zip にまとめる (今回は `s1330096_ex08.zip` 形式)

---

最後に: interface と polymorphism は Java の核心です。Ex09 (Polymorphism Part 2) でも同じ思想を使うので、Ex07 と Ex08 の問題を**自力で 2 回書き直す**と完全に体に入ります。テスト前に焦らないよう、今のうちに手を動かしてください。
