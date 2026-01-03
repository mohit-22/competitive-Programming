#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>>arr,brr,crr;
        for(int i=0 ; i<n ; i++){
            int x;
            cin>>x;
            arr.push_back({x,i+1});
        }
        for(int i=0 ; i<n ; i++){
             int x;
            cin>>x;
            brr.push_back({x,i+1});
        }
        for(int i=0 ; i<n ; i++){
            int x;
            cin>>x;
            crr.push_back({x,i+1});
        }

        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        sort(crr.begin(),crr.end());
        int mx=0;
        for(int i=n-1 ; i>=n-3 ; i--){
            for(int j=n-1 ; j>=n-3 ; j--){
                for(int k=n-1 ; k>=n-3 ; k--){
                    int x = arr[i].second,y=brr[j].second,z=crr[k].second;
                    if(x==y || y==z || z==x) continue;
                    int ans = arr[i].first+brr[j].first+crr[k].first;
                    mx = max(mx,ans);
                }
            }
        }
        cout<<mx<<endl;
        

    }
    return 0;
}