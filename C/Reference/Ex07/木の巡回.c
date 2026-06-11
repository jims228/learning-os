#include <stdio.h>

#define MAXN 100

int n;
int left[MAXN],right[MAXN],parent[MAXN];

void preorder(int u){
    // 根 -> 左 -> 右
    if(u == -1) return;
    printf(" %d",u);
    preorder(left[u]);
    preorder(right[u]);
}

void inorder(int u){
    // 左 -> 根 -> 右
    if(u == -1) return;
    inorder(left[u]);
    printf(" %d",u);
    inorder(right[u]);
}

void postorder(int u){
    // 左 -> 右 -> 根
    if(u == -1) return;
    postorder(left[u]);
    postorder(right[u]);
    printf(" %d",u);
}

int main(void){
    scanf("%d",&n);

    // 初期化
    for(int i=0;i < n;i++){
        left[i]=-1;
        right[i]=-1;
        parent[i]=-1;
    }

    // 入力: id left right
    // 子があるなら parent[child]=id を入れておく
    for(int i=0;i < n;i++){
        int id,l,r;
        scanf("%d %d %d",&id,&l,&r);

        left[id]=l;
        right[id]=r;

        if(l != -1) parent[l]=id;
        if(r != -1) parent[r]=id;
    }

    // 根を探す: 親がいない頂点が根
    int root=-1;
    for(int i=0;i < n;i++){
        if(parent[i] == -1){
            root=i;
            break;
        }
    }

    // 出力は各番号の前に必ず空白が必要
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
