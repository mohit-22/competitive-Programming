#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k,x;
        cin >> n>>k>>x;

        int y = n*x;
        bool flag = false;
        if(-y<=k && k<=y) flag  =true; 
        if(flag==false) cout<<-1<<endl;
        else{
            if(k%x==0) cout<<abs(k/x)<<endl;
            else cout<<abs(abs(k/x)+1)<<endl;
        } 
        
    }
    return 0;
}