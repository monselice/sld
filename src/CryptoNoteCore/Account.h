// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers
// --------------------------------
#include "CryptoNoteConfig.h"
#pragma once
#include <iostream>
//#include <chrono>
#include <ctime>
#include "CryptoNoteCore/CryptoNoteBasic.h"
#include "crypto/crypto.h"
// --------------------------------
namespace CryptoNote {

  class ISerializer;

  class AccountBase {
  public:
    AccountBase();
//    void generate();
//    void generate(bool _is_hdw);
//$$	
    static void generateViewFromSpend(Crypto::SecretKey&, Crypto::SecretKey&, Crypto::PublicKey&);
    static void generateViewFromSpend(Crypto::SecretKey&, Crypto::SecretKey&);	
//$$	
    void create_read_only(const CryptoNote::AccountPublicAddress& address, const Crypto::SecretKey& viewkey);
	Crypto::SecretKey generate_or_recover(const Crypto::SecretKey& recovery_key, const Crypto::SecretKey& secondary_key, bool is_recovery, bool is_copy, bool is_deterministic);

    const AccountKeys& getAccountKeys() const;
    void setAccountKeys(const AccountKeys& keys);
    uint64_t get_createtime() const { return m_creation_timestamp; }
    void set_createtime(uint64_t val) { m_creation_timestamp = val; }
    void serialize(ISerializer& s);

    template <class t_archive>
    inline void serialize(t_archive &a, const unsigned int /*ver*/) {
      a & m_keys;
      a & m_creation_timestamp;
    }

  private:
    void setNull();
    AccountKeys m_keys;
    uint64_t m_creation_timestamp;
  };
}
