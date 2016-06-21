#include <iostream>
#include "../TypeList.h"
#include "PacketBox.h"

typedef TypeList<PKT_LOGIN, PKT_LOGOUT, PKT_ADD_SCORE, PKT_SEND_MESSAGE> PACKET_TYPE;
template <typename T>
class PacketBox : public Packet
{
public:
	PacketBox()
	{
		mId = type_id<T, PACKET_TYPE>::value;
		mLen = sizeof(T);
	}

	T mBuf;
};

void main()
{
	std::cout << "* Length of PACKET_TYPE: " << length<PACKET_TYPE>::value << std::endl;

	std::cout << "* 2nd element of PACKET_TYPE: " << typeid(type_at<1, PACKET_TYPE>::type).name() << std::endl;
	
	PacketBox<PKT_ADD_SCORE> pkt;
	std::cout << "* ID of PKT_ADD_SCORE: " << pkt.mId << std::endl;
}