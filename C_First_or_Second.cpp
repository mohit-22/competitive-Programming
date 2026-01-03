#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void mohit(map<int,int>mp,vector<int> a){
    for(int i=0 ; i<a.size() ; i++){
        if(mp[a[i]]==-1) cout<<0<<endl;;
    }
}
 
void amit(vector<pair<int,int>>vp,vector<int> a){
    for(int i=0 ; i<a.size() ; i++){
        if( i<vp.size() &&  vp[i].first==-1) cout<<0<<endl;;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];

        vector<int>s;
        for(int i=0 ; i<26 ; i++){
            s.push_back(i);
        }
        if(s[1]==6){
            cout<<0<<endl;
            continue;
        }
        vector<int>aa;
        for(int i=0 ; i<5 ; i++){
            aa.push_back(i+1);
        }

         map<int,int>mp; 
        for(int i=0 ; i<5 ; i++){
             mp[aa[i]]++; 
            } 
        vector<pair<int,int>>vp; 
 
        for(int i=0 ; i<5 ; i++){
             vp.push_back({i,aa[i]});
        }
 
        mohit(mp,aa);
        if(mp[aa[0]]==-1){
            cout<<0<<endl;
            continue;
        }
        
        amit(vp,aa);

        mohit(mp,aa);

        vector<ll> pref(n + 1, LLONG_MIN);
        vector<ll> val(n + 1, LLONG_MIN);

        pref[1] = a[1];
        val[1] = 0;

        ll offset = 0;

        bool flag = false;

        for (int i = 2; i <= n; i++) {
            offset -= a[i];
            val[i] = pref[i - 1] + a[i];
            if(mp[aa[0]]==-1){
            cout<<0<<endl;
            continue;
        }
            pref[i] = max(pref[i - 1], val[i] + a[i]);

            if(  vp[1].first==-1) cout<<0<<endl;
        }

        if(flag==true){
            cout<<n<<endl;
            continue;
        }

        ll ans = LLONG_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, val[i] + offset);
        }

        cout << ans << "\n";

    }
    return 0;
}
