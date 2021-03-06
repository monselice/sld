// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers
// --------------------------------
#pragma once

#include <future>
#include <map>
#include <mutex>
#include <iostream>

#include "crypto/hash.h"
#include "IWalletLegacy.h"
// --------------------------------
// --------------------------------
namespace CryptoNote {
	namespace WalletHelper {
	// --------------------------------
	class SaveWalletResultObserver : public CryptoNote::IWalletLegacyObserver {
		public:
			std::promise<std::error_code> saveResult;
			virtual void saveCompleted(std::error_code result) override { saveResult.set_value(result); }
	};
	// --------------------------------
	class InitWalletResultObserver : public CryptoNote::IWalletLegacyObserver {
		public:
			std::promise<std::error_code> initResult;
			virtual void initCompleted(std::error_code result) override { initResult.set_value(result); }
	};
	// --------------------------------
	class SendCompleteResultObserver : public CryptoNote::IWalletLegacyObserver {
		public:
			virtual void sendTransactionCompleted(CryptoNote::TransactionId transactionId, std::error_code result) override;
			std::error_code wait(CryptoNote::TransactionId transactionId);

		private:
			std::mutex m_mutex;
			std::condition_variable m_condition;
			std::map<CryptoNote::TransactionId, std::error_code> m_finishedTransactions;
			std::error_code m_result;
	};
	// --------------------------------
	class IWalletRemoveObserverGuard {
		public:
			IWalletRemoveObserverGuard(CryptoNote::IWalletLegacy& wallet, CryptoNote::IWalletLegacyObserver& observer);
			~IWalletRemoveObserverGuard();

			void removeObserver();

		private:
			CryptoNote::IWalletLegacy& m_wallet;
			CryptoNote::IWalletLegacyObserver& m_observer;
			bool m_removed;
	};
	// --------------------------------
	void prepareFileNames(const std::string& file_path, std::string& keys_file, std::string& wallet_file);
	void storeWallet_7111WL(CryptoNote::IWalletLegacy& wallet, const std::string& walletFilename, bool save_cache = true);
	}
// --------------------------------
}
// --------------------------------
// --------------------------------
// --------------------------------
