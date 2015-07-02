#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isInterleaved(string s1, string s2, string s3, string &r, int s1_idx, int s2_idx)
    {
        int ret = false;
        if( r.length() == s3.length() )
        {
           if( !r.compare(s3) )
           {
	   	cout << r <<" " << s3 <<  endl;
	   	return true;
           }
	    else 
                return false;
        }
        
        if( s1_idx < s1.length() )
	{
            r.push_back(s1[s1_idx]);
            ret = isInterleaved(s1, s2, s3, r, s1_idx + 1, s2_idx);
            if( ret == true )
                return true;
            r.pop_back();
        }
        
        if( s2_idx < s2.length() )
	{
            r.push_back(s2[s2_idx]);
            ret = isInterleaved(s1, s2, s3, r, s1_idx, s2_idx + 1);
            if( ret == true )
                return true;
            r.pop_back();
        }
        
        return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        
        string r;
        return isInterleaved( s1, s2, s3, r, 0, 0);
    }

int main()
{
	string s1 = "abaaacbacaab";
	string s2 = "bcccababccc";
	string s3 = "bcccabaaaaabccaccbacabb";

	isInterleave( s1, s2, s3 );
	return 0;
}
