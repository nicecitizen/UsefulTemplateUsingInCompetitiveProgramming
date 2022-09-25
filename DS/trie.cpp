struct Trie
{
    char a[N][26];
    int tot = 0;
    Trie()
    {
        memset(a, '0', sizeof(a));
    }
    void build(string s)
    {
        int idx = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int lt = s[i] - 'A';
            if (a[idx][lt] == '0')
                a[idx][lt] = ++tot;
            idx = a[idx][lt];
        }
    }
};