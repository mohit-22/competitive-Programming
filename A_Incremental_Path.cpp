// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,m,x;
//         string s;
//         cin>>n>>m>>s;
//         set<int>st;
//         for(int i=0 ; i<m ;i++){
//             cin>>x,st.insert(x);
//         }
//         x = 1;
//         for(int i=0 ; i<s.length() ; i++){
//             x++;
//             if(s[i]=='B'){
//                 while(st.find(x)!=st.end()) x++;
//             }
//             st.insert(x);
//             if(s[i]=='B'){
//                 while(st.find(x)!=st.end()) x++;
//             }
//         }
//         cout<<st.size()<<endl;
//         for(auto it:st){
//             cout<<it<<" ";
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
        int n,m,x;
        string s;
        cin>>n>>m>>s;
        set<int>white;
        set<int>ans;
        for(int i=1 ; i<=2*(n+m) ; i++){
            white.insert(i);
        }
        for(int i=0 ; i<m ;i++){
            cin>>x,ans.insert(x),white.erase(x);
        }
        int curr=1;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='A'){
                curr++;
                if(white.count(curr)){
                    white.erase(curr);
                    ans.insert(curr);
                }
            }else{
                curr = *white.upper_bound(curr);
                auto temp = curr;
                curr = *white.upper_bound(curr);
                white.erase(temp);
                ans.insert(temp);
            }
        }
        cout<<ans.size()<<endl;
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}