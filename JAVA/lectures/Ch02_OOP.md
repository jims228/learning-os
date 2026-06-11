# Chapter 2: Object Oriented Programming

## オブジェクトとは？
- 現実世界のものをソフトウェアで表現したもの
- 2つの特徴:
  - **State（状態）**: データ → フィールド（変数）で表現
  - **Behavior（振る舞い）**: 動作 → メソッド（関数）で表現

## カプセル化 (Encapsulation)
- オブジェクトの内部状態を隠蔽し、メソッド経由でのみアクセスさせること
- フィールドに直接アクセスさせない → `private` で宣言
- メリット: モジュール性、情報隠蔽、コード再利用、デバッグのしやすさ

## クラスとは？
- オブジェクトを作るための「設計図（blueprint）」
- 同じクラスから複数のオブジェクト（インスタンス）を生成できる
- `class クラス名 { }` で定義
- ファイル名 = クラス名.java

## クラスの構成要素
- **フィールド**: オブジェクトの状態（例: `private int speed = 0;`）
- **メソッド**: オブジェクトの振る舞い（例: `void speedUp(int n) { ... }`）
- **コンストラクタ**: クラス名と同じ名前の特殊メソッド、オブジェクト初期化時に呼ばれる

## Bicycle クラスの例
```java
class Bicycle {
    private int cadence = 0;
    private int speed = 0;
    private int gear = 1;

    Bicycle() {  // コンストラクタ
        cadence = 0; speed = 0; gear = 1;
    }

    void changeCadence(int newValue) { cadence = newValue; }
    void changeGear(int newValue) { gear = newValue; }
    void speedUp(int increment) { speed = speed + increment; }
    void printStates() {
        System.out.println("cadence:" + cadence + " speed:" + speed + " gear:" + gear);
    }
}
```

## オブジェクトの生成と使用
```java
Bicycle bike1 = new Bicycle();  // インスタンス生成
bike1.speedUp(10);              // メソッド呼び出し
bike1.printStates();
```

## 手続き型 vs オブジェクト指向
| | 手続き型 | オブジェクト指向 |
|---|---|---|
| データ | 関数からアクセス可能 | メソッド経由のみ |
| 問題 | データが誰でも変更できる | データを安全に保護できる |
