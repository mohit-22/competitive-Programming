#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        // int n;
        // cin >> n;
        string s;
        cin>>s;
        int n = s.length();
        map<char,int>mp;
        int x=-1;
        for(int i=0 ; i<n ; i++){
            if(mp[s[i]]==0){
                mp[s[i]]++; 
                x = i;
            }
            else{
                break;
            }
        }
        int y = 0;
        bool flag = true;
        for(int i=x+1 ; i<n ; i++){
            if(s[i]==s[y]){
                y++;
                if(y==x+1){
                    y = 0;
                }
            }
            else{
                flag =false;
                break;
            }
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        // for(auto it:mp){ 
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        // cout<<x<<endl;

    }
    return 0;
}