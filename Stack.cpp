#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class StackOperations
{
private:
    stack<int> st;

public:
    // ============ BASIC OPERATIONS (1-10) ============
    
    void push()
    {
        int value;
        cout << "Enter value to push: ";
        cin >> value;
        st.push(value);
        cout << "Value pushed successfully!\n";
    }

    void pop() 
    {
        if (st.empty())
        {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Popped value: " << st.top() << endl;
        st.pop();
    }

    void peek()
    {
        if (st.empty())
        {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Top element: " << st.top() << endl;
    }

    bool isEmpty() 
    {
        return st.empty();
    }

    void display() 
    {
        if (st.empty())
        {
            cout << "Stack is empty!\n";
            return;
        }
        
        stack<int> temp = st;
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty())
        {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    int size()
    {
        return st.size();
    }

    void copyStack() 
    {
        stack<int> copy = st;
        cout << "Stack copied! Copy contents: ";
        while (!copy.empty())
        {
            cout << copy.top() << " ";
            copy.pop();
        }
        cout << endl;
    }

    void search()
    {
        int target;
        cout << "Enter value to search: ";
        cin >> target;
        
        stack<int> temp = st;
        int position = 1;
        bool found = false;
        
        while (!temp.empty())
        {
            if (temp.top() == target)
            {
                cout << "Found at position " << position << " from top\n";
                found = true;
                break;
            }
            temp.pop();
            position++;
        }
        
        if (!found)
            cout << "Element not found!\n";
    }

    void reverse() 
    {
        stack<int> temp;
        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }
        st = temp;
        cout << "Stack reversed!\n";
    }

    void pushArray()
    {
        int n;
        cout << "Enter number of elements: ";
        cin >> n;
        
        cout << "Enter elements:\n";
        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            st.push(value);
        }
        cout << n << " elements pushed!\n";
    }

    // ============ INTERMEDIATE OPERATIONS (11-20) ============

    bool checkBalancedParentheses()
    {
        string expr;
        cout << "Enter expression: ";
        cin.ignore();
        getline(cin, expr);
        
        stack<char> brackets;
        for (char c : expr)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                brackets.push(c);
            }
            else if (c == ')' || c == '}' || c == ']')
            {
                if (brackets.empty())
                    return false;
                
                char top = brackets.top();
                if ((c == ')' && top == '(') ||
                    (c == '}' && top == '{') ||
                    (c == ']' && top == '['))
                {
                    brackets.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return brackets.empty();
    }

    int getPrecedence(char op) 
    {
        if (op == '+' || op == '-')
            return 1;
        if (op == '*' || op == '/')
            return 2;
        if (op == '^')
            return 3;
        return 0;
    }

    string infixToPostfix() 
    {
        string infix;
        cout << "Enter infix expression: ";
        cin >> infix;
        
        stack<char> operators;
        string postfix = "";
        
        for (char c : infix)
        {
            if (isalnum(c)) 
            {
                postfix += c;
            }
            else if (c == '(')
            {
                operators.push(c);
            }
            else if (c == ')')
            {
                while (!operators.empty() && operators.top() != '(')
                {
                    postfix += operators.top();
                    operators.pop();
                }
                if (!operators.empty())
                    operators.pop();
            }
            else 
            {
                while (!operators.empty() && operators.top() != '(' &&
                       getPrecedence(operators.top()) >= getPrecedence(c))
                {
                    postfix += operators.top();
                    operators.pop();
                }
                operators.push(c);
            }
        }
        
        while (!operators.empty())
        {
            postfix += operators.top();
            operators.pop();
        }
        
        return postfix;
    }

    int evaluatePostfix() 
    {
        string postfix;
        cout << "Enter postfix expression: ";
        cin >> postfix;
        
        stack<int> eval;
        for (char c : postfix)
        {
            if (isdigit(c)) 
            {
                eval.push(c - '0');
            }
            else 
            {
                int op2 = eval.top(); eval.pop();
                int op1 = eval.top(); eval.pop();
                
                switch(c)
                {
                    case '+': eval.push(op1 + op2); break;
                    case '-': eval.push(op1 - op2); break;
                    case '*': eval.push(op1 * op2); break;
                    case '/': eval.push(op1 / op2); break;
                }
            }
        }
        return eval.top();
    }

    int findMax() 
    {
        if (st.empty())
        {
            cout << "Stack is empty!\n";
            return -1;
        }
        
        stack<int> temp = st;
        int maxVal = temp.top();
        
        while (!temp.empty())
        {
            if (temp.top() > maxVal)
                maxVal = temp.top();
            temp.pop();
        }
        return maxVal;
    }

    void removeGreaterThan() 
    {
        int threshold;
        cout << "Enter threshold value: ";
        cin >> threshold;
        
        stack<int> temp;
        while (!st.empty())
        {
            if (st.top() <= threshold)
                temp.push(st.top());
            st.pop();
        }
        
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        cout << "Elements greater than " << threshold << " removed!\n";
    }

    void removeElement() 
    {
        int target;
        cout << "Enter element to remove: ";
        cin >> target;
        
        stack<int> temp;
        bool removed = false;
        
        while (!st.empty())
        {
            if (st.top() == target && !removed)
            {
                removed = true;
            }
            else
            {
                temp.push(st.top());
            }
            st.pop();
        }
        
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        
        if (removed)
            cout << "Element removed!\n";
        else
            cout << "Element not found!\n";
    }

    void printTopToBottom() 
    {
        if (st.empty())
        {
            cout << "Stack is empty!\n";
            return;
        }
        
        vector<int> elements;
        stack<int> temp = st;
        
        while (!temp.empty())
        {
            elements.push_back(temp.top());
            temp.pop();
        }
        
        cout << "Stack (top to bottom): ";
        for (int val : elements)
            cout << val << " ";
        cout << endl;
    }

    void mergeTwoStacks() 
    {
        stack<int> other;
        int n;
        cout << "Enter size of second stack: ";
        cin >> n;
        
        cout << "Enter elements for second stack:\n";
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            other.push(val);
        }
        
        while (!other.empty())
        {
            st.push(other.top());
            other.pop();
        }
        cout << "Stacks merged!\n";
    }

    // ============ ADVANCED OPERATIONS (21-25) ============

    bool checkPalindrome() 
    {
        string str;
        cout << "Enter string: ";
        cin >> str;
        
        stack<char> s;
        for (char c : str)
            s.push(c);
        
        for (char c : str)
        {
            if (c != s.top())
                return false;
            s.pop();
        }
        return true;
    }

    void nextGreaterElement() 
    {
        vector<int> arr;
        int n;
        cout << "Enter array size: ";
        cin >> n;
        
        cout << "Enter array elements:\n";
        for (int i = 0; i < n; i++)
        {
            int val;
            cin >> val;
            arr.push_back(val);
        }
        
        stack<int> s;
        vector<int> result(n);
        
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && s.top() <= arr[i])
                s.pop();

            result[i] = s.empty() ? -1 : s.top();
            s.push(arr[i]);
        }
        
        cout << "Next Greater Elements: ";
        for (int val : result)
            cout << val << " ";
        cout << endl;
    }

    // ============ ADDITIONAL OPERATIONS (26-35) ============

    int findMin() 
    {
        if (st.empty())
        {
            cout << "Stack is empty!\n";
            return -1;
        }
        
        stack<int> temp = st;
        int minVal = temp.top();
        
        while (!temp.empty())
        {
            if (temp.top() < minVal)
                minVal = temp.top();
            temp.pop();
        }
        return minVal;
    }

    int sum() 
    {
        stack<int> temp = st;
        int total = 0;
        
        while (!temp.empty())
        {
            total += temp.top();
            temp.pop();
        }
        return total;
    }

    double average()
    {
        if (st.empty())
            return 0;
        return (double)sum() / st.size();
    }

    void clear()
    {
        while (!st.empty())
            st.pop();
        cout << "Stack cleared!\n";
    }

    void sortStack() 
    {
        stack<int> temp;
        
        while (!st.empty())
        {
            int current = st.top();
            st.pop();
            
            while (!temp.empty() && temp.top() > current)
            {
                st.push(temp.top());
                temp.pop();
            }
            temp.push(current);
        }
        st = temp;
        cout << "Stack sorted!\n";
    }

    void removeDuplicates()
    {
        stack<int> temp;
        vector<int> seen;
        
        while (!st.empty())
        {
            int val = st.top();
            st.pop();
            
            bool found = false;
            for (int s : seen)
            {
                if (s == val)
                {
                    found = true;
                    break;
                }
            }
            
            if (!found)
            {
                temp.push(val);
                seen.push_back(val);
            }
        }
        
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        cout << "Duplicates removed!\n";
    }

    int countOccurrences()
    {
        int target;
        cout << "Enter element to count: ";
        cin >> target;
        
        stack<int> temp = st;
        int count = 0;
        
        while (!temp.empty())
        {
            if (temp.top() == target)
                count++;
            temp.pop();
        }
        return count;
    }

    void replaceElement() 
    {
        int oldVal, newVal;
        cout << "Enter old value: ";
        cin >> oldVal;
        cout << "Enter new value: ";
        cin >> newVal;
        
        stack<int> temp;
        
        while (!st.empty())
        {
            if (st.top() == oldVal)
                temp.push(newVal);
            else
                temp.push(st.top());
            st.pop();
        }
        
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        cout << "Element replaced!\n";
    }

    void pushBottom() 
    {
        int value;
        cout << "Enter value to push at bottom: ";
        cin >> value;
        
        stack<int> temp;
        while (!st.empty())
        {
            temp.push(st.top());
            st.pop();
        }
        
        st.push(value);
        
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
        cout << "Value pushed at bottom!\n";
    }

    int secondTop() 
    {
        if (st.size() < 2)
        {
            cout << "Stack has less than 2 elements!\n";
            return -1;
        }
        
        int first = st.top();
        st.pop();
        int second = st.top();
        st.push(first);
        
        return second;
    }
};

