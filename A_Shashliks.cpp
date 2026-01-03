#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int k,a,b,x,y;
        cin >> k>>a>>b>>x>>y;

        int w = min(x,y);
        int c=0;
        if(w==x){
             c = a;
        }else{
             c=b; 
        }
        int p = k-c;
        int m = ((k-c)/w)+1;

        
    }
    return 0;
}