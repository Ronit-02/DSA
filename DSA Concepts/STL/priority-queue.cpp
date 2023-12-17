#include <iostream>
#include <queue>
using namespace std;

class cmp{
    public:
    bool operator ()(int a, int b){
        return a < b; // max heap
    }
};

int main(){

    priority_queue<int, vector<int>, std::greater<int>> pq;
    pq.push(1);
    pq.push(4);
    pq.push(7);
    pq.push(2);

    cout << "size: " << pq.size() << endl;

    cout << "elements: ";
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;

    // using custom function

    priority_queue<int, vector<int>, cmp> pq1;
    pq1.push(1);
    pq1.push(4);
    pq1.push(3);
    while(!pq1.empty()){
        cout << pq1.top() << " ";
        pq1.pop();
    }
}