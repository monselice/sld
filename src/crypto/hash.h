// Copyright (c) 2011-2016 The Cryptonote developers
// Copyright (c) 2014-2017 XDN-project developers
////////////////////////////////////////////////////////////////////////////
//Nebbiolo
//NEBBIOLO
#pragma once

#include "argon2.h"
#include <stddef.h>

#include <CryptoTypes.h>
#include "generic-ops.h"
////////////////////////////////////////////////////////////////////////////
//zz
// Nebbiolo Definitions
#define NEBBIOLO_HASHLEN 32 // The length of the resulting hash in bytes
#define NEBBIOLO_SALTLEN 16 // The length of our salt in bytes
#define NEBBIOLO_THREADS 1 // How many threads to use at once
#define NEBBIOLO_ITERS   1 // How many iterations we perform as part of our slow-hash
#define NEBBIOLO_MEMORY  512 // This value is in KiB (0.5MB)

//zz
namespace Crypto {

  extern "C" {
#include "hash-ops.h"
  }
////////////////////////////////////////////////////////////////////////////
//Cryptonight hash functions
////////////////////////////////////////////////////////////////////////////
  inline void cn_fast_hash(const void *data, size_t length, Hash &hash) {
    cn_fast_hash(data, length, reinterpret_cast<char *>(&hash));
  }
////////////////////////////////////////////////////////////////////////////
  inline Hash cn_fast_hash(const void *data, size_t length) {
    Hash h;
    cn_fast_hash(data, length, reinterpret_cast<char *>(&h));
    return h;
  }
////////////////////////////////////////////////////////////////////////////
  class cn_context {
  public:

    cn_context();
    ~cn_context();
#if !defined(_MSC_VER) || _MSC_VER >= 1800
    cn_context(const cn_context &) = delete;
    void operator=(const cn_context &) = delete;
#endif

  private:

    void *data;
    friend inline void cn_slow_hash(cn_context &, const void *, size_t, Hash &);
  };

  inline void cn_slow_hash(cn_context &context, const void *data, size_t length, Hash &hash) {
    (*cn_slow_hash_f)(context.data, data, length, reinterpret_cast<void *>(&hash));
  }
//zz
  inline void nebbiolo_slow_hash(const void *data, size_t length, Hash &hash) {
    uint8_t salt[NEBBIOLO_SALTLEN];
    memcpy(salt, data, sizeof(salt));
    argon2d_hash_raw(NEBBIOLO_ITERS, NEBBIOLO_MEMORY, NEBBIOLO_THREADS, data, length, salt, NEBBIOLO_SALTLEN, hash.data, NEBBIOLO_HASHLEN);
  }
//zz
  inline void tree_hash(const Hash *hashes, size_t count, Hash &root_hash) {
    tree_hash(reinterpret_cast<const char (*)[HASH_SIZE]>(hashes), count, reinterpret_cast<char *>(&root_hash));
  }

  inline void tree_branch(const Hash *hashes, size_t count, Hash *branch) {
    tree_branch(reinterpret_cast<const char (*)[HASH_SIZE]>(hashes), count, reinterpret_cast<char (*)[HASH_SIZE]>(branch));
  }

  inline void tree_hash_from_branch(const Hash *branch, size_t depth, const Hash &leaf, const void *path, Hash &root_hash) {
    tree_hash_from_branch(reinterpret_cast<const char (*)[HASH_SIZE]>(branch), depth, reinterpret_cast<const char *>(&leaf), path, reinterpret_cast<char *>(&root_hash));
  }

}
////////////////////////////////////////////////////////////////////////////
CRYPTO_MAKE_HASHABLE(Hash)
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
