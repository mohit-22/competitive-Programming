#include <bits/stdc++.h>
using namespace std;
#define int long long

int countGroups(const vector<pair<int,int>>& v) {
    vector<vector<int>> groups;

    for (auto &p : v) {
        int x = p.second;
        bool placed = false;

        for (auto &g : groups) {
            for (int y : g) {
                if (abs(x - y) == 1) {
                    g.push_back(x);
                    placed = true;
                    break;
                }
            }
            if (placed) break;
        }

        if (!placed) 
            groups.push_back({x});
    }

    return groups.size();
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) 
            cin >> arr[i];

        vector<pair<int,int>> v;
        v.reserve(n);
        for (int i = 0; i < n; i++)
            v.emplace_back(arr[i], i+1);

        sort(v.begin(), v.end(),
             [](auto &a, auto &b){
                 if (a.first != b.first) 
                     return a.first > b.first;
                 return a.second < b.second;
             });

        cout << countGroups(v) << "\n";
    }
    return 0;
}
