# FU15 データマネジメント概論 Quick Start

作成: 2026-06-08

## 授業の見方

この授業は「暗記科目」ではなく、「現実の情報をどうデータ構造にするか」を練習する授業。

最初の山はER図。

たとえば「学生が授業を履修する」という日本語を見たら、

- Student
- Course
- Registration
- Lecturer
- Department

のようなものを見つけて、それらの関係を図にする。

## 毎週の基本ルーティン

| タイミング | やること |
|---|---|
| 講義当日 | Lecture資料をざっと読む。知らない英単語をメモ |
| 講義後24時間以内 | Quizを先に終わらせる |
| Exercise週 | 早めにER図・提出zipを作る |
| 提出前日 | ファイル名、zip中身、Submit確認 |

通常の時間割:

| 曜日 | 時限 | 内容 |
|---|---|---|
| Tue | 1st + 2nd | Lecture |
| Fri | 1st + 2nd | Lecture |
| Fri | 3rd + 4th | Exercise |

空きコマの使い方:

1. Lecture直後にQuizを受ける準備をする。
2. Quiz前に英単語とスライド見出しだけ確認する。
3. Exerciseの説明を読んで、提出zipの中身を作り始める。
4. diagrams.net / draw.ioで図を触る。

重要:

- Quizは1回だけ。油断して開かない。
- Quizは10-20分制限が多い。
- Exerciseは次のExercise class前日の23:55締切。
- Submitボタンを押すまで終わりではない。

## 最初に覚える英単語

| 英語 | 意味 |
|---|---|
| data | データ。記録された値や事実 |
| information | 情報。意味づけされたデータ |
| knowledge | 知識。情報を使って判断できる状態 |
| metadata | データについてのデータ |
| entity | 実体。管理したいもの |
| relationship | 実体同士の関係 |
| attribute | 実体が持つ性質 |
| model | 現実を簡略化して表したもの |
| abstraction | 抽象化。重要な特徴だけ取り出すこと |
| lifecycle | 発生から保存・利用・破棄までの流れ |

## ER図の最低限

ER図では、まず3つだけ見る。

| 見るもの | 例 |
|---|---|
| Entity | Student, Course, Program |
| Relationship | Student registers Course |
| Attribute | student_id, course_name, credits |

考え方:

```text
現実の文章
→ 名詞を探す
→ 管理したい名詞をEntityにする
→ 動詞や関係をRelationshipにする
→ IDや名前などをAttributeにする
```

## Exercise 1でやる可能性が高いこと

公開情報から見ると、Exercise 1はER図の導入に近いはず。

やる準備:

1. diagrams.net / draw.ioを使えるようにする。
2. Academic Programs ER diagramを開く。
3. Course Registration ER diagramを開く。
4. entity / relationship / attributeを指差しで説明できるようにする。
5. 自分でも「履修登録」の簡単なER図を描いてみる。

## まずの目標

最初の2週間は、完璧な理解よりも締切管理。

- Lecture 1-2のQuizを期限内に出す。
- Exercise 1をzipで正しく出す。
- ER図で entity / relationship / attribute を説明できる。
- データと情報の違いを1文で言える。
