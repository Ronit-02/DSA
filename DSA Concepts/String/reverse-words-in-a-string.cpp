#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
    public:
        void swap(char &a, char&b){
            char temp = a;
            a = b;
            b = temp;
        }

        void reverse(string &s, int st, int e){
            while(st < e){
                swap(s[st++] , s[e--]);
            }
        }

        void reverseWords(string &s){

            int i, j;

            // Individual word reverse
            for(int a=0; s[a] != '\0'; a++){

                i = a;
                while(s[a] != ' '){
                    a++;
                    if(s[a] == '\0')
                        break;
                }
                j = a - 1;

                reverse(s, i, j);
            }

            // Full string reverse
            reverse(s, 0, s.length()-1);
        }
};


int main(){

    Solution s;

    string str = "the sky is blue";
    cout << str << endl;

    s.reverseWords(str);

    cout<< "\nNew string: " << str;
    return 0;
}