# Basic Input/Output (I/O)

## 範囲

- Input/Output Overview
- Streams
- Byte streams
- Character streams
- Buffered streams
- Data streams

## I/O Overview

I/O は program への input と program からの output。

- input: keyboard, file
- output: display, file

File I/O の利点:

- permanent copy を残せる。
- ある program の output を別 program の input にできる。
- 手入力ではなく自動入力できる。

## Stream

Stream は、データの source と destination をつなぐオブジェクト。

- Input stream: program に入力を提供する。
- Output stream: program からの出力を受け取る。

例:

- `System.in`: keyboard への input stream
- `System.out`: screen への output stream

基本手順:

1. Open the stream
2. Use the stream
3. Close the stream

stream は高価なリソースなので、使い終わったら必ず close する。

## Stream の種類

| 種類 | 対象 | 基本クラス |
|---|---|---|
| Byte stream | 8-bit / binary data | `InputStream`, `OutputStream` |
| Character stream | 16-bit Unicode text | `Reader`, `Writer` |

4つの基本クラス:

- `Reader`: text input
- `Writer`: text output
- `InputStream`: byte input
- `OutputStream`: byte output

## Byte Streams

### InputStream

`InputStream` は byte input stream の抽象スーパークラス。

主なメソッド:

| メソッド | 意味 |
|---|---|
| `int read()` | 次の1 byte を読む。終端なら `-1` |
| `int read(byte[] b)` | byte array に読む |
| `int read(byte[] b, int off, int len)` | offset と長さを指定して読む |
| `void close()` | stream を閉じる |
| `int available()` | blocking なしで読める byte 数 |
| `long skip(long n)` | n bytes skip |

### FileInputStream Example

```java
File file = new File("ReadStringsFromFile.java");
int ch;
try {
    FileInputStream fin = new FileInputStream(file);
    while ((ch = fin.read()) != -1) {
        System.out.print((char) ch);
    }
    fin.close();
} catch (FileNotFoundException e) {
    System.out.println("File could not be found");
} catch (IOException e) {
    System.out.println("Exception while reading the file");
}
```

`read()` は次の byte を返し、終端で `-1` を返す。

## OutputStream

`OutputStream` は byte output stream の抽象スーパークラス。

主なメソッド:

| メソッド | 意味 |
|---|---|
| `write(int b)` | 1 byte 書く |
| `write(byte[] b)` | byte array を書く |
| `write(byte[] b, int off, int len)` | offset と長さを指定して書く |
| `close()` | stream を閉じる |
| `flush()` | buffered output を強制的に書き出す |

### FileOutputStream Example

```java
String newline = System.getProperty("line.separator");
byte[] b3 = newline.getBytes();

FileOutputStream fout = new FileOutputStream("Example_2.txt");
String s1 = "This is line 1";
String s2 = "This is line 2";
fout.write(s1.getBytes());
fout.write(b3);
fout.write(s2.getBytes());
fout.close();
```

## CopyBytes Example

```java
FileInputStream in = null;
FileOutputStream out = null;
try {
    in = new FileInputStream("xanadu.txt");
    out = new FileOutputStream("outagain.txt");
    int b;
    while ((b = in.read()) != -1) {
        out.write(b);
    }
} finally {
    if (in != null) {
        in.close();
    }
    if (out != null) {
        out.close();
    }
}
```

byte 単位で読み、byte 単位で書く。

## Character Streams

Character stream は Unicode characters を扱う。

- `Reader`: character input stream のスーパークラス
- `Writer`: character output stream のスーパークラス

### Reader

| メソッド | 意味 |
|---|---|
| `int read()` | 1 character 読む |
| `int read(char[] cbuf)` | char array に読む |
| `int read(char[] cbuf, int off, int len)` | offset と長さ指定 |
| `void close()` | close |
| `boolean ready()` | read 可能か |
| `long skip(long n)` | n characters skip |

### Writer

| メソッド | 意味 |
|---|---|
| `write(int c)` | 1 character 書く |
| `write(String str)` | string を書く |
| `write(String str, int off, int len)` | string の一部を書く |
| `write(char[] cbuf)` | char array を書く |
| `close()` | flush して close |
| `flush()` | flush |

