// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,m;
//         cin >> n>>m;
//         int arr[m];
//         for(int i=0 ;i<m ; i++){
//             cin>>arr[i];
//         }
//         sort(arr,arr+m);
//         vector<int>v;
//         for(int i=0 ; i<m-1 ; i++){
//             v.push_back(arr[i+1]-arr[i]-1);
//         }
//         v.push_back(arr[0]-1+n-arr[m-1]);
//         sort(v.begin(),v.end(),greater<int>());
//         for(int i=0 ; i<v.size() ; i++){
//             v[i] = v[i]-4*i;
//         }
//         int sum = 0;
//         for(int i=0 ; i<v.size() ; i++){
//             if(v[i]>0){
//                 sum+=max(1LL,v[i]-1);
//             }
//         }
//         cout<<n-sum<<endl;
        
//     }
//     return 0;
// }












#include <iostream>
#include <algorithm>
using namespace std;

int binSrch(int a[], int l, int r, int val) {

    if (l <= r) {
        int m = (l + r) / 2;


        if (a[m] == val)
            return m;
        else if (a[m] > val)
            return binSrch(a, l, m - 1, val);
        else
            return binSrch(a, m + 1, r, val);
    }

    return -1;
}

int main() {
    int n;
    cout << "Size: ";
    cin >> n;

    int a[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);

    int x;
    cout << "Find: ";
    cin >> x;

    int idx = binSrch(a, 0, n - 1, x);

    if (idx == -1)
        cout << "Not found\n";
    else
        cout << "Found at index: " << idx << "\n";

    return 0;
}
