#include <bits/stdc++.h> 
#include <iostream>
using namespace std;
vector<int> getPrimeFactors(int n){ 
    // Declare a vector to store
    // the prime factors of n.
    vector<int> primeFactors; 
    
    // Loop from 2 up to n
    for(int i = 2; i <= n; i++){
        // Check if n is divisible by i
        if(n % i == 0){
            // If divisible, add i to
            // the primeFactors vector
            primeFactors.push_back(i);
        }
        // Continue dividing n by i
        // until it's no longer divisible
        while(n % i == 0){
            n = n / i;
        }
    }
    // Return the vector
    // containing the prime factors of n.
    return primeFactors; 
}
int main() {
    int n = 60;
    vector<int> ans = getPrimeFactors(n);
    cout << "Prime Factors for " << n << ": ";
    for(auto factor: ans){
        cout << factor << " ";
    }
    cout << endl;
}