## Writing a Text File

```java
FileWriter out = new FileWriter("test.txt");
BufferedWriter b = new BufferedWriter(out);
PrintWriter p = new PrintWriter(b);
for (int i = 1; i < 6; i++) {
    p.println("I'm sentence " + i + " in a text file.");
}
p.close();
```

Layer:

```text
FileWriter -> BufferedWriter -> PrintWriter
```

## Buffered Streams

Buffered streams は data を一時的に buffer にためることで、元の data source へのアクセス回数を減らす。

```java
BufferedReader f = new BufferedReader(new FileReader("data.txt"));
BufferedOutputStream b =
    new BufferedOutputStream(new FileOutputStream("dataout"));
```

file stream のように read/write が高コストな stream は buffer で包むのがよい。

## Reading a Text File

```java
BufferedReader a = null;
try {
    a = new BufferedReader(new FileReader("test.txt"));
    String s;
    while ((s = a.readLine()) != null) {
        System.out.println(s);
    }
} catch (Exception e) {
    System.out.println(e);
} finally {
    if (a != null) {
        a.close();
    }
}
```

`readLine()` は次の行を返し、終端で `null` を返す。

## Scanner

`Scanner` は formatted input を token に分解するのに便利。

```java
Scanner s = null;
try {
    s = new Scanner(new BufferedReader(new FileReader("test.txt")));
    while (s.hasNext()) {
        System.out.println(s.next());
    }
} finally {
    if (s != null) {
        s.close();
    }
}
```

## Data Streams

`InputStream` / `OutputStream` の byte 単位操作は、`int`, `double`, `String` などを扱うには不便。

Data stream は Java primitive types を自然な形で read/write できる。

- `DataOutputStream`: primitive Java data types を output stream に書く。
- `DataInputStream`: 書いた data を読み戻す。

## DataOutputStream

主なメソッド:

```java
writeInt(int)
writeLong(long)
writeByte(int)
writeShort(int)
writeDouble(double)
writeFloat(float)
writeChar(int)
writeBoolean(boolean)
writeUTF(String)
flush()
size()
```

## DataInputStream

主なメソッド:

```java
readInt()
readLong()
readByte()
readShort()
readFloat()
readDouble()
readChar()
readBoolean()
readUTF()
```

多くは `IOException` や `EOFException` を投げる可能性がある。

## Creating a Data Stream

```java
DataOutputStream out = null;
try {
    out = new DataOutputStream(
            new BufferedOutputStream(
                    new FileOutputStream(dataFile)));
    for (int i = 0; i < prices.length; i++) {
        out.writeDouble(prices[i]);
        out.writeInt(units[i]);
        out.writeUTF(descs[i]);
    }
} finally {
    out.close();
}
```

Layer:

```text
FileOutputStream -> BufferedOutputStream -> DataOutputStream
```

## Reading a Data Stream

```java
DataInputStream in = null;
double total = 0.0;
try {
    in = new DataInputStream(
            new BufferedInputStream(
                    new FileInputStream(dataFile)));
    double price;
    int unit;
    String desc;
    try {
        while (true) {
            price = in.readDouble();
            unit = in.readInt();
            desc = in.readUTF();
            total += unit * price;
        }
    } catch (EOFException e) {
    }
} finally {
    in.close();
}
```

Data stream は書いた順番と同じ順番で読む必要がある。

## Character Stream vs Data Stream

| 種類 | 使う場面 | 1回のI/O |
|---|---|---|
| Character stream | text file | character |
| Data stream | Java primitive values | variable value |

Character stream は Unicode と local character set の変換を行う。

Data stream は Java primitive values を platform-independent な形式で保存する。

## 試験で出そうな注意点

- stream は open -> use -> close。
- byte stream は `InputStream` / `OutputStream`。
- character stream は `Reader` / `Writer`。
- binary file なら byte/data stream、text file なら character stream。
- `read()` は終端で `-1`。
- `readLine()` は終端で `null`。
- `DataOutputStream` で書いた順番と `DataInputStream` で読む順番は一致させる。
- buffer は効率化のために stream を包む。
- close は忘れない。例外があっても閉じるために `finally` が使える。
