// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// int32_t main(){
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         string s;
//         cin>>s;

//         char hi1 = s[n-1];
//         char hi2 = s[n-2];
//         char hi3 = s[0];

//         int ct=0;
//         for(int i=0 ; i<n ; i++){
//             if(s[i]=='A') ct++;
//         }

//         if(s=="AB") cout<<"Alice"<<endl;
//         else if(s=="BA") cout<<"Bob"<<endl;

//         else if(ct>=n-1) cout<<"Alice"<<endl;
//         else if(hi1=='A' && hi2=='A') cout<<"Alice"<<endl;
//         else if(hi1=='A' && hi3=='A') cout<<"Alice"<<endl;
//         else cout<<"Bob"<<endl;
        
        
//     }
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

struct hash_pair {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    const long long MOD = 998244353;
	    int n;
	    cin>>n;
	    int arr[n];
	    
	    for(int i=0 ; i<n ; i++){
	        cin>>arr[i];
	        
	    }
	    
	    int ct=0;
	    
        unordered_map<pair<int, int>, int, hash_pair> freq;
	    
	    for(int i=0 ; i<n ; i++){
	        int x = arr[i]+1;
	        int y = n-arr[i];
	        if(x > y) swap(x,y);
	        
	        if(x==y) ct++;

	        freq[{x,y}]++;
	    }
	    
	    
	 
	    
	    bool flag = true;
	    for (auto p : freq) {
            int f = p.second;
        if (f >= 3) {
            flag=false;
            break;
        }
    }
	    
	    if(ct>=2 || flag==false) cout<<0<<endl;
	    else {
	        long long ans=1;
            for(int i=0 ; i<n/2 ; i++){
                ans*=2;
            }
            
            long long m = ans%MOD;
            
            cout<<m<<endl;
	        
	    }
	}

}
