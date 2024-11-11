

class Solution {
public:
    bool isPrime(int num) {
        if (num <= 1) return false;
        for (int divisor = 2; divisor <= sqrt(num); divisor++) {
            if (num % divisor == 0) {
                return false;
            }
        }
        return true;
    }

    bool primeSubOperation(std::vector<int>& nums) {
        for (int index = 0; index < nums.size(); index++) {
            int maxDifference = (index == 0) ? nums[index] : nums[index] - nums[index - 1];
            
            if (maxDifference <= 0) return false;
            
            int optimalPrime = 0;
            for (int candidatePrime = maxDifference - 1; candidatePrime >= 2; candidatePrime--) {
                if (isPrime(candidatePrime)) {
                    optimalPrime = candidatePrime;
                    break;
                }
            }
            
            nums[index] -= optimalPrime;
        }
        
        return true;
    }
};
