// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k;
//         cin >> n>>k;
//         int arr[n];
//         for(int i=0 ; i<n ; i++){
//             cin>>arr[i];
//         }
//         vector<pair<int, int>> v;
//         for (int i = 0; i < n; i++){
//             v.push_back({arr[i], i});
//         }
        
//         sort(v.begin(), v.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
//             return a.first > b.first;
//         });
//         int ans=0;
//         int idx=-1;
//         vector<int>p;
//         for(int i=0  ;i<k ; i++){
//             ans+=v[i].first;
//             p.push_back(v[i].second);
//         }
//         ans+=v[k].first;
//         for(int i=0  ;i<n ; i++){
//             if(arr[i]==v[k].first) idx=i;
//         }
//         if(idx==0 || idx==n-1) cout<<ans<<endl;
//         else{
//             sort(p.begin(),p.end());
//             int i=p[0];
//             int j=p[p.size()-1];
//             if(i==idx+1 || i+1==idx) cout<<ans<<endl;
//             else{
//                 int mx=INT_MIN;
//                 for(int x = i+1 ; x<j ; x++){
//                     mx = max(mx,arr[x]);
//                 }
//                 auto it1 = find(p.begin(), p.end(), 0);
//                 if (it1 == p.end()){
//                 mx = max(mx,arr[0]);
//                 }
//                 auto it2 = find(p.begin(), p.end(), n-1);
//                 if (it2 == p.end()){
//                 mx = max(mx,arr[n-1]);
//                 }

//                 ans-=v[k].first;
//                 ans+=mx;
//                 cout<<ans<<endl;
//             }
//         }
        
        
        
//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

#define int long long

void generateSubsequences(vector<int>& arr, int k, int idx, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == k) { // subsequence of length k formed
        result.push_back(current);
        return;
    }
    if (idx == arr.size()) return; // reached end

    // Take this element
    current.push_back(arr[idx]);
    generateSubsequences(arr, k, idx + 1, current, result);

    // Don't take this element
    current.pop_back();
    generateSubsequences(arr, k, idx + 1, current, result);
}

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        vector<int>v(n);
        for(int i=0 ; i<n  ;i++){
            cin>>v[i];
        }

        // vector<vector<int>> result;
        // vector<int> current;

        // generateSubsequences(v, k+1, 0, current, result);
        // vector<int>sum;

        // for(int i=0 ; i<result.size() ; i++){
        //     int s=0;
        //     for(int j=0 ; j<result[i].size() ; j++){
        //         s+=result[i][j];
        //     }
        //     sum.push_back(s);
        // }
        // sort(sum.begin(),sum.end(),greater<int>());
        // cout<<sum[0]<<endl;
        int sum=0;
        sort(v.begin(),v.end(),greater<int>());
        for(int i=0 ; i<=k ; i++){
            sum+=v[i];
        }
        cout<<sum<<endl;


        
    }
    return 0;
}