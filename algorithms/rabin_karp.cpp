#include <iostream>
#include <string>
void rabin_karp(std::string pat, std::string txt, int q = 101)
{
    /* initialize some values */
    int d = 256; // max number of characters
    int n = txt.length();
    int m = pat.length();
    int p = 0; // for hash of pattern
    int t = 0; // for hash of text
    int h = 1; // to calculate hash
    /* Calculate hash 'h' of pattern as d^(m-1)%q */
    for(int i=0;i<m-1;i++)
    {
        h = (h*d)%q;
    }
    /* Calculate the hash of pattern and the comparision window */
    for(int i=0;i<m;i++)
    {
        // hash of pattern
        p = (d*p + pat[i])%q;
        // hash of text
        t = (d*t + txt[i])%q;
    }
    /* Slide the pattern over the text one by one */
    for(int i=0;i<n-m+1;i++)
    {
        // if the both the hash match
        if(p == t)
        {
            // compare the pattern and the sliding window char-by-char
            int j =0;
            for(;j<m;j++)
            {
                if(txt[i+j] != pat[j])
                    break;
                }
            if(j==m)
                std::cout<<"Found at ["<<i<<"] index !"<<std::endl;
        }
        // slide the window by one character
        if(i<n-m)
        {
            t = (d * (t - txt[i] * h) + txt[i+m])%q;
            if(t<0)
            {
                t = t+q;
            }
        }
    }
}
int main()
{
    std::string txt = "DevBytesForRealDev";
    std::string pat = "Dev";
    rabin_karp(pat, txt);
    return 0;
}