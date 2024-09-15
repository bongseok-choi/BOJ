#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>

#define MAX 26 + 1
#define INF 100000000
using namespace std;

int n, passive[MAX]; // 피연산자의 개수, 피연산자에 대응하는 값을 저장하는 변수
string str; // 후위표기식을 입력받을 string
stack<double> stk; // 스택에는 실제 값만 넣는다

void input(){
    scanf("%d", &n);
    cin >> str;
    for(int i = 0; i < n; i++){
        // A:0, B:1, C:2 ...
        scanf("%d", &passive[i]);
    }
}

double operate(char tmp, double n1, double n2){
    if(tmp == '+')  return n1 + n2;
    else if(tmp == '-') return n1 - n2;
    else if(tmp == '/') return n1 / n2;
    else if(tmp == '*') return n1 * n2;
}

void postfix(){
    for(int i = 0; i < str.length(); i++){
        // 연산자가 주어졌을 때
        if(str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*'){
            double n2 = stk.top();
            stk.pop();
            double n1 = stk.top();
            stk.pop();
            double result = operate(str[i], n1, n2);
            stk.push(result);
        }
        // 피연산자가 주어졌을 때
        else{
            // A:0, B:1, C:2 ...
            stk.push(passive[str[i] - 'A']);
        }
    }
}

int main(void) {

    input();
    postfix();
    printf("%.2f", stk.top());


    return 0;
}
