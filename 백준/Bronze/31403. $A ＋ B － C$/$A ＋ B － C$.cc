#include<bits/stdc++.h>

using namespace std;

int main(void)
{
	string a;
	string b;
	string c;
	string d;

	int aa;
	int bb;
	int cc;
	int dd;


	cin >> a >> b >> c;

	d = a + b;


	aa = stoi(a);
	bb = stoi(b);
	cc = stoi(c);
	dd = stoi(d);

	cout<< aa + bb - cc<<"\n";
	cout << dd - cc;
	



	return 0;
}