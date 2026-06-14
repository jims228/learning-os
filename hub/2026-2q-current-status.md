# 2026 2Q Current Status

更新: 2026-06-14

## 現在の前提

確率統計論は2026年6月の試験で46点Dだったが、救済レポートが出たため提出済み。現在は結果待ち。通れば単位取得の可能性があるが、落ちた場合は再履修前提で扱う。

2Qは、試験前にまとめて詰め込むやり方をやめて、毎週のQuiz / Exercise / Assignmentを落とさない運用に切り替える。

## 2Qで通常運用する科目

| 科目 | repo内の入口 | 最重要 |
|---|---|---|
| FU03 離散系論 | `DiscreteSystems/FU03/course-info.md` | Assignment 30%、Final 70%。集合・論理・帰納法から固める |
| FU15 データマネジメント概論 | `DataManagement/FU15/course-info.md` | Quiz 40%、Exercise 30%、Final 30%。QuizとExerciseを落とさない |
| EN06 Intermediate English 2 | `english/courses/en06-intermediate-english-2/README.md` | Quiz/Homework 40%。語彙とFunctionsを毎週処理する |

## 2Qの通常運用から外した科目

| 科目 | 資料 | 扱い |
|---|---|---|
| 熱・統計力学 | `Physics/ThermoStatMech/` | 履修から外した。資料は残すが、締切管理には入れない |
| 心理言語学 | `Psycholinguistics/` | 履修から外した。将来候補メモとして残す |

## 今週の動き

1. FU15 Exercise 1提出物とQuiz / Exercise締切を確認する。
2. FU03 Lesson 01の集合・論理・帰納法を復習する。
3. EN06 Class 1 vocabulary / functions / Moodle activityを処理する。
4. 毎日1回、翌日までの提出・Quiz・授業資料を確認する。
5. TOEFLまたはEN06で英語を15分だけ継続する。
6. 確率統計論の救済レポート結果を待ちつつ、週1で基礎復習する。

## 毎日の最低ライン

忙しい日でも次だけはやる。

| 時間 | 内容 |
|---:|---|
| 10分 | Moodle / LMS / repoで翌日までの締切確認 |
| 20分 | いちばん近い授業資料を読む |
| 20分 | Quiz / Exercise / Assignmentのどれかを進める |
| 10分 | 今日やったことを1行で残す |

## AIの使い方

AIは答えを作らせるためではなく、自分が解けるようになるために使う。

毎回この順番にする。

1. まず自分で課題文・資料を5分読む。
2. 分からない語句や式だけAIに説明させる。
3. AIの解説を閉じて、自分で1問解く。
4. 自分の解答をAIに採点させる。
5. 最後に「自分で説明できること」を1行書く。

## Codex app に読ませる時のプロンプト

```text
Ubuntu 22.04側のrepoは /home/jimjace/learning-os です。

2Qの現在状況は以下を読んでください。
- /home/jimjace/learning-os/hub/2026-2q-current-status.md
- /home/jimjace/learning-os/hub/2026-2q-plan.md
- /home/jimjace/learning-os/hub/dashboard.md

2Qで通常運用する科目は FU03 離散系論 と FU15 データマネジメント概論です。
EN06 Intermediate English 2 も2Qの英語科目として扱ってください。
熱・統計力学と心理言語学は履修から外したので、通常の締切管理には入れないでください。

私は確率統計論で46点Dでしたが、救済レポートを提出済みで結果待ちです。2Qでは毎週のQuiz / Exercise / Assignmentを落とさない運用に立て直したいです。
AIに答えを作らせるのではなく、私が自分で解けるようになる形で伴走してください。
```
