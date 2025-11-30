class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;

        int total = 10;      // for n = 1
        int unique = 9;      // choices for first digit (1–9)
        int available = 9;   // remaining digits

        for (int i = 2; i <= n; i++) {
            unique *= available; 
            total += unique;
            available--;
        }

        return total;
    }
};
