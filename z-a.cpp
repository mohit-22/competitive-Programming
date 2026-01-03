// // #include<iostream>
// // #include<queue>
// // using namespace std;
// // class Node{
// // public:
// //     char val;
// //     Node *left;
// //     Node *right;
// //     Node(char val){
// //         this->val = val;
// //         this->left = NULL;
// //         this->right = NULL;
// //     }
// // };

// // Node *construct(vector<char>&arr,int n){
// //     queue<Node*>q;
// //     Node *root = new Node(arr[0]);
// //     q.push(root);
// //     int i=1;
// //     int j=2;
// //     while (!q.empty() && i < n) {
// //         Node* temp = q.front();
// //         q.pop();

// //         if (i < n) {
// //             temp->left = new Node(arr[i]);
// //             q.push(temp->left);
// //             i++;
// //         }

// //         if (i < n) {
// //             temp->right = new Node(arr[i]);
// //             q.push(temp->right);
// //             i++;
// //         }
// //     }
    
// //     return root;
// // }


// // vector<char> levelorderqueue(Node* root) {
// //     vector<char> result;
// //     if (!root) return result;

// //     queue<Node*> q;
// //     q.push(root);

// //     while (!q.empty()) {
// //         Node* temp = q.front();
// //         q.pop();
// //         result.push_back(temp->val);

// //         if (temp->left) q.push(temp->left);
// //         if (temp->right) q.push(temp->right);
// //     }

// //     return result;
// // }

// // void deallocateTree(Node* root) {
// //     if (root == NULL) return;
// //     deallocateTree(root->left);
// //     deallocateTree(root->right);
// //     delete root;
// // }


// // int main(){
    
// //    int t;
// //    cin>>t;
// //    while(t--){
// //     int n;
// //     cin>>n;

// //     vector<char>arr;
// //     arr.push_back('s');
// //     int i=0;
// //     while(i<n && arr.size()<n){
// //         if(arr[i]=='s'){
// //             arr.push_back('t');
// //             if(arr.size()==n) break;
// //             arr.push_back('c');
// //         }
// //         else if(arr[i]=='t'){
// //             arr.push_back('c');
// //             if(arr.size()==n) break;
// //             arr.push_back('s');
// //         }
// //         else if(arr[i]=='c'){
// //             arr.push_back('s');
// //             if(arr.size()==n) break;
// //             arr.push_back('t');
// //         }
// //         i++;

// //     }
// //         Node *root = construct(arr,n);
         
// //         vector<char>v = levelorderqueue(root);

// //         if(v[n-1]=='c') cout<<"Circle"<<endl;
// //         else if(v[n-1]=='s') cout<<"Square"<<endl;
// //         else if(v[n-1]=='t') cout<<"Triangle"<<endl;

// //         deallocateTree(root);
        
// //    }
    
    

// // }


// #include <iostream>
// using namespace std;

// int main() {
//     int t;
//     cin >> t;
    
//     while (t--) {
//         long long n;
//         cin >> n;
//         char structure = 's';  

//         while (n > 1) {
//             if (n % 2 != 0) {  
//                 if (structure == 's') structure = 'c';
//                 else if (structure == 't') structure = 's';
//                 else if (structure == 'c') structure = 't';
//             } else {  
//                 if (structure == 's') structure = 't';
//                 else if (structure == 't') structure = 'c';
//                 else if (structure == 'c') structure = 's';
//             }
//             n /= 2;  
//         }
    
//         if (structure == 's') cout<<"Square"<<endl;
//         else if (structure == 't') cout<<"Triangle"<<endl;
//         else cout<<"Circle"<<endl;
//     }

//     return 0;
// }





