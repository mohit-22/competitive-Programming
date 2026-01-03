#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string str;
        cin>>str;
        int s=0,p=0;
        int y = -1;
        bool flag = true;
        for(int i=0 ; i<n  ;i++){
            if(str[i]=='s' && y!=-1){
                flag = false;
                break;
            }
            if(str[i]=='s') s++;
            else if(str[i]=='p'){
                p++;
                y=0;
            }
        }
        if(!flag ){
            cout<<"NO"<<endl;
            continue;
        }
        if(s==0){
            cout<<"YES"<<endl;
            continue;
        }
        if(p<=1){
            cout<<"YES"<<endl;
            continue;
        }
        else cout<<"NO"<<endl;

    }
    return 0;
}