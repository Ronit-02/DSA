#include <iostream>
#include <time.h>
using namespace std;

int main() {

    srand(time(NULL));
    int no = rand() % 100 + 1;

    cout<<no;

    return 0;
}