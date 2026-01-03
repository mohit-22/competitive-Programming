#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int maxSum = LLONG_MIN;
        int bestL = -1, bestR = -1;
        int currSum = 0;
        int currL = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0 && s[i] == '0') {
                currSum = 0;
                currL = i + 1;
                continue;
            }

            currSum += arr[i];
            if (currSum > maxSum) {
                maxSum = currSum;
                bestL = currL;
                bestR = i;
            }
            if (currSum < 0) {
                currSum = 0;
                currL = i + 1;
            }
        }

        if (maxSum > k) {
            cout << "No" << endl;
            continue;
        }

        int maxSum2 = LLONG_MIN;
        int currentSum2 = 0;
        int startIndex2 = 0;
        int endIndex2 = -1;
        int tempStart2 = 0;
        bool hasZero2 = false;

        for (int i = 0; i < n; i++) {
            currentSum2 += arr[i];
            if (arr[i] == 0 && s[i] == '0') hasZero2 = true;

            if (hasZero2 && currentSum2 > maxSum2) {
                maxSum2 = currentSum2;
                startIndex2 = tempStart2;
                endIndex2 = i;
            }

            if (currentSum2 < 0) {
                currentSum2 = 0;
                hasZero2 = false;
                tempStart2 = i + 1;
            }
        }

        if (maxSum == k) {
            cout << "Yes" << endl;
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
            continue;
        }
        

        if (endIndex2 == -1) {
            if (maxSum == k) {
                cout << "Yes" << endl;
                for (int i = 0; i < n; i++) cout << arr[i] << " ";
                cout << endl;
            } else {
                cout << "No" << endl;
            }
            continue;
        }

        int ct = 0;
        vector<int> v;
        int sum3 = 0;
        for (int i = startIndex2; i <= endIndex2; i++) {
            if (s[i] == '0' && arr[i] == 0) {
                ct++;
                v.push_back(i);
            }
            sum3 += arr[i];
        }

        int x = k - sum3;
        if (x > 1e6) {
            if (ct * 1e6 < x) {
                cout << "No" << endl;
                continue;
            }

            int y = (x + 1e6 - 1) / 1e6;
            int i = 0;
            while (y > 1) {
                arr[v[i]] = 1e6;
                x = x - 1e6;
                i++;
                y--;
            }
            arr[v[i]] = x;
            cout << "Yes" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            continue;
        } else {
            arr[v[0]] = x;
            cout << "Yes" << endl;
            for (int i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            continue;
        }
    }
    return 0;
}