// ============ MIN STACK ============

class MinStack
{
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int val)
    {
        mainStack.push(val);
        if (minStack.empty() || val <= minStack.top())
            minStack.push(val);
    }

    void pop()
    {
        if (mainStack.empty())
            return;
        
        if (mainStack.top() == minStack.top())
            minStack.pop();
        mainStack.pop();
    }

    int getMin()
    {
        if (minStack.empty())
            return -1;
        return minStack.top();
    }

    int top()
    {
        if (mainStack.empty())
            return -1;
        return mainStack.top();
    }
};

// ============ MAX STACK ============

class MaxStack
{
private:
    stack<int> mainStack;
    stack<int> maxStack;

public:
    void push(int val)
    {
        mainStack.push(val);
        if (maxStack.empty() || val >= maxStack.top())
            maxStack.push(val);
    }

    void pop()
    {
        if (mainStack.empty())
            return;
        
        if (mainStack.top() == maxStack.top())
            maxStack.pop();
        mainStack.pop();
    }

    int getMax()
    {
        if (maxStack.empty())
            return -1;
        return maxStack.top();
    }

    int top()
    {
        if (mainStack.empty())
            return -1;
        return mainStack.top();
    }
};

// ============ MENU ============
void displayMenu()
{
    cout << "\n========== STACK OPERATIONS MENU (35 Methods) ==========\n";
    cout << "--- Basic (1-10) ---\n";
    cout << "1. Push\n2. Pop\n3. Peek\n4. Is Empty\n5. Display\n";
    cout << "6. Size\n7. Copy Stack\n8. Search\n9. Reverse\n10. Push Array\n";
    cout << "\n--- Intermediate (11-20) ---\n";
    cout << "11. Check Balanced Parentheses\n12. Infix to Postfix\n";
    cout << "13. Evaluate Postfix\n14. Find Max\n15. Remove Greater Than\n";
    cout << "16. Remove Element\n17. Print Top to Bottom\n18. Merge Stacks\n";
    cout << "\n--- Advanced (19-22) ---\n";
    cout << "19. Check Palindrome\n20. Next Greater Element\n";
    cout << "21. Test Min Stack\n22. Test Max Stack\n";
    cout << "\n--- Additional (23-32) ---\n";
    cout << "23. Find Min\n24. Sum\n25. Average\n26. Clear\n";
    cout << "27. Sort Stack\n28. Remove Duplicates\n29. Count Occurrences\n";
    cout << "30. Replace Element\n31. Push Bottom\n32. Second Top\n";
    cout << "\n0. Exit\n";
    cout << "========================================================\n";
    cout << "Enter choice: ";
}

