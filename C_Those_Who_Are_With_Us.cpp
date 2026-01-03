

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        int mx = INT_MIN;
        vector<int>x;
        vector<int>y;
        vector<vector<int>>v(n,vector<int>(m));
        for(int i=0; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cin>>v[i][j];
                mx = max(v[i][j],mx);
            }
        }

        for(int i=0; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(v[i][j]==mx){
                    x.push_back(i);
                    y.push_back(j);
                }
            }
        }

        unordered_map<int, int> freq;
        for (int it : x) {
            freq[it]++;
        }

        int mostFreqElement1 = x[0];
        int maxCount1 = 0;

        for (auto &p : freq) {
            if (p.second > maxCount1) {
                maxCount1 = p.second;
                mostFreqElement1 = p.first;
            }
        }

        unordered_map<int, int> freq2;
        for (int it : y) {
            freq2[it]++;
        }

        int mostFreqElement2 = y[0];
        int maxCount2 = 0;

        for (auto &p : freq2) {
            if (p.second > maxCount2) {
                maxCount2 = p.second;
                mostFreqElement2 = p.first;
            }
        }

        set<int>s;
        if(maxCount1>=maxCount2){
            for(int i=0 ; i<x.size() ; i++){
                if(x[i]!=mostFreqElement1){
                    s.insert(y[i]);
                }
            }
        }
        else{
            for(int i=0 ; i<x.size() ; i++){
                if(y[i]!=mostFreqElement2){
                    s.insert(x[i]);
                }
            }
        }

        if(s.size()<=1) cout<<mx-1<<endl;
        else cout<<mx<<endl;


        
    }
    return 0;
}