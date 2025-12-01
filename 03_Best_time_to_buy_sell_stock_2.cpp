class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if( n == 0) return 0;

        int notHold = 0 ;
        int hold = -prices[0];

        for(int i = 1 ; i<n ; i++){
        int newNotHold = max(notHold , hold + prices[i]);
        int newHold = max(hold , notHold - prices[i]);
        notHold = newNotHold;
            hold = newHold;
        }
        return notHold ;
    }
};
