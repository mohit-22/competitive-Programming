#include <bits/stdc++.h>
using namespace std;

#define int long long

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int size) {
        n = size + 2;
        bit.assign(n, 0);
    }

    void update(int i, int delta) {
        for (; i < n; i += i & -i)
            bit[i] += delta;
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i)
            sum += bit[i];
        return sum;
    }

    int range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int32_t main(){
    int n;
    cin >> n;
    vector<int> arr(n), nums(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());
    unordered_map<int, int> num_rank;
    for (int i = 0; i < n; i++) {
        num_rank[sorted_arr[i]] = i + 1;
    }

    vector<int> transformed(n);
    for (int i = 0; i < n; i++) {
        transformed[i] = num_rank[nums[i]];
    }

    vector<int> prev_greater(n, 0), after_smaller(n, 0);

    FenwickTree ft1(n);
    for (int i = 0; i < n; i++) {
        int rank = transformed[i];
        prev_greater[i] = ft1.range_query(rank + 1, n);
        ft1.update(rank, 1);
    }

    FenwickTree ft2(n);
    for (int i = n - 1; i >= 0; i--) {
        int rank = transformed[i];
        after_smaller[i] = ft2.range_query(1, rank - 1);
        ft2.update(rank, 1);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += prev_greater[i] + after_smaller[i];
    }

    const int MOD = 1e9 + 7;
    cout << ans % MOD << endl;

    return 0;
}
