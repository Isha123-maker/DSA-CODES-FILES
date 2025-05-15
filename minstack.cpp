#include <iostream>
#include <stack>
#include <utility>
#include <stdexcept> // For runtime_error

using namespace std;

// Class for getting the minimum value from a stack with TC: O(1) and SC: O(2 * n)
class MinStack
{
private:
    stack<pair<int, int>> s; // Stack stores {val, min_so_far}

public:
    // Constructor
    MinStack() {}

    // Push function
    void push(int val)
    {
        if (s.empty())
        {
            s.push({val, val});
        }
        else
        {
            s.push({val, min(val, s.top().second)});
        }
    }

    // Pop function (check if stack is not empty)
    void pop()
    {
        if (!s.empty())
        {
            s.pop();
        }
    }

    // Get the top element (check if stack is not empty)
    int top()
    {
        if (!s.empty())
        {
            return s.top().first;
        }
        throw runtime_error("Stack is empty");
    }

    // Get the minimum value (check if stack is not empty)
    int getMin()
    {
        if (!s.empty())
        {
            return s.top().second;
        }
        throw runtime_error("Stack is empty");
    }
};

// Class for getting the minimum value from a stack with TC: O(1) and SC: O(n)
class MinStack2
{
private:
    stack<long long int> s; // Stack to store values with transformations
    long long int minVal;   // Variable to keep track of the minimum value

public:
    // Constructor to initialize minVal with a large value
    MinStack2() : minVal(0) {}

    // Push function to insert an element while maintaining the min value
    void push(int val)
    {
        if (s.empty())
        {
            s.push(val);  // Store the actual value
            minVal = val; // Update min value
        }
        else
        {
            if (val < minVal)
            {
                // Store an encoded value to track the minimum
                s.push(2LL * val - minVal);
                minVal = val; // Update the new minimum
            }
            else
            {
                s.push(val); // Store the normal value
            }
        }
    }

    // Pop function to remove an element from the stack
    void pop()
    {
        if (s.empty())
        {
            throw runtime_error("Stack is empty, cannot pop");
        }

        if (s.top() < minVal)
        {
            // Restore the previous minimum value before removing the top element
            minVal = 2LL * minVal - s.top();
        }
        s.pop();
    }

    // Function to get the top element of the stack
    int top()
    {
        if (s.empty())
        {
            throw runtime_error("Stack is empty, cannot get top");
        }

        if (s.top() < minVal)
        {
            return minVal; // Return the actual minimum value
        }
        return s.top();
    }

    // Function to get the minimum value in the stack
    int getMin()
    {
        if (s.empty())
        {
            throw runtime_error("Stack is empty, cannot get minimum");
        }
        return minVal;
    }
};
int main()
{
    MinStack2 s;
    s.push(5);
    s.push(3);
    s.push(2);
    s.push(1);

    cout << "Minimum Element: " << s.getMin() << endl; // Output: 1

    s.pop();
    cout << "Minimum Element after pop: " << s.getMin() << endl; // Output: 2

    cout << "Top Element: " << s.top() << endl; // Output: 2

    return 0;
}
