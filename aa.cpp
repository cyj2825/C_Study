#include<iostream>
#include <fstream>
using namespace std;

int main()
{
    cin.tie(NULL);     // cin의 속도를 빠르게 하기 위해 즉 실행 속도를 빠르게 하기 위함 
    ios_base::sync_with_stdio(false);   // c의 stdio와 cpp의 iostream 동기화를 비활성화시켜줌

    int N = 0;//점수배열갯수
    int R;
    int i = 0;

    ifstream is("/Users/82107/Desktop/homework2_input_file/homework2_input_file_3.txt");
    if (!is) {
        cerr << "파일 오픈 실패" << endl;
        exit(1);
    }
    string trash;
    while (1) {
        is >> N >> R;
        cout << N << " " << R << " ";
        break;
    }

    int* s = new int[100];
    while (i < 100) {
        is >> s[i];
        cout << s[i] << " ";
        i++;
    }
    cout << endl;

    int* arr = new int[2 * N];
    int a = 0;
    while (a < 2 * N) {
        is >> arr[a];
        a++;
        is >> arr[a];
        a++;
    }
    for (int k = 1; k < 2 * N; k += 2) {
        for (int l = 1; l < 2 * N - k; l += 2) {
            if (arr[l] > arr[l + 2]) {
                int temp1, temp2;

                temp1 = arr[l];
                arr[l] = arr[l + 2];
                arr[l + 2] = temp1;

                temp2 = arr[l - 1];
                arr[l - 1] = arr[l + 1];
                arr[l + 1] = temp2;

            }
        }
    }
    for (int p = 0; p < 2 * N; p += 2) {
        cout << arr[p] << " " << arr[p + 1] << endl;
    }
    int score_rank[5001] = { 0 };
    int score_r[5001] = { 0 };
    for (int b = 0; b < 100; b++)
    {
        for (int c = 1; c < 2 * N; c += 2) {

            if (s[b] > arr[c])
            {
                score_rank[b]++;
            }
            if (s[b] >= arr[c])
            {
                score_r[b]++;
            }
        }
    }
    for (i = 0; i < 100; i++) {
        if (N == R && arr[N - 1] >= s[i])
        {
            cout << "-1" << endl;
        }
        else if (score_r[i] > R) {
            cout << "-1" << endl;
        }
        else {
            cout << score_rank[i] << endl;
        }
    }
    delete[] s;
    delete[] arr;
    return 0;
}