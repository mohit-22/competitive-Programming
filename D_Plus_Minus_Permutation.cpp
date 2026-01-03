#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,x,y;
        cin >> n>>x>>y;
        
        int r = __gcd(x,y);
        int s = (x*y)/r;
        s = n/s;
        int p = (n/x)-s;
        int q = (n/y)-s;
        int ans=0;
        // for(int i=1 ; i<=p ; i++){
        //     ans+=n;
        //     n--;
        // }
        // for(int i=1 ; i<=q ; i++){
        //     ans-=i;
        // }
        int w = (n*(n+1))/2 -( (n-p)*(n-p+1))/2;
        int m = (q*(q+1))/2;
        cout<<w-m<<endl;
        

        
    }
    return 0;
}