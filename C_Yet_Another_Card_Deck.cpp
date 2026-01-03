#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    // int t;
    // cin >> t;
    // while(t--){
        int n,q;
        cin >> n>>q;
        vector<int>first_pos(51,n+1);
        for(int i=1 ; i<=n ;i++){
            int color;
            cin>>color;
            if(first_pos[color]==n+1){
                first_pos[color] = i;
            }
        }
        while(q--){
            int query;
            cin>>query;
            int ans = first_pos[query];
            for(int i=1 ; i<=50 ; i++){
                if(first_pos[i]<ans){
                    first_pos[i]++;
                }
            }
            first_pos[query] =1;
            cout<<ans<<" ";
        }
    // }
    return 0;
}