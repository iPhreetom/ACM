namespace fastIO
{
#define BUF_SIZE 1048576

    inline char nc()
    {
        static char buf[BUF_SIZE], *p1 = buf + BUF_SIZE, *pend = buf + BUF_SIZE;
        if (p1 == pend)
        {
            p1 = buf;
            pend = buf + fread(buf, 1, BUF_SIZE, stdin);
            assert(pend != p1);
        }
        return *p1++;
    }

    inline bool blank(char c) { return c == ' ' || c == '\n' || c == '\r' || c == '\t'; }

    // non-negative integer
    inline int getint()
    {
        int x = 0;
        char c = nc();
        while (blank(c)) c = nc();
        for (; c >= '0' && c <= '9'; c = nc()) x = x * 10 + c - '0';
        return x;
    }

    // integer
    // inline int getint()
    // {
    //     int x = 0, sgn = 1;
    //     char c = nc();
    //     while (blank(c)) c = nc();
    //     if (c == '-') sgn = -1, c = nc();
    //     for (; c >= '0' && c <= '9'; c = nc()) x = x * 10 + c - '0';
    //     return sgn * x;
    // }

#undef BUF_SIZE
};
using namespace fastIO;
