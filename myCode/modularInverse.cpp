// Function to find modular inverse of a under modulo m 
// Assumption: m is prime 
void modInverse(int a, int m) 
{ 
    int g = gcd(a, m); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    { 
        // If a and m are relatively prime, then modulo inverse 
        // is a^(m-2) mode m 
        cout << "Modular multiplicative inverse is "
             << power(a, m-2, m); 
    } 
} 

// Function to find modulo inverse of a 
// Works when m and a are coprime
void modInverse(int a, int m) 
{ 
    int x, y; 
    int g = gcdExtended(a, m, &x, &y); 
    if (g != 1) 
        cout << "Inverse doesn't exist"; 
    else
    { 
        // m is added to handle negative x 
        int res = (x%m + m) % m; 
        cout << "Modular multiplicative inverse is " << res; 
    } 
} 

// A naive method to find modulor multiplicative inverse of 
// 'a' under modulo 'm' 
int modInverse(int a, int m) 
{ 
    a = a%m; 
    for (int x=1; x<m; x++) 
       if ((a*x) % m == 1) 
          return x; 
}