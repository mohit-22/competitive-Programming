#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        long long pairs = 0;
        for (int i = 0; i < 26; i++)
            pairs += freq[i] / 2;

        long long len = (pairs / k) * 2;

        long long remaining = n - len * k;
        if (remaining >= k) len++;

        cout << len << "\n";
    }
    return 0;
}