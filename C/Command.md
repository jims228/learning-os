パーミッション絶対に変える

cat FILE
less FILE
head -n 20 FILE
tail -n 20 FILE

touch p{1..12}.c

ls /home/course/alg1/2025/data
head -n 3 /home/course/alg1/2025/data/A.txt

## Cをコンパイルして実行
gcc -O2 -std=c11 -Wall -Wextra p1.c -o p1
./p1 < /home/course/alg1/2025/data/A.txt

##  よく使う: 連続でやる
gcc -O2 -std=c11 -Wall -Wextra main.c -o main && ./main < /home/course/alg1/2024/data/A.txt

## 5 出力をファイルに保存
./p1 < /home/course/alg1/2024/data/A.txt > out.txt
cat out.txt