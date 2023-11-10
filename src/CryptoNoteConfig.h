// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers
////////////////////////////////////////////////////////////////////////////
#pragma once

#include "rulez.h"

#include <stdint.h>
#include <initializer_list>
////////////////////////////////////////////////////////////////////////////

namespace CryptoNote 
{
	namespace parameters 
	{
		const uint64_t 		CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
		const std::size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
		const std::size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
		const uint64_t 		CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = ADDRESS_BASE58_PREFIX;//Prefix of the wallet address: start with 135=ZZP, 117=SLD
		const std::size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 18;
		const uint64_t 		CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;

		const std::size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 30;

		const uint64_t 		MONEY_SUPPLY                                  = static_cast<uint64_t>(-1);//Total amount of atomic units to be emitted.

		const std::size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
		const std::size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 1048576; //size of block (bytes) after which reward for block calculated using block size
		
		const std::size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 400; // 400 seems ok for Soldo
		const std::size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 8;

		const uint64_t COIN                                          = UINT64_C(100000000);// COIN - number of smallest units in one coin
		const uint64_t MINIMUM_FEE                                   = UINT64_C(1);// Transactions with less than this fee wouldn’t be accepted by daemons
		const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(2);//The amount bellow this value will be considered as dust: ZZP=1, SLD=2

		const uint64_t REAL_COINS_LIMITED_Z                          = UINT64_C(10000000);//Total amount of coins mineable with full reward
		const uint64_t REAL_COINS_LOWSPEED_Z                         = UINT64_C(2500000);//Total amount of coins mineable with limited reward
		const uint64_t MONEY_SUPPLY_MINEABLE_Z                       = REAL_COINS_LIMITED_Z*COIN;//Total amount of atomic units mineable with full reward
		const uint64_t MONEY_SUPPLY_LOWSPEED_Z                       = REAL_COINS_LOWSPEED_Z*COIN;//Total amount of atomic units mineable with limited reward
		const std::size_t   RUSH_BLOCKS_Z                            = 1000;//Premium rewarded blocks count
		const uint64_t RUSH_REWARD_Z                                 = (UINT64_C(100)*COIN);//Reward for a premium block
		const uint64_t COMMON_REWARD_Z                               = (UINT64_C(1)*COIN);//Reward for an ordinary block
		const uint64_t GENESIS_BLOCK_REWARD_Z						= (UINT64_C(50000));//Premine amount SLD=50000
		const std::size_t   RUSH_REWARD_LOCK_Z                            = 750000;//Premium rewarded blocks lock time

#ifdef IS_PREMINE_IN_ZERO_BLOCK
		const uint64_t INITIAL_BLOCKS_TO_SKIP_Z = 1;	
		const uint64_t ZERO_BLOCK_REWARD_Z = GENESIS_BLOCK_REWARD_Z*COIN;
		const uint64_t FIRST_BLOCK_REWARD_Z = 0;
#else
		const uint64_t INITIAL_BLOCKS_TO_SKIP_Z = 2;
		const uint64_t ZERO_BLOCK_REWARD_Z = 0;
		const uint64_t FIRST_BLOCK_REWARD_Z = GENESIS_BLOCK_REWARD_Z*COIN;
#endif

		const uint64_t DIFFICULTY_TARGET                             = 20;//Difficulty target is an ideal time period between blocks, in seconds
		const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
		
#ifndef PASSATELLI
	//SPAGHETTI code...
		const std::size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY/12; // blocks
		const std::size_t   DIFFICULTY_CUT                                = 60;//Timestamps to cut after sorting
		const std::size_t   DIFFICULTY_LAG                                = 20;//Lag of calculating the difficulty in terms of blocks

		static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");
#endif

		const std::size_t   DIFFICULTY_FNC_VER                            = 0;
		const std::size_t   DIFFICULTY_ZAWY_WINDOW                        = 30;

		const std::size_t   MAX_BLOCK_SIZE_INITIAL                        = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 4;
		const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
		const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

		const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
		const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

		const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = (60 * 60 * 4); //seconds, 4 hours
		const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = (60 * 60 * 8); //seconds, 8 hours
		const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

		const std::size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
		const std::size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
		const std::size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

		const std::size_t   X_MAX_OUTPUTS_COUNT_Z              		= 24; //max outputs per transa
		const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "chain.data";
		const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "idx.data";
		const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "cache.data";
		const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "mempool.data";
		const char     P2P_NET_DATA_FILENAME[]                       = "p2p.data";
		const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "chainidx.data";
		const char     MINER_CONFIG_FILE_NAME[]                      = "common.json";
	} // parameters

	const uint64_t TIMESTAMP_HACK_1_FUTURE_TIME_LIMIT_Z				= 60 * 7;//420 seconds/21 block = SLD
	const uint64_t ACCOUNT_CREATE_TIME_ACCURACY 					= 60 * 60 * 24; 
	
	const uint64_t FIRST_BLOCK_TIMESTAMP_Z							= 1509321600;

	const char     CRYPTONOTE_TICKER[]                           = CRYPTONOTE_ASSET_TICKER;
	const char     CRYPTONOTE_NAME[]                             = CRYPTONOTE_ASSET_NAME;
	const char     CRYPTONOTE_APP[]                              = CRYPTONOTE_ASSET_APP;

	const char GENESIS_COINBASE_TX_HEX[] = "010101ff00002101f0c11cb027ca12cb2b52d82bbe1851432ca1aabc5362375cddfb1c9606a8d135";

	const uint32_t GENESIS_NONCE                                 = 24;
	const char     GENESIS_WALLET_Z[]                            = "LaFwtcPWr5KhN5q1t5BYjxG6HqYph1x7B49AVdeWUewC1dMrFzXMuuJBo5YHQQRqQy7wRWQnctEcDY1eRQn76APPQycHeuj";

// HISTORY OF FORKS IN ORDER OF HAPPENS // --------------------------------	
	const uint64_t Z_FORK_BLOCK_0									= 0;//FAKE ONE, NO ANY FORKS REALLY
	const uint64_t Z_FORK_BLOCK_1									= 2;//UPGRADE_HEIGHT_V2
	const uint64_t Z_FORK_BLOCK_2									= 3;//UPGRADE_HEIGHT_V3
	const uint64_t Z_FORK_BLOCK_3									= 4;//UPGRADE_HEIGHT_V4
	const uint64_t Z_FORK_BLOCK_4									= 24000;// DIFFICULTY_ZAWY_START_BLOCK
	const uint64_t Z_FORK_BLOCK_5									= 377777;// TIMESTAMP_HACK_1_BLOCK_HEIGHT_Z
	const uint64_t Z_FORK_BLOCK_6									= 717969;// Soldo forked, two forks - Soldo and Goldo appeared
	const uint64_t Z_FORK_BLOCK_7									= 740622;// Soldo reward reduced /*0.01/
	const uint64_t Z_FORK_BLOCK_8									= 2368889;// Xoldo forked from Goldo
	const uint64_t Z_FORK_BLOCK_9									= 2382888;// Xoldo reward reduced to 1 atomic unit
	const uint64_t Z_FORK_BLOCK_10									= 10000000;// FUTURE - Xoldo fork to Argon2
	const uint64_t Z_FORK_BLOCK_11									= 0;// not happend yet
	const uint64_t Z_FORK_BLOCK_12									= 0;// not happend yet
	const uint64_t Z_FORK_BLOCK_13									= 0;// not happend yet
	
