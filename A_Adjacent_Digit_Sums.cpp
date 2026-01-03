#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a>>b;

        

        if(a+1==b) cout<<"Yes"<<endl;
        else if(a%9==0 && b==1) cout<<"Yes"<<endl;
        else if((a-b)%9==8) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        
    }
    return 0;
}