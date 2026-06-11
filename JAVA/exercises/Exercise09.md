# Exercise 9 — Polymorphism, Binding, Design Patterns

## Objectives
動的バインディングを理解し、クラスを再利用する設計パターンを学ぶ。

---

## Problem A: Sorting Machine [3 pt]

`SortingApplication` は N 個のランダムな整数を昇順にソートするアプリ。`SortingMachine` はコンストラクタまたは `setStrategy` でソートアルゴリズムを切り替えられる。

### 渡されるクラス (修正禁止)

```java
class SortingApplication {
    private static int N = 1000;
    public SortingApplication() {
        Judge judge = new Judge(N);
        int[] data = new int[N];
        SortingMachine machine = new SortingMachine(new SelectionSort());
        judge.setData(data);
        machine.sort(data);
        judge.validate(data);

        machine.setStrategy(new BubbleSort());
        judge.setData(data);
        machine.sort(data);
        judge.validate(data);
    }
    public static void main(String[] args) {
        new SortingApplication();
    }
}
```

```java
class SortingMachine {
    protected Strategy strategy;
    public SortingMachine(Strategy s) { strategy = s; }
    public void setStrategy(Strategy s) { strategy = s; }
    public void sort(int[] data) {
        System.out.println(strategy.getClass().getName());
        strategy.sort(data);
    }
}
```

```java
import java.util.Random;
import java.util.Arrays;
class Judge {
    private int N;
    private int[] in, out;
    public Judge(int N) {
        this.N = N;
        Random random = new Random();
        in = new int[N];
        for (int i = 0; i < N; i++) in[i] = random.nextInt(1000000000);
        out = in.clone();
        Arrays.sort(out);
    }
    public void setData(int[] data) {
        for (int i = 0; i < N; i++) data[i] = in[i];
    }
    public void validate(int[] data) {
        String res = "Yes";
        for (int i = 0; i < N; i++)
            if (data[i] != out[i]) res = "No";
        System.out.println(res);
    }
}
```

### 作るもの
- `Strategy.java` (Java Interface)
- `SelectionSort.java`
- `BubbleSort.java`

### Class diagram
```
SortingMachine
  strategy: Strategy
  setStrategy()
  sort()

<<interface>> Strategy
  sort()

SelectionSort implements Strategy
  sort()

BubbleSort implements Strategy
  sort()
```

### Sample Output
```
SelectionSort
Yes
BubbleSort
Yes
```

### Submission files
- SortingMachine.java
- SortingApplication.java
- Judge.java
- SelectionSort.java
- BubbleSort.java
- Strategy.java

---

## Problem B: Sorting Machine+ [4 pt]

Problem A を 2 方向に拡張する。
- `SortingMachine` を `AdvancedSortingMachine` で拡張
- 新しいアルゴリズム `MergeSort` を追加

### 渡されるクラス
```java
import java.util.Scanner;
class SortingApplicationPlus {
    private int N;
    public SortingApplicationPlus() {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        String algorithm = sc.next();
        SortingMachine machine = new AdvancedSortingMachine(new SelectionSort());
        if (algorithm.equals("bubble")) {
            machine.setStrategy(new BubbleSort());
        } else if (algorithm.equals("merge")) {
            machine.setStrategy(new MergeSort());
        }
        int[] data = new int[N];
        Judge judge = new Judge(N);
        judge.setData(data);
        machine.sort(data);
        judge.validate(data);
    }
    public static void main(String[] args) {
        new SortingApplicationPlus();
    }
}
```

### 作るもの
- `AdvancedSortingMachine` … sort 実行時間を `System.currentTimeMillis()` で測って出力。
- `MergeSort` … Strategy を実装。

### Sample I/O
```
Input:  30000 selection
Output: SelectionSort
        time: 445
        Yes

Input:  30000 bubble
Output: BubbleSort
        time: 1408
        Yes

Input:  30000 merge
Output: MergeSort
        time: 13
        Yes

Input:  100000 selection
Output: SelectionSort
        time: 4769
        Yes

Input:  100000 merge
Output: MergeSort
        time: 33
        Yes
```

### Submission files
- SortingMachine.java
- AdvancedSortingMachine.java
- SortingApplicationPlus.java
- Judge.java
- SelectionSort.java
- BubbleSort.java
- MergeSort.java
- Strategy.java

---

## Problem C: Adapter [5 pt]

`ContainerApplication` は Deque, Queue, Stack を作って挿入・削除をシミュレートする。

### 渡される ContainerApplication

