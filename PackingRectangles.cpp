#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll w, h, n;
    cin >> w >> h >> n;
    
    // Binary search on the answer
    ll left = 1, right = 1e18;
    ll answer = right;
    
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        
        // Calculate how many rectangles can fit in a square of side 'mid'
        ll horizontal = mid / w;  // rectangles that fit horizontally
        ll vertical = mid / h;    // rectangles that fit vertically
        
        // Check if we can fit at least n rectangles
        // Be careful with overflow: if horizontal or vertical is large enough,
        // their product might exceed n
        bool canFit = false;
        if (horizontal >= n || vertical >= n) {
            canFit = true;
        } else if (horizontal > 0 && vertical > 0) {
            // Check multiplication with overflow prevention
            if (horizontal <= n / vertical || horizontal * vertical >= n) {
                canFit = (horizontal * vertical >= n);
            }
        }
        
        if (canFit) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}