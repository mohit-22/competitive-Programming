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
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
        }
        unordered_map<int,int>mp;
        for(auto it: arr){
            mp[it]++;
        }
        bool flag = true;
        for(auto it:mp){
            if(it.second<2){
                flag=false;
                break;;
            }
        }
        if(flag==false){
            cout<<-1<<endl;
            continue;
        }
        vector<vector<int>> ans;
        for(int i=0 ; i<n-1 ; ){
            vector<int>v;
            int ct=0;
            while(i+1<n && arr[i]==arr[i+1]){
                v.push_back(i+1);
                i++;
                ct++;
            }
            v.push_back(i+1);
            reverse(v.begin(),v.end());
            if(ct%2==0){
                reverse(v.begin()+1,v.end());
            }
            ans.push_back(v);
            i++;
        }

        for (const auto& v : ans) {
            for (int x : v) {
                cout << x << " ";
            }
        }
        cout<<endl;
    }
    return 0;
}