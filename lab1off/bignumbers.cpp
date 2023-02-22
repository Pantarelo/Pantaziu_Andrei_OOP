#include <iostream>
#include <cstring>
using namespace std;

int conversie(char* s)
{
    int x = 0;
    for (int i = 0; s[i] != 0 && s[i] != '\n'; i++)
    {
        x = x * 10 + (s[i] - '0');
    }
    return x;
}

int main()
{
    FILE* fisier;
    bool ok = fopen_s(&fisier, "in.txt", "r");
    char* c = new char[256];
    char* m[10];
    char* sNr = new char[256];
    int s = 0, nr = -1, inPlus = 0;
    int v[10], maxi = 0;
    if (ok != 0)
    {
        cout << "Nu am putut citi fisierul";
        return 0;
    }
    for (int i = 0; i < 10; i++)
    {
        m[i] = new char[256];
    }
    while (fgets(m[++nr], 256, fisier))
    {
        if(m[nr][strlen(m[nr]) - 1] == '\n')
            m[nr][strlen(m[nr])-1] = '\0';
        v[nr] = strlen(m[nr]);
        if (maxi < v[nr])
            maxi = v[nr];
    }
    sNr[maxi] = '\0';
    for (int i = 1; i <= maxi; i++)
    {
        s = inPlus;
        for (int j = 0; j < nr; j++)
        {
            if (strlen(m[j])>=i)
            {
                s = s + (m[j][strlen(m[j])-i] - '0');
            }
        }
        inPlus = s / 10;
        sNr[maxi-i] = '0' + s % 10;
    }
    printf("%s", sNr);
    return 0;
}