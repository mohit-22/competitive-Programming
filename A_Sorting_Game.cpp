#include <bits/stdc++.h>
using namespace std;

int main() {

    int T;
    cin>>T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        string t = s;
        sort(t.begin(), t.end());
        if (s == t) {
            cout << "Bob\n";
            continue;
        }
        vector<int> pos ;
        for (int i = 0; i < n; ++i) if (s[i] != t[i]) pos.push_back(i+1);
        cout << "Alice\n";
        cout << pos.size() << "\n";
        for (int i = 0; i < (int)pos.size(); ++i) {
            if (i) cout << ' ';
            cout << pos[i];
        }
        cout << "\n";
    }
    return 0;
}