#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll findMinIndex(const vector<ll>& arr, ll query) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] >= query) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return result == -1 ? arr.size() + 1 : result + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k;
    cin >> n >> k;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < k; i++) {
        int query;
        cin >> query;
        cout << findMinIndex(arr, query) << "\n";
    }
    
    return 0;
}