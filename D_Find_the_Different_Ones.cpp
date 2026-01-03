// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         int arr[n];
//         for(int i=0 ; i<n ; i++){
//             cin>>arr[i];
//         }
//         vector<int>dist(n);
//         // unordered_map<int,bool> flag;
//         dist[0] = 1;
//         // flag[arr[0]] = true;
//         for(int i=1 ; i<n ; i++){
//            if(arr[i]==arr[i-1]){
//             dist[i] = dist[i-1];
//            }
//            else dist[i] = dist[i-1]+1;
//         }
//         // for(int i=0 ; i<n ; i++){
//         //     cout<<dist[i]<<" ";
//         // }
//         // cout<<endl;
        
//         int q;
//         cin>>q;
//         while(q--){
//             int x,y;
//             cin>>x>>y;
//             if(dist[x-1]==dist[y-1] ){
//                 cout<<-1<<" "<<-1<<endl;
//             }
//             else if(dist[x-1]!=dist[y-1] && arr[x-1]!=arr[y-1]){
//                 cout<<x<<" "<<y<<endl;
//             }
//             else if(dist[x-1]!=dist[y-1] && arr[x-1]==arr[y-1]){
//                 auto it = lower_bound(dist.begin()+(x-1),dist.begin()+y,dist[y-1]-1)-dist.begin();
//                 cout<<x<<" "<<it+1<<endl; 
//             }

//         }
//         cout<<endl;
//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

#define int long long

// pair<int,int> solve(int i,int j,vector<int>&v){
//     int a=-1;
//     int b=-1;
//     // vector<int>vv;
//     int x=-1;
//     for(int k=i+1 ; k<=j ; k++){
//         if(v[k] != v[k-1]) {
//             x = k;
//             break;
//         }
//     }
//     if(x!=-1){
//         a=i+1;
//         b =x+1;
//     }
//     return {a,b};    
// }

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(int i=0 ; i<n ;i++){
            cin>>v[i];
        }

        vector<int>arr(n);
        arr[0] = 1;
        for(int i=1 ; i<n ;i++){
            if(v[i]!=v[i-1]){
                arr[i] = arr[i-1]+1;
            }
            else arr[i]=arr[i-1];
        }

        int q;
        cin>>q;
        while(q--){
            int x,y;
            cin>>x>>y;
            // pair<int,int> res = solve(x-1,y-1,v);
            // cout<<res.first<<" "<<res.second<<endl;

            if(arr[x-1]!=arr[y-1]){
                auto it = lower_bound(arr.begin()+(x-1),arr.begin()+y , arr[x-1]+1)-arr.begin();
                cout<<x<<" "<<it+1<<endl;
            }
            else cout<<-1<<" "<<-1<<endl; 
        }
        cout<<endl;
        // for(int i=0 ; i<n ; i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;

    }
    return 0;
}