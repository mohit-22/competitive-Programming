#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int n,d;
        cin >> n>>d;
        int arr[n];
        bool flag = false;
        for(int i=0 ; i<n  ;i++){
            cin>>arr[i];
            if(arr[i]==0){
                flag=true;
            }
        }
        int x=  d*60;
        int y = d*60;
        int mn1=0;
        sort(arr,arr+n,greater<int>());
        for(int i=0 ; i<n ; i++){
            if(arr[i]==1 && x>=30){
                mn1++;
                x-=30;
            }
        }
        if(!flag){
            cout<<mn1<<endl;
            continue;
        }

        int mn2=1;
        y-=120;
        if(y<0){
            cout<<mn1<<endl;
            continue;
        }
        for(int i=0 ; i<n ; ){
            while(arr[i]==1 && y>=15){
                mn2++;
                y-=15;
                i++;
            }
            i++;
        }

        int b=-1;
        for(int i=0 ; i<n  ;i++){
            if(arr[i]==0){
                b=i;
                break;
            }
        }
        b++;
        while(b<n && y>=120 && arr[b]==0){
            mn2++;
            y-=120;
            b++;
        }
        cout<<max(mn1,mn2)<<endl;

        
    }
    return 0;
}