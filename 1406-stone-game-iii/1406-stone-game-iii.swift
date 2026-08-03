class Solution {
    func stoneGameIII(_ stoneValue: [Int]) -> String {
        let n = stoneValue.count
        var dp = Array(repeating: 0, count: n + 1)        
        for i in stride(from: n - 1, through: 0, by: -1) {
            var maxDiff = Int.min
            var currentSum = 0

            for k in 0..<3 {
                if i + k < n {
                    currentSum += stoneValue[i + k]
                    let nextDiff = (i + k + 1 <= n) ? dp[i + k + 1] : 0
                    maxDiff = max(maxDiff, currentSum - nextDiff)
                }
            }
            
            dp[i] = maxDiff
        }
        
        if dp[0] > 0 {
            return "Alice"
        } else if dp[0] < 0 {
            return "Bob"
        } else {
            return "Tie"
        }
    }
}