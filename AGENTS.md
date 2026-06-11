# AGENTS.md - Codex guide for learning-os

このファイルは Codex 用の入口です。Claude Code は引き続き `.claude/` と Claude Code 側の設定を使います。
Codex はこの `AGENTS.md` を起点に読み、Claude Code 用ファイルには原則干渉しません。

## このrepoの役割

`learning-os` は学業・試験対策・授業ノート・演習管理に加えて、旧 `SchoolAssignment` の学校課題管理を統合したリポジトリです。
今後はこのrepoを学習管理の正本として使います。

主な対象:

- 確率統計学
- JAVA
- フーリエ解析
- C
- 英語・TOEFL
- BCI・神経科学・信号処理
- 宇宙
- メタバース・VR
- 長期目標、週次レビュー、月次レポート
- 試験前の計画、チートシート、過去問、演習、講義ノート

起業・営業・顧客管理の正本は `/home/jimjace/jims-company-os` にあります。
このrepoでは学業タスクを優先し、事業側の判断が必要な場合だけ `jims-company-os` を参照します。

旧 `SchoolAssignment` の内容は `/home/jimjace/learning-os` に移行済みです。
統合前の `learning-os` の `README.md` と `CLAUDE.md` は `_archive/learning-os/` に保全しています。

## まず読む

学業全体の状況を把握する場合:

1. `README.md` - 統合後の全体像
2. `hub/context-summary.md` - 全体文脈の圧縮版
3. `EXAM_PREP_2026-06.md` - 2026年6月試験対策の全体計画
4. `hub/dashboard.md` - 長期学習の現在地
5. `hub/goals.md` - 留学・TOEFL・長期学習目標
6. `hub/study-plan.md` - TOEFLと専門学習の計画
7. `Math/Statistics/exam-prep/course-info.md` - 確率統計学の試験情報
8. `Math/Statistics/exam-prep/midterm-cheatsheet.md` - 統計の既存チートシート
9. `JAVA/study-guide-ex07-08.md` - JAVA演習7-8の学習ガイド

目的別:

- 統計の試験対策: `Math/Statistics/exam-prep/` と `Math/Statistics/exercises/past-exams/`
- JAVAの復習: `JAVA/lectures/`、`JAVA/exercises/`、`JAVA/study-guide-ex07-08.md`
- Cの確認: `C/Command.md` と `C/hello.c`
- 英語・TOEFL: `english/daily-log.md`、`english/toefl-prep/`、`hub/study-plan.md`
- 長期学習の目標確認: `hub/goals.md`、`hub/dashboard.md`
- BCI: `bci/index.md`
- 宇宙: `space/index.md`
- メタバース・VR: `metaverse-vr/index.md`
- 週次・月次振り返り: `reviews/`
- 全体スケジュール: `EXAM_PREP_2026-06.md`

## Claude Codeとの役割分担

- `.claude/`: Claude Code 用。Codex は原則編集しない。
- `.claude/settings.local.json`: Claude Code のローカル権限設定。Codex は変更しない。
- `AGENTS.md`: Codex 用。Codex の読み方、作業ルール、優先順位を書く。
- `_archive/learning-os/CLAUDE.md`: 統合前の `learning-os` のClaude向け指示の保全コピー。ルート指示としては扱わない。
- 共通の学習成果物はAI別メモリではなく、通常のrepo docsに残す。
- Claude Code でいつでも再開できるように、Claude Code 用ファイルや設定は残す。

## Codexの権限と参照範囲

このチャットの実行権限・モデル選択・サンドボックス設定は、リポジトリ内のファイルではなく、Codexセッション側の設定で決まります。

現在の作業前提:

- 作業ディレクトリ: `/home/jimjace/learning-os`
- 書き込み可能範囲: 基本的にこのrepo配下
- `/home/jimjace/jims-company-os` は必要に応じて読み取り参照できるが、このrepoの学業作業に直接関係しない限り読まない
- `/home/jimjace/SchoolAssignment` は旧学校課題repoとして扱い、今後の更新先はこのrepo
- Claude Code の権限設定は `.claude/settings.local.json` にあるが、Codex の権限とは別物として扱う

## 作業ルール

- 日本語で具体的に答える。
- 試験日・提出日・今日の日付を混同しない。相対日付ではなく必要に応じて具体日付で確認する。
- 講義ノートや解答を作る時は、既存ファイルの文体と構成に寄せる。
- 試験対策では「暗記」「理解」「演習」「チートシート化」を分けて整理する。
- 数式・コード・解答は、あとで見返せるようにMarkdownで整える。
- 既存の解答・ノートを壊さず、追加や修正は最小限にする。
- 古い版を消す必要がある場合は、ユーザーの明示指示がない限り削除しない。
- `git commit` / `git push` はユーザーが明示した時だけ行う。
- inboxのメモを整理する時は、移動先を明確にし、元メモを削除する前に必要な内容が移ったことを確認する。
- 週次レビュー・月次レポートは `reviews/` に置く。

## 編集方針

- 新しい試験対策資料は、科目ごとの既存ディレクトリに置く。
- 統計は `Math/Statistics/exam-prep/` または `Math/Statistics/exercises/` に置く。
- JAVAは `JAVA/lectures/`、`JAVA/exercises/`、または `JAVA/` 直下の学習ガイドに置く。
- Cは `C/` 配下に置く。
- TOEFL・英語ログは `english/` に置く。
- 長期学習の計画やダッシュボードは `hub/` に置く。
- BCI・宇宙・メタバース関連はそれぞれ `bci/`、`space/`、`metaverse-vr/` に置く。
- 複数科目にまたがる計画はrepoルートの `EXAM_PREP_*.md` にまとめる。

## 品質基準

- 公式・授業資料・既存ノートを優先し、推測で断定しない。
- 問題演習では、答えだけでなく途中式・考え方・よくあるミスも残す。
- JAVAやCのコードは、可能ならコンパイルして確認する。
- チートシートは試験持ち込み制限を確認してから分量を決める。
- 試験直前の依頼では、網羅性より得点に直結する順番を優先する。
- TOEFLなど外部試験の制度・日程・形式は変わる可能性があるため、最新情報が必要な時は公式情報を確認する。

## 2026年6月の注意点

`EXAM_PREP_2026-06.md` によると、現在の主な試験予定は次の通りです。

| 日付 | 科目 |
|---|---|
| 2026-06-04 | 確率統計学 |
| 2026-06-05 | 英語 |
| 2026-06-08 | JAVA + フーリエ解析 |

英語は本人対策のため、このrepoでは確率統計学・JAVA・フーリエ解析を主に扱います。

統合前からの英語学習計画も引き継ぎ済みです。TOEFLや留学準備の依頼では `hub/study-plan.md` と `english/daily-log.md` を参照します。

## よく使う依頼例

```text
EXAM_PREP_2026-06.mdを読んで、今日やるべき試験対策を3つに絞って。
```

```text
統計の過去問とチートシートを読んで、6/4に向けた弱点演習を作って。
```

```text
JAVA/lectures と exercises を見て、試験前に暗記すべき構文と概念を整理して。
```

```text
この解答を、途中式つきで試験復習用Markdownに直して。
```

```text
hub/dashboard.md と english/daily-log.md を見て、今日のTOEFL対策を30分に絞って。
```

```text
inbox/quick-notes.md の内容を整理して、適切な学習ノートに移して。
```
