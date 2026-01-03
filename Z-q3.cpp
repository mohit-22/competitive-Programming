#include <stdio.h>

#include <stdlib.h>



struct TreeNode {

    int key;
    struct TreeNode* leftBranch;


    struct TreeNode* rightBranch;
};

struct TreeNode* make_Node(int value) {


    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->key = value;

    newNode->leftBranch = NULL;
    newNode->rightBranch = NULL;
    return newNode;

}

struct TreeNode* Make_BalancedTree(int arr[], int start, int end) {


    if (start > end) return NULL;
    int center = (start + end) / 2;


    struct TreeNode* rootNode = make_Node(arr[center]);

    rootNode->leftBranch = Make_BalancedTree(arr, start, center - 1);


    rootNode->rightBranch = Make_BalancedTree(arr, center + 1, end);
    return rootNode;
}

void put_Node(struct TreeNode* root, int value) {
    if (root == NULL) return;


    if (value < root->key) {


        if (root->leftBranch == NULL) {


            root->leftBranch = make_Node(value);


        } else {
            put_Node(root->leftBranch, value);
        }
    } else {
        if (root->rightBranch == NULL) {


            root->rightBranch = make_Node(value);


        } else {
            put_Node(root->rightBranch, value);


        }
    }
}

void inorder_main_Traverse(struct TreeNode* root) {


    if (root == NULL) return;
    inorder_main_Traverse(root->leftBranch);


    printf("%d ", root->key);
    inorder_main_Traverse(root->rightBranch);
}

int main() {
    int num;
    printf("Enter number for add: ");


    scanf("%d", &num);

    int inputArr[] = {1, 2, 3, 4, 5, 6};


    struct TreeNode* root = Make_BalancedTree(inputArr, 0, 5);


    printf("Inorder  of the previous tree: ");
    inorder_main_Traverse(root);



    put_Node(root, num);

    printf("\nInorder  of the new tree: ");


    inorder_main_Traverse(root);

    return 0;
}
