#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;

        int high = m;
        int low = 1;
        int ans=INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            int x = m/(mid+1);
            if(((mid*x)+m-(mid+1)*x)*n>=k){
                ans = min(ans,mid);
                high = mid-1;
            }
            else low = mid+1;
        }
        cout<<ans<<endl;
        
    }
    return 0;
}