#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        int arr[n];
        for(int i = 0 ;i<n ; i++){
            cin>>arr[i];
        }
        if(n==1) cout<<0<<endl;
        else{
            sort(arr,arr+n);
            vector<int>brr;
            for(int i = 0 ; i<n-1 ; i++){
            brr.push_back(arr[i+1]-arr[i]);
            }
            int count=0;
            int mx = 0;
            for(int i = 0 ; i<brr.size() ; i++){
                if(brr[i]<=k){
                    count++;
                    mx = max(count,mx);
                }
                
                else count = 0;
            }
            cout<<n-mx-1<<endl;
        }
        
    }
    return 0;
}