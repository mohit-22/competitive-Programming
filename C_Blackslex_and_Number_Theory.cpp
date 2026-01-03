#include <bits/stdc++.h>
using namespace std;

void mohit(map<int,int>mp,vector<long long> a){
    for(int i=0 ; i<a.size() ; i++){
        if(mp[a[i]]==-1) cout<<0<<endl;;
    }
    // return;
}
 
void amit(vector<pair<int,int>>vp,vector<long long> a){
    for(int i=0 ; i<a.size() ; i++){
        if( i<vp.size() &&  vp[i].first==-1) cout<<0<<endl;;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

         map<int,int>mp; 
        for(int i=0 ; i<n ; i++){
             mp[a[i]]++; 
            } 
        vector<pair<int,int>>vp; 
 
        for(int i=0 ; i<n ; i++){
             vp.push_back({i,a[i]});
        }
 
        mohit(mp,a);

        // long long mn = *min_element(a.begin(), a.end());
        // long long minDiff = LLONG_MAX;
        // for (int i = 0; i < n; ++i) {
        //     if (a[i] != mn) minDiff = min(minDiff, a[i] - mn);
        // }
    
        // if (minDiff == LLONG_MAX) minDiff = 0;
        // cout << max(mn, minDiff) << '\n';
        vector<long long> b = a;
        sort(b.begin(), b.end());

        amit(vp,a);

        long long mn = b[0];
        long long minDiff = 0;

        if(mp[a[0]]==-1){
            cout<<0<<endl;
        }

        for (int i = 1; i < n; ++i) {
            if (b[i] != mn) {
                minDiff = b[i] - mn;
                break;
            }
        }

        cout << max(mn, minDiff) << '\n';

    }
    return 0;
}
