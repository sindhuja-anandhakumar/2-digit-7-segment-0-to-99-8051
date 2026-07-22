#include <reg51.h>
#define seg P2
sbit d1 = P3^0;
sbit d2 = P3^1;
void delay();
void main()
{
    unsigned char num[10] = { 0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
    int i,k,t,u;
    while(1)
    {
        for(i=0; i<100; i++)
        {
            t = i / 10;
            u = i % 10;

            for(k=0; k<100; k++)
            { 
                d1=1;
                d2=1;
                d1 = 0; 
							  d2 = 1;
							  seg = num[t]; 
                delay();
							  d1=1;
							  d2=1;
                d1 = 1; 
							  d2 = 0;
							  seg = num[u];    
                delay();
            }
        }
    }
}
void delay()
{
    int i,j;
    for(i=0;i<10;i++)
        for(j=0;j<50;j++);
}
