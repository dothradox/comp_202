#include <iostream>
#include "stack.h"
using namespace std;

stack::stack(){
    top_value=-1;
}
bool stack::isEmpty(){
    return top_value<0;
}
bool stack::isFull(){
    return top_value==(MAX-1);
}
bool stack::push(int ele){
    if (!this->isFull()){
        top_value++;
        elements[top_value]=ele;
        return true;
    }
    else{
        cout<<"stack overflow"<<endl;
        return false;
    }
}
int stack::pop(){
    if (this->isEmpty()){
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    else{
        int value=elements[top_value];
        top_value--;
        return value;

    }

}

int stack::top(){
    if (this->isEmpty()){
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    else{
        return elements[top_value];
    }

}

