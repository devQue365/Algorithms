#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
std::string lcs(std::string s1, std::string s2)
{
    // get lengths of the two strings
    int m = s1.length();
    int n = s2.length();
    std::vector<std::vector<int>> dp(m+1,std::vector<int>(n+1,0));
    // plot  the table
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            // if they match
            if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            // else
            else
                dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
        }
    }
    // get the longest subsequence length
    int lcs_length = dp[m][n];
    // backtrack the dp table
    int i = m;
    int j = n;
    std::string lcs_str = "";
    while(i>0 && j>0)
    {
        if(s1[i-1] == s2[j-1])
        {
            lcs_str = lcs_str + s1[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    std::reverse(lcs_str.begin(),lcs_str.end());
    return lcs_str;
}

int main()
{
    std::string lcs_str;
    std::string s1,s2;
    std::cout<<"Enter string-1 : ";
    std::cin>>s1;
    std::cout<<"Enter string-2 : ";
    std::cin>>s2;
    if(s1.length()>=s2.length())
        lcs_str = lcs(s1,s2);
    else
        lcs_str = lcs(s2,s1);
    std::cout<<"LCS is "<<lcs_str<<std::endl;
    return 0;
}