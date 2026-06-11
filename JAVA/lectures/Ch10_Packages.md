# Ch10: Packages

## What is a Package?

A package is a namespace that organizes a set of related classes and interfaces. Conceptually similar to folders on your computer.

Reasons to use packages:

- Make types easier to find and use
- Avoid naming conflicts
- Control access

"Types" includes classes, interfaces, enumerations, and annotation types.

### Java standard packages
- `java.lang` — fundamental classes (auto-imported)
- `java.io` — input/output
- and many more

## Creating and Using Packages

Suppose you have graphics classes (Circle, Rectangle, Line, Point) and an interface Draggable. Reasons to bundle them in a `graphics` package:

- Other programmers can tell these types are related
- They know where to find graphics-related functionality
- Type names don't conflict with names in other packages (new namespace)
- Types within the package can access each other freely; outside access can be restricted

### How to create a package

1. Choose a name for the package
2. Put `package <name>;` at the top of every source file
3. The package statement must be the first line in the file
4. Only one package statement per file, applies to all types in the file

### Example

```java
// in Draggable.java
package graphics;
public interface Draggable {
    ...
}
```

```java
// in Circle.java
package graphics;
public class Circle extends Graphic implements Draggable {
    ...
}
```

All 6 files (Draggable, Graphic, Circle, Rectangle, Point, Line) start with `package graphics;`.

## Naming Conventions

- Package names are all lowercase to avoid conflict with class/interface names
- Companies use reversed domain names: `com.example.orion`
- Java's own packages: `java.` or `javax.`

## Using Package Members

To use a public type from a different package, choose one of three:

### 1. Fully qualified name
```java
graphics.Rectangle myRect = new graphics.Rectangle();
```

### 2. Import a specific member
```java
import graphics.Rectangle;
...
Rectangle myRect = new Rectangle();
```

### 3. Import the whole package
```java
import graphics.*;
...
Circle c = new Circle();
Rectangle r = new Rectangle();
```

## Packages Imported Automatically

You do NOT need an `import` statement for:

- The package with no name (the "default" or unnamed package)
- `java.lang` (System, String, etc.)
- The current package (the file's own package)

## Apparent Hierarchies (NOT Real)

Package names look hierarchical but are not. Example:

- `java.awt`
- `java.awt.color`
- `java.awt.font`

```java
import java.awt.*;  // does NOT import java.awt.color or java.awt.font
```

To use all three, you must import them all separately:

```java
import java.awt.*;
import java.awt.color.*;
import java.awt.font.*;
```

## Managing Source and Class Files

Package name determines directory structure:

| Qualified name | File path |
|---|---|
| `graphics.Rectangle` | `graphics/Rectangle.java` |
| `com.example.graphics.Rectangle` | `com/example/graphics/Rectangle.java` |

After compilation, .class files live in mirrored directories under your output root.

### Simple example

```
/home/.../Ex08/demopackage/ClassOne.java   (package demopackage;)
/home/.../Ex08/demopackage/ClassTwo.java   (package demopackage;)
/home/.../Ex08/UsageDemoPackage.java       (import demopackage.*;)
```

Compile and run from `/home/.../Ex08/`:
```
javac UsageDemoPackage.java
java UsageDemoPackage
```

## Class Path

- The full path to the root containing your package directories is called the class path.
- Set via the `CLASSPATH` environment variable.
- The compiler / JVM also search the current directory and the platform's JAR files by default.

If your package is `com.example.graphics` and classpath is `<root>/classes`, the JVM looks for class files in `<root>/classes/com/example/graphics/`.

## Access Modifiers (Review)

| Modifier | Same class | Same package | Subclass (any pkg) | Anywhere |
|---|---|---|---|---|
| `public`    | Y | Y | Y | Y |
| `protected` | Y | Y | Y | N |
| (none)      | Y | Y | N | N |
| `private`   | Y | N | N | N |

Mnemonic for "(none)" — also called "package-private":
- Accessible only inside the same package, regardless of subclass relationship.

## Summary

- `package <name>;` at the top of every source file groups types into one namespace.
- To use a public type from another package: fully qualified name, `import` the member, or `import <pkg>.*`.
- The directory structure of source and class files mirrors the package name.
- Access modifiers control which classes can see members.
