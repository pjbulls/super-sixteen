#include <SPI.h>

#include "Pinout.h"
#include "Dac.h"
#include "digitalWriteFast.h"

namespace supersixteen {
void Dac::setOutput(uint8_t channel, uint8_t gain, uint8_t shutdown, unsigned int val)
{
	if (val < 0) {
		val = 0;
	} else if (val > 4095) {
		val = 4095;
	}
	uint8_t lowByte = val & 0xff;
	uint8_t highByte = ((val >> 8) & 0xff) | channel << 7 | gain << 5 | shutdown << 4;

	//PORTB &= 0xfb;
	SPI.setBitOrder(MSBFIRST);
	digitalWriteFast(CS3_PIN, LOW);
	SPI.transfer(highByte);
	SPI.transfer(lowByte);
	digitalWriteFast(CS3_PIN, HIGH);
}


//assuming dac single channel, gain=2
//void AnalogIo::setOutput(unsigned int val) {
//	if (val > 4096) {
//		val = 4095;
//	}
//	byte lowByte = val & 0xff;
//	byte highByte = ((val >> 8) & 0xff) | 0x10;
//
//	digitalWrite(CS1_PIN, LOW);
//	PORTB &= 0xfb;
//	SPI.transfer(highByte);
//	SPI.transfer(lowByte);
//	PORTB |= 0x4;
//	digitalWrite(CS1_PIN, HIGH);
//}

}