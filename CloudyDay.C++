/*
*/

//#pragma GCC optimize("O3")
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>

#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk

#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

#define eps 1e-8
#define M_PI 3.141592653589793
#define bsize 512

#define ldouble long double
using namespace std;

#define bs 1000000007

const int N = 600031;

int tests;

int n,P[N],X[N];
vector<pair<int,pair<int,int> > > events;
set<int> S;
long long m,y[N],r[N];
long long ans;

map<long long, long long> will_add;
map<long long, long long> ::iterator it;

int main(){
//    freopen("apache.in","r",stdin);
//    freopen("apache.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>P[i];
    }

    for (int i=1;i<=n;i++){
        cin>>X[i];
        events.push_back(make_pair(X[i],make_pair(0,i)));
    }

    cin>>m;
    for (int i=1;i<=m;i++){
        cin>>y[i];
    }
    for (int i=1;i<=m;i++){
        cin>>r[i];
        events.push_back(make_pair(y[i]-r[i],make_pair(-i,0)));
        events.push_back(make_pair(y[i]+r[i],make_pair(i,0)));
    }
    sort(events.begin(),events.end());
    for (int i=0;i<events.size();i++){
        if (events[i].second.first>0)// remove
        {
            int id=events[i].second.first;
            S.erase(id);
        }
        if (events[i].second.first<0){ // add
            int id=-events[i].second.first;
            S.insert(id);
        }
        if (events[i].second.first==0){ // query
            int id=events[i].second.second;
            if (S.size()==0){
                ans+=P[id];
            }
            if (S.size()==1){
                int onl=(*S.begin());
                will_add[onl]+=P[id];
            }
        }
    }

    long long max_add=0;
    for (it=will_add.begin();it!=will_add.end();it++){
        max_add=max(max_add,(*it).second);
    }
    cout<<ans+max_add<<endl;

//    cin.get(); cin.get();
    return 0;
}
