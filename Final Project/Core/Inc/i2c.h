#include "main.h"

uint32_t Get_Bit(uint32_t reg, uint8_t bit);
void Set_Bit(uint32_t reg, uint8_t bit);
enum I2C_CR1Bits :uint8_t
{
	PE=0, //Peripheral Enable
	START=8
};
enum Freq
{
	FREQ_2MHZ=0b000010,
	FREQ_4MHZ=0b000100,
	FREQ_8MHZ=0b001000

};
enum Status
{
	Start_Generated=0,
	Received=6,
	Transmitted=7
};
namespace mcal
{
constexpr uint32_t I2C_Speed=100000;
}
class I2C
{
public:
	I2C(I2C_TypeDef * pI2C, GPIO_TypeDef * pGpio) ;
	void I2C_INIT();
	bool I2C_Generate_StartBit();
	bool I2C_CheckReceived();
	bool I2C_CheckTransmitted();
	uint8_t I2C_Transmit(uint8_t x);
	uint8_t I2C_Receive();
private:

	I2C_TypeDef* mI2C;
	GPIO_TypeDef* gpio;

};
