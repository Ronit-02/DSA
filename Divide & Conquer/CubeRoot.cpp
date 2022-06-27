#include <iostream>

using namespace std;

double diff(double mid, double x){

    double diff;
    
    if(x > mid*mid*mid)
        double diff = x - mid*mid*mid;
    else
        double diff = mid*mid*mid - x;
    return diff;
}

double cubicRoot(double x){

    double start = 0;
    double end = x;
    double precision = 0.00001;

    while(start <= end){
        
        double mid = (start + end)/2;
        double error = diff(mid,x);

        if(error <= precision){
            return mid;
        }
        if((mid*mid*mid) > x){
            end = mid;
        }
        else{
            start = mid;
        }
    }
    return 0;
}

int main(){

    double n=3;
    cout<<cubicRoot(8.0);

    return 0;
}