/*
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
*/

class Queue {
public:
    stack<int> s1, s2;
    
    // Push element x to the back of queue.
    void push(int x) {
        s1.push(x);    
    }

    // Removes the element from in front of queue.
    void pop(void) {
        
        if( !s2.empty() )
        {
            s2.pop();
        }
        else if ( !s1.empty() )
        {
            while( !s1.empty() )
            {
                int x = s1.top();
                s2.push(x);
                s1.pop();
            }
            s2.pop();
        }
        else
        {
            cout << "ERROR: stack empty" << endl;
        }
        
    }

    // Get the front element.
    int peek(void) {
        
        if( !s2.empty() )
        {
            int x = s2.top();
            return x;
        }
        else if( !s1.empty() )
        {
            int x;
            while( !s1.empty() )
            {
                x = s1.top();
                s2.push(x);
                s1.pop();
            }
            return x;
        }
        else 
            return -1;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        
        return ( s1.empty() && s2.empty() );
    }
};
