#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c,d;
        cin >> a>>b>>c>>d;
        int x = min(a,c);
        int y = min(b,d);
        if(x>=y) cout<<"Gellyfish"<<endl;
        else cout<<"Flower"<<endl;
        
    }
    return 0;
}