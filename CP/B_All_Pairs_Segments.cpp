

#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, q;
        if (!(cin >> n >> q)) return 0;

        if (n < 0 || q < 0) {
            // invalid input guard
            cerr << "Invalid n or q\n";
            return 0;
        }

        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        vector<int> queries(q);
        for (int i = 0; i < q; ++i) {
            cin >> queries[i];
        }

        map<int,int> mp;
        map<int,int>mp2;
        for (int i = n - 1; i >= 0; --i) {
            // if (i >= 1 && arr[i] - arr[i-1] != 1) {
                int x = i ;
                int y = (i+1<n)?mp[arr[i+1]] - (n - i - 1 - 1):0;
                mp[arr[i]] = x + y;
                mp2[x+y]++;

            if(i>=1){
                int z = mp[arr[i]] - (n - i - 1);
                mp[arr[i] - 1] = z;
                int p = arr[i]-arr[i-1]-1;
                mp2[z]+=p;
            }

            // } else {
            //     int x = i ;
            //     int y = (i+1<n)?mp[arr[i+1]] - (n - i - 1 - 1):0;
            //     mp[arr[i]] = x + y;
            //     mp2[x+y]++;
            // }
        }

        for (auto &it : mp){
            // cout << it.first << " " << it.second << '\n';
        }
        
        for(int i=0 ; i<q ; i++){
            cout<<mp2[queries[i]]<<" ";
        }
        cout<<endl;

        


    }
    return 0;
}
