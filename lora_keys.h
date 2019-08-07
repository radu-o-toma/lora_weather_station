/*
 * lora_keys.h
 *
 * Created: 3/7/2019 2:42:55 PM
 *  Author: m50653
 */ 


#ifndef LORA_KEYS_H_
#define LORA_KEYS_H_

//#define OTAA              1
#define ABP             1

#ifdef OTAA

const char my_deveui[] = "0004A30B0024D753";
const char my_appeui[] = "70B3D57ED001FBAE";
const char my_appkey[] = "EE9B2EC14296FD4FE856FDF6A4C9898C";

#elif ABP

const char my_devaddr[] = "26051AB0";
const char my_nwkskey[] = "7E22D4C90358DC4C2B3C92E27C37A06F";
const char my_appskey[] = "F0982277D42CA9CC12DEEBE8ACF826B2";

#endif

#endif /* LORA_KEYS_H_ */