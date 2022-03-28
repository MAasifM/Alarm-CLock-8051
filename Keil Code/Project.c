#include <reg51.h>
#include <stdio.h>

char hexvalue[60]={0x00,0x01,0x02,0x03,0x04,0x5,0x06,0x07,0x08,0x09,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x40,0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59};
void onesecDelay(void)
{
	unsigned int i=0;
	unsigned int j=0; 
	while(i<3600)
	{
		TMOD = 0x02;
		TH0= -256;
		TR0=1;
		while(TF0==0)
		{}
		TF0=0;
		i++;
	}
}

void orgtimer(void)
{
	while(1)
	{
		unsigned int i;
		unsigned int j;
		unsigned int k;
		for(i=0;i<12;i++)
		{
			P3=hexvalue[i];
			for(j=0;j<60;j++)
			{
				P2=hexvalue[j];
				for(k=0;k<60;k++)
				{
					P0=hexvalue[k];
					onesecDelay();
				}
				k=0;
			}
			j=0;
		}
		i=0;
	}	
}  

// main function
int main()
{

	orgtimer();
}

end;