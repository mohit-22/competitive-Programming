#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    // int t;
    // cin >> t;
    // while(t--){
        int n,k;
        cin >> n>>k;
        int arr[n];
        vector<int>prev(n);
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }

        prev[0] = arr[0];
        for(int i=1 ;i<n ; i++){
            prev[i] = prev[i-1]+arr[i];
        }
        int sum=0;
        for(int i=k-1 ; i<n ; i++){
            if(i-k>=0) sum+=prev[i]-prev[i-k];
            else sum+=prev[i];
        }
        int x = n-k+1;
       double ans = (double)sum / x;
        cout<<fixed<<setprecision(10)<<ans<<endl;


        
    // }
    return 0;
}