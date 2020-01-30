#include<stdio.h>
#include<stdlib.h>

#define MOD 998244353L

typedef long long ll;

int abs(int x)
{
    return x<0?-x:x;    
}

ll fact(ll n)
{
    ll ans = 1;
    for(int i=1;i<=n;i++)
    {
        ans = (ans*i)%MOD;
    }
    return ans;
}
  
// Explanation
// extended euclide's algorithm finds numbers such that
// ax + by = gcd(a, b)
// I am off the assumption that a, b are coprime.
// so ax + by = 1 -> ax = 1 (mod b)
// So x is the mod inverse

// Took this function from Geeks for Geeks
ll gcdExtended(ll a, ll b, ll *x, ll *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    ll x1, y1; // To store results of recursive call 
    ll gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 

ll modularInverse(ll a, ll m) 
{ 
    ll x, y; 
    ll g = gcdExtended(a, m, &x, &y); 

    ll res = (x%m + m) % m;  
    return res;
} 

int main()
{
    ll base = MOD;

    int x1, y1, z1;
    scanf("%d %d %d", &x1, &y1, &z1);

    int x2, y2, z2;
    scanf("%d %d %d", &x2, &y2, &z2);

    int a = abs(x1 - x2);
    int b = abs(y1 - y2);
    int c = abs(z1 - z2);
    int n = a + b + c;

    ll a_fact = fact(a);
    ll a_inv  = modularInverse(a_fact, MOD);

    ll b_fact = fact(b);
    ll b_inv  = modularInverse(b_fact, MOD);

    ll c_fact = fact(c);
    ll c_inv  = modularInverse(c_fact, MOD);

    ll n_fact = fact(n);


    ll ans = (((((n_fact * a_inv)%MOD)*b_inv)%MOD)*c_inv)%MOD;

    printf("%ld\n", ans);
    return 0;
}
