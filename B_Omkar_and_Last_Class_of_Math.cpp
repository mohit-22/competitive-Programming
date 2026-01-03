#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans=-1;
        if(n%2==0){
            cout<<n/2<<" "<<n/2<<endl;
        }
        else{
            for(int i=2 ; i<=sqrt(n) ;i++){
                if(n%i==0){
                    ans=n/i;
                    break;
                }
            }
            if(ans==-1) cout<<1<<" "<<n-1<<endl;
            else cout<<ans<<" "<<n-ans<<endl;
        }
    }
    
    return 0;
}