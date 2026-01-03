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
        for(int i=0 ;i<n  ;i++){
            cin>>arr[i];
        }
        vector<pair<int,pair<int,int>>>v;
        for(int i=0 ; i<n ; i++){
            int ct=0;
            int y = i;
            int mx=INT_MIN;
            int at=i;
            for(int j=i ; j<n ; j++){
                if(arr[i]>arr[j]){
                    ct++;
                    y=j;
                }
                else if(arr[i]<arr[j]){
                    ct--;
                    y=j;
                }
                if(mx<ct){
                    mx = ct;
                    at = y;
                }
                
            }
    
            // }
            v.push_back({mx,{i,at}});
        }
        sort(v.begin(),v.end(),greater<pair<int,pair<int,int>>>());

        cout<<v[0].second.first+1<<" "<<v[0].second.second+1<<endl;

    }
    return 0;
}