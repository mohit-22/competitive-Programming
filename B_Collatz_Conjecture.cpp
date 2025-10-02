#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int x,y,k;
        cin >>x>>y>>k;
        bool flag = false;
        int r;
        while(k>0 && x!=1){
            if(x%y!=0)r =(y-(x%y));
            else r=1;
            if(k<r){
                cout<<x+k<<endl;
                flag= true;
                break;
                // continue;
            }
            x = x+r;
            k = k-r;
            while(x%y==0){
                x = x/y;
            }
            if(k==0) break;
        }
        
       int m = k%(y-1);
       if(!flag) cout<<x+m<<endl;
       
        
    }
    return 0;
}

