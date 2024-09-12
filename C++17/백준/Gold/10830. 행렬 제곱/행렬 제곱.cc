#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000;

// 행렬 곱셈 함수
vector<vector<int>> multiplyMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int N = A.size();
    vector<vector<int>> C(N, vector<int>(N, 0));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    
    return C;
}

// 행렬 제곱 함수 (이진 거듭제곱 사용)
vector<vector<int>> matrixPower(vector<vector<int>>& A, long long B) {
    int N = A.size();
    vector<vector<int>> result(N, vector<int>(N, 0));
    
    // 초기화: 결과 행렬을 단위 행렬로 설정
    for (int i = 0; i < N; ++i) {
        result[i][i] = 1;
    }
    
    while (B > 0) {
        if (B % 2 == 1) {
            result = multiplyMatrix(result, A);
        }
        A = multiplyMatrix(A, A);
        B /= 2;
    }
    
    return result;
}

int main() {
    int N;
    long long B;
    cin >> N >> B;
    
    vector<vector<int>> A(N, vector<int>(N));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> A[i][j];
        }
    }
    
    vector<vector<int>> result = matrixPower(A, B);
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (j > 0) cout << " ";
            cout << result[i][j];
        }
        cout << endl;
    }
    
    return 0;
}
