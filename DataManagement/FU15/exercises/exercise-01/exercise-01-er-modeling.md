# Exercise 1: ER Diagramming Basics

作成: 2026-06-12
資料: `IDM-Exercise-ER-modeling.pdf`
Moodle提出: Upload Solutions for Exercise 1

## 締切

| 項目 | 日時 |
|---|---|
| 開始予定 | 2026-06-12 Fri 10:50 |
| 期限 | 2026-06-18 Thu 23:55 |

## 全体

Exercise 1は2つのTaskからなる。

| Task | 点数 | 内容 |
|---|---:|---|
| Task 1 | up to 3 points | Moodleのサンプル `academic-er.xml` を拡張する |
| Task 2 | up to 7 points | 割り当てられたsubject domainについて、自分でER図を作る |

## Task 1

### やること

Moodleから `academic-er.xml` をダウンロードし、diagrams.net / draw.ioで開いて拡張する。

使うサイト:

```text
https://app.diagrams.net/
```

作業:

1. Moodleから `academic-er.xml` をダウンロードする。
2. diagrams.netで開く。
3. 指示に従ってER図を拡張する。
4. XMLとして保存する。
5. PNGとしてexportする。

注意:

```text
DO NOT FORGET TO SAVE YOUR DIAGRAM.
```

### 元のモデル

元の図は大学のacademic processを表す。

- University offers one or more Programs.
- Program is made up of one or more Courses.
- Student must enroll in one Program.
- Courses are parts of the Program.

元のEntity:

| Entity | 種類 | Attributes |
|---|---|---|
| Student | strong entity | ID, name |
| Program | strong entity | program name |
| Course | weak entity | name, capacity, course ID |

元のRelationship:

| Relationship | 意味 |
|---|---|
| Student enrolls_in Program | Studentは必ず1つのProgramに所属。ProgramはStudentなしでも存在可能 |
| Program owns Course | CourseはProgramの文脈で意味を持つweak entity。Programは少なくとも1つのCourseを含む |

### Task 1で追加するもの

1. Programに「卒業に必要な総単位数」属性を追加する。
2. Teacherは1つ以上のCourseを教える。
3. Courseは少なくとも1人のTeacherを持ち、複数Teacherに教えられてもよい。
4. Studentに「最初に入学した年」属性を追加する。
5. ManagerはProgramをcoordinateし、studentsにnotifyする。これはsimple directed association relationshipを使う。
6. Compulsory CourseとElective Courseが存在する。
7. ProgramはCompulsory Coursesから成る。
8. Teacherは複数のElective Coursesを教えることができる。ただしElective Courseを担当しないTeacherもありえる。

## Task 2

### やること

割り当てられたsubject domainについて、サンプルなしで自分のER図を作る。

作業:

1. 学生番号を16で割った余りから、自分のProblem A-Pを決める。
2. 該当Problemの説明を読む。
3. 主なEntity、Attribute、Relationshipを決める。
4. ER diagramを作る。
5. PNG画像にexportする。
6. 別文書でモデル説明を書く。

### 割当表

| student ID mod 16 | Problem |
|---:|---|
| 0 | A |
| 1 | B |
| 2 | C |
| 3 | D |
| 4 | E |
| 5 | F |
| 6 | G |
| 7 | H |
| 8 | I |
| 9 | J |
| 10 | K |
| 11 | L |
| 12 | M |
| 13 | N |
| 14 | O |
| 15 | P |

repo内の過去課題から見える学生番号が `s1330096` なら、

```text
1330096 mod 16 = 0
```

なので、割当は **Problem A: Personal Task Management**。

学生番号が違う場合は割当も変わる。

## Problem A: Personal Task Management

Personal Task Management systemを設計する。

題材:

- sticker boardのメタファーをデジタル化する。
- 各stickerはexactly one taskを表す。
- sticker boardにはurgencyによってtask groupを表すareasがある。
- task同士は「次に続く」sequenceとしてつながることがある。
- taskはresponsible personsのlistとつながることがある。ただし必須ではない。
- taskはname/id、short description、status、deadlineを持つ。
- 説明文書では、既存のtask/activity management applicationについて小規模に調べる。

## Grading

評価基準:

- 必要なEntity、Relationship、Attributeが適切に入っている。
- 良い解答の目安は7-10 entities。
- strong entity / weak entityを適切に使っている。
- one-to-one、one-to-many、zero-to-manyなどの関係を正しく判断している。
- 図が読みやすく整理されている。
- モデル説明が明確。
- 提出物が指定通り整理されている。

配点目安:

| 項目 | 割合 |
|---|---:|
| Diagram | up to 60% |
| Explanation file | up to 30% |
| Submission carefulness | 10% |

## 提出zipに入れるもの

Moodleの提出条件:

1. Task 1の拡張 `academic-er` diagramのXML file。
2. Task 1のacademic-er diagramをPNGに変換したimage file。
3. Task 2のER diagram XML file(s)。
4. Task 2のdiagram image file(s)、形式はjpgまたはpng。
5. Task 2のER modelについてbrief descriptionを書いたdocument file。PDF推奨。

## 推奨ファイル名

Course Infoの提出形式に合わせるなら、

```text
s1330096-e1.zip
```

zip内の例:

```text
task1-academic-er-extended.xml
task1-academic-er-extended.png
task2-personal-task-management.xml
task2-personal-task-management.png
task2-personal-task-management-description.pdf
```

学生番号が違う場合はzip名も変える。

## すぐやること

1. Moodleから `academic-er.xml` をダウンロードする。
2. diagrams.netで開けるか確認する。
3. Task 1を先に完成させる。
4. Task 2がProblem Aで正しいか確認する。
5. Problem AのEntity候補を7-10個に整理する。
