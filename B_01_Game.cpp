// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         string s;
//         cin>>s;
//         int ct0=0,ct1=0;
//         for(int i=0 ; i<s.size() ; i++){
//             if(s[i]=='0') ct0++;
//             else ct1++;
//         }
//         if(ct0==s.size() || ct1==s.size()) cout<<"NET"<<endl;
//         else{
//             int x = s.size()/2;
//                 if(x%2!=0 && ct0==ct1) cout<<"DA"<<endl;
//                 else if(x%2==0 && ct0==ct1) cout<<"NET"<<endl;
//                 else{
//                     if(ct0>ct1 && ct1%2==0) cout<<"NET"<<endl;
//                     else if(ct1>ct0 && ct0%2==0) cout<<"NET"<<endl;
//                     else if(ct0>ct1 && ct1%2!=0) cout<<"DA"<<endl;
//                     else if(ct1>ct0 && ct0%2!=0) cout<<"DA"<<endl;
//                 }
            
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
        string s;
        cin>>s;
        int ct0=0,ct1=0;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='0') ct0++;
            else ct1++;
        }
        if(min(ct0,ct1)%2==0) cout<<"NET"<<endl;
        else cout<<"DA"<<endl;
    }
    return 0;
}