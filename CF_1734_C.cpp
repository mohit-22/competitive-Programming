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

        vector<bool>isRemove(n,false);
        int ans=0;
        for(int i=1 ; i<=n ; i++){
            for(int j=i ; j<=n ; j+=i){
                if(s[j-1]=='1'){
                    break;
                }
                if(isRemove[j-1]){
                    continue;
                }
                else{
                    isRemove[j-1] = true;
                    ans+=i;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}