# Task 2 Problem A: Personal Task Management

作成: 2026-06-12
対象: Exercise 1 Task 2

## 問題の要約

Personal task management systemをER modelで表す。

中心となる比喩はsticker board。

- Sticker boardがある。
- Stickerはtaskを表す。
- Areaはurgencyごとのtask groupを表す。
- Taskには順序関係がある場合がある。
- Taskにはresponsible personsが関係する場合がある。
- Taskにはname/id、description、status、deadlineがある。
- 説明文書では既存のtask management appsを少し調べる。

## Entity候補

良い解答の目安は7-10 entitiesなので、次を候補にする。

| Entity | 主なAttributes | メモ |
|---|---|---|
| StickerBoard | board_id, name, owner, created_at | タスクボード |
| Area | area_id, name, urgency_level, display_order | urgencyごとの領域 |
| Sticker | sticker_id, color, position_x, position_y | 1つのStickerが1つのTaskを表す |
| Task | task_id, title, short_description, status, deadline | 中心Entity |
| Person | person_id, name, email | responsible person |
| TaskSequence | sequence_id, order_no | task同士の順序を表す中間Entity候補 |
| Status | status_id, status_name | scheduled, in work, suspended, completedなど |
| Tag | tag_id, tag_name | 自分の拡張要素 |

7個に絞るなら:

```text
StickerBoard, Area, Sticker, Task, Person, TaskSequence, Status
```

## Relationship候補

| Relationship | Cardinality案 | 意味 |
|---|---|---|
| StickerBoard contains Area | 1-to-many | 1つのboardに複数area |
| Area contains Sticker | 1-to-many | 1つのareaに複数sticker。空でもよい |
| Sticker represents Task | 1-to-1 | 各stickerはexactly one task |
| Task has Status | many-to-one | 各taskは1つのstatusを持つ |
| Task assigned_to Person | many-to-many, optional | taskは0人以上のresponsible personsを持つ |
| Task precedes Task | recursive relationship | task Aの後にtask Bが続く |
| Task has Tag | many-to-many, optional | 任意拡張 |

## 迷いやすい点

### StickerとTaskを分けるか

問題文では「Each sticker represents exactly one task」とある。
なので、StickerとTaskを別Entityにして1対1にすると説明しやすい。

ただし単純化するなら、StickerをTaskの表示形式としてAttribute扱いしてもよい。
今回はERモデルらしさを出すために分ける案がよい。

### AreaとUrgency

Areaはurgency groupを表す。

Areaに `urgency_level` を属性として持たせればよい。
別Entity `UrgencyLevel` を作ってもよいが、Entity数が増えすぎるならAreaの属性で十分。

### Task sequence

「one follows another」という順序関係は、Task同士のrecursive relationshipで表せる。

例:

```text
Task precedes Task
```

複雑にしたいなら `TaskDependency` や `TaskSequence` を中間Entityにする。

## 説明文書で書くこと

Task 2の説明文書には、図の説明だけでなく「何がER modelだけでは足りないか」も書く。

書ける内容:

- ER modelでは画面上のdrag and drop操作までは表しにくい。
- Taskの通知、リマインダー、権限管理などは別の設計が必要。
- Statusの変更履歴を管理するなら、StatusHistory Entityが必要。
- 既存アプリ例としてTrello, Todoist, Notion, Asanaなどがある。

## 既存アプリ調査メモ

説明文書で触れやすい例:

| App | 参考になる点 |
|---|---|
| Trello | board, list, cardの構造がsticker boardに近い |
| Todoist | task, project, label, priority, deadline |
| Notion | database view, status, relation |
| Asana | task assignment, project, dependency |

## 次の作業

1. Entityを7-8個に確定する。
2. Relationshipとcardinalityを決める。
3. draw.ioでTask 2図を描く。
4. brief description PDFを作る。
