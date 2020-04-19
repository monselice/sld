////////////////////////////////////////////////////////////////////////////
//misc.h
//(c) Zhe@Soldo Clan -> zhe[@]soldo.in
////////////////////////////////////////////////////////////////////////////
#pragma once

#include <string>
#include "rulez.h"
////////////////////////////////////////////////////////////////////////////
namespace misc 
{
	std::string RPC_SERVICE_NAME_STR = std::string(CRYPTONOTE_ASSET_NAME)+"-RPC";
	const char * RPC_SERVICE_NAME = RPC_SERVICE_NAME_STR.c_str();
	
	std::string DEFAULT_CONFIG = std::string(CRYPTONOTE_ASSET_TICKER) + "-rpc.ini";
	
	std::string STR_0001 = "serviceHandler";
	std::string STR_0002 = "Stop signal caught";
	std::string STR_0003 = "WindowsService";
	std::string STR_0004 = std::string(CRYPTONOTE_ASSET_NAME)+"_RPC";
	std::string STR_0005 = "Payment Gate";
	// to LPSTR = const_cast<char *>(misc::STR_0005.c_str())
	
	std::string STR_0006 = "Couldn't make RegisterServiceCtrlHandler call: ";
	std::string STR_0007 = "Couldn't make SetServiceStatus call: ";
	std::string STR_0008 = "Error occurred: ";
	std::string STR_0009 = "RunService";
	std::string STR_0010 = "Couldn't start service: ";
	std::string STR_0011 = "Service stopped";
	std::string STR_0012 = "ServiceRegistrator";
	std::string STR_0013 = "ServiceDeregistrator";
	
} 
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


