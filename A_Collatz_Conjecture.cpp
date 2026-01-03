#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int k,n;
        cin >> k>>n;
        int x = n;
        while(k>0){
            x = x*2;
            k--;
        }
        cout<<x<<endl;
        
    }
    return 0;
}