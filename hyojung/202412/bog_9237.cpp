#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end(),greater<int>());
    
    int max = -987654321;
    for(int i = 0;i<v.size();i++){
        int count = v[i] + i + 1;
        if(count > max){
            max = count;
        }
    }
    cout << max + 1;
    
}