# コンテキスト整理

最終更新: 2026-05-30

このファイルは、統合後の `learning-os` 全体を読んだうえでの作業用サマリーです。今後の学習相談・試験対策・ノート整理では、まずこのファイルと `hub/dashboard.md`、`EXAM_PREP_2026-06.md` を見る。

## 読み込み範囲

確認した対象:

- Markdown / TeX / YAML / JSON / TXT / C / Java などのテキストファイル
- 対象テキスト: 244ファイル、約10,459行
- `learning-os` 統合後に追加された `hub/`, `english/`, `bci/`, `math/`, `space/`, `metaverse-vr/`, `reviews/`, `templates/`

存在だけ確認した対象:

- Java `.class`
- 提出用 `.zip`
- 画像ファイル: `C/problems/*.jpg`, `Math/Statistics/exercises/past-exams/figures/*.png`

読解対象外:

- `.git/`
- バイナリ成果物

## 現在の最重要文脈

2026-05-30時点では、長期学習よりも6月試験対策を優先する。

| 日付 | 科目 | 優先度 |
|---|---|---|
| 2026-06-04 | 確率統計学 | 最優先 |
| 2026-06-05 | 英語 | 本人対策 |
| 2026-06-08 | JAVA + フーリエ解析 | 次点 |

試験対策の正本:

- `EXAM_PREP_2026-06.md`
- `hub/dashboard.md`
- `hub/goals.md`

## リポジトリの役割

`learning-os` は、学校課題管理と長期学習管理を統合した学習管理リポジトリ。

扱う領域:

- 学校: 確率統計学、JAVA、フーリエ解析、C
- 長期: TOEFL、英語、数学基礎、BCI、宇宙、メタバース・VR
- 運用: dashboard、goals、study-plan、weekly/monthly review、inbox

起業・営業・顧客管理は `/home/jimjace/jims-company-os` が正本。このrepoでは必要時だけ参照する。

## 入口ファイル

| ファイル | 役割 |
|---|---|
| `README.md` | 統合後の全体構成 |
| `AGENTS.md` | Codex向け運用ルール |
| `hub/context-summary.md` | このファイル。全体文脈の圧縮版 |
| `hub/dashboard.md` | 現在のフェーズと優先順位 |
| `hub/goals.md` | 直近・中期・長期目標 |
| `hub/study-plan.md` | TOEFL中心の長期学習計画 |
| `EXAM_PREP_2026-06.md` | 6月試験対策計画 |

## 確率統計学

配置:

- `Math/Statistics/exam-prep/course-info.md`
- `Math/Statistics/exam-prep/midterm-cheatsheet.md`
- `Math/Statistics/exam-prep/midterm-cheatsheet-1page.md`
- `Math/Statistics/exercises/past-exams/midterm-2026.md`
- `Math/Statistics/exercises/past-exams/midterm-2026-solutions.md`
- `Math/Statistics/exercises/past-exams/figures/`

内容:

- 既存教材は中間範囲 Ch1-3 が中心。
- チートシートは記述統計、確率、期待値・分散、分布、標準化、共分散・相関、ヒストグラム/散布図の読み取りに強い。
- 過去問解説は問1-7まであり、特に「サンプルサイズ/サンプル数」「標本分散/不偏分散」「用語の正確性」の罠が整理されている。

不足:

- 期末範囲 Ch4-5 のノート・チートシートが未整備。
- `EXAM_PREP_2026-06.md` では Ch4-5 は「極限定理・統計的推定」とされている。

次にやるべきこと:

1. Ch4-5 の講義資料を取り込む。
2. 大数の法則、中心極限定理、点推定、区間推定の要点を作る。
3. A4チートシートを期末向けに更新する。

## JAVA

配置:

- 講義ノート: `JAVA/lectures/`
- 演習説明: `JAVA/exercises/Exercise01.md` 〜 `Exercise10.md`
- 実装: `JAVA/exercises/Ex01/` 〜 `Ex12/`
- 復習ガイド: `JAVA/study-guide-ex07-08.md`

