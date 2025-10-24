#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a>>b;

        int res = INT_MAX;

        for(int i=0 ; i<=32 ; i++){
            int nb = b+i;
            if(nb==1) continue;
            int tempa = a;
            int ct=0;
            while(tempa>0){
                tempa = tempa/nb;
                ct++;
            }
            res = min(res,ct+i);

        }

        cout<<res<<endl;
        
    }
    return 0;
}