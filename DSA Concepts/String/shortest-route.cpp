#include <iostream>
using namespace std;

//   N
// W   E
//   S

int main(){

    char route[1000];
    cin.getline(route, 1000);

    int x=0,y=0;        //for saving coordinates

    for(int i=0; route[i]!='\0'; i++){

        switch(route[i]){

            case 'E': x++;
                    break;
            case 'N': y++;
                    break;
            case 'W': x--;
                    break;
            case 'S': y--;
                    break;
        }
    }

    cout<<"coordinates are: " <<x <<", " <<y <<endl;
    cout<<"shortest distance: " <<x+y;

    return 0;
}