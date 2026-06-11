#include <stdio.h>

#define MAX 100
#define NIL -1

int n;
int L[MAX], R[MAX], P[MAX];

void preorder(int u){
    if(u==NIL) return;
    printf(" %d",u);
    preorder(L[u]);
    preorder(R[u]);
}

void inorder(int u){
    if(u==NIL) return;
    inorder(L[u]);
    printf(" %d",u);
    inorder(R[u]);
}

void postorder(int u){
    if(u==NIL) return;
    postorder(L[u]);
    postorder(R[u]);
    printf(" %d",u);
}

int main(void){
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        L[i]=NIL;
        R[i]=NIL;
        P[i]=NIL;
    }

    for(int i=0;i<n;i++){
        int id,l,r;
        scanf("%d %d %d",&id,&l,&r);

        L[id]=l;
        R[id]=r;

        if(l!=NIL) P[l]=id;
        if(r!=NIL) P[r]=id;
    }

    int root=NIL;
    for(int i=0;i<n;i++){
        if(P[i]==NIL){
            root=i;
            break;
        }
    }

    printf("Preorder\n");
    preorder(root);
    printf("\n");

    printf("Inorder\n");
    inorder(root);
    printf("\n");

    printf("Postorder\n");
    postorder(root);
    printf("\n");

    return 0;
}
