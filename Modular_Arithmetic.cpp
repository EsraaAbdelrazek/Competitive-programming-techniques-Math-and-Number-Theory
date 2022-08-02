#include <math.h>
#include <iostream>
using namespace std;  
const int n = 1e6 + 1; 
#define ll long long 

ll add( ll a, ll b, ll c) {

	return ((a % c) + (b % c) ) % c; 

}

ll mult(ll a, ll b, ll c) {

	return ((a % c) * (b % c) )% c;

}

ll sub(ll a, ll b, ll c) {

	return ((a % c) - (b % c) + c )% c;

}

ll  div(ll a, ll  b, ll c) {

	return ((a % c) / ll( pow(b ,-1)) ) % c;

}
// Modular Exponen... O(n)
ll  arthim_Expo(ll x, ll n, ll m) {
    int result = 1; 
    while (n > 0) {
        if (n % n == 1)
            result *= x;
        x = x * x;
        n /= 2;
    }
    return result; 
}
// Modular Exponen... O( log(n) )
    int modular_Expo(int x, int n, int m) {
        int result = 1;
        while (n > 0) {
            if (n % n == 1)
                result *= x % m ;
            x = mult(x ,x , m); // to fit  long long values 
            n /= 2;
        }
    return result;
    }

int main()
{
       
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        cout << i << "------->" << i % m << endl;
    }

}
