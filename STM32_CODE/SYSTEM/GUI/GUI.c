#include "GUI.h"
#include "math.h"
//extern DAC_WAVE_Typedef DAC_SETTING;


void GUI_draw_key_0(void)
{
//  LCD_Clear(WHITE);   //清屏
    LCD_Display_Dir(1);//横屏
    POINT_COLOR = RED;          //设置字体为红色

    LCD_DrawRectangle(20, 20, 300, 220);

    LCD_DrawLine(90, 20, 90, 220);
    LCD_DrawLine(160, 20, 160, 220);
    LCD_DrawLine(230, 20, 230, 220);

    LCD_DrawLine(20, 70, 300, 70);
    LCD_DrawLine(20, 120, 300, 120);
    LCD_DrawLine(20, 170, 300, 170);

    Show_Str(140, 5, 200, 16, "信号源", 12, 1);

    Show_Str(35, 40, 200, 16, "正弦波", 16, 1);
    Show_Str(35, 90, 200, 16, "锯齿波", 16, 1);
    Show_Str(35, 140, 200, 16, "三角波", 16, 1);
    Show_Str(35, 190, 200, 16, "方  波", 16, 1);

    Show_Str(105, 40, 200, 16, "左  移", 16, 1);
    Show_Str(105, 90, 200, 16, "右  移", 16, 1);
    Show_Str(105, 140, 200, 16, "频率+1", 16, 1);
    Show_Str(105, 190, 200, 16, "频率-1", 16, 1);
//    LCD_ShowxNum(105, 172, DAC_SETTING.HZ, 4, 16, 0x00);    //显示频率

    Show_Str(175, 40, 200, 16, "上  移", 16, 1);
    Show_Str(175, 90, 200, 16, "下  移", 16, 1);
    Show_Str(175, 140, 200, 16, "幅度+1", 16, 1);
    Show_Str(175, 190, 200, 16, "幅度-1", 16, 1);

    Show_Str(245, 40, 200, 16, "水平挡", 16, 1);
    Show_Str(245, 90, 200, 16, "垂直挡", 16, 1);
    Show_Str(245, 140, 200, 16, "直流+0", 16, 1);
    Show_Str(245, 190, 200, 16, "直流-0", 16, 1);
}

void GUI_draw_key_1(void)
{
    LCD_Display_Dir(1);//横屏
    POINT_COLOR = RED;          //设置字体为红色

    LCD_DrawRectangle(20, 20, 300, 220);

    LCD_DrawLine(90, 20, 90, 220);
    LCD_DrawLine(160, 20, 160, 220);
    LCD_DrawLine(230, 20, 230, 220);

    LCD_DrawLine(20, 70, 300, 70);
    LCD_DrawLine(20, 120, 300, 120);
    LCD_DrawLine(20, 170, 300, 170);

    Show_Str(140, 5, 200, 16, "示波器", 12, 1);

    Show_Str(35, 40, 200, 16, "锁  定", 16, 1);
    Show_Str(35, 90, 200, 16, "锁定类", 16, 1);
    Show_Str(35, 140, 200, 16, "电平升", 16, 1);
    Show_Str(35, 190, 200, 16, "电平降", 16, 1);

    Show_Str(105, 40, 200, 16, "自  动", 16, 1);
    Show_Str(105, 90, 200, 16, "自  动", 16, 1);
    Show_Str(105, 140, 200, 16, "时间+1", 16, 1);
    Show_Str(105, 190, 200, 16, "时间-1", 16, 1);
    LCD_ShowxNum(105, 172, ADC_Fr, 7, 16, 0x00);    //显示采样率

    Show_Str(175, 40, 200, 16, "上  移", 16, 1);
    Show_Str(175, 90, 200, 16, "下  移", 16, 1);
    Show_Str(175, 140, 200, 16, "幅度+1", 16, 1);
    Show_Str(175, 190, 200, 16, "幅度-1", 16, 1);

    Show_Str(245, 40, 200, 16, "挡位0", 16, 1);
    Show_Str(245, 90, 200, 16, "挡位1", 16, 1);
    Show_Str(245, 140, 200, 16, "挡位2", 16, 1);
    Show_Str(245, 190, 200, 16, "挡位3", 16, 1);
}

void GUI_draw_coordinate(void)  //画坐标
{
//  LCD_Clear(WHITE);   //清屏
    LCD_Display_Dir(1);//横屏
    POINT_COLOR = RED;          //设置字体为红色
//  Show_Str(105,90,200,16,"画坐标",16,1);

    LCD_DrawRectangle(10, 10, 310, 230);
    LCD_DrawLine(40, 10, 40, 230);
    LCD_DrawLine(70, 10, 70, 230);
    LCD_DrawLine(100, 10, 100, 230);
    LCD_DrawLine(130, 10, 130, 230);
    LCD_DrawLine(159, 10, 159, 230);
    LCD_DrawLine(160, 10, 160, 230);
    LCD_DrawLine(161, 10, 161, 230);
    LCD_DrawLine(190, 10, 190, 230);
    LCD_DrawLine(220, 10, 220, 230);
    LCD_DrawLine(250, 10, 250, 230);
    LCD_DrawLine(280, 10, 280, 230);

    LCD_DrawLine(10, 30, 310, 30);
    LCD_DrawLine(10, 60, 310, 60);
    LCD_DrawLine(10, 90, 310, 90);
    LCD_DrawLine(10, 119, 310, 119);
    LCD_DrawLine(10, 120, 310, 120);
    LCD_DrawLine(10, 121, 310, 121);
    LCD_DrawLine(10, 150, 310, 150);
    LCD_DrawLine(10, 180, 310, 180);
    LCD_DrawLine(10, 210, 310, 210);
}

void GUI_draw_frame(void)   //画框
{
//  LCD_Clear(WHITE);   //清屏
    LCD_Display_Dir(1);//横屏
    POINT_COLOR = RED;          //设置字体为红色

    LCD_DrawRectangle(10, 10, 310, 230);
}

