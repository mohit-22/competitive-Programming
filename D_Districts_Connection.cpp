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
        set<int>s;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            s.insert(arr[i]);
        }
        if(s.size()==1){
            cout<<"NO"<<endl;
            continue;
        }
        int x=0;
        int y=-1;
        for(int i=0 ; i<n ; i++ ){
            if(arr[i]!=arr[x]){
                y=i;
                break;
            }
        }
        cout<<"YES"<<endl;
        for(int i=1 ; i<n ; i++){
            if(arr[i]!=arr[x]){
                cout<<x+1<<" "<<i+1<<endl;
            }
            else{
                cout<<y+1<<" "<<i+1<<endl;
            }
        }


    }
    return 0;
}