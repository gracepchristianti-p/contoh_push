#include <iostream>
#include <stack>
using namespace std;

int main() {
    string kalimat;
    stack<char> s;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);


    for (char c : kalimat) {
        s.push(c);
    }


    cout << "Hasil terbalik: ";
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    cout << endl;
    return 0;
}
