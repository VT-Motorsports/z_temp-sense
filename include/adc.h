// zephyr_adc.h
#pragma once
#include <zephyr/drivers/spi.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/device.h>

struct AD7708Config {
    struct spi_dt_spec spi;
    struct gpio_dt_spec drdy;
    struct gpio_dt_spec reset;
};

class AD7708
{
  private:
    int reset();
    int write_reg(uint8_t reg, uint8_t value);
    int read_reg(uint8_t reg, uint8_t *value);
    int wait_data_ready();
    const AD7708Config *config_;

  public:
    explicit AD7708(const AD7708Config *config);
    int init();
    int read_raw(uint8_t channel, int32_t *sample);


};