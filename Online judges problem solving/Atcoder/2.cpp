#include <iostream>
#include <vector>
using namespace std;

int N;
int i;

int main()
{
    cin >> N;
    vector<int> A(N);
    for (i = 0; i < N; i++)
    {
        cin >> A[i];
        A[i]--;
    }

    vector<bool> p(N, false);
    for (i = 0; i < N; i++)
        if (!p[i])
            p[A[i]] = true;
    
    vector<int> X;
    for (i = 0; i < N; i++)
        if (!p[i])
            X.push_back(i);

    int K = X.size();
    
    cout << K << endl;
    for (i = 0; i < K; i++)
    {
        cout << X[i] + 1;
        if (i < K - 1)
            cout << ' ';
    }
    cout << '\n';
    return 0;
}
