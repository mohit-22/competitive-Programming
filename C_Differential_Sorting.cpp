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
        bool flag = true;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            if(i!=0){
                if(arr[i-1]>arr[i]){
                    flag = false;
                }
            }
        }
        if(flag==true){
            cout<<0<<endl;
            continue;
        }
        if(arr[n-2]>arr[n-1]){
            cout<<-1<<endl;
            continue;
        }
        if(flag==false && arr[n-2]<0 && arr[n-1]<0){
            cout<<-1<<endl;
            continue;
        }
        cout<<n-2<<endl;
        for(int i=0 ; i<n-2 ; i++){
            cout<<i+1<<" "<<n-1<<" "<<n<<endl;
        }
        
    }
    return 0;
}