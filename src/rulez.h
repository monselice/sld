//------------------------------------------------------------------------------
//rulez.h
//(c) Zhe@Soldo Clan -> zhe[@]soldo.in
//------------------------------------------------------------------------------
//LEGACY_CODEBASE - code inherited from XDN
//SOLDO_CODEBASE - code used in SLD apps
//GOLDO_CODEBASE - code used in GOLDO apps
//XOLDO_CODEBASE - code used in XOLDO apps
//QCC_CODEBASE - code used in QCC apps
//PASSATELLI - code will be used in next coins, so Soldo hacks will be placed inside #ifndef PASSATELLI / #endif
#include <stdint.h>
#include <string>
//------------------------------------------------------------------------------
#ifndef SOLDO_CODEBASE
	#define SOLDO_CODEBASE // Soldo codebase defined

#ifndef LEGACY_CODEBASE
	#define LEGACY_CODEBASE SOLDO_CODEBASE is always LEGACY_CODEBASE
#endif

//	#define IS_PREMINE_IN_ZERO_BLOCK
/*	
	const std::string 		CRYPTONOTE_ASSET_TICKER					=	"sld";
	const std::string 		CRYPTONOTE_ASSET_NAME					=	"Soldo";
	const std::string 		CRYPTONOTE_ASSET_APP					=	"soldo";
	const std::string 		CRYPTONOTE_ASSET_DAEMON					=	"sldd";
	const std::string 		CRYPTONOTE_ASSET_WALLET					=	"sldw";
*/	
	#define CRYPTONOTE_ASSET_TICKER 				"sld"
	#define CRYPTONOTE_ASSET_NAME   				"Soldo"
	#define CRYPTONOTE_ASSET_APP    				"soldo"
	#define CRYPTONOTE_ASSET_DAEMON 				"sldd";
	#define CRYPTONOTE_ASSET_WALLET 				"sldw";


	const std::string 		CRYPTONOTE_ASSET_WALLET_HD				=	"hdwallet";
	const std::string 		CRYPTONOTE_ASSET_WALLET_ADDRESS_PREFIX	=	"L";
	const std::string 		CRYPTONOTE_ASSET_LINK_COMMUNITY			=	"https://discord.gg/46xpPye";
	const std::string 		GITHUB_URL								=	"https://github.com/monselice/sld.git";
	const uint64_t	 		ADDRESS_BASE58_PREFIX					=	117;

#endif

//------------------------------------------------------------------------------
/*
#ifndef PASSATELLI
	//SPAGHETTI code...

#endif

#ifdef LEGACY_CODEBASE
	//SPAGHETTI code...

#endif
#ifdef PASSATELLI
	//PASSATELLI code...

#endif
*/
