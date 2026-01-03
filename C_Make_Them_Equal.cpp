#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        char ch;
        cin >> n;
        cin>>ch;
        string s;
        cin>>s;
        bool flag = true;
        for(int i=0 ; i<n ; i++){
            if(s[i]!=ch){
                flag = false;
                break;
            }
        }
        if(flag==true){
            cout<<0<<endl;
            continue;
        }
        if(s[n-1]==ch){
            cout<<1<<endl;
            cout<<n<<endl;
        }
        else{
            bool flag1 = false;
            int x = -1;
            for(int i=n-1 ; i>=n/2 ; i--){
                if(s[i]==ch){
                    flag1 = true;
                    x = i;
                    break;
                }
            }
            if(flag1==true){
                cout<<1<<endl;
                cout<<x+1<<endl;
            }
            else{
                cout<<2<<endl;
                cout<<n-1<<" "<<n<<endl;
            }
        }
        
    }
    return 0;
}









// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         char ch;
//         cin >> n;
//         cin>>ch;
//         string s;
//         cin>>s;
//         bool flag = true;
//         for(int i=0 ; i<n ; i++){
//             if(s[i]!=ch){
//                 flag = false;
//                 break;
//             }
//         }
//         if(flag==true){
//             cout<<0<<endl;
//             continue;
//         }
//         // if(s[n-1]==ch){
//         //     cout<<1<<endl;
//         //     cout<<n<<endl;
//         // }
//         else{
//             bool flag1 = false;
//             int x = -1;
//             for(int i=n-1 ; i>=n/2 ; i--){
//                 if(s[i]==ch){
//                     flag1 = true;
//                     x = i;
//                     break;
//                 }
//             }
//             if(flag1==true){
//                 cout<<1<<endl;
//                 cout<<x+1<<endl;
//             }
//             else{
//                 cout<<2<<endl;
//                 cout<<n-1<<" "<<n<<endl;
//             }
//         }
        
//     }
//     return 0;
// }