	const uint64_t BINARY_INPUT_STREAM_SERIALIZER_MAX_ARRAY_SIZE	= UINT64_C(536870912);//Easy magic by Zhe
	const uint64_t BINARY_INPUT_STREAM_SERIALIZER_MAX_STRING_SIZE	= UINT64_C(536870912);//Another magic by Zhe
	
	const uint64_t  MAX_ROOT_BLOCK_SIZE_Z							= 2048;//some shit checked @ checkRootBlockSize
	
	// CRYPTONOTE_NETWORK is defined @ \P2p\P2pNetworks.h !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	const uint8_t  TRANSACTION_VERSION_1                         =  1;
	const uint8_t  TRANSACTION_VERSION_2                         =  2;
	
	const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
	const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
	const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
	const uint8_t  BLOCK_MAJOR_VERSION_4                         =  4;
	const uint8_t  BLOCK_MAJOR_VERSION_5                         =  5;
	const uint8_t  BLOCK_MAJOR_VERSION_6                         =  6;
	const uint8_t  BLOCK_MAJOR_VERSION_7                         =  7;
	
	const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
	const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

	const std::size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT   =  10000;  //by default, blocks ids count in synchronizing
	const std::size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT       =  256;    //by default, blocks count in blocks downloading
	const std::size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT    =  1000;

	const int      P2P_DEFAULT_PORT                              =  33711; //daemons p2p talk
	const int      RPC_DEFAULT_PORT                              =  33712; //daemon to wallet talk
	const int      RPC_WALLET_PORT                               =  33717; //daemon to wallet talk
	const int      RPC_PAYS_PORT                                 =  33719; //daemon to wallet talk
	const int      P2P_PAYS_PORT                                 =  33718; //daemon to wallet talk

	const std::size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT           =  128;
	const std::size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT            =  64;

	const std::size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE     = 128 * 1024 * 1024; // 64 MB
	const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 16;
	const std::size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT= 70;
	const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 300;           // seconds
	const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
	const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 64;
	const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 10 seconds
	const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 5000;          // 10 seconds
	const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
	const std::size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT     = 5000;          // 10 seconds
	const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "ab99e468743e62c86e6d07a0db4f26db5fa6c46dc2ee899b459b3a205385d460";
	
	const uint32_t REBUILD_CACHE_DISPLAY_STEP					= 10000;

	const std::initializer_list<const char*> SEED_NODES = {
		"s1_soldo:33711",  
		"s2_soldo:33711",  
		"s3_soldo:33711",  
		"s4_soldo:33711",  
		"s5_soldo:33711",  
		"s6_soldo:33711",  
		"s1_soldo:33710",  
	};

	struct CheckpointData {
		uint32_t height;
		const char* blockId;
	};

#ifdef __GNUC__
__attribute__((unused))
#endif

