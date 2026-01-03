#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        string p,s;
        cin>>p>>s;

        vector<pair<char, int>>v;
        int count = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i-1]) {
                count++;
            } else {
                v.push_back({s[i-1],count});
                count = 1;
            }
        }
        v.push_back({s.back(),count}); 

        vector<pair<char, int>>v2;
        int count2 = 1;
        for (int i = 1; i < p.size(); i++) {
            if (p[i] == p[i-1]) {
                count2++;
            } else {
                v2.push_back({p[i-1], count2});
                count2 = 1;
            }
        }
        v2.push_back({p.back(), count2}); 

        if(v.size() != v2.size()){
            cout << "NO"<<endl;
            continue;
        }

        bool flag = true;
        for(int i=0 ; i<v.size() ; i++){

            if(v[i].first != v2[i].first){
                flag=false;
                break;
            }

            if(v2[i].second>v[i].second || v[i].second>2*v2[i].second){
                flag=false;
                break;
            }
            
        }

        if(flag==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        
        
        
    }
    return 0;
}