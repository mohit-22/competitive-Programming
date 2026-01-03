





#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2==0){
            cout<<n/2<<" "<<n/2<<endl;
        }
        else{
            int x = -1;
            for(int i=2 ; i<=sqrt(n) ; i++){
                if(n%i==0){
                    x=i;
                    break;
                }
            }
            if(x==-1){
                cout<<1<<" "<<n-1<<endl;
            }
            else cout<<n/x<<" "<<n-(n/x)<<endl;
        }
    }
    return 0;
}