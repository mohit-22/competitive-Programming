// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         int arr[n],brr[n];
//         priority_queue<int>qa;
//         priority_queue<int>qb;
//         for(int i=0 ; i<n ; i++){
//             cin>>arr[i];
//         }
//         for(int i=0 ; i<n ;i++){
//             cin>>brr[i];
//         }

//         int crr[n],drr[n];
//         priority_queue<int>qc;
//         priority_queue<int>qd;
//         for(int i=0 ; i<n ; i++){
//             crr[i]=arr[i];
//         }
//         for(int i=0 ; i<n ;i++){
//             drr[i] = brr[i];
//         }
        
//         int ct=0;
//         vector<pair<int,int>>v;
//         vector<pair<int,int>>v1;
        
//         for(int i=0 ; i<n ; i++){
//             qa.push(arr[i]);
//         }
//         for(int i=0 ; i<n ;i++){
//             qb.push(brr[i]);
//         }
//         for(int i=0 ; i<n ; i++){
//             int x = qa.top();
//             int p=0;
//             for(int j=0 ; j<n ; j++){
//                 if(arr[j]==x){
//                     p=j;
//                     break;
//                 }
//             }
//             for(int j=p; j<n-1 ; j++){
//                 if(arr[j]>arr[j+1]){
//                     ct++;
//                     v.push_back({1,j+1});
//                     swap(arr[j],arr[j+1]);
//                 }
//             }
//             qa.pop();
//         }
//         for(int i=0 ; i<n ; i++){
//             int x = qb.top();
//             int p=0;
//             for(int j=0 ; j<n ; j++){
//                 if(brr[j]==x){
//                     p=j;
//                     break;
//                 }
//             }
//             for(int j=p; j<n-1 ; j++){
//                 if(brr[j]>brr[j+1]){
//                     ct++;
//                     v.push_back({2,j+1});
//                     swap(brr[j],brr[j+1]);
//                 }
//             }
//             qb.pop();
//         }
//         for(int i=0 ; i<n ;i++){
//             if(arr[i]>brr[i]){
//                 ct++;
//                 // cout<<3<<" "<<i+1<<endl;
//                 v.push_back({3,i+1});
//                 swap(arr[i],brr[i]);
//             }
//         }


       
//         int ct2=0;
        
//         for(int i=0 ; i<n ;i++){
//             if(crr[i]>drr[i]){
//                 ct2++;
//                 // cout<<3<<" "<<i+1<<endl;
//                 v1.push_back({3,i+1});
//                 swap(crr[i],drr[i]);
//             }
//         }
//         for(int i=0 ; i<n ; i++){
//             qc.push(crr[i]);
//         }
//         for(int i=0 ; i<n ;i++){
//             qd.push(drr[i]);
//         }
//         for(int i=0 ; i<n ; i++){
//             int x = qc.top();
//             int p=0;
//             for(int j=0 ; j<n ; j++){
//                 if(crr[j]==x){
//                     p=j;
//                     break;
//                 }
//             }
//             for(int j=p; j<n-1 ; j++){
//                 if(crr[j]>crr[j+1]){
//                     ct2++;
//                     v1.push_back({1,j+1});
//                     swap(crr[j],crr[j+1]);
//                 }
//             }
//             qc.pop();
//         }
//         for(int i=0 ; i<n ; i++){
//             int x = qd.top();
//             int p=0;
//             for(int j=0 ; j<n ; j++){
//                 if(drr[j]==x){
//                     p=j;
//                     break;
//                 }
//             }
//             for(int j=p; j<n-1 ; j++){
//                 if(drr[j]>drr[j+1]){
//                     ct2++;
//                     v1.push_back({2,j+1});
//                     swap(drr[j],drr[j+1]);
//                 }
//             }
//             qd.pop();
//         }
//         if(ct<ct2){
//             cout<<ct<<endl;
//             for(auto it:v){
//                 cout<<it.first<<" "<<it.second<<endl;
//             }
//         }
//         else{
//             cout<<ct2<<endl;
//             for(auto it:v1){
//                 cout<<it.first<<" "<<it.second<<endl;
//             }
//         }
        
//     }
//     return 0;
// }





#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int brr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
        }
        vector<pair<int,int>>v;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n-1; j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                v.push_back({1,j+1});

                }
            }
        }

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n-1; j++){
                if(brr[j]>brr[j+1]){
                    swap(brr[j],brr[j+1]);
                     v.push_back({2,j+1});
                }
               
            }
        }
        for(int i=0 ; i<n ; i++){
            if(arr[i]>brr[i]){
                swap(arr[i],brr[i]);
                v.push_back({3,i+1});
            }
        }
        cout<<v.size()<<endl;
        for(auto it: v){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    return 0;
}