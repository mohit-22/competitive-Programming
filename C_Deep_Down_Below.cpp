// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         int mx = 0;
//         int mn = INT_MAX;
//         int x = -1;
//         int y=-1;
//         int ct=0;
//         vector<int>vm;
//         int w = -1;
//         int z = 0;
//         while(z<n){
//             int s;
//             cin>>s;
//             vector<int>v(s);
//             for(int i=0 ; i<s ; i++){
//                 cin>>v[i];
//                 // if(i==0) mn = min(mn,v[i]);
//                 if(i==0){
//                     vm.push_back(v[i]);
//                 }
//                 if(v[i]>mx){
//                     mx = v[i];
//                     x = i;
//                     y=s;
//                     w = z;
//                 }
//             }
//             ct+=s;
//             z++;
//         }

//         for(int i=0 ; i<vm.size() ; i++){
//             if(i!=w) mn = min(mn,vm[i]);
//         }
//         if(mn==INT_MAX) mn = 0;
//         int p = ct-y+x;
//         int t = mn+1+p;
//         // int ans=0;
//         // if(t>mx){
//         //     cout<<mn+1<<endl;
//         // }
//         // else{
//         //     int e = mx-t+1;
//         //     cout<<t+e<<endl;
//         // }
//         cout<<mn<<" "<<mx<<endl;
//         cout<<p<<endl;



//     }
//     return 0;
// }









#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>>vp;
        // vector<vector<int>>v;
        for(int i=0 ; i<n  ;i++){
            int x ;
            cin>>x;
        int mx = INT_MIN;
            for(int j=0  ;j<x ; j++){
                int y;
                cin>>y;
                mx = max(mx,y-j+1);
            }
            vp.push_back({mx,x});
        }
        int ans=INT_MAX;
        sort(vp.begin(),vp.end());
        int low = vp[0].first;
        int high = vp[vp.size()-1].first;
        while(low<=high){
            bool flag = true;
            int mid = (high+low)/2;
            int curr=  mid;
            for(int i=0 ; i<n ; i++){
                if(curr>=vp[i].first){
                    curr += vp[i].second;
                }
                else{
                    flag = false;
                }
            }
            if(flag){
                high = mid-1;
                ans = min(ans,mid);
            }
            else low = mid+1;      
               
        }

        cout<<ans<<endl;
    }
    return 0;
}