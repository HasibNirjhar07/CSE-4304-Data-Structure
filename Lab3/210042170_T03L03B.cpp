#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;

        string result;
        bool removed;
        
        do {
            removed = false;
            result = "";
            
            for (int j = 0; j < input.length(); j++) {
                if (j < input.length() - 1 && input[j] == input[j + 1]) {
                    j++;  // Skip the next character
                    removed = true;
                } else {
                    result += input[j];
                }
            }
            
            input = result;
        } while (removed);

        cout << result << endl;
    }

    return 0;
}
