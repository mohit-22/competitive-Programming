#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin>>s;
        int ct1=0;
        int ct2=0;
        for(int i=0 ; i<n ; i++){
            if(i<=(n/2)){
                if(s[i]=='0')  ct1++;
            }
            else{
                if(s[i]=='0') ct2++;
            }
            
        }
    }
    return 0;
}