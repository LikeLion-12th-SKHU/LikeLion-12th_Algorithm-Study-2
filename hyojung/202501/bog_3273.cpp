#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    vector<int> v;
    int n;
    cin >> n;
    
    for(int i = 0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    int target;
    cin >> target;
    sort(v.begin(),v.end());
    
    int start = 0;
    int end = n-1;
    int count = 0;
   
    while(start < end){
        int sum = v[start] + v[end];
        if(sum == target){
            count++;
            end--;
        }
        else if(sum < target){
            start++;
        }
        else{
            end--;
        }
    }
    cout << count;
}