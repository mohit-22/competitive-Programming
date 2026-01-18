#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        vector<int>arr(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        if(k>=3){
            cout<<0<<endl;
            continue;
        }
        sort(arr.begin(),arr.end());
        vector<int>v;
        int mn = LLONG_MAX;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                v.push_back(abs(arr[j]-arr[i]));
            }
        }
        sort(v.begin(),v.end());

        mn = min(v[0],arr[0]);

        int mn2 = LLONG_MAX;
        if(k==2){ 
            
            for(int i=0 ; i<n ; i++){
                auto it = lower_bound(v.begin(),v.end(),arr[i]);
                int idx = it-v.begin();
                if(idx<v.size()) mn2 = min(mn2,abs(v[idx]-arr[i]));
                if(idx-1>=0){
                    mn2 = min(mn2,abs(v[idx-1]-arr[i]));
                }
            }
        }
        int ans = min(mn2,mn);

        cout<<ans<<endl;
        
    }
    return 0;
}