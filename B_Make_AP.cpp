#include <bits/stdc++.h>
using namespace std;


int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        double m=(double)(2*b-c)/a;
        double n=(double)(a+c)/(2*b);
        double o = (double)(2*b-a)/c;

        if(m>=1 && floor(m) == m) cout<<"YES"<<endl;
        else if(n>=1 && floor(n) == n) cout<<"YES"<<endl;
        else if(o>=1 && floor(o) == o) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;



        
    }
    return 0;
}