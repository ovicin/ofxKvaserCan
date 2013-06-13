#ifndef _CANDEMO_H_
#define _CANDEMO_H_

//defines
#define MAX_CHANNELS 63   //cannot be more because waitforsingle object can "only" handle 64 events

//includes
#include "canlib.h"


//for debug/error purposes
#if 1
#define PRINTF_ERR(x)     printf x
#else
#define PRINTF_ERR(x)
#endif  


//typedefs
typedef struct {
  int        channel;
  char       name[100];
  DWORD      hwType;
  canHandle  hnd;
  int        hwIndex;
  int        hwChannel;
  int        isOnBus;
  int        driverMode;
  int        txAck;
} ChannelDataStruct;


typedef struct {
  unsigned int       channelCount;
  ChannelDataStruct  channel[MAX_CHANNELS];
} driverData;

class ofxKvaserCan{
public:
	ofxKvaserCan();
	void help(void);
	void printDriverConfig( void );
	void InitDriver(void);
	void Cleanup(void);
	canStatus TransmitMessage(unsigned int   Id,unsigned char *inmsg, BOOL print);
	void ReadMessage(void);
};

#endif
