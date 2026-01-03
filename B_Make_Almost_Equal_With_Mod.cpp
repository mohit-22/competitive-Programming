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
        for(int i=0 ; i<n; i++) cin>>arr[i];
        int ans = -1;
        for(int i=1  ;i<=60 ; i++){

            int rem = 1LL<<i;
            // or 
            // int rem = pow(2,i);

            set<int>diff;
            for(int i=0 ; i<n ; i++){
                diff.insert(arr[i]%rem);
            }
            if(diff.size()==2){
                ans=rem;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}