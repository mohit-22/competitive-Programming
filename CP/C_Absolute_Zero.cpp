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
        vector<int>v;
        auto mn = *min_element(arr, arr + n);
        auto mx = *max_element(arr, arr + n);
        int ct=40;
        bool flag = true;
        while(ct>0 && ((mn+mx)/2ll!=0)){
            if((mn+mx)%2!=0){
                // cout<<-1<<endl;
                flag=false;
                break;
            }
            int mid = (mn+mx)/2ll;
            v.push_back(mid);
            for(int i=0 ; i<n ; i++){
                arr[i] = abs(arr[i]-mid);
            }
            mn = *min_element(arr, arr + n);
            mx = *max_element(arr, arr + n);
            ct--;
        }
        if(mn!=0 || mx!=0 || flag==false){
            cout<<-1<<endl;
        }
        else{
            cout<<v.size()<<endl;
            for(auto it:v){
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}