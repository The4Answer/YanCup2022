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

int MAX_NUM = 9;

int cauntGoods(int number, int d) {
	int caunt = 0;
	for (int i = 0; i <= number; ++i) 
		if (i % d == 0)
			caunt++;
	return caunt;
}

int main() {
	int t;
	string s;
	cin >> t;
	int b;
	for (int z = 0; z < t; ++z) {
		cin >> s >> b;
		long long ans = 0;
		for (int i = 0; i < s.size(); ++i) {
			int num = s[i] - '0';	//число текущего столбца
			long long tmp = 0;			//число перестановок в текущем столбце
			if (i + 1 < s.size())	//проверка не последний ли это столбец
				tmp = cauntGoods(num-1, b);
			else
				tmp = cauntGoods(num, b);
			ans += tmp * (pow(cauntGoods(MAX_NUM, b), s.size() - i - 1));
			if (num % b != 0)		//проверка хорошая ли цифра для продолжения
				break;
		}
		cout << ans - 1 << "\n";
	}
	return 0;
}
