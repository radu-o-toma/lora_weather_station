/*
 * sht3x.c
 *
 * Created: 30/07/2019 14:10:10
 *  Author: Radu
 */ 

#include "sht3x.h"
#include "i2c_simple_master.h"

uint8_t SHT3x_readByte(uint8_t reg_addr)
{
	return I2C_MASTER_read1ByteRegister(SHT3X_ADDR, reg_addr);
}