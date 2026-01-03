





#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,r,b;
        cin >> n>>r>>b;
        int x = r/(b+1);
        int y = r%(b+1);
        for(int i=0 ; i<b+1; i++){
            int m = x;
            while(m>0){
                cout<<"R";
                m--;
            }
            if(y>0){
                cout<<"R";
                y--;
            }
            if(i!=b) cout<<"B";
        }
        cout<<endl;
        
    }
    return 0;
}