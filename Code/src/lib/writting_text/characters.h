#ifndef CHARACTERS_H__
#define CHARACTERS_H__

#include <stdint.h>
#include <stdbool.h>


static uint8_t char7 [][7] = {
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, //' '
	{0x08, 0x14, 0x22, 0x41, 0x7f, 0x41, 0x41}, //'A'
	{0x3c, 0x22, 0x22, 0x3c, 0x22, 0x22, 0x3c}, //'B'
	{0x1c, 0x22, 0x40, 0x40, 0x40, 0x22, 0x1c}, //'C'
	{0x38, 0x24, 0x22, 0x22, 0x22, 0x24, 0x38}, //'D'
	{0x3e, 0x20, 0x20, 0x3c, 0x20, 0x20, 0x3e}, //'E'
	{0x3e, 0x20, 0x20, 0x3c, 0x20, 0x20, 0x20}, //'F'
	{0x1e, 0x20, 0x20, 0x2c, 0x22, 0x22, 0x1e}, //'G'
	{0x22, 0x22, 0x22, 0x3e, 0x22, 0x22, 0x22}, //'H'
	{0x1c, 0x08, 0x08, 0x08, 0x08, 0x08, 0x1c}, //'I'
	{0x1c, 0x04, 0x04, 0x04, 0x04, 0x14, 0x08}, //'J'
	{0x22, 0x24, 0x28, 0x30, 0x28, 0x24, 0x22}, //'K'
	{0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x3c}, //'L'
	{0x41, 0x63, 0x55, 0x49, 0x41, 0x41, 0x41}, //'M'
	{0x22, 0x32, 0x22, 0x2a, 0x22, 0x26, 0x22}, //'N'
	{0x1c, 0x22, 0x41, 0x41, 0x41, 0x22, 0x1c}, //'O'
	{0x38, 0x24, 0x24, 0x38, 0x20, 0x20, 0x20}, //'P'
	{0x1c, 0x22, 0x41, 0x41, 0x45, 0x22, 0x1d}, //'Q'
	{0x38, 0x24, 0x24, 0x38, 0x28, 0x24, 0x24}, //'R'
	{0x1e, 0x20, 0x20, 0x1c, 0x0a, 0x02, 0x3c}, //'S'
	{0x3e, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08}, //'T'
	{0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x1c}, //'U'
	{0x22, 0x22, 0x22, 0x14, 0x14, 0x14, 0x08}, //'V'
	{0x41, 0x41, 0x41, 0x49, 0x55, 0x63, 0x41}, //'W'
	{0x22, 0x22, 0x14, 0x08, 0x14, 0x22, 0x22}, //'X'
	{0x22, 0x22, 0x14, 0x08, 0x08, 0x08, 0x08}, //'Y'
	{0x3e, 0x02, 0x04, 0x08, 0x10, 0x20, 0x3e}, //'Z'
	{0x22, 0x77, 0x7f, 0x7f, 0x3e, 0x1c, 0x08}  //28 - heart
};
//https://thumbs.dreamstime.com/b/round-pixel-font-alphabets-numerals-punctuation-characters-retro-isolated-contains-spare-pixels-file-id-has-lower-40032894.jpg
const static uint16_t char16 [27][16] = {
	{0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000}, //' '
	{0x0000, 0x07c0, 0x0fe0, 0x0c60, 0x0c60, 0x1830, 0x1830, 0x1830, 0x1ff0, 0x1ff0, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x0000}, //'A'
	{0x0000, 0x1fc0, 0x1fe0, 0x1830, 0x1830, 0x1830, 0x1830, 0x1fe0, 0x1fe0, 0x1830, 0x1830, 0x1830, 0x1830, 0x1fe0, 0x1fc0, 0x0000}, //'B'
	{0x0000, 0x0fe0, 0x1ff0, 0x1830, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1830, 0x1ff0, 0x0fe0, 0x0000}, //'C'
	{0x0000, 0x1fe0, 0x1ff0, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1ff0, 0x1fe0, 0x0000}, //'D'
	{0x0000, 0x0ff0, 0x1ff0, 0x1800, 0x1800, 0x1800, 0x1800, 0x1f80, 0x1f80, 0x1800, 0x1800, 0x1800, 0x1800, 0x1ff0, 0x0ff0, 0x0000}, //'E'
	{0x0000, 0x0ff0, 0x1ff0, 0x1800, 0x1800, 0x1800, 0x1800, 0x1f80, 0x1f80, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x0000}, //'F'
	{0x0000, 0x0fe0, 0x1ff0, 0x1830, 0x1800, 0x1800, 0x1800, 0x1800, 0x19e0, 0x19f0, 0x1830, 0x1830, 0x1830, 0x1ff0, 0x0fe0, 0x0000}, //'G'
	{0x0000, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1ff0, 0x1ff0, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x0000}, //'H'
	{0x0000, 0x0ff0, 0x0ff0, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0ff0, 0x0ff0, 0x0000}, //'I'
	{0x0000, 0x0ff8, 0x0ff8, 0x00c0, 0x00c0, 0x00c0, 0x00c0, 0x00c0, 0x00c0, 0x00c0, 0x00c0, 0x08c0, 0x0cc0, 0x07c0, 0x0380, 0x0000}, //'J'
	{0x0000, 0x1818, 0x1838, 0x1830, 0x1860, 0x18e0, 0x1980, 0x1b00, 0x1f00, 0x1f80, 0x19c0, 0x1860, 0x1830, 0x1838, 0x1818, 0x0000}, //'K'
	{0x0000, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1ff0, 0x1ff0, 0x0000}, //'L'
	{0x0000, 0x1818, 0x1c38, 0x1c38, 0x1e78, 0x1ff8, 0x1bd8, 0x1998, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x1818, 0x0000}, //'M'
	{0x0000, 0x1830, 0x1c30, 0x1c30, 0x1e30, 0x1e30, 0x1b30, 0x1b30, 0x19b0, 0x19b0, 0x18f0, 0x18f0, 0x1870, 0x1870, 0x1830, 0x0000}, //'N'
	{0x0000, 0x0fe0, 0x1ff0, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1ff0, 0x0fe0, 0x0000}, //'O'
	{0x0000, 0x0fe0, 0x1ff0, 0x1830, 0x1830, 0x1830, 0x1830, 0x1ff0, 0x1fe0, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x1800, 0x0000}, //'P'
	{0x0000, 0x0fe0, 0x1ff0, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x18b0, 0x18f0, 0x1870, 0x1830, 0x1838, 0x1ffc, 0x0fe4, 0x0000}, //'Q'
	{0x0000, 0x1fc0, 0x1fe0, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1fe0, 0x1fc0, 0x18c0, 0x1860, 0x1860, 0x1830, 0x1830, 0x0000}, //'R'
	{0x0000, 0x0fe0, 0x1ff0, 0x1830, 0x1800, 0x1800, 0x1800, 0x1fe0, 0x0ff0, 0x0030, 0x0030, 0x0030, 0x1830, 0x1ff0, 0x0fe0, 0x0000}, //'S'
	{0x0000, 0x1ff8, 0x1ff8, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0000}, //'T'
	{0x0000, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1830, 0x1ff0, 0x0fe0, 0x0000}, //'U'
	{0x0000, 0x1008, 0x1818, 0x1818, 0x1818, 0x0c30, 0x0c30, 0x0c30, 0x0660, 0x0660, 0x0660, 0x03c0, 0x03c0, 0x0180, 0x0180, 0x0000}, //'V'
	{0x0000, 0x4002, 0x6006, 0x6006, 0x6006, 0x6006, 0x6006, 0x6186, 0x63c6, 0x366c, 0x366c, 0x366c, 0x366c, 0x1c38, 0x0810, 0x0000}, //'W'
	{0x0000, 0x1830, 0x1830, 0x0c60, 0x0c60, 0x06c0, 0x06c0, 0x0380, 0x0380, 0x06c0, 0x06c0, 0x0c60, 0x0c60, 0x1830, 0x1830, 0x0000}, //'X'
	{0x0000, 0x1008, 0x1818, 0x1818, 0x0c30, 0x0c30, 0x0660, 0x0660, 0x03c0, 0x03c0, 0x0180, 0x0180, 0x0180, 0x0180, 0x0180, 0x0000}, //'Y'
	{0x0000, 0x1ff0, 0x1ff0, 0x0070, 0x00e0, 0x00c0, 0x0180, 0x0180, 0x0300, 0x0300, 0x0600, 0x0e00, 0x1c00, 0x1ff0, 0x1ff0, 0x0000}  //'Z'
};

