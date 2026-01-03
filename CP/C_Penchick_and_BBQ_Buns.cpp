#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if(n%2==0){
            // int 
            for(int i=1 ; i<=n/2  ;i++){
                cout<<i<<" ";
                cout<<i<<" ";
            }
            cout<<endl;
        }
        else{
            if(n<=26){
                cout<<-1<<endl;
                continue;
            }
            int x=3;
            int ct=0;

            for(int i=1 ; i<=27 ; i++){
                if(i==1 || i==10 || i==26) cout<<1<<" ";
                else if(i==23 || i==27) cout<<2<<" ";
                else{
                    cout<<x<<" ";
                    ct++;
                    if(ct==2) {
                        x++;
                        ct=0;
                    }
                }
            }
            for(int i=28 ; i<=n ; i++){
                cout<<x<<" ";
                ct++;
                if(ct==2) {
                    x++;
                    ct=0;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}