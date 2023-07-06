#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <stack>

#define INF 100000000
using namespace std;

int n; // 연산의 개수
priority_queue<int, vector<int>, greater<int>> pq; // 최소힙

int main(void) {

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if(x == 0){
            if(pq.empty())
                printf("0\n");
            else{
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else{
            pq.push(x);
        }
    }

    return 0;
}