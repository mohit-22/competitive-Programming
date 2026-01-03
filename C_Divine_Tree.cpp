#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n>>m;
        int mx = (n*(n+1))/2;

        if(m<n || m>mx){
            cout<<-1<<endl;
            continue;
        }

        vector<int>arr(n,1);
        int rem = m-n;
        for(int i=0 ; i<n ; i++){
            int canadd = min(rem,n-arr[i]);
            arr[i]+=canadd;
            rem-=canadd;
        }
        cout<<arr[0]<<endl;
        

         vector<int> result;
        set<int> used;

    // Step 1: Add all non-1 elements from a
    for (int x : arr) {
        if (x != 1) {
            result.push_back(x);
            used.insert(x);
        }
    }

    // Step 2: Add the rest from 1 to n that aren't already in result
    for (int i = 1; i <= n; ++i) {
        if (used.find(i) == used.end()) {
            result.push_back(i);
        }
    }

    for(int i=0 ; i<result.size() ; i++){
        if(i!=result.size()-1)cout<<result[i]<<" ";
        if(i+1<result.size()) cout<<result[i+1]<<endl;
    }
        
    }
    return 0;
}