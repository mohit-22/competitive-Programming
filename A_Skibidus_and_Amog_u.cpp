#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        string ans="";
        for(int i=0 ; i<s.length()-2 ; i++){
            ans+=s[i];
        }
        ans+='i';
        for(int i=0 ; i<ans.length();i++){
            cout<<ans[i];
        }
        cout<<endl;
        
    }
    return 0;
}