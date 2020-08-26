/*
Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        v.push_back(x);
    }
    
    void pop() {
        if(!v.empty()) v.pop_back();
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return *min_element(v.begin(),v.end());
    }
private:
    vector<int> v;
};


// Approach 2 
// ------------
// ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
// [[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]


// class MinStack {
// public:
//     /** initialize your data structure here. */
//     MinStack() {}
    
//     /*
//     Push(x) : Inserts x at the top of stack.
    
//     If stack is empty, insert x into the stack and make min equal to x.
//     If stack is not empty, compare x with min. Two cases arise:
//     If x is greater than or equal to min, simply insert x.
//     If x is less than min, insert (2*x – min) into the stack and make min equal to x. 
//     For example, let previous min was 3. Now we want to insert 2. We update min as 2 and insert 2*2 – 3 = 1 into the stack.
//     */
//     void push(int x) {
//         if(s.empty()){
//             min=x;
//             s.push(x);
//             return;
//         }
        
//         if(x<min){
//             s.push(2*x-min);
//             min=x;
//         } else s.push(x);
//     }
    
//     /*
//     Pop() : Removes an element from top of stack.

//     Remove element from top. Let the removed element be y. Two cases arise:
//     If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
//     If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle – y). This is where we retrieve previous minimum from current minimum and its value in stack. 
//     For example, let the element to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 – 1 = 3.
//     */
//     void pop() {
//         if(s.empty()) return;
//         int t = s.top();
//         s.pop();
//         if(t<min) min=2*min-t;
//     }
    
//     int top() {
//         int t = s.top();
//         return (t<min)? min:t;
//     }
    
//     int getMin() {
//         return min;   
//     }
// private:
//     stack<int>s;
//     int min;
// };

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();