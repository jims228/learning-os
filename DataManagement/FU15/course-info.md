# FU15 データマネジメント概論 Course Info

作成: 2026-06-08  
出典: Moodleに公開されているCourse Outline / Lecture 0-2情報

## この授業でやること

この授業は、ざっくり言うと「データをどう整理し、モデル化し、保存し、扱うか」を学ぶ授業。

重要な柱は次の4つ。

| 領域 | 内容 |
|---|---|
| 基礎概念 | data / information / knowledge / metadata の違い |
| データモデリング | ER図、オブジェクト指向モデル、抽象化 |
| 保存・管理 | データ保存、バージョン管理、配布、バックアップ |
| DB利用 | データベースや専門的なデータ管理システムでの保存・アクセス |

## 目的

この授業の目的は、データマネジメントを研究・技術領域として理解し、現代の情報システムで使われるデータモデルとモデリング手法を学ぶこと。

特に重視されるのは、現実の場面での次の内容。

- データモデリング
- データ保存
- リレーショナルデータベース
- スプレッドシート
- データのバージョン管理
- データの配布
- データのバックアップ

この授業は、後続の Database Management Systems や Operating Systems の基礎になる。

## 扱わない範囲

次の内容は、この授業の主対象ではない。

- データアーカイブのアルゴリズムや技術
- 知的データ分析
- 情報検索
- データマイニング
- 情報セキュリティ
- 要求管理

## 成績評価

100点満点。

| 項目 | 点数 |
|---|---:|
| Exercises and individual projects | 30点 |
| Final test / quiz | 30点 |
| Quizzes on lecture content | 40点 |
| Bonus | 最大20%分まで補填の可能性 |

重要:

- Exerciseは次のExercise classまでに終わらせる必要がある。
- 提出期限はかなり厳しい。
- Exerciseは完全に個人作業。他人の解答利用は禁止。
- 小テストは通常、講義後に開き、次の講義前日の23:55まで。
- 小テストは10-20分程度の時間制限がある。
- 小テストは1回のみ。
- Submitボタンを押し忘れない。

## Exercise提出ルール

Exerciseは通常、2回分の講義内容を扱う。

提出期限:

- 次のExercise classの前日23:55まで

提出形式:

```text
<student id>-e<exercise number>.zip
```

例:

```text
s1280155-e2.zip
```

## 通常の授業パターン

Lecture 0資料によると、通常は次の形。

| 曜日 | 時限 | 内容 |
|---|---|---|
| Tue | 1st + 2nd periods | Lecture |
| Fri | 1st + 2nd periods | Lecture |
| Fri | 3rd + 4th periods | Exercise |

Lectureは週2回、Exerciseは週1回。
Quizは講義後にMoodleで開くことが多く、通常は次の講義前日の23:55まで。
Exercise提出は通常、次のExercise前日の23:55まで。

管理メモ:

- Lecture 0: `lectures/lecture-00-workflow.md`
- Lecture 1: `lectures/lecture-01-foundation-concepts.md`
- Week 1行動リスト: `exercises/week-01-action-plan.md`
- 資料一覧: `materials-inventory.md`

## 現時点で公開されている日程

### 2026-06-12 Fri

| 内容 | トピック |
|---|---|
| Lecture 0 | Course Organization and Workflow |
| Lecture 1 | From Information to Data, and Vice Versa / Intro to ER Diagrams |
| Exercise 1 | Lecture 1に関係するER図準備 |

Lecture 1で扱う内容:

- Data / Information / Knowledge
- What is data?
- DataとInformationの関係
- Clustering and classification
- Information systems
- Research data lifecycle
- Data to knowledge
- Metadata
- Metadata standards and examples
- ER Diagrams
- Entities and relationships
- Exercise 1の準備

公開例:

- Academic Programs ER diagram
- Course Registration ER diagram
- Course Registration ER diagram png

### 2026-06-16 Tue

| 内容 | トピック |
|---|---|
| Lecture 2 | ER and Object-Oriented Modeling |

Lecture 2で扱う内容:

- Data modeling
- Why do we create models?
- ER modelの目的、限界、主要要素
- Natural languageからER modelへ写す考え方
- Course registration systemのER modeling
- Data modeling and abstraction
- Object-oriented data models
- Object-oriented analysis and design

### 2026-06-19 Fri

| 内容 | トピック |
|---|---|
| Lecture 3 | LMS上ではLecture 3。詳細トピックは今後確認 |
| Exercise 2 | Lecture 1-2付近の内容 |

## 得点戦略

この授業は、期末一発勝負ではなく、毎回のQuizとExerciseを落とさないことが一番大事。

優先順位:

1. Quiz期限を絶対に落とさない。
2. Exerciseのzip提出形式を守る。
3. ER図・class diagramをdraw.io / diagrams.netで作れるようにする。
4. 用語は英語のまま覚える。
5. Final test前にLectureごとのQuiz内容を復習する。
