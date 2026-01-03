#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0 ; i<n  ;i++){
            cin>>arr[i];
        }
        string s;
        cin>>s;
        int x = 0;
        while(s[x]=='R'){
            x++;
        }
        int y = n-1;
        while(s[y]=='L'){
            y--;
        }
        vector<pair<int,int>>v;
        int p = x,q=y;
        while(p<n && q>=0 && p<q){
            if(s[p]=='L' && s[q]=='R'){
                v.push_back({p,q});
                p++;
                q--;
            }
            else if(s[p]=='R' && s[q]=='L'){
                p++;
                q--;
            }
            else if(s[p]=='R') p++;
            else if(s[q]=='L') q--;
        }
        vector<int>prev(n);
        prev[0] = arr[0];
        for(int i=1 ; i<n ;i++) prev[i]=prev[i-1]+arr[i];

        int sum=0;
        int u = v.size();
        for(int i=0 ; i<v.size() ; i++){
            int x = v[i].first;
            int y = v[i].second;
            if(x!=0){
                sum+= (prev[y]-prev[x-1]);
            }
            else sum+=(prev[y]);
            // u--;
        }
        cout<<sum<<endl;
    }
    return 0;
}