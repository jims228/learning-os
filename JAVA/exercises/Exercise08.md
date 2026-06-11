# Exercise 8 — Polymorphism Part 1

## 演習日（C3クラス・公式スケジュール表確定）
- 講義+演習: 05/01 (金) ※ 同日実施
- 締切: 05/08 (金) ※ 演習日から 1 週間以内

---

## Problem A: OpenList [3 pt]

`TreeTraverser` (与えられている) は完全 2 分木 (N=15) を `OpenList` に従って traverse する。`OpenList` interface を実装した `Stack` (LIFO) で深さ優先探索 (DFS)、`Queue` (FIFO) で幅優先探索 (BFS) を行う。

```java
public interface OpenList {
    public void push(int x);
    public int pop();
    public boolean isEmpty();
}
```

| Sample Output |
|---|
| Depth First Search: 0 2 6 14 13 5 12 11 1 4 10 9 3 8 7 |
| Breadth First Search: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 |

**Submit:** `Stack.java`, `Queue.java`, `OpenList.java`, `TreeTraverser.java`, `TreeTraverseApplication.java`

---

## Problem B: Sorting Points by Comparator [3 pt]

`PointComparator` interface を実装した `XYComparator` と `YXComparator` を作る。

| クラス | 比較基準 |
|---|---|
| XYComparator | x 優先 → 同値なら y 比較 |
| YXComparator | y 優先 → 同値なら x 比較 |

`SortingPointMachine` (与えられている、選択ソート) は `comparator` を runtime で切替可能 (Strategy Pattern)。

| Sample Input | Sample Output |
|---|---|
| 8 / 7 5 / 3 5 / 1 2 / 4 8 / 4 1 / 11 9 / 6 6 / 2 1 | Sorted by X-Y: (1,2)(2,1)(3,5)(4,1)(4,8)(6,6)(7,5)(11,9) / Sorted by Y-X: (2,1)(4,1)(1,2)(3,5)(7,5)(6,6)(4,8)(11,9) |

**Submit:** `PointComparator.java`, `XYComparator.java`, `YXComparator.java`, `Point.java`, `SortingPointMachine.java`, `SortingPointApplication.java`

---

## Problem C: Iterator [4 pt]

Iterator パターンの実装。
- `Aggregate` interface: `forwardIterator()` / `backwardIterator()`
- `Iterator` interface: `hasNext()` / `next()`
- `SimpleList` は `Aggregate` 実装、双方向循環連結リスト (sentinel `nil` ベース)
- `SimpleListForwardIterator` (与えられている) と `SimpleListBackwardIterator` (作る)
- `SimpleNode` は key + next + prev

`insert(key)` は head 側 (nil の直後) に追加 = 新しい挿入が forward の先頭に来る。

| Sample Input (13) | Sample Output |
|---|---|
| insert 2,3,5,7,11 / delete 3 / insert 13,17,23 / delete 17 / insert 29,31 / delete 17 (no-op) | forward: 31 29 23 13 11 7 5 2 / backward: 2 5 7 11 13 23 29 31 |

**Submit:** `SimpleNode.java`, `SimpleList.java`, `Iterator.java`, `Aggregate.java`, `SimpleListForwardIterator.java`, `SimpleListBackwardIterator.java`, `IteratorApplication.java`

---

## Summary
- Polymorphism = 同じ呼び出しコードが対象オブジェクトの実際型に応じて違う動きをする
- Strategy Pattern (Problem B): comparator を runtime で差し替え可能
- Iterator Pattern (Problem C): 走査方法 (forward/backward) を Aggregate から分離
- どちらも interface ベースの動的バインディング = polymorphism の典型応用
