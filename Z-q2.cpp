
#include <stdio.h>

#include <stdlib.h>

struct Node {
    int key;

    struct Node* leftNode;
    struct Node* rightNode;
};

struct Node* GivenNode(int vlue) {
    struct Node* tempNode = (struct Node*)malloc(sizeof(struct Node));
    tempNode->key = vlue;

    tempNode->leftNode = NULL;
    tempNode->rightNode = NULL;
    return tempNode;

}

struct Node* BSTTREE(int array[], int s, int e) {

    if (s > e) return NULL;

    int m = (s + e) / 2;

    struct Node* curr = GivenNode(array[m]);

    curr->leftNode = BSTTREE(array, s, m - 1);

    curr->rightNode = BSTTREE(array, m + 1, e);


    return curr;
}

void inoder(struct Node* rootNode) {


    if (rootNode == NULL) return;

    inoder(rootNode->leftNode);

    printf("%d ", rootNode->key);

    inoder(rootNode->rightNode);

}

int main() {



    int size;
    printf("Input size  ");

    scanf("%d", &size);

    int brr[size];
    printf("Enter : ");
    \

    for (int i = 0; i < size; ++i) {


        scanf("%d", &brr[i]);
    }

    for (int x = 0; x < size - 1; ++x) {


        for (int y = 0; y < size - x - 1; ++y) {

            if (brr[y] > brr[y + 1]) {


                int temp = brr[y];


                brr[y] = brr[y + 1];

                brr[y + 1] = temp;
            }
        }
    }

    struct Node* root = BSTTREE(brr, 0, size - 1);
    printf("inoder traversal of tree ");
    inoder(root);

    return 0;
}
