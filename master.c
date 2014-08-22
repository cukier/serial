/*
 * master.c
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

int m_cmd;
int nrSlv = 1;
int i;
int r_addr = 0xFF;
int r_cmd = 0xFF;

int buffer[buffer_size];

long pos_r;
long pos_slv[nrMax];

#include "funcoes.c"

int main(void) {

	while (TRUE) {
//		m_cmd = trata_bto();
//		if (m_cmd == cmd_subir || m_cmd == cmd_descer) {
//			delay_ms(20);
//			for (i = 1; i <= nrSlv; ++i) {
//				printf("%02u%02u\r\n", i, cmd_r);
//				gets(buffer);
//				pos_r = getPos(buffer);
//				pos_slv[i] = pos_r;
//			}
//		}
		send_cmd(0, cmd_w);
		send_pos(0, 12345);
		send_cmd(1, cmd_r);
		gets(buffer);
		r_addr = getAddr(buffer);
		pos_slv[0] = getPos(buffer);

		delay_ms(100);
	}

	return 0;
}

