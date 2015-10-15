/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

void print( vector<Interval> a )
    {
        for( int i = 0; i < a.size(); i++ )
        {
            cout << a[i].start << " - " << a[i].end << ", ";
        }
        
        cout << endl << endl;
    }
    static bool mySort( const Interval &a, const Interval &b )
    {
        return a.start < b.start;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        
        vector<Interval> result; 
        result.clear();
        Interval temp;
    
        if( intervals.size() == 0 )
        {
            return result;
        }
        
        sort( intervals.begin(), intervals.end(), mySort );
        
        temp.start = intervals[0].start; temp.end = intervals[0].end;
        
        print( intervals );
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
        
        print ( result );
        
        return result;
    }
