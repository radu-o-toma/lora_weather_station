/*
 * sht3x.h
 *
 * Created: 30/07/2019 14:09:05
 *  Author: Radu
 */ 


#ifndef SHT3X_H_
#define SHT3X_H_


/**
  Section: Included Files
 */

#include <stdbool.h>
#include <stdint.h>

/**
  Section: Macro Declarations
 */

// Device Information
#define SHT3X_ADDR 0x44

/**
  Section: SHT3X Sensor Driver APIs
 */

void    SHT3X_getStatus(void);



#endif /* SHT3X_H_ */