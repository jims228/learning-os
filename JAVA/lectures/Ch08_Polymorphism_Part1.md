# Ch08: Polymorphism (Part 1)

## Introduction

Polymorphism = "occurrence of something in multiple forms".

In OOP: the ability for the same code to be used with several different types of objects, behaving differently depending on the actual object used.

## Motivating Example: Drawing Shapes

A program needs to maintain a list of shapes (points, lines, rectangles, circles, ...) and print them on demand.

### In C (without polymorphism)

```c
typedef struct shape {
    int typeS;        // point=0, circle=1, line=2, rectangle=3
    int x, y;
    // ...
} ;
shape varShape;

if (varShape.typeS == 1) DrawCircle(varShape);
else if (varShape.typeS == 3) DrawRectangle(varShape);
else if (varShape.typeS == 0) DrawPoint(varShape);
else if (varShape.typeS == 2) DrawLine(varShape);
```

A type tag plus a long if/else chain.

### Using polymorphism

Just write:

```java
varShape.Draw();
```

The actual draw logic is selected by the runtime type of the object.

## Example 1: Person and Student

```java
class Person {
    private String name;
    public Person(String name) { this.name = name; }
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
    public String getID() { return id; }
    public String introduction() {
        return "I am a student. " + super.introduction() + " My ID is " + id + ".";
    }
}

public class PolymorphismDemo1 {
    public static void main(String[] args) {
        Student s = new Student("Saito", "s115333");
        Person p = s;
        System.out.println(s.introduction());
        System.out.println(p.introduction());
    }
}
```

Output (both lines identical):

```
I am a student. My name is Saito. My ID is s115333.
I am a student. My name is Saito. My ID is s115333.
```

Why? `s` and `p` reference the same Student object — reference assignment copies the reference, not the object. The same `introduction()` is sent to the same Student.

## Reference Assignment Recap

Primitive assignment copies the value:

```
num1 = 5; num2 = 12;
num2 = num1;     // num1=5, num2=5  (separate copies)
```

Reference assignment copies the reference:

```
obname1 → Contents 1
obname2 → Contents 2
obname2 = obname1;
// both obname1 and obname2 now point to Contents 1
// Contents 2 is unreferenced
```

## Example 2: Method Parameter

```java
public class PolymorphismDemo2 {
    public static void main(String[] args) {
        m(new Student("Saito", "s115333"));
        m(new Person("Tanaka"));
    }
    public static void m(Person x) {
        System.out.println(x.introduction());
    }
}
```

Output:

```
I am a student. My name is Saito. My ID is s115333.
My name is Tanaka.
```

Method `m(Person x)` accepts a Person OR any subtype. At runtime the JVM picks the correct `introduction()` based on the actual object type. This is dynamic binding (also called late binding or dynamic dispatch).

## Static vs. Dynamic Binding

| Binding | When | Methods |
|---|---|---|
| Static (early) | Compile time | static, final, private methods |
| Dynamic (late)  | Run time     | All other instance methods (the default) |

Java instance methods are polymorphic by default. A method is statically bound only if marked `static` or `final` (private implies final).

Two views of polymorphism:

- An object sends a message to another object without caring about the receiver's type.
- The receiving object responds to the message in a way appropriate for its actual type.

## Static Methods Are NOT Polymorphic

A static method can be inherited but cannot be overridden. If a subclass redeclares a static method, the parent version is hidden, not overridden.

```java
class Parent {
    public static void myStaticMethod() { System.out.println("A"); }
    public void myInstanceMethod()      { System.out.println("B"); }
}

public class Child extends Parent {
    public static void myStaticMethod() { System.out.println("C"); }
    public void myInstanceMethod()      { System.out.println("D"); }

    public static void main(String[] args) {
        Parent o1 = new Parent();
        Parent o2 = new Child();    // compile-time type Parent, runtime type Child
        Child  o3 = new Child();

        Parent.myStaticMethod();    // A
        Child.myStaticMethod();     // C
        o1.myStaticMethod();        // A
        o1.myInstanceMethod();      // B
        o2.myStaticMethod();        // A   ← static dispatched on COMPILE-TIME type
        o2.myInstanceMethod();      // D   ← instance dispatched on RUNTIME type
        o3.myStaticMethod();        // C
        o3.myInstanceMethod();      // D

        myStaticMethod();           // C   (called from static main, OK)
        myInstanceMethod();         // Compiler Error (instance call from static context)
    }
}
```

Key takeaway:

- Static methods: dispatched on the variable's compile-time type.
- Instance methods: dispatched on the object's runtime type.

## Method Matching vs. Method Binding

These are two separate steps:

1. Matching (compile time): the compiler picks a method by name + parameter types + count + order.
2. Binding (run time): the JVM picks which class's implementation actually runs.

## Dynamic Binding Search Order

If object `o` is an instance of C1 (subclass of C2, subclass of ..., subclass of Cn = Object) and `o` invokes method `p`:

- The JVM searches C1, C2, ..., Cn in that order.
- The first found implementation is invoked.

The most specific class wins.

## Casting Objects

### Up-casting (implicit, always safe)

A subtype object IS-A supertype object.

```java
Person o = new Student("Saito", "s115333");   // implicit up-cast
m(o);
```

### Down-casting (explicit, may fail at runtime)

A supertype variable might or might not actually reference a subtype.

```java
Person o = new Student("Saito", "s115333");
Student b = o;            // COMPILE ERROR
Student b = (Student) o;  // OK with explicit cast (down-cast)
```

The compiler does not track the runtime type, even when it is obvious to you.

### Apple/Orange analogy

```java
Fruit f;
Apple a = new Apple();
Orange o = new Orange();

f = a;   // up-cast (implicit)
f = o;   // up-cast (implicit)

if (f instanceof Apple) {
    a = (Apple) f;   // down-cast (explicit)
}
```

## The instanceof Operator

Use `instanceof` to test the runtime type before down-casting.

```java
Person p = new Student("Saito", "s115333");
System.out.println(p.getID());     // Compile error: Person has no getID()

if (p instanceof Student) {
    System.out.println("Student ID: " + ((Student) p).getID());
}
```

Why parentheses around `(Student) p`? Casting has lower precedence than dot:

- `((Student) p).getID()` — cast p first, then call getID. Correct.
- `(Student) p.getID()`   — call getID first, then try to cast its return type. Wrong.

## Summary

Polymorphism = "multiple forms":

- Same face: a common interface in the base class.
- Different forms: different overriding method bodies in subclasses.

Polymorphism does not work in isolation. It works only as part of the larger picture of class relationships, inheritance, and dynamic binding.

Reference: Bruce Eckel, Thinking in Java, Chapter 7.
