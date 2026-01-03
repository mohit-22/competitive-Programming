#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());

        int ans=0;
        for(int i=0 ; i<n-2 ; i++){
            for(int j = i+1 ; j<n-1 ; j++){
                int lb = lower_bound(arr.begin()+j+1,arr.end() , arr[i]+arr[j])-arr.begin();
                
                if(arr[lb]>=arr[i]+arr[j] || lb==n) lb--;
                if(lb!=n-1){
                    if(arr[i]+arr[j]+arr[lb]>arr[n-1]){
                        int lb2 = lower_bound(arr.begin()+j+1,arr.end() , arr[n-1]-arr[i]-arr[j]+1)-arr.begin();
                        ans+=lb-lb2+1;
                    }
                }else{
                    if(arr[i]+arr[j]>arr[n-1]){
                        // int lb2 = lower_bound(arr.begin()+j+1,arr.end() , arr[i]+arr[j]-arr[n-1])-arr.begin();
                        ans+=lb-j;
                    }
                }
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}