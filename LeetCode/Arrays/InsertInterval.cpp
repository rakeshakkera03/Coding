/*

ven a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
*/

static bool mySort( const Interval &a, const Interval &b )
    {
        return a.start < b.start;
    }
    
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
     
        vector<Interval> result; 
        result.clear();
        Interval temp;
        
        intervals.push_back( newInterval );
    
        if( intervals.size() == 0 )
        {
            return result;
        }
        
        sort( intervals.begin(), intervals.end(), mySort );
        
        temp.start = intervals[0].start; temp.end = intervals[0].end;
        
        //print( intervals );
        int i = 1;
        while( i < intervals.size() )
        {
            if( temp.end >= intervals[i].start )
            {
                temp.end = max( temp.end, intervals[i].end ); // here max is necessary since, the interval with same start 
                                                              // but smaller end can be after  
            }
            else
            {
                result.push_back(temp);
                temp.start = intervals[i].start;
                temp.end = intervals[i].end;
            }
            
            i++;
        }
        result.push_back(temp);
        
        //print ( result );
        
        return result;  
    }
