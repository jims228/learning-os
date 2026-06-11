# Exceptions

## 範囲

- Traditional Error Handling
- Exceptions vs Traditional Error Handling
- What is an Exception?
- Kinds of Exceptions
- Exception Handling Keywords
- Catching and Handling Exceptions
- finally
- throw / throws
- Custom Exceptions
- Exception Chain

## Traditional Error Handling の問題

ファイルを読む処理を考える。

```text
open the file
determine its size
allocate memory
read the file
close the file
```

各ステップで失敗する可能性がある。

- ファイルを開けない
- サイズを取得できない
- メモリを確保できない
- 読み込みに失敗する
- ファイルを閉じられない

従来のエラーコード方式では、通常処理とエラー処理が混ざり、コードが読みにくくなる。

## Exception Handling の利点

通常処理とエラー処理を分離できる。

```java
try {
    openFile();
    readFile();
    closeFile();
} catch (FileOpenFailed e) {
    // handle error
} catch (ReadFailed e) {
    // handle error
}
```

## What is an Exception?

例外は、プログラム実行中に通常の流れを中断するイベント。

エラーが起きると、メソッドは exception object を作り、runtime system に渡す。これを throwing an exception という。

runtime system は call stack を上にたどり、対応する exception handler を探す。

## Catch or Specify Requirement

Checked exception については、次のどちらかが必要。

1. catch する。
2. throws で投げる可能性を宣言する。

```java
public void writeList() throws IOException {
    // ...
}
```

## Kinds of Exceptions

| 種類 | checked? | 説明 |
|---|---|---|
| Checked exception | checked | 予測・回復可能。Catch or Specify Requirement の対象 |
| Error | unchecked | システム障害など。通常は回復不能 |
| Runtime exception | unchecked | ロジックエラーやAPIの誤用 |

`Error`, `RuntimeException`, そのサブクラス以外は checked exception。

## Keywords

| keyword | 意味 |
|---|---|
| `try` | 例外が起きる可能性のある処理を書く |
| `catch` | 例外を捕まえて処理する |
| `throw` | 例外を投げる |
| `throws` | メソッドが投げる可能性のある例外を宣言する |
| `finally` | 例外の有無に関係なく必ず実行する |

## try-catch-finally

```java
try {
    // statements that may throw exceptions
} catch (ExceptionType1 e) {
    // handle ExceptionType1
} catch (ExceptionType2 e) {
    // handle ExceptionType2
} finally {
    // always executed
}
```

## Example: ArrayIndexOutOfBoundsException

```java
public class ExcepTest {
    public static void main(String[] args) {
        int a[] = {347, 975};
        try {
            System.out.println("Access element three :" + a[3]);
            System.out.println("a[0]=" + a[0]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Exception thrown :" + e);
        }
        System.out.println("Out of the try block");
    }
}
```

出力:

```text
Exception thrown :java.lang.ArrayIndexOutOfBoundsException: 3
Out of the try block
```

`a[3]` で例外が起きたため、try block の残りは実行されず、catch block に移る。

## finally

`finally` は例外が起きても起きなくても実行される。ファイルを閉じるなどの後片付けに使う。

```java
try {
    // risky code
} catch (Exception e) {
    // handling
} finally {
    // cleanup
}
```

例:

```java
try {
    Scanner keyboard = new Scanner(System.in);
    int i = keyboard.nextInt();
    System.out.println(a[i]);
} catch (ArrayIndexOutOfBoundsException e) {
    System.out.println("Exception thrown :" + e);
} finally {
    a[0] = 6;
    System.out.println("The finally statement is executed.");
}
```

## throws

checked exception を catch しない場合、メソッド宣言で `throws` を書く。

```java
public void writeList() throws IOException, ArrayIndexOutOfBoundsException {
    PrintWriter out = new PrintWriter(new FileWriter("OutFile.txt"));
    // ...
    out.close();
}
```

`IOException` は checked exception なので、catch するか throws する必要がある。

## throw

明示的に例外を投げる。

```java
public Object pop() {
    if (size == 0) {
        throw new EmptyStackException();
    }
    // ...
}
```

`throw` できるのは `java.lang.Throwable` を継承したオブジェクトだけ。

## Custom Exception

独自例外は `Exception` を継承して作る。

```java
public class NoSuchAttributeException extends Exception {
    public final String attrName;

    public NoSuchAttributeException(String name) {
        super("No attribute named " + name + " found");
        attrName = name;
    }
}
```

使う側:

```java
public void replaceValue(String name, Object newValue)
        throws NoSuchAttributeException {
    Attr attr = find(name);
    if (attr == null) {
        throw new NoSuchAttributeException(name);
    }
    attr.setValue(newValue);
}
```

catch:

```java
try {
    attributedObj.replaceValue("Age", value);
} catch (NoSuchAttributeException e) {
    Attr attr = new Attr(e.attrName, value);
    attributedObj.add(attr);
}
```

## Exception Chain

低レベルの例外を高レベルの例外で包んで投げ直す。

```java
try {
    in = new FileInputStream("data.txt");
} catch (IOException e) {
    throw new BadDataException("Bad data.", e);
}
```

独自例外:

```java
public class BadDataException extends Exception {
    public BadDataException() {}
    public BadDataException(String details) {
        super(details);
    }
    public BadDataException(Throwable cause) {
        super(cause);
    }
    public BadDataException(String details, Throwable cause) {
        super(details, cause);
    }
}
```

## Multiple catch

具体的な例外から先に catch する。

```java
catch (FileNotFoundException e) {
    // specific
} catch (IOException e) {
    // more general
} catch (Exception e) {
    // most general
}
```

## Divider Example

```java
try {
    System.out.println("Before Division");
    int i = Integer.parseInt(args[0]);
    int j = Integer.parseInt(args[1]);
    System.out.println(i / j);
    System.out.println("After Division");
} catch (ArithmeticException e) {
    System.out.println("ArithmeticException");
} catch (ArrayIndexOutOfBoundsException e) {
    System.out.println("ArrayIndexOutOfBoundsException");
} catch (NumberFormatException e) {
    System.out.println("NumberFormatException");
} finally {
    System.out.println("Finally block");
}
```

| 実行 | 起きる例外 |
|---|---|
| `java Divider` | `ArrayIndexOutOfBoundsException` |
| `java Divider x y` | `NumberFormatException` |
| `java Divider 1 0` | `ArithmeticException` |
| `java Divider 12 4` | 正常実行 |

## 試験で出そうな注意点

- checked exception は catch or specify が必要。
- unchecked exception は `RuntimeException` / `Error` 系。
- 例外が起きると try block の残りは実行されない。
- `finally` は基本的に必ず実行される。
- `throw` は例外を投げる。
- `throws` はメソッド宣言に書く。
- catch は具体的な例外から一般的な例外へ並べる。
- custom exception は `Exception` を継承する。
- call stack を上にたどって handler が探される。
