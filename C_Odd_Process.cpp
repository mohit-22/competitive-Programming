#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        int n,b;
        cin>>n;
        vector<int> o,e;
        for(int i=0;i<n;i++){
            cin>>b;
            if(b&1) o.push_back(b);
            else e.push_back(b);
        }
        sort(o.begin(),o.end());
        sort(e.begin(),e.end());
        if(o.size()==0){
            for(int i=1;i<=n;i++) cout<<0<<" ";
            cout<<endl;
        }
        else if(e.size()==0){
            for(int i=1;i<=n;i++) cout<<(i&1?o.back():0)<<" ";
            cout<<endl;
        }
        else{
            int ans=o.back(),x=1;
            cout<<ans<<" ";
            for(int i=e.size()-1;i>=0;i--){
                x++;
                ans+=e[i];
                cout<<ans<<" ";
            }
            bool ok=1;
            if(x<n){
                for(++x;x<n;x++){
                    if(ok) ans-=e[0];
                    else ans+=e[0];
                    ok=!ok;
                    cout<<ans<<" ";
                }
                if(o.size()&1) cout<<ans+e[0]<<" ";
                else cout<<0<<" ";
            }

            cout<<endl;
        }
    }
    return 0;
}