#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,s;
        cin >> n>>s;
        vector<int>arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        vector<int>v(n+1,0);
        v[1] = arr[0];
        for(int i=2 ; i<=n ; i++){
            v[i] = arr[i-1]+v[i-1];
        }
        if(v[n]<s){
            cout<<-1<<endl;
            continue;
        } 
        int ans = INT_MAX;
        for(int i=1 ; i<n+1 ; i++){
            int find = s+v[i-1];
            if(v[n]<s) continue;
            else{
                int idx = upper_bound(v.begin(), v.end(), find) - v.begin();
                idx--;
                int left = i-1;
                int right = n-idx;
                ans = min(ans,left+right);

            }
        }
        cout<<ans<<endl;
    }
    return 0;
}