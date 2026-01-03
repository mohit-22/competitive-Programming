#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >>n>>k;
        int x = ((n+1)*(n))/2;
        if(x>=k){
            int low = 1,high=x;
            int ans = INT_MAX;
            while(low<=high){
                int mid = (high+low)/2;
                int x = (mid*(mid+1))/2;
                if(x>=mid){
                    ans = min(ans,mid);
                    high = mid-1;
                }
                else low = mid+1;
            }
            cout<<ans<<endl;
        }
        else{
            int y = k-x;
            int low = 1,high = n-1;
            int ans = INT_MAX;
            while(low>=high){
                int mid = (high+low)/2;
                int m = n-x;
                int x = m*(n+x-1)/2;
                if(x>=y){
                    ans = min(ans,mid);
                    low = mid+1;
                }
                

            }
        }

        
    }
    return 0;
}