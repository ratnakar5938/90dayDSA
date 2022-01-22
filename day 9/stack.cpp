#include <iostream>

using namespace std;

#define MAX 10

class stack
{
public:
    int items[MAX];
    int top;
    int size;
    stack();
};

typedef stack st;

stack::stack()
{
    top = -1;
    size = 0;
}

bool isFull(st *s)
{
    return s->top == MAX - 1;
}

bool isEmpty(st *s)
{
    return s->top == -1;
}

void push(st *s, int newitem)
{
    if (!isFull(s))
    {
        s->top++;
        s->items[s->top] = newitem;
        s->size++;
    }
    else
    {
        cout << "Stack is full!!!" << endl;
    }
}

void pop(st *s)
{
    if (isEmpty(s))
    {
        cout << "Stack is empty!!!" << endl;
    }
    else
    {
        cout << "Item poped : " << s->items[s->top] << endl;
        s->top--;
        s->size--;
    }
}

void printStack(st *s)
{
    for (int i = 0; i < s->size; i++)
    {
        cout << s->items[i] << " ";
    }
    cout << endl;
}

int main()
{
    st *s = new st();

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    cout << "\nAfter popping out\n";
    printStack(s);

    return 0;
}