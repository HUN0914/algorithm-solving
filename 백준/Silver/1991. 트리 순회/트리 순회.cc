#include <iostream>

using namespace std;

pair<char, char> node[26];
//node 하나에 char 1, char 2를 담을 수 있는 것

void pre(char val)
{
	if (val == '.')
	{
		return;
	}

	cout << val;
	pre(node[val - 'A'].first);
	pre(node[val - 'A'].second);
}

void inorder(char val)
{
	if (val == '.')
	{
		return;
	}

	inorder(node[val - 'A'].first);
	cout << val;
	inorder(node[val - 'A'].second);

}

void postorder(char val)
{
	if (val == '.')
	{
		return;
	}

	postorder(node[val - 'A'].first); //가능한 왼쪽을 다 뒤짐
	postorder(node[val - 'A'].second);  // 가능한 오른쪽을 다 뒤짐
	cout << val; 
	/*
	
	만약 D의 우측 자식이 있다면 우측자식까지 간다음에 왼쪽을 다 뒤짐

	*/

}



int main(void)
{

	int t;
	char root, left, right;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> root >> left >> right;

		node[root - 'A'].first = left;
		node[root - 'A'].second = right;



	}
	pre('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');


	return 0;
}