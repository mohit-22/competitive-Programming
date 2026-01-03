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
        // int mx=INT_MIN;
        int sec_max = INT_MIN;
        for(int i=0  ;i<n ; i++){
            cin>>arr[i];
        }
        int mx = INT_MIN;
        for(int i=0  ;i<n-1 ; i++){
            int x = min(arr[i],arr[i+1]);
            mx = max(mx,x);
        }
        int mx2 = INT_MIN;
        for(int i=0 ; i<n-2 ; i++){
            vector<int>v;
            for(int j=i ; j<=2+i ; j++){
                v.push_back(arr[j]);
            }
            sort(v.begin(),v.end());
            int x = v[1];
            mx2 = max(mx2,x);
        }
        cout<<max(mx,mx2)<<endl;
        
    }
    return 0;
}