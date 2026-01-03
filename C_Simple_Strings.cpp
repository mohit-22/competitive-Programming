// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     string s;
//     cin>>s;
//     int n = s.length();
//     vector<pair<int,int>>v;
//     for(int i=0 ; i<n-1 ; ){
//         int ct=1;
//         int x = i;
//         while(i+1<n && s[i]==s[i+1]){
//             ct++;
//             i++;
//         }
//         if(ct>=2){
//             v.push_back({x,ct});
//         }
//         i++;
//     }
//     for(auto it:v){
//         for(int i=it.first ; i<it.first+it.second ; i+=2){
//             if(it.second%2!=0){
//                 if(i+1!=it.first+it.second ){
//                     if(s[i+1]!='z'){
//                         s[i+1] = s[i+1]+1;
//                     }
//                     else{
//                         s[i+1]='a';
//                     }
//                 }
//             }
//             else{
//                 if(it.first!=0){
//                     int x = abs(s[i]-s[i-1]);
                    
//                     s[i] = 'a' + ( (s[i-1] - 'a' + x + 1) % 26 );
//                     if(s[i]==s[i-1]) s[i] = s[i]+1;
//                 }
//                 else{
//                     if(s[i]!='z'){
//                         s[i] = s[i]+1;
//                     }
//                     else{
//                         s[i]='a';
//                     }
//                 }
//             }
//         }
//     }
//     cout<<s<<endl;
//     return 0;
// }





#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    string s;
    cin>>s;
    int n = s.size();
    for(int i=1 ; i<n ;i++){
        if(s[i]==s[i-1]){
            for(char c='a' ; c<='z' ; c++){
                if(c!=s[i-1] && (i==n-1 || c!=s[i+1])){
                    s[i] = c;
                    break;
                }
            }
        }
    }
    cout<<s<<endl;
    return 0;
}