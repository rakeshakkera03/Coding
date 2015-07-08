/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

void merge(int* nums1, int m, int* nums2, int n) {
    
    int temp = 0;
    
    if( m == 0 )
    {
        for( int i = 0; i < n; i++)
        {
            nums1[i] = nums2[i];
        }
        return;
    }
    else if ( n == 0 )
    {
        return;
    }
   
    // Copying all elements of nums1 to end of nums1 
    for( int i = m - 1; i >= 0; i-- )
    {
        nums1[i+n] = nums1[i];        
    }
    
    int i = 0, j = n;
    int k = 0;
    while( i < n  && j < m+n )
    {
        if( nums2[i] < nums1[j] )
        {
            nums1[k++] = nums2[i++];
        }
        else
        {
            nums1[k++] = nums1[j++];
        }
    }
    if( i < n)
    {
        while( i < n )
        {
            nums1[k++] = nums2[i++];
        }
    }
    else if( j < m+n )
    {
        while( j < m+n )
        {
            nums1[k++] = nums1[j++];
        }
    }
    return;
}
