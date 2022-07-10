#include "header.h"
#include <math.h>

/*
 * You are required to implement the parser functions below.
 *
 * int validateHeader(uint32_t header); function validates the header. A header is valid if all the conditions below evaluate true.
 *  - SYNC field is equal to 0x2a
 *  - if ACK bit is set V bit is also
 *  - if ACK bit is reset TYPE is non-zero.
 *  - SOURCE ADDRESS and DESTINATION ADDRESS are non-zero and different than each other.
 *
 *  If the header is valid, the function returns 1 otherwise it returns 0.
 *
 * int getFrameId(uint32_t header); function returns FRAME ID field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to FRAME ID field.
 *
 * int getFrameType(uint32_t header); function returns TYPE field if the header is valid, possibly checked using validateHeader function above, and ACK bit is reset.
 *  - If the header is not valid, it returns -1.
 *  - If ACK bit is set, it returns 0.
 *  - Otherwise, it returns non-negative integer corresponding to TYPE field.
 *
 * int getSourceAddress(uint32_t header); function returns SOURCE ADDRESS field if the header is valid, possibly checked using validateHeader function above.
 *  - If the header is not valid, it returns -1.
 *  - Otherwise, it returns non-negative integer corresponding to SOURCE ADDRESS field.
 */

int st[40];
int n;
const int SYNC_STANDARD_VALUE = 42;
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
void to_brinay(int value, int begin, int end)
{
    int t_st[30];
    int cnt = 1;
    while (value)
    {
        int x = value % 2;
        value /= 2;
        t_st[cnt++] = x;
    }
    cnt--;
    int pos = begin;

    for (int i = 1; i <= cnt; i++)
    {
        st[pos] = t_st[i];
        pos++;
    }
}
int old_translate(int begin, int end)
{
    int sum = 0;
    for (int i = begin; i <= end; i++)
    {
        //printf("i:%d st[i]:%d sum:%d\n", i, st[i], sum);
        int time = end - begin;
        if (st[i] != 0)
        {
            sum += pow(2, time);
        }
        time--;
    }
    return sum;
}
uint32_t translate(int begin, int end)
{
    uint32_t sum = 0;
    int cnt = 0;
    for (int i = begin; i <= end; i++)
    {
        if (st[i] != 0)
        {
            sum += pow(2, cnt);
        }
        cnt++;
    }
    return sum;
}

int validateHeader(uint32_t header)
    {
        int sync = translate(0, 5);
        //printf("%d\n", sync);
        if (sync != SYNC_STANDARD_VALUE)
        {
            return 0;
        }
        if (st[6] != st[7])
        {
            return 0;
        }
        if (st[6] == 0 && (st[7] + st[8] + st[9]) != 0)
        {
            return 0;
        }
        int source = translate(16, 23);
        int direct = translate(24, 31);
        //printf("%d %d\n", source, direct);
        if (source == 0 || direct == 0 || source == direct)
        {
            return 0;
        }
        return 1;
    }
int getFrameId(uint32_t header)
{
    if (validateHeader(header) == 0)
        return -1;
    return translate(11, 15);
}
int getFrameType(uint32_t header)
{
    if (validateHeader(header) == 0)
        return -1;
    if (st[6] != 0)
        return 0;
    return translate(8, 10);
}
int getSourceAddress(uint32_t header)
{
    if (validateHeader(header) == 0)
        return -1;
    return translate(16, 23);
}
uint32_t createAckHeader(int destAddress, int sourceAddress, uint32_t frameId, char valid)
{
    st[6] = 1;
    st[0] = 1;
    for (int i = 0; i <= 5; i++)
    {
        if (i % 2 == 0)
            st[i] = 0;
        else
            st[i] = 1;
    }
    if (valid == 0)
        st[7] = 0;
    else
        st[7] = 1;
    to_brinay(destAddress, 24, 31);
    to_brinay(sourceAddress, 16, 23);
    to_brinay(frameId, 11, 15);
    return translate(0, 31);
}
uint32_t createHeader(int destAddress, int sourceAddress, uint8_t frameId, uint8_t type)
{
    st[0] = 1;
    for (int i = 0; i <= 5; i++)
    {
        if (i % 2 == 0)
            st[i] = 0;
        else
            st[i] = 1;
    }
    to_brinay(destAddress, 24, 31);
    to_brinay(sourceAddress, 16, 23);
    to_brinay(frameId, 11, 15);
    to_brinay(type, 8, 10);
    return translate(0, 31);
}
int main()
{
    printf("hello world\n");
    createAckHeader(12, 3, 5, 0);
    for(int i=0;i<=31;i++)
    {
        printf("%d",st[i]);
    }
}