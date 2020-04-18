#include "Vector.h"

namespace Vector
{
    vector::vector() {
        sz = 0;
        space = 0;
        arr = nullptr;
    }
    //vector::vector(int n) :sz(n), space(n), arr(&arr[n]) {}
    vector::vector(int n) {
        sz = n;
        space = n;
        arr = new int[n];
        for(int i = 0; i < n; i++) {
            arr[i] = 0;
        }
    }
    //Return the value of the array element at the given index
    int vector::get(int i) const{
        return arr[i];
    }
    //Set the value of the array at the given index
    void vector::set(int i, int x) {
        arr[i] = x;
    }
    //Return the number of elements
    int vector::size(){
        return sz;
    }
    //Return the space allocated for the array
    int vector::capacity(){
        return space;
    }
    /*Push an element to the end of the array:
    if sz == 0, reserve 1
    else if sz == space, reserve 2 * space
    assign x to the end of the array.
    increment sz*/
    void vector::push_back(int x) {
        if(sz == 0) {
            reserve(1);
        }
        else if(sz == space) {
            reserve(2 * space);
        }
        arr[sz] = x;
        sz++;
    }
    /*Increase the allocated memory space for the array:
    allocate a temporary int array of size n
    copy the values of arr into temp with a loop
    deallocate arr.  This prevents a memory leak.
    assign temp to arr.
    assign n to space*/
    void vector::reserve(int n){
        int* tempArr = new int[n];
        for(int i = 0; i < space; i++) {
            tempArr[i] = arr[i];
        }
        space = n;
        delete[] arr;

        arr = tempArr;
    }



   ///Define member functions here

}