講義ノートの主な範囲:

- Ch01: Java概要、コンパイル、VM、Platform
- Ch02: OOP、クラス、カプセル化
- Ch04: Classes and Objects、コンストラクタ、this、static、final、値渡し/参照渡し
- Ch05: Inheritance Part 1、override/hide、super、constructor chain、casting、composition vs inheritance
- Ch06: Inheritance Part 2、Object、equals、abstract class、IS-A/HAS-A、Composite
- Ch07: Interfaces、interface as type、multiple inheritance、abstract classとの違い
- Ch08: Polymorphism Part 1、dynamic binding、static method、method matching/binding、casting、instanceof
- Ch10: Packages、import、classpath、access modifiers
- Ch12: Numbers and Strings、wrapper、printf、DecimalFormat、Math、char/String/StringBuilder

演習テーマ:

- Ex01: Java入門、標準出力、Fahrenheit変換、素因数分解
- Ex02: Object生成、Point操作、safe moving、vector
- Ex03: static field、array assignment、sorting arrays、Stack
- Ex04: primitive/reference passing、doubly linked list、multiple queues
- Ex05: inheritance、composition、constructor chain、overriding
- Ex06: equals、abstract class、shape hierarchy、Composite file system
- Ex07: interface、Relatable、sorting relatable objects
- Ex08: polymorphism、Strategy、Comparator、Iterator
- Ex09: Strategy拡張、AdvancedSortingMachine、Adapter
- Ex10: package、access control、Template Method
- Ex11: exception、finally、ListOfNumbers、custom stack exceptions
- Ex12: command-line args、strings/ring/transformation系

不足:

- `EXAM_PREP_2026-06.md` では Ch03 Language Basics、Ch09 Polymorphism Pt2、Ch11 Exception が穴として明記されている。
- 講義ノートとして `Ch03`, `Ch09`, `Ch11` は未保存。
- 実装は Ex11 まであるため、例外処理の演習材料はある。

試験直前に見る順:

1. `JAVA/study-guide-ex07-08.md`
2. `JAVA/lectures/Ch04_ClassesAndObjects.md`
3. `JAVA/lectures/Ch05_Inheritance.md`
4. `JAVA/lectures/Ch06_InheritancePart2.md`
5. `JAVA/lectures/Ch07_Interfaces.md`
6. `JAVA/lectures/Ch08_Polymorphism_Part1.md`
7. `JAVA/exercises/Exercise09.md`
8. `JAVA/exercises/Exercise10.md`
9. `JAVA/exercises/Ex11/`

## フーリエ解析

配置:

- `Math/Fourier/exercises/A9_FourierAssignment.tex`
- `Math/Fourier/exercises/A10_FourierAssignment.tex`
- `Math/Fourier/lectures/.gitkeep`
- `Math/Fourier/src/.gitkeep`

内容:

- A9/A10 のTeX解答がある。
- `EXAM_PREP_2026-06.md` 上では、A9はFFT、A10はラプラス解答実績あり。

不足:

- 講義ノートが未保存。
- 試験範囲として想定されるフーリエ級数、フーリエ変換、DFT/FFT、ラプラス、畳み込みの整理が未作成。

次にやるべきこと:

1. 講義スライドや授業資料を `Math/Fourier/lectures/` に入れる。
2. 試験用公式集を `Math/Fourier/exam-prep/` として作る。
3. A9/A10 を復習用Markdownに変換する。

## C

配置:

- `C/Command.md`
- `C/hello.c`
- `C/Practice/`
- `C/Submit/`
- `C/Reference/`
- `C/2024/practice/`

内容:

- アルゴリズム演習用のCコードが中心。
- テーマは、素数、スタック、キュー、連結リスト、ソート、探索、木の巡回、ヒープ、DFS/BFS、最短経路、動的計画法など。
- `C/Command.md` にはコンパイル・実行・データ入力コマンドのメモがある。

注意:

