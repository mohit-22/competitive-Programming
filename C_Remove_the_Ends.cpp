#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0 ; i<n ; i++){
            cin>>v[i];
        }
        vector<int>pp(n,0);
        vector<int>pn(n,0);
        int poss=0;
        int negs=0;
        for(int i=0 ; i<n ; i++){
            if(v[i]>=0){
                poss+=v[i];
            }
            else negs+=abs(v[i]);
            pp[i] = poss;
            pn[i] = negs;
        }
        int ans =max(poss,negs);
        for(int i=0 ; i<n ; i++){
            ans=max(ans,pp[i]+(pn[n-1]-pn[i]));
        }
        cout<<ans<<endl;
    }
    return 0;
}