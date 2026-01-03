#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        map<int,vector<int>>mp;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            mp[arr[i]].push_back(i);
        }
        int ct=0;
        bool flag = true;
        for(auto it:mp){
            // v.push_back(it.first);
            if(it.first!=1){
                if((it.second.size()%it.first)!=0){
                    flag=false;
                    break;
                }
            }

            ct = ct+ (it.first)*((it.second.size())/it.first);
        }
        if(ct!=n || flag==false){
            cout<<-1<<endl;
            continue;
        }
        vector<int>ans(n,0);
        int y = 1;
        for(auto it: mp){
            // int it.first = arr[i];
            int x = it.first;
            int ct1=0;
            for(auto it: mp[x]){
                ans[it] = y;
                ct1++;
                if(ct1==x){
                    y++; 
                    ct1=0;
                }

            }
        }
        for(int i=0 ; i<n ; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

      
    }
    return 0;
}