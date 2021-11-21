#include <iostream>
#include <vector>
#include <fstream>         // 파일을 입출력하기 위해
#include <ctime>           // 수행시간 구하기 위해, clock_t, clock..등
using namespace std;       // 표준 네임스페이스를 사용하기 위해 

typedef pair<int, int> pi;   // 쌍으로 값을 저장하기 위해 pair 사용
vector<pi>vec;             // 병합 정렬을 하기 위한 값들의 벡터
vector<pi>sor;             // 정렬한 값들을 넣기 위한 벡터

void merge(vector<pi>& list, int left, int mid, int right) {     // 병합하기 위한 함수
    int a, b, c, d;
    a = left;
    b = mid + 1;
    c = left;

    while (a <= mid && b <= right) {
        if (list[a].second < list[b].second) {              // 먼저 y좌표가 증가하는 순으로 정렬
            sor[c++] = list[a++];
        }
        else if (list[a].second == list[b].second) {      // y좌표가 같으면 x좌표가 증가하는 순서로 정렬
            if (list[a].first <= list[b].first) {
                sor[c++] = list[a++];
            }
            else {
                sor[c++] = list[b++];
            }
        }
        else {
            sor[c++] = list[b++];
        }
    }
    if (a > mid) {
        for (d = b; d <= right; d++) {
            sor[c++] = list[d];
        }
    }
    else {
        for (d = a; d <= mid; d++) {     // 왼쪽 부분 배열이 남은 경우 
            sor[c++] = list[d];
        }
    }
    for (d = left; d <= right; d++) {    // 오른쪽 부분 배열이 남은 경우
        list[d] = sor[d];
    }
}
void mergeSort(vector<pi>& list, int left, int right) {    // 병합 정렬을 위한 함수
    int mid;
    if (left < right) {
        mid = (left + right) / 2;            // 중간 지점 계산
        mergeSort(list, left, mid);          // 이등분한 배열 정렬하기, 전반부 정렬
        mergeSort(list, mid + 1, right);     // 후반부 정렬
        merge(list, left, mid, right);       // 병합
    }
}
int main()
{
    cin.tie(NULL);           // cin의 속도를 빠르게 하기 위해 즉 실행 속도를 빠르게 하기 위함 
    ios_base::sync_with_stdio(false);   // c의 stdio와 cpp의 iostream 동기화를 비활성화시켜줌

    ifstream is("/Users/82107/Desktop/homework2_input_file/homework2_input_file_1.txt");  // 해당 파일 읽기
    if (!is) {              // 에러 처리
        cerr << "파일 오픈 실패" << endl;
        exit(1);
    }
    int N;
    while (1) {            // 점의 개수 N의 값을 파일로부터 받아오기 위해 
        is >> N;
        cout << N << " ";
        break;
    }
    sor = vector<pi>(N);
    int i = 0;
    while (i < N) {       // 점 N개의 개수만큼 파일로부터 (x,y) 값 받아오기
        int M, P;
        is >> M >> P;
        vec.push_back(pi(M, P));
        i++;
    }
    cout << endl;
    clock_t start = clock();            // 수행시간을 측정하기 위해 
    mergeSort(vec, 0, N - 1);      // 병합 정렬 함수 이용
    for (int i = 0; i < vec.size(); i++) {        // 병합 정렬한 (x,y) 값 출력
        cout << vec[i].first << " " << vec[i].second << "\n";
    }
    clock_t end = clock();
    double time = (double)((end - start) / CLOCKS_PER_SEC);    // 초 단위 수행시간
    cout << "수행시간 : " << time << "s\n";       // 수행시간 출력
    return 0;
}