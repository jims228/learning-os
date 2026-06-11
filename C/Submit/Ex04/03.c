#include<stdio.h>
#include<string.h>
int Dictionary[25000001];

int getCharValue(char ch){
    if(ch == 'A') return 1;
    if(ch == 'C') return 2;
    if(ch == 'G') return 3;
    if(ch == 'T') return 4;
    return 0;
}

// 文字列全体から一意なIDを計算する関数
//１０進数だとメモリ取りすぎるから、４進数で考える
long long getID(char str[]){
    long long id = 0;
    long long powerOf4 = 1; //４のN乗にする、位をとって文字をダブらないようにするため
    int i;

    for(i=0;i<strlen(str);i++){
        id = id + getCharValue(str[i]) * powerOf4;
        powerOf4 = powerOf4 * 4; //次の文字のために重みを４倍にする
    }
    return id;
}

int main(){
    int n;
    char command[10];
    char str[15];
    scanf("%d",&n);
    while(n--){
        scanf("%s %s", command, str);
        long long key = getID(str);
        
        if(command[0] == 'i'){
            Dictionary[key] = 1;
        }
        else{
            if(Dictionary[key] == 1){
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }
    return 0;
}