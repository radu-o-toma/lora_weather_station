#include <atmel_start.h>
#include <string.h>
#include "lora_handling.h"
#include "low_power.h"
#include <util/delay.h>

#include "i2c_simple_master.h"
#include "sht3x.h"

char* sensor_data[15];

#define COMMAND_LENGTH 2
char command[2];
char reply[10];
float temperature, humidity;

char* SENSORS_HANDLING_readSensors(void);


int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

    LORA_HANDLING_loraInit();
	
	command[0]=0xF3;
	command[1]=0x2D;
	
	_delay_ms(100); //  delay for SHT3x sensor
	
	I2C_MASTER_writeNBytes(SHT3X_ADDR, &command, COMMAND_LENGTH);
	_delay_ms(1); //  delay for SHT3x sensor
	I2C_MASTER_readNBytes(SHT3X_ADDR, &reply,3);
	
	command[0]=0x30;
	command[1]=0x41;
	
	I2C_MASTER_writeNBytes(SHT3X_ADDR, &command, COMMAND_LENGTH);
	_delay_ms(1); //  delay for SHT3x sensor
	I2C_MASTER_readNBytes(SHT3X_ADDR, &reply,3);

    while (1)
    {
		
		//LOW_POWER_exitLowPower();
	
        
        //LORA_HANDLING_transmit(sensor_data);
		

        //LOW_POWER_enterLowPower();
		for (uint16_t counter = 0; counter < 10; counter++)
			_delay_ms(1000);
			
		
		
		*sensor_data = reply[0];
		*(sensor_data+1) = reply[1];
		*(sensor_data+2) = reply[3];
		*(sensor_data+3) = reply[4];
		
		strcpy(sensor_data, SENSORS_HANDLING_readSensors());
		LORA_HANDLING_transmit(sensor_data);

    }

    return 0;
}

char* SENSORS_HANDLING_readSensors(void)
{
	char command[2];
	char reply[10];
    uint16_t temperature_reading;
    uint16_t humidity_reading;
    static char transmission_command[15];
	
	//command[0]=0x24;	// no clock stretching
	//command[1]=0x16;	// low repeatability
	command[0]=0x2C;	// clock stretching
	command[1]=0x06;	// low repeatability
		
		
	I2C_MASTER_writeNBytes(SHT3X_ADDR, &command, COMMAND_LENGTH);
	//_delay_ms(5); //  delay for SHT3x sensor
	I2C_MASTER_readNBytes(SHT3X_ADDR, &reply,6);
		
	temperature_reading = (reply[0] << 8) + reply[1];
	humidity_reading = (reply[3] << 8) + reply[4];
		
	temperature = ((175.0 * temperature_reading)/(float)(65535.0)) - 45.0;
	humidity = (100.0 * humidity_reading)/65535.0;
		
	printf("T: %.2f degC, RH: %.2f\r\n", temperature, humidity);
	
	snprintf(transmission_command, sizeof transmission_command, "%x%x", temperature_reading, humidity_reading);
    
    return transmission_command;
}
