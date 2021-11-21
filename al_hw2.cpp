#include<iostream>
#include <fstream>      // ������ ������ϱ� ����
#include <ctime>        // ����ð� ���ϱ� ����, clock_t, clock...��
using namespace std;    // ǥ�� ���ӽ����̽��� ����ϱ� ���� 

int main()
{
    cin.tie(NULL);     // cin�� �ӵ��� ������ �ϱ� ���� �� ���� �ӵ��� ������ �ϱ� ���� 
    ios_base::sync_with_stdio(false);   // c�� stdio�� cpp�� iostream ����ȭ�� ��Ȱ��ȭ������

    int N = 0;
    int R = 0;
    int i = 0;

    ifstream is("/Users/82107/Desktop/homework2_input_file/homework2_input_file_2.txt");  // �ش� ���� �б�(���� ��ġ ����)
    if (!is) {        // ���� ó��
        cerr << "���� ���� ����" << endl;
        exit(1);
    }
    int* s= new int[30000];
    string trash;    
    int j = 0;
    while (1)
    {
        is >> s[j];       // ���Ͽ��� ���� �о� �迭�� �־��ֱ�
        if (!is.fail()) {    // ���� ���� �ֱ� ����
            j++;
            if (j == 2) {
                j++;
            }
            continue;    // ������ ������ ��� �ݺ�
            
        }
        if (is.eof()) {    // �������� �����ϸ� while�� ������
            break;
        }
        is.clear();
        is >> trash;     // ���ڰ� �ƴ� ���� trash���ٰ� �־��ֱ�
    }
    N = s[0];      // ���Ͽ��� ���� s[0]���� ��ŷ�� �ö� �� �ִ� ����� ���� N�� ������ �ֱ�
    R = s[1];      // ���Ͽ��� ���� s[1]���� ��ŷ���ھ� ���� R�� ������ �ֱ�
    s[2] = 1998916;
    for (int e = 0; e < 102; e++) {    // N, R�� ���Ӱ� ���Ե� ������ ���
        cout << s[e] << " ";
    }
    cout << endl;
    clock_t start = clock();      // ����ð��� �����ϱ� ���� 
    for (int k = 103; k < 2 * N+102; k += 2) {        // ��ŷ ���ھ�(ID, ����)���� ������ �������� ������������ ����
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
    for (int p = 102; p < 2 * N; p += 2) {     // ������������ ������ ��ŷ ���ھ���� ���
        cout << s[p] << " " << s[p + 1] << endl;
    }
    cout << endl;
    int score_rank[5001] = { 0 };   
    int score_r[5001] = { 0 };       
    for (int b = 2; b < 102; b++)     // ���Ե� ������ ����� �ű�� ����
    {
        for (int c = 103; c < 2 * N+102; c += 2) {

            if (s[b] > s[c])          // ����� ���� ����
            {
                score_rank[b]++;
            }
            if (s[b] >= s[c])         // ���� ������ �ִٸ� ����ó���ϱ� ����
            {
                score_r[b]++;
            }
        }
    }
    clock_t end = clock();
    cout << "<���Ӱ� ���Ե� �������� ��� ���>" << endl;
    for (i = 2; i < 102; i++) {      // ���Ӱ� ���Ե� ���� ���� ���
        if (N == R && s[N+101] >= s[i])    // N�� R�� ���� ���ų� ���Ե� ������ ���� ���� ��� -1 ���
        {
            cout << "-1" << endl;
        }
        else if (score_r[i] > R) {      // ��ŷ���ھ� ������ �Ѿ�� ������ ��쵵 -1 ���
            cout << "-1" << endl;
        }
        else {          // �� �ܿ��� �ش� ������ ������ ���
            cout << score_rank[i] << endl;
        }
    }
    delete[] s;
    double time = (double)((end - start) / CLOCKS_PER_SEC);  // �� ���� ����ð�
    cout << "����ð� : " << time << "s\n";    // ����ð� ���

    return 0;
}