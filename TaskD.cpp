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

int n, l;


int calc(string a, string b) {
	int sum = 0;
	for (int i = 0; i < l; ++i) {
		if (a[i] == 'A' && b[i] == 'G')
			sum += 2;
		else if (a[i] == 'C' && b[i] == 'T')
			sum += 2;
		else if (a[i] == 'G' && b[i] == 'A')
			sum += 2;
		else if (a[i] == 'T' && b[i] == 'C')
			sum += 2;
		else if (a[i] == b[i])
			sum += 0;
		else
			sum++;
	}
	return sum;
}

int main() {
	cin >> n >> l;
	vector< string> need(n); // need
	string t;
	for (int i = 0; i < n; ++i)
		cin >> need[i];

	vector <string> have;
	string s = "";
	for (int i = 0; i < l; ++i) {
		s += "A";
	}
	have.push_back(s);
	int otvet = 0;
	map<string, int> M;
	M[have[0]]++;
	for (int i = 0; i < n; ++i) {
		string temp = "";
		int ans = 1000000000;
		for (int j = 0; j < have.size(); ++j) {
			for (int k = 0; k < need.size(); ++k) {
				int tmp = calc(have[j], need[k]);
				if (M[need[k]] > 0)
					continue;
				if (ans > tmp) {
					ans = tmp;
					temp = need[k];
				}
			}
		}
		have.push_back(temp);
		M[temp]++;
		otvet += ans;
	}
	cout << otvet;
	return 0;
}
