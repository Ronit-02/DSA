## Ascii Table
Some common Ascii values
- A: 65
- a: 96
- 0: 48

<img src="https://www.w3resource.com/w3r_images/cpp-for-loop-image-exercise-61.png" width="500">


## Precedence order
<img src="https://2.bp.blogspot.com/-hHb0hoWI7P0/T6a91TOVTVI/AAAAAAAAAOU/JfcNJJXDgY0/s640/precedence.png" width="300">


## Oveflow
- -10^9 < `int` < 10^9 
- -10^12 < `long int` < 10^12 
- -10^18 < `long long int` < 10^18 


## Precision
- The precision of a floating-point number defines how many significant digits it can represent without information loss
- we dont use float and double much becoz of less precision
- floor(1.55) = 1, closest int which is less
- ceil(1.55) = 2, closest int which is more
- trunc(1.33) = 1, removes decimal
- round(1.33) = 1, round(1.55) = 2
- setprecision(1) << 3.144 = 3.1


## Global & local array
- Local array (order of 5)
- as local variable are stored in stack(memory limit)
```cpp
void main(){ 
    int n = 5e5;
    int arr[n];
}
```
- Global array (order of 7)
- they are stored in data segment
```cpp
const int n = 2e7;
int arr[n];
void main(){ }
```


## Modular Arithmetic
- M = 1e9 + 7 (very close to integer)
- (a + b) % M = ((a % M) + (b % M)) % M
- (a * b) % M = ((a % M) * (b % M)) % M
- (a - b) % M = ((a % M) - (b % M) + M) % M
- (a / b) % M = ((a % M) * (b^-1 % M)) % M