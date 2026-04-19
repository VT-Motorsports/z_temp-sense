// zephyr_adc.cpp
#include "adc.h"
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(zephyr_adc);



int AD7708::reset() {

}

int AD7708::write_reg(uint8_t reg, uint8_t value){

}

int AD7708::read_reg(uint8_t reg, uint8_t *value){

}

int AD7708::wait_data_ready(){

}

AD7708::AD7708(const AD7708Config *config) : config_(config){

}

int AD7708::init(){

}

int AD7708::read_raw(uint8_t channel, int32_t *sample){

}