# Polymorphism Part 2

## 範囲

- Examples
- The Mechanics of Polymorphism
- Abstract Classes
- Private and Static Methods
- Order of Constructor Calls
- Designing Classes
- Summary of Polymorphism

## Polymorphism の復習

Polymorphism は「多態性」。同じコードが複数の型のオブジェクトに対して使われ、実際のオブジェクト型によって異なる動作をすること。

```java
Person p = new Student("Saito", "s115333");
p.introduction(); // Student 側の introduction が呼ばれる
```

参照型は `Person` でも、実体が `Student` ならオーバーライドされた `Student` のメソッドが動く。

## Example 3: 配列と多態性

```java
class Person {
    private String name;

    public Person(String name) {
        this.name = name;
    }

    public String introduction() {
        return "My name is " + name + ".";
    }
}

class Student extends Person {
    private String id;

    public Student(String name, String id) {
        super(name);
        this.id = id;
    }

    public String getID() {
        return id;
    }

    public String introduction() {
        return "I am a student. " + super.introduction() + " My ID is " + id + ".";
    }
}
```

```java
Person[] people = {
    new Person("Suzuki"),
    new Student("Tanaka", "s116000"),
    new Person("Murakawa")
};

for (int i = 0; i < people.length; i++) {
    System.out.println(people[i].introduction());
}
```

`people[1]` の参照型は `Person` だが、実体は `Student`。そのため `Student.introduction()` が呼ばれる。

## Example 4: 呼び出し元メソッド内でも dynamic binding

```java
class Person {
    public String introduction() {
        return "My name is ...";
    }

    public String getInfo() {
        return introduction();
    }
}
```

`getInfo()` は `Person` にあるメソッドだが、その中で呼ばれる `introduction()` は実体の型で決まる。

```java
Student s = new Student("Saito", "s115333");
Person p = s;

System.out.println(s.getInfo());
System.out.println(p.getInfo());
```

どちらも `Student.introduction()` を使った結果になる。

ただし、次はコンパイルエラー。

```java
System.out.println(p.getID()); // Person 型には getID がない
```

重要:

- コンパイル時に呼べるメソッドは参照型で決まる。
- 実行時にどの実装が呼ばれるかは実体型で決まる。

## Abstract Classes

抽象クラスは `abstract` で宣言され、直接インスタンス化できない。

```java
abstract class GraphicObject {
    int x, y;

    void moveTo(int newX, int newY) {
        // common implementation
    }

    abstract void draw();
    abstract void resize();
}
```

抽象メソッドは実装なしで宣言される。

```java
abstract void draw();
```

サブクラスは抽象メソッドを実装する必要がある。実装しない場合、そのサブクラスも `abstract` にする必要がある。

## Abstract Class Example: Animal

```java
abstract class Animal {
    private String name;

    public Animal(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public abstract void talk();
}
```

```java
class Dog extends Animal {
    public Dog(String name) {
        super(name);
    }

    public void talk() {
        System.out.println(getName() + " Woof");
    }
}
```

```java
Animal ref = new Cow("Edna");
ref.talk(); // Edna Moo

ref = new Dog("Humi");
ref.talk(); // Humi Woof

ref = new Cat("Aya");
ref.talk(); // Aya Meow
```

`Animal` 型の参照で、`Cow`, `Dog`, `Cat` を扱える。

## Private Methods

private method はサブクラスから見えない。したがって override されない。

```java
public class PrivateOverride {
    private void f() {
        System.out.println("private f()");
    }

    public static void main(String[] args) {
        PrivateOverride po = new Derived();
        po.f();
    }
}

class Derived extends PrivateOverride {
    public void f() {
        System.out.println("public f()");
    }
}
```

出力:

```text
private f()
```

`Derived.f()` は override ではなく、まったく別の新しいメソッド。

## Static Methods

static method は polymorphic に振る舞わない。クラスに属するため、参照型で決まる。

```java
class Mother {
    public static String staticGet() {
        return "Mother staticGet()";
    }

    public String dynamicGet() {
        return "Mother dynamicGet()";
    }
}

class Child extends Mother {
    public static String staticGet() {
        return "Child staticGet()";
    }

    public String dynamicGet() {
        return "Child dynamicGet()";
    }
}
```

```java
Mother child = new Child();
System.out.println(child.staticGet());
System.out.println(child.dynamicGet());
```

出力:

```text
Mother staticGet()
Child dynamicGet()
```

## Constructor Call Order

複雑なオブジェクトのコンストラクタ呼び出し順:

1. base-class constructor が呼ばれる。継承階層の root から順に構築される。
2. member initializers が宣言順に呼ばれる。
3. derived-class constructor の body が実行される。

例:

```java
class Meal {
    Meal() { System.out.println("Meal()"); }
}

class Lunch extends Meal {
    Lunch() { System.out.println("Lunch()"); }
}

class PortableLunch extends Lunch {
    PortableLunch() { System.out.println("PortableLunch()"); }
}

public class Sandwich extends PortableLunch {
    private Bread b = new Bread();
    private Cheese c = new Cheese();
    private Lettuce l = new Lettuce();

    public Sandwich() {
        System.out.println("Sandwich()");
    }
}
```

出力:

```text
Meal()
Lunch()
PortableLunch()
Bread()
Cheese()
Lettuce()
Sandwich()
```

## Designing Classes: HAS-A vs IS-A

### IS-A

継承で表現する。

```text
Dog is an Animal.
Student is a Person.
```

### HAS-A

Composition で表現する。

```text
Car has an Engine.
Stage has an Actor.
```

基本方針:

- inheritance は behavior の違いを表す時に使う。
- fields / composition は state の違いを表す時に使う。
- 迷ったら composition を先に考える。

## Composition と動的な振る舞い

```java
abstract class Actor {
    public abstract void act();
}

class HappyActor extends Actor {
    public void act() {
        System.out.println("HappyActor");
    }
}

class SadActor extends Actor {
    public void act() {
        System.out.println("SadActor");
    }
}

class Stage {
    private Actor actor = new HappyActor();

    public void change() {
        actor = new SadActor();
    }

    public void performPlay() {
        actor.act();
    }
}
```

`Stage` は `Actor` を持つ。`actor` の参照先を実行時に変えられるため、振る舞いも変わる。

## 試験で出そうな注意点

- 参照型で呼べるメソッドが決まる。
- override されたインスタンスメソッドは実体型で決まる。
- private method は override されない。
- static method は dynamic binding されない。
- constructor は親から子へ呼ばれる。
- メンバ初期化はコンストラクタ本体より先。
- IS-A は継承、HAS-A は composition。
