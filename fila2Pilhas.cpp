#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> prat;
    stack<int> dep;

    int tam{0};
    cin >> tam;

    for(int i = 0; i < tam; i++){
        int val{0};
        cin >> val;

        if(val == 1){
            int val2{0};
            cin >> val2;
            dep.push(val2);
        } else if(val == 2){
            prat.pop();
        } else if(val == 3){
            cout << prat.top() << endl;
        }
        if(prat.empty()){
            while(!dep.empty()){
                prat.push(dep.top());
                dep.pop();
            }
        }
    }
}
