#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a>>b;
        int x = a+b;
        int n=0;
        while((n*(n+1))/2<x){
            if(((n+1)*(n+2)/2)<=x){
                n++;
            }
            else break;
        }
        cout<<n<<endl;
    }
    return 0;
}