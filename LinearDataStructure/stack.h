#define MAX 100
class stack{
private:
    int elements[MAX];
    int top_value;
public:
    stack();
    bool isEmpty();
    bool isFull();
    bool push(int ele);
    int pop();
    int top();


};
