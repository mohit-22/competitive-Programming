#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,l,r;
        cin >> n>>l>>r;
        vector<int>v;
        bool flag=true;
        for(int i=1 ; i<=n ; i++){
            // int temp = ceil((double)l/i)*i;
            // or
            int temp = ((l+i-1)/i)*i;
            if(temp>r){
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
            v.push_back(temp);
        }
        if(flag==true){
            cout<<"YES"<<endl;
            for(auto it:v){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        

    }
    return 0;
}