
#include <iostream>
#include<tuple>
using namespace std; 
 // Extended Euclidian Algorithm 
	/*
		Bezout's theorem --->  ax + by = gcd(a , b)  = gcd (b  a% b)


		## a %b = a - b *floor(a/b) 

		bx1 + (a%b) y1 = gcd(a ,b) 
		bx1 + (a - b* floor(a/b) )y1 = gcd(a b)

		bx1 + ay1 - b*floor(a/b)y1 = gcd(a,b)
		ay1 + b(x1 - floor (a/b) * y1) = gcd(a,b) 

		x --> y1 
		y --> x1 - floor(a/b)*y1 

		## base case ==>> b =0 , x =1 , y =0  

		*/
	int extendedEuclid_recursive(int a, int b, int& x, int& y) {
		if (b == 0) {
			x = 1;
			y = 0;
			return a;
		}
		int x1, y1;
		int d = extendedEuclid_recursive(b, a % b, x1, y1);
		x = y1;
		y = x1 - y1 * (a / b);
		return d;
	}

	int extendedEuclid_iterative(int a, int b, int& x_prev, int& y_prev)
	{
		x_prev = 1, y_prev = 0;
		int x = 0, y = 1;
		while (b) {
			int q = a / b;
			tie(x, x_prev) = make_tuple(x_prev - q * x, x);
			tie(y, y_prev) = make_tuple(y_prev - q * y, y);
			tie(a, b) = make_tuple(b, a % b);

		}
		return a;
	}

int main()
{
  
	return 0; 
}
