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
        int ct=0;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='0'){
                ct++;
            }
        }
        if(ct==1){
            cout<<"BOB"<<endl;
            continue;
        }
        for(int i=1 ; i<=ct ; i++){
            int x = 2*i+1;
            int y = 4*i-2;
            int z = 4*i;

            if(ct%y==0){
                cout<<"BOB"<<endl;
                break;
            }
            else if(ct%x==0){
                cout<<"ALICE"<<endl;
                break;
            }
            else if(ct%z==0){
                cout<<"DRAW"<<endl;
                break;
            }
        }

    }
    return 0;
}