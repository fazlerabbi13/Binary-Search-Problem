#include<bits/stdc++.h>
using namespace std;

#define ll long long 
// Function to check if we can make at least n copies in time T
bool canMakeCopies(ll n, ll x, ll y, ll T) {
    // We need to make the first copy, it takes min(x, y) time
    ll firstCopyTime = min(x, y);
    
    // If we don't have enough time for even one copy
    if (T < firstCopyTime) {
        return false;
    }
    
    // After making first copy, we have (T - firstCopyTime) seconds left
    ll remainingTime = T - firstCopyTime;
    
    // In remaining time, both copiers can work
    // Copier 1 can make: remainingTime / x copies
    // Copier 2 can make: remainingTime / y copies
    ll copiesFromX = remainingTime / x;
    ll copiesFromY = remainingTime / y;
    
    // Total copies = 1 (first copy) + copies from both copiers
    ll totalCopies = 1 + copiesFromX + copiesFromY;
    
    return totalCopies >= n;
}

int main() {
    ll n, x, y;
    cin >> n >> x >> y;
    
    // Binary search on time
    ll left = 0;
    ll right = (long long)n * max(x, y); // Upper bound: use only slower copier
    ll answer = right;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        
        if (canMakeCopies(n, x, y, mid)) {
            // We can make n copies in time mid, try less time
            answer = mid;
            right = mid - 1;
        } else {
            // Cannot make n copies in time mid, need more time
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}