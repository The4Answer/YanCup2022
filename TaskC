	//#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <deque>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <ctime>



using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");


int main() {
	long long n;
	long long ans = 1000000000;
	cin >> n;
	long long k = sqrt(n);
	if (k > 1 && k * (k + 1) > n)
		k--;
	for (;k > 0; k--) {
		long long k_tmp = k;
		long long n_tmp = n;
		long long caut = 0;
		while (n_tmp > 0) {
			n_tmp -= k_tmp * (k_tmp + 1);
			caut++;
			k_tmp = sqrt(n_tmp);
			if (k_tmp > 1 && k_tmp * (k_tmp + 1) > n_tmp) 
				k_tmp--;
			
		}
		ans = min(ans, caut);
	}
	cout << ans;
	return 0;
}
