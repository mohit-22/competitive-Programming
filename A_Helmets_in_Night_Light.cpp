



#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,p;
        cin >> n>>p;

        int arr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        int brr[n];
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
        }

        vector<pair<int,int>>v;
        for(int i=0 ; i<n ; i++){
            v.push_back({brr[i],arr[i]});
        }

        sort(v.begin(),v.end());
        int ct=1;
        int sum=p;
        for(auto it:v){
            if(ct<n && it.first<p){
                int x = n-ct;
                if(x>=it.second) sum+=(it.first*it.second);
                else sum+=it.first*x;

                ct+=min(x,it.second);
            }   
        }
        // sum-=v[0].first;
        sum+=p*(n-ct);

        cout<<sum<<endl;

        

        
        
    }
    return 0;
}