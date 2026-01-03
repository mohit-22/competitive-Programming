#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        int brr[n];
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        for(int i=0 ; i<n ; i++){
            cin>>brr[i];
        }
        vector<pair<int,int>>v;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n-1; j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                v.push_back({1,j+1});

                }
            }
        }

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n-1; j++){
                if(brr[j]>brr[j+1]){
                    swap(brr[j],brr[j+1]);
                     v.push_back({2,j+1});
                }
               
            }
        }
        for(int i=0 ; i<n ; i++){
            if(arr[i]>brr[i]){
                swap(arr[i],brr[i]);
                v.push_back({3,i+1});
            }
        }
        cout<<v.size()<<endl;
        for(auto it: v){
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
    return 0;
}