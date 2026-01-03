#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m,a,b;
        cin >> n>>m>>a>>b;

        int x = max(n*(b-1),n*(m-b));
        int y = max(m*(n-a),m*(a-1));
        // cout<<x<<" "<<y<<endl;

        if(y>=x){
            n = max(a,n-a);
            // int k = (n)/2;
            // int l = (m)/2;
            // cout<<1+k+l<<endl;
            while(n>1 || m>1){
                if(n!=1 & m!=1){
                    if(n%2!=0 && m%2!=0){
                        n = (n+1)/2;
                        
                    }
                }
            }
        }
        else{
            m = max(b,m-b);
            int k = (n)/2;
            int l = (m)/2;
            cout<<1+k+l<<endl;;
        }
        
    }
    return 0;
}