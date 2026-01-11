#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
const int MOD=1e9+7;
const int N=1e5+1;
using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        bool f1 = false;
        for( int i = 0; i <= 360; i++){
            double kt = i;
            double ot = ((kt-2)*(180*1.0))/kt;
            // cout << ot << " " << i << endl;
            if( ot == n ){
                f1 = true;
                break;
            }
        }
        if(f1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}