```java
import java.util.Scanner;
class ContainerApplication {
    public static void main(String[] args) {
        new ContainerApplication().run();
    }
    public void run() {
        Scanner sc = new Scanner(System.in);
        Deque deque = new DequeImplByDLL();
        Queue queue = new QueueImplByDeque();
        Stack stack = new StackImplByDeque();
        while (true) {
            String to = sc.next();
            if (to.equals("end")) break;
            String com = sc.next();
            if (to.equals("deque")) {
                if (com.equals("insertFront")) deque.insertFront(sc.nextInt());
                else if (com.equals("insertBack")) deque.insertBack(sc.nextInt());
                else if (com.equals("removeFront")) deque.removeFront();
                else if (com.equals("removeBack")) deque.removeBack();
                else if (com.equals("front")) System.out.println(deque.front() + " from the front of the deque.");
                else if (com.equals("back")) System.out.println(deque.back() + " from the back of the deque.");
            } else if (to.equals("stack")) {
                if (com.equals("push")) stack.push(sc.nextInt());
                else if (com.equals("pop")) System.out.println(stack.pop() + " from the top of the stack.");
            } else if (to.equals("queue")) {
                if (com.equals("enqueue")) queue.enqueue(sc.nextInt());
                else if (com.equals("dequeue")) System.out.println(queue.dequeue() + " from the front of the queue.");
            }
        }
    }
}
```

### Interfaces

```java
public interface Deque {
    void insertFront(int key);
    void insertBack(int key);
    void removeFront();
    void removeBack();
    int front();
    int back();
    int size();
    boolean empty();
}

public interface Stack {
    void push(int x);
    int pop();
    int top();
    int size();
    boolean empty();
}

public interface Queue {
    void enqueue(int key);
    int dequeue();
    int front();
    int size();
    boolean empty();
}
```

### 渡される SimpleDoublyLinkedList

```java
class SimpleDoublyLinkedList {
    private SimpleNode nil;
    SimpleDoublyLinkedList() {
        nil = new SimpleNode();
        nil.setNext(nil);
        nil.setPrev(nil);
    }
    private void deleteNode(SimpleNode t) {
        t.getPrev().setNext(t.getNext());
        t.getNext().setPrev(t.getPrev());
    }
    public void removeFront() { deleteNode(nil.getNext()); }
    public void removeBack() { deleteNode(nil.getPrev()); }
    public int front() { return nil.getNext().getKey(); }
    public int back()  { return nil.getPrev().getKey(); }
    public void addFront(int key) {
        SimpleNode x = new SimpleNode();
        x.setKey(key);
        x.setNext(nil.getNext());
        nil.getNext().setPrev(x);
        nil.setNext(x);
        x.setPrev(nil);
    }
    public void addBack(int key) {
        SimpleNode x = new SimpleNode();
        x.setKey(key);
        x.setPrev(nil.getPrev());
        nil.getPrev().setNext(x);
        nil.setPrev(x);
        x.setNext(nil);
    }
}
```

注: SimpleNode の実装 (getKey/setKey/getNext/setNext/getPrev/setPrev) は自作する必要あり。

### 作るもの
- `DequeImplByDLL implements Deque` — SimpleDoublyLinkedList をラップする Adapter
- `StackImplByDeque implements Stack` — Deque をラップする Adapter
- `QueueImplByDeque implements Queue` — Deque をラップする Adapter
- `SimpleNode` — リンクリストのノード

### スケルトン

```java
class DequeImplByDLL implements Deque {
    private SimpleDoublyLinkedList list;
    private int n;
    DequeImplByDLL() {
        list = new SimpleDoublyLinkedList();
        n = 0;
    }
    /* your codes */
}
```

```java
class StackImplByDeque implements Stack {
    private Deque deque;
    StackImplByDeque() {
        this.deque = new DequeImplByDLL();
    }
    /* your codes */
}
```

### Sample I/O (一部)

```
Input:                          Output:
deque insertFront 3
deque insertFront 2
deque insertFront 1
deque insertBack 4
deque insertBack 5
deque removeFront
deque removeFront
deque removeBack
deque front                     3 from the front of the deque.
deque back                      4 from the back of the deque.
deque insertFront 8
deque insertFront 9
deque removeBack
deque removeBack
deque removeBack
deque front                     9 from the front of the deque.
deque back                      9 from the back of the deque.
stack push 1
stack push 5
stack push 3
stack pop                       3 from the top of the stack.
stack pop                       5 from the top of the stack.
stack push 8
stack push 11
stack pop                       11 from the top of the stack.
stack pop                       8 from the top of the stack.
stack pop                       1 from the top of the stack.
queue enqueue 100
queue enqueue 101
queue enqueue 102
queue dequeue                   100 from the front of the queue.
queue enqueue 300
queue dequeue                   101 from the front of the queue.
queue enqueue 301
queue enqueue 302
queue dequeue                   102 from the front of the queue.
queue dequeue                   300 from the front of the queue.
queue dequeue                   301 from the front of the queue.
end
```

### Submission files
- ContainerApplication.java
- SimpleDoublyLinkedList.java
- SimpleNode.java
- DequeImplByDLL.java
- StackImplByDeque.java
- QueueImplByDeque.java
- Deque.java
- Stack.java
- Queue.java

---

## ポイント整理

- Problem A は interface 1 つ + sort クラス 2 つ。素直に書ける。
- Problem B は A の拡張 + System.currentTimeMillis() で時間計測。
- Problem C は Adapter パターン。SimpleDoublyLinkedList をラップする 3 段構造。
