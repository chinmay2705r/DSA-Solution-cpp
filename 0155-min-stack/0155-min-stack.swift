class MinStack {
    private var stack: [Int]
    private var minStack: [Int]

    init() {
        self.stack = []
        self.minStack = []
    }
    
    func push(_ value: Int) {
        stack.append(value)
        if let currentMin = minStack.last {
            minStack.append(min(value, currentMin))
        } else {
            minStack.append(value)
        }
    }
    
    func pop() {
        _ = stack.popLast()
        _ = minStack.popLast()
    }
    
    func top() -> Int {
        return stack.last ?? 0
    }
    
    func getMin() -> Int {
        return minStack.last ?? 0
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack()
 * obj.push(value)
 * obj.pop()
 * let ret_3: Int = obj.top()
 * let ret_4: Int = obj.getMin()
 */