// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int x,y;
//         cin >> x>>y;

//         vector<int>a;
//         vector<int>b;
   
//         while(x>0){
//             int p = x%10;
//             a.push_back(p);
//             x = x/10;
//         }
//         while(y>0){
//             int p = y%10;
//             b.push_back(p);
//             y = y/10;
//         }

//         reverse(a.begin(),a.end());
//         reverse(b.begin(),b.end());

//         if(a[0]>=b[0]){
//             for(int i=1 ; i<a.size() ;i++){
//                 if(a[i]>b[i]){
//                     swap(a[i],b[i]);
//                 }
//             }
//         }
//         else{
//             for(int i=1 ; i<a.size() ;i++){
//                 if(a[i]<b[i]){
//                     swap(a[i],b[i]);
//                 }
//             }
//         }

//         for(int i=0; i<a.size() ; i++){
//             cout<<a[i];
//         }
//         cout<<endl;
//         for(int i=0; i<a.size() ; i++){
//             cout<<b[i];
//         }
//         cout<<endl;
        
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
        string x,y;
        cin>>x>>y;

        vector<int>a;
        vector<int>b;
   
        // while(x>0){
        //     int p = x%10;
        //     a.push_back(p);
        //     x = x/10;
        // }
        // while(y>0){
        //     int p = y%10;
        //     b.push_back(p);
        //     y = y/10;
        // }

        for(char c : x) a.push_back(c - '0');
        for(char c : y) b.push_back(c - '0');


        int p = -1;
        for(int i=0 ; i<a.size() ; i++){
            if(a[i]!=b[i]){
                p=i;
                break;
            }
        }
        for(int i=p+1 ; i<a.size() ; i++){
            if(a[p]>b[p]){
                if(a[i]>b[i]){
                    swap(a[i],b[i]);
                }
            }
            else{
                if(b[i]>a[i]){
                    swap(a[i],b[i]);
                }
            }
        }

        for(int i=0; i<a.size() ; i++){
            cout<<a[i];
        }
        cout<<endl;
        // cout<<endl;
        for(int i=0; i<b.size() ; i++){
            cout<<b[i];
        }
        cout<<endl;
        
    }
    return 0;
}