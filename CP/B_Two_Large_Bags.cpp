#include <bits/stdc++.h>
using namespace std;

#define int long long

int funcn(vector<int> &v, int y) {
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i] == y) {
            return i;
        }
    }
    return -1; 
}


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
        sort(arr,arr+n);
        set<int>s;
        vector<int>v;
        bool flag = true;
        for(int i=0 ; i<n-1 ; i+=2){
            if(arr[i]==arr[i+1]){
                if(s.find(arr[i])!=s.end()){
                    s.insert(*s.rbegin()+1);
                    v.push_back((*s.rbegin()));
                }
                else{
                    s.insert(arr[i]);
                    v.push_back(arr[i]);
                }
                // i++;
            }
            else{
                if((s.find(arr[i])!=s.end()) && (s.find(arr[i+1])!=s.end())){
                    s.insert(*s.rbegin()+1);
                    v.push_back(*s.rbegin());
                }
                else if(s.find(arr[i])!=s.end()){
                    int x = funcn(v,arr[i]);
                    if (x == -1) {
                        flag = false;
                        break;
                    }
                    if(v.size()-x>=arr[i+1]-arr[i]){
                        s.insert(arr[i+1]);
                        v.push_back(arr[i+1]);
                    }
                    else{
                        flag=false;
                        break;
                    }
                    
                }
                // else if(s.find(arr[i+1])!=s.end()){
                //     s.insert(arr[i+1]);
                // }
                else{
                    flag=false;
                    break;
                }
                
            }
        }
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}