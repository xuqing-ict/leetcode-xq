class Solution {
public:
    void reverseWords(string &s) {
        const int n = s.size();
        if(n==0) return ;
        int left=0;
        string ret,word;
        while(left<n)
        {
            while(left<n && s[left] == ' ')++left;
            word.clear();
            while(left<n && s[left] != ' ')
            {
                word += s[left]; 
                ++left;
            }            
            if(!word.empty())
            {
                reverse(word.begin(),word.end());
                ret += word;
                ret += ' ';
            }
        }
        if(!ret.empty()) ret.pop_back();
        reverse(ret.begin(), ret.end());
        s=ret;

    }
};
