#include <iostream>
#include <vector>
using namespace std;
vector<int> v(1000000, 0);
void kmp(string s)
{
    int index = 0, i = 1;
    for (i = 1; i < s.size();)
    {
        if (s[index] == s[i])
        {
            v[i] = index + 1;
            i++;
            index++;
        }
        else
        {
            if (index != 0)
            {
                index = v[index - 1];
            }
            else
            {
                v[i] = 0;
                i++;
            }
        }
    }
}
int ok(string s, string p)
{
    int i = 0, j = 0, h = 0;
    while (i < s.size())
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = v[j - 1];
            }
            else
                i++;
        }
        //cout<<j<<endl;
        if (j == p.size())
        {
            h++;
            j = v[j - 1];
        }
    }
    return h;
}

int main()
{
    int tc, r = 0;
    cin >> tc;
    while (tc--)
    {
        cout << "Case " << ++r << ": ";
        int i;
        string k, s;
        cin >> s >> k;
        kmp(k);
        int ans = ok(s, k);
        //  for(i=0;i<k.size();i++)cout<<v[i]<<" ";
        cout << ans << endl;
    }
}
