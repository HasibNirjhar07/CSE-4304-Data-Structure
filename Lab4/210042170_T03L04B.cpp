// You have a class which counts the number of recent requests within a certain time frame.

// Implement the function:
// int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].

// It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.


#include <iostream>
#include <queue>

using namespace std;

int ping(int t)
{
    static queue<int> requests;

    while (!requests.empty() && requests.front() < t - 3000)
    {
        requests.pop();
    }

    requests.push(t);

    return requests.size();
}

int main()
{
    cout << ping(1) << "\n";
    cout << ping(2) << "\n";
    cout << ping(3) << "\n";
    cout << ping(4) << "\n";
    cout << ping(3001) << "\n";
    cout << ping(3002) << "\n";
    cout << ping(3003) << "\n";
    cout << ping(6003) << "\n";
    cout << ping(10003) << "\n";

    return 0;
}

// Expected output: 1 2 3 4 5 5 5 2 1