#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    vector<int> v;
    int n,m;
    cin >> n >> m;
    
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    sort(v.begin(),v.end());
    
    int start = 0;
    int end = n - 1;
    
    int count = 0;
    while(start < end){
        if(v[start] + v[end] <= m){
            count++;
            start++;
            end--;
        }
        else{
            //end값 줄여가기
            end--;
        }
    }
    cout << count;
}