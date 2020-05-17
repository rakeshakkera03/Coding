class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int> table;
        table.push_back(1);
        int i2 = 0;
        int i3 = 0;
        int i5 = 0;
        
        while (table.size() <= n)
        {
            int len = table.size();
            //cout << table[i2] * 2 << ", " << table[i3] * 3 << ", " << table[i5] * 5 << "\n";
            int nextUglyNumber = min(table[i2] * 2, min(table[i3] * 3, table[i5] * 5));
            
            table.push_back(nextUglyNumber);
            
            if (table[i2] * 2 == nextUglyNumber)
            {
                i2++;
            }
            if (table[i3] * 3 == nextUglyNumber)
            {
                i3++;
            }
            if (table[i5] * 5 == nextUglyNumber)
            {
                i5++;
            }
        }
        
        //Print(table);
        
        return table[n - 1];
        
    }
    
    void Print(vector<int>& table)
    {
        for( int i = 0; i< table.size(); i++)
        {
            cout << table[i] << ",";
        }
        
        cout << "\n";
    }
};

