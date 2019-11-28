#ifndef MQ_H
#define MQ_H

#define MQ_SEND_MSG 1
#define MQ_RECV_MSG 2


#pragma pack(push,1)
struct mq_reg
{
	char* data;
	size_t size;
};
#pragma pack(pop)
#endif
