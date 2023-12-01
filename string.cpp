/*
    1.KMP pattern matching algorithm
    Time Complexity: O(N+M) where N is the length of the text and M is the length of the pattern to be found.
    Auxiliary Space: O(M)
    
void getlps(string pat,vector<int>&lps)
{
    if(pat.length()==1)
    {
        return;
    }
    int i=1,j=0;
    while(i<pat.length())
    {
        if(pat[i]==pat[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else if(j>0)
        {
            j=lps[j-1];//jump to index of prev match
        }
        else
        {
            lps[i]=0;
            i++;
        }
    }
}
vector <int> search(string pat, string txt)
{
    int i=0, j=0;
    vector<int>lps(pat.length(),0),ans;
    getlps(pat,lps);
    
    while(i<txt.length() && j<txt.length())
    {
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }
        else if (j>0)
        {
            j=lps[j-1];//begin search from the point which is suffix, as well as prefix
        }
        else
        {
            i++;
        }
        if(j==pat.length())
        {
            ans.push_back(i-j+1);
            j=lps[j-1];
        }
    }
    if(!ans.size())
    {
        ans.push_back(-1);
    }
    return ans;
    //code hee.
}
*/