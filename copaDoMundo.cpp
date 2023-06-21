#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<char> time;
    for (int i = 0; i < 16; ++i) {
        time.push('A' + i);
    }

    for (int i = 0; i < 15; ++i) {
        int golsa, golsb;
        char p1 = time.front();
        time.pop();
        char p2 = time.front();
        time.pop();
        cin >> golsa >> golsb;

        if (golsa > golsb) {
            time.push(p1);
        } else {
            time.push(p2);
        }
    }
    cout << time.front() << endl;
}
