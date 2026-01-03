#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int>mp;
        vector<vector<int>>vp(n);
        for(int i=0; i<n ; i++){
            int s;
            cin>>s;
            // vp[i].resize(s);
            for(int j=0 ; j<s ; j++){
                int x;
                cin>>x;
                vp[i].push_back(x);
                mp[x]++;
            }
        }
        bool flag = false;
        for(int i=0  ;i<n ; i++){
            bool flag2 = true;
            for(auto it:vp[i]){
                if(mp[it]<2){
                    flag2=false;
                    break;
                }
            }
            if(flag2){
                flag = true;
                break;
            }
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}