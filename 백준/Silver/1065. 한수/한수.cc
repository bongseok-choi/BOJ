#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n;
    int num[5], sub[4]; // 자리수 배열, 자리수 차이 배열
    int a, ans, indx;
    ans = 0;
    cin >> n;
    if(n < 100){
        cout << n; // 100이하일 경우 모든 수가 등차수열
        return 0;
    }
    for (int i = 100; i <= n; i++){
        a = i;
        indx = 0;
        while(a!=0){
            num[indx] = a % 10; // 각 자리수를 저장
            a /= 10;
            indx++;
        } 
        for (int j = 0; j < indx - 1; j++){
            sub[j] = num[j] - num[j + 1]; // 자리수 차를 저장
        }
        bool isit = true;
        for (int j = 0; j < indx - 2;j++){
            if(sub[j] != sub[j+1]){
                isit = false; // 자리수의 차를 비교하며 다르면 false
                break;
            }
        }
        if(isit){ // 자리수의 차가 모두 같은 경우 카운트
            ans++;
        }
    }
    cout << ans + 99; 
    //100보다 큰 경우 카운트를 했으므로 100보다 작은 한수도 더해줌
    return 0;
} // 16 min