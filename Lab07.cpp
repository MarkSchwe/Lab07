//file containing the searching functions. 

#include <iostream>


using namespace std;

template <typename T>
int binSearch_iterative( const T arr[], int first, int last, const T& target){

int searchmid = last /2;
while(arr[searchmid] != target && arr[searchmid] != last){
if(target < arr[searchmid]){
    last = searchmid;
    searchmid = last/2;
}
if(target > arr[searchmid]){
    first = searchmid;
    searchmid = searchmid + searchmid/2;
}
}
if(arr[searchmid] == target){
return searchmid + 1;
//To make it more readable (0th index is 1, 1 is 2, etc.)
}
if(searchmid == last){
    return last;
}
return last;
}

template <typename T>
int binSearch_recursive( const T arr[], int first, int last, const T& target){
int mid = last / 2;
if(arr[mid] == target){
return mid + 1;
//To make it more readable (0th index is 1, 1 is 2, etc.)
}
if(mid == last){
return last;
}
if(target > arr[mid]){
return binSearch_recursive(arr, mid, last, target);
}
if(target < arr[mid]){
return binSearch_recursive(arr, first, mid, target);
}
return last;
}



int main(){
int arr[8] = {1,2,3,4,5,6,7,8};
//cout << binSearch_recursive(arr, 1, 8, 2) << endl;
cout << binSearch_iterative(arr, 1, 8, 2) << endl;



return 0;
}
