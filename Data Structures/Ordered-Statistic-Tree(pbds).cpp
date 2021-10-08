#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define bolt                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
#define endl "\n"

#define int long long
const int N = 2e5 + 5;

#define T pair<int, int>
typedef tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> oset;
#define ll long long

// find1_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

/*1. Number of elements strictly greater than a[i]
int cnt = sz(curr) - (int)curr.order_of_key({a[i]+1,0});

2. Number of elements strictly less than a[i]
int cnt = (int)curr.order_of_key({a[i],i});

3. Use insert like this : curr.insert({a[id], id});

4. Finding the k -th smallest element in the set using * because
    find_by_order returns an iterator
    auto k-th_smallest_value =  *(o_set.find_by_order(k - 1))
    It is (k - 1) since it uses zero indexes

5. Erasing : curr.erase({a[i], i});*/

/*
Example : 
Problem : https://codeforces.com/contest/1042/problem/D
Solution :
*/

ll a[200005], n, k, prefix[200005], ans;

signed main()
{
#ifdef ONLINE_JUDGE
    bolt;
#endif
    cin >> n >> k;
    oset s;
    s.insert({0, 0});
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        prefix[i] = prefix[i - 1] + a[i];
        int now = s.order_of_key({prefix[i] - k, 1e9});
        ans += s.size() - now;
        s.insert({prefix[i], i});
    }
    cout << ans;
    return 0;
}