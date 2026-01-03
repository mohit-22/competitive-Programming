#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        int ct=0;
        int mx=0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='1'){
                ct++;
                mx = max(ct,mx);
            }
            else {
                ct=0;
            }
        }
        ct=0;
        int t=-1;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='1'){
                ct++;
                t=i;
            }
            else break;
        }
        for(int i=n-1 ; i>t ; i--){
            if(s[i]=='1'){
                ct++;
            }
            else{
                break;
            }
        }
        if(mx<ct){
            mx = ct;
        }

        if(mx==n){
            cout<<n*n<<endl;
        }
        else{
            int x = (mx+1)/2;
            int y = (mx+2)/2;
            cout<<x*y<<endl;
        }
        
    }
    return 0;
}