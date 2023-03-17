#include <iostream>
#include <cmath>

using namespace std;

int main(){
    float a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    float sp = (a + b + c)/2;
    float area = sqrt(sp * (sp - a) * (sp - b) * (sp - c));

    cout << "Area: " << area << endl;
    
    return 0;
}