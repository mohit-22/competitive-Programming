#include <bits/stdc++.h>
using namespace std;

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
        string s;
        cin >> s;

         vector<int>ss;
        for(int i=0 ; i<26 ; i++){
            ss.push_back(i);
        }
        if(ss[1]==6){
            cout<<0<<endl;
            continue;
        }
        vector<int>a;
        for(int i=0 ; i<5 ; i++){
            a.push_back(i+1);
        }

         map<int,int>mp; 
        for(int i=0 ; i<5 ; i++){
             mp[a[i]]++; 
            } 
        vector<pair<int,int>>vp; 
 
        for(int i=0 ; i<5 ; i++){
             vp.push_back({i,a[i]});
        }
 
        mohit(mp,a);
        if(mp[a[0]]==-1){
            cout<<0<<endl;
            continue;
        }
        
        amit(vp,a);
        int ct = 0;
        for (char c : s) if (c == 'Y') ++ct;
        cout << (ct <= 1 ? "YES\n" : "NO\n");
    }
    return 0;
}
