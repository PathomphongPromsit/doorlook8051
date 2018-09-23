//condition - All 7 segment are common anode
#include <REGX52.H>
int key_data;
int digit_one=11;
int digit_two=11;
int digit_three=11;
int digit_four=11;

int pass_one=1;
int pass_two=2;
int pass_three=3;
int pass_four=4;

int k =1;
int count=0;

sbit C3 = P3^0;
sbit C2 = P3^1;
sbit C1 = P3^2;
sbit R4 = P3^3;
sbit R3 = P3^4;
sbit R2 = P3^5;
sbit R1 = P3^6;





unsigned int f,m=1,p;


delay(unsigned int y)
{
    unsigned int i,j;
    for(i=0;i<y;i++)
    {
        for(j=0;j<1275;j++)
        {
        }
    }
}

display_digit(int c) //function 7seg pattern anode
{ 
	switch(c)
	{ 	
		case 0: P1=0xc0;
		break; 
		case 1: P1=0xf9;
		break;
		case 2: P1=0xa4;
		break; 
		case 3: P1=0xb0;
		break;
		case 4:P1=0x99;
		break; 
		case 5: P1=0x92;
		break; 
		case 6:P1=0x82;
		break; 
		case 7:P1=0xf8;
		break;
		case 8:P1=0x80;
		break;
		case 9:P1=0x90;
		break;
		case 10:P1=0x7f;//dot
		break;
		case 11:P1=0xbf;// -	*
		break;
		case 12:P1=0xa3;// o	#
		break;
		case 13:P1=0x89;// H	
		break;
		case 99:P1=0xff;// empty
	
		break;
		return;
 	} 
}


int row_finder1() //Function for finding the row for column 1
{
	R1=R2=R3=R4=1;
	C1=C2=C3=0;


	if(R1==0)
	key_data = 1;
	else if(R2==0)
	key_data = 4;
	else if(R3==0)
	key_data = 7;
	else if(R4==0)
	key_data = 11;
	return key_data;
}

int row_finder2() //Function for finding the row for column 2
{
	R1=R2=R3=R4=1;
	C1=C2=C3=0;
	
	if(R1==0)
	key_data = 2;
	else if(R2==0)
	key_data = 5;
	else if(R3==0)
	key_data = 8;
	else if(R4==0)
	key_data = 0;
	return key_data;
}

int row_finder3() //Function for finding the row for column 3
{
	R1=R2=R3=R4=1;
	C1=C2=C3=0;

	if(R1==0)
	key_data = 3;
	else if(R2==0)
	key_data = 6;
	else if(R3==0)
	key_data = 9;
	else if(R4==0)
	key_data = 12;
	return key_data;
}



void main()
{
	P2_4=1;
	
	while(1)
    { 
		C1=C2=C3=1;
		R1=R2=R3=R4=0;
		
		if(C1==0)
		{
			key_data = row_finder1();
			digit_one=digit_two;
			digit_two=digit_three;
			digit_three=digit_four;
			digit_four=key_data;
			P2_5=1;
			delay(20);
			P2_5=0;
			
		}
		else if(C2==0)
		{
			key_data = row_finder2();
			digit_one=digit_two;
			digit_two=digit_three;
			digit_three=digit_four;
			digit_four=key_data;
			P2_5=1;
			delay(20);
			P2_5=0;
		}
		else if(C3==0)
		{
			key_data = row_finder3();
			digit_one=digit_two;
			digit_two=digit_three;
			digit_three=digit_four;
			digit_four=key_data;
			P2_5=1;
			delay(20);
			P2_5=0;
		}
		
			
		P2_3=1;
		P2_2=0;
		P2_1=0;
		P2_0=0;
		display_digit(digit_one);
		delay(k);
		P2_3=0;
		P2_2=0;
		P2_1=0;
		P2_0=0;
		delay(k);
	

		P2_3=0;
		P2_2=1;
		P2_1=0;
		P2_0=0;
		display_digit(digit_two);
		delay(k);
		P2_3=0;
		P2_2=0;
		P2_1=0;
		P2_0=0;
		delay(k);
		
		P2_3=0;
		P2_2=0;
		P2_1=1;
		P2_0=0;
		display_digit(digit_three);
		delay(k);
		P2_3=0;
		P2_2=0;
		P2_1=0;
		P2_0=0;
		delay(k);
		
		P2_3=0;
		P2_2=0;
		P2_1=0;
		P2_0=1;
		display_digit(digit_four);
		delay(k);
		P2_3=0;
		P2_2=0;
		P2_1=0;
		P2_0=0;
		delay(k);
		
		
		if(digit_one == pass_one && digit_two == pass_two && digit_three == pass_three && digit_four==pass_four)
		{
			m=1;
		}
		else
		{
			m=0;
		}
		
		if(m==1)
		{
			//PASSWORD MATCHED
			display_digit(13);
			P2_3=1;
			P2_2=1;
			P2_1=1;
			P2_0=1;
			P2_4=0;
			P2_5=1;
			delay(400);
			P2_4=1;
			P2_5=0;
			display_digit(11);
			digit_one = 11;
			digit_two = 11;
			digit_three = 11;
			digit_four = 11;
			
		}
			
		else
		{
			delay(30);
			count=count+1;
		}
		if (count >=30)
		{
			count = 0;
			digit_one = 11;
			digit_two = 11;
			digit_three = 11;
			digit_four = 11;
			P2_3=1;
			P2_2=1;
			P2_1=1;
			P2_0=1;
			display_digit(11);

		}				
	}	
}
