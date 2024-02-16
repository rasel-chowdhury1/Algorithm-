/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long e, m, b, result = 0;

    cin >> e >> m >> b;

    long long minn = min({e, m, b});
    result += minn;
    e -= minn;
    m -= minn;
    b -= minn;

    minn = min(e / 2, b);
    result += minn;

    cout << result;

    return 0;
}