#include<stdio.h>

typedef struct{
    int value;
    char symbol[3];
} Card;

int N;

void PrintArray(Card C[]);
void BubbleSort(Card C[], Card Original[]);
void SelectSort(Card C[], Card Original[]);
int isStable(Card C[], Card Original[]);

void PrintArray(Card C[]){
    int i;
    for(i=0;i<N;i++){
        printf("%s",C[i].symbol);
        if(i<N-1){
            printf(" ");
        }
    }
    printf("\n");
}

int isStable(Card C[], Card Original[]){
    int i,j,k,l;
    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            if(C[i].value == C[j].value){
                for(k=0;k<N;k++){
                    if(C[i].symbol[0] == Original[k].symbol[0] && C[i].symbol[1] == Original[k].symbol[1]){
                        break;
                    }
                }

                for (l = 0; l < N; l++) {
                    if (C[j].symbol[0] == Original[l].symbol[0] && C[j].symbol[1] == Original[l].symbol[1]) {
                        break;
                    }
                }

                if(l<k){
                    return 0;
                }
            }
        }
    }
    return 1;
}

void BubbleSort(Card C[], Card Original[]){
    int i,j;
    Card temp; //Card型で
    for(i=0;i<N;i++){
        for(j=N-1;j>=i+1;j--){
            if(C[j].value < C[j-1].value){
                temp = C[j];
                C[j] = C[j-1];
                C[j-1] = temp;
            }
        }
    }
    PrintArray(C);
    if(isStable(C, Original)){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }
}

void SelectSort(Card C[], Card Original[]){
    int i,j,minj;
    Card temp;
    for(i=0;i<N;i++){
        minj = i;
        for(j=i;j<N;j++){
            if(C[j].value < C[minj].value){
                minj = j;
            }
        }
        if(i != minj){
            temp = C[i];
            C[i] = C[minj];
            C[minj] = temp;
        }
    }
    PrintArray(C);
    if(isStable(C, Original)){
        printf("Stable\n");
    }else{
        printf("Not stable\n");
    }

}

int main(){
    int i;
    scanf("%d",&N);
    Card card_inp[N];
    Card card_B[N];
    Card card_S[N];

    for(i=0;i<N;i++){
        scanf("%2s",card_inp[i].symbol);
        card_inp[i].value = card_inp[i].symbol[1] - '0';
        /*アスキーの数字の文字列から０引いたら数字になるやつで
        valueの数字にぶち込む*/
    }

    for(i=0;i<N;i++){
        card_B[i] = card_inp[i];
    }
    BubbleSort(card_B, card_inp);

    for(i=0;i<N;i++){
        card_S[i] = card_inp[i];
    }
    SelectSort(card_S, card_inp);

    return 0;
}
