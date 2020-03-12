// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers
// --------------------------------
#include "Checkpoints.h"
#include "Common/StringTools.h"
// --------------------------------
using namespace Logging;

namespace CryptoNote {
// --------------------------------
Checkpoints::Checkpoints(Logging::ILogger &log) : logger(log, "checkpoints") {}
// --------------------------------
bool Checkpoints::add_checkpoint(uint32_t height, const std::string &hash_str) {
  Crypto::Hash h = NULL_HASH;

  if (!Common::podFromHex(hash_str, h)) {
    logger(ERROR, Logging::RED) 
		<< "WRONG HASH IN CHECKPOINTS!!!";
    return false;
  }

  if (!(0 == m_points.count(height))) {
    logger(ERROR, Logging::RED) 
		<< "WRONG HASH IN CHECKPOINTS!!!";
    return false;
  }

  m_points[height] = h;
  return true;
}
// --------------------------------
bool Checkpoints::is_in_checkpoint_zone(uint32_t  height) const {
	return !m_points.empty() && (height <= (--m_points.end())->first);
}
// --------------------------------
bool Checkpoints::check_block(uint32_t  height, const Crypto::Hash &h, bool &is_a_checkpoint) const {
	
	auto it = m_points.find(height);
	
	is_a_checkpoint = it != m_points.end();
	
	if (!is_a_checkpoint) return true;

	if (it->second == h) {
		logger(Logging::INFO, Logging::CYAN) 
			<< "CHECKPOINT PASSED FOR HEIGHT " 
			<< height 
			<< " " 
			<< h;
			
		return true;
	} else {
		logger(Logging::ERROR, Logging::RED) 
			<< "CHECKPOINT FAILED FOR HEIGHT " << height
			<< ". EXPECTED HASH: " 
			<< it->second
			<< ", FETCHED HASH: " 
			<< h;
			
		return false;
	}
}
// --------------------------------
bool Checkpoints::check_block(uint32_t  height, const Crypto::Hash &h) const {
	bool ignored;
	
	return check_block(height, h, ignored);
}
// --------------------------------
bool Checkpoints::is_alternative_block_allowed(uint32_t  blockchain_height,
                                               uint32_t  block_height) const {
	if (0 == block_height) return false;

	if (block_height<blockchain_height-parameters::CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW) 
		{
			//it's too late, dude, the train left.
			logger(Logging::ERROR, Logging::RED) 
				<< "Too late, dude, the train left " 
				<< blockchain_height-block_height 
				<< " blocks ago, rejected...";
				
			return false;
		}

	auto it = m_points.upper_bound(blockchain_height);
  
	// Is blockchain_height before the first checkpoint?
	if (it == m_points.begin()) return true;

	--it;
	uint32_t  checkpoint_height = it->first;
	return checkpoint_height < block_height;
}
// --------------------------------
}
// --------------------------------
// --------------------------------
// --------------------------------
