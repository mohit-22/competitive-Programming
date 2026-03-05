#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; if(!(cin>>t)) return 0;
    while(t--){
        string s; cin>>s;
        int n = s.size();
        bool bad = false;
        for(int i=0;i+1<n;i++){
            if(s[i] != '<' && s[i+1] != '>'){
                bad = true; break;
            }
        }
        if(bad) cout << -1 << '\n';
        else {
            int cntL = 0, cntR = 0;
            for(char c: s){
                if(c=='<') cntL++;
                if(c=='>') cntR++;
            }
            cout << (n - min(cntL, cntR)) << '\n';
        }
    }
    return 0;
}