// ---- START: New helper functions for sub-menus ----
void displayMinStackMenu()
{
    cout << "\n--- MinStack Interactive Menu ---\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Get Min\n";
    cout << "4. Get Top\n";
    cout << "0. Back to Main Menu\n";
    cout << "-----------------------------\n";
    cout << "Enter choice: ";
}

void displayMaxStackMenu()
{
    cout << "\n--- MaxStack Interactive Menu ---\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Get Max\n";
    cout << "4. Get Top\n";
    cout << "0. Back to Main Menu\n";
    cout << "-----------------------------\n";
    cout << "Enter choice: ";
}
// ---- END: New helper functions for sub-menus ----


int main()
{
    StackOperations stack;
    MinStack minStack; 
    MaxStack maxStack; 
    int choice;
    
    cout << "====== Stack Operations Program (35 Methods) ======\n";
    
    do {
        displayMenu();
        cin >> choice;
        
        switch(choice)
        {
            case 1: stack.push(); break;
            case 2: stack.pop(); break;
            case 3: stack.peek(); break;
            case 4: cout << (stack.isEmpty() ? "Empty" : "Not empty") << endl; break;
            case 5: stack.display(); break;
            case 6: cout << "Size: " << stack.size() << endl; break;
            case 7: stack.copyStack(); break;
            case 8: stack.search(); break;
            case 9: stack.reverse(); break;
            case 10: stack.pushArray(); break;
            case 11: cout << (stack.checkBalancedParentheses() ? "Balanced" : "Not balanced") << endl; break;
            case 12: cout << "Postfix: " << stack.infixToPostfix() << endl; break;
            case 13: cout << "Result: " << stack.evaluatePostfix() << endl; break;
            case 14: cout << "Max: " << stack.findMax() << endl; break;
            case 15: stack.removeGreaterThan(); break;
            case 16: stack.removeElement(); break;
            case 17: stack.printTopToBottom(); break;
            case 18: stack.mergeTwoStacks(); break;
            case 19: cout << (stack.checkPalindrome() ? "Palindrome" : "Not palindrome") << endl; break;
            case 20: stack.nextGreaterElement(); break;
            
            case 21: { 
                int minStackChoice;
                do {
                    displayMinStackMenu();
                    cin >> minStackChoice;
                    switch (minStackChoice) {
                        case 1: {
                            int val;
                            cout << "Enter value to push to MinStack: ";
                            cin >> val;
                            minStack.push(val);
                            cout << val << " pushed.\n";
                            break;
                        }
                        case 2:
                            if(minStack.top() != -1) cout << "Popped: " << minStack.top() << endl;
                            minStack.pop();
                            break;
                        case 3:
                            cout << "Current Min: " << minStack.getMin() << endl;
                            break;
                        case 4:
                            cout << "Current Top: " << minStack.top() << endl;
                            break;
                        case 0:
                            cout << "Returning to main menu...\n";
                            break;
                        default:
                            cout << "Invalid choice!\n";
                    }
                } while (minStackChoice != 0);
                break;
            }
            case 22: { 
                int maxStackChoice;
                do {
                    displayMaxStackMenu();
                    cin >> maxStackChoice;
                     switch (maxStackChoice) {
                        case 1: {
                            int val;
                            cout << "Enter value to push to MaxStack: ";
                            cin >> val;
                            maxStack.push(val);
                            cout << val << " pushed.\n";
                            break;
                        }
                        case 2:
                             if(maxStack.top() != -1) cout << "Popped: " << maxStack.top() << endl;
                            maxStack.pop();
                            break;
                        case 3:
                            cout << "Current Max: " << maxStack.getMax() << endl;
                            break;
                        case 4:
                            cout << "Current Top: " << maxStack.top() << endl;
                            break;
                        case 0:
                            cout << "Returning to main menu...\n";
                            break;
                        default:
                            cout << "Invalid choice!\n";
                    }
                } while (maxStackChoice != 0);
                break;
            }

            case 23: cout << "Min: " << stack.findMin() << endl; break;
            case 24: cout << "Sum: " << stack.sum() << endl; break;
            case 25: cout << "Average: " << stack.average() << endl; break;
            case 26: stack.clear(); break;
            case 27: stack.sortStack(); break;
            case 28: stack.removeDuplicates(); break;
            case 29: cout << "Count: " << stack.countOccurrences() << endl; break;
            case 30: stack.replaceElement(); break;
            case 31: stack.pushBottom(); break;
            case 32: cout << "Second top: " << stack.secondTop() << endl; break;
            case 0: cout << "\nThank you!\n"; break;
            default: cout << "Invalid choice!\n";
        }
        
    } while(choice != 0);
    
    return 0;
}