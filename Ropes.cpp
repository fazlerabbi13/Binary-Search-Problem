#include<bits/stdc++.h>
using namespace std;

// Function to check if we can get at least k pieces of length 'len'
bool canCut(vector<int>& ropes, int k, double len) {
    long long totalPieces = 0;
    
    for (int i = 0; i < ropes.size(); i++) {
        // Calculate how many pieces of length 'len' we can get from this rope
        totalPieces += (long long)(ropes[i] / len);
        
        // Early exit if we already have enough pieces
        if (totalPieces >= k) {
            return true;
        }
    }
    
    return totalPieces >= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> ropes(n);
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }
    
    // Binary search on the answer
    double left = 0.0;
    double right = 1e7; // Maximum possible length
    double epsilon = 1e-7; // Precision
    
    // Binary search for 100 iterations (enough for required precision)
    for (int iter = 0; iter < 100; iter++) {
        double mid = (left + right) / 2.0;
        
        if (canCut(ropes, k, mid)) {
            // We can cut k pieces of length mid, try larger
            left = mid;
        } else {
            // Cannot cut k pieces of length mid, try smaller
            right = mid;
        }
    }
    
    // Output with required precision
    cout << fixed << setprecision(10) << left << endl;
    
    return 0;
}