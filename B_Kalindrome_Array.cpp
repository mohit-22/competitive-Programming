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
        for(int i=0  ;i<n ; i++){
            cin>>arr[i];
        }
        int i=0,j=n-1;
        while(i<j){
            if(arr[i]!=arr[j]){
                break;
            }
            i++;
            j--;
        }
        int k=i;
        int l=j;
        int x = arr[k];
        int y = arr[l];
        i = i+1;
        bool flag = true;
        while(i<j){
            if(arr[i]!=arr[j]){
                if(arr[i]==x){
                    i++;
                }
                else if(arr[j]==x){
                    j--;
                }
                else{
                    flag = false;
                    break;
                }
            }
            else{
                i++;
                j--;
            }
        }
        bool flag2 = true;
        l = l-1;
        while(k<l){
            if(arr[k]!=arr[l]){
                if(arr[k]==y){
                    k++;
                }
                else if(arr[l]==y){
                    l--;
                }
                else{
                    flag2 = false;
                    break;
                }
            }
            else{
                k++;
                l--;
            }
        }

        if(flag == false && flag2 == false){
            cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
        
    }
    return 0;
}