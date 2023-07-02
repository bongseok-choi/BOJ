#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    int n, m;
    char button[11]; // find함수를 쓰기 위해서 char로 입렵받음
    bool channels[1000002];//채널을 만들수있는지 저장
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        cin >> button[i];
    }
    string num;
    int result = 99999999;
    int result2 = 99999999;
    if(n != 100){
        for (int i = 0; i < 1000001; i++){
            channels[i] = true; 
            num = to_string(i);//채널을 string으로 바꿈 (비교를 위해서)
            for (int j = 0; j < m;j++){
                if(num.find(button[j]) != std::string::npos){
                    channels[i] = false;
                    break;
                }//find 함수를 통해 고장난 버튼이 포함된 경우 false
            }
        }
        channels[100] = true;//채널 100부터 시작하기 때문에 true
 
        //목표 채널로 부터 버튼으로 만들 수 있는 가장 가까운 채널을 찾음
        for (int i = n; i >=0 ;i--){ // n보다 작은 채널에서 탐색
            if(channels[i]){
                result = i;
                break;
            }
        }
        for (int i = n; i < n + abs(n - 100); i++){
            if(channels[i]){
                result2 = i;
                break;
            } // n보다 큰 채널에서 탐색
        }
 
        //각 채널 비교
        int first = abs(result - n) + (to_string(result).length());
        // 작은 채널까지 가는데 눌러야하는 수
        // + or - 버튼 누르는 수 + 숫자 버튼 누르는 수
 
        int second = abs(result2 - n) + (to_string(result2).length());
        // 큰 채널까지 가는데 눌러야하는 수
 
        int third = abs(100 - n);
        //채널 100번에서 그냥 + or - 리모컨을 눌러서 가는 수
 
        //비교하여 최소 값을 찾아 줌
        if(first <= second){
            if(first < third){
                cout << first;
            }else{
                cout << third;
            }
        }else if(first > second){
            if(second < third){
                cout << second;
            }else{
                cout << third;
            }
        }
    }else{
        cout << 0;
    }
    return 0;
}