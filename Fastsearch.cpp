#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll lowerBound(const vector<ll>& arr, ll target) {
    int left = 0, right = arr.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

ll upperBound(const vector<ll>& arr, ll target) {
    int left = 0, right = arr.size();
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    
    sort(arr.begin(), arr.end());
    
    ll k;
    cin >> k;
    
    for (int i = 0; i < k; i++) {
        ll l, r;
        cin >> l >> r;
        
        
        int leftIdx = lowerBound(arr, l);
        
        int rightIdx = upperBound(arr, r);
        
        int count = rightIdx - leftIdx;
        
        cout << count;
        if (i < k - 1){
            cout << " ";
        }
    }
    cout << "\n";
    
    return 0;
}