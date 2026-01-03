#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin>>s;
        vector<int>v;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='1') v.push_back(i);
        }
        if(v.size()==0){
            cout<<"YES"<<endl;
            vector<int>v1;
            for(int i=0 ;i<n ; i++){
                // cout<<n-i<<" ";
                v1.push_back(n-i);
            }
            if(v1.size()%2!=0 && v1.size()>=2){
                int y = v1.size()/2;
                swap(v1[y-1],v1[y]);
            }
            for(int i=0 ; i<v1.size() ; i++){
                cout<<v1[i]<<" ";
            }
            cout<<endl;
            continue;
        }
        bool flag = false;
        if(v[0]==1 || v[v.size()-1]==n-2){
            cout<<"NO"<<endl;
            continue;
        }
        
        for(int i=0 ; i<v.size()-1 ; i++){
            if(v[i+1]-v[i]-1==1){
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<"NO"<<endl;
            continue;
        }
        int x=1;
        cout<<"YES"<<endl;
        for(int i=0 ; i<v.size() ; ){
            vector<int>v1;
            while(x<v[i]+1){
                v1.push_back(x);
                x++;
            }
            reverse(v1.begin(),v1.end());
            if(v1.size()%2!=0 && v1.size()>=2){
                int y = v1.size()/2;
                swap(v1[y-1],v1[y]);
            }
            for(int i=0 ; i<v1.size() ; i++){
                cout<<v1[i]<<" ";
            }
            cout<<x<<" ";
            x++;
            i++;

        }
         x = v[v.size()-1]+1;
         vector<int>v1;
        while(x<n){
            v1.push_back(x+1);
                x++;
        }
        reverse(v1.begin(),v1.end());
        if(v1.size()%2!=0 && v1.size()>=2){
                int y = v1.size()/2;
                swap(v1[y-1],v1[y]);
            }
        for(auto it:v1){
            cout<<it<<" ";
        }
        cout<<endl;

    }
    return 0;
}