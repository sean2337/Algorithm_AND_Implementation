/*
- 0을 제외한 모든 숫자는 앞에 올 수있다.
- 이때 1~8은 뒤에 올 수 있는 숫자가 총 2종류이다. (숫자 +- 1)
- 하지만 9 뒤엔 오직 숫자 8만이 올 수 있다.

dp 테이블을 2차원 리스트이며, "dp[자리수][앞에오는숫자] = 경우의 수" 이다.

case1) 앞에 오는 숫자가 0일떄
=> dp[자리수][0] = dp[자리수 - 1][1]

case2) 앞에 오는 숫자 = 1~8 사이의 숫자일때
=> dp[자리수][앞에 오는숫자] = dp[자리수-1][앞에 오는숫자 - 1] + dp[자리수 -1][앞에 오는숫자 + 1]
dp[n][i] = dp[n-1][i-1] + dp[n-1][i+1]


case3) 앞에 오는 숫자 = 9 일떄
=> dp[자리수][9] = dp[자리수 -1][8]
=> 
*/

#include <iostream>

using namespace std;

#define MOD 1000000000

int N;
int dp[9][101];
int ans = 0;

int main()
{
    cin >> N;

    // 1, 2, 3, 4, 5, 6, 7, 8, 9는 계단 수, 0으로 끝나는 수는 없음
    for (int i = 1; i <= 9; i++)
        dp[i][1] = 1;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (j == 0)
            {
                //길이가 i이고 0으로 끝나는 계단 수는 바로 전의 수가 1로 끝나는 것만 가능
                dp[j][i] = dp[1][i - 1];
            }
            else if (j == 9)
            {
                //길이가 i이고 9로 끝나는 계단 수는 바로 전의 수가 8로 끝나는 것만 가능    
                dp[j][i] = dp[8][i - 1];
            }
            else
            {
                // 2~8로 끝나는 계단수는 (1,3), (2,4), ... (7, 9)이므로
                // j-1, j+1의 개수를 더한것 과 같음
                dp[j][i] += dp[j - 1][i - 1];
                dp[j][i] += dp[j + 1][i - 1];
            }
            dp[j][i] %= MOD;
        }
    }

    for (int i = 0; i <= 9; i++)
    {
        // 0~9까지 끝나며, 길이가 N인 수를 모두 더해서 출력
        ans += dp[i][N];
        ans %= MOD;
    }


    cout << ans << '\n';

    return 0;
}