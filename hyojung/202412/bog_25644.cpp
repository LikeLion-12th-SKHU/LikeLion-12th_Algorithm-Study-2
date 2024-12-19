#include <iostream>

using namespace std;
int main(void){
   
    int n;
    int arr[200001];
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    int min = arr[0];
    int max = -987654321;
    
    for(int i = 1;i<n;i++){
        if(arr[i] < min){
            min = arr[i];
        }
        else{
            if(max < arr[i] - min){
                max = arr[i] - min;
            }
        }
    }
    if(max == -987654321){
        cout << 0;
    }
    else{
        cout << max;
    }
}