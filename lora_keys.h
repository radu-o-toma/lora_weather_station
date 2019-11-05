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

const char my_devaddr[] = "26011DFF";
const char my_nwkskey[] = "9CA51BE2BBC59ECFE12D94277ED24F24";
const char my_appskey[] = "82B3BF83DFCBE7F8A5E5639CF62AB40B";

#endif

#endif /* LORA_KEYS_H_ */