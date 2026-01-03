#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a>>b;

        // int x = b/2;
        int mx = -1;
        if(a%2!=0 && b%2!=0){
            mx = a*b+1;
        }
        else{
            if(b%2==0){
                int x = b/2;
                int y = a*x+2;
                 if(y%2==0)mx = a*x+2;
            }
        }
        cout<<mx<<endl;

    }

        
    
    return 0;
}