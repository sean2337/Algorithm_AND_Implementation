#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> s;
	int n;
	cin >> n;
	while (n--) {
		int data;
		cin >> data;
		if (data == 0) 
			s.pop();
		else
			s.push(data);
	}

	int res = 0;
	while (!s.empty()) { // while 문을 활용해야 함에 유의
		res += s.top();
		s.pop();
	}
	cout << res;
}
