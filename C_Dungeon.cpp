#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        multiset<int>s;
        for(int i=0 ; i<n ; i++){
            int x;
            cin>>x;
            s.insert(x);
        }
        vector<int>brr(m);
        vector<int>crr(m);
        vector<pair<int,int>>vp;
        vector<int>v;
        vector<int>drr;
        for(int i=0 ; i<m ; i++){
            cin>>brr[i];
        }
        for(int i=0 ; i<m ; i++){
            cin>>crr[i];
            if(crr[i]!=0) vp.push_back({brr[i],crr[i]});
            else v.push_back(brr[i]);
        }
        sort(vp.begin(), vp.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if(a.first == b.first)
                return a.second > b.second; 
            return a.first < b.first;       
        });

        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0 ; i<vp.size() ; ){
            auto it = s.begin();
            if(vp[i].first<=*it){
                ans++;
                s.insert(max(*it,vp[i].second));
                i++;

            }else drr.push_back(*it);
            s.erase(it);
            if(s.size()==0) break;
        }
        for(auto it:drr){
            s.insert(it);
        }
        for(int i=0 ; i<v.size() ; ){
            auto it = s.begin();
            if(v[i]<=*it){
                ans++;
                i++;
            }
            s.erase(it);
            if(s.size()==0) break;
        }

        cout<<ans<<endl;

        
    }
    return 0;
}