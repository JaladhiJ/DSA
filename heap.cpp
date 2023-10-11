#include <iostream>

/*
In this exercise, we will implement heap as discussed in the class.
We need to implement the following functions.


ONLY THIS FILE MUST BE MODIFIED FOR SUBMISSION

You may edit main.cpp for writing more test cases.
But your code must continue to work with the original main.cpp


THERE IS ONLY ONE TEST CASE ONLY FOR YOUR UNDERSTANDING.

-- You may need to generate more random tests to get your tests right
-- Print will not work until you have a good printing function
*/


#include "heap.h"


int Heap::parent(int i) {
  return (int((i-1)/2)); // dummy return
}

int Heap::left(int i) {
  return (2*i+1); // dummy return
}

int Heap::right(int i) {
  return (2*i+2); //dummy
}

int Heap::max() {
  return (store[0]); //dummy
}

void Heap::swap(int i, int j) {
  int t=store[i];
  store[i]=store[j];
  store[j]=t;
  swap_count++;

}

void Heap::insert(int v) {
  int k=sz;
  store[k]=v;
  while (k>0 and store[parent(k)]<store[k])
  {
    swap(parent(k),k);
  }
  sz=sz+1;
}

void Heap::heapify(int i) {
  int x=i;

  if((left(i)<sz)&& (right(i)<sz)&&(store[left(i)]>store[right(i)])&&(store[left(i)]>store[i])){x=left(i);}
  if((left(i)<sz)&& (right(i)>=sz)&&(store[left(i)]>store[i])){x=left(i);}
  if((left(i)<sz)&& (right(i)<sz)&&(store[right(i)]>store[left(i)])&&(store[right(i)]>store[i])){x=right(i);}
  if((left(i)>=sz)&& (right(i)<sz)&&(store[right(i)]>store[i])){x=right(i);}
  if(x==i){return;}
  swap(i,x);
  heapify(x);
}


void Heap::deleteMax() {
  swap(0,sz-1);
  sz=sz-1;
  heapify(0);
}

void Heap::buildHeap() {
  for(int i=(sz-1);i>=0;i--)
  {
    heapify(i);
  }
}

void Heap::heapSort() {
  buildHeap();
  while (sz>0)
  {
    deleteMax();
  }
}


