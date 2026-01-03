#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
ios_base::sync_with_stdio(false); cin.tie(NULL);    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        if(n==0) cout<<"99"<<endl;
        else if(n>0){
            s="987654321";
            if(n>=1 && n<=8){
                for(int i=0  ;i<=n ;i++){
                    cout<<s[i];
                }
                cout<<endl;
            }
            else cout<<"IMPOSSIBLE"<<endl;
        }
        else {
            s="123456789";
            if(n>=-8 && n<=-1){
                int m=abs(n);
                for(int i=0  ;i<=m ;i++){
                    cout<<s[i];
                }
                cout<<endl;
            }
            else cout<<"IMPOSSIBLE"<<endl;
        }
        

        
    }
    return 0;
}