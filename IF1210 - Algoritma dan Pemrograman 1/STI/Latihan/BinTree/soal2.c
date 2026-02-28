#include <stdio.h>
#include "bintree_traversal.h"

int main() {
    // Bentuk pohon BST nya begini:
    //         8
    //       /   \
    //      3     10
    //     / \      \
    //    2   6      14
    //   /   / \     /
    //  1   4   7   13
    
    BinTree T = NIL;
    ElType x;

    // Bangun BST menggunakan insSearchTree
    int keys[] = {8, 3, 10, 2, 6, 14, 1, 7, 4, 13};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        x.key = keys[i];
        x.count = 1;
        insSearchTree(x, &T);
    }

    // Cetak traversal
    printf("Traversal PreOrder: ");
    printPreOrder(T);
    printf("\n");

    printf("Traversal InOrder: ");
    printInOrder(T);
    printf("\n");

    printf("Traversal PostOrder: ");
    printPostOrder(T);
    printf("\n");


    int value;
    printf("Apa yang mau di search? ");
    scanf("%d", &value);
    printf("Level dari %d adalah %d\n", value, level(T,value));
    // // Cetak list traversal
    // NodeList* preList = makeListPreOrder(T);
    // NodeList* inList = makeListInOrder(T);
    // NodeList* postList = makeListPostOrder(T);

    // printf("\nList PreOrder: ");
    // printNodeList(preList);

    // printf("List InOrder: ");
    // printNodeList(inList);

    // printf("List PostOrder: ");
    // printNodeList(postList);

    return 0;
}