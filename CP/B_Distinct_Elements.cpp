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
        for(int i=0;  i<n ; i++){
            cin>>arr[i];
        }
        vector<int>ans;
        ans.push_back(1);
        int mx=1;
        for(int i=1 ; i<n ; i++){
            int x = arr[i]-arr[i-1];
            if(x>ans.size()){
                mx = max(mx,ans[ans.size()-1]);
                mx = mx+1;
                ans.push_back(mx);   
            }
            else ans.push_back(ans[ans.size()-x]);
        }
        for(int i=0 ; i<n  ;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}