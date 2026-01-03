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
        int c1=0;
        int c2=0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='-') c1++;
            else c2++;
        }
        if(n<3) cout<<0<<endl;
        else{
            int x = 0;
            int y = 0;
            if(c1%2==0){
                x = c1/2;
                 y = c1/2;
            }
            else{
                x = c1/2;
                y = c1/2+1;
            }

            cout<<x*y*c2<<endl;
            
        }
    }
    return 0;
}