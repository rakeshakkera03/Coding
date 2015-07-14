/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/


class MinStack {
public:
    stack<int> s1;
    stack<int> s2;
    void push(int x) {
        s1.push(x);
        
        if( s2.empty() )
        {
            s2.push(x);
        }
        else if( x <= s2.top() )
        {
            s2.push(x);
        }
    }

    void pop() {
        if( s1.empty() )
        {
            cout << "ERROR: stack empty.. cannot pop" << endl;
        }
        else
        {
            int x = s1.top();
            s1.pop();
            if( s2.top() == x )
            {
                s2.pop();
            }
        }
    }

    int top() {
        
        int x = s1.top();
        
        return x;
    }

    int getMin() {
        
        if( !s2.empty() )
            return s2.top();
        
        return -1;
    }
};
