#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int, vector<int>, greater<int>> cookies; // min heap

    for (int i = 0; i < n; ++i) { //iterating through the values and pushing them into the heap
        int sweetness;
        cin >> sweetness; 
        cookies.push(sweetness); 
    }

    int operations = 0;

    while (cookies.size() >= 2 && cookies.top() < k) { //iterate through the loop untill the heap has 2 or more elements and the top element is less than k
        int least_sweet_1 = cookies.top();
        cookies.pop();
        int least_sweet_2 = cookies.top();
        cookies.pop();

        int combined_sweetness = least_sweet_1 + 2 * least_sweet_2;
        cookies.push(combined_sweetness);

        operations++;
    }

    if (cookies.top() < k) {
        cout << -1 << endl;
    } else {
        cout << operations << endl;
    }

    return 0;
}
