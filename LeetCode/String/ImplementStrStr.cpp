int strStr(char* haystack, char* needle)
{
    if( strlen( needle ) > strlen( haystack ) )
	{
		return -1;
	}
	
	if( strlen(needle) == 0 )
	{
	    return 0;
	}
	
	int d = 256;
	int q = 101;

	int textHash  = 0; // Hash value of the window from the text of length equal to the length of the pattern.
	int pattHash  = 0; // Hash value of the pattern that we want to compare in the text
	int helperVal = 1; // Helper variable for hash value computations, equal to d^m-1; where 'd' is the number of possible character sets in the input and 'm' is the pattern length.

	// Indices on which we iterate.
	int i = -1, j = -1;

	// Calculate the value of the 'helperVal' variable.
	for( i = 0; i < strlen( needle ) - 1; i++ )
	{
		helperVal = ( helperVal * d ) % q;
	}

	// Calculate the hash value for the pattern and for the initial pattern length window from the text.
	for( i = 0; i < strlen( needle ); i++ )
	{
		pattHash = ( pattHash * d + needle[ i ] ) % q;
		textHash = ( textHash * d + haystack[ i ] ) % q;
	}

	for( i = 0; i <= ( strlen( haystack ) - strlen( needle ) ); i++ )
	{
		if( pattHash == textHash )
		{
			for( j = 0 ; j < strlen( needle ) ; j++ )
			{
				if( needle[ j ] != haystack[ i + j ] )
				{
					break;
				}

				if( j == ( strlen( needle ) - 1 ) )
				{
					return i;
				}
			}
		}

		if( i != ( strlen( haystack ) - strlen( needle ) ) )
		{
			textHash = ( d * ( textHash - ( haystack[ i ] * helperVal ) ) + haystack[ i + strlen( needle ) ] ) % q;
			if( textHash < 0 )
				textHash += q;
		}
	}
	
	return -1;
}

/* Brute force C++ 

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int i = 0;
        int index = -1;
        
        if( haystack.empty() || needle.empty() || haystack.length() < needle.length() )
            return -1;
        
        while ( i < haystack.length() )
        {
            if( haystack[i] == needle[0] )
            {
                int j = 0;
                index = i;
                while( j < needle.length() )
                {
                    if( haystack[i+j] == needle[j])
                    {
                        j++;
                    }
                    else
                        break;
                }
                if( j == needle.length())
                {
                    return index;
                }
                else
                {
                    index = -1;
                }
            }
            i++;
            
        }
        
        return -1;
        
    }
};

*/
