//file containing the fibbonacci sequence numbers

#include <iostream>
#include <ctime>
using namespace std;
//fib = sum of first two preceeding ones

void fib(int rounds){
long long first, second, total;
first = 0;
second = 1;
total = 1;
for(int i = 0; i <= rounds; i++){
    cout << total << endl;
first = second;
second = total;
total = first + second;
}
}

long long fibRecBi(long long rounds, long long first, long long second = 1){
if(rounds == 0){
    return first + second;
}
if(rounds >= 0){
second = fibRecBi(0, first, second) + fibRecBi(rounds-1, second, second + first);
//cout << second << endl;
}
return 0;
}

long long fibRecSeq(int rounds, long long first = 0, long long second = 1, long long total = 1){
//cout << total << endl;
if(rounds >= 0){
return fibRecSeq(rounds-1, second, total, second + total);
}
return 0;
}

int main(){
double start = double(clock()) / CLOCKS_PER_SEC;
fib(50);
// 8.375 seconds for 100000000 runs of 50, .015625 seconds for 10 millionth fibonacci number.
fibRecBi(50, 0);
// .01625 seconds for 100000 runs.
fibRecSeq(50, 0, 1, 1);
//161.969 seconds for 10000000 runs.

cout << endl;

double finish = double(clock()) / CLOCKS_PER_SEC;

double elapsed = finish - start;
cout << elapsed << endl;
return 0;
}
