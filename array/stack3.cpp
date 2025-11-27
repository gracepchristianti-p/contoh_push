#include <iostream>
#include <stack>
using namespace std;

// Fungsi untuk mengecek apakah pasangan kurung cocok
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool isValid(string ekspresi) {
    stack<char> s;

    for (char c : ekspresi) {
       
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        }
   
        else if (c == ')' || c == '}' || c == ']') {
           
            if (s.empty()) return false;

            if (!isMatching(s.top(), c)) return false;

            s.pop(); 
        }
    }

    
    return s.empty();
}

int main() {
    string ekspresi;

    cout << "Masukkan ekspresi: ";
    getline(cin, ekspresi);

    if (isValid(ekspresi))
        cout << "Output: Valid\n";
    else
        cout << "Output: Tidak Valid\n";

    return 0;
}
