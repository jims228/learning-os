# Chapter 1: Introduction to Java

## Java Technology
- Java = プログラミング言語 + プラットフォーム
- 特徴: Simple, Object-oriented, Distributed, Multithreaded, Dynamic, Architecture neutral, Portable, High performance, Robust, Secure

## コンパイル・実行の流れ
1. `.java` ソースファイルを作成
2. `javac` コンパイラで `.class` ファイル（バイトコード）を生成
3. `java` ランチャーでJava VM上で実行

## Java VM
- 複数OS上で同じ `.class` ファイルを実行可能（Write Once, Run Anywhere）
- Windows, Solaris, Linux, Mac OS対応

## Java Platform
- 2つのコンポーネント: Java VM + Java API
- APIはパッケージ（関連クラス・インタフェースのライブラリ）で構成
- ハードウェアからプログラムを隔離（プラットフォーム非依存）

## 開発ツール
- コンパイラ: `javac`
- ランチャー: `java`
- ドキュメントツール: `javadoc`

## Welcome to Java! の例
```java
class Welcome {
    public static void main(String[] args) {
        System.out.println("Welcome to Java!");
    }
}
```
- 保存: `Welcome.java`
- コンパイル: `javac Welcome.java`
- 実行: `java Welcome`
- すべてのJavaアプリケーションには `public static void main(String[] args)` が必要
