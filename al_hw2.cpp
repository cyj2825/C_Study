#include<iostream>
#include <fstream>      // 파일을 입출력하기 위해
#include <ctime>        // 수행시간 구하기 위해, clock_t, clock...등
using namespace std;    // 표준 네임스페이스를 사용하기 위해 

int main()
{
    cin.tie(NULL);     // cin의 속도를 빠르게 하기 위해 즉 실행 속도를 빠르게 하기 위함 
    ios_base::sync_with_stdio(false);   // c의 stdio와 cpp의 iostream 동기화를 비활성화시켜줌

    int N = 0;
    int R = 0;
    int i = 0;

    ifstream is("/Users/82107/Desktop/homework2_input_file/homework2_input_file_2.txt");  // 해당 파일 읽기(파일 위치 포함)
    if (!is) {        // 에러 처리
        cerr << "파일 오픈 실패" << endl;
        exit(1);
    }
    int* s= new int[30000];
    string trash;    
    int j = 0;
    while (1)
    {
        is >> s[j];       // 파일에서 값을 읽어 배열에 넣어주기
        if (!is.fail()) {    // 숫자 값만 넣기 위함
            j++;
            if (j == 2) {
                j++;
            }
            continue;    // 마지막 전까지 계속 반복
            
        }
        if (is.eof()) {    // 마지막에 도달하면 while문 나가기
            break;
        }
        is.clear();
        is >> trash;     // 숫자가 아닌 값을 trash에다가 넣어주기
    }
    N = s[0];      // 파일에서 읽은 s[0]값을 랭킹에 올라갈 수 있는 등수의 개수 N의 값으로 넣기
    R = s[1];      // 파일에서 읽은 s[1]값을 랭킹스코어 개수 R의 값으로 넣기
    s[2] = 1998916;
    for (int e = 0; e < 102; e++) {    // N, R과 새롭게 삽입된 점수들 출력
        cout << s[e] << " ";
    }
    cout << endl;
    clock_t start = clock();      // 수행시간을 측정하기 위해 
    for (int k = 103; k < 2 * N+102; k += 2) {        // 랭킹 스코어(ID, 점수)쌍을 점수를 기준으로 내림차순으로 정렬
        for (int l = 103; l < (2 * N+102) - k; l += 2) {
            if (s[l] > s[l + 2]) {
                int temp1, temp2;

                temp1 = s[l];
                s[l] = s[l + 2];
                s[l + 2] = temp1;

                temp2 = s[l - 1];
                s[l - 1] = s[l + 1];
                s[l + 1] = temp2;

            }
        }
    }
    for (int p = 102; p < 2 * N; p += 2) {     // 내림차순으로 정렬한 랭킹 스코어값들을 출력
        cout << s[p] << " " << s[p + 1] << endl;
    }
    cout << endl;
    int score_rank[5001] = { 0 };   
    int score_r[5001] = { 0 };       
    for (int b = 2; b < 102; b++)     // 삽입된 점수의 등수를 매기기 위해
    {
        for (int c = 103; c < 2 * N+102; c += 2) {

            if (s[b] > s[c])          // 등수를 세기 위해
            {
                score_rank[b]++;
            }
            if (s[b] >= s[c])         // 같은 점수가 있다면 동등처리하기 위해
            {
                score_r[b]++;
            }
        }
    }
    clock_t end = clock();
    cout << "<새롭게 삽입된 점수들의 등수 출력>" << endl;
    for (i = 2; i < 102; i++) {      // 새롭게 삽입된 점수 순위 출력
        if (N == R && s[N+101] >= s[i])    // N과 R의 값이 같거나 삽입된 점수가 순위 밖일 경우 -1 출력
        {
            cout << "-1" << endl;
        }
        else if (score_r[i] > R) {      // 랭킹스코어 개수를 넘어가는 순위일 경우도 -1 출력
            cout << "-1" << endl;
        }
        else {          // 그 외에는 해당 점수의 순위를 출력
            cout << score_rank[i] << endl;
        }
    }
    delete[] s;
    double time = (double)((end - start) / CLOCKS_PER_SEC);  // 초 단위 수행시간
    cout << "수행시간 : " << time << "s\n";    // 수행시간 출력

    return 0;
}