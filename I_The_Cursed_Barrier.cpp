// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
// ios_base::sync_with_stdio(false); cin.tie(NULL); 
//         int q,n;
//         cin >>q>> n;

//         int arr[n];
//         for(int i=0 ; i<n ; i++){
//             cin>>arr[i];
//         }
//         vector<int>v(n,0);
//         for(int i=0 ; i<n-1 ; i+=2){
//             for(int j=arr[i] ; j<=arr[i+1] ; j++){
//                 v[j-1]++;
//             }
//         }
//         int mx=-1;
//         int k=-1;
//         for(int i=0 ; i<n ; i++){
//             if(v[i]>mx){
//                 mx=v[i];
//                 k=i+1;
//             }
//         }
//         cout<<mx<<" "<<k<<endl;

     
        

        
    
//     return 0;
// }




#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;


} ListNode;

ListNode* createNewNode(int num) {


    ListNode* fresh = (ListNode*)malloc(sizeof(ListNode));
    if (!fresh) {
        printf("Memory allocation failed!\n");


        return NULL;
    }


    fresh->data = num;


    fresh->next = NULL;


    return fresh;
}

ListNode* insertNode(ListNode* chalu, int num) {





    ListNode* newNode = createNewNode(num);


    if (!chalu) return newNode;

    ListNode* temp = chalu;
    while (temp->next) {


        temp = temp->next;
    }
    
    temp->next = newNode;
    return chalu;
}

int searchElement(ListNode* chalu, int key) {



    ListNode* var = chalu;
    int idx = 0;

    while (var) {
        if (var->data == key) {




            return idx; 
        }
        var = var->next;
        idx++;
    }
    return -1;
}

int main() {
    ListNode* chalu = NULL;

    int arr[] = {70, 25, 30, 15, 80, 5, 20, 1, 7, 2, 18, 13, 10, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        chalu = insertNode(chalu, arr[i]);

        
    }

    int userNum;
    printf("Enter the number to search: ");



    scanf("%d", &userNum);




    int result = searchElement(chalu, userNum);

    if (result != -1)
    
        printf("Your element was found at position %d (Original idx)\n", result);
    else
        printf("Your element not found.\n");

    return 0;
}












