#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){

    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        int cta=0;
        for(int i=0 ; i<n ;i++){
            if(s[i]=='A') cta++;
        }
        while(q--){
            int x;
            cin>>x;
            int ans=0;
            if(cta==n){
                ans=x;
            }
            else{
                int i=0;
                while(x!=0){
                    if(s[i]=='A'){
                        x--;
                    }
                    else{
                        x=x/2;
                    }
                    ans++;
                    i++;
                    if(i==s.length()) i=0;
                    if(x<=0) break;
                }
            }
            cout<<ans<<endl;
        }
    }
    




    return 0;
}
