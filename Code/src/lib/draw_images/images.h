#ifndef IMAGES_H__
#define IMAGES_H__

#include <stdint.h>
#include <stdbool.h>

#define C_W_R	255
#define C_W_G	235
#define C_W_B	212
#define C_Y_R	255
#define C_Y_G	235
#define C_Y_B	0
#define BLACK	0

//uint8_t superMario[16][3][18] = {
//	{
//		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},		//RED
//		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},		//GREEN
//		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//BLUE
//	},
//	{
//		{0, 0, 0, 0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},		//RED
//		{0, 0, 0, 0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},		//GREEN
//		{0, 0, 0, 0, 0, 0, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//BLUE
//	},
//};

uint8_t smileSunGlass [17][3][18] =
{
	{//white
		{C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R},		//RED
		{C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G},		//GREEN
		{C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B}		//BLUE
	},
	{//0
		{C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, BLACK, BLACK, BLACK, BLACK, BLACK, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R},		//RED
		{C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, BLACK, BLACK, BLACK, BLACK, BLACK, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G},		//GREEN
		{C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, BLACK, BLACK, BLACK, BLACK, BLACK, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B}		//BLUE
	},
	{//1
		{C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, BLACK, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, BLACK, BLACK, C_W_R, C_W_R, C_W_R, C_W_R},		//RED
		{C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, BLACK, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, BLACK, BLACK, C_W_G, C_W_G, C_W_G, C_W_G},		//GREEN
		{C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, BLACK, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, BLACK, BLACK, C_W_B, C_W_B, C_W_B, C_W_B},		//BLUE
	},
	{//2
		{C_W_R, C_W_R, C_W_R, C_W_R, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, BLACK, BLACK, C_Y_R, C_Y_R, BLACK, C_W_R, C_W_R, C_W_R},		//RED
		{C_W_G, C_W_G, C_W_G, C_W_G, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, BLACK, BLACK, C_Y_G, C_Y_G, BLACK, C_W_G, C_W_G, C_W_G},		//GREEN
		{C_W_B, C_W_B, C_W_B, C_W_B, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, BLACK, BLACK, C_Y_B, C_Y_B, BLACK, C_W_B, C_W_B, C_W_B},		//BLUE
	},
	{//3
		{C_W_R, C_W_R, C_W_R, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, C_W_R, C_W_R, BLACK, C_Y_R, C_Y_R, C_Y_R, BLACK, C_W_R, C_W_R},		//RED
		{C_W_G, C_W_G, C_W_G, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, C_W_G, C_W_G, BLACK, C_Y_G, C_Y_G, C_Y_G, BLACK, C_W_G, C_W_G},		//GREEN
		{C_W_B, C_W_B, C_W_B, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, C_W_B, C_W_B, BLACK, C_Y_B, C_Y_B, C_Y_B, BLACK, C_W_B, C_W_B},		//BLUE
	},
	{//4
		{C_W_R, C_W_R, C_W_R, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, BLACK, C_W_R, BLACK, C_Y_R, C_Y_R, C_Y_R, BLACK, C_W_R, C_W_R},		//RED
		{C_W_G, C_W_G, C_W_G, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, BLACK, C_W_G, BLACK, C_Y_G, C_Y_G, C_Y_G, BLACK, C_W_G, C_W_G},		//GREEN
		{C_W_B, C_W_B, C_W_B, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, BLACK, C_W_B, BLACK, C_Y_B, C_Y_B, C_Y_B, BLACK, C_W_B, C_W_B},		//BLUE
	},
	{//5
		{C_W_R, C_W_R, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, BLACK, BLACK, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, C_W_R},		//RED
		{C_W_G, C_W_G, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, BLACK, BLACK, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, C_W_G},		//GREEN
		{C_W_B, C_W_B, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, BLACK, BLACK, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, C_W_B},		//BLUE
	},
	{//6
		{C_W_R, C_W_R, BLACK, C_Y_R, C_Y_R, BLACK, C_Y_R, C_Y_R, C_Y_R, BLACK, BLACK, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, C_W_R},		//RED
		{C_W_G, C_W_G, BLACK, C_Y_G, C_Y_G, BLACK, C_Y_G, C_Y_G, C_Y_G, BLACK, BLACK, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, C_W_G},		//GREEN
		{C_W_B, C_W_B, BLACK, C_Y_B, C_Y_B, BLACK, C_Y_B, C_Y_B, C_Y_B, BLACK, BLACK, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, C_W_B},		//BLUE
	},
	{//7
		{C_W_R, C_W_R, BLACK, C_Y_R, C_Y_R, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, C_W_R},		//RED
		{C_W_G, C_W_G, BLACK, C_Y_G, C_Y_G, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, C_W_G},		//GREEN
		{C_W_B, C_W_B, BLACK, C_Y_B, C_Y_B, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, C_W_B},		//BLUE
	},
	{//8
		{C_W_R, C_W_R, BLACK, C_Y_R, C_Y_R, BLACK, C_Y_R, C_Y_R, C_Y_R, BLACK, BLACK, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, C_W_R},		//RED
		{C_W_G, C_W_G, BLACK, C_Y_G, C_Y_G, BLACK, C_Y_G, C_Y_G, C_Y_G, BLACK, BLACK, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, C_W_G},		//GREEN
		{C_W_B, C_W_B, BLACK, C_Y_B, C_Y_B, BLACK, C_Y_B, C_Y_B, C_Y_B, BLACK, BLACK, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, C_W_B},		//BLUE
	},
	{//9
		{C_W_R, C_W_R, BLACK, C_Y_R, C_Y_R, BLACK, C_Y_R, C_Y_R, BLACK, C_W_R, C_W_R, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, C_W_R},		//RED
		{C_W_G, C_W_G, BLACK, C_Y_G, C_Y_G, BLACK, C_Y_G, C_Y_G, BLACK, C_W_G, C_W_G, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, C_W_G},		//GREEN
		{C_W_B, C_W_B, BLACK, C_Y_B, C_Y_B, BLACK, C_Y_B, C_Y_B, BLACK, C_W_B, C_W_B, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, C_W_B},		//BLUE
	},
	{//10
		{C_W_R, C_W_R, C_W_R, BLACK, C_Y_R, C_Y_R, BLACK, C_Y_R, BLACK, BLACK, C_W_R, BLACK, C_Y_R, C_Y_R, C_Y_R, BLACK, C_W_R, C_W_R},		//RED
		{C_W_G, C_W_G, C_W_G, BLACK, C_Y_G, C_Y_G, BLACK, C_Y_G, BLACK, BLACK, C_W_G, BLACK, C_Y_G, C_Y_G, C_Y_G, BLACK, C_W_G, C_W_G},		//GREEN
		{C_W_B, C_W_B, C_W_B, BLACK, C_Y_B, C_Y_B, BLACK, C_Y_B, BLACK, BLACK, C_W_B, BLACK, C_Y_B, C_Y_B, C_Y_B, BLACK, C_W_B, C_W_B},		//BLUE
	},
	{//11
		{C_W_R, C_W_R, C_W_R, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, BLACK, BLACK, BLACK, C_Y_R, C_Y_R, C_Y_R, BLACK, C_W_R, C_W_R},		//RED
		{C_W_G, C_W_G, C_W_G, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, BLACK, BLACK, BLACK, C_Y_G, C_Y_G, C_Y_G, BLACK, C_W_G, C_W_G},		//GREEN
		{C_W_B, C_W_B, C_W_B, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, BLACK, BLACK, BLACK, C_Y_B, C_Y_B, C_Y_B, BLACK, C_W_B, C_W_B},		//BLUE
	},
	{//12
		{C_W_R, C_W_R, C_W_R, C_W_R, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, BLACK, BLACK, C_Y_R, C_Y_R, BLACK, C_W_R, C_W_R, C_W_R},		//RED
		{C_W_G, C_W_G, C_W_G, C_W_G, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, BLACK, BLACK, C_Y_G, C_Y_G, BLACK, C_W_G, C_W_G, C_W_G},		//GREEN
		{C_W_B, C_W_B, C_W_B, C_W_B, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, BLACK, BLACK, C_Y_B, C_Y_B, BLACK, C_W_B, C_W_B, C_W_B},		//BLUE
	},
	{//13
		{C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, BLACK, BLACK, C_Y_R, C_Y_R, C_Y_R, C_Y_R, BLACK, BLACK, BLACK, C_W_R, C_W_R, C_W_R, C_W_R},		//RED
		{C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, BLACK, BLACK, C_Y_G, C_Y_G, C_Y_G, C_Y_G, BLACK, BLACK, BLACK, C_W_G, C_W_G, C_W_G, C_W_G},		//GREEN
		{C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, BLACK, BLACK, C_Y_B, C_Y_B, C_Y_B, C_Y_B, BLACK, BLACK, BLACK, C_W_B, C_W_B, C_W_B, C_W_B},		//BLUE
	},
	{//14
		{C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, BLACK, BLACK, BLACK, BLACK, BLACK, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R},		//RED
		{C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, BLACK, BLACK, BLACK, BLACK, BLACK, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G},		//GREEN
		{C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, BLACK, BLACK, BLACK, BLACK, BLACK, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B}		//BLUE
	},
	{//white
		{C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R, C_W_R},		//RED
		{C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G, C_W_G},		//GREEN
		{C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B, C_W_B}		//BLUE
	}
};


#endif
