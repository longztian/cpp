class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (!myData.empty()) myData.emplace_back(x, min(x, myData.back().min));
        else myData.emplace_back(x, x);
    }

    void pop() {
        myData.pop_back();
    }

    int top() {
        return myData.back().val;
    }

    int getMin() {
        return myData.back().min;
    }

private:
    struct MinNode {
        int val;
        int min;

        MinNode(int val, int min) : val(val), min(min) {}
    };

    vector<MinNode> myData;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
