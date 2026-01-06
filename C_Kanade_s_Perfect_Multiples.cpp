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
//         vector<int>present(k+1,false);
//         for(int i=0 ; i<n ; i++){
//             cin>>arr[i];
//             present[arr[i]]=true;
//         }
//         int mx = *max_element(arr,arr+n);

//         sort(arr,arr+n);
//         set<int>s;
//         for(auto it:arr){
//             s.insert(it);
//         }
//         vector<int>b;
//         vector<bool>check(k+1,false);


//         for(int i=1 ; i<=k ; i++){
//             if(!present[i]) continue;
//             for(int j=i*2 ; j<=k ; j+=i){
//                 if(present[j]){
//                     check[j]=true;
//                 }
//             }
//         }

//         for (int i = 1; i <= k; i++) {
//             if (present[i] && !check[i]) {
//                 b.push_back(i);
//             }
//         }


//         bool flag = true;
//         for(int x : b){
//             for(int i = x ; i <= k ; i += x){
//                 if(!present[i]){
//                     flag  = false;
//                 }
//             }
//         }

//         if(!flag) cout<<-1<<endl;
//         else{
//             cout<<b.size()<<endl;
//             for(auto x:b){
//                 cout<<x<<" ";
//             }
//             cout<<endl;
//         }
        
        
//     }
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> arr(n);
        unordered_set<long long> st;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            st.insert(arr[i]);
        }

       
        vector<long long> v(st.begin(), st.end());
        sort(v.begin(), v.end());

        long long mx = v.back();

     c
        unordered_set<long long> covered;

        for (long long x : v) {
            for (long long mult = 2 * x; mult <= mx; mult += x) {
                if (st.count(mult)) {
                    covered.insert(mult);
                }
            }
        }

        vector<long long> B;
        for (long long x : v) {
            if (!covered.count(x)) {
                B.push_back(x);
            }
        }

        bool ok = true;
        for (long long x : B) {
            for (long long mult = x; mult <= k; mult += x) {
                if (!st.count(mult)) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }

     
        if (!ok) {
            cout << -1 << "\n";
        } else {
            cout << B.size() << "\n";
            for (long long x : B) cout << x << " ";
            cout << "\n";
        }
    }

    return 0;
}
