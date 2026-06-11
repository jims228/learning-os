# Exercise 1 — Introduction to Java

## Problem A: Welcome to Java! [1 pt]
Create the simplest Java program: a source file that generates `WelcomeJava.class`.
- Just create a source file that can be compiled.
- **Submit:** `WelcomeJava.java`

## Problem B: Standard Output: Hello World [1 pt]
Create a program that outputs "Hello World". Class name: `HelloWorld`.

Template:
```java
class HelloWorld{
    public static void main(String[] args){
        // your codes
    }
}
```

- Use `System.out.println("Hello World");`
- **Submit:** `HelloWorld.java`

## Problem C: Simple Calculation [1 pt]
Fahrenheit to Celsius conversion: `Celsius = (5.0 / 9) * (Fahrenheit - 32)`

Template:
```java
import java.util.Scanner;
class Fahrenheit{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int F = sc.nextInt();
        // your code
    }
}
```

| Sample Input | Sample Output |
|---|---|
| 77 | 25.0 |
| 80 | 26.6667 |
| 91 | 32.7778 |
| 108 | 42.2222 |

- **Submit:** `Fahrenheit.java`

## Problem D: Basic Program [1 pt]
Write a program to factorize a given integer n.
- Print n and ':' then prime factors in ascending order separated by spaces.

| Sample Input | Sample Output |
|---|---|
| 12 | 12: 2 2 3 |
| 126 | 126: 2 3 3 7 |
| 1234567890 | 1234567890: 2 3 3 5 3607 3803 |
| 1000000000 | 1000000000: 2 2 2 2 2 2 2 2 2 5 5 5 5 5 5 5 5 5 |

- **Submit:** `PrimeFactorizer.java`
