#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    priority_queue<long long, vector<long long>, greater<long long>> pq; // min-heap
    long long sum = 0;
    
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        pq.push(a[i]);
        if (sum < 0) {
            long long smallest = pq.top(); pq.pop();
            sum -= smallest;
        }
    }
    
    cout << (int)pq.size() << '\n';
    return 0;
}