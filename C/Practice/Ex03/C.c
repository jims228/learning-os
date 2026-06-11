#include<stdio.h>
#include<string.h>
#define MAXQ 2000005
#define NIL 0

typedef struct{
    int key;
    int prev;
    int next;
} Node;

Node node[MAXQ];
int ix =1;

void init_list(void){
    node[NIL].next=NIL;
    node[NIL].prev=NIL;
}

void delete_node(int x){
    int p=node[x].prev;
    int n=node[x].next;
    node[p].next=n;
    node[n].prev=p;
}

void insert_front(int key){
    int x=ix++;
    node[x].key=key;
    int first=node[NIL].next;
    node[x].prev=NIL;
    node[x].next=first;
    node[NIL].next=x;
    node[first].prev=x;
    if(node[NIL].prev==NIL) node[NIL].prev=x;
}

void delete_first(void){
    int first=node[NIL].next;
    if(first != NIL) delete_node(first);
    if(node[NIL].next == NIL) node[NIL].prev=NIL;
}

void delete_last(void){
    int last=node[NIL].prev;
    if(last != NIL) delete_node(last);
    if(node[NIL].prev == NIL) node[NIL].next=NIL;
}

void delete_key(int key){
    int cur=node[NIL].next;
    while(cur != NIL){
        if(node[cur].key == key){
            delete_node(cur);
            if(node[NIL].next == NIL) node[NIL].prev=NIL;
            return;
        }
        cur=node[cur].next;
    }
}

int main(void){
    init_list();
    int n;
    scanf("%d",&n);
    char cmd[16];

    for(int i=0;i<n;i++){
        scanf("%s",cmd);
        if(cmd[0] == 'i'){
            int x;
            scanf("%d",&x);
            insert_front(x);
        }else{
            if(strcmp(cmd,"deleteFirst")==0){
                delete_first();
            }else if(strcmp(cmd,"deleteLast")==0){
                delete_last();
            }else{
                int x;
                scanf("%d",&x);
                delete_key(x);
            }
        }
    }

    int cur = node[NIL].next;
    if(cur != NIL){
        printf("%d",node[cur].key);
        cur = node[cur].next;
        while(cur != NIL){
            printf(" %d",node[cur].key);
            cur = node[cur].next;
        }
    }
    printf("\n");
    return 0;
}