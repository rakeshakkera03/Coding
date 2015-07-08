/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

int maxProfit(int* prices, int pricesSize) {
    
    int* diffPrices;
    
    if(pricesSize < 2)
        return 0;
        
    diffPrices = (int*)malloc(sizeof(int) * pricesSize - 1);
    memset(diffPrices, 0, sizeof(int) * pricesSize - 1);
    
    for(int i = 0 ; i < pricesSize - 1; i++ )
    {
        diffPrices[i] = prices[i+1] - prices[i];
    }
    
    int sum = 0;
    int total_sum = 0;
    for(int i = 0; i < pricesSize - 1; i++ )
    {
        
        if( diffPrices[i] > 0 )
        {
            sum = sum + diffPrices[i];
        }
    }
    
    return sum;
}
