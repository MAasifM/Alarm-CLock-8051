#include <reg51.h>
#include<stdio.h>
unsigned int i;
unsigned int j;
unsigned int k;

unsigned int su=0;
unsigned int st=0;
unsigned int mu=0;
unsigned int mt=0;
unsigned int hu=0;
unsigned int ht=0;

char hexvalue[60]={0x00,0x01,0x02,0x03,0x04,0x5,0x06,0x07,0x08,0x09,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59};
// keypad rows
sbit keyrow1 = P1 ^ 0;				// 4x3 keypad Row 1
sbit keyrow2 = P1 ^ 1;				// 4x3 keypad Row 2
sbit keyrow3 = P1 ^ 2;				// 4x3 keypad Row 3
sbit keyrow4 = P1 ^ 3;				// 4x3 keypad Row 4

//keypad column	
sbit keycolumn1 = P1 ^ 4;			// 4x3 keypad column 1
sbit keycolumn2 = P1 ^ 5;			// 4x3 keypad column 2
sbit keycolumn3 = P1 ^ 6;			// 4x3 keypad column 3

sbit Snooze = P1 ^ 7;
void delay(unsigned int j)
{
    int a, b;
    for (a = 0; a < j; a++)
    {
        for (b = 0; b < 100; b++);
    }
}

int keypad()
{
    int x = 0;
    while (x == 0)
    {
		// Algorithm for 4 x 3 keypad
        // assign values for first row
        keyrow1 = 0;
        keyrow2 = 1;
        keyrow3 = 1;
        keyrow4 = 1;
        if (keycolumn1 == 0)
        {
            delay(1000);
            x = 1;
            return 1;
        }
        if (keycolumn2 == 0)
        {
            delay(1000);
            x = 1;
            return 2;
        }
        if (keycolumn3 == 0)
        {
            delay(1000);
            x = 1;
            return 3;
        }
        // assign values for second row
        keyrow1 = 1;
        keyrow2 = 0;
        keyrow3 = 1;
        keyrow4 = 1;

        if (keycolumn1 == 0)
        {
            delay(1000);
            x = 1;
            return 4;
        }
        if (keycolumn2 == 0)
        {
            delay(1000);
            x = 1;
            return 5;
        }
        if (keycolumn3 == 0)
        {
            delay(1000);
            x = 1;
            return 6;
        }

        // assign values for third row
        keyrow1 = 1;
        keyrow2 = 1;
        keyrow3 = 0;
        keyrow4 = 1;
        if (keycolumn1 == 0)
        {
            delay(1000);
            x = 1;
            return 7;
        }
        if (keycolumn2 == 0)
        {
            delay(1000);
            x = 1;
            return 8;
        }
        if (keycolumn3 == 0)
        {
            delay(1000);
            x = 1;
            return 9;
        }

        // assign values for forth row
        keyrow1 = 1;
        keyrow2 = 1;
        keyrow3 = 1;
        keyrow4 = 0;

        if (keycolumn2 == 0)
        {
            delay(1000);
            x = 1;
            return 0;
        }
    }
}

void SetAlarm()
{
	while(1)
	{
		ht=keypad();
		if(ht>2)
		{
			P3=0x00;
			continue;
		}
		hu=keypad();
		if(hu>3)
		{
			P3=0x00;
			continue;
		}
		break;
	}
	P3=hexvalue[ht*10+hu];
	while(1)
	{
		mt=keypad();
		if(mt>6)
		{
			P2=0x00;
			continue;
		}
		mu=keypad();
		break;
	}
	P2=hexvalue[mt*10+mu];
	while(1)
	{
		st=keypad();
		if(st>6)
		{
			P0=0x00;
			continue;
		}
		su=keypad();
		break;
	}
	P0=hexvalue[st*10+su];
}

void main()
{
	i=0;
	j=0;
	k=0;
	SetAlarm();
	while(1)
	{
		if(Snooze==0)
		{
			mu=mu+2;
			if(mu==10)
			{
				mu=0;
				mt++;
				if(mt==6)
				{
					mt=0;
					hu++;
					if(hu==10)
					{
						hu=0;
						ht++;
					}
				}
			}
			P0=hexvalue[st*10+su];
			P2=hexvalue[mt*10+mu];
			P3=hexvalue[ht*10+hu];
			delay(1000);
		}
	}
}
