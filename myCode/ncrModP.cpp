// Returns n^(-1) mod p (used Fermat's little theorem)
ll modInverse(ll n, ll p){
    return power(n, p-2, p);
}
 
// Returns nCr % p using Fermat's little theorem.
ll nCrModP(ll n, ll r, ll p){
   // Base case
   if(r == 0)
      return 1;
    // Fill factorial array so that we can find all factorial of r, n and n - r
    ll fact[n + 1];
    fact[0] = 1;
    fl(i, 1, n + 1){
        fact[i] = (fact[i - 1] * i) % p;
    }
    return (fact[n] * modInverse(fact[r], p) % p * modInverse(fact[n - r], p) % p) % p;
}