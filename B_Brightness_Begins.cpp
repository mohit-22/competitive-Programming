    #include <bits/stdc++.h>
    using namespace std;

    #define int long long

    int solve(int n){
        int low = 1, high = 2*n;   
        int ans = 0;

        while(low <= high){
            int mid = (low + high) / 2;

            // int val = mid - (int)sqrt(mid);
            
            // compute integer floor(sqrt(mid)) robustly
            long double sd = sqrtl((long double)mid);
            long long r = (long long)sd;

            // // adjust r to be exact floor(sqrt(mid))
            // while((__int128)(r+1)*(r+1) <= mid) r++;
            // while((__int128)r*r > mid) r--;

            int val = mid - r;  // number of non-perfect squares <= mid

            if(val >= n){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
    int32_t main(){
        int t;
        cin >> t;
        while(t--){
            int n;
            cin >> n;
            int y =  solve(n);
            cout<<y<<endl;
        }
        
        return 0;
    }