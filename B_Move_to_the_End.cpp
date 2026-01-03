// // #include <bits/stdc++.h>
// // using namespace std;

// // #define int long long

// // int32_t main(){
// //     int t;
// //     cin >> t;
// //     while(t--){
// //         int n;
// //         cin >> n;
// //         int arr[n];
// //         for(int i = 0 ;i<n ; i++){
// //             cin>>arr[i];
// //         }

// //         vector<int> ans(n, -1);
// //         int max_left = -1;

// //         for(int i = 0; i < n; i++){
// //             if(max_left > arr[i]){
// //                 ans[i] = max_left;
// //             }
// //             max_left = max(max_left, arr[i]);
// //         }
        

// //         vector<int> suffixSum(n);

// //         suffixSum[n-1] = arr[n-1]; 

        
// //         for (int i = n-2; i >= 0; --i) {
// //             suffixSum[i] = arr[i] + suffixSum[i+1];
// //         }


   
// //         for(int i=n-1 ; i>=0 ; i--){
// //             if(ans[i]>arr[i]){
// //                 suffixSum[i] = suffixSum[i]-arr[i]+ans[i];
// //             }
// //         }

// //         reverse(suffixSum.begin(),suffixSum.end());
// //         for(int i=0 ; i<suffixSum.size() ; i++){
// //             cout<<suffixSum[i]<<" ";
// //         }
// //         cout<<endl;

// //     }
// //     return 0;
// // }








// #include <bits/stdc++.h>
// using namespace std;
// #define int long long

// int countGroups(const vector<pair<int,int>>& v) {
//     vector<vector<int>> groups;

//     for (auto &p : v) {
//         int x = p.second;
//         bool placed = false;

//         // try to find a group where x is adjacent to ANY member
//         for (auto &g : groups) {
//             for (int y : g) {
//                 if (abs(x - y) == 1) {
//                     g.push_back(x);
//                     placed = true;
//                     break;
//                 }
//             }
//             if (placed) break;
//         }

//         // if no existing group could take x, start a new one
//         if (!placed) {
//             groups.push_back({x});
//         }
//     }

//     return groups.size();
// }

// int32_t main() {
//     // your input order:
//     vector<pair<int,int>> v = {
//         {10,6}, {10,8}, {10,9},
//          {9,3},
//          {7,2}, {7,4}, {7,10},
//          {2,7},
//          {1,1}, {1,5}
//     };

//     cout << countGroups(v) << "\n";  // prints 3
//     return 0;
// }




#include <bits/stdc++.h>
using namespace std;
#define int long long

int countGroups(const vector<pair<int,int>>& v) {
    // each group is just a vector<int> of the second‐values
    vector<vector<int>> groups;

    for (auto &p : v) {
        int x = p.second;
        bool placed = false;

        // try to find the first group where x is adjacent to ANY member
        for (auto &g : groups) {
            for (int y : g) {
                if (abs(x - y) == 1) {
                    g.push_back(x);
                    placed = true;
                    break;
                }
            }
            if (placed) 
                break;
        }

        // if we didn't fit x into any existing group, start a new one
        if (!placed) {
            groups.push_back({x});
        }
    }

    return groups.size();
}

int32_t main(){
    // your test data, in the exact order you gave
    vector<pair<int,int>> v = {
        {10,6}, {10,8}, {10,9},
         {9,3},
         {7,2}, {7,4}, {7,10},
         {2,7},
         {1,1}, {1,5}
    };

    // this will print 3
    cout << countGroups(v) << "\n";
    return 0;
}

