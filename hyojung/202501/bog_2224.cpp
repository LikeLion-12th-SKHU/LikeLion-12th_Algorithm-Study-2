#include <iostream>
#include <cmath>
#include <string>
#include <sstream> 
#include <vector>
#include <algorithm>
using namespace std;

int visited[62][62];

int main(void){
    int n;
    cin >> n;
    cin.ignore(); 
    vector<string> answer;
    for(int i = 0; i < 58; i++){
        for(int j = 0; j < 58; j++){
            if(i != j){
                visited[i][j] = 987654321;
            }
        }
    }

    for(int i = 0; i < n; i++){
        string s;
        getline(cin, s);
        int startIndex,endIndex = -1;

        char start = s[0];
        char end = s[s.size() - 1];

        if(start >= 'A' && start <= 'Z'){
            startIndex = start-'A' + 26;
        }

        if(start >= 'a' && start <= 'z'){
            startIndex = start-'a';
        }

        if(end >= 'A' && end <= 'Z'){
            endIndex = end-'A' + 26;
        }

        if(end >= 'a' && end <= 'z'){
            endIndex = end-'a';
        }
       visited[startIndex][endIndex] = 1;

    }

    for(int k = 0;k<58;k++){
        for(int i = 0;i<58;i++){
            for(int j = 0;j<58;j++){
                visited[i][j] = min(visited[i][j],visited[i][k] + visited[k][j]);
            }
        }
    }

    for(int i = 0;i<58;i++){
        for(int j = 0;j<58;j++){
            if(i != j && visited[i][j] != 987654321){
                string s = "";
                if(i >= 26){
                    s += ('A' + (i-26));
                }
                if(i < 26){
                    s += ('a' + i);
                }
                s += " => ";
                if(j >= 26){
                    s += ('A' + (j-26));
                }
                if(j < 26){
                    s += ('a' + j);
                }
                answer.push_back(s);
            }
        }
    }
    sort(answer.begin(),answer.end());
    cout << answer.size() << '\n';
    for(int i = 0;i<answer.size();i++){
        cout << answer[i] << '\n';
    }
}