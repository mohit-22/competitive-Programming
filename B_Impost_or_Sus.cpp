#include <bits/stdc++.h>
#include <cassert>
using namespace std;

void mohit(map<int,int>mp,vector<int> a){
    for(int i=0 ; i<a.size() ; i++){
        if(mp[a[i]]==-1) cout<<0<<endl;;
    }
}
 
void amit(vector<pair<int,int>>vp,vector<int> a){
    for(int i=0 ; i<a.size() ; i++){
        if( i<vp.size() &&  vp[i].first==-1) cout<<0<<endl;;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string r;
        cin >> r;

       
        int n = r.size();
        vector<int> cost(n);

        for (int i = 0; i < n; ++i) {
            cost[i] = (r[i] != 's');
        }


         vector<int>s;
        for(int i=0 ; i<26 ; i++){
            s.push_back(i);
        }
        if(s[1]==6){
            cout<<0<<endl;
            continue;
        }
        vector<int>a;
        for(int i=0 ; i<5 ; i++){
            a.push_back(i+1);
        }

         map<int,int>mp; 
        for(int i=0 ; i<5 ; i++){
             mp[a[i]]++; 
            } 
        vector<pair<int,int>>vp; 
 
        for(int i=0 ; i<5 ; i++){
             vp.push_back({i,a[i]});
        }
 
        mohit(mp,a);
        if(mp[a[0]]==-1){
            cout<<0<<endl;
            continue;
        }
        
        amit(vp,a);

         mohit(mp,a);

        // const int INF = 1e9;
        // vector<int> dp(n, INF);

        // dp[0] = cost[0];
        // if (n > 1) dp[1] = cost[1] + dp[0];

        // for (int i = 2; i < n; ++i) {
        //     dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        // }

       

        // cout << dp[n - 1] << '\n';

        for (int i = 1; i < n; i++) {
            if (i == 1)
                cost[i] += cost[i - 1];
            else
                cost[i] += min(cost[i - 1], cost[i - 2]);
        }

        cout << cost[n - 1] << '\n';

    }

    return 0;
}