//信号发生器 DAC
void GUI_scan_0(void)
{
    LCD_Display_Dir(1);//横屏
    tp_dev.scan(0); 	//多屏通用扫描
    if ((tp_dev.sta & 0x80))	//触摸屏被按下
    {
//		TP_Draw_Big_Point(tp_dev.x[0],tp_dev.y[0],BLUE);		//画图	   just for test
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(1,1) 正弦波
        {

        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(1,2) 左移
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(1,3) 上移
        {

        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(1,4) 水平挡
        {

        }
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(2,1) 锯齿波
        {

        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(2,2) 右移
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(2,3) 下移
        {

        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(2,4) 垂直挡
        {

        }
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(3,1) 三角波
        {

        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(3,2) 频率+
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(3,3) 幅度+
        {

        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(3,4) 直流+
        {

        }
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(4,1) 方波
        {

        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(4,2) 频率-
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(4,3) 幅度-
        {

        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(4,4) 直流-
        {

        }
    }
}

//示波器 ADC
void GUI_scan_1(void)
{
    LCD_Display_Dir(1);//横屏
    tp_dev.scan(0); 	//多屏通用扫描
    if ((tp_dev.sta & 0x80))	//触摸屏被按下
    {
//		TP_Draw_Big_Point(tp_dev.x[0],tp_dev.y[0],BLUE);		//画图 just for test
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(1,1) 锁定
        {

        }
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(1,2) 锁定类
        {
            GUI_change_Lock_phase();
        }
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(1,3) 电平升
        {
            GUI_Lock_up();
        }
        if ((tp_dev.x[0] > x0) && (tp_dev.x[0] < x1) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(1,4) 电平降
        {
            GUI_Lock_down();
        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(2,1) 左移
        {
            Auto_set();
        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(2,2) 右移
        {
            Auto_set();
        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(2,3) 时间+
        {
            ADC_Fr_dec();
        }
        if ((tp_dev.x[0] > x1) && (tp_dev.x[0] < x2) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(2,4) 时间-
        {
            ADC_Fr_plus();
        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(3,1) 上移
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(3,2) 下移
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(3,3) 幅度+
        {

        }
        if ((tp_dev.x[0] > x2) && (tp_dev.x[0] < x3) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(3,4) 幅度-
        {

        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y0) && (tp_dev.y[0] < y1))	//(4,1) gear0
        {
            ADC_change_gear(0);
        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y1) && (tp_dev.y[0] < y2))	//(4,2) gear1
        {
            ADC_change_gear(1);
        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y2) && (tp_dev.y[0] < y3))	//(4,3) gear2
        {
            ADC_change_gear(2);
        }
        if ((tp_dev.x[0] > x3) && (tp_dev.x[0] < x4) && (tp_dev.y[0] > y3) && (tp_dev.y[0] < y4))	//(4,4) gear3
        {
            ADC_change_gear(3);
        }
    }
}

//u16 i = 0;
//u8 flag = 0;
//u8 LeftorRight_Val = 0;
int UporDown_Val = 0;
//u8 AnyWaveTab[256] = {0};
//double DisplayCoefficient = 0.6;    //系数，最大 = 240/255
u16 Displacement = 0;//位移

/*
//正弦波
void GUI_draw_sin(void)
{
    POINT_COLOR = BLUE;         //设置字体为蓝色
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//横屏
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //清除上次波形
        LCD_DrawPoint(i + 10, ((sin_wave[i % 256] >> 4) * DisplayCoefficient + Displacement)); //画正弦波，正弦波形数据最大0xff，最小0x00,中间值0x80，要求中间值在图形正中间位置即y坐标=570，所以128+442=570
    }
    LeftorRight_Val = 0;                     //非移位状态清0
    UporDown_Val = 0;
    for (i = 0; i < 256; i++)                //存储当前波形数据到数组AnyWaveTab[]中
    {
        AnyWaveTab[i] = (sin_wave[i] >> 4);
    }
//    LED0 = (!LED0);
}

//锯齿波
void GUI_draw_triangle(void)
{
    POINT_COLOR = BLUE;         //设置字体为蓝色
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//横屏
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //清除上次波形
        LCD_DrawPoint(i + 10, ((triangle_wave[i % 256] >> 4) * DisplayCoefficient + Displacement)); //画正弦波，正弦波形数据最大0xff，最小0x00,中间值0x80，要求中间值在图形正中间位置即y坐标=570，所以128+442=570
    }
    LeftorRight_Val = 0;                     //非移位状态清0
    UporDown_Val = 0;
    for (i = 0; i < 256; i++)                //存储当前波形数据到数组AnyWaveTab[]中
    {
        AnyWaveTab[i] = (triangle_wave[i] >> 4);
    }
//    LED0 = (!LED0);
}

//三角波
void GUI_draw_sawtooth(void)
{
    POINT_COLOR = BLUE;         //设置字体为蓝色
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//横屏
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //清除上次波形
        LCD_DrawPoint(i + 10, ((sawtooth_wave[i % 256] >> 4) * DisplayCoefficient + Displacement)); //画正弦波，正弦波形数据最大0xff，最小0x00,中间值0x80，要求中间值在图形正中间位置即y坐标=570，所以128+442=570
    }
    LeftorRight_Val = 0;                     //非移位状态清0
    UporDown_Val = 0;
    for (i = 0; i < 256; i++)                //存储当前波形数据到数组AnyWaveTab[]中
    {
        AnyWaveTab[i] = (sawtooth_wave[i] >> 4);
    }
//    LED0 = (!LED0);
}

//方波
void GUI_draw_square(void)
{
    POINT_COLOR = BLUE;         //设置字体为蓝色
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//横屏
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //清除上次波形
        LCD_DrawPoint(i + 10, ((rectangular_wave[i % 256] >> 4) * DisplayCoefficient + Displacement)); //画正弦波，正弦波形数据最大0xff，最小0x00,中间值0x80，要求中间值在图形正中间位置即y坐标=570，所以128+442=570
    }
    LeftorRight_Val = 0;                     //非移位状态清0
    UporDown_Val = 0;
    for (i = 0; i < 256; i++)                //存储当前波形数据到数组AnyWaveTab[]中
    {
        AnyWaveTab[i] = (rectangular_wave[i] >> 4);
    }
//    LED0 = (!LED0);
}

//左移
void GUI_draw_left(void)
{
    POINT_COLOR = BLUE;         //设置字体为蓝色
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//横屏
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //清除上次波形
        if (((AnyWaveTab[(i + LeftorRight_Val + LeftorRight_Num) % 256] * DisplayCoefficient + Displacement + UporDown_Val) > 10) && ((AnyWaveTab[(i + LeftorRight_Val + LeftorRight_Num) % 256] * DisplayCoefficient + Displacement + UporDown_Val) < 230))
        {
            LCD_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val + LeftorRight_Num) % 256] * DisplayCoefficient + Displacement + UporDown_Val)); //画正弦波，正弦波形数据最大0xff，最小0x00,中间值0x80，要求中间值在图形正中间位置即y坐标=570，所以128+442=570
        }
    }
    LeftorRight_Val = LeftorRight_Val + LeftorRight_Num;
//    LED0 = (!LED0);
}

//右移
void GUI_draw_right(void)
{
    POINT_COLOR = BLUE;         //设置字体为红色
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//横屏
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //清除上次波形
        if (((AnyWaveTab[(i + LeftorRight_Val - LeftorRight_Num) % 256] * DisplayCoefficient + Displacement + UporDown_Val) > 10) && ((AnyWaveTab[(i + LeftorRight_Val - LeftorRight_Num) % 256] * DisplayCoefficient + Displacement + UporDown_Val) < 230))
        {
            LCD_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val - LeftorRight_Num) % 256] * DisplayCoefficient + Displacement + UporDown_Val)); //画正弦波，正弦波形数据最大0xff，最小0x00,中间值0x80，要求中间值在图形正中间位置即y坐标=570，所以128+442=570
        }
    }
    LeftorRight_Val = LeftorRight_Val - LeftorRight_Num;
//    LED0 = (!LED0);
}

//上移
void GUI_draw_up(void)
{
    POINT_COLOR = BLUE;         //设置字体为红色
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//横屏
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //清除上次波形
        if (((AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val - UporDown_Num) > 10) && ((AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val - UporDown_Num) < 230))
        {
            LCD_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val - UporDown_Num)); //画正弦波，正弦波形数据最大0xff，最小0x00,中间值0x80，要求中间值在图形正中间位置即y坐标=570，所以128+442=570
            flag = 1;
        }
    }
    if (flag)
    {
        UporDown_Val = UporDown_Val - UporDown_Num;
        flag = 0;
    }
//    LED0 = (!LED0);
}

//下移
void GUI_draw_down(void)
{
    POINT_COLOR = BLUE;         //设置字体为红色
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//横屏
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //清除上次波形
        if (((AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val + UporDown_Num) > 10) && ((AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val + UporDown_Num) < 230))
        {
            LCD_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val + UporDown_Num)); //画正弦波，正弦波形数据最大0xff，最小0x00,中间值0x80，要求中间值在图形正中间位置即y坐标=570，所以128+442=570
            flag = 1;
        }
    }
    if (flag)
    {
        UporDown_Val = UporDown_Val + UporDown_Num;
        flag = 0;
    }
//    LED0 = (!LED0);
}

//画当前波形
void GUI_draw_AnyWave(void)
{
    POINT_COLOR = BLUE;         //设置字体为蓝色
    Displacement = 120 - 128 * DisplayCoefficient;
    LCD_Display_Dir(1);//横屏
    for ( i = 0; i < 300; i++)
    {
        LCD_Fast_DrawPoint(i + 10, (AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val), WHITE); //清除上次波形
        if (((AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val + UporDown_Num) > 10) && ((AnyWaveTab[(i + LeftorRight_Val) % 256] * DisplayCoefficient + Displacement + UporDown_Val + UporDown_Num) < 230))
        {
            LCD_DrawPoint(i + 10, (AnyWaveTab[i % 256] * DisplayCoefficient + Displacement));
//          LCD_DrawPoint(i+10,(AnyWaveTab[(i + LeftorRight_Val)%256] * DisplayCoefficient + Displacement + UporDown_Val + UporDown_Num));  //画正弦波，正弦波形数据最大0xff，最小0x00,中间值0x80，要求中间值在图形正中间位置即y坐标=570，所以128+442=570
        }
    }
//    LED0 = (!LED0);
}
*/

//
//锁定相关的变量
u16 Lock_start_num = 0; //锁定后 波的起始位置
u16 Lock_value = 0x0800;        //锁定值     //just for test
u8 Lock_phase = 0;      //锁定的相位，0为上升，1为下降
u8 Lock_done = 0;       //锁定成功


//画ADC波形
u16 AdcWaveTab[300] = {0};
u8 lastAdcWaveValue = 0;
u8 currcetAdcWaveValue = 0;
void GUI_draw_AdcWave(void)
{
    uint16_t draw_adc_i = 0;
    if (UpdatTrue == 0xff)
    {
        UpdatTrue = 0;

        GUI_signal_processing();    //AD数据处理

        GUI_Lock(); //触发锁定

        LCD_Display_Dir(1);//横屏
        //画锁定位置
        POINT_COLOR = YELLOW;
        LCD_DrawLine(10, ((0xFFF - Lock_value) >> 4), 310, ((0xFFF - Lock_value) >> 4));

        POINT_COLOR = BLUE;         //设置字体为蓝色
        Displacement = 120 - 64;
        for ( draw_adc_i = 0; draw_adc_i < 300; draw_adc_i++)
        {
            lastAdcWaveValue = ((0xFFF - AdcWaveTab[draw_adc_i]) >> 4) * 200 / 256 + 20; //上次点幅度
            currcetAdcWaveValue = ((0xFFF - ADCConvertedValue[draw_adc_i + Lock_start_num]) >> 4) * 200 / 256 + 20; //上次点幅度

            LCD_Fast_DrawPoint(draw_adc_i + 10, lastAdcWaveValue, WHITE); //清除上次波形
            LCD_Fast_DrawPoint(draw_adc_i + 10, lastAdcWaveValue - 1, WHITE); //清除上次波形
            LCD_Fast_DrawPoint(draw_adc_i + 10, lastAdcWaveValue + 1, WHITE); //清除上次波形

            POINT_COLOR = BLUE;         //设置字体为蓝色
            LCD_DrawPoint(draw_adc_i + 10, currcetAdcWaveValue); //画波
            LCD_DrawPoint(draw_adc_i + 10, currcetAdcWaveValue - 1); //画波
            LCD_DrawPoint(draw_adc_i + 10, currcetAdcWaveValue + 1); //画波
            AdcWaveTab[draw_adc_i] = ADCConvertedValue[draw_adc_i + Lock_start_num];
        }

//        TIM_Cmd(TIM3, ENABLE);
//      for (draw_adc_i = 0; draw_adc_i < 256; draw_adc_i++)                //存储当前波形数据到数组AdcWaveTab[]中
//      {
//          AdcWaveTab[draw_adc_i] = ADCConvertedValue[draw_adc_i];
//      }
        // LED0 = (!LED0);
    }
}

//触发锁定
void GUI_Lock(void)
{
    uint16_t i = 0;
    Lock_done = 0;
    for ( i = 0; i < (SAMPDEPTH - 300); i++)
    {
        if (Lock_phase == 0)    //上升
        {
            if ((ADCConvertedValue[i] <= (Lock_value + 1)) && (ADCConvertedValue[i + 1] <= (Lock_value + 1)))
            {
                if ((ADCConvertedValue[i + 2] >= (Lock_value - 1)) && (ADCConvertedValue[i + 3] >= (Lock_value - 1)))
                {
                    Lock_start_num = i + 1;
                    Lock_done = 1;
                    break;
                }
            }
        }
        else
        {
            if ((ADCConvertedValue[i] >= (Lock_value - 1)) && (ADCConvertedValue[i + 1] >= (Lock_value - 1)))
            {
                if ((ADCConvertedValue[i + 2] <= (Lock_value + 1)) && (ADCConvertedValue[i + 3] <= (Lock_value + 1)))
                {
                    Lock_start_num = i + 1;
                    Lock_done = 1;
                    break;
                }
            }
        }
    }
    if (Lock_done == 0)
    {
        Lock_start_num = 0;
    }
    // printf("%d\n", Lock_start_num);
    if (Lock_start_num == 0)
    {
        printf("lock failed!\n");
    }
    else if (Lock_start_num > 300)
    {
        printf("error!\n");
    }
}

void GUI_Lock_up(void)
{
    //清除定位置
    LCD_Display_Dir(1);//横屏
    POINT_COLOR = WHITE;
    LCD_DrawLine(10, ((0xFFF - Lock_value) >> 4), 310, ((0xFFF - Lock_value) >> 4));

    Lock_value += 10;
}

void GUI_Lock_down(void)
{
    //清除定位置
    LCD_Display_Dir(1);//横屏
    POINT_COLOR = WHITE;
    LCD_DrawLine(10, ((0xFFF - Lock_value) >> 4), 310, ((0xFFF - Lock_value) >> 4));

    Lock_value -= 10;
}

void GUI_change_Lock_phase(void)
{
    if (Lock_phase == 1)
    {
        Lock_phase = 0;
    }
    else if (Lock_phase == 0)
    {
        Lock_phase = 1;
    }
    else
    {
        Lock_phase = 0;
    }
}


extern u32 FreqExtCounter;
extern u32 FreqVal;
extern u32 FreqVal1;
extern u8 refresh_flag;	//定义在timer.h

u16 cYmax=0;  //最大值
u16 cYmin=3.3;  //最小值
u16 cYavr;  //中值
float ADmax;
float ADmin;
float ADmen;
float ADcycle;	//周期
//u16 ADCConvertedValue_new[SAMPDEPTH];
float DCmV3 = 0, freq3 = 0, cycle3 = 0, phase3 = 0, scope3 = 0; //参数

u8 *lp; //字符串
u8 callbuf[33];
u8 max_flag=0;
void GUI_signal_processing(void)
{
    //AD采样数据处理
    u16  k, cY1 = 0, cY2 = 0;
	u16 cYmax1, cYmax2, cYmax3;
	u16 cYmin1, cYmin2, cYmin3;
max_flag=1;
    for (k = 1; k < SAMPDEPTH; k++) {
        ADCConvertedValue[k] = (ADCConvertedValue[k] + ADCConvertedValue[k - 1]) / 2;   //平均滤波
    }
    cYmax = ADCConvertedValue[0];
    cYmin = ADCConvertedValue[0];
    for (k = 0; k < SAMPDEPTH; k++) {
        if (cYmax <= ADCConvertedValue[k])	cYmax = ADCConvertedValue[k];  //求数据的最大值
        if (cYmin >= ADCConvertedValue[k])  cYmin = ADCConvertedValue[k];  //求数据的最小值
    }
	
    cY2 = cY1;
    cY1 = cYmin + (cYmax - cYmin) / 2;
    cYavr = (cY1 + cY2) / 2;     		//求出数据的平均值

    ADmax = (float)(cYmax * 3300.0) / (4096.0); //mVp 最大值
    ADmin = (float)(cYmin * 3300.0) / (4096.0); //mVp 最小值
    ADmen = (float)(cYavr * 3300.0) / (4096.0); //mVp 平均值
    ADcycle = (float)(1000000.0 / FreqVal);

//	printf("max = %6.2f, min = %6.1f, men = %6.1f\n", ADmax, ADmin, ADmen);	//just for test

	/*
///////////////////////////////////////////////////////////////////////////////
////求最大值，最小值，峰峰值
////一次运算
///////////////////////////////////////////////////////////////////////////////
    cYmax1 = ADCConvertedValue[0];
    cYmin1 = ADCConvertedValue[0];
	for(k = 0; k < 512; k++){
        if (cYmax1 <= ADCConvertedValue[k])	cYmax1 = ADCConvertedValue[k];  //求数据的最大值
        if (cYmin1 >= ADCConvertedValue[k])  cYmin1 = ADCConvertedValue[k];  //求数据的最小值
	}
	
///////////////////////////////////////////////////////////////////////////////
////求最大值，最小值，峰峰值
////二次运算
///////////////////////////////////////////////////////////////////////////////
    cYmax2 = ADCConvertedValue[256];
    cYmin2 = ADCConvertedValue[256];
	for(k = 256; k < 768; k++){
        if (cYmax2 <= ADCConvertedValue[k])	cYmax2 = ADCConvertedValue[k];  //求数据的最大值
        if (cYmin2 >= ADCConvertedValue[k])  cYmin2 = ADCConvertedValue[k];  //求数据的最小值
	}	
	
///////////////////////////////////////////////////////////////////////////////
////求最大值，最小值，峰峰值
////三次运算
///////////////////////////////////////////////////////////////////////////////
    cYmax3 = ADCConvertedValue[512];
    cYmin3 = ADCConvertedValue[512];
	for(k = 512; k < 1024; k++){
        if (cYmax3 <= ADCConvertedValue[k])	cYmax3 = ADCConvertedValue[k];  //求数据的最大值
        if (cYmin3 >= ADCConvertedValue[k])  cYmin3 = ADCConvertedValue[k];  //求数据的最小值
	}
	
///////////////////////////////////////////////////////////////////////////////
////求最大值，最小值，峰峰值
////三次运算的值作比较
///////////////////////////////////////////////////////////////////////////////
	if ((fabs(cYmax2 - cYmax1) / cYmax1) <= 0.002)	//2
    {
		cYmax = (cYmax1/2) + (cYmax2/2);
//		cYmax = cYmax1;
    } else if ((fabs(cYmax3 - cYmax2) / cYmax2) <= 0.002)	//1
    {
		cYmax = (cYmax3/2) + (cYmax2/2);
//		cYmax = cYmax2;
    } else if ((fabs(cYmax1 - cYmax3) / cYmax3) <= 0.002)	//2
    {
		cYmax = (cYmax1/2) + (cYmax3/2);
//		cYmax = cYmax3;
    }
	
	if ((fabs(cYmin2 - cYmin1) / cYmin1) <= 0.002)	//2
    {
		cYmin = (cYmin1/2) + (cYmin2/2);
    } else if ((fabs(cYmin3 - cYmin2) / cYmin2) <= 0.002)	//1
    {
		cYmin = (cYmin3/2) + (cYmin2/2);
    } else if ((fabs(cYmin1 - cYmin3) / cYmin3) <= 0.002)	//2
    {
		cYmin = (cYmin1/2) + (cYmin3/2);
    }
		
    cY2 = cY1;
    cY1 = cYmin + (cYmax - cYmin) / 2;
    cYavr = (cY1 + cY2) / 2;     		//求出数据的平均值
	
	printf("max = %d, min = %6d, men = %d\r\n", cYmax, cYmin, cYavr);	//just for test
	
    ADmax = (float)(cYmax * 3300.0) / (4096.0); //mVp 最大值
    ADmin = (float)(cYmin * 3300.0) / (4096.0); //mVp 最小值
    ADmen = (float)(cYavr * 3300.0) / (4096.0); //mVp 平均值
    ADcycle = (float)(1000000.0 / FreqVal);

*/
//	printf("max = %6.2f, min = %6.1f, men = %6.1f\n", ADmax, ADmin, ADmen);	//just for test
	
//		LCD_ShowxNum(165, 34 + 28 * 0, cYmax, 6, 16, 0); //显示Ymax
//		LCD_ShowxNum(165, 34 + 28 * 1, cYavr, 6, 16, 0); //显示Ymid

///////////////////////////////////////////////////////////////////////////////
////求参数，求周期、频率等参数
///////////////////////////////////////////////////////////////////////////////

//    //限幅放大，把正弦波放大成方波
//    for (t = 0; t < SAMPDEPTH; t++)
//        if (ADCConvertedValue[t] >= cYavr) {
//            ADCConvertedValue_new[t] = 2048;
//        }
//        else {
//            ADCConvertedValue_new[t] = 1024;
//        }
//    //求信号的过0相位点
//    for (t = 0; t < SAMPDEPTH; t++) //求频率
//        if ((ADCConvertedValue_new[t] == 1024) & (ADCConvertedValue_new[t + 1] == 2048)) {
//            eK = t + 1;    //0相位点（上升点）
//            break;
//        }
//    for (t = eK + 1; t < SAMPDEPTH; t++)
//        if ((ADCConvertedValue_new[t] == 2048) & (ADCConvertedValue_new[t + 1] == 1024)) {
//            bK = t + 1;    //180度点（下降点）
//            break;
//        }
//    for (t = bK + 1; t < SAMPDEPTH; t++)
//        if ((ADCConvertedValue_new[t] == 1024) & (ADCConvertedValue_new[t + 1] == 2048)) {
//            cK = t + 1;    //360度点=0度点（上升点）
//            break;
//        }
//    //求触发相位点，重eK到触发电平点的相位差
//    if ((Lock_value <= cYmax) & (Lock_value >= cYmin))
//    {
//        if (Lock_phase == 0) //上升触发
//        {
//            for (t = eK + 1; t < SAMPDEPTH; t++)
//                if ((ADCConvertedValue[t] <= Lock_value) & (ADCConvertedValue[t + 1] >= Lock_value)) {
//                    dK = t;
//                    break;
//                }
//        } else //下降触发
//            for (t = eK + 1; t < SAMPDEPTH; t++)
//                if ((ADCConvertedValue[t] >= Lock_value) & (ADCConvertedValue[t + 1] <= Lock_value)) {
//                    dK = t;
//                    break;
//                }
//    } else dK = eK;
///////////////////////////////////////////////////////////////////////////////////////
////参数计算，周期、频率等参数，需要采用浮点运算
//////////////////////////////////////////////////////////////////////////////////////
//    cycle = (float)(1000.0 * (float)(cK - eK) * (arr_ADC) * (psc_ADC) / (72 * 1000.0)); //T=(arr+1)(psc+1)/72 us
//    freq = (1000000 * 1000 / (float)cycle) / 1000; //Hz
//    phase = (float)(360 * (float)fabs((float)(dK - eK) * 1000 / (cK - eK))) / 1000;
//    scope = (float)((cYmax - cYmin) * 3300) / (2 * 4096); //mVp
//    DCmV = (float)((cYavr) * 3300) / (2 * 4096); //mVp

////二次求解

//    //求信号的过0相位点
//    for (t = 200; t < SAMPDEPTH; t++) //求频率
//        if ((ADCConvertedValue_new[t] == 1024) & (ADCConvertedValue_new[t + 1] == 2048)) {
//            eK = t + 1;    //0相位点（上升点）
//            break;
//        }
//    for (t = eK + 1; t < SAMPDEPTH; t++)
//        if ((ADCConvertedValue_new[t] == 2048) & (ADCConvertedValue_new[t + 1] == 1024)) {
//            bK = t + 1;    //180度点（下降点）
//            break;
//        }
//    for (t = bK + 1; t < SAMPDEPTH; t++)
//        if ((ADCConvertedValue_new[t] == 1024) & (ADCConvertedValue_new[t + 1] == 2048)) {
//            cK = t + 1;    //360度点=0度点（上升点）
//            break;
//        }
//    //求触发相位点，重eK到触发电平点的相位差
//    if ((Lock_value <= cYmax) & (Lock_value >= cYmin))
//    {
//        if (Lock_phase == 0) //上升触发
//        {
//            for (t = eK + 1; t < SAMPDEPTH; t++)
//                if ((ADCConvertedValue[t] <= Lock_value) & (ADCConvertedValue[t + 1] >= Lock_value)) {
//                    dK = t;
//                    break;
//                }
//        } else //下降触发
//            for (t = eK + 1; t < SAMPDEPTH; t++)
//                if ((ADCConvertedValue[t] >= Lock_value) & (ADCConvertedValue[t + 1] <= Lock_value)) {
//                    dK = t;
//                    break;
//                }
//    } else dK = eK;
///////////////////////////////////////////////////////////////////////////////////////
////参数计算，周期、频率等参数，需要采用浮点运算
//////////////////////////////////////////////////////////////////////////////////////
//    cycle1 = (float)(1000.0 * (float)(cK - eK) * (arr_ADC) * (psc_ADC) / (72 * 1000.0)); //T=(arr+1)(psc+1)/72 us
//    freq1 = (1000000 * 1000 / (float)cycle1) / 1000.0; //Hz
//    phase1 = (float)(360 * (float)fabs((float)(dK - eK) * 1000 / (cK - eK))) / 1000;
//    scope1 = (float)((cYmax - cYmin) * 3300) / (4096); //mVp
//    DCmV1 = (float)((cYavr) * 3300) / (4096); //mVp

////三次求解

//    //求信号的过0相位点
//    for (t = 400; t < SAMPDEPTH; t++) //求频率
//        if ((ADCConvertedValue_new[t] == 1024) & (ADCConvertedValue_new[t + 1] == 2048)) {
//            eK = t + 1;    //0相位点（上升点）
//            break;
//        }
//    for (t = eK + 1; t < SAMPDEPTH; t++)
//        if ((ADCConvertedValue_new[t] == 2048) & (ADCConvertedValue_new[t + 1] == 1024)) {
//            bK = t + 1;    //180度点（下降点）
//            break;
//        }
//    for (t = bK + 1; t < SAMPDEPTH; t++)
//        if ((ADCConvertedValue_new[t] == 1024) & (ADCConvertedValue_new[t + 1] == 2048)) {
//            cK = t + 1;    //360度点=0度点（上升点）
//            break;
//        }
//    //求触发相位点，重eK到触发电平点的相位差
//    if ((Lock_value <= cYmax) & (Lock_value >= cYmin))
//    {
//        if (Lock_phase == 0) //上升触发
//        {
//            for (t = eK + 1; t < SAMPDEPTH; t++)
//                if ((ADCConvertedValue[t] <= Lock_value) & (ADCConvertedValue[t + 1] >= Lock_value)) {
//                    dK = t;
//                    break;
//                }
//        } else //下降触发
//            for (t = eK + 1; t < SAMPDEPTH; t++)
//                if ((ADCConvertedValue[t] >= Lock_value) & (ADCConvertedValue[t + 1] <= Lock_value)) {
//                    dK = t;
//                    break;
//                }
//    } else dK = eK;
///////////////////////////////////////////////////////////////////////////////////////
////参数计算，周期、频率等参数，需要采用浮点运算，参数稳定处理
//////////////////////////////////////////////////////////////////////////////////////
//    cycle2 = (float)(1000 * (float)(cK - eK) * (arr_ADC) * (psc_ADC) / (72 * 1000)); //T=(arr+1)(psc+1)/72 us
//    freq2 = (1000000 * 1000 / (float)cycle2) / 1000; //Hz
//    phase2 = (float)(360 * (float)fabs((float)(dK - eK) * 1000 / (cK - eK))) / 1000;
//    scope2 = (float)((cYmax - cYmin) * 3300) / (2 * 4096); //mVp
//    DCmV2 = (float)((cYavr) * 3300) / (2 * 4096); //mVp

//    if ((fabs(cycle1 - cycle) / cycle) <= 0.002)
//    {
//        cycle3 = cycle; //us
//        freq3 = freq; //Hz
//    } else if ((fabs(cycle2 - cycle) / cycle2) <= 0.002)
//    {
//        cycle3 = cycle2; //us
//        freq3 = freq2; //Hz
//    } else if ((fabs(cycle2 - cycle1) / cycle1) <= 0.002)
//    {
//        cycle3 = cycle1; //us
//        freq3 = freq1; //Hz
//    }
//    if ((fabs(phase1 - phase) / phase) <= 0.002)
//    {
//        phase3 = phase; //度
//    } else if ((fabs(phase2 - phase) / phase2) <= 0.002)
//    {
//        phase3 = phase2; //度
//    } else if ((fabs(phase2 - phase1) / phase1) <= 0.002)
//    {
//        phase3 = phase1; //度
//    }
//    scope3 = scope1; //mVp
//    DCmV3 = DCmV1; //mVp
}

extern float av;
void GUI_show_signal(void)
{
	float vpp;
    u32 temp = 0;
    lp = callbuf;

    if(refresh_flag) {
        refresh_flag = 0;

        POINT_COLOR = BLACK;
//		LCD_ShowxNum(165, 34 + 28 * 0, cYmax, 6, 16, 0); //显示Ymax
//		LCD_ShowxNum(165, 34 + 28 * 1, cYavr, 6, 16, 0); //显示Ymid
//		LCD_ShowxNum(20, 34 + 28 * 2, cYmin, 6, 16, 0); //显示Ymin

        Show_Str(15, 40 + 28 * 0, 60, 16, "频  率", 16, 1);
        //Show_Str(15, 40 + 28 * 1, 60, 16, "周  期", 16, 1);
        //Show_Str(15, 40 + 28 * 2, 60, 16, "最大值", 16, 1);
        //Show_Str(15, 40 + 28 * 3, 60, 16, "最小值", 16, 1);
        Show_Str(15, 40 + 28 * 4, 60, 16, "电流峰峰值", 16, 1);

        LCD_Fill(70, 40 + 28 * 0, 70 + 100, 40 + 28 * 0 + 24, WHITE); //显示频率
        sprintf((char*)lp, "%6.1f Hz", (float)FreqVal);
        Show_Str(70, 40 + 28 * 0, 100, 16, lp, 16, 1);

       /* LCD_Fill(70, 40 + 28 * 1, 70 + 100, 40 + 28 * 1 + 24, WHITE); //显示周期
        sprintf((char*)lp, "%6.1f us", ADcycle);
        Show_Str(70, 40 + 28 * 1, 100, 16, lp, 16, 1);

        LCD_Fill(70, 40 + 28 * 2, 70 + 100, 40 + 28 * 2 + 24, WHITE); //显示最大值
        sprintf((char*)lp, "%6.1f mVp", ADmax);
        Show_Str(70, 40 + 28 * 2, 100, 16, lp, 16, 1);

        LCD_Fill(70, 40 + 28 * 3, 70 + 100, 40 + 28 * 3 + 24, WHITE); //显示最小值
        sprintf((char*)lp, "%6.1f mVp", ADmin);
        Show_Str(70, 40 + 28 * 3, 100, 16, lp, 16, 1);*/
vpp=ADmax-ADmin;
vpp=(2.93*0.002189*vpp-0.00421*FreqVal)*0.066;
        LCD_Fill(70, 40 + 28 * 4, 70 + 100, 40 + 28 * 4 + 24, WHITE); //显示峰峰值
        sprintf((char*)lp, "%6.1f A", vpp);
        Show_Str(70, 40 + 28 * 4, 100, 16, lp, 16, 1);


        ////////////////////////////////////////////////////////////////////
        ////脉冲宽度测量（高电平）由T5做脉宽捕获，串口输出脉宽
        ////////////////////////////////////////////////////////////////////
        if(TIM5CH1_CAPTURE_STA & 0X80) //成功捕获到了一次上升沿
        {
            temp = TIM5CH1_CAPTURE_STA & 0X3F;
            temp *= 65536; //溢出时间总和
            temp += TIM5CH1_CAPTURE_VAL; //得到总的高电平时间

            TIM5CH1_CAPTURE_STA = 0; //开启下一次捕获
        }
        /////////////////////////////////////////////////////////////////////
        ////数据显示，频率，整周期，尾数，脉宽
        ////////////////////////////////////////////////////////////////////

//		LCD_Fill(150, 34 + 28 * 0, 150 + 200, 34 + 28 * 0 + 24, WHITE); //显示频率
//		sprintf((char*)lp, "Frequence%6dHz", FreqVal);
//		Show_Str(150, 34 + 28 * 0, 150, 16, lp, 16, 1);

//		LCD_ShowNum(180, 34 + 28 * 0, FreqVal, 9, 16);
//		LCD_ShowNum(180, 34 + 28 * 1, FreqExtCounter, 9, 16);
//		LCD_ShowNum(180, 34 + 28 * 2, FreqVal1, 9, 16);
//		LCD_ShowNum(180, 34 + 28 * 3, temp + 2, 9, 16);
    }
}


u16 LCDout_sta = 0, LCD_data = 0;
u16 LCDout1[300];//数据输出缓冲器1
u16 LCDout2[300];//数据输出缓冲器2
u16 aX = 9, bX = 128, aY = 5, bY = 0, cY = 110; //X为水平控制，Y为垂直控制,a为幅度控制（放大系数），b为相位控制（1：左移，0：右移）,c是幅度平均值
//u8 LCD_n = 0; //显示跟新选择
float fstep_pixel = 0; 	//每两个像素之间的频率差	采样频率/1024
u16 fstep_grid = 0;		//每两格之间的频率差        fstep_pixel * 30
//FFT处理，并发送数据到usart1,
void GUI_show_FFT(void) {

    uint16_t show_fft_i = 0;
    if (UpdatTrue == 0xff)
    {
		UpdatTrue = 0;
        GUI_signal_processing();    //AD数据处理
		GUI_fft_harmonic();			//计算谐波
        for(show_fft_i = 0; show_fft_i < 1024; show_fft_i++)
        {
            input[2 * show_fft_i] = ADCConvertedValue[show_fft_i]; //生成输入信号实部
            input[2 * show_fft_i + 1] = 0; //虚部全部为0
        }
        cr4_fft_1024_stm32(output, input, 1024);

        /* 求幅值 */
        PowerMag(1024);
//			arm_cfft_radix4_f32(&scfft,fft_inputbuf);	//FFT计算（基4）
//			arm_cmplx_mag_f32(fft_inputbuf,fft_outputbuf,FFT_LENGTH);	//把运算结果复数求模得幅值
        /* 打印输出结果 */
//        printf("FFT Result:\r\n");
//        for (show_fft_i = 0; show_fft_i < 1024; show_fft_i++)
//        {
//            printf("fft_outputbuf[%d]:%6.2f\r\n", show_fft_i, Mag[show_fft_i]);
//        }
		
		
		GUI_fft_harmonic();			//计算谐波

        for(show_fft_i = 0; show_fft_i < 300; show_fft_i++) //装载一幀LCD数据
        {
            LCD_data = Mag[show_fft_i];
            LCD_data = (LCD_data >> 2); // + bY
            if((LCD_data) >= 224 - 28) LCD_data = 224 - 28; //总幅度不能>224,bY每格=8
            LCDout1[show_fft_i] = LCD_data;
            //        if((LCDout_sta + 1) % 2 == 0)LCDout1[show_fft_i] = LCD_data; //偶数存LCDout1
            //        else LCDout2[show_fft_i] = LCD_data;
            /*
            	t++;
            	if(aX!=1)//插值处理
            		{
            		for(show_fft_i=1;show_fft_i<aX;show_fft_i++)
            			{
            			if(ADCin2[k+1]>=ADCin2[k]){LCD_data=ADCin2[k]+((ADCin2[k+1]-ADCin2[k])*show_fft_i/aX);}  //A[K+1]>A[K]
            			else                      {LCD_data=ADCin2[k]-((ADCin2[k]-ADCin2[k+1])*show_fft_i/aX);}   //A[K+1]<A[K]
            			LCD_data=LCD_data+bY;
            			if((LCD_data)>=360)LCD_data=359;  //总幅度不能>360,bY每格=10
            			if((LCDout_sta+1)%2==0)LCDout1[t]=LCD_data;  //偶数存LCDout1
            			else LCDout2[t]=LCD_data;
            			t++;
            			}
            		}
            	k++;
            */
        }

        //    LCD_Clear(WHITE);
        //    LCDout_sta++;//内存数块交换

            for(show_fft_i = 0; show_fft_i < 300; ++show_fft_i) //显示LCD数据
            {
                //清除前一次波形
                POINT_COLOR = WHITE;
                LCD_DrawLine(10 + show_fft_i, (230 - 20) - LCDout2[show_fft_i], 10 + show_fft_i, 230 - 20); //到780的竖线
                //画当前波形
                POINT_COLOR = BLUE;
                LCD_DrawLine(10 + show_fft_i, (230 - 20) - LCDout1[show_fft_i], 10 + show_fft_i, 230 - 20); //到780的竖线
                //将当前波形存入LCDout2
                LCDout2[show_fft_i] = LCDout1[show_fft_i];
            }


    }
}

//计算谐波
u8 FrcErrorValue = 5;
//u32 wave_value_0 = 0;	//
u32 wave_value_1 = 0;	//基波
u32 wave_value_2 = 0;	//二次谐波
u32 wave_value_3 = 0;	//三次谐波
u32 wave_value_4 = 0;	//四次谐波
u32 wave_value_5 = 0;	//五次谐波
u32 wave_value_6 = 0;	//六次谐波
u32 wave_value_7 = 0;	//七次谐波
u32 wave_value_8 = 0;	//八次谐波
u32 wave_value_9 = 0;	//九次谐波
float V_value_1 = 0;	//基波
float V_value_2 = 0;	//二次谐波
float V_value_3 = 0;	//三次谐波
float V_value_4 = 0;	//四次谐波
float V_value_5 = 0;	//五次谐波
float V_value_6 = 0;	//六次谐波
float V_value_7 = 0;	//七次谐波
float V_value_8 = 0;	//八次谐波
float V_value_9 = 0;	//九次谐波
void GUI_fft_harmonic(void){
//	uint32_t Mag[] 幅值
//	u32 FreqVal		频率
    //计算刻度
    fstep_pixel = ADC_Fr / 512.0;	//每两个像素之间的频率差 ADC_Fr / 1024
    fstep_grid = fstep_pixel * 30; //每两格之间的频率差
//    printf("fstep_pixel = %f, fstep_grid = %d\n", fstep_pixel, fstep_grid);	//just for test
	wave_value_1 = FFT_FindMax(FreqVal,FrcErrorValue);
	wave_value_2 = FFT_FindMax(FreqVal*2,FrcErrorValue);
	wave_value_3 = FFT_FindMax(FreqVal*3,FrcErrorValue);
	wave_value_4 = FFT_FindMax(FreqVal*4,FrcErrorValue);
	wave_value_5 = FFT_FindMax(FreqVal*5,FrcErrorValue);
	wave_value_6 = FFT_FindMax(FreqVal*6,FrcErrorValue);
	wave_value_7 = FFT_FindMax(FreqVal*7,FrcErrorValue);
	wave_value_8 = FFT_FindMax(FreqVal*8,FrcErrorValue);
	wave_value_9 = FFT_FindMax(FreqVal*9,FrcErrorValue);
	V_value_1 = wave_value_1 * 3300.0 / 1024.0;
	V_value_2 = wave_value_2 * 3300.0 / 1024.0;
	V_value_3 = wave_value_3 * 3300.0 / 1024.0;
	V_value_4 = wave_value_4 * 3300.0 / 1024.0;
	V_value_5 = wave_value_5 * 3300.0 / 1024.0;
	V_value_6 = wave_value_6 * 3300.0 / 1024.0;
	V_value_7 = wave_value_7 * 3300.0 / 1024.0;
	V_value_8 = wave_value_8 * 3300.0 / 1024.0;
	V_value_9 = wave_value_9 * 3300.0 / 1024.0;
//	printf("value_1 = %d,value_2 = %d,value_3 = %d,value_4 = %d\r\n",wave_value_1,wave_value_2,wave_value_3,wave_value_4);
}

//计算一个范围内的最大值
uint32_t FFT_FindMax(u32 Frc, u8 error){
	uint32_t max_value = 0;
	u16 loop_i = 0;
	u16 frc_value = 0;
	u16 start_num = 0;
	u16 end_num = 0;
	
	frc_value = Frc * 512.0/ ADC_Fr;
	
	
	
	start_num = frc_value - error;
	end_num = frc_value + error;
	for(loop_i = start_num; loop_i <= end_num; loop_i++){
		if(Mag[loop_i] > max_value){
			max_value = Mag[loop_i];
		}
	}
	return max_value;
}

void GUI_show_fft_value(void) {
//    u32 temp = 0;
    lp = callbuf;

	
    if(refresh_flag) {
        refresh_flag = 0;

        POINT_COLOR = BLACK;


//        Show_Str(10, 32 + 30 * 0, 80, 16, "基    波", 16, 1);
//        LCD_Fill(75, 32 + 30 * 0, 75 + 100, 32 + 30 * 0 + 24, WHITE); //显示基    波
//        sprintf((char*)lp, "%6d mVp", wave_value_1);
//        Show_Str(75, 32 + 30 * 0, 100, 16, lp, 16, 1);

        Show_Str(10, 32 + 30 * 1, 80, 16, "二次谐波", 16, 1);
        LCD_Fill(75, 32 + 30 * 1, 75 + 100, 32 + 30 * 1 + 24, WHITE); //显示二次谐波
        sprintf((char*)lp, "%6.1f mVp", V_value_2);
        Show_Str(75, 32 + 30 * 1, 100, 16, lp, 16, 1);

        Show_Str(10, 32 + 30 * 2, 80, 16, "四次谐波", 16, 1);
        LCD_Fill(75, 32 + 30 * 2, 75 + 100, 32 + 30 * 2 + 24, WHITE); //显示四次谐波
        sprintf((char*)lp, "%6.1f mVp", V_value_4);
        Show_Str(75, 32 + 30 * 2, 100, 16, lp, 16, 1);

        Show_Str(10, 32 + 30 * 3, 80, 16, "四次谐波", 16, 1);
        LCD_Fill(75, 32 + 30 * 3, 75 + 100, 32 + 30 * 3 + 24, WHITE); //显示六次谐波
        sprintf((char*)lp, "%6.1f mVp", V_value_6);
        Show_Str(75, 32 + 30 * 3, 100, 16, lp, 16, 1);

        Show_Str(10, 32 + 30 * 4, 80, 16, "六次谐波", 16, 1);
        LCD_Fill(75, 32 + 30 * 4, 75 + 100, 32 + 30 * 4 + 24, WHITE); //显示八次谐波
        sprintf((char*)lp, "%6.1f mVp", V_value_8);
        Show_Str(75, 32 + 30 * 4, 100, 16, lp, 16, 1);
		
		
        Show_Str(165, 32 + 30 * 0, 80, 16, "基    波", 16, 1);
        LCD_Fill(230, 32 + 30 * 0, 230 + 100, 32 + 30 * 0 + 24, WHITE); //显示基    波
        sprintf((char*)lp, "%6.1f mVp", V_value_1);
        Show_Str(230, 32 + 30 * 0, 100, 16, lp, 16, 1);

        Show_Str(165, 32 + 30 * 1, 80, 16, "三次谐波", 16, 1);
        LCD_Fill(230, 32 + 30 * 1, 230 + 100, 32 + 30 * 1 + 24, WHITE); //显示三次谐波
        sprintf((char*)lp, "%6.1f mVp", V_value_3);
        Show_Str(230, 32 + 30 * 1, 100, 16, lp, 16, 1);

        Show_Str(165, 32 + 30 * 2, 80, 16, "五次谐波", 16, 1);
        LCD_Fill(230, 32 + 30 * 2, 230 + 100, 32 + 30 * 2 + 24, WHITE); //显示五次谐波
        sprintf((char*)lp, "%6.1f mVp", V_value_5);
        Show_Str(230, 32 + 30 * 2, 100, 16, lp, 16, 1);

        Show_Str(165, 32 + 30 * 3, 80, 16, "七次谐波", 16, 1);
        LCD_Fill(230, 32 + 30 * 3, 230 + 100, 32 + 30 * 3 + 24, WHITE); //显示七次谐波
        sprintf((char*)lp, "%6.1f mVp", V_value_7);
        Show_Str(230, 32 + 30 * 3, 100, 16, lp, 16, 1);

        Show_Str(165, 32 + 30 * 4, 80, 16, "九次谐波", 16, 1);
        LCD_Fill(230, 32 + 30 * 4, 230 + 100, 32 + 30 * 4 + 24, WHITE); //显示九次谐波
        sprintf((char*)lp, "%6.1f mVp", V_value_9);
        Show_Str(230, 32 + 30 * 4, 100, 16, lp, 16, 1);
		
		//显示刻度
        LCD_Fill(10, 210, 10 + 120, 210 + 24, WHITE);
        sprintf((char*)lp, "%6d Hz/div", fstep_grid);
        Show_Str(10, 210, 120, 16, lp, 16, 1);
    }


}

void Auto_set (void) {

    //自动锁定
    LCD_Display_Dir(1);//横屏
    POINT_COLOR = WHITE;
    LCD_DrawLine(10, ((0xFFF - Lock_value) >> 4), 310, ((0xFFF - Lock_value) >> 4));
    Lock_value = cYmin/2 + cYmax/2;// + cYmin

    if(state_flag == 0 || state_flag == 1) {
        ADC_Fr = FreqVal * 16;
        ADC_Change_Fr(ADC_Fr);
    }
    else if(state_flag == 2 || state_flag == 3) {
        ADC_Fr = FreqVal * 200;
        ADC_Change_Fr(ADC_Fr);
    }
}
