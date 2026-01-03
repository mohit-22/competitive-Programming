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
        priority_queue<int> maxpq;
        priority_queue<int,vector<int>, greater<int>> minpq;
        for(int i=0 ; i<n ; i++){
            cin>>arr[i];
            minpq.push(arr[i]);
            maxpq.push(arr[i]);
        }

        int i=0,j=n-1;
        bool flag=false;
        while(i<=j){

            if(arr[i]!=minpq.top() && arr[i]!=maxpq.top() && arr[j]!=minpq.top() && arr[j]!=maxpq.top()){
                cout<<i+1<<" "<<j+1<<endl;
                flag=true;
                break;
            }

            if(arr[i]==minpq.top()){
                i++;
                minpq.pop();
            }
            else if(arr[i]==maxpq.top()){
                i++;
                maxpq.pop();
            }

            if(arr[j]==minpq.top()){
                j--;
                minpq.pop();
            }
            else if(arr[j]==maxpq.top()){
                j--;
                maxpq.pop();
            }

            
        }
        if(flag==false){
            cout<<-1<<endl;
        }

    }
    return 0;
}