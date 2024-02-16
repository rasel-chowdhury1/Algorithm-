/*
    ** Sujan Sarkar **
    Github: https://github.com/sujansarkar69
*/

//Diploma CGPA Calculator-----------
#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    printf("############################\n\t2016 Probidhan\n############################\n");

    double f; printf("\t1st Sem: "); cin >> f;

    double s; printf("\t2nd Sem: "); cin >> s;

    double t; printf("\t3rd Sem: "); cin >> t;

    double fo; printf("\t4th Sem: "); cin >> fo;

    double fi; printf("\t5th Sem: "); cin >> fi;

    double si; printf("\t6th Sem: "); cin >> si;

    double se; printf("\t7th Sem: "); cin >> se;

    double e; printf("\t8th Sem: "); cin >> e;

    double ans;
    double a1, a2, a3, a4, a5, a6, a7, a8;

    if (f <= 4.00 && f >= 2.00) a1= f * 0.2;

    if (s <= 4.00 && s >= 2.00) a2= s * 0.2;

    if (t <= 4.00 && t >= 2.00) a3= t * 0.2;

    if (fo <= 4.00 && fo >= 2.00) a4= fo * 0.4;

    if (fi <= 4.00 && fi >= 2.00) a5= fi * 0.6;

    if (si <= 4.00 && si >= 2.00) a6= si * 0.8;
    
    if (se <= 4.00 && se >= 2.00) a7= se * 1;

    if (e <= 4.00 && e >= 2.00) a8= e * 0.6;

    ans = a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8;
    printf("\n############################\n");
    printf("    Your Final CGPA: %.2lf\n",ans/4);
    printf("############################\n");
    

    return 0;
}