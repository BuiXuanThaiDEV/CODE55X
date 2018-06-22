#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct _nodetree{
    char word;
    struct _nodetree *leftchild;
    struct _nodetree *rightchild;
}NodeTree;

NodeTree *makeNewNode(char x){
    NodeTree *NewNode = NULL;
    NewNode = (NodeTree*)malloc(sizeof(NodeTree));
    NewNode->word = x;
    NewNode->leftchild = NULL;
    NewNode->rightchild = NULL;
    return NewNode;
}
void preOder(NodeTree *tree){
    if(tree == NULL)
        return;
    printf("%c ",tree->word);
    preOder(tree->leftchild);
    preOder(tree->rightchild);

}
void postOder(NodeTree *tree){
    if(tree == NULL)
        return;

    postOder(tree->leftchild);
    postOder(tree->rightchild);
    printf("%c ",tree->word);

}
void inOder(NodeTree *tree){
    if(tree == NULL)
        return;
    inOder(tree->leftchild);
    printf("%c ",tree->word);
    inOder(tree->rightchild);
}


int main(){
    NodeTree *nut1 =NULL;
    NodeTree *A = makeNewNode('A');
    NodeTree *B = makeNewNode('B');
    NodeTree *C = makeNewNode('C');
    NodeTree *D = makeNewNode('D');
    NodeTree *E = makeNewNode('E');
    NodeTree *F = makeNewNode('F');
    NodeTree *G = makeNewNode('G');
    NodeTree *H = makeNewNode('H');
    NodeTree *I = makeNewNode('I');
    A->leftchild = B;
    A->rightchild = C;
    B->leftchild = E;
    B->rightchild = F;
    F->leftchild = H;
    C->leftchild = G;
    C->rightchild = D;
    G->rightchild = I;
    nut1 = A;
    preOder(nut1);
    printf("\n");
    postOder(nut1);
    printf("\n");
    inOder(nut1);
}
