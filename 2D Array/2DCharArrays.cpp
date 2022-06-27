#include <iostream>
using namespace std;

int main() {

    char numbers[][10] = {
        "one",
        "two",
        "three"
    };

    //printing entire row
    for(int i=0; i<3; i++){
        cout<< numbers[i] <<endl;       //contains address for entire row
    }

    //printing elements of one row
    for(int i=0; i<10; i++){
        cout<< numbers[0][i] <<", ";
    }

	return 0;
}

