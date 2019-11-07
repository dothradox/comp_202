#include <iostream>
#include "stack.h"
using namespace std;
int main()
{
    stack test;
    cout<<"Enter a number";
    int x;
    for(int i=0;i<10;i++){
        cin>>x;
        test.push(x);
    }
    cout<<"Top of the stack is "<<test.top()<<endl;
    cout<<"Pop operation: "<<test.pop();
    getch();

    return 0;
}
