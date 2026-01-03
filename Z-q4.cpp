#include <stdio.h>
#include <stdlib.h>


typedef struct Node {

    int value;
    struct Node* left;

    struct Node* right;

} Node;


Node* Make_Node(int v) {

    Node* temp = (Node*)malloc(sizeof(Node));
    temp->value = v;


    temp->left = NULL;
    temp->right = NULL;

    
    return temp;
}

Node* Make_BalancedTree(int nums[], int start, int end) {


    if (start > end) return NULL;
    int middle = (start + end) / 2;


    Node* root = Make_Node(nums[middle]);
    root->left = Make_BalancedTree(nums, start, middle - 1);

    root->right = Make_BalancedTree(nums, middle + 1, end);
    return root;


}

void Inorder_main_Traverse(Node* root) {
    if (root == NULL) return;


    Inorder_main_Traverse(root->left);


    printf("%d ", root->value);


    Inorder_main_Traverse(root->right);
}

int left_Mai_max(Node* root) {

    if (root->right == NULL) return root->value;

    return left_Mai_max(root->right);
}

Node* Tree_main_sai_delete(Node* root, int value_hatani_wali) {
    if (root == NULL) return NULL;

    if (root->value == value_hatani_wali && root->left == NULL && root->right == NULL) return NULL;
    if (root->value == value_hatani_wali && root->left == NULL) return root->right;
    if (root->value == value_hatani_wali && root->right == NULL) return root->left;

    if (root->value == value_hatani_wali) {
        int replacement = left_Mai_max(root->left);
        root->value = replacement;

        root->left = Tree_main_sai_delete(root->left, replacement);
        return root;
    }

    if (root->value > value_hatani_wali)
        root->left = Tree_main_sai_delete(root->left, value_hatani_wali);
    else
        root->right = Tree_main_sai_delete(root->right, value_hatani_wali);

    return root;
}


int main() {
    int deleteNum;
    printf("Enter the value which you want to delete: ");


    scanf("%d", &deleteNum);

    int inputArray[] = {1, 2, 3, 4, 5, 6};
    Node* root = Make_BalancedTree(inputArray, 0, 5);

    printf("Inorder  of the previous tree: ");



    Inorder_main_Traverse(root);

    root = Tree_main_sai_delete(root, deleteNum);

    printf("\nInorder  after deletion: ");

    Inorder_main_Traverse(root);

    return 0;
}
