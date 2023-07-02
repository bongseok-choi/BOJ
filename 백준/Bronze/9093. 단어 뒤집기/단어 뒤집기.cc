#include<iostream>
#include<string>
using namespace std;
 
class Stack {
public:
	char stack[1000];
	int size;
 
	Stack() { size = 0; }
 
	void Push(char data) {
		stack[size] = data;
		size += 1;
	}
 
	char Pop() {
		if (!empty())
		{
			stack[size - 1] = 0;
			size -= 1;
			return stack[size];
		}
	}
 
	bool empty() {
		if (size == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
 
	char top() {
		if (!empty())
		{
			return stack[size - 1];
		}
	}
};
 
 
int main() {
	int T; // 테스트 케이스 개수 
	cin >> T;
 
	cin.ignore(); // getline을 쓰기 위해
 
	Stack s; // 객체 생성
 
	while (T--)
	{
		string str; // 문자열 입력
		getline(cin, str); // string 클래스의 getline() 실행
 
		str += '\n';
 
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ' || str[i] == '\n') // 만약 해당 문자가 공백 또는 \n이라면
			{
				while (!s.empty())
				{
					cout << s.top();
					s.Pop();
				}
				cout << ' ';
			}
			else if (str[i] != ' ') // 만약 해당 문자가 공백이 아니라면
			{
				s.Push(str[i]);
			}
		}
 
		cout << '\n';
	}
	return 0;
}