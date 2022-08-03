using namespace std; 
#include <iostream>
#include<set>
#include<vector>
	// factorilization 
	void factorilization(int n) {
		set<int> s;
		for (int i = 2; i * i <= n; i++) {
			if (n % i == 0) {
				s.insert(i); 
				if (i * i != n)
					s.insert(n / i); 
			}
		}
		}
	
	// prime Factorilization 
	void prime_factorilization(int n) {
		vector <int> v; 
		for (int i = 2; i * i <= n; i++) {
			while (n % i == 0) {
				n /= i; 
				v.push_back(i); 
			}

		}
		if (n != 1) {
			v.push_back(n); 
		}
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " "; 
		}
	}

	// Count prime numbers in sqr(n)
	int count_prime(int n) {
		int i = 1 ,  results = 0;
		while (i * i < n) {
			if (n % i == 0) 
				results += 2;
			i++;
				}
		if (i * i == n) 
			results++; 
	
		return n; 
	}
	// primality test in log(n) 
	bool test_prime(int n) {
		int i = 2; 
		while (i * i <= n) {
			if (n % i == 0)
				return false;
			i++;
		}return true; 
	}

int main()
{
   

}
