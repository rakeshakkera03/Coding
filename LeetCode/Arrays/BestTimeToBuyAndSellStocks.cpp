/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/


int CalculateMaxCrossing(int* prices, int low, int mid, int high )
{
    int left_sum = 0;
    int right_sum = 0;
    int curr_sum = 0;
    
    for( int i = mid; i >= low; i-- )
    {
        curr_sum = curr_sum + prices[i];
        if( curr_sum > left_sum )
        {
            left_sum = curr_sum;
        }
    }
    curr_sum = 0;
    for( int i = mid+1; i <= high; i++ )
    {
        curr_sum = curr_sum + prices[i];
        if( curr_sum > right_sum )
        {
            right_sum = curr_sum;
        }
    }
    
    return (left_sum + right_sum);
    
}
int CalculateMaxProfit(int* prices, int low , int high )
{
    if( low == high )
    {
        return (prices[low] >= 0? prices[low]:0);
    }
        
    
    int mid = (low + high)/2;
    
    int left  = CalculateMaxProfit( prices, low, mid );
    int right = CalculateMaxProfit( prices, mid + 1, high );
    int cross = CalculateMaxCrossing( prices, low, mid, high );
    
    if( left >= right && left >= cross )
    {
        return left;
    }
    else if ( right >= left && right >= cross )
    {
        return right;
    }
    else 
        return cross;
}

int maxProfit(int* prices, int pricesSize) {
    
    if(pricesSize == 0 || pricesSize == 1)
        return 0;
        
    int priceDiff[pricesSize - 1];
    for(int i = 0; i < pricesSize - 1; i++ )
    {
        priceDiff[i] = prices[i+1] - prices[i];
    }
    
    return (CalculateMaxProfit(priceDiff, 0, pricesSize - 2));
 
}
