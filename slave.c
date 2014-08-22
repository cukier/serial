/*
 * slave.c
 *
 *  Created on: 18/08/2014
 *      Author: cuki
 */

#include<18F252.h>
#zero_ram

#include<stdlib.h>

#fuses HS
#use delay(clock=15MHz)
#use rs232(baud=9600,xmit=pin_c6,rcv=pin_c7)

#include "defines.c"

short ctrl_bto;

int m_addr = 0xFF;
int r_addr = 0xFF;
int r_cmd = 0xFF;

long r_pos = 12345;
long m_pos = 12345;

int buffer[arrayLen];

#include "funcoes.c"

void trata_comunicacao() {

	gets(buffer);
	r_addr = 0xFF;
	r_cmd = 0xFF;
	r_addr = getAddr(buffer);
	r_cmd = getCmd(buffer);

	if (r_addr == m_addr | !r_addr) {
		if (r_cmd == cmd_w) {
			gets(buffer);
			r_pos = getPos(buffer);
		} else if (r_cmd == cmd_r) {
			send_pos(m_addr, r_pos);
		}
	}
}

int main(void) {

	m_addr = 1;

	while (TRUE) {
		trata_comunicacao();
	}
	return 0;
}
