# Exercise 10 — Packages

## Objectives
Classes と interfaces を package にまとめる方法、 package 内の class の使い方を学ぶ。

---

## Problem A: Creating a Package [2 pt]

以下の 2 クラスをそれぞれ指定された package に入れる。

```java
public class A {
    public void print() {
        System.out.println("This is A.");
    }
}
```

```java
public class B {
    public B() {
        A a = new A();
        a.print();
    }
    public static void main(String[] args) {
        new B();
    }
}
```

### Package 割り当て
| Package Name | Class Name |
|---|---|
| package_a | A |
| package_b | B |

### 提出
- `package_a/A.java`
- `package_b/B.java`

正しく compile + run できるように適切な `package` 文と `import` 文を追加する必要がある。

---

## Problem B: Access Control [3 pt]

Alpha, Beta, Gamma, Delta の 4 クラスを以下の条件で完成させる。

### 条件
- Alpha.x: Alpha のみ直接アクセス可
- Alpha.z: Alpha と Gamma のみ直接アクセス可
- Gamma.w: Alpha と Gamma のみ直接アクセス可
- Alpha.u: Alpha, Gamma, Beta のみ直接アクセス可
- Beta.y: Beta のみ直接アクセス可
- Beta は Alpha の subclass
- Gamma.v: すべての class からアクセス可
- Delta と Beta は同じ package

"直接アクセス可" = dot operator (例: `a.x`) または simple name (例: `x`) でアクセス可。method 経由は含まない。

### テンプレート

```java
package ________;
public class Alpha {
    ________ int u = 30;
    ________ int x = 120;
    ________ int z = 86;
    public void show(Gamma g) {
        System.out.println("Alpha");
        System.out.println("u: " + u);
        System.out.println("v: " + g.v);
        System.out.println("w: " + g.w);
        System.out.println("x: " + x);
        System.out.println("z: " + z);
        System.out.println();
    }
}
```

```java
package ________;
public class Gamma {
    ________ int v = 1000;
    ________ int w = 777;
    public void show(Alpha a) {
        System.out.println("Gamma");
        System.out.println("u: " + a.u);
        System.out.println("v: " + v);
        System.out.println("w: " + w);
        System.out.println("z: " + a.z);
        System.out.println();
    }
}
```

```java
package ________;
import ________;
import ________;
public class Beta extends Alpha {
    ________ int y = 30;
    public void show(Gamma g) {
        System.out.println("Beta");
        System.out.println("u: " + u);
        System.out.println("v: " + g.v);
        System.out.println("y: " + y);
        System.out.println();
    }
}
```

```java
package ________;
import ________;
import ________;
public class Delta {
    Alpha alpha = new Alpha();
    Beta beta = new Beta();
    Gamma gamma = new Gamma();
    public Delta() {
        alpha.show(gamma);
        beta.show(gamma);
        gamma.show(alpha);
    }
    public static void main(String[] args) {
        new Delta();
    }
}
```

### 期待出力
```
Alpha
u: 30
v: 1000
w: 777
x: 120
z: 86

Beta
u: 30
v: 1000
y: 30

Gamma
u: 30
v: 1000
w: 777
z: 86
```

### 提出
- `????/Alpha.java`
- `????/Beta.java`
- `????/Gamma.java`
- `????/Delta.java`

---

## Problem C: Template Method [4 pt]

2 分木のノードを巡る algorithms の template。

```java
package template;
public abstract class BinaryTreeTraverser {
    public abstract void initialize();
    public abstract void finalize();
    public void performPre(BinaryTreeNode u)  { /* hook */ }
    public void performIn(BinaryTreeNode u)   { /* hook */ }
    public void performPost(BinaryTreeNode u) { /* hook */ }

    public void run(BinaryTreeNode s) {
        initialize();
        parse(s);
        finalize();
    }

    private void parse(BinaryTreeNode u) {
        if (u == null) return;
        performPre(u);
        parse(u.getLeftChild());
        performIn(u);
        parse(u.getRightChild());
        performPost(u);
    }
}
```

### 作るもの
- `PreOrderTraversal` — pre-order
- `InOrderTraversal` — in-order
- `PostOrderTraversal` — post-order
- `EulerTour` — pre + post (= performPre と performPost の両方)

### 提供されるもの

```java
package template;
public interface BinaryTreeNode {
    public BinaryTreeNode getLeftChild();
    public BinaryTreeNode getRightChild();
    public Integer getKey();
}
```

```java
package impl;
import template.BinaryTreeNode;
public class SimpleTreeNode implements BinaryTreeNode {
    private SimpleTreeNode leftChild;
    private SimpleTreeNode rightChild;
    private Integer key;
    public SimpleTreeNode(int key) { this.key = key; }
    public BinaryTreeNode getLeftChild()  { return leftChild; }
    public BinaryTreeNode getRightChild() { return rightChild; }
    public Integer getKey() { return key; }
    public void addLeftChild(SimpleTreeNode c)  { leftChild = c; }
    public void addRightChild(SimpleTreeNode c) { rightChild = c; }
}
```

```java
package impl;
import template.BinaryTreeTraverser;
import template.BinaryTreeNode;
public class BinaryTreeTraverseApplication {
    public void run() {
        SimpleTreeNode[] T = new SimpleTreeNode[9];
        for (int i = 0; i < 9; i++) T[i] = new SimpleTreeNode(i);
        T[0].addLeftChild(T[1]);
        T[0].addRightChild(T[2]);
        T[1].addLeftChild(T[5]);
        T[1].addRightChild(T[7]);
        T[2].addLeftChild(T[3]);
        T[2].addRightChild(T[4]);
        T[3].addLeftChild(T[6]);
        T[3].addRightChild(T[8]);
        BinaryTreeTraverser[] traversers = {
            new PreOrderTraversal(),
            new InOrderTraversal(),
            new PostOrderTraversal(),
            new EulerTour()
        };
        for (BinaryTreeTraverser t : traversers) {
            t.run(T[0]);
            System.out.println();
        }
    }
    public static void main(String[] args) {
        new BinaryTreeTraverseApplication().run();
    }
}
```

### 期待出力
```
Begin Pre-order Traversal
0 1 5 7 2 3 6 8 4
End Pre-order Traversal

Begin In-order Traversal
5 1 7 0 6 3 8 2 4
End In-order Traversal

Begin Post-order Traversal
5 7 1 6 8 3 4 2 0
End Post-order Traversal

Begin Euler Tour
0 1 5 5 7 7 1 2 3 6 6 8 8 3 4 4 2 0
End Euler Tour
```

### 提出
- `template/BinaryTreeNode.java`
- `template/BinaryTreeTraverser.java`
- `impl/SimpleTreeNode.java`
- `impl/PreOrderTraversal.java`
- `impl/InOrderTraversal.java`
- `impl/PostOrderTraversal.java`
- `impl/EulerTour.java`
- `impl/BinaryTreeTraverseApplication.java`
