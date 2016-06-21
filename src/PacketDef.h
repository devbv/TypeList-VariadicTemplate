#pragma once

struct Packet
{
	int mId;
	int mLen;
};

struct PKT_LOGIN
{
	char mUserId[32];
	char mPassword[128];
};

struct PKT_LOGOUT
{
	char mLog[128];
};

struct PKT_SEND_MESSAGE
{
	int mTargetId;
	char mMessage[512];
};

struct PKT_ADD_SCORE
{
	int mScore;
};