#include "db.h"
#include "math.h"
#include "dac.h"
/*
float Db_to_av(float db)
{
	return (20*log10(av));
}*/

float Av_to_db(float av)
{
	return  (20*log10(av));
}

void Av_control(float av)//av 0.317-31.6
{
	float db=Av_to_db(av);
	float volt;
	volt=-0.025*(db-10);
	Dac1_Set_Vol(volt);
}
extern float av;
extern u16 cYmax;
extern float ADmax;
void AD603()
{
	if(cYmax>4000)
	{
	Dac1_Set_Vol(500);
	}
	else
	{
	Dac1_Set_Vol(0);
	}
  /*
	if((ADmax<=2000)&&(ADmax>=500))
	{
		
	}
	if(ADmax>2000)
	{
		av=av-2;
		Av_control(av);
	}
	if(ADmax<500)
	{
		av=av+2;
		Av_control(av);
	}
	if(av>3.1)
		av=3.1;
	if(av<0.31)
		av=0.31; */
}