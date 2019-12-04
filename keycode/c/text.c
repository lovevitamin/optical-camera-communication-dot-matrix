// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this 
// with something like:
// make or gcc -o led led.c -lbcm2835
// sudo ./led
/*
             define from bcm2835.h                       define from Board DVK511
                 3.3V | | 5V               ->                 3.3V | | 5V
    RPI_V2_GPIO_P1_03 | | 5V               ->                  SDA | | 5V
    RPI_V2_GPIO_P1_05 | | GND              ->                  SCL | | GND
       RPI_GPIO_P1_07 | | RPI_GPIO_P1_08   ->                  IO7 | | TX
                  GND | | RPI_GPIO_P1_10   ->                  GND | | RX
       RPI_GPIO_P1_11 | | RPI_GPIO_P1_12   ->                  IO0 | | IO1
    RPI_V2_GPIO_P1_13 | | GND              ->                  IO2 | | GND
       RPI_GPIO_P1_15 | | RPI_GPIO_P1_16   ->                  IO3 | | IO4
                  VCC | | RPI_GPIO_P1_18   ->                  VCC | | IO5
       RPI_GPIO_P1_19 | | GND              ->                 MOSI | | GND
       RPI_GPIO_P1_21 | | RPI_GPIO_P1_22   ->                 MISO | | IO6
       RPI_GPIO_P1_23 | | RPI_GPIO_P1_24   ->                  SCK | | CE0
                  GND | | RPI_GPIO_P1_26   ->                  GND | | CE1

::if your raspberry Pi is version 1 or rev 1 or rev A
RPI_V2_GPIO_P1_03->RPI_GPIO_P1_03
RPI_V2_GPIO_P1_05->RPI_GPIO_P1_05
RPI_V2_GPIO_P1_13->RPI_GPIO_P1_13:

*/
#include <bcm2835.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define uchar unsigned char
#define uint unsigned int


//#define Max7219_pinCLK  RPI_GPIO_P1_11
#define Max7219_pinCS  RPI_GPIO_P1_24
//#define Max7219_pinDIN  RPI_V2_GPIO_P1_13

char characters[37] = { 
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
	'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
	'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z', ' ' 
};

uchar disp1[9][8] = {
	{' ',' ',' ','H','E',' ',' ',' '},
	{'X','I','A','O','S','O','N','G'},
	{' ',' ','O','C','C',' ',' ',' '},
	{' ',' ','T','E','S','T',' ',' '},
	{' ','S','U','C','C','E','S','S'},
	{' ','L','I','G','H','T',' ',' '},
	{' ','C','O','M','M','U','N','I'},
	{'C','A','T','I','O','N',' ',' '},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}
		    };//transmit

void Delay_xms(uint x)
{
	bcm2835_delay(x);
}
//------------------------

void Write_Max7219_byte(uchar DATA)
{
	bcm2835_gpio_write(Max7219_pinCS,LOW);
	bcm2835_spi_transfer(DATA);
}

void Write_Max7219(uchar address1,uchar dat1,uchar address2,uchar dat2,uchar address3,uchar dat3,uchar address4,uchar dat4,uchar address5,uchar dat5,uchar address6,uchar dat6,uchar address7,uchar dat7,uchar address8,uchar dat8,uchar address9,uchar dat9,uchar address10,uchar dat10,uchar address11,uchar dat11,uchar address12,uchar dat12,uchar address13,uchar dat13,uchar address14,uchar dat14,uchar address15,uchar dat15,uchar address16,uchar dat16)
{
	bcm2835_gpio_write(Max7219_pinCS,LOW);
	Write_Max7219_byte(address1);
	Write_Max7219_byte(dat1); 
	Write_Max7219_byte(address2);
	Write_Max7219_byte(dat2); 
	Write_Max7219_byte(address3);
	Write_Max7219_byte(dat3); 
	Write_Max7219_byte(address4);
	Write_Max7219_byte(dat4); 
	Write_Max7219_byte(address5);
	Write_Max7219_byte(dat5); 
	Write_Max7219_byte(address6);
	Write_Max7219_byte(dat6); 
	Write_Max7219_byte(address7);
	Write_Max7219_byte(dat7); 
	Write_Max7219_byte(address8);
	Write_Max7219_byte(dat8); 
	Write_Max7219_byte(address9);
	Write_Max7219_byte(dat9); 
	Write_Max7219_byte(address10);
	Write_Max7219_byte(dat10); 
	Write_Max7219_byte(address11);
	Write_Max7219_byte(dat11); 
	Write_Max7219_byte(address12);
	Write_Max7219_byte(dat12); 
	Write_Max7219_byte(address13);
	Write_Max7219_byte(dat13); 

	Write_Max7219_byte(address14);
	Write_Max7219_byte(dat14); 
	Write_Max7219_byte(address15);
	Write_Max7219_byte(dat15); 
	Write_Max7219_byte(address16);
	Write_Max7219_byte(dat16); 


	bcm2835_gpio_write(Max7219_pinCS,HIGH);
}

void Init_MAX7219()
{
	Write_Max7219(0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00,0x09,0x00);
	Write_Max7219(0x0a,0x03,0x0a,0x03,0x0a,0x03,0x0a,0x03,0x0a,0x03,0x0a,0x03,0x0a,0x03,0x0a,0x03,0x0a,0x03,0x0a,0x03,0x0a,0x03,0x0a,0x03,0x0a,0x03,0x0a,0x03,0x0a,0x03,0x0a,0x03);
	Write_Max7219(0x0b,0x07,0x0b,0x07,0x0b,0x07,0x0b,0x07,0x0b,0x07,0x0b,0x07,0x0b,0x07,0x0b,0x07,0x0b,0x07,0x0b,0x07,0x0b,0x07,0x0b,0x07,0x0b,0x07,0x0b,0x07,0x0b,0x07,0x0b,0x07);
	Write_Max7219(0x0c,0x01,0x0c,0x01,0x0c,0x01,0x0c,0x01,0x0c,0x01,0x0c,0x01,0x0c,0x01,0x0c,0x01,0x0c,0x01,0x0c,0x01,0x0c,0x01,0x0c,0x01,0x0c,0x01,0x0c,0x01,0x0c,0x01,0x0c,0x01);
	Write_Max7219(0x0f,0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00,0x0f,0x00);
}



void led_print(int char1) {
	for(uchar i = 1;i < 9;i++) {
		Write_Max7219(i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1],i,disp1[char1][i-1]);
	}
}

int main(int argc, char *argv[])
{
	if (1 == argc) {
		printf("Enter text as an argument.\n");
		return 1;
	}

	if (!bcm2835_init()) {
		printf("Unable to init bcm2835.\n");
		return 2;
	}

	bcm2835_spi_begin();
	bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);      // The default
	bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);                   // The default
	bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_256); // The default
	bcm2835_gpio_fsel(Max7219_pinCS, BCM2835_GPIO_FSEL_OUTP); 
	bcm2835_gpio_write(disp1[0][0],HIGH);
	Delay_xms(50);
	Init_MAX7219();

	int index = 0;
	while (index < 2) {
		// Retrive first letter
	//	char letter1 = toupper(argv[1][index]);
		
		// Retrieve second letter
		// If it does not exist use space
		for(int d = 0;d < 9; d++ )
		{
			if(d<8)
			{
		led_print(d);
			}
			else
			{	d = 0;
				led_print(d);
			}

		Delay_xms(60);
		}
		index++;
	}
	// Clear screen
	led_print(8);
	bcm2835_spi_end();
	bcm2835_close();
	return 0;
}
