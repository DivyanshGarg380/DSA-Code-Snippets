class Solution {
    public int maxProfit(int[] prices) {
        int l=0,r=1;
        int max = 0;

        while(r<prices.length)
        {
            if(prices[l]<prices[r])
            {
                int profit = prices[r] - prices[l];

                max = Math.max(profit,max);
            }
            else l=r;
            r++;
        }
        return max;
    }
}
