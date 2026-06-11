# Ch07: Interfaces

## What is an Interface?

An interface is a contract specifying which methods a class must provide, without specifying how. In its most common form, it is a group of related methods with empty bodies.

### Class hierarchy motivation

```
            Bicycle
   ┌──────────┼──────────┐
RoadBike  MountainBike  TandemBike
```

All bicycles share: current speed, current pedal cadence, current gear.

### Bicycle as a regular class

```java
class Bicycle {
    private int cadence, speed, gear;

    public Bicycle(int startCadence, int startSpeed, int startGear) {
        gear = startGear;
        cadence = startCadence;
        speed = startSpeed;
    }
    public void changeCadence(int newValue) { cadence = newValue; }
    public void changeGear(int newValue)    { gear = newValue; }
    public void speedUp(int increment)      { speed = speed + increment; }
    public void applyBrakes(int decrement)  { speed = speed - decrement; }
    public void printStates() {
        System.out.println("cadence:" + cadence + " speed:" + speed + " gear:" + gear);
    }
}
```

### MountainBike as a subclass

```java
public class MountainBike extends Bicycle {
    private int seatHeight;

    public MountainBike(int startHeight, int startCadence, int startSpeed, int startGear) {
        super(startCadence, startSpeed, startGear);
        seatHeight = startHeight;
    }
    public void setHeight(int newValue) { seatHeight = newValue; }
}
```

All fields and methods of Bicycle are inherited.

## Bicycle as an Interface

```java
interface BicycleInterface {
    void changeCadence(int newValue);
    void changeGear(int newValue);
    void speedUp(int increment);
    void applyBrakes(int decrement);
}
```

To use the interface, write a class with `implements`:

```java
class ACMEBicycle implements BicycleInterface {
    private int cadence, speed, gear;

    public ACMEBicycle(int startCadence, int startSpeed, int startGear) {
        gear = startGear;
        cadence = startCadence;
        speed = startSpeed;
    }
    public void changeCadence(int newValue) { cadence = newValue; }
    public void changeGear(int newValue)    { gear = newValue; }
    public void speedUp(int increment)      { speed = speed + increment; }
    public void applyBrakes(int decrement)  { speed = speed - decrement; }
    public void printStates() {
        System.out.println("cadence:" + cadence + " speed:" + speed + " gear:" + gear);
    }
}
```

If a class claims to implement an interface, all the interface's methods must appear in the class. This contract is enforced by the compiler at build time.

## Why Interfaces Exist

In software engineering, disparate teams often need a contract spelling out how their software interacts. Each team should write code without knowing how the other team's code is written. Interfaces are such contracts.

## Interfaces in Java

An interface is a reference type, similar to a class, that can contain only:

- constants
- method signatures
- nested types

There are no method bodies. Interfaces cannot be instantiated. They can only be:

- implemented by classes
- extended by other interfaces

### Robotic car example

```java
public interface OperateCar {
    int turn(Direction direction, double radius, double startSpeed, double endSpeed);
    int changeLanes(Direction direction, double startSpeed, double endSpeed);
    int signalTurn(Direction direction, boolean signalOn);
    int getRadarFront(double distanceToCar, double speedOfCar);
    int getRadarRear(double distanceToCar, double speedOfCar);
    // more method signatures
}
```

```java
public class OperateBMW760i implements OperateCar {
    public int signalTurn(Direction direction, boolean signalOn) {
        // BMW-specific implementation
    }
    // implement all other OperateCar methods
}
```

Multiple manufacturers (Chevrolet, Toyota) can implement the same interface differently. Clients of the interface (the guidance system) call the same methods regardless of who built the car.

## Interfaces and Multiple Inheritance

- Java does not permit multiple inheritance of classes.
- A class can implement more than one interface.
- An object's types = its own class type plus every interface it implements.
- A variable declared as an interface type can reference any object whose class implements that interface.

### An interface extending other interfaces

```java
public interface GroupedInterface extends Interface1, Interface2, Interface3 {
    double E = 2.718282;             // constant
    void doSomething(int i, double x);
    int doSomethingElse(String s);
}
```

## Sample Interface: Relatable

```java
public interface Relatable {
    // returns 1 / 0 / -1 if this is greater than / equal to / less than other
    public int isLargerThan(Relatable other);
}
```

Any class can implement Relatable if there is some way to compare relative size:

- Strings: number of characters
- Books: number of pages
- Students: weight
- Planar shapes: area
- 3D shapes: volume

### Implementation: RectanglePlus

```java
public class RectanglePlus implements Relatable {
    private int width = 0;
    private int height = 0;
    private Point origin;

    public RectanglePlus() {
        origin = new Point(0, 0);
    }
    public int getArea() {
        return width * height;
    }
    public int isLargerThan(Relatable other) {
        RectanglePlus otherRect = (RectanglePlus) other;
        if (this.getArea() < otherRect.getArea()) return -1;
        else if (this.getArea() > otherRect.getArea()) return 1;
        else return 0;
    }
}
```

## Using an Interface as a Type

Defining an interface = defining a new reference type. You can use an interface name anywhere a type is expected. If you declare a variable of an interface type, any object you assign to it must be an instance of a class that implements that interface.

```java
public Object findLargest(Object object1, Object object2) {
    Relatable obj1 = (Relatable) object1;
    Relatable obj2 = (Relatable) object2;
    if ((obj1).isLargerThan(obj2) > 0)
        return object1;
    else
        return object2;
}
```

This method works for any "relatable" objects — they have behavior from both their own superclass AND the interface, similar to multiple inheritance.

## Rewriting Interfaces

If you add a method to an existing interface, every existing implementing class breaks (it no longer satisfies the contract). The fix is to extend the interface instead:

```java
public interface DoIt {
    void doSomething(int i, double x);
    int doSomethingElse(String s);
}
```

```java
public interface DoItPlus extends DoIt {
    boolean didItWork(int i, double x, String s);
}
```

Existing users keep DoIt; new users adopt DoItPlus. Try to specify the interface completely from the beginning to avoid this.

## Abstract Classes vs. Interfaces

| Abstract Class | Interface |
|---|---|
| Fields can be non-static and non-final | All fields are static and final |
| Used when classes have an "is-a" relationship | Implemented by unrelated classes |
| Cannot extend more than one | Can implement more than one |
| Can implement some methods | Cannot implement methods (in this course's scope) |
| Constrains class identity | Extends class functionality |

### Partial implementation pattern

A class that implements an interface must implement all the interface's methods unless the class is declared abstract:

```java
abstract class X implements Y {
    // implements all but one method of Y
}
class XX extends X {
    // implements the remaining method in Y
}
```

X must be abstract because it does not fully implement Y. XX is concrete and finishes the job.

## Summary

- An interface defines a protocol of communication: signatures only, no implementation.
- A class that implements an interface must implement all declared methods.
- An interface name can be used anywhere a type can be used.

These two declarations are equivalent. In an interface, fields are implicitly `public static final`, and methods are implicitly `public abstract`:

```java
public interface T1 {
    public static final int K = 1;
    public abstract void p();
}
```

```java
public interface T1 {
    int K = 1;
    void p();
}
```

## UML Notation

Two notations:

1. `<<interface>>` stereotype above the name in a UML class box.
2. A dashed arrow labeled "implements" from a class to an interface.

```java
interface Relatable {
    int isLargerThan();
}

class Point implements Relatable {
    int isLargerThan(Relatable r) {
        // ...
    }
}
```
