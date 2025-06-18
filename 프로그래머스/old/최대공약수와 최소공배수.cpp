#include <vector>

using namespace std;

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

vector<int> solution(int n, int m) {
    const auto g = gcd(n,m);
    return {g, n*m/g};
}
