// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The WiFicoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef WIFICOIN_WIFICOINCONSENSUS_H
#define WIFICOIN_WIFICOINCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_WIFICOIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/wificoin-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBWIFICOINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define WIFICOINCONSENSUS_API_VER 1

typedef enum wificoinconsensus_error_t
{
    wificoinconsensus_ERR_OK = 0,
    wificoinconsensus_ERR_TX_INDEX,
    wificoinconsensus_ERR_TX_SIZE_MISMATCH,
    wificoinconsensus_ERR_TX_DESERIALIZE,
    wificoinconsensus_ERR_AMOUNT_REQUIRED,
    wificoinconsensus_ERR_INVALID_FLAGS,
} wificoinconsensus_error;

/** Script verification flags */
enum
{
    wificoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    wificoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    wificoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    wificoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    wificoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    wificoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    wificoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    wificoinconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = wificoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | wificoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               wificoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | wificoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               wificoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | wificoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int wificoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, wificoinconsensus_error* err);

EXPORT_SYMBOL int wificoinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, wificoinconsensus_error* err);

EXPORT_SYMBOL unsigned int wificoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // WIFICOIN_WIFICOINCONSENSUS_H
