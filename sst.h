/*************************************************
 * File:   sst.h
 * Author: Argirov; argirov@outlook.com
 *
 * Created on Wednesday, 2012, September 27, 14:58
 *
 * 1) SST25VF032B Datasheet - http://ww1.microchip.com/downloads/en/DeviceDoc/25071A.pdf
 * 2) PIC18F2550 Datasheet - http://ww1.microchip.com/downloads/en/DeviceDoc/39632e.pdf
 *************************************************/

#ifndef SST_H
#define	SST_H

/*************************************************
 * Defines of IO pins
 * [2] page 4
 * [2] page 208, table 19-2
 *************************************************/
#define CS_LOW			PORTAbits.RA5 = 0;
#define CS_HIGH			PORTAbits.RA5 = 1;

#define SCK_PORT		PORTBbits.RB1
#define SCK_TRIS		TRISBbits.RB1
#define SDO_PORT		PORTCbits.RC7
#define SDO_TRIS		TRISCbits.RC7
#define SDI_PORT		PORTBbits.RB0
#define SDI_TRIS		TRISBbits.RB0
#define CS_PORT			PORTAbits.RA5
#define CS_TRIS			TRISAbits.RA5


/*************************************************
 * Defines of supported instructions
 * [1] page 9, table 5
 *************************************************/
#define COM_READ					0x03
#define COM_HI_SPEED_READ			0x0b
#define COM_4KB_SECOTR_ERASE			0x20
#define COM_32KB_BLOCK_ERASE			0x52
#define COM_64KB_BLOCK_ERASE			0xd8
#define COM_CHIP_ERASE					0x60
#define COM_BYTE_PROGRAM			0x02
#define COM_AAI_WORD_PROGRAM			0xad
#define COM_READ_STATUS_REG			0x05
#define COM_ENABLE_WRITE_STATUS_REG	0x50
#define COM_WRITE_STATUS_REG			0x01
#define COM_WRITE_ENABLE			0x06
#define COM_WRITE_DISABLE			0x04
#define COM_READ_ID					0x90
#define COM_READ_JEDEC_ID			0x9f
#define COM_ENABLE_SO_BUSY			0x70
#define COM_DISABLE_SO_BUSY			0x80




/*************************************************
 * Function prototypes
 *************************************************/
void SST_Init(void);
void SST_Read(unsigned char *, long, int);
void SST_High_Speed_Read(unsigned char *, long, int);
void SST_Byte_Program(unsigned char, long);
void SST_Chip_Erase(void);
void SST_Sector_Erase(long);
void SST_32KB_Block_Erase(long);
void SST_64KB_Block_Erase(long);
unsigned char SST_Read_Status_Register(void);
void SST_Read_ID(unsigned char *);
void SST_Write_Enable(void);
void SST_Write_Disable(void);
void SST_Enable_Write_Status_Register(void);
void SST_Clear_Write_Protection(void);
void SST_Write_Status_Register(unsigned char);
void SST_Read_Jedec_ID(unsigned char *);
void SST_AAI_Soft_EoW(unsigned char *, long, int);



#endif	/* SST_H */

