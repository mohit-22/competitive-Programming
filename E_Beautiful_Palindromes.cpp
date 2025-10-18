#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n>>k;
        int arr[n];
        set<int>s;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            s.insert(arr[i]);
        }
        vector<int>v;
        for(int i=1 ; i<=n ; i++){
            if(s.find(i)==s.end()){
                v.push_back(i);
            }
        }
        if(v.size()==0){
            for(int i=0 ; i<k ; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        else{
            if(k<=v.size()){
                for(int i=0 ; i<k ; i++){
                    cout<<v[i]<<" ";
                }
                cout<<endl;
            }
            else{
                for(int i=0 ; i<v.size() ; i++){
                    cout<<v[i]<<" ";
                }
                int x = k-v.size();
                int y = arr[n-1];
                bool flag = false;
                for(auto it : s){
                    if(it!=y) {
                        cout<<it<<" ";
                        x--;
                    }else{
                        flag=true;
                    }
                    if(x<=0) break;
                }
                if(flag) cout<<y<<endl;

                // cout<<endl;
            }
        }

        
    }
    return 0;
}