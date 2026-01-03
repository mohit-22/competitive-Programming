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
        map<char,int>mp;
        for(int i=0 ; i<n ; i++){
            mp[s[i]]++;
        }
        while(mp.size()!=0){
            for(auto it = mp.begin(); it != mp.end(); ){
                cout<<it->first;
                it->second--;
                if(it->second==0){
                    it = mp.erase(it);
                } else {
                    ++it;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}