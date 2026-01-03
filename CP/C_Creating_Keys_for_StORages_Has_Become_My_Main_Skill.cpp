#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        if(n==1){
            cout<<k<<endl;
            continue;
        }

        vector<int>v;
        int x = 0;
        for(int i=0 ; i<n ; i++){
            if((k|i)==k){
                v.push_back(i);
                x=(x|i);    
            }
        } 
        int i=0;
        while(v.size()<n){
            v.push_back(v[i]);
            i++;
        }
        // sort(v.begin(),v.end());
        // int value = *max_element(v.begin(), v.end());
        // cout<<it<<endl;
        if(x!=k){
            v.pop_back();
            // auto it = find(v.begin(), v.end(), value);
            // if(it != v.end()) {
            //     v.erase(it);
            // }
            v.push_back(k);
        }
        for(int i=0 ; i<v.size() ; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        
        

        
    }
    return 0;
}