#include <bits/stdc++.h>
using namespace std;

long getMinimumSize(vector<int> payloadSize, vector<int> cacheA, vector<int> cacheB, int minThreshold) {
    

    int n = (int)payloadSize.size();
    vector<int> both, onlyA, onlyB;

    for (int i = 0; i < n; i++) {
    int type = cacheA[i] + cacheB[i];

    if (type == 2) {
        both.push_back(payloadSize[i]);
    } else if (type == 1) {
        if (cacheA[i]) onlyA.push_back(payloadSize[i]);
        else onlyB.push_back(payloadSize[i]);
    }
}

    sort(both.begin(), both.end());
    sort(onlyA.begin(), onlyA.end());
    sort(onlyB.begin(), onlyB.end());

    auto make_prefix = [](const vector<int>& v) {
        vector<long long> pref(v.size() + 1, 0);
        int i = 0;
        while (i < (int)v.size()) {
            pref[i + 1] = pref[i] + v[i];
            i++;
        }
        return pref;
    };

    vector<long long> prefBoth = make_prefix(both);
    vector<long long> prefA = make_prefix(onlyA);
    vector<long long> prefB = make_prefix(onlyB);


    long long ans = LLONG_MAX;
    int maxBoth = (int)both.size();
    int sizeA = (int)onlyA.size();
    int sizeB = (int)onlyB.size();

    for (int k = 0; k <= maxBoth; k++) {
        int need = minThreshold - k;
        if (need < 0) need = 0;

        if (need <= sizeA && need <= sizeB) {
            long long part1 = prefBoth[k];
            long long part2 = prefA[need];
            long long part3 = prefB[need];

            long long cost = part1 + part2 + part3;
            if (cost < ans) {
                ans = cost;
            }
        }
    }

    if (ans == LLONG_MAX) {
        return -1;
    }
    return ans;

}
