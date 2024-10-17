#include <iostream>
#include <sstream>  // std::istringstream
#include <string>   // std::string

using namespace std;

int main() {
    string line;
    getline(cin, line); // 한 줄 입력 받기

    istringstream iss(line); // 문자열 스트림 생성
    string word;
    int word_count = 0;

    while (iss >> word) { // 공백으로 단어를 분리하며 읽기
        ++word_count;
    }

    cout << word_count << endl;

    return 0;
}