#endif //CHARACTERS_H__
/*

{ 
  0b0000000000000000, //0
  0b0000111111100000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0000111111100000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //1
  0b0000001110000000,
  0b0000011110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000011111100000,
  0b0000011111100000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //2
  0b0000111111100000,
  0b0001111111110000,
  0b0001100000110000,
  0b0000000000110000,
  0b0000000000110000,
  0b0000000001110000,
  0b0000000011100000,
  0b0000000111000000,
  0b0000001110000000,
  0b0000011100000000,
  0b0000111000000000,
  0b0001110000000000,
  0b0001111111110000,
  0b0001111111110000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //3
  0b0001111111110000,
  0b0001111111110000,
  0b0000000001110000,
  0b0000000011100000,
  0b0000000111000000,
  0b0000001110000000,
  0b0000011111110000,
  0b0000011111110000,
  0b0000000000110000,
  0b0000000000110000,
  0b0000000000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0000111111100000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //4
  0b0000000011100000,
  0b0000000011100000,
  0b0000000101100000,
  0b0000001101100000,
  0b0000001101100000,
  0b0000011001100000,
  0b0000011001100000,
  0b0000110001100000,
  0b0000110001100000,
  0b0001100001100000,
  0b0001111111111000,
  0b0001111111111000,
  0b0000000001100000,
  0b0000000001100000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //5
  0b0001111111110000,
  0b0001111111110000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001111111100000,
  0b0000111111110000,
  0b0000000000110000,
  0b0000000000110000,
  0b0000000000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0000111111100000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //6
  0b0000111111100000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001111111100000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0000111111100000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //7
  0b0001111111110000,
  0b0001111111110000,
  0b0000000001110000,
  0b0000000011000000,
  0b0000000011000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000001100000000,
  0b0000001100000000,
  0b0000011000000000,
  0b0000011000000000,
  0b0000110000000000,
  0b0000110000000000,
  0b0000110000000000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //8
  0b0000111111100000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0000111111100000,
  0b0000111111100000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0000111111100000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //9
  0b0000111111100000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111100000,
  0b0000111111100000,
  0b0000000000110000,
  0b0000000000110000,
  0b0000000000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0000111111100000,
  0b0000000000000000,
},




{
  0b0000000000000000, //' '
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
  0b0000000000000000,
},
{
  0b0000000000000000, //'A'
  0b0000011111000000,
  0b0000111111100000,
  0b0000110001100000,
  0b0000110001100000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0000000000000000,
},
{
  0b0000000000000000, //'B'
  0b0001111111000000,
  0b0001111111100000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111100000,
  0b0001111111100000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111100000,
  0b0001111111000000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //'C'
  0b0000111111100000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000110000,
  0b0001111111110000,
  0b0000111111100000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //'D'
  0b0001111111100000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0001111111100000,
  0b0000000000000000,
},
{
  0b0000000000000000, //'E'
  0b0000111111110000,
  0b0001111111110000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001111110000000,
  0b0001111110000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001111111110000,
  0b0000111111110000,
  0b0000000000000000,
},
{
  0b0000000000000000, //'F'
  0b0000111111110000,
  0b0001111111110000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001111110000000,
  0b0001111110000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0000000000000000,
},
{
  0b0000000000000000, //'G'
  0b0000111111100000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100111100000,
  0b0001100111110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0000111111100000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //'H'
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0000000000000000,
},
{
  0b0000000000000000, //'I'
  0b0000111111110000,
  0b0000111111110000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000111111110000,
  0b0000111111110000,
  0b0000000000000000,
},
{
  0b0000000000000000, //'J'
  0b0000111111111000,
  0b0000111111111000,
  0b0000000011000000,
  0b0000000011000000,
  0b0000000011000000,
  0b0000000011000000,
  0b0000000011000000,
  0b0000000011000000,
  0b0000000011000000,
  0b0000000011000000,
  0b0000100011000000,
  0b0000110011000000,
  0b0000011111000000,
  0b0000001110000000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //'K'
  0b0001100000011000,
  0b0001100000111000,
  0b0001100000110000,
  0b0001100001100000,
  0b0001100011100000,
  0b0001100110000000,
  0b0001101100000000,
  0b0001111100000000,
  0b0001111110000000,
  0b0001100111000000,
  0b0001100001100000,
  0b0001100000110000,
  0b0001100000111000,
  0b0001100000011000,
  0b0000000000000000,
},
{
  0b0000000000000000, //'L'
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001111111110000,
  0b0001111111110000,
  0b0000000000000000,
},
{
  0b0000000000000000, //'M'
  0b0001100000011000,
  0b0001110000111000,
  0b0001110000111000,
  0b0001111001111000,
  0b0001111111111000,
  0b0001101111011000,
  0b0001100110011000,
  0b0001100000011000,
  0b0001100000011000,
  0b0001100000011000,
  0b0001100000011000,
  0b0001100000011000,
  0b0001100000011000,
  0b0001100000011000,
  0b0000000000000000,
},
{
  0b0000000000000000, //'N'
  0b0001100000110000,
  0b0001110000110000,
  0b0001110000110000,
  0b0001111000110000,
  0b0001111000110000,
  0b0001101100110000,
  0b0001101100110000,
  0b0001100110110000,
  0b0001100110110000,
  0b0001100011110000,
  0b0001100011110000,
  0b0001100001110000,
  0b0001100001110000,
  0b0001100000110000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //'O'
  0b0000111111100000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0000111111100000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //'P'
  0b0000111111100000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0001111111100000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //'Q'
  0b0000111111100000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100010110000,
  0b0001100011110000,
  0b0001100001110000,
  0b0001100000110000,
  0b0001100000111000,
  0b0001111111111100,
  0b0000111111100100,
  0b0000000000000000,
},
{
  0b0000000000000000, //'R'
  0b0001111111000000,
  0b0001111111100000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111100000,
  0b0001111111000000,
  0b0001100011000000,
  0b0001100001100000,
  0b0001100001100000,
  0b0001100000110000,
  0b0001100000110000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //'S'
  0b0000111111100000,
  0b0001111111110000,
  0b0001100000110000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001100000000000,
  0b0001111111100000,
  0b0000111111110000,
  0b0000000000110000,
  0b0000000000110000,
  0b0000000000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0000111111100000,
  0b0000000000000000,
},
{
  0b0000000000000000, //'T'
  0b0001111111111000,
  0b0001111111111000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000000000000,
},
{
  0b0000000000000000, //'U'
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001100000110000,
  0b0001111111110000,
  0b0000111111100000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //'V'
  0b0001000000001000,
  0b0001100000011000,
  0b0001100000011000,
  0b0001100000011000,
  0b0000110000110000,
  0b0000110000110000,
  0b0000110000110000,
  0b0000011001100000,
  0b0000011001100000,
  0b0000011001100000,
  0b0000001111000000,
  0b0000001111000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //'W'
  0b0100000000000010,
  0b0110000000000110,
  0b0110000000000110,
  0b0110000000000110,
  0b0110000000000110,
  0b0110000000000110,
  0b0110000110000110,
  0b0110001111000110,
  0b0011011001101100,
  0b0011011001101100,
  0b0011011001101100,
  0b0011011001101100,
  0b0001110000111000,
  0b0000100000010000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //'X'
  0b0001100000110000,
  0b0001100000110000,
  0b0000110001100000,
  0b0000110001100000,
  0b0000011011000000,
  0b0000011011000000,
  0b0000001110000000,
  0b0000001110000000,
  0b0000011011000000,
  0b0000011011000000,
  0b0000110001100000,
  0b0000110001100000,
  0b0001100000110000,
  0b0001100000110000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //'Y'
  0b0001000000001000,
  0b0001100000011000,
  0b0001100000011000,
  0b0000110000110000,
  0b0000110000110000,
  0b0000011001100000,
  0b0000011001100000,
  0b0000001111000000,
  0b0000001111000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000000000000000,
},
{ 
  0b0000000000000000, //'Z'
  0b0001111111110000,
  0b0001111111110000,
  0b0000000001110000,
  0b0000000011100000,
  0b0000000011000000,
  0b0000000110000000,
  0b0000000110000000,
  0b0000001100000000,
  0b0000001100000000,
  0b0000011000000000,
  0b0000111000000000,
  0b0001110000000000,
  0b0001111111110000,
  0b0001111111110000,
  0b0000000000000000,
}
*/
