// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers
// --------------------------------
#pragma once

#include <condition_variable>
#include <future>
#include <memory>
#include <mutex>

#include <boost/program_options/variables_map.hpp>

#include "IWalletLegacy.h"
#include "PasswordContainer.h"

#include "Common/ConsoleHandler.h"
#include "CryptoNoteCore/CryptoNoteBasicImpl.h"
#include "CryptoNoteCore/Currency.h"
#include "NodeRpcProxy/NodeRpcProxy.h"
#include "WalletLegacy/WalletHelper.h"

#include <Logging/LoggerRef.h>
#include <Logging/LoggerManager.h>

#include <System/Dispatcher.h>
#include <System/Ipv4Address.h>
#include "crypto/electrum-words.h"
// --------------------------------

namespace CryptoNote
{
	class simple_wallet : 
		public CryptoNote::INodeObserver, 
		public CryptoNote::IWalletLegacyObserver, 
		public CryptoNote::INodeRpcProxyObserver 
	{
	public:
		simple_wallet(System::Dispatcher& dispatcher, const CryptoNote::Currency& currency, Logging::LoggerManager& log);

		bool init(const boost::program_options::variables_map& vm);
		bool deinit();
		bool run();
		void stop();

		bool process_command(const std::vector<std::string> &args);
		std::string get_commands_str();

		const CryptoNote::Currency& currency() const { return m_currency; }
		
	private:

		Logging::LoggerMessage success_msg_writer(bool color = false) {
			return logger(Logging::INFO, color ? Logging::GREEN : Logging::DEFAULT);
		}

		Logging::LoggerMessage fail_msg_writer() const {
			auto msg = logger(Logging::ERROR, Logging::BRIGHT_RED);
			msg << "Error: ";
			return msg;
		}

		void handle_command_line(const boost::program_options::variables_map& vm);

		bool run_console_handler();

		bool new_wallet
		(
			const std::string &wallet_file, 
			const std::string& password,
			const Crypto::SecretKey& recovery_key,
			const Crypto::SecretKey& secondary_key,
			bool is_recovery, 
			bool is_copy,
			bool is_deterministic
		);
		
		bool open_wallet(const std::string &wallet_file, const std::string& password);
		bool close_wallet();
		bool help(const std::vector<std::string> &args = std::vector<std::string>());
		bool exit(const std::vector<std::string> &args);
		bool start_mining(const std::vector<std::string> &args);
		bool stop_mining(const std::vector<std::string> &args);
		bool show_balance(const std::vector<std::string> &args = std::vector<std::string>());
		bool show_incoming_transfers(const std::vector<std::string> &args);
		bool show_payments(const std::vector<std::string> &args);
		bool show_blockchain_height(const std::vector<std::string> &args);
		bool read_only_wallet(const std::vector<std::string> &args);
		bool paper(const std::vector<std::string> &args);
		bool silent_mode(const std::vector<std::string> &args);
		bool paper_prn(const std::vector<std::string> &args);
		bool listTransfers(const std::vector<std::string> &args);
		bool listComments(const std::vector<std::string> &args);
		bool transfer(const std::vector<std::string> &args);
		bool print_address(const std::vector<std::string> &args = std::vector<std::string>());
		bool print_keys(const std::vector<std::string> &args = std::vector<std::string>());
		bool print_seed(const std::vector<std::string> &args = std::vector<std::string>());
		bool testing(const std::vector<std::string> &args);
		bool save(const std::vector<std::string> &args);
		bool reset(const std::vector<std::string> &args);
		bool set_log(const std::vector<std::string> &args);
		bool change_password(const std::vector<std::string> &args);

		bool ask_wallet_create_if_needed();
		std::string resolveAlias(const std::string& aliasUrl);
//z
		bool try_seed(std::string& electrum_words, AccountKeys keys);
		bool print_paper_wallet_to_stream(bool _is_to_file, std::ostream& _stream);
		bool print_paper_wallet(const std::string _file_name);
//z
		void printConnectionError() const;

		//---------------- IWalletLegacyObserver -------------------------
		virtual void initCompleted(std::error_code result) override;
		virtual void externalTransactionCreated(CryptoNote::TransactionId transactionId) override;
		virtual void synchronizationCompleted(std::error_code result) override;
		virtual void synchronizationProgressUpdated(uint32_t current, uint32_t total) override;
		//----------------------------------------------------------

		//----------------- INodeRpcProxyObserver --------------------------
		virtual void connectionStatusUpdated(bool connected) override;
		//----------------------------------------------------------

		friend class refresh_progress_reporter_t;

		class refresh_progress_reporter_t
		{
			public:
				refresh_progress_reporter_t(CryptoNote::simple_wallet& simple_wallet)
				: m_simple_wallet(simple_wallet)
				, m_blockchain_height(0)
				, m_blockchain_height_update_time()
				, m_print_time()
				{
				}

				void update(uint64_t height, bool force = false)
				{
					auto current_time = std::chrono::system_clock::now();
					
					if (std::chrono::seconds(m_simple_wallet.currency().difficultyTarget() / 2) < current_time - m_blockchain_height_update_time || m_blockchain_height <= height) {
						update_blockchain_height();
						m_blockchain_height = (std::max)(m_blockchain_height, height);
					}

					if (std::chrono::milliseconds(1) < current_time - m_print_time || force) {
						std::cout << "Height " << height << " of " << m_blockchain_height << '\r';
						m_print_time = current_time;
					}
				}

			private:
				void update_blockchain_height()
				{
				uint64_t blockchain_height = m_simple_wallet.m_node->getLastLocalBlockHeight();
				m_blockchain_height = blockchain_height;
				m_blockchain_height_update_time = std::chrono::system_clock::now();
				}

			private:
				CryptoNote::simple_wallet& m_simple_wallet;
				uint64_t m_blockchain_height;
				std::chrono::system_clock::time_point m_blockchain_height_update_time;
				std::chrono::system_clock::time_point m_print_time;
		};

	private:
		std::string m_wallet_file_arg;
		std::string m_generate_new;
		std::string m_import_path;

		std::string m_daemon_address;
		std::string m_daemon_host;
		uint16_t m_daemon_port;

		std::string m_wallet_file;
//z	
		//Crypto::SecretKey m_common_recovery_key; //key to use in recovery
		bool m_nocache;  // discard wallets cache
		bool m_is_recovery_mode;  // recovery mode, not new wallet
		bool m_is_copy; // is direct keys copy mode
		bool m_restore_seed;  // recovery by mnemoseed flag
		bool m_restore_keys;  // recovery by hexadecimal wallet keys flag
		bool m_restore_legacy;  // recovery by old-style recovery key flag
		bool m_restore_ro;  // create readonly wallet flag
		bool m_classic;  // old 2-random non_deterministic wallet generation	
		bool m_silent_mode; // suppress some output if true
		std::string m_seed;  // electrum-style seed parameter
		std::string m_legacy_key;  // old-style recovery key string
		std::string m_spend_key;  // Private Spend key string
		std::string m_view_key;  // Private View key string
		std::string m_address;  // Wallet address string
		std::string m_pass;  // Wallet password
		
		Crypto::SecretKey m_spend_secret_key;  // Private Spend Key
		Crypto::SecretKey m_view_secret_key;  // Private View Key
//z	
		std::unique_ptr<std::promise<std::error_code>> m_initResultPromise;

		Common::ConsoleHandler m_consoleHandler;
		const CryptoNote::Currency& m_currency;
		Logging::LoggerManager& logManager;
		System::Dispatcher& m_dispatcher;
		Logging::LoggerRef logger;
		Tools::PasswordContainer pwd_container;

		std::unique_ptr<CryptoNote::NodeRpcProxy> m_node;
		std::unique_ptr<CryptoNote::IWalletLegacy> m_wallet;
		refresh_progress_reporter_t m_refresh_progress_reporter;

		bool m_walletSynchronized;
		std::mutex m_walletSynchronizedMutex;
		std::condition_variable m_walletSynchronizedCV;
  };
}
// --------------------------------
// --------------------------------
// --------------------------------
