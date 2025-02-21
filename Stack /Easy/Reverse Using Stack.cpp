char* reverse(char *S, int len)
{
    int a=0;
    len--;
    while(a<len)
    swap(S[a++],S[len--]);
    return S;
}
