#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){

    vector<int>v;
    for(int i=1 ; i<=4 ; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    bool flag = false;
    for(int i=0; i<v.size() ; i++){
        if(v[i]!=i+1){
            cout<<i+1<<endl;
            flag = true;
            break;
        }
    }
    if(!flag) cout<<5<<endl;

    return 0;
}