- 0行の空ファイルがいくつかある。
  - `C/Practice/Ex09/B.c`
  - `C/Reference/Ex03/Queue.c`
  - `C/Reference/Ex12/最小全域木.c`
  - `C/Submit/Ex03/03.c`
  - `C/Submit/Ex06/C.c`
  - `C/Submit/Ex08/A.c`
- `C/problems/` に問題画像があるが、画像の内容は未整理。

## 英語・TOEFL

配置:

- `english/daily-log.md`
- `english/toefl-prep/overview.md`
- `english/vocab/index.md`
- `hub/study-plan.md`

目標:

- TOEFL 88点以上。
- Rose-Hulman 工科大学への交換留学準備。
- 長期的には海外大学院・米国起業に耐える英語力。

現状メモ:

- 推定TOEFL 65点。
- 得意: Writing。
- 最弱点: Listening。
- 2026-04-25 のログでは、TEDを字幕なしで聞いて3割程度、音声変化が課題。
- TOEFL3800を購入済み。

注意:

- TOEFL形式や制度は変わりうるため、実際に対策を再開する時は公式情報確認が必要。
- 6月試験期間中は維持程度でよい。

## 長期学習テーマ

### 数学

`math/index.md` は長期学習としての数学ロードマップ。

順序:

1. 線形代数
2. 統計・確率
3. 微積分
4. フーリエ解析

学校科目としての数学は `Math/`、長期基礎としての数学は `math/` に分ける。

### BCI

`bci/index.md` にロードマップあり。

順序:

1. 神経科学の基礎
2. EEGの基礎
3. 信号処理
4. 機械学習
5. OpenBCI等の実システム

### 宇宙

`space/index.md` に入門ロードマップあり。

まずは宇宙産業、人工衛星、ロケット・軌道の基礎を理解する。

### メタバース・VR

`metaverse-vr/index.md` に入門ロードマップあり。

XRの違い、Meta Quest、Apple Vision Pro、Roblox、BCIとの接点を見る。

## 運用ファイル

| パス | 役割 |
|---|---|
| `inbox/quick-notes.md` | 雑メモ投入口 |
| `templates/daily-log.md` | 日次ログテンプレート |
| `templates/weekly-review.md` | 週次レビューテンプレート |
| `reviews/weekly/2026-W17.md` | 旧learning-os初週レビュー |
| `.github/workflows/weekly-review.yml` | 週次レビュー自動生成 |
| `.github/workflows/monthly-report.yml` | 月次レポート自動生成 |

注意:

- GitHub Actions はレビュー/レポートファイルを作ってcommit/pushする設定。
- 実際にGitHub上で動かす場合、リポジトリ権限・Actions権限の確認が必要。

## Claude Code / Codex 境界

- `.claude/settings.local.json` はClaude Code用。変更しない。
- `AGENTS.md` はCodex用。
- `_archive/learning-os/CLAUDE.md` は旧 `learning-os` の保全コピー。現在のルート指示としては扱わない。
- Claude Codeで再開したい場合も、`.claude/` は残してある。

## 今後の優先順位

2026-05-30時点:

1. 確率統計学 Ch4-5 の期末対策を作る。
2. フーリエ解析の試験用公式・ノートを作る。
3. JAVAの Ch03 / Ch09 / Ch11 欠落を埋める。
4. 試験後にTOEFL計画を実績ベースで更新する。
5. 長期テーマは試験終了後に週次運用へ戻す。

## 依頼を受けた時の初動

試験対策:

1. `hub/context-summary.md`
2. `hub/dashboard.md`
3. `EXAM_PREP_2026-06.md`
4. 対象科目のディレクトリ

TOEFL:

1. `hub/context-summary.md`
2. `hub/study-plan.md`
3. `english/daily-log.md`
4. `english/toefl-prep/overview.md`

長期学習:

1. `hub/goals.md`
2. 対象テーマの `index.md`
3. `reviews/`

コード課題:

1. 対応する `ExerciseXX.md`
2. 対応する `ExXX/` 実装
3. 必要ならコンパイルして確認
