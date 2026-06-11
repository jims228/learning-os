# Lecture 1: Foundation Concepts

作成: 2026-06-09
資料: `IDM-Lecture-01-Foundation-Concepts.pdf`

## この回のテーマ

Lecture 1は、データマネジメントの入口。

中心は次の3つ。

1. Data / Information / Knowledge の違い
2. Metadataとは何か
3. ER model / ER diagramの入口

## Data と Information

資料では2つの見方が出てくる。

| 見方 | 意味 |
|---|---|
| Information-centric analysis | DataはInformationを表すための方法 |
| Data-centric analysis | Informationは文脈の中で管理されたData |

ざっくり言うと、

```text
Data = まだ生の値・記録
Information = 文脈がついて意味が分かるデータ
Knowledge = 情報を使って判断できる状態
```

例:

```text
Data: 1という値がある
Information: それはtomatoを表している
Knowledge: tomatoはfruitである
Wisdom: tomatoはfruit saladには普通入れない
```

## What is Data?

技術的には、Dataは次のように説明される。

```text
Facts that can be analyzed or used in computers
```

または、

```text
Information represented in a form suitable for acquisition,
interpretation, storage, and processing
```

つまり、コンピュータで取得・保存・処理できる形になった情報。

## Research Data Lifecycle

研究データでは、集めて終わりではない。
時間が経っても使えるようにする必要がある。

確認すべき質問:

- What are your goals?
- What are you collecting?
- What are you keeping?
- Where do you want to keep it?
- What do you need to use, change, share, or repurpose it later?

## Metadata

Metadataは「data about data」。

データはそれだけでは自分の意味を説明してくれない。
だから、後で探す・理解する・共有するためにmetadataが必要。

例:

| Data | Metadata |
|---|---|
| 2026-06-12 | 測定日、授業日、提出日などの説明 |
| 80 | 点数、温度、人数などの説明 |
| `student_id` | 何のIDか、形式、誰が使うか |

## Metadata Standards

資料に出てくる標準例:

- FGDC
- DDI
- Dublin Core
- Darwin Core
- ABCD
- AVMS
- CSDGM

ここは全部暗記よりも、

```text
分野ごとにmetadataの標準がある
```

と理解すればよい。

## Data Model

Data modelは、データをきれいに見せるだけの図ではない。
次を表すための考え方。

- Data structures
- Data relationships
- Constraints
- Operations

つまり、

```text
どんなデータがあり、
それらがどう関係し、
どんな制約があり、
どう操作されるか
```

を表す。

## ER Model

ER ModelはPeter Chenが1976年に提案したモデル。

基本は、

```text
real world = entities + relationships
```

現実世界には「もの」と「関係」がある、と見る。

| 用語 | 意味 | 例 |
|---|---|---|
| Entity | 管理したいもの | Student, Program, Course |
| Relationship | Entity同士の関係 | Student enrolls in Program |
| Attribute | Entityの性質 | Name, ID, Capacity |

## Academic Programsの例

資料の例:

- University offers one or more programs.
- A program is made up of one or more courses.
- A student must enroll in one program.
- Courses are parts of the program.

Entity候補:

- University
- Program
- Course
- Student

Attribute候補:

| Entity | Attribute |
|---|---|
| Program | Name |
| Course | Name, Capacity, Course ID |
| Student | Name, ID |

## Exercise 1でできるようにすること

1. 英文から名詞を探す。
2. 管理したい名詞をEntityにする。
3. 動詞・所属・構成関係をRelationshipにする。
4. IDやNameなどをAttributeにする。
5. diagrams.net / draw.ioで図として描く。

## 口頭説明用

この授業では、現実の情報をコンピュータで扱えるデータとして整理する方法を学ぶ。
Lecture 1では、data, information, knowledge, metadataの違いを押さえ、そのあとER図でentity, relationship, attributeを表す入口を学ぶ。