	const std::initializer_list<CheckpointData> CHECKPOINTS = 
	{
		{ 10,       "9d9c8d35abe3df6d6b568ceaec0484ab4de90b117f449e3f20268d4c5157cd3c" },
		{ 500,      "6484b98d348a8bb912ccac1f57bf489e79b2e7f182fbcd85f9e6fb6cb9b75020" },
		{ 1000,     "e71a72d72446b61b70fb11bc4b9f5a9b4acbea772522876181aaab6cfeb9f8b3" },
		{ 5000,     "8c25c2783910ede539fa575edf7dbd8aae87e851081a163f51f4af381a3dc488" },
		{ 10000,    "9f5a62a04e0dea35f922c9c46240bc26d766c3cf9d45df62cc1dcb3a2b296042" },
		{ 20000,    "338b94eea1c836545b9ac52635bf56e793c4d7087327b8344f801d19d244efdc" },
		{ 24000,    "e191d6292e928410481ed6209c4d492e0f0eff82723f9a18031f85d3955dffc9" },
		{ 50000,    "d77bbc550a5e08502e8bd58e6cd5f0ec24ab00179135cd4eb99a9d7c74d8cc4e" },
		{ 75000,    "75a833470bff666bc414a5803ecd9bf1a7c19b75049ed6c4d5903690210f66fd" },
		{ 100000,   "2a9f74669832fe2e2a14129d4df423d8d2fa1547a0a24358a51fc71b810ff641" },
		{ 125000,   "776a8b2b40cf5297375b5813fde5480c6ae8525db35fad73b7b523d6d67771c8" },
		{ 150000,   "b8d953e0b5d81f8a2b0db3d3881107ec676d72e0368c88c25085a913830a6656" },
		{ 175000,   "6c8b5543f94a9fbc3914fdfd0a58277d8ff1879b1f173db6890f99425fecc3aa" },
		{ 200000,   "b529eb8efbd46d978d7ce48f18ab07bb1bf6d0e4ddb85adf9808aed781fc045b" },
		{ 225000,   "6ceb7e3443978adb2356608417bb3dd61184246979d42ad8131ab274b2138a18" },
		{ 250000,   "9269ae2275b997f5d5d34e14a40c89471cf0f5b127693cdb0ea9b4a58420d966" },
		{ 275000,   "94fb70d53ce490f44da2d15b5df8f7c498c721504c01c30e4cb6c58df26dafc7" },
		{ 300000,   "a2e254ad0064addff57808135d42ed84a42c89df93f4f3a7765d0bf0efa9b8fe" },
		{ 325000,   "a012f24b7f2a9d417a4e79a0634212aba806ec13fd78a9990e36f7339a1c0a7d" },
		{ 350000,   "aecc323b82167e13b6d0c26493af87f9b97fbbc6a5cc0e93ad46a388d0889ac0" },
		{ 377777,   "fda74af4c706dd90c3b1c229e844cb95c2f6247f412e90971355f41257599172" },
		{ 400000,   "9a7d7ac7c224ff4f9c0d7c5e8a3a749934b59747ddac04292253adb4b7f88f90" },
		{ 425000,   "a4d8679422aee196f51126bde457402b031f9abce3688980f5239b85ad515296" },
		{ 450000,   "bfb507c5057d273eb3b4a256a8e729f6e18de4b4cd4de9326de030b7cf30ad14" },
		{ 475000,   "76e9f6a822e3e3a9078132ce8b104701b1a9c55c990c4d2185631802da0b5fbe" },
		{ 500000,   "4569f0c235536786cc0d2057e1a8b9a857ed0d97e03542cc86fe4ba5756678eb" },
		{ 525000,   "eec5f77dd46dacc95ee1bf78c939bb6caef15f1a1614b5678cc288ccfbf7a7ab" },
		{ 550000,   "b920182434221a65d64726ce62bc9d9640cd7ad0e7358d1e1f8b6d02770e9813" },
		{ 575000,   "2d012a3dc3368e9083a8cdc8a21e2f4e384aaac2a6ca1fcd0bb3cf175a5d0ae8" },
		{ 600000,   "9f7306ae82b72b8c57a97a7a422825068c0187fc6f0f8aa4e067242d66f1de94" },
		{ 625000,   "465d13678c2bfe699ae4baf58a0e3c8b698b73d08cac548a6ed6df5bb38de8c2" },
		{ 650000,   "5a94c7f078099866ecaf2f8512692be48b1bff63685409e17ab1c09b3d701223" },
		{ 675000,   "c35bd4f1b8ac5f0c876855c28d463d39bea9721ca651d55f1dad32b7ac37a228" },
		{ 700000,   "f04a589aba3ab4104fd29d0aa1429e5e28ae25c63f90b7eefc489433dd6c6a6b" },
		{ 717969,   "a13f7f9871c7ed4d178e4aecbd64436ecb4bd888470034a508fee791907a6f79" },
		{ 725000,   "5e3f2475e31ec7d3eff5eb6e3d2b55755d5f3a9181f0631cf2d59d2fee8b31c8" },
		{ 740622,   "db434659e95bad3b00968bb0e16852bbbc59d0e208c0e2865d2f37e424c4530c" },
		{ 750000,   "37bdfddc9d0af0d672580e32d5ac1d95f23c107632c28f5639f0a5075d9ecb29" },
		{ 775000,   "71a6b61b287eb4aab81171490c94844ca5caa5fb480618156f3df0041877e7bb" },
		{ 800000,   "2fb0f7b23a734ab49e7ef4b34d8120a45f3f2b91a2626239234cbed4c626452f" },
		{ 825000,   "3d161f569521a7c636b892aff1ec2658a621bd129da515a2fec6fea932ef5643" },
		{ 850000,   "f85cfb4557d98974f14af9911f47450616bda1473e03c5858c592f2030e0958a" },
		{ 875000,   "74c5a04aca754591fb335d407282c0354bb1d7f9fa4dea00b391a24b9f427d58" },
		{ 900000,   "fe97d845062fd573ab594cf238c2bf710a12319bce2ddebeb121d77fb92f3888" },
		{ 925000,   "fee59465c8103864d81658e017ce0280fe9c767426a56ae56a62bf1bd4c68fba" },
		{ 950000,   "5d3bed7acfa0f47dfe1b0f47327220cc83cb7ddd6dd12dcbfaf4d391b89c85b7" },
		{ 975000,   "545b866348181ee7f8a9c3bf595ec56d5ae108019414e89bd7a9750c123a64c6" },
		{ 1000000,   "c16e8f57e815f37b2c6783616dfe5a26124578e250b7b90f4266ea724221108b" },
		{ 1025000,   "f74adf9f8d13eb17c92f697106076fe7edc40a334853ac319bfb6cab08aa0128" },
		{ 1050000,   "5b9829a212b2986a1d0a081ee6d3edee9d5a2612e4f072c21525819411822bdf" },
		{ 1075000,   "4046dd6a6782ebfbb6709e310df5a81f0d742a8f1d36acabd9d8656cb9e41229" },
		{ 1100000,   "d821cd83c4d76c96e1fd14141dc5df09765b692cf0f08e3cdcbe07bbb533f411" },
		{ 1111111,   "731410166ee9307adf693e4172c27ce3102a6fe330368549553731167ef089e4" },
		{ 1125000,   "8eb3000afed0ac949a7dacd16ced9435c953d737ef0e948e389f8da56907a388" },
		{ 1150000,   "154a414045d40b718fb163745397b9df93d9c552b9180e282a139d76f2d13b0a" },
		{ 1175000,   "fd6185a205a69d538f6fb0bb1b4e100ae45cdb4937a44ffd6a5d0c31b86235c1" },
		{ 1200000,   "aa06337eb359ec58172a33931e6be59b22aaceeaf16e67e9cf0f9f914c89cfb7" },
		{ 1225000,   "47cae233b46560f27c6f9a32be630e770dcf41abc5d521aedc01f8764bba14c4" },
		{ 1250000,   "171f1abd5dc48935d1b8a9b3f6a1e68f8977a7debe22d7db0d92d534614597f9" },
		{ 1275000,   "75ab22e2130aee49440f63f31f2e3eb5a7323072d5f0228caf3d4dec4dfcd606" },
		{ 1300000,   "ba599fd1c2f37dfbfb4cb67e9ab4930809af07301acc04fdcf0f3cc114a0deb5" },
		{ 1350000,   "39ce3e2cb03668b52f64cbf7e0cb69211b268ecb65e66d4b6d01ea97358f3286" },
		{ 1400000,   "7d0c53b36e6d7c59775f7845831d5e395b3c60bcb56048f05ffda7c239bc39d7" },
		{ 1450000,   "c7d5f263b8150fbd39752a4d3fd828cef73e3050cc07c60a82733f0380ba35fd" },
		{ 1500000,   "0c1b752a4348a4765512f7212907e9ff2a954bd4319384b32d18784985eacd40" },
		{ 1550000,   "5dd6ec4260b84aff861be863a406ef888e73909c2ceeb6a41599084aa1e4eef4" },
		{ 1600000,   "4795871ac6bf532c51dd0a926eca74c955a6ce92d29c29c398a5b7ed112354c0" },
		{ 1650000,   "557858bf30fc4dfe0f8b3f2ff73af50d58681e9b7223da20307cc59104569a58" },
		{ 1700000,   "30a34beb9792957e28eec0edb2e88ac2a954234812ded5629dcee7741c6eb307" },
		{ 1800000,   "3f20d85f6f6d411df6c12fb91cf10e2e293e57f84598a538e51fdf0bef1d9938" },
		{ 1900000,   "91985628883304ca2777d515424cb15c4e45848293294b8edda41b2d3fafc840" },
		{ 2000000,   "db0ead0f8e5663581bf58274fbb53b47b8f0022797cf6c4a4d16d823f867a9cb" },		
		{ 2100000,   "dbcf59b83513208f7bf2ba21474db7bbbbdadc2c6d0247e36a7bd2d44e020d73" },		
		{ 2200000,   "df5e5b72e32289844d49b51051979747dabd72434821ea8ff4bc661afe2fc868" },		
		{ 2222222,   "ae10829f494d65a2833d6691bb623bd5b33295dcee1d8507f70ffa4b183f09ee" },		

		{ 2228085,   "2192e5c39c0847c4e20867dd80670876f42105c9788793388bb30d03835318e8" },		
		{ 2228100,   "57233ed4996b183b45dff321a5d624f5afcf6447c8639ccfd431e914f7a710b3" },		
		{ 2228125,   "38ec595e80626a6e1989ade4476cce8e6422461c197857e0be22aaabc327a6b0" },		
		{ 2228150,   "bd741d2b8c67ba49240ea14cef25e9343d2658e1df4f15b02a8696eb789e667d" },		
		{ 2228175,   "ecb6037d8747ba1f40d5214a23fbc9b6e46970c7748c8cc632919a1e95a40cca" },		
		{ 2228200,   "6cd58918d901f40cfaa1514550c511124d9e0489cb269472e32c7fee04374e06" },		
		{ 2228225,   "e98c8d537befefb746922086213f3d877ff347267370f402149727aaf90865bf" },		
		{ 2228250,   "78ce713bcfd839312e0cc3ed72b534a03a50015cf0a3db25a9b6196a0c739f98" },		
		{ 2228275,   "89a3940df9cc4b338d53126a809cb643ac8ba9ac47dbd340b51752428d114c6a" },		
		{ 2228300,   "b4c2c49ffff9158d437aed5269f1fac8c415253d7c3387a3a6a005ffc703b778" },			
		
		{ 2244777,   "f484503e702a3ff8a5054a3ab2f32655327425ad2929bcb0328224a75705beaf" },		
		{ 2253666,   "5916fda38f4b88988961bad743cd80abc4120e518f8e8a18a03104c74ae2b5f2" },		
		{ 2257777,   "f01e8914fbcee5d5ad518a31f0dc4cb6715cbe161f6582bfce783b650c2ba76e" },		
		{ 2268050,   "75780f6fe42b8c5264319144bbc3822d2faab605a91995584ab818089dda90f6" },		
		{ 2268700,   "1845a4df7bff53dcf43d30f4a8bbee1c5eba855a5a95d52d62a97fc84b9b5e3b" },		
		{ 2289200,   "7c12db5dbdbca4f81c381188dbbbe7c9ff6c11342841516d11c417721919f5b2" },		
		{ 2293640,   "eb54329dac6b6a2b670c45519c1a81a86d0ac704326332f2d5121adacca0830e" },		
		{ 2300000,   "0933b4b03773787970dfa536faf99844f9df4f4dd0b2565af58745864d9527c1" },		
		{ 2318500,   "4a8c63321e835acbf49c2c293b806ee05f5bcd66d9694a14affd50d9958167af" },		
		{ 2339654,   "9b20b2c076d0d4945e26415e6815b6b20883e1eac88504aeb1d5ed483609bf97" },		
		
		{ 2400000,   "93b0a7d8360d1cb09bfc20bdeac84c67f3f249a7aedf8027fc88d809d08b7202" },		
		{ 2500000,   "804d70f0928967c45c5cf4aad68f1764b195113b440299d4ab37b4551261f11a" },		
		{ 2600000,   "ad75a0c0f9577caba7ee4a94d3010e23d15efd5b9185d0e95d81a4c586ff5a98" },		
		{ 2700000,   "61f6d4ef5c3f563ecd73da62f6e8d3ab260a2098955cba36ca7e8633a1b0b12c" },		
		{ 2800000,   "08236d3b9c120ede4dfcef2f959e53919e39fcf8d99cb88a2363f532d8e335f3" },		
		{ 2900000,   "9facecfc69eff03bad8dfbd8f1da88d13bba4007d37ec4de6b6a8cec61583282" },		
		{ 3000000,   "5382c713b9bf352def675bce1164e91dbb4ed4de7215ecf64bd8bbcd63c4e0f5" },		
		{ 3100000,   "4ca65d43c09a786827a8f12318f5329358ff32872f2b34332e0c3b86f0a590a1" },		
		{ 3200000,   "70ca7adce1959d233c191c196d9007ceb89e61facd03f5b8de9f0c1158d282d3" },		
		{ 3300000,   "ba488636ea1d0bc44b517e796e7f8b2947810a1d405497afcfea6d1c61730992" },		
		{ 3400000,   "9d2a82c8f40179e84821dff44d5fdba248fd0c47d37b3aa8c01056a82c6abf7a" },		
		{ 3500000,   "44720fea6dbd5740e123757dfabc755f044e02ff4dbd2d3a2bf49517aaa4d7b8" },		
		{ 3600000,   "9b5d205667b584226d7448a4727a3c0ea918e885cebcb0a6c5ff1f7ab3a99b8b" },		
		{ 3700000,   "3ecee8bb592ef7d4d0898a5a707dfec7a4fcaba6d0c67bc0c1bf99bc194a2d9b" },		
		{ 3800000,   "0923c1ffa8ee188a0f2e01207c5e8f27b11105e47c6d25b22af1ae37c3d872cc" },		
		{ 3821111,   "63cc6217651e7259de7a670fdf0c84e5cba903973808d4a8b23b04013cbbf834" },
		{ 3840111,   "4863dcec7303a283b2a7eaf4b75ea9e2ea0268e509fa9e8d275e646e13a17f3b" },

		{ 3850000,	"22cb25cb310a1a5bf6aec195ce992bcc8aedd7a6d0baeb1286eb85347999f99a" },
		{ 3875000,	"3212202518588d439c178d5e3cb63e4e31d254cf3be755f1d87d8fbba55e6151" },
		{ 3900000,	"3a84d893e2edec594956a08440a06361511ad19c27bb6a1440f3744a99a7e4b2" },
		{ 3925000,	"70e252ade7955b245b93e31e7f41ff2512481652b2114087f9aa0246612f1098" },
		{ 3950000,	"9f66c9b6c60aae83841f3b6470596f9e30020e082621e555e49ef76d7bbf672a" },
		{ 3975000,	"959553836c0e12f4974d072bb0b336fb0ed52623163b0ba721bf2ad79ef3d08f" },
		{ 4000000,	"1024aea53de78272f05a16fa1cd9e69436c07d8c4bad059e64e960fdc20f7e23" },
		{ 4025000,	"49e4de16bb287d5e8a5a21b1b88fd7c0a4d0acc478d4f61dc38f27e413acc7ae" },
		{ 4050000,	"ab35660b84db7cbf97508d93843a6d05b2746720619a0483c945a9220d003720" },
		{ 4075000,	"faad8d28cce44182c10c5d82d8902e65d9e60260e52a8c2a7c63713d4795b3cb" },
		{ 4100000,	"20c7512945d6cd77d7174525ffeecba7dfe9b75730f671a277d2feb21d2d0e12" },
		{ 4125000,	"511628970b4afa81c8b922340086fb2dcfad6d4d10fc24feea9d11fb9bee86fc" },
		{ 4150000,	"5b11053f93398f999059b2d86824ded10709b625d45a6bcb652ee727a5e0e4d7" },
		{ 4175000,	"800c73ee85f1484ae293d1570af2bdb2817baf029476f95c253749e1dab3ff2e" },
		{ 4200000,	"11fe581a968ea6cc06d9eb9d9e3bbc834c826b4a44a1b7500ec77bd3fab2f90d" },
		{ 4225000,	"b9cf9125d266f1c3d1f7bbadd75d7735cdd67515342cc46393974948f58287d5" },
		{ 4250000,	"b35f030348dd031d842b0b45d792ad813281e193167e1865c8c7373144d8c7be" },
		{ 4275000,	"b480c653a6f0c186d0bcad576afad211aae4e6067f1f7ccd1163d6e2faf3f3af" },
		{ 4300000,	"72184161b3e3cfe0149a6aeb71308279f21193bd9eaea7526866e79848eb6388" },
		{ 4325000,	"57c5bfbdb3a2dc21dbc7dfb64af11174304683f370018bfb2df70423f3e1a61b" },
		{ 4350000,	"ebf84ab690e1592bf0f1db06f3f7522004460d2d42f0dc8cd7048e12217c9491" },
		{ 4375000,	"f7aa0b317d439467b0a376242b3a4a6efa01c8706050d1e5965f5ec57f1b5e26" },
		{ 4400000,	"81e72255bbb7ede420cc2428ca2dfa7bc327bc1a2d47be7b77767f703260ac62" },
		{ 4425000,	"0c799dbe75ce839cb8fa99e43980cd0ec25d6f6695b5a4f061f721b69851f424" },
		{ 4450000,	"85abd65a787ada66942be28015c13f8f32b746ddf57df7d9b59dbf3dce8d57eb" },
		{ 4475000,	"ad986db56d3e867b710362842c77697613e5bb6e150bfb5b7ff8f55a701dbc4c" },
		{ 4500000,	"a746da15656a43fc569058aa9987dcf2464d1e1455863010e3544183ac12b550" },
		{ 4525000,	"febbf7e55ff774eb8ef58c689e9979e12840e704bae62b9f41c7c50d1e6987fc" },
		{ 4550000,	"187eac4c0473cee8ee8da4a4f70e2f024e8adf09781e9f6f36f0c748194280d7" },
		{ 4575000,	"ba0636d5328933c2a501028aebbe75cc5491df3d1e2d682a36b721c588d86fc7" },
		{ 4600000,	"03a687551835598eba4a2ccad287b15050313cc0365080ddc0182a2712810d8a" },
		{ 4625000,	"157b43c98252f3a1b3517bc38b8154719aae49ef916b8e1a4e0264cdd8672c7e" },
		{ 4650000,	"ebaaadbea0a9e20f029918bac0076536acc8e779e3730cef2ef4c88236b663bc" },
		{ 4675000,	"bbe771502156c60a2fbcb966ee8e4111d90274dae9cf1c11b85beed31aa79771" },
		{ 4700000,	"0f66745034a93d0920626c75a7f7f47d8500a3dd045afa86adbe234717b0e424" },
		{ 4725000,	"8c0477b31cae67b9ea0820dce79709487df2df374b87ec4d3dc351c079ae4bd1" },
		{ 4750000,	"a97430ccaed7cb64fa639440e58ffff21e0f1bc1492ab4f3741ebc55f55b2729" },
		{ 4775000,	"9da4d008a17a9e6f08c1428a5051efb9ee5f782c99ca0f96e4de2299ffde4086" },
		{ 4800000,	"a786d110f8a722ee842608e40f54044658fcfabf01d3739b8359fa7e50b80dd1" },
		{ 4825000,	"a8a7441ffbddcd93e62bbe5b99aba653e432f2b52ee57a1df90f9326bc486808" },
		{ 4850000,	"88e0c349a28a2c48682b608acd1ca5d0d33be8f385ca7f6e1487539a573f3383" },
		{ 4875000,	"593e8ecf69e1805e44429010203727564ee7e0caaf3b0f1ee520be68cc14c132" },
		{ 4900000,	"8268bf156ed7f163f89ff91591057c987d65915993290323771e4d87129e605d" },
		{ 4925000,	"1dc3a6d8fefa14795a97214a9f67cc48c1426e0265a425b84314a13256708727" },
		{ 4950000,	"12d64b5f6d98f805f460e7cd7c648982c21faeb9c11b07501085661e8eeafa5b" },
		{ 4975000,	"1f464f1e4a9b10228c9b245b488d9cea553db9dca6263be387aaa902033438ac" },
		{ 5000000,	"7a9aabbab47262ee2bfc59b6f2c0b994eb059ca9881276d28d16478b743791a7" },
		{ 5025000,	"29bfa3ac1adf3b59da84857d2b06fd3c3561c531cd4a099785df1259daf91656" },
		{ 5050000,	"b77ea2865181009fa3e19c32e7039770643ccead1cc5211506c934e431fa1f8c" },
		{ 5075000,	"0260abac244f93d470bc93feaba63de8dc879aae09a91054dd73f2f5977aaf59" },
		{ 5100000,	"ee286ebde4758611f4594d874feeecbd81b3fc1290cac8e70e80244007465eaa" },
		{ 5125000,	"36445c07076a27d7c92a4dd17d4124cad609053c6bb8c93eb0ba255e124c1c25" },
		{ 5150000,	"f641095ce5cb8d4876f31bb8a5323ee9b8942ad37ae9e2cb8924d98d199651ce" },
		{ 5175000,	"466db5d6c04aeaf43ec25105048738a90243df2c326837b8a2fdf6f2ad5ce815" },
		{ 5200000,	"9243e333c6d5c145f90d59da0dc748aa89f2735e2ba5f972fbc08a590a1c9452" },
		{ 5225000,	"05a927f7a995bf714b27d0e6a1e9cf55ab271cef0b4071ca075e096d692e0fa0" },
		{ 5250000,	"88c4f478d3cee93b5ff4da488dcee68ee0788d47e19756c88d40145f065e78ca" },
		{ 5275000,	"7366b67edc6d7c11928acb41e31ac89b02913ae1d846cb0f161b609fb7ae85da" },
		{ 5300000,	"493f42d8a3d7a3d20bdd09e4e1f4271d299ad5c8364f24a82b5022af5a889a02" },
		{ 5325000,	"07ff8986972c8c52c5dbdbe02616957b7bbcfe75d3b3641d05ccd10e4bfe59b7" },
		{ 5350000,	"d6dff7114677bbaa91532fe7fa3a1dbbbe46c8646e622a27ea3dc8e98e4fa3cb" },
		{ 5375000,	"894792e452d85f9b99d7ce9fda2935b8d10782510e15aaab6d5d7d1393630dfd" },
		{ 5400000,	"2a1f0fd45433a11d0eb702c283c2665f730ce51531ba5d3af3a7d521376fc2df" },
		{ 5425000,	"bc404ce0416a27477c99c0f25362903b992a3f64beaa903e16ba369f900524af" },
		{ 5450000,	"8f18521f4c7f7cbdf1e77ec0caf9a16d3ba5dd2f3d7d0428e002fe02588003f4" },
		{ 5475000,	"7caded97bdb236c10791d0ce377f944bfe67a6a66af1c0d25d68513e6378f17c" },
		{ 5500000,	"e1bd567e493150b2acb58588cdee8e451692dfbb1065c307831f2f700b612b1c" },
		{ 5525000,	"3f8fe16635a3f3c1e37238f7a3c997b8918c441a1189e9d45374852c6baef84e" },
		{ 5550000,	"3611610dfa2e82800ecfc6c7803f41babf1c13a06a0b3d75687964a7eac9151e" },
		{ 5575000,	"f6540348ace72266830ed806862ee210c59ea0d9bd0992a90cf55f5f20acbd39" },
		{ 5600000,	"3cdbe791c3f19b9b57bd4cc957d5b82b7cb8681cfd8bca510328b25b0c9a7d60" },
		{ 5625000,	"9602e35c1522b7ba0a97bb0fdec5f24cf59610fecf76e7a525c94fbe6361828f" },
		{ 5650000,	"83c95b458ec123af01b2afffa89f72458f9a9988eb82685cacc91247f6cfd392" },
		{ 5675000,	"e7ddd56d20813f8cd065c864c14bd1eb1a58ed1b76da7488a266ee8d398f0878" },
		{ 5700000,	"5623b8eba51d128d2a61be148ca200e073ee884d100bc9eccad9d6693a1e6b62" },
		{ 5725000,	"ea4b331f9edbe34f347b10e2adefe8d0b01f99c27d84f06dc228ea0d928e1ee3" },
		{ 5750000,	"67bc1d3abbee5facd28c79f1d829cff27ba0479f856febd229ebf69669c4c74e" },
		{ 5775000,	"052ff3d66dec5785e8b2a575fac469f6df34b591158b5e8f6df8f8f02a9895a9" },
		{ 5800000,	"bc8279217d4ac2e5f2fafc145b5d8e4107f46eb0ef0ff6388a4baf929cb768d6" },
		{ 5825000,	"a83089cfe15e815dad6eceb6569d205deaa4a1828b75fc589e7e989d87e966d0" },
		{ 5850000,	"4a9e24837553a43e711e23a4db6ffe727d6cad4cd6e58d081d7c8920c29cbe97" },
		{ 5875000,	"4e9173e6615c9d57002c6e79fb511bc94fbc4eab4d9a8874d8735888d78363e5" },
		{ 5900000,	"443a7034734724ef40d2b58c5800c1982c89dd9cbca4c2476f9ba0707856b601" },
		{ 5925000,	"32b37834ca82ad429f9d632013a56072a5e0458fb5bc09f0f8f53c438199ce43" },
		{ 5950000,	"e6d146957a5e55498450abd163fc3ac47212a27cd1a30b26cd3e906cfd23d0bc" },
		{ 5975000,	"d865b867a5fb8cd2af2959819e3b0d92c71a950f2cf09830e5f242b57c280df9" },
		{ 6000000,	"90d25aa28d87848d6854b3c5cd8bb1a5ffd09a6585f03222086fb02cec7ba5b3" },
		{ 6025000,	"933a89614c428e223a154f93de6d7d61e1722028530098a42eedccb0368024ac" },
		{ 6050000,	"5ab7752d4f48ec97b58c428dc3a7dd9410f80e1b62d01fe10e255ca0643fefbc" },
		{ 6075000,	"04624d99d6ea667906a459b10cdd6af22de5da8a5b6e94d2457e6d067a9fa5f9" },
		{ 6100000,	"cf52f3c9d1ab46abcbcfd1d927a4cefa6255bc24d07702c16d85a39c78d7f0e6" },
		{ 6125000,	"ef6477e7c60f4a23ee01022e0896ba6a9179b7d5bf0147f5a89eb47ade968a82" },
		{ 6150000,	"01984543a6d660e316efbbd50aa82ba4f43add1b7f3349cc998e7ff2500c7f04" },
		{ 6175000,	"362d9cab826a93c3f60ae748b9ff56976b018f7a14cb91af64ab910f9393961a" },
		{ 6200000,	"cc0a826ed304e9447aea2591f9f280cc616f7fface382143a58b092d8f0332ec" },
		{ 6225000,	"bc3ac9df37a39beb57657350ce020c19a48363ef9074619ccdcfc7e85689560f" },
		{ 6250000,	"abe86b1918aecfc0a85bdd2db113e0624fe6157f08a6db98d1028741c898bdb3" },
		{ 6275000,	"bb6f0fc4d335dc3e355e7368be794bd455bc6242e217ba9a8d84f47584e8c146" },
		{ 6300000,	"0bc79bc777ebccf6ed293b124cbf1a0fb2647734688d60f2db7349de5a0c26e8" },
		{ 6325000,	"d71912b45fb052d2ae390795036491b5c68e5a3b913b6a37dd0914b2718229f2" },
		{ 6350000,	"5bcb2f5b856c07dc8ef5aaceae0733aa3fdb899cb6fc6761c05f00d4ebc8b615" },
		{ 6375000,	"2f119dab49cad47b3114906d106797ac64f59c277d7c81c6b058afcd36ca3ea6" },
		{ 6400000,	"a2a76025aa6db8ece6c3396019957d2e681f27fe0b216bb012d61cd3032378d7" },
		{ 6425000,	"1fd5a10898b77fdcf708b4ee6317e3b22354d0e1757078aa41530c4140b77420" },
		{ 6450000,	"9dfccec9f95707167a918df653f3bf017607e50e8af3f0d3e9b40d84689b7cbf" },
		{ 6475000,	"3cbc5791b9747c5a2c53ee19049d9e7c2edf9ccbdd05eef7f12bba84125cb00f" },
		{ 6500000,	"15b2334f6dbabab13100005747ed2c11d15127bafe21d69708891fd0d57e8bca" },
		{ 6525000,	"bc421963390335d8544e3db3bd2fea3edeb03a99c38b6b0ea2e50542f6a29373" },
		{ 6550000,	"c2c53e14752f1e9ce0561a746ca4ce4b1ab465fe0e2ecf9840933aa5e9a48ad2" },
		{ 6575000,	"9adc149436b60704769e7645d0a0abc9b484965a64ddc1a9d415a507fb215e7d" },
		{ 6600000,	"8d870e103f1c63965a370d6839a3e3fd5b960d29e52c2b2d79e9485d16620383" },
		{ 6625000,	"df90f211cff15dd3ef249e15e965163098a865a9f7c4f5d91b0ffd4a7be79dad" },
		{ 6650000,	"4d3d41ce0ca862befb8c33a87697da4517204562a87f7011299389b9b274f92e" },
		{ 6675000,	"e2cffd10fb7c351f8b7f8a5860864390bee5e095ea7059ddcd5ffda7d0e98efd" },
		{ 6700000,	"dd3a7405393ec3dafb51d861a4d0dc9c63413a487d178f72cae927179e1fb150" },
		{ 6725000,	"0593e2501cf76da2c45bf5c0ccdc408982727e331fb526f9fb7abdcfd0174cc0" },
		{ 6750000,	"3335a9c4f20d2101fb470c365a52c71825efa1fdf591cfd2d2591c7b63be35e7" },
		{ 6775000,	"582999f55720b487d1d0bd9d10707e9e8d506a3e022aee9650837bfd35c3b8c3" },
		{ 6800000,	"64c7671c674cd3a296e4b3e01defeaeae5bca8f7229525a951021608f9d11380" },
		{ 6825000,	"e2831838691111de2b3a0f94aee6a55ee04af83a2132ec5b8764a28bbe3246cc" },
		{ 6850000,	"d9a7d5c2d9c8a730069ac24cd9e30607052398f69e42222d85ef8fe6a583d468" },
		{ 6875000,	"db56060b355cc17692c90557d782b0160fa32fdcc29b5338bb69a0654ca4380a" },
		{ 6900000,	"f021e80e3df30266429a8e1cbf5c06083c0178752d70c8f0d116b87d3b87d20d" },
		{ 6925000,	"240d3d90d600bf9ff54462f1143b8760c7e69c4b6bc35fa4bda714eb6e7e35bc" },
		{ 6950000,	"096eff2319e0c90265f8d2fdc2c48b13f39ab2c5428711cb97e219a7e46a21cf" },
		{ 6975000,	"c3bc7c80d7e0f2328946a2d7bc7dabd7b849a07d22247104db3ef028e2b52737" },
		{ 7000000,	"fc5fb67fc15e4c1b13dbcf8c556be764f1db8c9c07b82d6925b48d385369ca1f" },
		{ 7025000,	"5c2afe2e897a8fa8a5e4f19da5f5e8bcfb855654dcadc9b6fc9baa01bf94620c" },
		{ 7050000,	"3e83723b645503cb8c3ad512191db1df3678f39d65a5f842c108e82edba0113d" },
		{ 7075000,	"f63991c6972e69bde69ec3e125dcfe036420a5ae6e55fffd66aa461fecfc67fb" },
		{ 7100000,	"5dcd277e65b9a58773fd4516c1ac572b36ed4447aae57681eec6a97deda5cf88" },
		{ 7125000,	"89f9018e315e4a73eaf75d05dab4931feaa1f7bb03ccbdfa6ea3ea3a89581c54" },
		{ 7150000,	"c6d428696300df30e5d0551383600497a50dc641e4882575fc157f155fbf8b28" },
		{ 7175000,	"6d7fbf36fce636bac433ec1f66a02782eb51b2f58d23ee160a4d0bcc14cfd9a1" },
		{ 7200000,	"a588477de08b785eabdbb232d1a9f58a4e1c047ff5b61b16816c282699fe6fe3" },
		{ 7225000,	"e78cc785611ca5f920941881646196873b4490b9fc362f599c8c07dfcf2a4b13" },
		{ 7250000,	"9174aca393ef12e8f0d1e9eab6bbfc835b29e8dc62a38df0caf85f3d954d02bd" },
		{ 7275000,	"9c267d1ecc3193f6658a10bdf44ad857dba622a1d58133037a5425415ccf278c" },
		{ 7300000,	"d8a7e9695bc2e107d95952aedc1dd312c3f32b95148f55390441854fc7a3c6ca" },
		{ 7325000,	"0557ccf827014f7fe2d1f5a4656078f8f8896f26a84f8615bd6a62bdea8fe380" },
		{ 7350000,	"ead5f4e54aaa15e5d2728d2d3792809a79d8593bc4aaad0bfd2ccf68c0e8f92c" },
		{ 7375000,	"03a02556d952046f5735d0738a33c4e16fda351478afe594a49a2c72b3574dfa" },
		{ 7400000,	"fb562018e04cffce2b4c805ff03684ccec92c1966d524ab0dc31f56edf9477af" },
		{ 7425000,	"f9c790f378c985b02487d98a9c3b84473c0fc0597d1e756c19de3c7aaed74ed5" },
		{ 7450000,	"7f4a8031c1c707cd1e8d00db52f2f0f8ee7cd327566a7863862d5f570fe77601" },
		{ 7475000,	"b0c89f797d805a8aace010472cd0c16d7cb314bbb8a81cd240543cfd4950f4a3" },
		{ 7500000,	"a316726a3634f09d1f79a9951f0bcb6ad1135a0e579acd0e9b50fc0abe1a07d5" },
		{ 7525000,	"531b842907b1b58cf33e2d73a4a08af1ba732a3658dd559f6ad2f516fafb4f56" },
		{ 7550000,	"98af765c4c3445a7f3d7da2634a2a248e14913ddedac7cc5170f5c1fec18918d" },
		{ 7575000,	"46bde9ee0633522cdc8b672f2fba93f98d09b420a22049b9ecff4c434c57f821" },
		{ 7600000,	"e9a4960b7cd4693355436e27c7311fdcb8f0f6fb835906e5de081f36b19eaeaa" },
		{ 7625000,	"1d148688feaad6a72fb0e5c4613827d3b8410b9bed58b27a5db5fa4db7f25f87" },
		{ 7650000,	"fb83fe275e726cc065d4db80b6d47c5911aaba1a0d11b480c08e69d1e02d2e72" },
		{ 7675000,	"e4a8058cd0dbbc3ab6c5c396df3d8e5c167451fcd4a03fe18651cccce4bc5676" },
		{ 7700000,	"e7b2d72f270f70d83b89f2769e8419d7eb612bc0a63b8c13aabc3b6a44a10953" },
		{ 7725000,	"c0594e5fae34fb42c549acbecffbc968aae254ccb077c33891338f098869c978" },
		{ 7750000,	"2fa09ca315d2f5bcdc43871b2f6ffcbca4167c70c532ddca49d17c9144de8574" },
		{ 7775000,	"dc4052f1859def8a5a726e853202e95d89ae7e32c4c6568ef46f6c8281cfea2a" },
		{ 7800000,	"d14f735e19c5b007c54d58c6188581d6189011e40c12cb67a165c85d3016932c" },
		{ 7825000,	"898ab60d3b7318ac635704a3b0b3c43a3c593bb960a2948f76e25383152ee3ed" },
		{ 7850000,	"0e68f042ccce68fae9aa11a8ae4e31583d536866a80e773b9dc0f72ec5629117" },
		{ 7875000,	"3a4989008ac2b73614bd2f7c8a5f6d628ac536f9b749a26a9233558e43f48ee3" },
		{ 7900000,	"a49377418f1e959bdc94dc568833e7c1cf9985f47c1ab9df638287a0fe0067d1" },
		{ 7925000,	"6f16a401e4c3a6397cbbe6e0692612d0e287af950d6172fc73ea5d356a81de28" },
		{ 7950000,	"a2f21ab0213ac6e9c85b34f911609237357f363ad2c1b2e22f5760d450a0e3fd" },
		{ 7975000,	"31add755f18f354844a20db939b13694d3eaff07a3650f5249761fef1e8357d4" },
		{ 8000000,	"51ff125bef2b8c4daab201cc00f6d14528a8155646a542a615cf118b4ffe3e34" },
		{ 8025000,	"ae7a51be3ff8f79dcac609315adfea1bfd7de1333e68e19b10b031cf964b8bf1" },
		{ 8050000,	"9c8b718e3ec2b3ff2c7bdeb861453b0ed1cdce4b1f49ea8dbd1ed43a5091a7c2" },
		{ 8075000,	"d8923c78bd7ddeadd39c54e6f190ea6cdb3d2ecb25d9b03fab74e7421e2f2204" },
		{ 8100000,	"7a8a3a6f0a34ead0e80f8f743c5309b7706ebdc0832d8f26bf29e19a99f56360" },
		{ 8125000,	"bc146a4be7bf51f044c954f5719c92c26abaa281a4f36425b763ba58ac676fe1" },
		{ 8150000,	"2007a71fd977b7d9e76a1b0a537d489c920f50e1a01f7d7b89b68f415dd86ae3" },
		{ 8175000,	"517639cd46a0dd2c7e5808f7063d7c63bdc162188ae2ac07b1dbcb04f408460b" },
		{ 8200000,	"ba6178d3e3ae5479c3c7c32fea8b60c9350e4b88782d7b5ce1494fe5749fcc24" },
		{ 8225000,	"5e23358d6cd2d237ac3ee620379ac3a5fde39dcf4c9c36e6348c7e0cde8ba84b" },
		{ 8250000,	"2fa021c1b0868047fcb96ac9fe1aa46c4e9f3b25712417f55a6e35596cc7f741" },
		{ 8275000,	"8368f643a3e1af8b515f9da12a24d41f177c9d2b721b7bd112f0757d48210360" },
		{ 8300000,	"436f80e7543f47e6367ce956a909f188bf85239644677e028dcf178a7b38f2e5" },
		{ 8325000,	"e84a7285dd0ad4ff601af59a2fa82596c4200bc83cceaf364374620a64a855bd" },
		{ 8350000,	"3a2abd05f155274ea857043429de0fbee8c936d840826fa8a5f8b7728951599d" },
		{ 8375000,	"763b92fc3b1970031097a3b09184ab33f74dc98f97bf5c0f574b570b079b6d38" },
		{ 8400000,	"1f3f442fd3d9cc5cc19a414cd29107d7f7fe29cb16e45e55f5ccff2e1a2d0511" },
		{ 8425000,	"37cb7f1daba58c50c3a25a78ac979f4d8a6355881ccf4393582337fb81e7ee6a" },
		{ 8450000,	"efd76fa3ebe6d2c559abe85352ebc953b013c6906d1a428f0aaac0caad36591c" },
		{ 8475000,	"f7c9ae9a5de3267f0be6e3a105f621543083af5d6290e1d903693d6cfe213232" },
		{ 8500000,	"c15364d11e13ac8f524a2e99c0bd913f30120805c8e4b92053d35c01f2ba22b1" },
		{ 8525000,	"710befcc8f951cc401d217963d1c876ecb311d28f31316428fc018d7004e7b89" },
		{ 8550000,	"40ffb9d5beed3948ae8a899d170719bbc7dd3ede3309da27f368f47cfe2edff5" },
		{ 8575000,	"b29b1b31e8a59316ef8670c65b3473096bd9c7960051ddbddce126cd1708a2e8" },
		{ 8600000,	"8d7f7f375a94b07f7d0e989fe1dc0b1102c0f9bfb245feb5ffcdb3be102727fe" },
		{ 8625000,	"955a7448f57f3437724589c28b1f6c2a913285a7466f0eca5ae58790d8eb5e2e" },
		{ 8650000,	"ef8857447e8b3495babefdc4b02f14db9ba6a5f3a43084842aed7c1dcb9387ec" },
		{ 8675000,	"298e844c0d0d7cdd12571a6eda0e6ef112a16fb7eb5c4b698f119a7eda1ca87b" },
		{ 8700000,	"77c6f793a00bcfef30033a75d806d53694813357de957c178f6c4c687fa7a665" },
		{ 8725000,	"fd64eb25008beaec52aa648334a2978264858981635eda00321ea63ab7181316" },
		{ 8750000,	"3d232db6cffdd5af3a520fc498a81449dd2bf4387e44a077a24c95fff24412c1" },
		{ 8775000,	"c97028591b53662cd6646bf5f6e03fc6d33e24e4f2d07e35b55cee1f7b339aca" },
		{ 8800000,	"326a6bbf46a8c232aac4feaedf33137c849cfb8e3afa9978ba986cbfe079f586" },
		{ 8825000,	"19a5e656ec65f18263f141261deaa0098f4f5eb4bd368b0a02e1e32a6b2ae745" },
		{ 8850000,	"056fa0e37fe0c299efc9140fb1de2b2e0c4b3fa0c2937795249b2ef98f329961" },
		{ 8875000,	"56c3003a97d43b9ecb25f30e56057480accbc6a5de43b664153f8a96412daa5b" },
		{ 8900000,	"1c670adc25e0dd76817ad0f4f04868715dae0bb31b79c4ab7b615965b3eab8f6" },
		{ 8925000,	"d16ee1f9042a22fc7bcef978140bf438ecce0f252243c769d35f4b5de2c34eb2" },
		{ 8950000,	"d9792a139527dcee7e657b888a27838ed9202bca352f6742032d1bbe2b89d205" },
		{ 8975000,	"4f08e7d751cf066040294d147ac02a20fe26e8e379c44361de886abc7462ace0" },
		{ 9000000,	"df8512e678539ed98a2a87049391b5235ea5fdf890409186bbdb62dbf89e45eb" },
		{ 9025000,	"cee1b99246d2471886c13846d79457e2b5169671e240fc37b8451149e3756dde" },
		{ 9050000,	"612d83438de117d1e3d0580f1bdebbf2ed4c6f4e94d0f403f2a12399e9b2d49a" },
		{ 9075000,	"1c4ec388b5310575f1d0b695660a1a832b397304552358873ee5a614d0621367" },
		{ 9100000,	"061ede3ee4797434e221d2a1846d0db58c206b0b968d9c519ab8c8a61613c180" },
		{ 9125000,	"84e43620193ea4fa15200472fcfcf124fffe284cc6262825861826b75276a4b2" },
		{ 9150000,	"8e5b0d57b54bd8477d019fd0b38627f444a5c22b2cb5ea2d1f9281b3200cd7c3" },
		{ 9175000,	"9affa3ef5e8cc83a7bc7c87e20ec11a91df0235cce154371f7f306adab21821c" },
		{ 9200000,	"cb03b43d5cb811f049def99255d871cf08203716ac48da571b8d97e046a30cc1" },
		{ 9225000,	"9cf69937c60d9f5ba062238a996043bdb3e358fdff25657155f95492fc97aff0" },
		{ 9250000,	"61ab2d0625d87a3675c7b4669ed905709617eb405ff4556d0b84ba2ee0c8a0b7" },
		{ 9275000,	"adcf48723ffb21b6c58aa4aab39d2c1071582abc8b7c97018cd7d372aedf9da4" },
		{ 9300000,	"618a5accedf987f3c3eaf40e2155566978ca0b48aa95777d48868cf04eee13e2" },
		{ 9325000,	"9bd6e90f4d4cf7693b3241e340eb69dda3d42b2e3bb3e234381673c67d7298d2" },
		{ 9350000,	"b60eb489cdf661d4d70fec969188cffc27f4b889eb77d77ac4b5f915cb6055c1" },
		{ 9375000,	"a847bf1867f7618b88ee8477a514b21322d136b801c368f345a878250d5a632d" },
		{ 9400000,	"4d48702293270d667491d7f3b2ea1ca706b0d879af3e69a5aa67263c464ea32a" },
		{ 9425000,	"4e09f0ebdd0d7813347ddf60f8a8527e41cd10a85e3369205a2fa79da309348a" },
		{ 9450000,	"6ecd4e8307a3cc186b91bd44af11aadef17b73c05e70574982ca055881ce47af" },
		{ 9475000,	"b4292c8dae7f4de82bde6f2587bcb091f1a554dcce54a9f598776ea22c4e7623" },
		{ 9500000,	"680ced9c17d2b12a50643579993764bb285a07d23c651511a8781e2c4b366f9b" },
		
	};

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


