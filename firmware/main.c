#include <avr/io.h>
#include <util/delay.h>
#include "main.h"

int main() {
	// PB4 as output pin
	DDRB |= _BV(PB4);

	for (int i = 0; i < 8; ++i) {
		unsigned char working_byte = code[i];

		// Hum, this is a dirty code
		// But anyway, let's explain it
		//
		// To save space, our 128 bit code
		// is stored into eight unsigned chars
		// so we need to iterate for each byte
		// of the array, and then iterate for
		// each bit of the array
		// 
		// I set PORTB to 0xFF because I wanted
		// to get my code running as fast as I
		// could and I didn't wanted to mess up
		// with bit masks.
		for (int j = 0; j < 8; ++j) {
			if ((working_byte >> j) & 0b1) {
				PORTB = 0xFF;
			} else {
				PORTB = 0x00;
			}
			_delay_us(343);
		}
	}

	return 0;
}