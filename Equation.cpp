#include<bits/stdc++.h>
using namespace std;


// Function to calculate f(x) = x^2 + sqrt(x)
double f(double x) {
    return x * x + sqrt(x);
}

int main() {
    double c;
    cin >> c;
    
    // Binary search on x
    double left = 0.0;
    double right = 1e10; // Upper bound for x
    
    // Binary search for 100 iterations (sufficient for 10^-6 precision)
    for (int iter = 0; iter < 100; iter++) {
        double mid = (left + right) / 2.0;
        
        double value = f(mid);
        
        if (value < c) {
            // f(mid) is too small, need larger x
            left = mid;
        } else {
            // f(mid) is too large or equal, need smaller x
            right = mid;
        }
    }
    
    // Output the result with sufficient precision
    cout << fixed << setprecision(10) << left << endl;
    
    return 0;
}