#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
// Function to find all prime
// numbers up to 'n'
vector<int> findAllPrimes(int n) {
     // Initialize with 1 (assuming all
     // numbers are prime initially)
    vector<int> prime(n + 1, 1);
    // 0 and 1 are not prime
    prime[0] = prime[1] = 0; 
    // Apply Sieve of Eratosthenes
    for (int i = 2; i <= sqrt(n); ++i) {
        if (prime[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                // Mark multiples of prime
                // numbers as not prime
                prime[j] = 0; 
            }
        }
    }
    vector<int> ans;
    // Collect prime numbers
    for (int i = 2; i <= n; ++i) {
        if (prime[i] == 1) {
            ans.push_back(i);
        }
    }
    return ans;
}
int main() {
    int n = 32;
    vector<int> primes = findAllPrimes(n);
    cout << "Prime numbers less than or equal to " << n << ":" << endl;
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}