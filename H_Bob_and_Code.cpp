#include <bits/stdc++.h>
using namespace std;
#include<stack>
#include<algorithm>
#include<cmath>

int main() {
    
    
        int n;
        cin >> n;
        vector<string> arr(n);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int ct=0;
        for (int i = 0; i < n; i++)
        {
            /* code */
            string chek=arr[i];
            reverse(chek.begin(),chek.end());
            string geck=arr[i];
            if(chek==geck){
                ct++;
                arr[i]="123!@#";
                arr[i] += to_string(i);
            }
        }
        unordered_map<string,int>mapp;
        for (int i = 0; i < n; i++)

        {
            mapp[arr[i]]++;
            string rev;
            reverse(arr[i].begin(),arr[i].end());
            rev=arr[i];
            mapp[rev]++;


            /* code */
        }


        
        for(const auto it:mapp){
            if(it.second%2==0 && it.second>0 ){
                string ch = it.first;
                reverse(ch.begin(), ch.end());
                if(mapp.find(ch)!=mapp.end()){
                    ct+=it.second/2;
                }
                
                
                }
            }   
        
        cout<<n-ct<<endl;

}