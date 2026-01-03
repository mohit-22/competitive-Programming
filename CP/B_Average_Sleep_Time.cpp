#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){

    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    int x = n-k+1;
    int m = min(n-x+1,x);
    int y=1;
    int s=0;
    for(int i=1 ; i<m ; i++){
        s+=(y*arr[i-1]);
        y++;
    }
    int j=n-m+1;
    y--;
    for(int i=j+1 ; i<=n ; i++){
        s+=(y*arr[i-1]);
        y--;
    }
    for(int i=m ; i<=n-m+1 ; i++){
        s+=(m*arr[i-1]);
    }
    // cout<<s/x<<endl;

    double ans = (double)s/x;
    cout<<fixed<<setprecision(10)<<ans<<endl;




    return 0;
}
