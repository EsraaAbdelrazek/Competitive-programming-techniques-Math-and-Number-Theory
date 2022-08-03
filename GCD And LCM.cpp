using namespace std; 
#include <iostream>
#define ll long long 
 // gcd 
ll gcd(ll a, ll b) {

	while (b != 0) {
		ll a2 = a; 
		a = b; 
		b = a2 % b; 
	}
	return  a ; 
} 
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;  // == (a*b)/gcd(a,b)  --> to fit long long  
 }
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	ll a, b; 
	cin >> a >> b; 

	cout << gcd(a, b ) << endl; 
	 cout << lcm(a , b) << endl ;
	
}

