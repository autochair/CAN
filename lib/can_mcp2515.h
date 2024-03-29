
#ifndef _MCP2515_H_
#define _MCP2515_H_

#include "can_mcp2515_dfs.h"

#define MAX_CHAR_IN_MESSAGE 8

class MCP_CAN
{
private:

	unsigned char   ext_flg;                         // identifier xxxID
											// either extended (the 29 LSB) or standard (the 11 LSB)
	unsigned long  can_id;                  // can id
	unsigned char   dta_len;                         // data length
	unsigned char   dta[MAX_CHAR_IN_MESSAGE];        // data
	unsigned char   rtr;                             // rtr
	unsigned char   filhit;

	/*
	*  mcp2515 driver function
	*/

private:

	void mcp2515_reset(void);                                   // reset mcp2515

	unsigned char mcp2515_readRegister(const unsigned char address);              // read mcp2515's register

	void mcp2515_readRegisterS(const unsigned char address,
		unsigned char values[],
		const unsigned char n);
	void mcp2515_setRegister(const unsigned char address,                // set mcp2515's register
		const unsigned char value);

	void mcp2515_setRegisterS(const unsigned char address,               // set mcp2515's registers
		const unsigned char values[],
		const unsigned char n);

	void mcp2515_initCANBuffers(void);

	void mcp2515_modifyRegister(const unsigned char address,             // set bit of one register
		const unsigned char mask,
		const unsigned char data);

	unsigned char mcp2515_readStatus(void);                              // read mcp2515's Status
	unsigned char mcp2515_setCANCTRL_Mode(const unsigned char newmode);           // set mode
	unsigned char mcp2515_configRate(const unsigned char canSpeed);               // set boadrate
	unsigned char mcp2515_init(const unsigned char canSpeed);                     // mcp2515init

	void mcp2515_write_id(const unsigned char mcp_addr,                 // write can id
		const unsigned char ext,
		const unsigned long id);

	void mcp2515_read_id(const unsigned char mcp_addr,                  // read can id
		unsigned char* ext,
		unsigned long* id);

	void mcp2515_write_canMsg(const unsigned char buffer_sidh_addr, int rtrBit);   // write can msg
	void mcp2515_read_canMsg(const unsigned char buffer_sidh_addr);     // read can msg
	void mcp2515_start_transmit(const unsigned char mcp_addr);           // start transmit
	unsigned char mcp2515_getNextFreeTXBuf(unsigned char *txbuf_n);               // get Next free txbuf

																/*
																*  can operator function
																*/

	unsigned char setMsg(unsigned long id, unsigned char ext, unsigned char len, unsigned char rtr, unsigned char *pData);   // set message
	unsigned char setMsg(unsigned long id, unsigned char ext, unsigned char len, unsigned char *pData);             //  set message
	unsigned char clearMsg();                                                // clear all message to zero
	unsigned char readMsg();                                                 // read message
	unsigned char sendMsg(int rtrBit);                                                 // send message

public:
	unsigned char begin(unsigned char speedset);                                      // init can
	unsigned char init_Mask(unsigned char num, unsigned char ext, unsigned long ulData);       // init Masks
	unsigned char init_Filt(unsigned char num, unsigned char ext, unsigned long ulData);       // init filters
	unsigned char sendMsgBuf(unsigned long id, unsigned char ext, unsigned char rtr, unsigned char len, unsigned char *buf);     // send buf
	unsigned char sendMsgBuf(unsigned long id, unsigned char ext, unsigned char len, unsigned char *buf);               // send buf
	unsigned char readMsgBuf(unsigned char *len, unsigned char *buf);                          // read buf
	unsigned char readMsgBufID(unsigned long *ID, unsigned char *len, unsigned char *buf);     // read buf with object ID
	unsigned char checkReceive(void);                                        // if something received
	unsigned char checkError(void);                                          // if something error
	unsigned long getCanId(void);                                   // get can id when receive
	unsigned char isRemoteRequest(void);                                     // get RR flag when receive
	unsigned char isExtendedFrame(void);                                     // did we recieve 29bit frame?
};

#endif
/*********************************************************************************************************
END FILE
*********************************************************************************************************/
