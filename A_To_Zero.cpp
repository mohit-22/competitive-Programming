// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k;
//         cin >> n>>k;
//         int ct=0;
//         if(n%2==0){
//             if(k%2==0){
//                 ct += n/k;
//                 if(n%k!=0)ct++;
//             }
//             else{
//                 ct += n/(k-1);
//                 if(n%(k-1)!=0)ct++;
//             }
//         }
//         else{
//             if(k%2==0){
//                 n = n-(k-1);
//                 ct++;
//                 ct += n/k;
//                 if(n%k!=0)ct++;
//             }
//             else{
//                 n=n-k;
//                 ct++;
//                 ct += n/(k-1);
//                 if(n%(k-1)!=0)ct++;

//             }
//         }
//         cout<<ct<<endl;
        
//     }
//     return 0;
// }








#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
    	cin>>n>>k;
    	vector<int>v;
    	if(((n)/2)+1<=k) v.push_back(-1);
    	else if(k==1){
    	        for(int i=n ; i>0 ; i--){
    	            v.push_back(i);
    	        }
    	    
    	    if(n%2!=0) swap(v[n/2],v[(n/2)+1]);
    	}
    	else{
    	    int x = n/k;
    	    int y=n;
    	    for(int i=1 ; i<=x ; i++){
    	        int m=n;
    	        for(int i=k ; i>0 ; i--){
    	            v.push_back(m-i+1);
    	        }
    	        n = n-k;
    	    }
    	    if(n>0) v.push_back(n);
    	    bool flag=false;
        	for(int i=0 ; i<y ; i++){
        	    if(v[i]==i+1){
        	        flag=true;
        	        break;
        	    }
        	    
        	}
        	
            if(flag==true) reverse(v.begin(),v.end());
    	        
    	}
    	
        	for(int i=0  ;i<v.size() ; i++){
        	        cout<<v[i]<<" ";
        	}
    	    cout<<endl;
	}
	

}
