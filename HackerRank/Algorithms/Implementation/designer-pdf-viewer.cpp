// https://www.hackerrank.com/challenges/designer-pdf-viewer
#include <iostream>
#include <string>
#include <array>
using namespace std;
int main()
{
	array<int, 26> h;
	for (auto& x : h)
		cin >> x;
	string word;
	cin >> word;
	auto max{ 0 };
	for (auto c : word)
		if (h[c - 'a'] > max)
			max = h[c - 'a'];
	cout << max * word.size();
}
