#include <bits/stdc++.h>
using namespace std;
/*
>> abbsa -> YES
>> xdyxddy -> YES
>> hehehi -> NO
*/

int main()
{
    string s;
    cin >> s;

    map<char,int>a;
    for( auto ch: s) a[ch - 'a']++;

    int odd_count = 0;
    for (int i = 0; i < 26; i++) odd_count += (a[i] % 2);

    if (odd_count > 1) cout << "NO\n";
    else cout << "YES\n";

    string result;
    for (int i = 0; i < 26; i++){
        if(!(a[i]%2)){
            for(int j = 0; j < a[i]/2; j++) result.push_back(i + 'a');
        }
    }
    for (int i = 0; i < 26; i++){
        if(a[i]%2){
            for(int j = 0; j < a[i]; j++) result.push_back(i + 'a');
        }
    }
    for (int i = 25; i >= 0; i--){
        if(!(a[i]%2)){
            for(int j = 0; j < a[i]/2; j++) result.push_back(i + 'a');
        }
    }
    

    cout << result << endl;

    return 0;
}