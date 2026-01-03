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
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        vector<int>v;
        // v.push_back(1);
        // int s = arr[0];
        for(int i=1 ; i<n ; i++){
            v.push_back(arr[i]-arr[i-1]);
        }
        vector<int>ans;
        ans.push_back(1);
        int s=1;
        int p=1;
        for(int i=0;i<v.size() ; i++){
            if(v[i]<=s){
                ans.push_back(p);
            }
            else{
                s=v[i];
                p = p+1;
                ans.push_back(p);
            }
        }
        for(int i=0 ; i<n ; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}