/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __WINCRYPT_H__
#define __WINCRYPT_H__

#include <_mingw.h>
#include <_mingw_unicode.h>
#include <guiddef.h>
#include <winapifamily.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _HRESULT_DEFINED
#define _HRESULT_DEFINED
  typedef LONG HRESULT;
#endif

#ifndef DECLSPEC_IMPORT
#ifndef __WIDL__
#define DECLSPEC_IMPORT __declspec(dllimport)
#else
#define DECLSPEC_IMPORT
#endif
#endif

#ifndef WINIMPM
#define WINIMPM DECLSPEC_IMPORT
#endif

#include <apisetcconv.h>

#ifndef WINAPI
#if defined(_ARM_)
#define WINAPI
#else
#define WINAPI __stdcall
#endif
#endif

#ifndef CALLBACK
#if defined(_ARM_)
#define CALLBACK
#else
#define CALLBACK __stdcall
#endif
#endif

#ifndef CONST
#define CONST const
#endif

#ifndef _NO_W32_PSEUDO_MODIFIERS
#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#ifndef OPTIONAL
#define OPTIONAL
#endif
#endif

#ifndef WINCRYPT32API
#define WINCRYPT32API WINIMPM
#endif

#ifndef WINCRYPT32STRINGAPI
#define WINCRYPT32STRINGAPI WINIMPM
#endif

#define GET_ALG_CLASS(x) (x & (7 << 13))
#define GET_ALG_TYPE(x) (x & (15 << 9))
#define GET_ALG_SID(x) (x & 511)

#define ALG_CLASS_ANY (0)
#define ALG_CLASS_SIGNATURE (1 << 13)
#define ALG_CLASS_MSG_ENCRYPT (2 << 13)
#define ALG_CLASS_DATA_ENCRYPT (3 << 13)
#define ALG_CLASS_HASH (4 << 13)
#define ALG_CLASS_KEY_EXCHANGE (5 << 13)
#define ALG_CLASS_ALL (7 << 13)

#define ALG_TYPE_ANY (0)
#define ALG_TYPE_DSS (1 << 9)
#define ALG_TYPE_RSA (2 << 9)
#define ALG_TYPE_BLOCK (3 << 9)
#define ALG_TYPE_STREAM (4 << 9)
#define ALG_TYPE_DH (5 << 9)
#define ALG_TYPE_SECURECHANNEL (6 << 9)
#if NTDDI_VERSION >= NTDDI_VISTA
#define ALG_TYPE_ECDH (7 << 9)
#endif
#if NTDDI_VERSION >= NTDDI_WIN10_RS1
#define ALG_TYPE_THIRDPARTY (8 << 9)
#endif

#define ALG_SID_ANY (0)

#if NTDDI_VERSION >= NTDDI_WIN10_RS1
#define ALG_SID_THIRDPARTY_ANY (0)
#endif

#define ALG_SID_RSA_ANY 0
#define ALG_SID_RSA_PKCS 1
#define ALG_SID_RSA_MSATWORK 2
#define ALG_SID_RSA_ENTRUST 3
#define ALG_SID_RSA_PGP 4

#define ALG_SID_DSS_ANY 0
#define ALG_SID_DSS_PKCS 1
#define ALG_SID_DSS_DMS 2
#if NTDDI_VERSION >= NTDDI_VISTA
#define ALG_SID_ECDSA 3
#endif

#define ALG_SID_DES 1
#define ALG_SID_3DES 3
#define ALG_SID_DESX 4
#define ALG_SID_IDEA 5
#define ALG_SID_CAST 6
#define ALG_SID_SAFERSK64 7
#define ALG_SID_SAFERSK128 8
#define ALG_SID_3DES_112 9
#define ALG_SID_SKIPJACK 10
#define ALG_SID_TEK 11
#define ALG_SID_CYLINK_MEK 12
#define ALG_SID_RC5 13
#if NTDDI_VERSION >= NTDDI_WINXP
#define ALG_SID_AES_128 14
#define ALG_SID_AES_192 15
#define ALG_SID_AES_256 16
#define ALG_SID_AES 17
#endif

#define CRYPT_MODE_CBCI 6
#define CRYPT_MODE_CFBP 7
#define CRYPT_MODE_OFBP 8
#define CRYPT_MODE_CBCOFM 9
#define CRYPT_MODE_CBCOFMI 10

#define ALG_SID_RC2 2

#define ALG_SID_RC4 1
#define ALG_SID_SEAL 2

#define ALG_SID_DH_SANDF 1
#define ALG_SID_DH_EPHEM 2
#define ALG_SID_AGREED_KEY_ANY 3
#define ALG_SID_KEA 4
#if NTDDI_VERSION >= NTDDI_VISTA
#define ALG_SID_ECDH 5
#define ALG_SID_ECDH_EPHEM 6
#endif

#define ALG_SID_MD2 1
#define ALG_SID_MD4 2
#define ALG_SID_MD5 3
#define ALG_SID_SHA 4
#define ALG_SID_SHA1 4
#define ALG_SID_MAC 5
#define ALG_SID_RIPEMD 6
#define ALG_SID_RIPEMD160 7
#define ALG_SID_SSL3SHAMD5 8
#define ALG_SID_HMAC 9
#define ALG_SID_TLS1PRF 10
#if NTDDI_VERSION >= NTDDI_WINXP
#define ALG_SID_HASH_REPLACE_OWF 11
#endif
#if NTDDI_VERSION > NTDDI_WINXPSP2
#define ALG_SID_SHA_256 12
#define ALG_SID_SHA_384 13
#define ALG_SID_SHA_512 14
#endif

#define ALG_SID_SSL3_MASTER 1
#define ALG_SID_SCHANNEL_MASTER_HASH 2
#define ALG_SID_SCHANNEL_MAC_KEY 3
#define ALG_SID_PCT1_MASTER 4
#define ALG_SID_SSL2_MASTER 5
#define ALG_SID_TLS1_MASTER 6
#define ALG_SID_SCHANNEL_ENC_KEY 7

#if NTDDI_VERSION >= NTDDI_VISTA
#define ALG_SID_ECMQV 1
#endif

#define ALG_SID_EXAMPLE 80

#ifndef ALGIDDEF
#define ALGIDDEF
  typedef unsigned int ALG_ID;
#endif

#define CALG_MD2 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD2)
#define CALG_MD4 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD4)
#define CALG_MD5 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MD5)
#define CALG_SHA (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA)
#define CALG_SHA1 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA1)
#define CALG_MAC (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_MAC)
#define CALG_RSA_SIGN (ALG_CLASS_SIGNATURE | ALG_TYPE_RSA | ALG_SID_RSA_ANY)
#define CALG_DSS_SIGN (ALG_CLASS_SIGNATURE | ALG_TYPE_DSS | ALG_SID_DSS_ANY)
#if NTDDI_VERSION >= NTDDI_WINXP
#define CALG_NO_SIGN (ALG_CLASS_SIGNATURE | ALG_TYPE_ANY | ALG_SID_ANY)
#endif
#define CALG_RSA_KEYX (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_RSA|ALG_SID_RSA_ANY)
#define CALG_DES (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_DES)
#define CALG_3DES_112 (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_3DES_112)
#define CALG_3DES (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_3DES)
#define CALG_DESX (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_DESX)
#define CALG_RC2 (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_RC2)
#define CALG_RC4 (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_STREAM|ALG_SID_RC4)
#define CALG_SEAL (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_STREAM|ALG_SID_SEAL)
#define CALG_DH_SF (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_DH|ALG_SID_DH_SANDF)
#define CALG_DH_EPHEM (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_DH|ALG_SID_DH_EPHEM)
#define CALG_AGREEDKEY_ANY (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_DH|ALG_SID_AGREED_KEY_ANY)
#define CALG_KEA_KEYX (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_DH|ALG_SID_KEA)
#define CALG_HUGHES_MD5 (ALG_CLASS_KEY_EXCHANGE|ALG_TYPE_ANY|ALG_SID_MD5)
#define CALG_SKIPJACK (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_SKIPJACK)
#define CALG_TEK (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_TEK)
#define CALG_CYLINK_MEK (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_CYLINK_MEK)
#define CALG_SSL3_SHAMD5 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SSL3SHAMD5)
#define CALG_SSL3_MASTER (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SSL3_MASTER)
#define CALG_SCHANNEL_MASTER_HASH (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SCHANNEL_MASTER_HASH)
#define CALG_SCHANNEL_MAC_KEY (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SCHANNEL_MAC_KEY)
#define CALG_SCHANNEL_ENC_KEY (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SCHANNEL_ENC_KEY)
#define CALG_PCT1_MASTER (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_PCT1_MASTER)
#define CALG_SSL2_MASTER (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_SSL2_MASTER)
#define CALG_TLS1_MASTER (ALG_CLASS_MSG_ENCRYPT|ALG_TYPE_SECURECHANNEL|ALG_SID_TLS1_MASTER)
#define CALG_RC5 (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_RC5)
#define CALG_HMAC (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_HMAC)
#define CALG_TLS1PRF (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_TLS1PRF)
#if NTDDI_VERSION >= NTDDI_WINXP
#define CALG_HASH_REPLACE_OWF (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_HASH_REPLACE_OWF)
#define CALG_AES_128 (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_AES_128)
#define CALG_AES_192 (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_AES_192)
#define CALG_AES_256 (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_AES_256)
#define CALG_AES (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_AES)
#endif
#if NTDDI_VERSION > NTDDI_WINXPSP2
#define CALG_SHA_256 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_256)
#define CALG_SHA_384 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_384)
#define CALG_SHA_512 (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_512)
#endif
#if NTDDI_VERSION >= NTDDI_VISTA
#define CALG_ECDH (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_DH | ALG_SID_ECDH)
#define CALG_ECDH_EPHEM (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_ECDH | ALG_SID_ECDH_EPHEM)
#define CALG_ECMQV (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_ANY | ALG_SID_ECMQV)
#define CALG_ECDSA (ALG_CLASS_SIGNATURE | ALG_TYPE_DSS | ALG_SID_ECDSA)
#define CALG_NULLCIPHER (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_ANY | 0)
#endif
#if NTDDI_VERSION >= NTDDI_WIN10_RS1
#define CALG_THIRDPARTY_KEY_EXCHANGE (ALG_CLASS_KEY_EXCHANGE | ALG_TYPE_THIRDPARTY | ALG_SID_THIRDPARTY_ANY)
#define CALG_THIRDPARTY_SIGNATURE (ALG_CLASS_SIGNATURE | ALG_TYPE_THIRDPARTY | ALG_SID_THIRDPARTY_ANY)
#define CALG_THIRDPARTY_CIPHER (ALG_CLASS_DATA_ENCRYPT | ALG_TYPE_THIRDPARTY | ALG_SID_THIRDPARTY_ANY)
#define CALG_THIRDPARTY_HASH (ALG_CLASS_HASH | ALG_TYPE_THIRDPARTY | ALG_SID_THIRDPARTY_ANY)
#endif

#if NTDDI_VERSION < NTDDI_WINXP
#define SIGNATURE_RESOURCE_NUMBER 0x29A

  typedef struct _VTableProvStruc {
    DWORD Version;
    FARPROC FuncVerifyImage;
    FARPROC FuncReturnhWnd;
    DWORD dwProvType;
    BYTE *pbContextInfo;
    DWORD cbContextInfo;
    LPSTR pszProvName;
  } VTableProvStruc, *PVTableProvStruc;
#endif

/* In ncrypt.h too */
#ifndef HCRYPTPROV_DEFINED
#define HCRYPTPROV_DEFINED
  typedef ULONG_PTR HCRYPTHASH;
  typedef ULONG_PTR HCRYPTKEY;
  typedef ULONG_PTR HCRYPTPROV;
#endif

#define CRYPT_VERIFYCONTEXT 0xf0000000
#define CRYPT_NEWKEYSET 0x8
#define CRYPT_DELETEKEYSET 0x10
#define CRYPT_MACHINE_KEYSET 0x20
#define CRYPT_SILENT 0x40
#if NTDDI_VERSION >= NTDDI_VISTA
#define CRYPT_DEFAULT_CONTAINER_OPTIONAL 0x80
#endif

#define CRYPT_EXPORTABLE 0x1
#define CRYPT_USER_PROTECTED 0x2
#define CRYPT_CREATE_SALT 0x4
#define CRYPT_UPDATE_KEY 0x8
#define CRYPT_NO_SALT 0x10
#define CRYPT_PREGEN 0x40
#define CRYPT_RECIPIENT 0x10
#define CRYPT_INITIATOR 0x40
#define CRYPT_ONLINE 0x80
#define CRYPT_SF 0x100
#define CRYPT_CREATE_IV 0x200
#define CRYPT_KEK 0x400
#define CRYPT_DATA_KEY 0x800
#define CRYPT_VOLATILE 0x1000
#define CRYPT_SGCKEY 0x2000
#if NTDDI_VERSION >= NTDDI_WINXP
#define CRYPT_ARCHIVABLE 0x4000
#endif
#if NTDDI_VERSION >= NTDDI_VISTA
#define CRYPT_FORCE_KEY_PROTECTION_HIGH 0x8000
#endif
#define CRYPT_USER_PROTECTED_STRONG 0x100000

#define RSA1024BIT_KEY 0x4000000

#define CRYPT_SERVER 0x400

#define KEY_LENGTH_MASK 0xffff0000

#define CRYPT_Y_ONLY 0x1
#define CRYPT_SSL2_FALLBACK 0x2
#define CRYPT_DESTROYKEY 0x4
#if NTDDI_VERSION >= NTDDI_WS03
#define CRYPT_DECRYPT_RSA_NO_PADDING_CHECK 0x20
#endif
#define CRYPT_OAEP 0x40
#define CRYPT_BLOB_VER3 0x80
#if NTDDI_VERSION >= NTDDI_WINXP
#define CRYPT_IPSEC_HMAC_KEY 0x100
#endif

#define CRYPT_SECRETDIGEST 0x1
#if NTDDI_VERSION >= NTDDI_WINXP
#define CRYPT_OWF_REPL_LM_HASH 0x1
#endif
#define CRYPT_LITTLE_ENDIAN 0x1

#define CRYPT_NOHASHOID 0x1
#define CRYPT_TYPE2_FORMAT 0x2
#define CRYPT_X931_FORMAT 0x4

#define CRYPT_MACHINE_DEFAULT 0x1
#define CRYPT_USER_DEFAULT 0x2
#define CRYPT_DELETE_DEFAULT 0x4

#define SIMPLEBLOB 0x1
#define PUBLICKEYBLOB 0x6
#define PRIVATEKEYBLOB 0x7
#define PLAINTEXTKEYBLOB 0x8
#define OPAQUEKEYBLOB 0x9
#define PUBLICKEYBLOBEX 0xa
#define SYMMETRICWRAPKEYBLOB 0xb
#if NTDDI_VERSION >= NTDDI_WS03
#define KEYSTATEBLOB 0xc
#endif

#define AT_KEYEXCHANGE 1
#define AT_SIGNATURE 2

#define CRYPT_USERDATA 1

#define KP_IV 1
#define KP_SALT 2
#define KP_PADDING 3
#define KP_MODE 4
#define KP_MODE_BITS 5
#define KP_PERMISSIONS 6
#define KP_ALGID 7
#define KP_BLOCKLEN 8
#define KP_KEYLEN 9
#define KP_SALT_EX 10
#define KP_P 11
#define KP_G 12
#define KP_Q 13
#define KP_X 14
#define KP_Y 15
#define KP_RA 16
#define KP_RB 17
#define KP_INFO 18
#define KP_EFFECTIVE_KEYLEN 19
#define KP_SCHANNEL_ALG 20
#define KP_CLIENT_RANDOM 21
#define KP_SERVER_RANDOM 22
#define KP_RP 23
#define KP_PRECOMP_MD5 24
#define KP_PRECOMP_SHA 25
#define KP_CERTIFICATE 26
#define KP_CLEAR_KEY 27
#define KP_PUB_EX_LEN 28
#define KP_PUB_EX_VAL 29
#define KP_KEYVAL 30
#define KP_ADMIN_PIN 31
#define KP_KEYEXCHANGE_PIN 32
#define KP_SIGNATURE_PIN 33
#define KP_PREHASH 34
#if NTDDI_VERSION >= NTDDI_WS03
#define KP_ROUNDS 35
#endif
#define KP_OAEP_PARAMS 36
#define KP_CMS_KEY_INFO 37
#define KP_CMS_DH_KEY_INFO 38
#define KP_PUB_PARAMS 39
#define KP_VERIFY_PARAMS 40
#define KP_HIGHEST_VERSION 41
#if NTDDI_VERSION >= NTDDI_WS03
#define KP_GET_USE_COUNT 42
#endif
#define KP_PIN_ID 43
#define KP_PIN_INFO 44

#define PKCS5_PADDING 1
#define RANDOM_PADDING 2
#define ZERO_PADDING 3

#define CRYPT_MODE_CBC 1
#define CRYPT_MODE_ECB 2
#define CRYPT_MODE_OFB 3
#define CRYPT_MODE_CFB 4
#define CRYPT_MODE_CTS 5

#define CRYPT_ENCRYPT 0x1
#define CRYPT_DECRYPT 0x2
#define CRYPT_EXPORT 0x4
#define CRYPT_READ 0x8
#define CRYPT_WRITE 0x10
#define CRYPT_MAC 0x20
#define CRYPT_EXPORT_KEY 0x40
#define CRYPT_IMPORT_KEY 0x80
#if NTDDI_VERSION >= NTDDI_WINXP
#define CRYPT_ARCHIVE 0x100
#endif

#define HP_ALGID 0x1
#define HP_HASHVAL 0x2
#define HP_HASHSIZE 0x4
#define HP_HMAC_INFO 0x5
#define HP_TLS1PRF_LABEL 0x6
#define HP_TLS1PRF_SEED 0x7

#define CRYPT_FAILED FALSE
#define CRYPT_SUCCEED TRUE

#define RCRYPT_SUCCEEDED(RT) ((RT) == CRYPT_SUCCEED)
#define RCRYPT_FAILED(RT) ((RT) == CRYPT_FAILED)

#define PP_ENUMALGS 1
#define PP_ENUMCONTAINERS 2
#define PP_IMPTYPE 3
#define PP_NAME 4
#define PP_VERSION 5
#define PP_CONTAINER 6
#define PP_CHANGE_PASSWORD 7
#define PP_KEYSET_SEC_DESCR 8
#define PP_CERTCHAIN 9
#define PP_KEY_TYPE_SUBTYPE 10
#define PP_PROVTYPE 16
#define PP_KEYSTORAGE 17
#define PP_APPLI_CERT 18
#define PP_SYM_KEYSIZE 19
#define PP_SESSION_KEYSIZE 20
#define PP_UI_PROMPT 21
#define PP_ENUMALGS_EX 22
#define PP_ENUMMANDROOTS 25
#define PP_ENUMELECTROOTS 26
#define PP_KEYSET_TYPE 27
#define PP_ADMIN_PIN 31
#define PP_KEYEXCHANGE_PIN 32
#define PP_SIGNATURE_PIN 33
#define PP_SIG_KEYSIZE_INC 34
#define PP_KEYX_KEYSIZE_INC 35
#define PP_UNIQUE_CONTAINER 36
#define PP_SGC_INFO 37
#define PP_USE_HARDWARE_RNG 38
#define PP_KEYSPEC 39
#define PP_ENUMEX_SIGNING_PROT 40
#if NTDDI_VERSION >= NTDDI_WS03
#define PP_CRYPT_COUNT_KEY_USE 41
#endif
#if NTDDI_VERSION >= NTDDI_VISTA
#define PP_USER_CERTSTORE 42
#define PP_SMARTCARD_READER 43
#define PP_SMARTCARD_GUID 45
#define PP_ROOT_CERTSTORE 46
#endif
#if NTDDI_VERSION >= NTDDI_WIN8
#define PP_SMARTCARD_READER_ICON 47
#endif

#define CRYPT_FIRST 1
#define CRYPT_NEXT 2
#define CRYPT_SGC_ENUM 4

#define CRYPT_IMPL_HARDWARE 1
#define CRYPT_IMPL_SOFTWARE 2
#define CRYPT_IMPL_MIXED 3
#define CRYPT_IMPL_UNKNOWN 4
#define CRYPT_IMPL_REMOVABLE 8

#define CRYPT_SEC_DESCR 0x1
#define CRYPT_PSTORE 0x2
#define CRYPT_UI_PROMPT 0x4

#define CRYPT_FLAG_PCT1 0x1
#define CRYPT_FLAG_SSL2 0x2
#define CRYPT_FLAG_SSL3 0x4
#define CRYPT_FLAG_TLS1 0x8
#define CRYPT_FLAG_IPSEC 0x10
#define CRYPT_FLAG_SIGNING 0x20

#define CRYPT_SGC 0x1
#define CRYPT_FASTSGC 0x2

#define PP_CLIENT_HWND 1
#define PP_CONTEXT_INFO 11
#define PP_KEYEXCHANGE_KEYSIZE 12
#define PP_SIGNATURE_KEYSIZE 13
#define PP_KEYEXCHANGE_ALG 14
#define PP_SIGNATURE_ALG 15
#define PP_DELETEKEY 24
#if NTDDI_VERSION >= NTDDI_VISTA
#define PP_PIN_PROMPT_STRING 44
#define PP_SECURE_KEYEXCHANGE_PIN 47
#define PP_SECURE_SIGNATURE_PIN 48
#endif
#if NTDDI_VERSION >= NTDDI_WIN10_RS5
#define PP_DISMISS_PIN_UI_SEC 49
#endif

#define PROV_RSA_FULL 1
#define PROV_RSA_SIG 2
#define PROV_DSS 3
#define PROV_FORTEZZA 4
#define PROV_MS_EXCHANGE 5
#define PROV_SSL 6
#define PROV_STT_MER 7
#define PROV_STT_ACQ 8
#define PROV_STT_BRND 9
#define PROV_STT_ROOT 10
#define PROV_STT_ISS 11
#define PROV_RSA_SCHANNEL 12
#define PROV_DSS_DH 13
#define PROV_EC_ECDSA_SIG 14
#define PROV_EC_ECNRA_SIG 15
#define PROV_EC_ECDSA_FULL 16
#define PROV_EC_ECNRA_FULL 17
#define PROV_DH_SCHANNEL 18
#define PROV_SPYRUS_LYNKS 20
#define PROV_RNG 21
#define PROV_INTEL_SEC 22
#if NTDDI_VERSION >= NTDDI_WINXP
#define PROV_REPLACE_OWF 23
#define PROV_RSA_AES 24
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)

#define MS_DEF_PROV __MINGW_NAME_UAW(MS_DEF_PROV)
#define MS_ENHANCED_PROV __MINGW_NAME_UAW(MS_ENHANCED_PROV)
#define MS_STRONG_PROV __MINGW_NAME_UAW(MS_STRONG_PROV)
#define MS_DEF_RSA_SIG_PROV __MINGW_NAME_UAW(MS_DEF_RSA_SIG_PROV)
#define MS_DEF_RSA_SCHANNEL_PROV __MINGW_NAME_UAW(MS_DEF_RSA_SCHANNEL_PROV)
#define MS_DEF_DSS_PROV __MINGW_NAME_UAW(MS_DEF_DSS_PROV)
#define MS_DEF_DSS_DH_PROV __MINGW_NAME_UAW(MS_DEF_DSS_DH_PROV)
#define MS_ENH_DSS_DH_PROV __MINGW_NAME_UAW(MS_ENH_DSS_DH_PROV)
#define MS_DEF_DH_SCHANNEL_PROV __MINGW_NAME_UAW(MS_DEF_DH_SCHANNEL_PROV)
#define MS_SCARD_PROV __MINGW_NAME_UAW(MS_SCARD_PROV)
#if NTDDI_VERSION >= NTDDI_WINXP
#define MS_ENH_RSA_AES_PROV_XP __MINGW_NAME_UAW(MS_ENH_RSA_AES_PROV_XP)
#define MS_ENH_RSA_AES_PROV __MINGW_NAME_UAW(MS_ENH_RSA_AES_PROV)
#endif

#define MS_DEF_PROV_A "Microsoft Base Cryptographic Provider v1.0"
#define MS_DEF_PROV_W L"Microsoft Base Cryptographic Provider v1.0"
#define MS_ENHANCED_PROV_A "Microsoft Enhanced Cryptographic Provider v1.0"
#define MS_ENHANCED_PROV_W L"Microsoft Enhanced Cryptographic Provider v1.0"
#define MS_STRONG_PROV_A "Microsoft Strong Cryptographic Provider"
#define MS_STRONG_PROV_W L"Microsoft Strong Cryptographic Provider"
#define MS_DEF_RSA_SIG_PROV_A "Microsoft RSA Signature Cryptographic Provider"
#define MS_DEF_RSA_SIG_PROV_W L"Microsoft RSA Signature Cryptographic Provider"
#define MS_DEF_RSA_SCHANNEL_PROV_A "Microsoft RSA SChannel Cryptographic Provider"
#define MS_DEF_RSA_SCHANNEL_PROV_W L"Microsoft RSA SChannel Cryptographic Provider"
#define MS_DEF_DSS_PROV_A "Microsoft Base DSS Cryptographic Provider"
#define MS_DEF_DSS_PROV_W L"Microsoft Base DSS Cryptographic Provider"
#define MS_DEF_DSS_DH_PROV_A "Microsoft Base DSS and Diffie-Hellman Cryptographic Provider"
#define MS_DEF_DSS_DH_PROV_W L"Microsoft Base DSS and Diffie-Hellman Cryptographic Provider"
#define MS_ENH_DSS_DH_PROV_A "Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider"
#define MS_ENH_DSS_DH_PROV_W L"Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider"
#define MS_DEF_DH_SCHANNEL_PROV_A "Microsoft DH SChannel Cryptographic Provider"
#define MS_DEF_DH_SCHANNEL_PROV_W L"Microsoft DH SChannel Cryptographic Provider"
#define MS_SCARD_PROV_A "Microsoft Base Smart Card Crypto Provider"
#define MS_SCARD_PROV_W L"Microsoft Base Smart Card Crypto Provider"
#if NTDDI_VERSION >= NTDDI_WINXP
#define MS_ENH_RSA_AES_PROV_A "Microsoft Enhanced RSA and AES Cryptographic Provider"
#define MS_ENH_RSA_AES_PROV_W L"Microsoft Enhanced RSA and AES Cryptographic Provider"
#define MS_ENH_RSA_AES_PROV_XP_A "Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"
#define MS_ENH_RSA_AES_PROV_XP_W L"Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"
#endif

#define MAXUIDLEN 64

#define EXPO_OFFLOAD_REG_VALUE "ExpoOffload"
#define EXPO_OFFLOAD_FUNC_NAME "OffloadModExpo"

#ifndef szKEY_CRYPTOAPI_PRIVATE_KEY_OPTIONS
#define szKEY_CRYPTOAPI_PRIVATE_KEY_OPTIONS "Software\\Policies\\Microsoft\\Cryptography"
#endif

#define szKEY_CACHE_ENABLED "CachePrivateKeys"
#define szKEY_CACHE_SECONDS "PrivateKeyLifetimeSeconds"

#if NTDDI_VERSION >= NTDDI_WINXP
#define szPRIV_KEY_CACHE_MAX_ITEMS "PrivKeyCacheMaxItems"
#define cPRIV_KEY_CACHE_MAX_ITEMS_DEFAULT 20

#define szPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS "PrivKeyCachePurgeIntervalSeconds"
#define cPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS_DEFAULT 86400
#endif

#define CUR_BLOB_VERSION 2

  typedef struct _CMS_KEY_INFO {
    DWORD dwVersion;
    ALG_ID Algid;
    BYTE *pbOID;
    DWORD cbOID;
  } CMS_KEY_INFO,*PCMS_KEY_INFO;

  typedef struct _HMAC_Info {
    ALG_ID HashAlgid;
    BYTE *pbInnerString;
    DWORD cbInnerString;
    BYTE *pbOuterString;
    DWORD cbOuterString;
  } HMAC_INFO,*PHMAC_INFO;

  typedef struct _SCHANNEL_ALG {
    DWORD dwUse;
    ALG_ID Algid;
    DWORD cBits;
    DWORD dwFlags;
    DWORD dwReserved;
  } SCHANNEL_ALG,*PSCHANNEL_ALG;
#define SCHANNEL_MAC_KEY 0x0
#define SCHANNEL_ENC_KEY 0x1

#define INTERNATIONAL_USAGE 0x1

  typedef struct _PROV_ENUMALGS {
    ALG_ID aiAlgid;
    DWORD dwBitLen;
    DWORD dwNameLen;
    CHAR szName[20];
  } PROV_ENUMALGS;

  typedef struct _PROV_ENUMALGS_EX {
    ALG_ID aiAlgid;
    DWORD dwDefaultLen;
    DWORD dwMinLen;
    DWORD dwMaxLen;
    DWORD dwProtocols;
    DWORD dwNameLen;
    CHAR szName[20];
    DWORD dwLongNameLen;
    CHAR szLongName[40];
  } PROV_ENUMALGS_EX;

  typedef struct _PUBLICKEYSTRUC {
    BYTE bType;
    BYTE bVersion;
    WORD reserved;
    ALG_ID aiKeyAlg;
  } BLOBHEADER,PUBLICKEYSTRUC;

  typedef struct _RSAPUBKEY {
    DWORD magic;
    DWORD bitlen;
    DWORD pubexp;
  } RSAPUBKEY;

  typedef struct _PUBKEY {
    DWORD magic;
    DWORD bitlen;
  } DHPUBKEY,DSSPUBKEY,KEAPUBKEY,TEKPUBKEY;

  typedef struct _DSSSEED {
    DWORD counter;
    BYTE seed[20];
  } DSSSEED;

  typedef struct _PUBKEYVER3 {
    DWORD magic;
    DWORD bitlenP;
    DWORD bitlenQ;
    DWORD bitlenJ;
    DSSSEED DSSSeed;
  } DHPUBKEY_VER3, DSSPUBKEY_VER3;

  typedef struct _PRIVKEYVER3 {
    DWORD magic;
    DWORD bitlenP;
    DWORD bitlenQ;
    DWORD bitlenJ;
    DWORD bitlenX;
    DSSSEED DSSSeed;
  } DHPRIVKEY_VER3,DSSPRIVKEY_VER3;

  typedef struct _KEY_TYPE_SUBTYPE {
    DWORD dwKeySpec;
    GUID Type;
    GUID Subtype;
  } KEY_TYPE_SUBTYPE,*PKEY_TYPE_SUBTYPE;

  typedef struct _CERT_FORTEZZA_DATA_PROP {
    unsigned char SerialNumber[8];
    int CertIndex;
    unsigned char CertLabel[36];
  } CERT_FORTEZZA_DATA_PROP;

#if NTDDI_VERSION >= NTDDI_WS03
  typedef struct _CRYPT_RC4_KEY_STATE {
    unsigned char Key[16];
    unsigned char SBox[256];
    unsigned char i;
    unsigned char j;
  } CRYPT_RC4_KEY_STATE,*PCRYPT_RC4_KEY_STATE;

  typedef struct _CRYPT_DES_KEY_STATE {
    unsigned char Key[8];
    unsigned char IV[8];
    unsigned char Feedback[8];
  } CRYPT_DES_KEY_STATE,*PCRYPT_DES_KEY_STATE;

  typedef struct _CRYPT_3DES_KEY_STATE {
    unsigned char Key[24];
    unsigned char IV[8];
    unsigned char Feedback[8];
  } CRYPT_3DES_KEY_STATE,*PCRYPT_3DES_KEY_STATE;
#endif

#if NTDDI_VERSION >= NTDDI_VISTA
  typedef struct _CRYPT_AES_128_KEY_STATE {
    unsigned char Key[16];
    unsigned char IV[16];
    unsigned char EncryptionState[11][16];
    unsigned char DecryptionState[11][16];
    unsigned char Feedback[16];
  } CRYPT_AES_128_KEY_STATE,*PCRYPT_AES_128_KEY_STATE;

  typedef struct _CRYPT_AES_256_KEY_STATE {
    unsigned char Key[32];
    unsigned char IV[16];
    unsigned char EncryptionState[15][16];
    unsigned char DecryptionState[15][16];
    unsigned char Feedback[16];
  } CRYPT_AES_256_KEY_STATE,*PCRYPT_AES_256_KEY_STATE;
#endif
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_APP)

#ifndef CRYPTO_BLOBS_DEFINED
#define CRYPTO_BLOBS_DEFINED
  typedef struct _CRYPTOAPI_BLOB {
    DWORD cbData;
    BYTE *pbData;
  } CRYPT_INTEGER_BLOB,*PCRYPT_INTEGER_BLOB,CRYPT_UINT_BLOB,*PCRYPT_UINT_BLOB,CRYPT_OBJID_BLOB,*PCRYPT_OBJID_BLOB,CERT_NAME_BLOB,*PCERT_NAME_BLOB,CERT_RDN_VALUE_BLOB,*PCERT_RDN_VALUE_BLOB,CERT_BLOB,*PCERT_BLOB,CRL_BLOB,*PCRL_BLOB,DATA_BLOB,*PDATA_BLOB,CRYPT_DATA_BLOB,*PCRYPT_DATA_BLOB,CRYPT_HASH_BLOB,*PCRYPT_HASH_BLOB,CRYPT_DIGEST_BLOB,*PCRYPT_DIGEST_BLOB,CRYPT_DER_BLOB,*PCRYPT_DER_BLOB,CRYPT_ATTR_BLOB,*PCRYPT_ATTR_BLOB;
#endif
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP) || defined(WINSTORECOMPAT)
  WINIMPM WINBOOL WINAPI CryptAcquireContextA (HCRYPTPROV *phProv, LPCSTR szContainer, LPCSTR szProvider, DWORD dwProvType, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptAcquireContextW (HCRYPTPROV *phProv, LPCWSTR szContainer, LPCWSTR szProvider, DWORD dwProvType, DWORD dwFlags);
#define CryptAcquireContext __MINGW_NAME_AW(CryptAcquireContext)
  WINIMPM WINBOOL WINAPI CryptReleaseContext (HCRYPTPROV hProv, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptGenRandom (HCRYPTPROV hProv, DWORD dwLen, BYTE *pbBuffer);
#endif
#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)
  typedef struct _CMS_DH_KEY_INFO {
    DWORD dwVersion;
    ALG_ID Algid;
    LPSTR pszContentEncObjId;
    CRYPT_DATA_BLOB PubInfo;
    void *pReserved;
  } CMS_DH_KEY_INFO,*PCMS_DH_KEY_INFO;

#define CryptSignHash __MINGW_NAME_AW(CryptSignHash)
#define CryptVerifySignature __MINGW_NAME_AW(CryptVerifySignature)
#define CryptSetProvider __MINGW_NAME_AW(CryptSetProvider)
#define CryptSetProviderEx __MINGW_NAME_AW(CryptSetProviderEx)
#define CryptGetDefaultProvider __MINGW_NAME_AW(CryptGetDefaultProvider)
#define CryptEnumProviderTypes __MINGW_NAME_AW(CryptEnumProviderTypes)
#define CryptEnumProviders __MINGW_NAME_AW(CryptEnumProviders)

  WINIMPM WINBOOL WINAPI CryptGenKey (HCRYPTPROV hProv, ALG_ID Algid, DWORD dwFlags, HCRYPTKEY *phKey);
  WINIMPM WINBOOL WINAPI CryptDeriveKey (HCRYPTPROV hProv, ALG_ID Algid, HCRYPTHASH hBaseData, DWORD dwFlags, HCRYPTKEY *phKey);
  WINIMPM WINBOOL WINAPI CryptDestroyKey (HCRYPTKEY hKey);
  WINIMPM WINBOOL WINAPI CryptSetKeyParam (HCRYPTKEY hKey, DWORD dwParam, CONST BYTE *pbData, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptGetKeyParam (HCRYPTKEY hKey, DWORD dwParam, BYTE *pbData, DWORD *pdwDataLen, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptSetHashParam (HCRYPTHASH hHash, DWORD dwParam, CONST BYTE *pbData, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptGetHashParam (HCRYPTHASH hHash, DWORD dwParam, BYTE *pbData, DWORD *pdwDataLen, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptSetProvParam (HCRYPTPROV hProv, DWORD dwParam, CONST BYTE *pbData, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptGetProvParam (HCRYPTPROV hProv, DWORD dwParam, BYTE *pbData, DWORD *pdwDataLen, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptGetUserKey (HCRYPTPROV hProv, DWORD dwKeySpec, HCRYPTKEY *phUserKey);
  WINIMPM WINBOOL WINAPI CryptExportKey (HCRYPTKEY hKey, HCRYPTKEY hExpKey, DWORD dwBlobType, DWORD dwFlags, BYTE *pbData, DWORD *pdwDataLen);
  WINIMPM WINBOOL WINAPI CryptImportKey (HCRYPTPROV hProv, CONST BYTE *pbData, DWORD dwDataLen, HCRYPTKEY hPubKey, DWORD dwFlags, HCRYPTKEY *phKey);
  WINIMPM WINBOOL WINAPI CryptEncrypt (HCRYPTKEY hKey, HCRYPTHASH hHash, WINBOOL Final, DWORD dwFlags, BYTE *pbData, DWORD *pdwDataLen, DWORD dwBufLen);
  WINIMPM WINBOOL WINAPI CryptDecrypt (HCRYPTKEY hKey, HCRYPTHASH hHash, WINBOOL Final, DWORD dwFlags, BYTE *pbData, DWORD *pdwDataLen);
  WINIMPM WINBOOL WINAPI CryptCreateHash (HCRYPTPROV hProv, ALG_ID Algid, HCRYPTKEY hKey, DWORD dwFlags, HCRYPTHASH *phHash);
  WINIMPM WINBOOL WINAPI CryptHashData (HCRYPTHASH hHash, CONST BYTE *pbData, DWORD dwDataLen, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptHashSessionKey (HCRYPTHASH hHash, HCRYPTKEY hKey, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptDestroyHash (HCRYPTHASH hHash);
  WINIMPM WINBOOL WINAPI CryptSignHashA (HCRYPTHASH hHash, DWORD dwKeySpec, LPCSTR szDescription, DWORD dwFlags, BYTE *pbSignature, DWORD *pdwSigLen);
  WINIMPM WINBOOL WINAPI CryptSignHashW (HCRYPTHASH hHash, DWORD dwKeySpec, LPCWSTR szDescription, DWORD dwFlags, BYTE *pbSignature, DWORD *pdwSigLen);
  WINIMPM WINBOOL WINAPI CryptVerifySignatureA (HCRYPTHASH hHash, CONST BYTE *pbSignature, DWORD dwSigLen, HCRYPTKEY hPubKey, LPCSTR szDescription, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptVerifySignatureW (HCRYPTHASH hHash, CONST BYTE *pbSignature, DWORD dwSigLen, HCRYPTKEY hPubKey, LPCWSTR szDescription, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptSetProviderA (LPCSTR pszProvName, DWORD dwProvType);
  WINIMPM WINBOOL WINAPI CryptSetProviderW (LPCWSTR pszProvName, DWORD dwProvType);
  WINIMPM WINBOOL WINAPI CryptSetProviderExA (LPCSTR pszProvName, DWORD dwProvType, DWORD *pdwReserved, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptSetProviderExW (LPCWSTR pszProvName, DWORD dwProvType, DWORD *pdwReserved, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptGetDefaultProviderA (DWORD dwProvType, DWORD *pdwReserved, DWORD dwFlags, LPSTR pszProvName, DWORD *pcbProvName);
  WINIMPM WINBOOL WINAPI CryptGetDefaultProviderW (DWORD dwProvType, DWORD *pdwReserved, DWORD dwFlags, LPWSTR pszProvName, DWORD *pcbProvName);
  WINIMPM WINBOOL WINAPI CryptEnumProviderTypesA (DWORD dwIndex, DWORD *pdwReserved, DWORD dwFlags, DWORD *pdwProvType, LPSTR szTypeName, DWORD *pcbTypeName);
  WINIMPM WINBOOL WINAPI CryptEnumProviderTypesW (DWORD dwIndex, DWORD *pdwReserved, DWORD dwFlags, DWORD *pdwProvType, LPWSTR szTypeName, DWORD *pcbTypeName);
  WINIMPM WINBOOL WINAPI CryptEnumProvidersA (DWORD dwIndex, DWORD *pdwReserved, DWORD dwFlags, DWORD *pdwProvType, LPSTR szProvName, DWORD *pcbProvName);
  WINIMPM WINBOOL WINAPI CryptEnumProvidersW (DWORD dwIndex, DWORD *pdwReserved, DWORD dwFlags, DWORD *pdwProvType, LPWSTR szProvName, DWORD *pcbProvName);
  WINIMPM WINBOOL WINAPI CryptContextAddRef (HCRYPTPROV hProv, DWORD *pdwReserved, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptDuplicateKey (HCRYPTKEY hKey, DWORD *pdwReserved, DWORD dwFlags, HCRYPTKEY *phKey);
  WINIMPM WINBOOL WINAPI CryptDuplicateHash (HCRYPTHASH hHash, DWORD *pdwReserved, DWORD dwFlags, HCRYPTHASH *phHash);
#if NTDDI_VERSION >= NTDDI_WS03
  WINBOOL __cdecl GetEncSChannel (BYTE **pData, DWORD *dwDecSize);
#endif
#endif

#ifndef _DDK_DRIVER_
  typedef ULONG_PTR HCRYPTPROV_OR_NCRYPT_KEY_HANDLE;
  typedef ULONG_PTR HCRYPTPROV_LEGACY;

#include <bcrypt.h>

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_APP)
#include <ncrypt.h>

  typedef struct _CRYPT_BIT_BLOB {
    DWORD cbData;
    BYTE *pbData;
    DWORD cUnusedBits;
  } CRYPT_BIT_BLOB,*PCRYPT_BIT_BLOB;

  typedef struct _CRYPT_ALGORITHM_IDENTIFIER {
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Parameters;
  } CRYPT_ALGORITHM_IDENTIFIER,*PCRYPT_ALGORITHM_IDENTIFIER;
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)
#define szOID_RSA "1.2.840.113549"
#define szOID_PKCS "1.2.840.113549.1"
#define szOID_RSA_HASH "1.2.840.113549.2"
#define szOID_RSA_ENCRYPT "1.2.840.113549.3"

#define szOID_PKCS_1 "1.2.840.113549.1.1"
#define szOID_PKCS_2 "1.2.840.113549.1.2"
#define szOID_PKCS_3 "1.2.840.113549.1.3"
#define szOID_PKCS_4 "1.2.840.113549.1.4"
#define szOID_PKCS_5 "1.2.840.113549.1.5"
#define szOID_PKCS_6 "1.2.840.113549.1.6"
#define szOID_PKCS_7 "1.2.840.113549.1.7"
#define szOID_PKCS_8 "1.2.840.113549.1.8"
#define szOID_PKCS_9 "1.2.840.113549.1.9"
#define szOID_PKCS_10 "1.2.840.113549.1.10"
#define szOID_PKCS_12 "1.2.840.113549.1.12"

#define szOID_RSA_RSA "1.2.840.113549.1.1.1"
#define szOID_RSA_MD2RSA "1.2.840.113549.1.1.2"
#define szOID_RSA_MD4RSA "1.2.840.113549.1.1.3"
#define szOID_RSA_MD5RSA "1.2.840.113549.1.1.4"
#define szOID_RSA_SHA1RSA "1.2.840.113549.1.1.5"
#define szOID_RSA_SETOAEP_RSA "1.2.840.113549.1.1.6"

#define szOID_RSAES_OAEP "1.2.840.113549.1.1.7"
#define szOID_RSA_MGF1 "1.2.840.113549.1.1.8"
#define szOID_RSA_PSPECIFIED "1.2.840.113549.1.1.9"
#define szOID_RSA_SSA_PSS "1.2.840.113549.1.1.10"
#define szOID_RSA_SHA256RSA "1.2.840.113549.1.1.11"
#define szOID_RSA_SHA384RSA "1.2.840.113549.1.1.12"
#define szOID_RSA_SHA512RSA "1.2.840.113549.1.1.13"

#define szOID_RSA_DH "1.2.840.113549.1.3.1"

#define szOID_RSA_data "1.2.840.113549.1.7.1"
#define szOID_RSA_signedData "1.2.840.113549.1.7.2"
#define szOID_RSA_envelopedData "1.2.840.113549.1.7.3"
#define szOID_RSA_signEnvData "1.2.840.113549.1.7.4"
#define szOID_RSA_digestedData "1.2.840.113549.1.7.5"
#define szOID_RSA_hashedData "1.2.840.113549.1.7.5"
#define szOID_RSA_encryptedData "1.2.840.113549.1.7.6"

#define szOID_RSA_emailAddr "1.2.840.113549.1.9.1"
#define szOID_RSA_unstructName "1.2.840.113549.1.9.2"
#define szOID_RSA_contentType "1.2.840.113549.1.9.3"
#define szOID_RSA_messageDigest "1.2.840.113549.1.9.4"
#define szOID_RSA_signingTime "1.2.840.113549.1.9.5"
#define szOID_RSA_counterSign "1.2.840.113549.1.9.6"
#define szOID_RSA_challengePwd "1.2.840.113549.1.9.7"
#define szOID_RSA_unstructAddr "1.2.840.113549.1.9.8"
#define szOID_RSA_extCertAttrs "1.2.840.113549.1.9.9"
#define szOID_RSA_certExtensions "1.2.840.113549.1.9.14"
#define szOID_RSA_SMIMECapabilities "1.2.840.113549.1.9.15"
#define szOID_RSA_preferSignedData "1.2.840.113549.1.9.15.1"

#define szOID_TIMESTAMP_TOKEN "1.2.840.113549.1.9.16.1.4"
#define szOID_RFC3161_counterSign "1.3.6.1.4.1.311.3.3.1"

#define szOID_RSA_SMIMEalg "1.2.840.113549.1.9.16.3"
#define szOID_RSA_SMIMEalgESDH "1.2.840.113549.1.9.16.3.5"
#define szOID_RSA_SMIMEalgCMS3DESwrap "1.2.840.113549.1.9.16.3.6"
#define szOID_RSA_SMIMEalgCMSRC2wrap "1.2.840.113549.1.9.16.3.7"

#define szOID_RSA_MD2 "1.2.840.113549.2.2"
#define szOID_RSA_MD4 "1.2.840.113549.2.4"
#define szOID_RSA_MD5 "1.2.840.113549.2.5"

#define szOID_RSA_RC2CBC "1.2.840.113549.3.2"
#define szOID_RSA_RC4 "1.2.840.113549.3.4"
#define szOID_RSA_DES_EDE3_CBC "1.2.840.113549.3.7"
#define szOID_RSA_RC5_CBCPad "1.2.840.113549.3.9"

#define szOID_ANSI_X942 "1.2.840.10046"
#define szOID_ANSI_X942_DH "1.2.840.10046.2.1"

#define szOID_X957 "1.2.840.10040"
#define szOID_X957_DSA "1.2.840.10040.4.1"
#define szOID_X957_SHA1DSA "1.2.840.10040.4.3"

#define szOID_ECC_PUBLIC_KEY "1.2.840.10045.2.1"
#define szOID_ECC_CURVE_P256 "1.2.840.10045.3.1.7"
#define szOID_ECC_CURVE_P384 "1.3.132.0.34"
#define szOID_ECC_CURVE_P521 "1.3.132.0.35"

#define szOID_ECC_CURVE_BRAINPOOLP160R1 "1.3.36.3.3.2.8.1.1.1"
#define szOID_ECC_CURVE_BRAINPOOLP160T1 "1.3.36.3.3.2.8.1.1.2"
#define szOID_ECC_CURVE_BRAINPOOLP192R1 "1.3.36.3.3.2.8.1.1.3"
#define szOID_ECC_CURVE_BRAINPOOLP192T1 "1.3.36.3.3.2.8.1.1.4"
#define szOID_ECC_CURVE_BRAINPOOLP224R1 "1.3.36.3.3.2.8.1.1.5"
#define szOID_ECC_CURVE_BRAINPOOLP224T1 "1.3.36.3.3.2.8.1.1.6"
#define szOID_ECC_CURVE_BRAINPOOLP256R1 "1.3.36.3.3.2.8.1.1.7"
#define szOID_ECC_CURVE_BRAINPOOLP256T1 "1.3.36.3.3.2.8.1.1.8"
#define szOID_ECC_CURVE_BRAINPOOLP320R1 "1.3.36.3.3.2.8.1.1.9"
#define szOID_ECC_CURVE_BRAINPOOLP320T1 "1.3.36.3.3.2.8.1.1.10"
#define szOID_ECC_CURVE_BRAINPOOLP384R1 "1.3.36.3.3.2.8.1.1.11"
#define szOID_ECC_CURVE_BRAINPOOLP384T1 "1.3.36.3.3.2.8.1.1.12"
#define szOID_ECC_CURVE_BRAINPOOLP512R1 "1.3.36.3.3.2.8.1.1.13"
#define szOID_ECC_CURVE_BRAINPOOLP512T1 "1.3.36.3.3.2.8.1.1.14"

#define szOID_ECC_CURVE_EC192WAPI "1.2.156.11235.1.1.2.1"
#define szOID_CN_ECDSA_SHA256 "1.2.156.11235.1.1.1"

#define szOID_ECC_CURVE_NISTP192 "1.2.840.10045.3.1.1"
#define szOID_ECC_CURVE_NISTP224 "1.3.132.0.33"
#define szOID_ECC_CURVE_NISTP256 szOID_ECC_CURVE_P256
#define szOID_ECC_CURVE_NISTP384 szOID_ECC_CURVE_P384
#define szOID_ECC_CURVE_NISTP521 szOID_ECC_CURVE_P521

#define szOID_ECC_CURVE_SECP160K1 "1.3.132.0.9"
#define szOID_ECC_CURVE_SECP160R1 "1.3.132.0.8"
#define szOID_ECC_CURVE_SECP160R2 "1.3.132.0.30"
#define szOID_ECC_CURVE_SECP192K1 "1.3.132.0.31"
#define szOID_ECC_CURVE_SECP192R1 szOID_ECC_CURVE_NISTP192
#define szOID_ECC_CURVE_SECP224K1 "1.3.132.0.32"
#define szOID_ECC_CURVE_SECP224R1 szOID_ECC_CURVE_NISTP224
#define szOID_ECC_CURVE_SECP256K1 "1.3.132.0.10"
#define szOID_ECC_CURVE_SECP256R1 szOID_ECC_CURVE_P256
#define szOID_ECC_CURVE_SECP384R1 szOID_ECC_CURVE_P384
#define szOID_ECC_CURVE_SECP521R1 szOID_ECC_CURVE_P521

#define szOID_ECC_CURVE_WTLS7 szOID_ECC_CURVE_SECP160R2
#define szOID_ECC_CURVE_WTLS9 "2.23.43.1.4.9"
#define szOID_ECC_CURVE_WTLS12 szOID_ECC_CURVE_NISTP224

#define szOID_ECC_CURVE_X962P192V1 "1.2.840.10045.3.1.1"
#define szOID_ECC_CURVE_X962P192V2 "1.2.840.10045.3.1.2"
#define szOID_ECC_CURVE_X962P192V3 "1.2.840.10045.3.1.3"
#define szOID_ECC_CURVE_X962P239V1 "1.2.840.10045.3.1.4"
#define szOID_ECC_CURVE_X962P239V2 "1.2.840.10045.3.1.5"
#define szOID_ECC_CURVE_X962P239V3 "1.2.840.10045.3.1.6"
#define szOID_ECC_CURVE_X962P256V1 szOID_ECC_CURVE_P256

#define szOID_ECDSA_SHA1 "1.2.840.10045.4.1"
#define szOID_ECDSA_SPECIFIED "1.2.840.10045.4.3"
#define szOID_ECDSA_SHA256 "1.2.840.10045.4.3.2"
#define szOID_ECDSA_SHA384 "1.2.840.10045.4.3.3"
#define szOID_ECDSA_SHA512 "1.2.840.10045.4.3.4"

#define szOID_NIST_AES128_CBC "2.16.840.1.101.3.4.1.2"
#define szOID_NIST_AES192_CBC "2.16.840.1.101.3.4.1.22"
#define szOID_NIST_AES256_CBC "2.16.840.1.101.3.4.1.42"

#define szOID_NIST_AES128_WRAP "2.16.840.1.101.3.4.1.5"
#define szOID_NIST_AES192_WRAP "2.16.840.1.101.3.4.1.25"
#define szOID_NIST_AES256_WRAP "2.16.840.1.101.3.4.1.45"

#define szOID_DH_SINGLE_PASS_STDDH_SHA1_KDF "1.3.133.16.840.63.0.2"
#define szOID_DH_SINGLE_PASS_STDDH_SHA256_KDF "1.3.132.1.11.1"
#define szOID_DH_SINGLE_PASS_STDDH_SHA384_KDF "1.3.132.1.11.2"

#define szOID_DS "2.5"
#define szOID_DSALG "2.5.8"
#define szOID_DSALG_CRPT "2.5.8.1"
#define szOID_DSALG_HASH "2.5.8.2"
#define szOID_DSALG_SIGN "2.5.8.3"
#define szOID_DSALG_RSA "2.5.8.1.1"

#define szOID_OIW "1.3.14"

#define szOID_OIWSEC "1.3.14.3.2"
#define szOID_OIWSEC_md4RSA "1.3.14.3.2.2"
#define szOID_OIWSEC_md5RSA "1.3.14.3.2.3"
#define szOID_OIWSEC_md4RSA2 "1.3.14.3.2.4"
#define szOID_OIWSEC_desECB "1.3.14.3.2.6"
#define szOID_OIWSEC_desCBC "1.3.14.3.2.7"
#define szOID_OIWSEC_desOFB "1.3.14.3.2.8"
#define szOID_OIWSEC_desCFB "1.3.14.3.2.9"
#define szOID_OIWSEC_desMAC "1.3.14.3.2.10"
#define szOID_OIWSEC_rsaSign "1.3.14.3.2.11"
#define szOID_OIWSEC_dsa "1.3.14.3.2.12"
#define szOID_OIWSEC_shaDSA "1.3.14.3.2.13"
#define szOID_OIWSEC_mdc2RSA "1.3.14.3.2.14"
#define szOID_OIWSEC_shaRSA "1.3.14.3.2.15"
#define szOID_OIWSEC_dhCommMod "1.3.14.3.2.16"
#define szOID_OIWSEC_desEDE "1.3.14.3.2.17"
#define szOID_OIWSEC_sha "1.3.14.3.2.18"
#define szOID_OIWSEC_mdc2 "1.3.14.3.2.19"
#define szOID_OIWSEC_dsaComm "1.3.14.3.2.20"
#define szOID_OIWSEC_dsaCommSHA "1.3.14.3.2.21"
#define szOID_OIWSEC_rsaXchg "1.3.14.3.2.22"
#define szOID_OIWSEC_keyHashSeal "1.3.14.3.2.23"
#define szOID_OIWSEC_md2RSASign "1.3.14.3.2.24"
#define szOID_OIWSEC_md5RSASign "1.3.14.3.2.25"
#define szOID_OIWSEC_sha1 "1.3.14.3.2.26"
#define szOID_OIWSEC_dsaSHA1 "1.3.14.3.2.27"
#define szOID_OIWSEC_dsaCommSHA1 "1.3.14.3.2.28"
#define szOID_OIWSEC_sha1RSASign "1.3.14.3.2.29"

#define szOID_OIWDIR "1.3.14.7.2"
#define szOID_OIWDIR_CRPT "1.3.14.7.2.1"
#define szOID_OIWDIR_HASH "1.3.14.7.2.2"
#define szOID_OIWDIR_SIGN "1.3.14.7.2.3"
#define szOID_OIWDIR_md2 "1.3.14.7.2.2.1"
#define szOID_OIWDIR_md2RSA "1.3.14.7.2.3.1"

#define szOID_INFOSEC "2.16.840.1.101.2.1"
#define szOID_INFOSEC_sdnsSignature "2.16.840.1.101.2.1.1.1"
#define szOID_INFOSEC_mosaicSignature "2.16.840.1.101.2.1.1.2"
#define szOID_INFOSEC_sdnsConfidentiality "2.16.840.1.101.2.1.1.3"
#define szOID_INFOSEC_mosaicConfidentiality "2.16.840.1.101.2.1.1.4"
#define szOID_INFOSEC_sdnsIntegrity "2.16.840.1.101.2.1.1.5"
#define szOID_INFOSEC_mosaicIntegrity "2.16.840.1.101.2.1.1.6"
#define szOID_INFOSEC_sdnsTokenProtection "2.16.840.1.101.2.1.1.7"
#define szOID_INFOSEC_mosaicTokenProtection "2.16.840.1.101.2.1.1.8"
#define szOID_INFOSEC_sdnsKeyManagement "2.16.840.1.101.2.1.1.9"
#define szOID_INFOSEC_mosaicKeyManagement "2.16.840.1.101.2.1.1.10"
#define szOID_INFOSEC_sdnsKMandSig "2.16.840.1.101.2.1.1.11"
#define szOID_INFOSEC_mosaicKMandSig "2.16.840.1.101.2.1.1.12"
#define szOID_INFOSEC_SuiteASignature "2.16.840.1.101.2.1.1.13"
#define szOID_INFOSEC_SuiteAConfidentiality "2.16.840.1.101.2.1.1.14"
#define szOID_INFOSEC_SuiteAIntegrity "2.16.840.1.101.2.1.1.15"
#define szOID_INFOSEC_SuiteATokenProtection "2.16.840.1.101.2.1.1.16"
#define szOID_INFOSEC_SuiteAKeyManagement "2.16.840.1.101.2.1.1.17"
#define szOID_INFOSEC_SuiteAKMandSig "2.16.840.1.101.2.1.1.18"
#define szOID_INFOSEC_mosaicUpdatedSig "2.16.840.1.101.2.1.1.19"
#define szOID_INFOSEC_mosaicKMandUpdSig "2.16.840.1.101.2.1.1.20"
#define szOID_INFOSEC_mosaicUpdatedInteg "2.16.840.1.101.2.1.1.21"

#define szOID_NIST_sha256 "2.16.840.1.101.3.4.2.1"
#define szOID_NIST_sha384 "2.16.840.1.101.3.4.2.2"
#define szOID_NIST_sha512 "2.16.840.1.101.3.4.2.3"

  typedef struct _CRYPT_OBJID_TABLE {
    DWORD dwAlgId;
    LPCSTR pszObjId;
  } CRYPT_OBJID_TABLE,*PCRYPT_OBJID_TABLE;

  typedef struct _CRYPT_HASH_INFO {
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_HASH_BLOB Hash;
  } CRYPT_HASH_INFO,*PCRYPT_HASH_INFO;
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_APP)
  typedef struct _CERT_EXTENSION {
    LPSTR pszObjId;
    WINBOOL fCritical;
    CRYPT_OBJID_BLOB Value;
  } CERT_EXTENSION,*PCERT_EXTENSION;

  typedef const CERT_EXTENSION *PCCERT_EXTENSION;
#endif

  typedef struct _CRYPT_ATTRIBUTE_TYPE_VALUE {
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Value;
  } CRYPT_ATTRIBUTE_TYPE_VALUE,*PCRYPT_ATTRIBUTE_TYPE_VALUE;

  typedef struct _CRYPT_ATTRIBUTE {
    LPSTR pszObjId;
    DWORD cValue;
    PCRYPT_ATTR_BLOB rgValue;
  } CRYPT_ATTRIBUTE,*PCRYPT_ATTRIBUTE;

  typedef struct _CRYPT_ATTRIBUTES {
    DWORD cAttr;
    PCRYPT_ATTRIBUTE rgAttr;
  } CRYPT_ATTRIBUTES,*PCRYPT_ATTRIBUTES;

  typedef struct _CERT_RDN_ATTR {
    LPSTR pszObjId;
    DWORD dwValueType;
    CERT_RDN_VALUE_BLOB Value;
  } CERT_RDN_ATTR,*PCERT_RDN_ATTR;

#define szOID_COMMON_NAME "2.5.4.3"
#define szOID_SUR_NAME "2.5.4.4"
#define szOID_DEVICE_SERIAL_NUMBER "2.5.4.5"
#define szOID_COUNTRY_NAME "2.5.4.6"
#define szOID_LOCALITY_NAME "2.5.4.7"
#define szOID_STATE_OR_PROVINCE_NAME "2.5.4.8"
#define szOID_STREET_ADDRESS "2.5.4.9"
#define szOID_ORGANIZATION_NAME "2.5.4.10"
#define szOID_ORGANIZATIONAL_UNIT_NAME "2.5.4.11"
#define szOID_TITLE "2.5.4.12"
#define szOID_DESCRIPTION "2.5.4.13"
#define szOID_SEARCH_GUIDE "2.5.4.14"
#define szOID_BUSINESS_CATEGORY "2.5.4.15"
#define szOID_POSTAL_ADDRESS "2.5.4.16"
#define szOID_POSTAL_CODE "2.5.4.17"
#define szOID_POST_OFFICE_BOX "2.5.4.18"
#define szOID_PHYSICAL_DELIVERY_OFFICE_NAME "2.5.4.19"
#define szOID_TELEPHONE_NUMBER "2.5.4.20"
#define szOID_TELEX_NUMBER "2.5.4.21"
#define szOID_TELETEXT_TERMINAL_IDENTIFIER "2.5.4.22"
#define szOID_FACSIMILE_TELEPHONE_NUMBER "2.5.4.23"
#define szOID_X21_ADDRESS "2.5.4.24"
#define szOID_INTERNATIONAL_ISDN_NUMBER "2.5.4.25"
#define szOID_REGISTERED_ADDRESS "2.5.4.26"
#define szOID_DESTINATION_INDICATOR "2.5.4.27"
#define szOID_PREFERRED_DELIVERY_METHOD "2.5.4.28"
#define szOID_PRESENTATION_ADDRESS "2.5.4.29"
#define szOID_SUPPORTED_APPLICATION_CONTEXT "2.5.4.30"
#define szOID_MEMBER "2.5.4.31"
#define szOID_OWNER "2.5.4.32"
#define szOID_ROLE_OCCUPANT "2.5.4.33"
#define szOID_SEE_ALSO "2.5.4.34"
#define szOID_USER_PASSWORD "2.5.4.35"
#define szOID_USER_CERTIFICATE "2.5.4.36"
#define szOID_CA_CERTIFICATE "2.5.4.37"
#define szOID_AUTHORITY_REVOCATION_LIST "2.5.4.38"
#define szOID_CERTIFICATE_REVOCATION_LIST "2.5.4.39"
#define szOID_CROSS_CERTIFICATE_PAIR "2.5.4.40"
#define szOID_GIVEN_NAME "2.5.4.42"
#define szOID_INITIALS "2.5.4.43"
#define szOID_DN_QUALIFIER "2.5.4.46"

#define szOID_DOMAIN_COMPONENT "0.9.2342.19200300.100.1.25"

#define szOID_PKCS_12_FRIENDLY_NAME_ATTR "1.2.840.113549.1.9.20"
#define szOID_PKCS_12_LOCAL_KEY_ID "1.2.840.113549.1.9.21"
#define szOID_PKCS_12_KEY_PROVIDER_NAME_ATTR "1.3.6.1.4.1.311.17.1"
#define szOID_LOCAL_MACHINE_KEYSET "1.3.6.1.4.1.311.17.2"
#define szOID_PKCS_12_EXTENDED_ATTRIBUTES "1.3.6.1.4.1.311.17.3"
#define szOID_PKCS_12_PROTECTED_PASSWORD_SECRET_BAG_TYPE_ID "1.3.6.1.4.1.311.17.4"

#define szOID_KEYID_RDN "1.3.6.1.4.1.311.10.7.1"

#define szOID_EV_RDN_LOCALE "1.3.6.1.4.1.311.60.2.1.1"
#define szOID_EV_RDN_STATE_OR_PROVINCE "1.3.6.1.4.1.311.60.2.1.2"
#define szOID_EV_RDN_COUNTRY "1.3.6.1.4.1.311.60.2.1.3"

#define CERT_RDN_ANY_TYPE 0
#define CERT_RDN_ENCODED_BLOB 1
#define CERT_RDN_OCTET_STRING 2
#define CERT_RDN_NUMERIC_STRING 3
#define CERT_RDN_PRINTABLE_STRING 4
#define CERT_RDN_TELETEX_STRING 5
#define CERT_RDN_T61_STRING 5
#define CERT_RDN_VIDEOTEX_STRING 6
#define CERT_RDN_IA5_STRING 7
#define CERT_RDN_GRAPHIC_STRING 8
#define CERT_RDN_VISIBLE_STRING 9
#define CERT_RDN_ISO646_STRING 9
#define CERT_RDN_GENERAL_STRING 10
#define CERT_RDN_UNIVERSAL_STRING 11
#define CERT_RDN_INT4_STRING 11
#define CERT_RDN_BMP_STRING 12
#define CERT_RDN_UNICODE_STRING 12
#define CERT_RDN_UTF8_STRING 13

#define CERT_RDN_TYPE_MASK 0x000000ff
#define CERT_RDN_FLAGS_MASK 0xff000000

#define CERT_RDN_ENABLE_T61_UNICODE_FLAG 0x80000000
#define CERT_RDN_ENABLE_UTF8_UNICODE_FLAG 0x20000000
#define CERT_RDN_FORCE_UTF8_UNICODE_FLAG 0x10000000
#define CERT_RDN_DISABLE_CHECK_TYPE_FLAG 0x40000000
#define CERT_RDN_DISABLE_IE4_UTF8_FLAG 0x1000000
#define CERT_RDN_ENABLE_PUNYCODE_FLAG 0x2000000

#define IS_CERT_RDN_CHAR_STRING(X) (((X) & CERT_RDN_TYPE_MASK) >= CERT_RDN_NUMERIC_STRING)

  typedef struct _CERT_RDN {
    DWORD cRDNAttr;
    PCERT_RDN_ATTR rgRDNAttr;
  } CERT_RDN,*PCERT_RDN;

  typedef struct _CERT_NAME_INFO {
    DWORD cRDN;
    PCERT_RDN rgRDN;
  } CERT_NAME_INFO,*PCERT_NAME_INFO;

  typedef struct _CERT_NAME_VALUE {
    DWORD dwValueType;
    CERT_RDN_VALUE_BLOB Value;
  } CERT_NAME_VALUE,*PCERT_NAME_VALUE;

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_APP)
  typedef struct _CERT_PUBLIC_KEY_INFO {
    CRYPT_ALGORITHM_IDENTIFIER Algorithm;
    CRYPT_BIT_BLOB PublicKey;
  } CERT_PUBLIC_KEY_INFO,*PCERT_PUBLIC_KEY_INFO;
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)
#define CERT_RSA_PUBLIC_KEY_OBJID szOID_RSA_RSA
#define CERT_DEFAULT_OID_PUBLIC_KEY_SIGN szOID_RSA_RSA
#define CERT_DEFAULT_OID_PUBLIC_KEY_XCHG szOID_RSA_RSA

  typedef struct _CRYPT_ECC_PRIVATE_KEY_INFO {
    DWORD dwVersion;
    CRYPT_DER_BLOB PrivateKey;
    LPSTR szCurveOid;
    CRYPT_BIT_BLOB PublicKey;
  } CRYPT_ECC_PRIVATE_KEY_INFO,*PCRYPT_ECC_PRIVATE_KEY_INFO;

#define CRYPT_ECC_PRIVATE_KEY_INFO_v1 1

  typedef struct _CRYPT_PRIVATE_KEY_INFO {
    DWORD Version;
    CRYPT_ALGORITHM_IDENTIFIER Algorithm;
    CRYPT_DER_BLOB PrivateKey;
    PCRYPT_ATTRIBUTES pAttributes;
  } CRYPT_PRIVATE_KEY_INFO,*PCRYPT_PRIVATE_KEY_INFO;

  typedef struct _CRYPT_ENCRYPTED_PRIVATE_KEY_INFO {
    CRYPT_ALGORITHM_IDENTIFIER EncryptionAlgorithm;
    CRYPT_DATA_BLOB EncryptedPrivateKey;
  } CRYPT_ENCRYPTED_PRIVATE_KEY_INFO,*PCRYPT_ENCRYPTED_PRIVATE_KEY_INFO;

  typedef WINBOOL (CALLBACK *PCRYPT_DECRYPT_PRIVATE_KEY_FUNC) (CRYPT_ALGORITHM_IDENTIFIER Algorithm, CRYPT_DATA_BLOB EncryptedPrivateKey, BYTE *pbClearTextKey, DWORD *pcbClearTextKey, LPVOID pVoidDecryptFunc);
  typedef WINBOOL (CALLBACK *PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC) (CRYPT_ALGORITHM_IDENTIFIER *pAlgorithm, CRYPT_DATA_BLOB *pClearTextPrivateKey, BYTE *pbEncryptedKey, DWORD *pcbEncryptedKey, LPVOID pVoidEncryptFunc);
  typedef WINBOOL (CALLBACK *PCRYPT_RESOLVE_HCRYPTPROV_FUNC) (CRYPT_PRIVATE_KEY_INFO *pPrivateKeyInfo, HCRYPTPROV *phCryptProv, LPVOID pVoidResolveFunc);

  typedef struct _CRYPT_PKCS8_IMPORT_PARAMS {
    CRYPT_DIGEST_BLOB PrivateKey;
    PCRYPT_RESOLVE_HCRYPTPROV_FUNC pResolvehCryptProvFunc;
    LPVOID pVoidResolveFunc;
    PCRYPT_DECRYPT_PRIVATE_KEY_FUNC pDecryptPrivateKeyFunc;
    LPVOID pVoidDecryptFunc;
  } CRYPT_PKCS8_IMPORT_PARAMS,*PCRYPT_PKCS8_IMPORT_PARAMS, CRYPT_PRIVATE_KEY_BLOB_AND_PARAMS,*PCRYPT_PRIVATE_KEY_BLOB_AND_PARAMS;

  typedef struct _CRYPT_PKCS8_EXPORT_PARAMS {
    HCRYPTPROV hCryptProv;
    DWORD dwKeySpec;
    LPSTR pszPrivateKeyObjId;
    PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC pEncryptPrivateKeyFunc;
    LPVOID pVoidEncryptFunc;
  } CRYPT_PKCS8_EXPORT_PARAMS,*PCRYPT_PKCS8_EXPORT_PARAMS;
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_APP)
  typedef struct _CERT_INFO {
    DWORD dwVersion;
    CRYPT_INTEGER_BLOB SerialNumber;
    CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    CERT_NAME_BLOB Issuer;
    FILETIME NotBefore;
    FILETIME NotAfter;
    CERT_NAME_BLOB Subject;
    CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
    CRYPT_BIT_BLOB IssuerUniqueId;
    CRYPT_BIT_BLOB SubjectUniqueId;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
  } CERT_INFO,*PCERT_INFO;
#endif

#define CERT_V1 0
#define CERT_V2 1
#define CERT_V3 2

#define CERT_INFO_VERSION_FLAG 1
#define CERT_INFO_SERIAL_NUMBER_FLAG 2
#define CERT_INFO_SIGNATURE_ALGORITHM_FLAG 3
#define CERT_INFO_ISSUER_FLAG 4
#define CERT_INFO_NOT_BEFORE_FLAG 5
#define CERT_INFO_NOT_AFTER_FLAG 6
#define CERT_INFO_SUBJECT_FLAG 7
#define CERT_INFO_SUBJECT_PUBLIC_KEY_INFO_FLAG 8
#define CERT_INFO_ISSUER_UNIQUE_ID_FLAG 9
#define CERT_INFO_SUBJECT_UNIQUE_ID_FLAG 10
#define CERT_INFO_EXTENSION_FLAG 11

  typedef struct _CRL_ENTRY {
    CRYPT_INTEGER_BLOB SerialNumber;
    FILETIME RevocationDate;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
  } CRL_ENTRY,*PCRL_ENTRY;

  typedef struct _CRL_INFO {
    DWORD dwVersion;
    CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    CERT_NAME_BLOB Issuer;
    FILETIME ThisUpdate;
    FILETIME NextUpdate;
    DWORD cCRLEntry;
    PCRL_ENTRY rgCRLEntry;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
  } CRL_INFO,*PCRL_INFO;

#define CRL_V1 0
#define CRL_V2 1

#define CERT_BUNDLE_CERTIFICATE 0
#define CERT_BUNDLE_CRL 1

  typedef struct _CERT_OR_CRL_BLOB {
    DWORD dwChoice;
    DWORD cbEncoded;
    BYTE *pbEncoded;
  } CERT_OR_CRL_BLOB,*PCERT_OR_CRL_BLOB;

  typedef struct _CERT_OR_CRL_BUNDLE {
    DWORD cItem;
    PCERT_OR_CRL_BLOB rgItem;
  } CERT_OR_CRL_BUNDLE,*PCERT_OR_CRL_BUNDLE;

  typedef struct _CERT_REQUEST_INFO {
    DWORD dwVersion;
    CERT_NAME_BLOB Subject;
    CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
    DWORD cAttribute;
    PCRYPT_ATTRIBUTE rgAttribute;
  } CERT_REQUEST_INFO,*PCERT_REQUEST_INFO;

#define CERT_REQUEST_V1 0

  typedef struct _CERT_KEYGEN_REQUEST_INFO {
    DWORD dwVersion;
    CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
    LPWSTR pwszChallengeString;
  } CERT_KEYGEN_REQUEST_INFO,*PCERT_KEYGEN_REQUEST_INFO;

#define CERT_KEYGEN_REQUEST_V1 0

  typedef struct _CERT_SIGNED_CONTENT_INFO {
    CRYPT_DER_BLOB ToBeSigned;
    CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    CRYPT_BIT_BLOB Signature;
  } CERT_SIGNED_CONTENT_INFO,*PCERT_SIGNED_CONTENT_INFO;

  typedef struct _CTL_USAGE {
    DWORD cUsageIdentifier;
    LPSTR *rgpszUsageIdentifier;
  } CTL_USAGE,*PCTL_USAGE,CERT_ENHKEY_USAGE,*PCERT_ENHKEY_USAGE;

  typedef const CTL_USAGE *PCCTL_USAGE;
  typedef const CERT_ENHKEY_USAGE *PCCERT_ENHKEY_USAGE;

  typedef struct _CTL_ENTRY {
    CRYPT_DATA_BLOB SubjectIdentifier;
    DWORD cAttribute;
    PCRYPT_ATTRIBUTE rgAttribute;
  } CTL_ENTRY,*PCTL_ENTRY;

  typedef struct _CTL_INFO {
    DWORD dwVersion;
    CTL_USAGE SubjectUsage;
    CRYPT_DATA_BLOB ListIdentifier;
    CRYPT_INTEGER_BLOB SequenceNumber;
    FILETIME ThisUpdate;
    FILETIME NextUpdate;
    CRYPT_ALGORITHM_IDENTIFIER SubjectAlgorithm;
    DWORD cCTLEntry;
    PCTL_ENTRY rgCTLEntry;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
  } CTL_INFO,*PCTL_INFO;

#define CTL_V1 0

  typedef struct _CRYPT_TIME_STAMP_REQUEST_INFO {
    LPSTR pszTimeStampAlgorithm;
    LPSTR pszContentType;
    CRYPT_OBJID_BLOB Content;
    DWORD cAttribute;
    PCRYPT_ATTRIBUTE rgAttribute;
  } CRYPT_TIME_STAMP_REQUEST_INFO,*PCRYPT_TIME_STAMP_REQUEST_INFO;

  typedef struct _CRYPT_ENROLLMENT_NAME_VALUE_PAIR {
    LPWSTR pwszName;
    LPWSTR pwszValue;
  } CRYPT_ENROLLMENT_NAME_VALUE_PAIR,*PCRYPT_ENROLLMENT_NAME_VALUE_PAIR;

  typedef struct _CRYPT_CSP_PROVIDER {
    DWORD dwKeySpec;
    LPWSTR pwszProviderName;
    CRYPT_BIT_BLOB Signature;
  } CRYPT_CSP_PROVIDER,*PCRYPT_CSP_PROVIDER;

#define CERT_ENCODING_TYPE_MASK 0x0000ffff
#define CMSG_ENCODING_TYPE_MASK 0xffff0000
#define GET_CERT_ENCODING_TYPE(T) (T & CERT_ENCODING_TYPE_MASK)
#define GET_CMSG_ENCODING_TYPE(T) (T & CMSG_ENCODING_TYPE_MASK)

#define CRYPT_ASN_ENCODING 0x1
#define CRYPT_NDR_ENCODING 0x2
#define X509_ASN_ENCODING 0x1
#define X509_NDR_ENCODING 0x2
#define PKCS_7_ASN_ENCODING 0x10000
#define PKCS_7_NDR_ENCODING 0x20000

  WINIMPM WINBOOL WINAPI CryptFormatObject (DWORD dwCertEncodingType, DWORD dwFormatType, DWORD dwFormatStrType, void *pFormatStruct, LPCSTR lpszStructType, const BYTE *pbEncoded, DWORD cbEncoded, void *pbFormat, DWORD *pcbFormat);

#define CRYPT_FORMAT_STR_MULTI_LINE 0x1
#define CRYPT_FORMAT_STR_NO_HEX 0x10

#define CRYPT_FORMAT_SIMPLE 0x1
#define CRYPT_FORMAT_X509 0x2
#define CRYPT_FORMAT_OID 0x4
#define CRYPT_FORMAT_RDN_SEMICOLON 0x100
#define CRYPT_FORMAT_RDN_CRLF 0x200
#define CRYPT_FORMAT_RDN_UNQUOTE 0x400
#define CRYPT_FORMAT_RDN_REVERSE 0x800
#define CRYPT_FORMAT_COMMA 0x1000
#define CRYPT_FORMAT_SEMICOLON CRYPT_FORMAT_RDN_SEMICOLON
#define CRYPT_FORMAT_CRLF CRYPT_FORMAT_RDN_CRLF

  typedef LPVOID (WINAPI *PFN_CRYPT_ALLOC)(size_t cbSize);
  typedef VOID (WINAPI *PFN_CRYPT_FREE)(LPVOID pv);

  typedef struct _CRYPT_ENCODE_PARA {
    DWORD cbSize;
    PFN_CRYPT_ALLOC pfnAlloc;
    PFN_CRYPT_FREE pfnFree;
  } CRYPT_ENCODE_PARA,*PCRYPT_ENCODE_PARA;

  WINIMPM WINBOOL WINAPI CryptEncodeObjectEx (DWORD dwCertEncodingType, LPCSTR lpszStructType, const void *pvStructInfo, DWORD dwFlags, PCRYPT_ENCODE_PARA pEncodePara, void *pvEncoded, DWORD *pcbEncoded);
  WINIMPM WINBOOL WINAPI CryptEncodeObject (DWORD dwCertEncodingType, LPCSTR lpszStructType, const void *pvStructInfo, BYTE *pbEncoded, DWORD *pcbEncoded);

#define CRYPT_ENCODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG 0x8
#define CRYPT_ENCODE_ALLOC_FLAG 0x8000
#define CRYPT_UNICODE_NAME_ENCODE_ENABLE_T61_UNICODE_FLAG CERT_RDN_ENABLE_T61_UNICODE_FLAG
#define CRYPT_UNICODE_NAME_ENCODE_ENABLE_UTF8_UNICODE_FLAG CERT_RDN_ENABLE_UTF8_UNICODE_FLAG
#define CRYPT_UNICODE_NAME_ENCODE_FORCE_UTF8_UNICODE_FLAG CERT_RDN_FORCE_UTF8_UNICODE_FLAG
#define CRYPT_UNICODE_NAME_ENCODE_DISABLE_CHECK_TYPE_FLAG CERT_RDN_DISABLE_CHECK_TYPE_FLAG
#define CRYPT_SORTED_CTL_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG 0x10000
#define CRYPT_ENCODE_ENABLE_PUNYCODE_FLAG 0x20000
#define CRYPT_ENCODE_ENABLE_UTF8PERCENT_FLAG 0x40000
#define CRYPT_ENCODE_ENABLE_IA5CONVERSION_FLAG (CRYPT_ENCODE_ENABLE_PUNYCODE_FLAG | CRYPT_ENCODE_ENABLE_UTF8PERCENT_FLAG)

  typedef struct _CRYPT_DECODE_PARA {
    DWORD cbSize;
    PFN_CRYPT_ALLOC pfnAlloc;
    PFN_CRYPT_FREE pfnFree;
  } CRYPT_DECODE_PARA,*PCRYPT_DECODE_PARA;

  WINIMPM WINBOOL WINAPI CryptDecodeObjectEx (DWORD dwCertEncodingType, LPCSTR lpszStructType, const BYTE *pbEncoded, DWORD cbEncoded, DWORD dwFlags, PCRYPT_DECODE_PARA pDecodePara, void *pvStructInfo, DWORD *pcbStructInfo);
  WINIMPM WINBOOL WINAPI CryptDecodeObject (DWORD dwCertEncodingType, LPCSTR lpszStructType, const BYTE *pbEncoded, DWORD cbEncoded, DWORD dwFlags, void *pvStructInfo, DWORD *pcbStructInfo);

#define CRYPT_DECODE_NOCOPY_FLAG 0x1
#define CRYPT_DECODE_TO_BE_SIGNED_FLAG 0x2
#define CRYPT_DECODE_SHARE_OID_STRING_FLAG 0x4
#define CRYPT_DECODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG 0x8
#define CRYPT_DECODE_ALLOC_FLAG 0x8000
#define CRYPT_UNICODE_NAME_DECODE_DISABLE_IE4_UTF8_FLAG CERT_RDN_DISABLE_IE4_UTF8_FLAG
#define CRYPT_DECODE_ENABLE_PUNYCODE_FLAG 0x2000000
#define CRYPT_DECODE_ENABLE_UTF8PERCENT_FLAG 0x4000000
#define CRYPT_DECODE_ENABLE_IA5CONVERSION_FLAG (CRYPT_DECODE_ENABLE_PUNYCODE_FLAG | CRYPT_DECODE_ENABLE_UTF8PERCENT_FLAG)

#define CRYPT_ENCODE_DECODE_NONE 0
#define X509_CERT ((LPCSTR) 1)
#define X509_CERT_TO_BE_SIGNED ((LPCSTR) 2)
#define X509_CERT_CRL_TO_BE_SIGNED ((LPCSTR) 3)
#define X509_CERT_REQUEST_TO_BE_SIGNED ((LPCSTR) 4)
#define X509_EXTENSIONS ((LPCSTR) 5)
#define X509_NAME_VALUE ((LPCSTR) 6)
#define X509_NAME ((LPCSTR) 7)
#define X509_PUBLIC_KEY_INFO ((LPCSTR) 8)
#define X509_AUTHORITY_KEY_ID ((LPCSTR) 9)
#define X509_KEY_ATTRIBUTES ((LPCSTR) 10)
#define X509_KEY_USAGE_RESTRICTION ((LPCSTR) 11)
#define X509_ALTERNATE_NAME ((LPCSTR) 12)
#define X509_BASIC_CONSTRAINTS ((LPCSTR) 13)
#define X509_KEY_USAGE ((LPCSTR) 14)
#define X509_BASIC_CONSTRAINTS2 ((LPCSTR) 15)
#define X509_CERT_POLICIES ((LPCSTR) 16)
#define PKCS_UTC_TIME ((LPCSTR) 17)
#define PKCS_TIME_REQUEST ((LPCSTR) 18)
#define RSA_CSP_PUBLICKEYBLOB ((LPCSTR) 19)
#define X509_UNICODE_NAME ((LPCSTR) 20)
#define X509_KEYGEN_REQUEST_TO_BE_SIGNED ((LPCSTR) 21)
#define PKCS_ATTRIBUTE ((LPCSTR) 22)
#define PKCS_CONTENT_INFO_SEQUENCE_OF_ANY ((LPCSTR) 23)
#define X509_UNICODE_NAME_VALUE ((LPCSTR) 24)
#define X509_ANY_STRING X509_NAME_VALUE
#define X509_UNICODE_ANY_STRING X509_UNICODE_NAME_VALUE
#define X509_OCTET_STRING ((LPCSTR) 25)
#define X509_BITS ((LPCSTR) 26)
#define X509_INTEGER ((LPCSTR) 27)
#define X509_MULTI_BYTE_INTEGER ((LPCSTR) 28)
#define X509_ENUMERATED ((LPCSTR) 29)
#define X509_CHOICE_OF_TIME ((LPCSTR) 30)
#define X509_AUTHORITY_KEY_ID2 ((LPCSTR) 31)
#define X509_AUTHORITY_INFO_ACCESS ((LPCSTR) 32)
#define X509_SUBJECT_INFO_ACCESS X509_AUTHORITY_INFO_ACCESS
#define X509_CRL_REASON_CODE X509_ENUMERATED
#define PKCS_CONTENT_INFO ((LPCSTR) 33)
#define X509_SEQUENCE_OF_ANY ((LPCSTR) 34)
#define X509_CRL_DIST_POINTS ((LPCSTR) 35)
#define X509_ENHANCED_KEY_USAGE ((LPCSTR) 36)
#define PKCS_CTL ((LPCSTR) 37)
#define X509_MULTI_BYTE_UINT ((LPCSTR) 38)
#define X509_DSS_PUBLICKEY X509_MULTI_BYTE_UINT
#define X509_DSS_PARAMETERS ((LPCSTR) 39)
#define X509_DSS_SIGNATURE ((LPCSTR) 40)
#define PKCS_RC2_CBC_PARAMETERS ((LPCSTR) 41)
#define PKCS_SMIME_CAPABILITIES ((LPCSTR) 42)
#define X509_QC_STATEMENTS_EXT ((LPCSTR) 42)
#define PKCS_RSA_PRIVATE_KEY ((LPCSTR) 43)
#define PKCS_PRIVATE_KEY_INFO ((LPCSTR) 44)
#define PKCS_ENCRYPTED_PRIVATE_KEY_INFO ((LPCSTR) 45)
#define X509_PKIX_POLICY_QUALIFIER_USERNOTICE ((LPCSTR) 46)
#define X509_DH_PUBLICKEY X509_MULTI_BYTE_UINT
#define X509_DH_PARAMETERS ((LPCSTR) 47)
#define X509_ECC_SIGNATURE ((LPCSTR) 47)
#define PKCS_ATTRIBUTES ((LPCSTR) 48)
#define PKCS_SORTED_CTL ((LPCSTR) 49)
#define X942_DH_PARAMETERS ((LPCSTR) 50)
#define X509_BITS_WITHOUT_TRAILING_ZEROES ((LPCSTR) 51)
#define X942_OTHER_INFO ((LPCSTR) 52)
#define X509_CERT_PAIR ((LPCSTR) 53)
#define X509_ISSUING_DIST_POINT ((LPCSTR) 54)
#define X509_NAME_CONSTRAINTS ((LPCSTR) 55)
#define X509_POLICY_MAPPINGS ((LPCSTR) 56)
#define X509_POLICY_CONSTRAINTS ((LPCSTR) 57)
#define X509_CROSS_CERT_DIST_POINTS ((LPCSTR) 58)
#define CMC_DATA ((LPCSTR) 59)
#define CMC_RESPONSE ((LPCSTR) 60)
#define CMC_STATUS ((LPCSTR) 61)
#define CMC_ADD_EXTENSIONS ((LPCSTR) 62)
#define CMC_ADD_ATTRIBUTES ((LPCSTR) 63)
#define X509_CERTIFICATE_TEMPLATE ((LPCSTR) 64)
#define OCSP_SIGNED_REQUEST ((LPCSTR) 65)
#define OCSP_REQUEST ((LPCSTR) 66)
#define OCSP_RESPONSE ((LPCSTR) 67)
#define OCSP_BASIC_SIGNED_RESPONSE ((LPCSTR) 68)
#define OCSP_BASIC_RESPONSE ((LPCSTR) 69)
#define X509_LOGOTYPE_EXT ((LPCSTR) 70)
#define X509_BIOMETRIC_EXT ((LPCSTR) 71)
#define CNG_RSA_PUBLIC_KEY_BLOB ((LPCSTR) 72)
#define X509_OBJECT_IDENTIFIER ((LPCSTR) 73)
#define X509_ALGORITHM_IDENTIFIER ((LPCSTR) 74)
#define PKCS_RSA_SSA_PSS_PARAMETERS ((LPCSTR) 75)
#define PKCS_RSAES_OAEP_PARAMETERS ((LPCSTR) 76)
#define ECC_CMS_SHARED_INFO ((LPCSTR) 77)
#define TIMESTAMP_REQUEST ((LPCSTR) 78)
#define TIMESTAMP_RESPONSE ((LPCSTR) 79)
#define TIMESTAMP_INFO ((LPCSTR) 80)
#define X509_CERT_BUNDLE ((LPCSTR) 81)
#define X509_ECC_PRIVATE_KEY ((LPCSTR) 82)
#define CNG_RSA_PRIVATE_KEY_BLOB ((LPCSTR) 83)
#define X509_SUBJECT_DIR_ATTRS ((LPCSTR) 84)
#define X509_ECC_PARAMETERS ((LPCSTR) 85)

#define PKCS7_SIGNER_INFO ((LPCSTR) 500)
#define CMS_SIGNER_INFO ((LPCSTR) 501)

#define szOID_AUTHORITY_KEY_IDENTIFIER "2.5.29.1"
#define szOID_KEY_ATTRIBUTES "2.5.29.2"
#define szOID_CERT_POLICIES_95 "2.5.29.3"
#define szOID_KEY_USAGE_RESTRICTION "2.5.29.4"
#define szOID_SUBJECT_ALT_NAME "2.5.29.7"
#define szOID_ISSUER_ALT_NAME "2.5.29.8"
#define szOID_BASIC_CONSTRAINTS "2.5.29.10"
/* szOID_KEY_USAGE is defined incorrectly in msdn as 2.5.29.4 --
   http://www.oid-info.com/get/2.5.29.15 RFC3280 */
#define szOID_KEY_USAGE "2.5.29.15"
#define szOID_PRIVATEKEY_USAGE_PERIOD "2.5.29.16"
#define szOID_BASIC_CONSTRAINTS2 "2.5.29.19"

#define szOID_CERT_POLICIES "2.5.29.32"
#define szOID_ANY_CERT_POLICY "2.5.29.32.0"
#define szOID_INHIBIT_ANY_POLICY "2.5.29.54"

#define szOID_AUTHORITY_KEY_IDENTIFIER2 "2.5.29.35"
#define szOID_SUBJECT_KEY_IDENTIFIER "2.5.29.14"
#define szOID_SUBJECT_ALT_NAME2 "2.5.29.17"
#define szOID_ISSUER_ALT_NAME2 "2.5.29.18"
#define szOID_CRL_REASON_CODE "2.5.29.21"
#define szOID_REASON_CODE_HOLD "2.5.29.23"
#define szOID_CRL_DIST_POINTS "2.5.29.31"
#define szOID_ENHANCED_KEY_USAGE "2.5.29.37"

#define szOID_ANY_ENHANCED_KEY_USAGE "2.5.29.37.0"

#define szOID_CRL_NUMBER "2.5.29.20"

#define szOID_DELTA_CRL_INDICATOR "2.5.29.27"
#define szOID_ISSUING_DIST_POINT "2.5.29.28"

#define szOID_FRESHEST_CRL "2.5.29.46"
#define szOID_NAME_CONSTRAINTS "2.5.29.30"

#define szOID_POLICY_MAPPINGS "2.5.29.33"
#define szOID_LEGACY_POLICY_MAPPINGS "2.5.29.5"
#define szOID_POLICY_CONSTRAINTS "2.5.29.36"

#define szOID_RENEWAL_CERTIFICATE "1.3.6.1.4.1.311.13.1"
#define szOID_ENROLLMENT_NAME_VALUE_PAIR "1.3.6.1.4.1.311.13.2.1"
#define szOID_ENROLLMENT_CSP_PROVIDER "1.3.6.1.4.1.311.13.2.2"
#define szOID_OS_VERSION "1.3.6.1.4.1.311.13.2.3"

#define szOID_ENROLLMENT_AGENT "1.3.6.1.4.1.311.20.2.1"

#define szOID_PKIX "1.3.6.1.5.5.7"
#define szOID_PKIX_PE "1.3.6.1.5.5.7.1"
#define szOID_AUTHORITY_INFO_ACCESS "1.3.6.1.5.5.7.1.1"
#define szOID_SUBJECT_INFO_ACCESS "1.3.6.1.5.5.7.1.11"
#define szOID_BIOMETRIC_EXT "1.3.6.1.5.5.7.1.2"
#define szOID_QC_STATEMENTS_EXT "1.3.6.1.5.5.7.1.3"
#define szOID_LOGOTYPE_EXT "1.3.6.1.5.5.7.1.12"
#define szOID_TLS_FEATURES_EXT "1.3.6.1.5.5.7.1.24"

#define szOID_CERT_EXTENSIONS "1.3.6.1.4.1.311.2.1.14"
#define szOID_NEXT_UPDATE_LOCATION "1.3.6.1.4.1.311.10.2"
#define szOID_REMOVE_CERTIFICATE "1.3.6.1.4.1.311.10.8.1"
#define szOID_CROSS_CERT_DIST_POINTS "1.3.6.1.4.1.311.10.9.1"

#define szOID_CTL "1.3.6.1.4.1.311.10.1"

#define szOID_SORTED_CTL "1.3.6.1.4.1.311.10.1.1"

#ifndef szOID_SERIALIZED
#define szOID_SERIALIZED "1.3.6.1.4.1.311.10.3.3.1"
#endif

#ifndef szOID_NT_PRINCIPAL_NAME
#define szOID_NT_PRINCIPAL_NAME "1.3.6.1.4.1.311.20.2.3"
#endif

#ifndef szOID_INTERNATIONALIZED_EMAIL_ADDRESS
#define szOID_INTERNATIONALIZED_EMAIL_ADDRESS "1.3.6.1.4.1.311.20.2.4"
#endif

#ifndef szOID_PRODUCT_UPDATE
#define szOID_PRODUCT_UPDATE "1.3.6.1.4.1.311.31.1"
#endif

#define szOID_ANY_APPLICATION_POLICY "1.3.6.1.4.1.311.10.12.1"

#define szOID_AUTO_ENROLL_CTL_USAGE "1.3.6.1.4.1.311.20.1"

#define szOID_ENROLL_CERTTYPE_EXTENSION "1.3.6.1.4.1.311.20.2"

#define szOID_CERT_MANIFOLD "1.3.6.1.4.1.311.20.3"

#ifndef szOID_CERTSRV_CA_VERSION
#define szOID_CERTSRV_CA_VERSION "1.3.6.1.4.1.311.21.1"
#endif
#define szOID_CERTSRV_PREVIOUS_CERT_HASH "1.3.6.1.4.1.311.21.2"
#define szOID_CRL_VIRTUAL_BASE "1.3.6.1.4.1.311.21.3"
#define szOID_CRL_NEXT_PUBLISH "1.3.6.1.4.1.311.21.4"
#define szOID_KP_CA_EXCHANGE "1.3.6.1.4.1.311.21.5"
#define szOID_KP_KEY_RECOVERY_AGENT "1.3.6.1.4.1.311.21.6"
#define szOID_CERTIFICATE_TEMPLATE "1.3.6.1.4.1.311.21.7"
#define szOID_ENTERPRISE_OID_ROOT "1.3.6.1.4.1.311.21.8"
#define szOID_RDN_DUMMY_SIGNER "1.3.6.1.4.1.311.21.9"
#define szOID_APPLICATION_CERT_POLICIES "1.3.6.1.4.1.311.21.10"
#define szOID_APPLICATION_POLICY_MAPPINGS "1.3.6.1.4.1.311.21.11"
#define szOID_APPLICATION_POLICY_CONSTRAINTS "1.3.6.1.4.1.311.21.12"
#define szOID_ARCHIVED_KEY_ATTR "1.3.6.1.4.1.311.21.13"
#define szOID_CRL_SELF_CDP "1.3.6.1.4.1.311.21.14"
#define szOID_REQUIRE_CERT_CHAIN_POLICY "1.3.6.1.4.1.311.21.15"
#define szOID_ARCHIVED_KEY_CERT_HASH "1.3.6.1.4.1.311.21.16"
#define szOID_ISSUED_CERT_HASH "1.3.6.1.4.1.311.21.17"
#define szOID_DS_EMAIL_REPLICATION "1.3.6.1.4.1.311.21.19"
#define szOID_REQUEST_CLIENT_INFO "1.3.6.1.4.1.311.21.20"
#define szOID_ENCRYPTED_KEY_HASH "1.3.6.1.4.1.311.21.21"
#define szOID_CERTSRV_CROSSCA_VERSION "1.3.6.1.4.1.311.21.22"

#define szOID_NTDS_REPLICATION "1.3.6.1.4.1.311.25.1"

#define szOID_SUBJECT_DIR_ATTRS "2.5.29.9"

#define szOID_PKIX_KP "1.3.6.1.5.5.7.3"

#define szOID_PKIX_KP_SERVER_AUTH "1.3.6.1.5.5.7.3.1"
#define szOID_PKIX_KP_CLIENT_AUTH "1.3.6.1.5.5.7.3.2"
#define szOID_PKIX_KP_CODE_SIGNING "1.3.6.1.5.5.7.3.3"
#define szOID_PKIX_KP_EMAIL_PROTECTION "1.3.6.1.5.5.7.3.4"
#define szOID_PKIX_KP_IPSEC_END_SYSTEM "1.3.6.1.5.5.7.3.5"
#define szOID_PKIX_KP_IPSEC_TUNNEL "1.3.6.1.5.5.7.3.6"
#define szOID_PKIX_KP_IPSEC_USER "1.3.6.1.5.5.7.3.7"
#define szOID_PKIX_KP_TIMESTAMP_SIGNING "1.3.6.1.5.5.7.3.8"
#define szOID_PKIX_KP_OCSP_SIGNING "1.3.6.1.5.5.7.3.9"

#define szOID_PKIX_OCSP_NONCE "1.3.6.1.5.5.7.48.1.2"
#define szOID_PKIX_OCSP_NOCHECK "1.3.6.1.5.5.7.48.1.5"

#define szOID_IPSEC_KP_IKE_INTERMEDIATE "1.3.6.1.5.5.8.2.2"

#define szOID_PKINIT_KP_KDC "1.3.6.1.5.2.3.5"

#define szOID_KP_CTL_USAGE_SIGNING "1.3.6.1.4.1.311.10.3.1"

#define szOID_KP_TIME_STAMP_SIGNING "1.3.6.1.4.1.311.10.3.2"

#ifndef szOID_SERVER_GATED_CRYPTO
#define szOID_SERVER_GATED_CRYPTO "1.3.6.1.4.1.311.10.3.3"
#endif

#ifndef szOID_SGC_NETSCAPE
#define szOID_SGC_NETSCAPE "2.16.840.1.113730.4.1"
#endif

#define szOID_KP_EFS "1.3.6.1.4.1.311.10.3.4"
#define szOID_EFS_RECOVERY "1.3.6.1.4.1.311.10.3.4.1"

#define szOID_WHQL_CRYPTO "1.3.6.1.4.1.311.10.3.5"
#define szOID_ATTEST_WHQL_CRYPTO "1.3.6.1.4.1.311.10.3.5.1"
#define szOID_NT5_CRYPTO "1.3.6.1.4.1.311.10.3.6"
#define szOID_OEM_WHQL_CRYPTO "1.3.6.1.4.1.311.10.3.7"
#define szOID_EMBEDDED_NT_CRYPTO "1.3.6.1.4.1.311.10.3.8"
#define szOID_ROOT_LIST_SIGNER "1.3.6.1.4.1.311.10.3.9"
#define szOID_KP_QUALIFIED_SUBORDINATION "1.3.6.1.4.1.311.10.3.10"
#define szOID_KP_KEY_RECOVERY "1.3.6.1.4.1.311.10.3.11"
#define szOID_KP_DOCUMENT_SIGNING "1.3.6.1.4.1.311.10.3.12"
#define szOID_KP_LIFETIME_SIGNING "1.3.6.1.4.1.311.10.3.13"
#define szOID_KP_MOBILE_DEVICE_SOFTWARE "1.3.6.1.4.1.311.10.3.14"
#define szOID_KP_SMART_DISPLAY "1.3.6.1.4.1.311.10.3.15"
#define szOID_KP_CSP_SIGNATURE "1.3.6.1.4.1.311.10.3.16"
#define szOID_KP_FLIGHT_SIGNING "1.3.6.1.4.1.311.10.3.27"
#define szOID_PLATFORM_MANIFEST_BINARY_ID "1.3.6.1.4.1.311.10.3.28"

#ifndef szOID_DRM
#define szOID_DRM "1.3.6.1.4.1.311.10.5.1"
#endif

#ifndef szOID_DRM_INDIVIDUALIZATION
#define szOID_DRM_INDIVIDUALIZATION "1.3.6.1.4.1.311.10.5.2"
#endif

#ifndef szOID_LICENSES
#define szOID_LICENSES "1.3.6.1.4.1.311.10.6.1"
#endif

#ifndef szOID_LICENSE_SERVER
#define szOID_LICENSE_SERVER "1.3.6.1.4.1.311.10.6.2"
#endif

#ifndef szOID_KP_SMARTCARD_LOGON
#define szOID_KP_SMARTCARD_LOGON "1.3.6.1.4.1.311.20.2.2"
#endif

#define szOID_KP_KERNEL_MODE_CODE_SIGNING "1.3.6.1.4.1.311.61.1.1"
#define szOID_KP_KERNEL_MODE_TRUSTED_BOOT_SIGNING "1.3.6.1.4.1.311.61.4.1"
#define szOID_REVOKED_LIST_SIGNER "1.3.6.1.4.1.311.10.3.19"
#define szOID_WINDOWS_KITS_SIGNER "1.3.6.1.4.1.311.10.3.20"
#define szOID_WINDOWS_RT_SIGNER "1.3.6.1.4.1.311.10.3.21"
#define szOID_PROTECTED_PROCESS_LIGHT_SIGNER "1.3.6.1.4.1.311.10.3.22"
#define szOID_WINDOWS_TCB_SIGNER "1.3.6.1.4.1.311.10.3.23"
#define szOID_PROTECTED_PROCESS_SIGNER "1.3.6.1.4.1.311.10.3.24"
#define szOID_WINDOWS_THIRD_PARTY_COMPONENT_SIGNER "1.3.6.1.4.1.311.10.3.25"
#define szOID_WINDOWS_SOFTWARE_EXTENSION_SIGNER "1.3.6.1.4.1.311.10.3.26"
#define szOID_DISALLOWED_LIST "1.3.6.1.4.1.311.10.3.30"
#define szOID_PIN_RULES_SIGNER "1.3.6.1.4.1.311.10.3.31"
#define szOID_PIN_RULES_CTL "1.3.6.1.4.1.311.10.3.32"
#define szOID_PIN_RULES_EXT "1.3.6.1.4.1.311.10.3.33"
#define szOID_PIN_RULES_DOMAIN_NAME "1.3.6.1.4.1.311.10.3.34"
#define szOID_PIN_RULES_LOG_END_DATE_EXT "1.3.6.1.4.1.311.10.3.35"
#define szOID_IUM_SIGNING "1.3.6.1.4.1.311.10.3.37"
#define szOID_EV_WHQL_CRYPTO "1.3.6.1.4.1.311.10.3.39"
#define szOID_BIOMETRIC_SIGNING "1.3.6.1.4.1.311.10.3.41"
#define szOID_ENCLAVE_SIGNING "1.3.6.1.4.1.311.10.3.42"
#define szOID_SYNC_ROOT_CTL_EXT "1.3.6.1.4.1.311.10.3.50"
#define szOID_HPKP_DOMAIN_NAME_CTL "1.3.6.1.4.1.311.10.3.60"
#define szOID_HPKP_HEADER_VALUE_CTL "1.3.6.1.4.1.311.10.3.61"
#define szOID_KP_KERNEL_MODE_HAL_EXTENSION_SIGNING "1.3.6.1.4.1.311.61.5.1"
#define szOID_WINDOWS_STORE_SIGNER "1.3.6.1.4.1.311.76.3.1"
#define szOID_DYNAMIC_CODE_GEN_SIGNER "1.3.6.1.4.1.311.76.5.1"
#define szOID_MICROSOFT_PUBLISHER_SIGNER "1.3.6.1.4.1.311.76.8.1"
#define szOID_YESNO_TRUST_ATTR "1.3.6.1.4.1.311.10.4.1"
#define szOID_SITE_PIN_RULES_INDEX_ATTR "1.3.6.1.4.1.311.10.4.2"
#define szOID_SITE_PIN_RULES_FLAGS_ATTR "1.3.6.1.4.1.311.10.4.3"

#define SITE_PIN_RULES_ALL_SUBDOMAINS_FLAG 0x1

#define szOID_PKIX_POLICY_QUALIFIER_CPS "1.3.6.1.5.5.7.2.1"
#define szOID_PKIX_POLICY_QUALIFIER_USERNOTICE "1.3.6.1.5.5.7.2.2"

#define szOID_ROOT_PROGRAM_FLAGS "1.3.6.1.4.1.311.60.1.1"
#define CERT_ROOT_PROGRAM_FLAG_ORG 0x80
#define CERT_ROOT_PROGRAM_FLAG_LSC 0x40
#define CERT_ROOT_PROGRAM_FLAG_SUBJECT_LOGO 0x20
#define CERT_ROOT_PROGRAM_FLAG_OU 0x10
#define CERT_ROOT_PROGRAM_FLAG_ADDRESS 0x08

#define szOID_CERT_POLICIES_95_QUALIFIER1 "2.16.840.1.113733.1.7.1.1"

#define szOID_RDN_TPM_MANUFACTURER "2.23.133.2.1"
#define szOID_RDN_TPM_MODEL "2.23.133.2.2"
#define szOID_RDN_TPM_VERSION "2.23.133.2.3"

#define szOID_RDN_TCG_PLATFORM_MANUFACTURER "2.23.133.2.4"
#define szOID_RDN_TCG_PLATFORM_MODEL "2.23.133.2.5"
#define szOID_RDN_TCG_PLATFORM_VERSION "2.23.133.2.6"

#define szOID_CT_CERT_SCTLIST "1.3.6.1.4.1.11129.2.4.2"

#define szOID_ENROLL_EK_INFO "1.3.6.1.4.1.311.21.23"
#define szOID_ENROLL_AIK_INFO "1.3.6.1.4.1.311.21.39"
#define szOID_ENROLL_ATTESTATION_STATEMENT "1.3.6.1.4.1.311.21.24"

#define szOID_ENROLL_KSP_NAME "1.3.6.1.4.1.311.21.25"

#define szOID_ENROLL_EKPUB_CHALLENGE "1.3.6.1.4.1.311.21.26"
#define szOID_ENROLL_CAXCHGCERT_HASH "1.3.6.1.4.1.311.21.27"
#define szOID_ENROLL_ATTESTATION_CHALLENGE "1.3.6.1.4.1.311.21.28"
#define szOID_ENROLL_ENCRYPTION_ALGORITHM "1.3.6.1.4.1.311.21.29"

#define szOID_KP_TPM_EK_CERTIFICATE "2.23.133.8.1"
#define szOID_KP_TPM_PLATFORM_CERTIFICATE "2.23.133.8.2"
#define szOID_KP_TPM_AIK_CERTIFICATE "2.23.133.8.3"

#define szOID_ENROLL_EKVERIFYKEY "1.3.6.1.4.1.311.21.30"
#define szOID_ENROLL_EKVERIFYCERT "1.3.6.1.4.1.311.21.31"
#define szOID_ENROLL_EKVERIFYCREDS "1.3.6.1.4.1.311.21.32"

#define szOID_ENROLL_SCEP_ERROR "1.3.6.1.4.1.311.21.33"

#define szOID_ENROLL_SCEP_SERVER_STATE "1.3.6.1.4.1.311.21.34"
#define szOID_ENROLL_SCEP_CHALLENGE_ANSWER "1.3.6.1.4.1.311.21.35"
#define szOID_ENROLL_SCEP_CLIENT_REQUEST "1.3.6.1.4.1.311.21.37"
#define szOID_ENROLL_SCEP_SERVER_MESSAGE "1.3.6.1.4.1.311.21.38"
#define szOID_ENROLL_SCEP_SERVER_SECRET "1.3.6.1.4.1.311.21.40"

#define szOID_ENROLL_KEY_AFFINITY "1.3.6.1.4.1.311.21.41"

#define szOID_ENROLL_SCEP_SIGNER_HASH "1.3.6.1.4.1.311.21.42"

#define szOID_ENROLL_EK_CA_KEYID "1.3.6.1.4.1.311.21.43"

#define szOID_ATTR_SUPPORTED_ALGORITHMS "2.5.4.52"
#define szOID_ATTR_TPM_SPECIFICATION "2.23.133.2.16"
#define szOID_ATTR_PLATFORM_SPECIFICATION "2.23.133.2.17"
#define szOID_ATTR_TPM_SECURITY_ASSERTIONS "2.23.133.2.18"

  typedef struct _CERT_EXTENSIONS {
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
  } CERT_EXTENSIONS,*PCERT_EXTENSIONS;

#define CERT_UNICODE_RDN_ERR_INDEX_MASK 0x3ff
#define CERT_UNICODE_RDN_ERR_INDEX_SHIFT 22
#define CERT_UNICODE_ATTR_ERR_INDEX_MASK 0x3f
#define CERT_UNICODE_ATTR_ERR_INDEX_SHIFT 16
#define CERT_UNICODE_VALUE_ERR_INDEX_MASK 0xffff
#define CERT_UNICODE_VALUE_ERR_INDEX_SHIFT 0

#define GET_CERT_UNICODE_RDN_ERR_INDEX(X) ((X >> CERT_UNICODE_RDN_ERR_INDEX_SHIFT) &CERT_UNICODE_RDN_ERR_INDEX_MASK)
#define GET_CERT_UNICODE_ATTR_ERR_INDEX(X) ((X >> CERT_UNICODE_ATTR_ERR_INDEX_SHIFT) &CERT_UNICODE_ATTR_ERR_INDEX_MASK)
#define GET_CERT_UNICODE_VALUE_ERR_INDEX(X) (X &CERT_UNICODE_VALUE_ERR_INDEX_MASK)

  typedef struct _CERT_AUTHORITY_KEY_ID_INFO {
    CRYPT_DATA_BLOB KeyId;
    CERT_NAME_BLOB CertIssuer;
    CRYPT_INTEGER_BLOB CertSerialNumber;
  } CERT_AUTHORITY_KEY_ID_INFO,*PCERT_AUTHORITY_KEY_ID_INFO;

  typedef struct _CERT_PRIVATE_KEY_VALIDITY {
    FILETIME NotBefore;
    FILETIME NotAfter;
  } CERT_PRIVATE_KEY_VALIDITY,*PCERT_PRIVATE_KEY_VALIDITY;

  typedef struct _CERT_KEY_ATTRIBUTES_INFO {
    CRYPT_DATA_BLOB KeyId;
    CRYPT_BIT_BLOB IntendedKeyUsage;
    PCERT_PRIVATE_KEY_VALIDITY pPrivateKeyUsagePeriod;
  } CERT_KEY_ATTRIBUTES_INFO,*PCERT_KEY_ATTRIBUTES_INFO;

#define CERT_ENCIPHER_ONLY_KEY_USAGE 0x01
#define CERT_CRL_SIGN_KEY_USAGE 0x02
#define CERT_OFFLINE_CRL_SIGN_KEY_USAGE 0x02
#define CERT_KEY_CERT_SIGN_KEY_USAGE 0x04
#define CERT_KEY_AGREEMENT_KEY_USAGE 0x08
#define CERT_DATA_ENCIPHERMENT_KEY_USAGE 0x10
#define CERT_KEY_ENCIPHERMENT_KEY_USAGE 0x20
#define CERT_NON_REPUDIATION_KEY_USAGE 0x40
#define CERT_DIGITAL_SIGNATURE_KEY_USAGE 0x80

#define CERT_DECIPHER_ONLY_KEY_USAGE 0x80

  typedef struct _CERT_POLICY_ID {
    DWORD cCertPolicyElementId;
    LPSTR *rgpszCertPolicyElementId;
  } CERT_POLICY_ID,*PCERT_POLICY_ID;

  typedef struct _CERT_KEY_USAGE_RESTRICTION_INFO {
    DWORD cCertPolicyId;
    PCERT_POLICY_ID rgCertPolicyId;
    CRYPT_BIT_BLOB RestrictedKeyUsage;
  } CERT_KEY_USAGE_RESTRICTION_INFO,*PCERT_KEY_USAGE_RESTRICTION_INFO;

  typedef struct _CERT_OTHER_NAME {
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Value;
  } CERT_OTHER_NAME,*PCERT_OTHER_NAME;

  typedef struct _CERT_ALT_NAME_ENTRY {
    DWORD dwAltNameChoice;
    __C89_NAMELESS union {
      PCERT_OTHER_NAME pOtherName;
      LPWSTR pwszRfc822Name;
      LPWSTR pwszDNSName;
      /* CERT_DATA_BLOB is not documented, and x400Address is documented
       * to be not implemented; commented out to prevent compile errors
       * see http://msdn.microsoft.com/en-us/library/aa377173.aspx for
       * CERT_ALT_NAME_ENTRY documentation where this is specified.
      CERT_DATA_BLOB x400Address;
       */
      CERT_NAME_BLOB DirectoryName;
      /* pEdiPartyName is not implemented, either. see:
       * http://msdn.microsoft.com/en-us/library/aa924681.aspx or
       * http://msdn.microsoft.com/en-us/library/aa377173.aspx
      LPWSTR pEdiPartyName;
       */
      LPWSTR pwszURL;
      CRYPT_DATA_BLOB IPAddress;
      LPSTR pszRegisteredID;
    };
  } CERT_ALT_NAME_ENTRY,*PCERT_ALT_NAME_ENTRY;

#define CERT_ALT_NAME_OTHER_NAME 1
#define CERT_ALT_NAME_RFC822_NAME 2
#define CERT_ALT_NAME_DNS_NAME 3
#define CERT_ALT_NAME_X400_ADDRESS 4
#define CERT_ALT_NAME_DIRECTORY_NAME 5
#define CERT_ALT_NAME_EDI_PARTY_NAME 6
#define CERT_ALT_NAME_URL 7
#define CERT_ALT_NAME_IP_ADDRESS 8
#define CERT_ALT_NAME_REGISTERED_ID 9

  typedef struct _CERT_ALT_NAME_INFO {
    DWORD cAltEntry;
    PCERT_ALT_NAME_ENTRY rgAltEntry;
  } CERT_ALT_NAME_INFO,*PCERT_ALT_NAME_INFO;
#define CERT_ALT_NAME_ENTRY_ERR_INDEX_MASK 0xff
#define CERT_ALT_NAME_ENTRY_ERR_INDEX_SHIFT 16
#define CERT_ALT_NAME_VALUE_ERR_INDEX_MASK 0x0000ffff
#define CERT_ALT_NAME_VALUE_ERR_INDEX_SHIFT 0

#define GET_CERT_ALT_NAME_ENTRY_ERR_INDEX(X) ((X >> CERT_ALT_NAME_ENTRY_ERR_INDEX_SHIFT) &CERT_ALT_NAME_ENTRY_ERR_INDEX_MASK)
#define GET_CERT_ALT_NAME_VALUE_ERR_INDEX(X) (X &CERT_ALT_NAME_VALUE_ERR_INDEX_MASK)

  typedef struct _CERT_BASIC_CONSTRAINTS_INFO {
    CRYPT_BIT_BLOB SubjectType;
    WINBOOL fPathLenConstraint;
    DWORD dwPathLenConstraint;
    DWORD cSubtreesConstraint;
    CERT_NAME_BLOB *rgSubtreesConstraint;
  } CERT_BASIC_CONSTRAINTS_INFO, *PCERT_BASIC_CONSTRAINTS_INFO;

#define CERT_CA_SUBJECT_FLAG 0x80
#define CERT_END_ENTITY_SUBJECT_FLAG 0x40

  typedef struct _CERT_BASIC_CONSTRAINTS2_INFO {
    WINBOOL fCA;
    WINBOOL fPathLenConstraint;
    DWORD dwPathLenConstraint;
  } CERT_BASIC_CONSTRAINTS2_INFO,*PCERT_BASIC_CONSTRAINTS2_INFO;

  typedef struct _CERT_POLICY_QUALIFIER_INFO {
    LPSTR pszPolicyQualifierId;
    CRYPT_OBJID_BLOB Qualifier;
  } CERT_POLICY_QUALIFIER_INFO,*PCERT_POLICY_QUALIFIER_INFO;

  typedef struct _CERT_POLICY_INFO {
    LPSTR pszPolicyIdentifier;
    DWORD cPolicyQualifier;
    CERT_POLICY_QUALIFIER_INFO *rgPolicyQualifier;
  } CERT_POLICY_INFO,*PCERT_POLICY_INFO;

  typedef struct _CERT_POLICIES_INFO {
    DWORD cPolicyInfo;
    CERT_POLICY_INFO *rgPolicyInfo;
  } CERT_POLICIES_INFO,*PCERT_POLICIES_INFO;

  typedef struct _CERT_POLICY_QUALIFIER_NOTICE_REFERENCE {
    LPSTR pszOrganization;
    DWORD cNoticeNumbers;
    int *rgNoticeNumbers;
  } CERT_POLICY_QUALIFIER_NOTICE_REFERENCE,*PCERT_POLICY_QUALIFIER_NOTICE_REFERENCE;

  typedef struct _CERT_POLICY_QUALIFIER_USER_NOTICE {
    CERT_POLICY_QUALIFIER_NOTICE_REFERENCE *pNoticeReference;
    LPWSTR pszDisplayText;
  } CERT_POLICY_QUALIFIER_USER_NOTICE,*PCERT_POLICY_QUALIFIER_USER_NOTICE;

  typedef struct _CPS_URLS {
    LPWSTR pszURL;
    CRYPT_ALGORITHM_IDENTIFIER *pAlgorithm;
    CRYPT_DATA_BLOB *pDigest;
  } CPS_URLS,*PCPS_URLS;

  typedef struct _CERT_POLICY95_QUALIFIER1 {
    LPWSTR pszPracticesReference;
    LPSTR pszNoticeIdentifier;
    LPSTR pszNSINoticeIdentifier;
    DWORD cCPSURLs;
    CPS_URLS *rgCPSURLs;
  } CERT_POLICY95_QUALIFIER1,*PCERT_POLICY95_QUALIFIER1;

  typedef struct _CERT_POLICY_MAPPING {
    LPSTR pszIssuerDomainPolicy;
    LPSTR pszSubjectDomainPolicy;
  } CERT_POLICY_MAPPING,*PCERT_POLICY_MAPPING;

  typedef struct _CERT_POLICY_MAPPINGS_INFO {
    DWORD cPolicyMapping;
    PCERT_POLICY_MAPPING rgPolicyMapping;
  } CERT_POLICY_MAPPINGS_INFO,*PCERT_POLICY_MAPPINGS_INFO;

  typedef struct _CERT_POLICY_CONSTRAINTS_INFO {
    WINBOOL fRequireExplicitPolicy;
    DWORD dwRequireExplicitPolicySkipCerts;
    WINBOOL fInhibitPolicyMapping;
    DWORD dwInhibitPolicyMappingSkipCerts;
  } CERT_POLICY_CONSTRAINTS_INFO,*PCERT_POLICY_CONSTRAINTS_INFO;

  typedef struct _CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY {
    LPSTR pszObjId;
    DWORD cValue;
    PCRYPT_DER_BLOB rgValue;
  } CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY,*PCRYPT_CONTENT_INFO_SEQUENCE_OF_ANY;

  typedef struct _CRYPT_CONTENT_INFO {
    LPSTR pszObjId;
    CRYPT_DER_BLOB Content;
  } CRYPT_CONTENT_INFO,*PCRYPT_CONTENT_INFO;

  typedef struct _CRYPT_SEQUENCE_OF_ANY {
    DWORD cValue;
    PCRYPT_DER_BLOB rgValue;
  } CRYPT_SEQUENCE_OF_ANY,*PCRYPT_SEQUENCE_OF_ANY;

  typedef struct _CERT_AUTHORITY_KEY_ID2_INFO {
    CRYPT_DATA_BLOB KeyId;
    CERT_ALT_NAME_INFO AuthorityCertIssuer;
    CRYPT_INTEGER_BLOB AuthorityCertSerialNumber;
  } CERT_AUTHORITY_KEY_ID2_INFO,*PCERT_AUTHORITY_KEY_ID2_INFO;

  typedef struct _CERT_ACCESS_DESCRIPTION {
    LPSTR pszAccessMethod;
    CERT_ALT_NAME_ENTRY AccessLocation;
  } CERT_ACCESS_DESCRIPTION,*PCERT_ACCESS_DESCRIPTION;

  typedef struct _CERT_AUTHORITY_INFO_ACCESS {
    DWORD cAccDescr;
    PCERT_ACCESS_DESCRIPTION rgAccDescr;
  } CERT_AUTHORITY_INFO_ACCESS,*PCERT_AUTHORITY_INFO_ACCESS;

  typedef CERT_AUTHORITY_INFO_ACCESS CERT_SUBJECT_INFO_ACCESS,*PCERT_SUBJECT_INFO_ACCESS;

#define szOID_PKIX_ACC_DESCR "1.3.6.1.5.5.7.48"
#define szOID_PKIX_OCSP "1.3.6.1.5.5.7.48.1"
#define szOID_PKIX_CA_ISSUERS "1.3.6.1.5.5.7.48.2"
#define szOID_PKIX_TIME_STAMPING "1.3.6.1.5.5.7.48.3"
#define szOID_PKIX_CA_REPOSITORY "1.3.6.1.5.5.7.48.5"

#define CRL_REASON_UNSPECIFIED 0
#define CRL_REASON_KEY_COMPROMISE 1
#define CRL_REASON_CA_COMPROMISE 2
#define CRL_REASON_AFFILIATION_CHANGED 3
#define CRL_REASON_SUPERSEDED 4
#define CRL_REASON_CESSATION_OF_OPERATION 5
#define CRL_REASON_CERTIFICATE_HOLD 6
#define CRL_REASON_REMOVE_FROM_CRL 8
#define CRL_REASON_PRIVILEGE_WITHDRAWN 9
#define CRL_REASON_AA_COMPROMISE 10

  typedef struct _CRL_DIST_POINT_NAME {
    DWORD dwDistPointNameChoice;
    __C89_NAMELESS union {
      CERT_ALT_NAME_INFO FullName;
    };
  } CRL_DIST_POINT_NAME,*PCRL_DIST_POINT_NAME;

#define CRL_DIST_POINT_NO_NAME 0
#define CRL_DIST_POINT_FULL_NAME 1
#define CRL_DIST_POINT_ISSUER_RDN_NAME 2

  typedef struct _CRL_DIST_POINT {
    CRL_DIST_POINT_NAME DistPointName;
    CRYPT_BIT_BLOB ReasonFlags;
    CERT_ALT_NAME_INFO CRLIssuer;
  } CRL_DIST_POINT,*PCRL_DIST_POINT;

#define CRL_REASON_UNUSED_FLAG 0x80
#define CRL_REASON_KEY_COMPROMISE_FLAG 0x40
#define CRL_REASON_CA_COMPROMISE_FLAG 0x20
#define CRL_REASON_AFFILIATION_CHANGED_FLAG 0x10
#define CRL_REASON_SUPERSEDED_FLAG 0x08
#define CRL_REASON_CESSATION_OF_OPERATION_FLAG 0x04
#define CRL_REASON_CERTIFICATE_HOLD_FLAG 0x02
#define CRL_REASON_PRIVILEGE_WITHDRAWN_FLAG 0x01
#define CRL_REASON_AA_COMPROMISE_FLAG 0x80

  typedef struct _CRL_DIST_POINTS_INFO {
    DWORD cDistPoint;
    PCRL_DIST_POINT rgDistPoint;
  } CRL_DIST_POINTS_INFO,*PCRL_DIST_POINTS_INFO;

#define CRL_DIST_POINT_ERR_INDEX_MASK 0x7f
#define CRL_DIST_POINT_ERR_INDEX_SHIFT 24
#define GET_CRL_DIST_POINT_ERR_INDEX(X) ((X >> CRL_DIST_POINT_ERR_INDEX_SHIFT) &CRL_DIST_POINT_ERR_INDEX_MASK)

#define CRL_DIST_POINT_ERR_CRL_ISSUER_BIT __MSABI_LONG(0x80000000)
#define IS_CRL_DIST_POINT_ERR_CRL_ISSUER(X) (0 != (X & CRL_DIST_POINT_ERR_CRL_ISSUER_BIT))

  typedef struct _CROSS_CERT_DIST_POINTS_INFO {
    DWORD dwSyncDeltaTime;
    DWORD cDistPoint;
    PCERT_ALT_NAME_INFO rgDistPoint;
  } CROSS_CERT_DIST_POINTS_INFO,*PCROSS_CERT_DIST_POINTS_INFO;

#define CROSS_CERT_DIST_POINT_ERR_INDEX_MASK 0xff
#define CROSS_CERT_DIST_POINT_ERR_INDEX_SHIFT 24
#define GET_CROSS_CERT_DIST_POINT_ERR_INDEX(X) ((X >> CROSS_CERT_DIST_POINT_ERR_INDEX_SHIFT) &CROSS_CERT_DIST_POINT_ERR_INDEX_MASK)

  typedef struct _CERT_PAIR {
    CERT_BLOB Forward;
    CERT_BLOB Reverse;
  } CERT_PAIR,*PCERT_PAIR;

  typedef struct _CRL_ISSUING_DIST_POINT {
    CRL_DIST_POINT_NAME DistPointName;
    WINBOOL fOnlyContainsUserCerts;
    WINBOOL fOnlyContainsCACerts;
    CRYPT_BIT_BLOB OnlySomeReasonFlags;
    WINBOOL fIndirectCRL;
  } CRL_ISSUING_DIST_POINT,*PCRL_ISSUING_DIST_POINT;

  typedef struct _CERT_GENERAL_SUBTREE {
    CERT_ALT_NAME_ENTRY Base;
    DWORD dwMinimum;
    WINBOOL fMaximum;
    DWORD dwMaximum;
  } CERT_GENERAL_SUBTREE,*PCERT_GENERAL_SUBTREE;

  typedef struct _CERT_NAME_CONSTRAINTS_INFO {
    DWORD cPermittedSubtree;
    PCERT_GENERAL_SUBTREE rgPermittedSubtree;
    DWORD cExcludedSubtree;
    PCERT_GENERAL_SUBTREE rgExcludedSubtree;
  } CERT_NAME_CONSTRAINTS_INFO,*PCERT_NAME_CONSTRAINTS_INFO;

#define CERT_EXCLUDED_SUBTREE_BIT __MSABI_LONG(0x80000000)
#define IS_CERT_EXCLUDED_SUBTREE(X) (0!=(X & CERT_EXCLUDED_SUBTREE_BIT))

#define SORTED_CTL_EXT_FLAGS_OFFSET (0)
#define SORTED_CTL_EXT_COUNT_OFFSET (4)
#define SORTED_CTL_EXT_MAX_COLLISION_OFFSET (8)
#define SORTED_CTL_EXT_HASH_BUCKET_OFFSET (12)

#define SORTED_CTL_EXT_HASHED_SUBJECT_IDENTIFIER_FLAG 0x1

  typedef struct _CERT_DSS_PARAMETERS {
    CRYPT_UINT_BLOB p;
    CRYPT_UINT_BLOB q;
    CRYPT_UINT_BLOB g;
  } CERT_DSS_PARAMETERS,*PCERT_DSS_PARAMETERS;

#define CERT_DSS_R_LEN 20
#define CERT_DSS_S_LEN 20
#define CERT_DSS_SIGNATURE_LEN (CERT_DSS_R_LEN + CERT_DSS_S_LEN)

#define CERT_MAX_ASN_ENCODED_DSS_SIGNATURE_LEN (48)

  typedef struct _CERT_DH_PARAMETERS {
    CRYPT_UINT_BLOB p;
    CRYPT_UINT_BLOB g;
  } CERT_DH_PARAMETERS,*PCERT_DH_PARAMETERS;

  typedef struct _CERT_ECC_SIGNATURE {
    CRYPT_UINT_BLOB r;
    CRYPT_UINT_BLOB s;
  } CERT_ECC_SIGNATURE,*PCERT_ECC_SIGNATURE;

  typedef struct _CERT_X942_DH_VALIDATION_PARAMS {
    CRYPT_BIT_BLOB seed;
    DWORD pgenCounter;
  } CERT_X942_DH_VALIDATION_PARAMS,*PCERT_X942_DH_VALIDATION_PARAMS;

  typedef struct _CERT_X942_DH_PARAMETERS {
    CRYPT_UINT_BLOB p;
    CRYPT_UINT_BLOB g;
    CRYPT_UINT_BLOB q;
    CRYPT_UINT_BLOB j;
    PCERT_X942_DH_VALIDATION_PARAMS pValidationParams;
  } CERT_X942_DH_PARAMETERS,*PCERT_X942_DH_PARAMETERS;

#define CRYPT_X942_COUNTER_BYTE_LENGTH 4
#define CRYPT_X942_KEY_LENGTH_BYTE_LENGTH 4
#define CRYPT_X942_PUB_INFO_BYTE_LENGTH (512/8)

  typedef struct _CRYPT_X942_OTHER_INFO {
    LPSTR pszContentEncryptionObjId;
    BYTE rgbCounter[CRYPT_X942_COUNTER_BYTE_LENGTH];
    BYTE rgbKeyLength[CRYPT_X942_KEY_LENGTH_BYTE_LENGTH];
    CRYPT_DATA_BLOB PubInfo;
  } CRYPT_X942_OTHER_INFO,*PCRYPT_X942_OTHER_INFO;

#define CRYPT_ECC_CMS_SHARED_INFO_SUPPPUBINFO_BYTE_LENGTH 4

  typedef struct _CRYPT_ECC_CMS_SHARED_INFO {
    CRYPT_ALGORITHM_IDENTIFIER Algorithm;
    CRYPT_DATA_BLOB EntityUInfo;
    BYTE rgbSuppPubInfo[CRYPT_ECC_CMS_SHARED_INFO_SUPPPUBINFO_BYTE_LENGTH];
  } CRYPT_ECC_CMS_SHARED_INFO,*PCRYPT_ECC_CMS_SHARED_INFO;

  typedef struct _CRYPT_RC2_CBC_PARAMETERS {
    DWORD dwVersion;
    WINBOOL fIV;
    BYTE rgbIV[8];
  } CRYPT_RC2_CBC_PARAMETERS,*PCRYPT_RC2_CBC_PARAMETERS;

#define CRYPT_RC2_40BIT_VERSION 160
#define CRYPT_RC2_56BIT_VERSION 52
#define CRYPT_RC2_64BIT_VERSION 120
#define CRYPT_RC2_128BIT_VERSION 58

  typedef struct _CRYPT_SMIME_CAPABILITY {
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Parameters;
  } CRYPT_SMIME_CAPABILITY,*PCRYPT_SMIME_CAPABILITY;

  typedef struct _CRYPT_SMIME_CAPABILITIES {
    DWORD cCapability;
    PCRYPT_SMIME_CAPABILITY rgCapability;
  } CRYPT_SMIME_CAPABILITIES,*PCRYPT_SMIME_CAPABILITIES;

  typedef struct _CERT_QC_STATEMENT {
    LPSTR pszStatementId;
    CRYPT_OBJID_BLOB StatementInfo;
  } CERT_QC_STATEMENT,*PCERT_QC_STATEMENT;

  typedef struct _CERT_QC_STATEMENTS_EXT_INFO {
    DWORD cStatement;
    PCERT_QC_STATEMENT rgStatement;
  } CERT_QC_STATEMENTS_EXT_INFO,*PCERT_QC_STATEMENTS_EXT_INFO;

#define szOID_QC_EU_COMPLIANCE "0.4.0.1862.1.1"
#define szOID_QC_SSCD "0.4.0.1862.1.4"

  typedef struct _CRYPT_MASK_GEN_ALGORITHM {
    LPSTR pszObjId;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
  } CRYPT_MASK_GEN_ALGORITHM,*PCRYPT_MASK_GEN_ALGORITHM;

  typedef struct _CRYPT_RSA_SSA_PSS_PARAMETERS {
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_MASK_GEN_ALGORITHM MaskGenAlgorithm;
    DWORD dwSaltLength;
    DWORD dwTrailerField;
  } CRYPT_RSA_SSA_PSS_PARAMETERS,*PCRYPT_RSA_SSA_PSS_PARAMETERS;

#define PKCS_RSA_SSA_PSS_TRAILER_FIELD_BC 1

  typedef struct _CRYPT_PSOURCE_ALGORITHM {
    LPSTR pszObjId;
    CRYPT_DATA_BLOB EncodingParameters;
  } CRYPT_PSOURCE_ALGORITHM,*PCRYPT_PSOURCE_ALGORITHM;

  typedef struct _CRYPT_RSAES_OAEP_PARAMETERS {
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_MASK_GEN_ALGORITHM MaskGenAlgorithm;
    CRYPT_PSOURCE_ALGORITHM PSourceAlgorithm;
  } CRYPT_RSAES_OAEP_PARAMETERS,*PCRYPT_RSAES_OAEP_PARAMETERS;

#define szOID_VERISIGN_PRIVATE_6_9 "2.16.840.1.113733.1.6.9"
#define szOID_VERISIGN_ONSITE_JURISDICTION_HASH "2.16.840.1.113733.1.6.11"
#define szOID_VERISIGN_BITSTRING_6_13 "2.16.840.1.113733.1.6.13"

#define szOID_VERISIGN_ISS_STRONG_CRYPTO "2.16.840.1.113733.1.8.1"

#define szOIDVerisign_MessageType "2.16.840.1.113733.1.9.2"
#define szOIDVerisign_PkiStatus "2.16.840.1.113733.1.9.3"
#define szOIDVerisign_FailInfo "2.16.840.1.113733.1.9.4"

#define szOIDVerisign_SenderNonce "2.16.840.1.113733.1.9.5"
#define szOIDVerisign_RecipientNonce "2.16.840.1.113733.1.9.6"

#define szOIDVerisign_TransactionID "2.16.840.1.113733.1.9.7"

#define szOID_NETSCAPE "2.16.840.1.113730"
#define szOID_NETSCAPE_CERT_EXTENSION "2.16.840.1.113730.1"
#define szOID_NETSCAPE_CERT_TYPE "2.16.840.1.113730.1.1"
#define szOID_NETSCAPE_BASE_URL "2.16.840.1.113730.1.2"
#define szOID_NETSCAPE_REVOCATION_URL "2.16.840.1.113730.1.3"
#define szOID_NETSCAPE_CA_REVOCATION_URL "2.16.840.1.113730.1.4"
#define szOID_NETSCAPE_CERT_RENEWAL_URL "2.16.840.1.113730.1.7"
#define szOID_NETSCAPE_CA_POLICY_URL "2.16.840.1.113730.1.8"
#define szOID_NETSCAPE_SSL_SERVER_NAME "2.16.840.1.113730.1.12"
#define szOID_NETSCAPE_COMMENT "2.16.840.1.113730.1.13"

#define szOID_NETSCAPE_DATA_TYPE "2.16.840.1.113730.2"
#define szOID_NETSCAPE_CERT_SEQUENCE "2.16.840.1.113730.2.5"

#define NETSCAPE_SIGN_CA_CERT_TYPE 0x01
#define NETSCAPE_SMIME_CA_CERT_TYPE 0x02
#define NETSCAPE_SSL_CA_CERT_TYPE 0x04
#define NETSCAPE_SIGN_CERT_TYPE 0x10
#define NETSCAPE_SMIME_CERT_TYPE 0x20
#define NETSCAPE_SSL_SERVER_AUTH_CERT_TYPE 0x40
#define NETSCAPE_SSL_CLIENT_AUTH_CERT_TYPE 0x80

#define szOID_CT_PKI_DATA "1.3.6.1.5.5.7.12.2"
#define szOID_CT_PKI_RESPONSE "1.3.6.1.5.5.7.12.3"

#define szOID_PKIX_NO_SIGNATURE "1.3.6.1.5.5.7.6.2"

#define szOID_CMC "1.3.6.1.5.5.7.7"
#define szOID_CMC_STATUS_INFO "1.3.6.1.5.5.7.7.1"
#define szOID_CMC_IDENTIFICATION "1.3.6.1.5.5.7.7.2"
#define szOID_CMC_IDENTITY_PROOF "1.3.6.1.5.5.7.7.3"
#define szOID_CMC_DATA_RETURN "1.3.6.1.5.5.7.7.4"
#define szOID_CMC_TRANSACTION_ID "1.3.6.1.5.5.7.7.5"
#define szOID_CMC_SENDER_NONCE "1.3.6.1.5.5.7.7.6"
#define szOID_CMC_RECIPIENT_NONCE "1.3.6.1.5.5.7.7.7"
#define szOID_CMC_ADD_EXTENSIONS "1.3.6.1.5.5.7.7.8"
#define szOID_CMC_ENCRYPTED_POP "1.3.6.1.5.5.7.7.9"
#define szOID_CMC_DECRYPTED_POP "1.3.6.1.5.5.7.7.10"
#define szOID_CMC_LRA_POP_WITNESS "1.3.6.1.5.5.7.7.11"
#define szOID_CMC_GET_CERT "1.3.6.1.5.5.7.7.15"
#define szOID_CMC_GET_CRL "1.3.6.1.5.5.7.7.16"
#define szOID_CMC_REVOKE_REQUEST "1.3.6.1.5.5.7.7.17"
#define szOID_CMC_REG_INFO "1.3.6.1.5.5.7.7.18"
#define szOID_CMC_RESPONSE_INFO "1.3.6.1.5.5.7.7.19"
#define szOID_CMC_QUERY_PENDING "1.3.6.1.5.5.7.7.21"
#define szOID_CMC_ID_POP_LINK_RANDOM "1.3.6.1.5.5.7.7.22"
#define szOID_CMC_ID_POP_LINK_WITNESS "1.3.6.1.5.5.7.7.23"
#define szOID_CMC_ID_CONFIRM_CERT_ACCEPTANCE "1.3.6.1.5.5.7.7.24"

#define szOID_CMC_ADD_ATTRIBUTES "1.3.6.1.4.1.311.10.10.1"

  typedef struct _CMC_TAGGED_ATTRIBUTE {
    DWORD dwBodyPartID;
    CRYPT_ATTRIBUTE Attribute;
  } CMC_TAGGED_ATTRIBUTE,*PCMC_TAGGED_ATTRIBUTE;

  typedef struct _CMC_TAGGED_CERT_REQUEST {
    DWORD dwBodyPartID;
    CRYPT_DER_BLOB SignedCertRequest;
  } CMC_TAGGED_CERT_REQUEST,*PCMC_TAGGED_CERT_REQUEST;

  typedef struct _CMC_TAGGED_REQUEST {
    DWORD dwTaggedRequestChoice;
    __C89_NAMELESS union {
      PCMC_TAGGED_CERT_REQUEST pTaggedCertRequest;
    };
  } CMC_TAGGED_REQUEST,*PCMC_TAGGED_REQUEST;

#define CMC_TAGGED_CERT_REQUEST_CHOICE 1

  typedef struct _CMC_TAGGED_CONTENT_INFO {
    DWORD dwBodyPartID;
    CRYPT_DER_BLOB EncodedContentInfo;
  } CMC_TAGGED_CONTENT_INFO,*PCMC_TAGGED_CONTENT_INFO;

  typedef struct _CMC_TAGGED_OTHER_MSG {
    DWORD dwBodyPartID;
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Value;
  } CMC_TAGGED_OTHER_MSG,*PCMC_TAGGED_OTHER_MSG;

  typedef struct _CMC_DATA_INFO {
    DWORD cTaggedAttribute;
    PCMC_TAGGED_ATTRIBUTE rgTaggedAttribute;
    DWORD cTaggedRequest;
    PCMC_TAGGED_REQUEST rgTaggedRequest;
    DWORD cTaggedContentInfo;
    PCMC_TAGGED_CONTENT_INFO rgTaggedContentInfo;
    DWORD cTaggedOtherMsg;
    PCMC_TAGGED_OTHER_MSG rgTaggedOtherMsg;
  } CMC_DATA_INFO,*PCMC_DATA_INFO;

  typedef struct _CMC_RESPONSE_INFO {
    DWORD cTaggedAttribute;
    PCMC_TAGGED_ATTRIBUTE rgTaggedAttribute;
    DWORD cTaggedContentInfo;
    PCMC_TAGGED_CONTENT_INFO rgTaggedContentInfo;
    DWORD cTaggedOtherMsg;
    PCMC_TAGGED_OTHER_MSG rgTaggedOtherMsg;
  } CMC_RESPONSE_INFO,*PCMC_RESPONSE_INFO;

  typedef struct _CMC_PEND_INFO {
    CRYPT_DATA_BLOB PendToken;
    FILETIME PendTime;
  } CMC_PEND_INFO,*PCMC_PEND_INFO;

  typedef struct _CMC_STATUS_INFO {
    DWORD dwStatus;
    DWORD cBodyList;
    DWORD *rgdwBodyList;
    LPWSTR pwszStatusString;
    DWORD dwOtherInfoChoice;
    __C89_NAMELESS union {
      DWORD dwFailInfo;
      PCMC_PEND_INFO pPendInfo;
    };
  } CMC_STATUS_INFO,*PCMC_STATUS_INFO;

#define CMC_OTHER_INFO_NO_CHOICE 0
#define CMC_OTHER_INFO_FAIL_CHOICE 1
#define CMC_OTHER_INFO_PEND_CHOICE 2

#define CMC_STATUS_SUCCESS 0
#define CMC_STATUS_FAILED 2
#define CMC_STATUS_PENDING 3
#define CMC_STATUS_NO_SUPPORT 4
#define CMC_STATUS_CONFIRM_REQUIRED 5

#define CMC_FAIL_BAD_ALG 0
#define CMC_FAIL_BAD_MESSAGE_CHECK 1
#define CMC_FAIL_BAD_REQUEST 2
#define CMC_FAIL_BAD_TIME 3
#define CMC_FAIL_BAD_CERT_ID 4
#define CMC_FAIL_UNSUPORTED_EXT 5
#define CMC_FAIL_MUST_ARCHIVE_KEYS 6
#define CMC_FAIL_BAD_IDENTITY 7
#define CMC_FAIL_POP_REQUIRED 8
#define CMC_FAIL_POP_FAILED 9
#define CMC_FAIL_NO_KEY_REUSE 10
#define CMC_FAIL_INTERNAL_CA_ERROR 11
#define CMC_FAIL_TRY_LATER 12

  typedef struct _CMC_ADD_EXTENSIONS_INFO {
    DWORD dwCmcDataReference;
    DWORD cCertReference;
    DWORD *rgdwCertReference;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
  } CMC_ADD_EXTENSIONS_INFO,*PCMC_ADD_EXTENSIONS_INFO;

  typedef struct _CMC_ADD_ATTRIBUTES_INFO {
    DWORD dwCmcDataReference;
    DWORD cCertReference;
    DWORD *rgdwCertReference;
    DWORD cAttribute;
    PCRYPT_ATTRIBUTE rgAttribute;
  } CMC_ADD_ATTRIBUTES_INFO,*PCMC_ADD_ATTRIBUTES_INFO;

  typedef struct _CERT_TEMPLATE_EXT {
    LPSTR pszObjId;
    DWORD dwMajorVersion;
    WINBOOL fMinorVersion;
    DWORD dwMinorVersion;
  } CERT_TEMPLATE_EXT,*PCERT_TEMPLATE_EXT;

  typedef struct _CERT_HASHED_URL {
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_HASH_BLOB Hash;
    LPWSTR pwszUrl;
  } CERT_HASHED_URL,*PCERT_HASHED_URL;

  typedef struct _CERT_LOGOTYPE_DETAILS {
    LPWSTR pwszMimeType;
    DWORD cHashedUrl;
    PCERT_HASHED_URL rgHashedUrl;
  } CERT_LOGOTYPE_DETAILS,*PCERT_LOGOTYPE_DETAILS;

  typedef struct _CERT_LOGOTYPE_REFERENCE {
    DWORD cHashedUrl;
    PCERT_HASHED_URL rgHashedUrl;
  } CERT_LOGOTYPE_REFERENCE,*PCERT_LOGOTYPE_REFERENCE;

  typedef struct _CERT_LOGOTYPE_IMAGE_INFO {
    DWORD dwLogotypeImageInfoChoice;
    DWORD dwFileSize;
    DWORD dwXSize;
    DWORD dwYSize;
    DWORD dwLogotypeImageResolutionChoice;
    __C89_NAMELESS union {
      DWORD dwNumBits;
      DWORD dwTableSize;
    };
    LPWSTR pwszLanguage;
  } CERT_LOGOTYPE_IMAGE_INFO,*PCERT_LOGOTYPE_IMAGE_INFO;

#define CERT_LOGOTYPE_GRAY_SCALE_IMAGE_INFO_CHOICE 1
#define CERT_LOGOTYPE_COLOR_IMAGE_INFO_CHOICE 2

#define CERT_LOGOTYPE_NO_IMAGE_RESOLUTION_CHOICE 0
#define CERT_LOGOTYPE_BITS_IMAGE_RESOLUTION_CHOICE 1
#define CERT_LOGOTYPE_TABLE_SIZE_IMAGE_RESOLUTION_CHOICE 2

  typedef struct _CERT_LOGOTYPE_IMAGE {
    CERT_LOGOTYPE_DETAILS LogotypeDetails;
    PCERT_LOGOTYPE_IMAGE_INFO pLogotypeImageInfo;
  } CERT_LOGOTYPE_IMAGE,*PCERT_LOGOTYPE_IMAGE;

  typedef struct _CERT_LOGOTYPE_AUDIO_INFO {
    DWORD dwFileSize;
    DWORD dwPlayTime;
    DWORD dwChannels;
    DWORD dwSampleRate;
    LPWSTR pwszLanguage;
  } CERT_LOGOTYPE_AUDIO_INFO,*PCERT_LOGOTYPE_AUDIO_INFO;

  typedef struct _CERT_LOGOTYPE_AUDIO {
    CERT_LOGOTYPE_DETAILS LogotypeDetails;
    PCERT_LOGOTYPE_AUDIO_INFO pLogotypeAudioInfo;
  } CERT_LOGOTYPE_AUDIO,*PCERT_LOGOTYPE_AUDIO;

  typedef struct _CERT_LOGOTYPE_DATA {
    DWORD cLogotypeImage;
    PCERT_LOGOTYPE_IMAGE rgLogotypeImage;
    DWORD cLogotypeAudio;
    PCERT_LOGOTYPE_AUDIO rgLogotypeAudio;
  } CERT_LOGOTYPE_DATA,*PCERT_LOGOTYPE_DATA;

  typedef struct _CERT_LOGOTYPE_INFO {
    DWORD dwLogotypeInfoChoice;
    __C89_NAMELESS union {
      PCERT_LOGOTYPE_DATA pLogotypeDirectInfo;
      PCERT_LOGOTYPE_REFERENCE pLogotypeIndirectInfo;
    };
  } CERT_LOGOTYPE_INFO,*PCERT_LOGOTYPE_INFO;

#define CERT_LOGOTYPE_DIRECT_INFO_CHOICE 1
#define CERT_LOGOTYPE_INDIRECT_INFO_CHOICE 2

  typedef struct _CERT_OTHER_LOGOTYPE_INFO {
    LPSTR pszObjId;
    CERT_LOGOTYPE_INFO LogotypeInfo;
  } CERT_OTHER_LOGOTYPE_INFO,*PCERT_OTHER_LOGOTYPE_INFO;

#define szOID_LOYALTY_OTHER_LOGOTYPE "1.3.6.1.5.5.7.20.1"
#define szOID_BACKGROUND_OTHER_LOGOTYPE "1.3.6.1.5.5.7.20.2"

  typedef struct _CERT_LOGOTYPE_EXT_INFO {
    DWORD cCommunityLogo;
    PCERT_LOGOTYPE_INFO rgCommunityLogo;
    PCERT_LOGOTYPE_INFO pIssuerLogo;
    PCERT_LOGOTYPE_INFO pSubjectLogo;
    DWORD cOtherLogo;
    PCERT_OTHER_LOGOTYPE_INFO rgOtherLogo;
  } CERT_LOGOTYPE_EXT_INFO,*PCERT_LOGOTYPE_EXT_INFO;

  typedef struct _CERT_BIOMETRIC_DATA {
    DWORD dwTypeOfBiometricDataChoice;
    __C89_NAMELESS union {
      DWORD dwPredefined;
      LPSTR pszObjId;
    };
    CERT_HASHED_URL HashedUrl;
  } CERT_BIOMETRIC_DATA,*PCERT_BIOMETRIC_DATA;

#define CERT_BIOMETRIC_PREDEFINED_DATA_CHOICE 1
#define CERT_BIOMETRIC_OID_DATA_CHOICE 2

#define CERT_BIOMETRIC_PICTURE_TYPE 0
#define CERT_BIOMETRIC_SIGNATURE_TYPE 1

  typedef struct _CERT_BIOMETRIC_EXT_INFO {
    DWORD cBiometricData;
    PCERT_BIOMETRIC_DATA rgBiometricData;
  } CERT_BIOMETRIC_EXT_INFO,*PCERT_BIOMETRIC_EXT_INFO;

  typedef struct _OCSP_SIGNATURE_INFO {
    CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
    CRYPT_BIT_BLOB Signature;
    DWORD cCertEncoded;
    PCERT_BLOB rgCertEncoded;
  } OCSP_SIGNATURE_INFO,*POCSP_SIGNATURE_INFO;

  typedef struct _OCSP_SIGNED_REQUEST_INFO {
    CRYPT_DER_BLOB ToBeSigned;
    POCSP_SIGNATURE_INFO pOptionalSignatureInfo;
  } OCSP_SIGNED_REQUEST_INFO,*POCSP_SIGNED_REQUEST_INFO;

  typedef struct _OCSP_CERT_ID {
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_HASH_BLOB IssuerNameHash;
    CRYPT_HASH_BLOB IssuerKeyHash;
    CRYPT_INTEGER_BLOB SerialNumber;
  } OCSP_CERT_ID,*POCSP_CERT_ID;

  typedef struct _OCSP_REQUEST_ENTRY {
    OCSP_CERT_ID CertId;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
  } OCSP_REQUEST_ENTRY,*POCSP_REQUEST_ENTRY;

  typedef struct _OCSP_REQUEST_INFO {
    DWORD dwVersion;
    PCERT_ALT_NAME_ENTRY pRequestorName;
    DWORD cRequestEntry;
    POCSP_REQUEST_ENTRY rgRequestEntry;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
  } OCSP_REQUEST_INFO,*POCSP_REQUEST_INFO;

#define OCSP_REQUEST_V1 0

  typedef struct _OCSP_RESPONSE_INFO {
    DWORD dwStatus;
    LPSTR pszObjId;
    CRYPT_OBJID_BLOB Value;
  } OCSP_RESPONSE_INFO,*POCSP_RESPONSE_INFO;

#define OCSP_SUCCESSFUL_RESPONSE 0
#define OCSP_MALFORMED_REQUEST_RESPONSE 1
#define OCSP_INTERNAL_ERROR_RESPONSE 2
#define OCSP_TRY_LATER_RESPONSE 3
#define OCSP_SIG_REQUIRED_RESPONSE 5
#define OCSP_UNAUTHORIZED_RESPONSE 6

#define szOID_PKIX_OCSP_BASIC_SIGNED_RESPONSE "1.3.6.1.5.5.7.48.1.1"

  typedef struct _OCSP_BASIC_SIGNED_RESPONSE_INFO {
    CRYPT_DER_BLOB ToBeSigned;
    OCSP_SIGNATURE_INFO SignatureInfo;
  } OCSP_BASIC_SIGNED_RESPONSE_INFO,*POCSP_BASIC_SIGNED_RESPONSE_INFO;

  typedef struct _OCSP_BASIC_REVOKED_INFO {
    FILETIME RevocationDate;
    DWORD dwCrlReasonCode;
  } OCSP_BASIC_REVOKED_INFO,*POCSP_BASIC_REVOKED_INFO;

  typedef struct _OCSP_BASIC_RESPONSE_ENTRY {
    OCSP_CERT_ID CertId;
    DWORD dwCertStatus;
    __C89_NAMELESS union {
      POCSP_BASIC_REVOKED_INFO pRevokedInfo;
    };
    FILETIME ThisUpdate;
    FILETIME NextUpdate;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
  } OCSP_BASIC_RESPONSE_ENTRY,*POCSP_BASIC_RESPONSE_ENTRY;

#define OCSP_BASIC_GOOD_CERT_STATUS 0
#define OCSP_BASIC_REVOKED_CERT_STATUS 1
#define OCSP_BASIC_UNKNOWN_CERT_STATUS 2

  typedef struct _OCSP_BASIC_RESPONSE_INFO {
    DWORD dwVersion;
    DWORD dwResponderIdChoice;
    __C89_NAMELESS union {
      CERT_NAME_BLOB ByNameResponderId;
      CRYPT_HASH_BLOB ByKeyResponderId;
    };
    FILETIME ProducedAt;
    DWORD cResponseEntry;
    POCSP_BASIC_RESPONSE_ENTRY rgResponseEntry;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
  } OCSP_BASIC_RESPONSE_INFO,*POCSP_BASIC_RESPONSE_INFO;

#define OCSP_BASIC_RESPONSE_V1 0
#define OCSP_BASIC_BY_NAME_RESPONDER_ID 1
#define OCSP_BASIC_BY_KEY_RESPONDER_ID 2

  typedef struct _CERT_SUPPORTED_ALGORITHM_INFO {
    CRYPT_ALGORITHM_IDENTIFIER Algorithm;
    CRYPT_BIT_BLOB IntendedKeyUsage;
    CERT_POLICIES_INFO IntendedCertPolicies;
  } CERT_SUPPORTED_ALGORITHM_INFO, *PCERT_SUPPORTED_ALGORITHM_INFO;

  typedef struct _CERT_TPM_SPECIFICATION_INFO {
    LPWSTR pwszFamily;
    DWORD dwLevel;
    DWORD dwRevision;
  } CERT_TPM_SPECIFICATION_INFO, *PCERT_TPM_SPECIFICATION_INFO;

  typedef void *HCRYPTOIDFUNCSET;
  typedef void *HCRYPTOIDFUNCADDR;

#define CRYPT_OID_ENCODE_OBJECT_FUNC "CryptDllEncodeObject"
#define CRYPT_OID_DECODE_OBJECT_FUNC "CryptDllDecodeObject"
#define CRYPT_OID_ENCODE_OBJECT_EX_FUNC "CryptDllEncodeObjectEx"
#define CRYPT_OID_DECODE_OBJECT_EX_FUNC "CryptDllDecodeObjectEx"
#define CRYPT_OID_CREATE_COM_OBJECT_FUNC "CryptDllCreateCOMObject"
#define CRYPT_OID_VERIFY_REVOCATION_FUNC "CertDllVerifyRevocation"
#define CRYPT_OID_VERIFY_CTL_USAGE_FUNC "CertDllVerifyCTLUsage"
#define CRYPT_OID_FORMAT_OBJECT_FUNC "CryptDllFormatObject"
#define CRYPT_OID_FIND_OID_INFO_FUNC "CryptDllFindOIDInfo"
#define CRYPT_OID_FIND_LOCALIZED_NAME_FUNC "CryptDllFindLocalizedName"

#define CRYPT_OID_REGPATH "Software\\Microsoft\\Cryptography\\OID"
#define CRYPT_OID_REG_ENCODING_TYPE_PREFIX "EncodingType "
#define CRYPT_OID_REG_DLL_VALUE_NAME L"Dll"
#define CRYPT_OID_REG_FUNC_NAME_VALUE_NAME L"FuncName"
#define CRYPT_OID_REG_FUNC_NAME_VALUE_NAME_A "FuncName"

#define CRYPT_OID_REG_FLAGS_VALUE_NAME L"CryptFlags"

#define CRYPT_DEFAULT_OID "DEFAULT"

  typedef struct _CRYPT_OID_FUNC_ENTRY {
    LPCSTR pszOID;
    void *pvFuncAddr;
  } CRYPT_OID_FUNC_ENTRY,*PCRYPT_OID_FUNC_ENTRY;

#define CRYPT_INSTALL_OID_FUNC_BEFORE_FLAG 1
#define CRYPT_GET_INSTALLED_OID_FUNC_FLAG 0x1

#define CRYPT_REGISTER_FIRST_INDEX 0
#define CRYPT_REGISTER_LAST_INDEX 0xffffffff

  WINIMPM WINBOOL WINAPI CryptInstallOIDFunctionAddress (HMODULE hModule, DWORD dwEncodingType, LPCSTR pszFuncName, DWORD cFuncEntry, const CRYPT_OID_FUNC_ENTRY rgFuncEntry[], DWORD dwFlags);
  WINIMPM HCRYPTOIDFUNCSET WINAPI CryptInitOIDFunctionSet (LPCSTR pszFuncName, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptGetOIDFunctionAddress (HCRYPTOIDFUNCSET hFuncSet, DWORD dwEncodingType, LPCSTR pszOID, DWORD dwFlags, void **ppvFuncAddr, HCRYPTOIDFUNCADDR *phFuncAddr);
  WINIMPM WINBOOL WINAPI CryptGetDefaultOIDDllList (HCRYPTOIDFUNCSET hFuncSet, DWORD dwEncodingType, WCHAR *pwszDllList, DWORD *pcchDllList);
  WINIMPM WINBOOL WINAPI CryptGetDefaultOIDFunctionAddress (HCRYPTOIDFUNCSET hFuncSet, DWORD dwEncodingType, LPCWSTR pwszDll, DWORD dwFlags, void **ppvFuncAddr, HCRYPTOIDFUNCADDR *phFuncAddr);
  WINIMPM WINBOOL WINAPI CryptFreeOIDFunctionAddress (HCRYPTOIDFUNCADDR hFuncAddr, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptRegisterOIDFunction (DWORD dwEncodingType, LPCSTR pszFuncName, LPCSTR pszOID, LPCWSTR pwszDll, LPCSTR pszOverrideFuncName);
  WINIMPM WINBOOL WINAPI CryptUnregisterOIDFunction (DWORD dwEncodingType, LPCSTR pszFuncName, LPCSTR pszOID);
  WINIMPM WINBOOL WINAPI CryptRegisterDefaultOIDFunction (DWORD dwEncodingType, LPCSTR pszFuncName, DWORD dwIndex, LPCWSTR pwszDll);
  WINIMPM WINBOOL WINAPI CryptUnregisterDefaultOIDFunction (DWORD dwEncodingType, LPCSTR pszFuncName, LPCWSTR pwszDll);
  WINIMPM WINBOOL WINAPI CryptSetOIDFunctionValue (DWORD dwEncodingType, LPCSTR pszFuncName, LPCSTR pszOID, LPCWSTR pwszValueName, DWORD dwValueType, const BYTE *pbValueData, DWORD cbValueData);
  WINIMPM WINBOOL WINAPI CryptGetOIDFunctionValue (DWORD dwEncodingType, LPCSTR pszFuncName, LPCSTR pszOID, LPCWSTR pwszValueName, DWORD *pdwValueType, BYTE *pbValueData, DWORD *pcbValueData);

  typedef WINBOOL (WINAPI *PFN_CRYPT_ENUM_OID_FUNC) (DWORD dwEncodingType, LPCSTR pszFuncName, LPCSTR pszOID, DWORD cValue, const DWORD rgdwValueType[], LPCWSTR const rgpwszValueName[], const BYTE *const rgpbValueData[], const DWORD rgcbValueData[], void *pvArg);

  WINIMPM WINBOOL WINAPI CryptEnumOIDFunction (DWORD dwEncodingType, LPCSTR pszFuncName, LPCSTR pszOID, DWORD dwFlags, void *pvArg, PFN_CRYPT_ENUM_OID_FUNC pfnEnumOIDFunc);

#define CRYPT_MATCH_ANY_ENCODING_TYPE 0xffffffff
#define CALG_OID_INFO_CNG_ONLY 0xffffffff
#define CALG_OID_INFO_PARAMETERS 0xfffffffe
#define IS_SPECIAL_OID_INFO_ALGID(Algid) (Algid >= CALG_OID_INFO_PARAMETERS)

#define CRYPT_OID_INFO_HASH_PARAMETERS_ALGORITHM L"CryptOIDInfoHashParameters"
#define CRYPT_OID_INFO_ECC_PARAMETERS_ALGORITHM L"CryptOIDInfoECCParameters"
#define CRYPT_OID_INFO_MGF1_PARAMETERS_ALGORITHM L"CryptOIDInfoMgf1Parameters"
#define CRYPT_OID_INFO_NO_SIGN_ALGORITHM L"CryptOIDInfoNoSign"
#define CRYPT_OID_INFO_OAEP_PARAMETERS_ALGORITHM L"CryptOIDInfoOAEPParameters"
#define CRYPT_OID_INFO_ECC_WRAP_PARAMETERS_ALGORITHM L"CryptOIDInfoECCWrapParameters"
#define CRYPT_OID_INFO_NO_PARAMETERS_ALGORITHM L"CryptOIDInfoNoParameters"

  typedef struct _CRYPT_OID_INFO {
    DWORD cbSize;
    LPCSTR pszOID;
    LPCWSTR pwszName;
    DWORD dwGroupId;
    __C89_NAMELESS union {
      DWORD dwValue;
      ALG_ID Algid;
      DWORD dwLength;
    };
    CRYPT_DATA_BLOB ExtraInfo;
#ifdef CRYPT_OID_INFO_HAS_EXTRA_FIELDS
    LPCWSTR pwszCNGAlgid;
    LPCWSTR pwszCNGExtraAlgid;
#endif
  } CRYPT_OID_INFO,*PCRYPT_OID_INFO;

  typedef const CRYPT_OID_INFO CCRYPT_OID_INFO,*PCCRYPT_OID_INFO;

#define CRYPT_HASH_ALG_OID_GROUP_ID 1
#define CRYPT_ENCRYPT_ALG_OID_GROUP_ID 2
#define CRYPT_PUBKEY_ALG_OID_GROUP_ID 3
#define CRYPT_SIGN_ALG_OID_GROUP_ID 4
#define CRYPT_RDN_ATTR_OID_GROUP_ID 5
#define CRYPT_EXT_OR_ATTR_OID_GROUP_ID 6
#define CRYPT_ENHKEY_USAGE_OID_GROUP_ID 7
#define CRYPT_POLICY_OID_GROUP_ID 8
#define CRYPT_TEMPLATE_OID_GROUP_ID 9
#define CRYPT_KDF_OID_GROUP_ID 10
#define CRYPT_LAST_OID_GROUP_ID 10

#define CRYPT_FIRST_ALG_OID_GROUP_ID CRYPT_HASH_ALG_OID_GROUP_ID
#define CRYPT_LAST_ALG_OID_GROUP_ID CRYPT_SIGN_ALG_OID_GROUP_ID

#define CRYPT_OID_INHIBIT_SIGNATURE_FORMAT_FLAG 0x1
#define CRYPT_OID_USE_PUBKEY_PARA_FOR_PKCS7_FLAG 0x2
#define CRYPT_OID_NO_NULL_ALGORITHM_PARA_FLAG 0x4

#define CRYPT_OID_PUBKEY_ENCRYPT_ONLY_FLAG 0x40000000
#define CRYPT_OID_PUBKEY_SIGN_ONLY_FLAG 0x80000000
#define CRYPT_OID_USE_CURVE_NAME_FOR_ENCODE_FLAG 0x20000000
#define CRYPT_OID_USE_CURVE_PARAMETERS_FOR_ENCODE_FLAG 0x10000000

  WINIMPM PCCRYPT_OID_INFO WINAPI CryptFindOIDInfo (DWORD dwKeyType, void *pvKey, DWORD dwGroupId);

#define CRYPT_OID_INFO_OID_KEY 1
#define CRYPT_OID_INFO_NAME_KEY 2
#define CRYPT_OID_INFO_ALGID_KEY 3
#define CRYPT_OID_INFO_SIGN_KEY 4
#define CRYPT_OID_INFO_CNG_ALGID_KEY 5
#define CRYPT_OID_INFO_CNG_SIGN_KEY 6

#define CRYPT_OID_INFO_OID_KEY_FLAGS_MASK 0xffff0000
#define CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG 0x80000000
#define CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG 0x40000000

#define CRYPT_OID_DISABLE_SEARCH_DS_FLAG 0x80000000

#ifdef CRYPT_OID_INFO_HAS_EXTRA_FIELDS
#define CRYPT_OID_PREFER_CNG_ALGID_FLAG 0x40000000
#endif

#define CRYPT_OID_INFO_OID_GROUP_BIT_LEN_MASK 0x0fff0000
#define CRYPT_OID_INFO_OID_GROUP_BIT_LEN_SHIFT 16

#define CRYPT_INSTALL_OID_INFO_BEFORE_FLAG 1

  typedef WINBOOL (WINAPI *PFN_CRYPT_ENUM_OID_INFO) (PCCRYPT_OID_INFO pInfo, void *pvArg);

  WINIMPM WINBOOL WINAPI CryptRegisterOIDInfo (PCCRYPT_OID_INFO pInfo, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CryptUnregisterOIDInfo (PCCRYPT_OID_INFO pInfo);
  WINIMPM WINBOOL WINAPI CryptEnumOIDInfo (DWORD dwGroupId, DWORD dwFlags, void *pvArg, PFN_CRYPT_ENUM_OID_INFO pfnEnumOIDInfo);
  WINIMPM LPCWSTR WINAPI CryptFindLocalizedName (LPCWSTR pwszCryptName);

#define CRYPT_LOCALIZED_NAME_ENCODING_TYPE 0
#define CRYPT_LOCALIZED_NAME_OID "LocalizedNames"

#define CERT_STRONG_SIGN_ECDSA_ALGORITHM L"ECDSA"

  typedef struct _CERT_STRONG_SIGN_SERIALIZED_INFO {
    DWORD dwFlags;
    LPWSTR pwszCNGSignHashAlgids;
    LPWSTR pwszCNGPubKeyMinBitLengths;
  } CERT_STRONG_SIGN_SERIALIZED_INFO,*PCERT_STRONG_SIGN_SERIALIZED_INFO;

  typedef struct _CERT_STRONG_SIGN_PARA {
    DWORD cbSize;
    DWORD dwInfoChoice;
    __C89_NAMELESS union {
      void *pvInfo;
      PCERT_STRONG_SIGN_SERIALIZED_INFO pSerializedInfo;
      LPSTR pszOID;
    };
  } CERT_STRONG_SIGN_PARA,*PCERT_STRONG_SIGN_PARA;

  typedef const CERT_STRONG_SIGN_PARA *PCCERT_STRONG_SIGN_PARA;

#define CERT_STRONG_SIGN_SERIALIZED_INFO_CHOICE 1
#define CERT_STRONG_SIGN_OID_INFO_CHOICE 2

#define CERT_STRONG_SIGN_ENABLE_CRL_CHECK 0x1
#define CERT_STRONG_SIGN_ENABLE_OCSP_CHECK 0x2

#define szOID_CERT_STRONG_SIGN_OS_PREFIX "1.3.6.1.4.1.311.72.1."

#define szOID_CERT_STRONG_SIGN_OS_1 "1.3.6.1.4.1.311.72.1.1"
#define szOID_CERT_STRONG_SIGN_OS_CURRENT szOID_CERT_STRONG_SIGN_OS_1

#define CERT_STRONG_SIGN_PARA_OS_1 { sizeof (CERT_STRONG_SIGN_PARA), CERT_STRONG_SIGN_OID_INFO_CHOICE, szOID_CERT_STRONG_SIGN_OS_1 }
#define CERT_STRONG_SIGN_PARA_OS_CURRENT { sizeof (CERT_STRONG_SIGN_PARA), CERT_STRONG_SIGN_OID_INFO_CHOICE, szOID_CERT_STRONG_SIGN_OS_CURRENT }

#define szOID_CERT_STRONG_KEY_OS_PREFIX "1.3.6.1.4.1.311.72.2."
#define szOID_CERT_STRONG_KEY_OS_1 "1.3.6.1.4.1.311.72.2.1"
#define szOID_CERT_STRONG_KEY_OS_CURRENT szOID_CERT_STRONG_KEY_OS_1

#define CERT_STRONG_KEY_PARA_OS_1 { sizeof (CERT_STRONG_SIGN_PARA), CERT_STRONG_SIGN_OID_INFO_CHOICE, szOID_CERT_STRONG_KEY_OS_1 }
#define CERT_STRONG_KEY_PARA_OS_CURRENT { sizeof (CERT_STRONG_SIGN_PARA), CERT_STRONG_SIGN_OID_INFO_CHOICE, szOID_CERT_STRONG_KEY_OS_CURRENT }

  typedef void *HCRYPTMSG;

#define szOID_PKCS_7_DATA "1.2.840.113549.1.7.1"
#define szOID_PKCS_7_SIGNED "1.2.840.113549.1.7.2"
#define szOID_PKCS_7_ENVELOPED "1.2.840.113549.1.7.3"
#define szOID_PKCS_7_SIGNEDANDENVELOPED "1.2.840.113549.1.7.4"
#define szOID_PKCS_7_DIGESTED "1.2.840.113549.1.7.5"
#define szOID_PKCS_7_ENCRYPTED "1.2.840.113549.1.7.6"

#define szOID_PKCS_9_CONTENT_TYPE "1.2.840.113549.1.9.3"
#define szOID_PKCS_9_MESSAGE_DIGEST "1.2.840.113549.1.9.4"

#define CMSG_DATA 1
#define CMSG_SIGNED 2
#define CMSG_ENVELOPED 3
#define CMSG_SIGNED_AND_ENVELOPED 4
#define CMSG_HASHED 5
#define CMSG_ENCRYPTED 6

#define CMSG_ALL_FLAGS (~__MSABI_LONG(0U))
#define CMSG_DATA_FLAG (1 << CMSG_DATA)
#define CMSG_SIGNED_FLAG (1 << CMSG_SIGNED)
#define CMSG_ENVELOPED_FLAG (1 << CMSG_ENVELOPED)
#define CMSG_SIGNED_AND_ENVELOPED_FLAG (1 << CMSG_SIGNED_AND_ENVELOPED)
#define CMSG_HASHED_FLAG (1 << CMSG_HASHED)
#define CMSG_ENCRYPTED_FLAG (1 << CMSG_ENCRYPTED)

  typedef struct _CERT_ISSUER_SERIAL_NUMBER {
    CERT_NAME_BLOB Issuer;
    CRYPT_INTEGER_BLOB SerialNumber;
  } CERT_ISSUER_SERIAL_NUMBER,*PCERT_ISSUER_SERIAL_NUMBER;

  typedef struct _CERT_ID {
    DWORD dwIdChoice;
    __C89_NAMELESS union {
      CERT_ISSUER_SERIAL_NUMBER IssuerSerialNumber;
      CRYPT_HASH_BLOB KeyId;
      CRYPT_HASH_BLOB HashId;
    };
  } CERT_ID,*PCERT_ID;

#define CERT_ID_ISSUER_SERIAL_NUMBER 1
#define CERT_ID_KEY_IDENTIFIER 2
#define CERT_ID_SHA1_HASH 3

  typedef struct _CMSG_SIGNER_ENCODE_INFO {
    DWORD cbSize;
    PCERT_INFO pCertInfo;
    __C89_NAMELESS union {
      HCRYPTPROV hCryptProv;
      NCRYPT_KEY_HANDLE hNCryptKey;
    };
    DWORD dwKeySpec;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
    DWORD cAuthAttr;
    PCRYPT_ATTRIBUTE rgAuthAttr;
    DWORD cUnauthAttr;
    PCRYPT_ATTRIBUTE rgUnauthAttr;
#ifdef CMSG_SIGNER_ENCODE_INFO_HAS_CMS_FIELDS
    CERT_ID SignerId;
    CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;
    void *pvHashEncryptionAuxInfo;
#endif
  } CMSG_SIGNER_ENCODE_INFO,*PCMSG_SIGNER_ENCODE_INFO;

  typedef struct _CMSG_SIGNED_ENCODE_INFO {
    DWORD cbSize;
    DWORD cSigners;
    PCMSG_SIGNER_ENCODE_INFO rgSigners;
    DWORD cCertEncoded;
    PCERT_BLOB rgCertEncoded;
    DWORD cCrlEncoded;
    PCRL_BLOB rgCrlEncoded;
#ifdef CMSG_SIGNED_ENCODE_INFO_HAS_CMS_FIELDS
    DWORD cAttrCertEncoded;
    PCERT_BLOB rgAttrCertEncoded;
#endif
  } CMSG_SIGNED_ENCODE_INFO,*PCMSG_SIGNED_ENCODE_INFO;

  typedef struct _CMSG_RECIPIENT_ENCODE_INFO CMSG_RECIPIENT_ENCODE_INFO,*PCMSG_RECIPIENT_ENCODE_INFO;

  typedef struct _CMSG_ENVELOPED_ENCODE_INFO {
    DWORD cbSize;
    HCRYPTPROV_LEGACY hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    void *pvEncryptionAuxInfo;
    DWORD cRecipients;
    PCERT_INFO *rgpRecipients;
#ifdef CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS
    PCMSG_RECIPIENT_ENCODE_INFO rgCmsRecipients;
    DWORD cCertEncoded;
    PCERT_BLOB rgCertEncoded;
    DWORD cCrlEncoded;
    PCRL_BLOB rgCrlEncoded;
    DWORD cAttrCertEncoded;
    PCERT_BLOB rgAttrCertEncoded;
    DWORD cUnprotectedAttr;
    PCRYPT_ATTRIBUTE rgUnprotectedAttr;
#endif
  } CMSG_ENVELOPED_ENCODE_INFO,*PCMSG_ENVELOPED_ENCODE_INFO;

  typedef struct _CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO {
    DWORD cbSize;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    void *pvKeyEncryptionAuxInfo;
    HCRYPTPROV_LEGACY hCryptProv;
    CRYPT_BIT_BLOB RecipientPublicKey;
    CERT_ID RecipientId;
  } CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO,*PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO;

  typedef struct _CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO {
    DWORD cbSize;
    CRYPT_BIT_BLOB RecipientPublicKey;
    CERT_ID RecipientId;
    FILETIME Date;
    PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
  } CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO,*PCMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO;

  typedef struct _CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO {
    DWORD cbSize;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    void *pvKeyEncryptionAuxInfo;
    CRYPT_ALGORITHM_IDENTIFIER KeyWrapAlgorithm;
    void *pvKeyWrapAuxInfo;
    HCRYPTPROV_LEGACY hCryptProv;
    DWORD dwKeySpec;
    DWORD dwKeyChoice;
    __C89_NAMELESS union {
      PCRYPT_ALGORITHM_IDENTIFIER pEphemeralAlgorithm;
      PCERT_ID pSenderId;
    };
    CRYPT_DATA_BLOB UserKeyingMaterial;
    DWORD cRecipientEncryptedKeys;
    PCMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO *rgpRecipientEncryptedKeys;
  } CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO,*PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO;

#define CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE 1
#define CMSG_KEY_AGREE_STATIC_KEY_CHOICE 2

  typedef struct _CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO {
    DWORD cbSize;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    void *pvKeyEncryptionAuxInfo;
    HCRYPTPROV hCryptProv;
    DWORD dwKeyChoice;
    __C89_NAMELESS union {
      HCRYPTKEY hKeyEncryptionKey;
      void *pvKeyEncryptionKey;
    };
    CRYPT_DATA_BLOB KeyId;
    FILETIME Date;
    PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
  } CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO,*PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO;

#define CMSG_MAIL_LIST_HANDLE_KEY_CHOICE 1

#define CMSG_KEY_TRANS_RECIPIENT 1
#define CMSG_KEY_AGREE_RECIPIENT 2
#define CMSG_MAIL_LIST_RECIPIENT 3

#define CMSG_RC4_NO_SALT_FLAG 0x40000000
#define CMSG_SP3_COMPATIBLE_ENCRYPT_FLAG 0x80000000

  struct _CMSG_RECIPIENT_ENCODE_INFO {
    DWORD dwRecipientChoice;
    __C89_NAMELESS union {
      PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO pKeyTrans;
      PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO pKeyAgree;
      PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO pMailList;
    };
  };

  typedef struct _CMSG_RC2_AUX_INFO {
    DWORD cbSize;
    DWORD dwBitLen;
  } CMSG_RC2_AUX_INFO,*PCMSG_RC2_AUX_INFO;

  typedef struct _CMSG_SP3_COMPATIBLE_AUX_INFO {
    DWORD cbSize;
    DWORD dwFlags;
  } CMSG_SP3_COMPATIBLE_AUX_INFO,*PCMSG_SP3_COMPATIBLE_AUX_INFO;

  typedef struct _CMSG_RC4_AUX_INFO {
    DWORD cbSize;
    DWORD dwBitLen;
  } CMSG_RC4_AUX_INFO,*PCMSG_RC4_AUX_INFO;

  typedef struct _CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO {
    DWORD cbSize;
    CMSG_SIGNED_ENCODE_INFO SignedInfo;
    CMSG_ENVELOPED_ENCODE_INFO EnvelopedInfo;
  } CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO,*PCMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO;

  typedef struct _CMSG_HASHED_ENCODE_INFO {
    DWORD cbSize;
    HCRYPTPROV_LEGACY hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
  } CMSG_HASHED_ENCODE_INFO,*PCMSG_HASHED_ENCODE_INFO;

  typedef struct _CMSG_ENCRYPTED_ENCODE_INFO {
    DWORD cbSize;
    CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    void *pvEncryptionAuxInfo;
  } CMSG_ENCRYPTED_ENCODE_INFO,*PCMSG_ENCRYPTED_ENCODE_INFO;

  typedef WINBOOL (WINAPI *PFN_CMSG_STREAM_OUTPUT) (const void *pvArg, BYTE *pbData, DWORD cbData, WINBOOL fFinal);

#define CMSG_INDEFINITE_LENGTH (0xffffffff)

  typedef struct _CMSG_STREAM_INFO {
    DWORD cbContent;
    PFN_CMSG_STREAM_OUTPUT pfnStreamOutput;
    void *pvArg;
  } CMSG_STREAM_INFO,*PCMSG_STREAM_INFO;

#define CMSG_BARE_CONTENT_FLAG 0x1
#define CMSG_LENGTH_ONLY_FLAG 0x2
#define CMSG_DETACHED_FLAG 0x4
#define CMSG_AUTHENTICATED_ATTRIBUTES_FLAG 0x8
#define CMSG_CONTENTS_OCTETS_FLAG 0x10
#define CMSG_MAX_LENGTH_FLAG 0x20
#define CMSG_CMS_ENCAPSULATED_CONTENT_FLAG 0x40
#define CMSG_SIGNED_DATA_NO_SIGN_FLAG 0x80
#define CMSG_CRYPT_RELEASE_CONTEXT_FLAG 0x8000

  WINIMPM HCRYPTMSG WINAPI CryptMsgOpenToEncode (DWORD dwMsgEncodingType, DWORD dwFlags, DWORD dwMsgType, void const *pvMsgEncodeInfo, LPSTR pszInnerContentObjID, PCMSG_STREAM_INFO pStreamInfo);
  WINIMPM DWORD WINAPI CryptMsgCalculateEncodedLength (DWORD dwMsgEncodingType, DWORD dwFlags, DWORD dwMsgType, void const *pvMsgEncodeInfo, LPSTR pszInnerContentObjID, DWORD cbData);
  WINIMPM HCRYPTMSG WINAPI CryptMsgOpenToDecode (DWORD dwMsgEncodingType, DWORD dwFlags, DWORD dwMsgType, HCRYPTPROV_LEGACY hCryptProv, PCERT_INFO pRecipientInfo, PCMSG_STREAM_INFO pStreamInfo);
  WINIMPM HCRYPTMSG WINAPI CryptMsgDuplicate (HCRYPTMSG hCryptMsg);
  WINIMPM WINBOOL WINAPI CryptMsgClose (HCRYPTMSG hCryptMsg);
  WINIMPM WINBOOL WINAPI CryptMsgUpdate (HCRYPTMSG hCryptMsg, const BYTE *pbData, DWORD cbData, WINBOOL fFinal);
  WINIMPM WINBOOL WINAPI CryptMsgGetParam (HCRYPTMSG hCryptMsg, DWORD dwParamType, DWORD dwIndex, void *pvData, DWORD *pcbData);

#define CMSG_TYPE_PARAM 1
#define CMSG_CONTENT_PARAM 2
#define CMSG_BARE_CONTENT_PARAM 3
#define CMSG_INNER_CONTENT_TYPE_PARAM 4
#define CMSG_SIGNER_COUNT_PARAM 5
#define CMSG_SIGNER_INFO_PARAM 6
#define CMSG_SIGNER_CERT_INFO_PARAM 7
#define CMSG_SIGNER_HASH_ALGORITHM_PARAM 8
#define CMSG_SIGNER_AUTH_ATTR_PARAM 9
#define CMSG_SIGNER_UNAUTH_ATTR_PARAM 10
#define CMSG_CERT_COUNT_PARAM 11
#define CMSG_CERT_PARAM 12
#define CMSG_CRL_COUNT_PARAM 13
#define CMSG_CRL_PARAM 14
#define CMSG_ENVELOPE_ALGORITHM_PARAM 15
#define CMSG_RECIPIENT_COUNT_PARAM 17
#define CMSG_RECIPIENT_INDEX_PARAM 18
#define CMSG_RECIPIENT_INFO_PARAM 19
#define CMSG_HASH_ALGORITHM_PARAM 20
#define CMSG_HASH_DATA_PARAM 21
#define CMSG_COMPUTED_HASH_PARAM 22
#define CMSG_ENCRYPT_PARAM 26
#define CMSG_ENCRYPTED_DIGEST 27
#define CMSG_ENCODED_SIGNER 28
#define CMSG_ENCODED_MESSAGE 29
#define CMSG_VERSION_PARAM 30
#define CMSG_ATTR_CERT_COUNT_PARAM 31
#define CMSG_ATTR_CERT_PARAM 32
#define CMSG_CMS_RECIPIENT_COUNT_PARAM 33
#define CMSG_CMS_RECIPIENT_INDEX_PARAM 34
#define CMSG_CMS_RECIPIENT_ENCRYPTED_KEY_INDEX_PARAM 35
#define CMSG_CMS_RECIPIENT_INFO_PARAM 36
#define CMSG_UNPROTECTED_ATTR_PARAM 37
#define CMSG_SIGNER_CERT_ID_PARAM 38
#define CMSG_CMS_SIGNER_INFO_PARAM 39

  typedef struct _CMSG_SIGNER_INFO {
    DWORD dwVersion;
    CERT_NAME_BLOB Issuer;
    CRYPT_INTEGER_BLOB SerialNumber;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;
    CRYPT_DATA_BLOB EncryptedHash;
    CRYPT_ATTRIBUTES AuthAttrs;
    CRYPT_ATTRIBUTES UnauthAttrs;
  } CMSG_SIGNER_INFO,*PCMSG_SIGNER_INFO;

  typedef struct _CMSG_CMS_SIGNER_INFO {
    DWORD dwVersion;
    CERT_ID SignerId;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;
    CRYPT_DATA_BLOB EncryptedHash;
    CRYPT_ATTRIBUTES AuthAttrs;
    CRYPT_ATTRIBUTES UnauthAttrs;
  } CMSG_CMS_SIGNER_INFO,*PCMSG_CMS_SIGNER_INFO;

  typedef CRYPT_ATTRIBUTES CMSG_ATTR;
  typedef CRYPT_ATTRIBUTES *PCMSG_ATTR;

#define CMSG_SIGNED_DATA_V1 1
#define CMSG_SIGNED_DATA_V3 3
#define CMSG_SIGNED_DATA_PKCS_1_5_VERSION CMSG_SIGNED_DATA_V1
#define CMSG_SIGNED_DATA_CMS_VERSION CMSG_SIGNED_DATA_V3

#define CMSG_SIGNER_INFO_V1 1
#define CMSG_SIGNER_INFO_V3 3
#define CMSG_SIGNER_INFO_PKCS_1_5_VERSION CMSG_SIGNER_INFO_V1
#define CMSG_SIGNER_INFO_CMS_VERSION CMSG_SIGNER_INFO_V3

#define CMSG_HASHED_DATA_V0 0
#define CMSG_HASHED_DATA_V2 2
#define CMSG_HASHED_DATA_PKCS_1_5_VERSION CMSG_HASHED_DATA_V0
#define CMSG_HASHED_DATA_CMS_VERSION CMSG_HASHED_DATA_V2

#define CMSG_ENVELOPED_DATA_V0 0
#define CMSG_ENVELOPED_DATA_V2 2
#define CMSG_ENVELOPED_DATA_PKCS_1_5_VERSION CMSG_ENVELOPED_DATA_V0
#define CMSG_ENVELOPED_DATA_CMS_VERSION CMSG_ENVELOPED_DATA_V2

  typedef struct _CMSG_KEY_TRANS_RECIPIENT_INFO {
    DWORD dwVersion;
    CERT_ID RecipientId;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    CRYPT_DATA_BLOB EncryptedKey;
  } CMSG_KEY_TRANS_RECIPIENT_INFO,*PCMSG_KEY_TRANS_RECIPIENT_INFO;

  typedef struct _CMSG_RECIPIENT_ENCRYPTED_KEY_INFO {
    CERT_ID RecipientId;
    CRYPT_DATA_BLOB EncryptedKey;
    FILETIME Date;
    PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
  } CMSG_RECIPIENT_ENCRYPTED_KEY_INFO,*PCMSG_RECIPIENT_ENCRYPTED_KEY_INFO;

  typedef struct _CMSG_KEY_AGREE_RECIPIENT_INFO {
    DWORD dwVersion;
    DWORD dwOriginatorChoice;
    __C89_NAMELESS union {
      CERT_ID OriginatorCertId;
      CERT_PUBLIC_KEY_INFO OriginatorPublicKeyInfo;
    };
    CRYPT_DATA_BLOB UserKeyingMaterial;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    DWORD cRecipientEncryptedKeys;
    PCMSG_RECIPIENT_ENCRYPTED_KEY_INFO *rgpRecipientEncryptedKeys;
  } CMSG_KEY_AGREE_RECIPIENT_INFO,*PCMSG_KEY_AGREE_RECIPIENT_INFO;

#define CMSG_KEY_AGREE_ORIGINATOR_CERT 1
#define CMSG_KEY_AGREE_ORIGINATOR_PUBLIC_KEY 2

  typedef struct _CMSG_MAIL_LIST_RECIPIENT_INFO {
    DWORD dwVersion;
    CRYPT_DATA_BLOB KeyId;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    CRYPT_DATA_BLOB EncryptedKey;
    FILETIME Date;
    PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
  } CMSG_MAIL_LIST_RECIPIENT_INFO,*PCMSG_MAIL_LIST_RECIPIENT_INFO;

  typedef struct _CMSG_CMS_RECIPIENT_INFO {
    DWORD dwRecipientChoice;
    __C89_NAMELESS union {
      PCMSG_KEY_TRANS_RECIPIENT_INFO pKeyTrans;
      PCMSG_KEY_AGREE_RECIPIENT_INFO pKeyAgree;
      PCMSG_MAIL_LIST_RECIPIENT_INFO pMailList;
    };
  } CMSG_CMS_RECIPIENT_INFO,*PCMSG_CMS_RECIPIENT_INFO;

#define CMSG_ENVELOPED_RECIPIENT_V0 0
#define CMSG_ENVELOPED_RECIPIENT_V2 2
#define CMSG_ENVELOPED_RECIPIENT_V3 3
#define CMSG_ENVELOPED_RECIPIENT_V4 4
#define CMSG_KEY_TRANS_PKCS_1_5_VERSION CMSG_ENVELOPED_RECIPIENT_V0
#define CMSG_KEY_TRANS_CMS_VERSION CMSG_ENVELOPED_RECIPIENT_V2
#define CMSG_KEY_AGREE_VERSION CMSG_ENVELOPED_RECIPIENT_V3
#define CMSG_MAIL_LIST_VERSION CMSG_ENVELOPED_RECIPIENT_V4

  WINIMPM WINBOOL WINAPI CryptMsgControl (HCRYPTMSG hCryptMsg, DWORD dwFlags, DWORD dwCtrlType, void const *pvCtrlPara);

#define CMSG_CTRL_VERIFY_SIGNATURE 1
#define CMSG_CTRL_DECRYPT 2
#define CMSG_CTRL_VERIFY_HASH 5
#define CMSG_CTRL_ADD_SIGNER 6
#define CMSG_CTRL_DEL_SIGNER 7
#define CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR 8
#define CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR 9
#define CMSG_CTRL_ADD_CERT 10
#define CMSG_CTRL_DEL_CERT 11
#define CMSG_CTRL_ADD_CRL 12
#define CMSG_CTRL_DEL_CRL 13
#define CMSG_CTRL_ADD_ATTR_CERT 14
#define CMSG_CTRL_DEL_ATTR_CERT 15
#define CMSG_CTRL_KEY_TRANS_DECRYPT 16
#define CMSG_CTRL_KEY_AGREE_DECRYPT 17
#define CMSG_CTRL_MAIL_LIST_DECRYPT 18
#define CMSG_CTRL_VERIFY_SIGNATURE_EX 19
#define CMSG_CTRL_ADD_CMS_SIGNER_INFO 20
#define CMSG_CTRL_ENABLE_STRONG_SIGNATURE 21

  typedef struct _CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA {
    DWORD cbSize;
    HCRYPTPROV_LEGACY hCryptProv;
    DWORD dwSignerIndex;
    DWORD dwSignerType;
    void *pvSigner;
  } CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA,*PCMSG_CTRL_VERIFY_SIGNATURE_EX_PARA;

#define CMSG_VERIFY_SIGNER_PUBKEY 1
#define CMSG_VERIFY_SIGNER_CERT 2
#define CMSG_VERIFY_SIGNER_CHAIN 3
#define CMSG_VERIFY_SIGNER_NULL 4

  typedef struct _CMSG_CTRL_DECRYPT_PARA {
    DWORD cbSize;
    __C89_NAMELESS union {
      HCRYPTPROV hCryptProv;
      NCRYPT_KEY_HANDLE hNCryptKey;
    };
    DWORD dwKeySpec;
    DWORD dwRecipientIndex;
  } CMSG_CTRL_DECRYPT_PARA,*PCMSG_CTRL_DECRYPT_PARA;

  typedef struct _CMSG_CTRL_KEY_TRANS_DECRYPT_PARA {
    DWORD cbSize;
    __C89_NAMELESS union {
      HCRYPTPROV hCryptProv;
      NCRYPT_KEY_HANDLE hNCryptKey;
    };
    DWORD dwKeySpec;
    PCMSG_KEY_TRANS_RECIPIENT_INFO pKeyTrans;
    DWORD dwRecipientIndex;
  } CMSG_CTRL_KEY_TRANS_DECRYPT_PARA,*PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA;

  typedef struct _CMSG_CTRL_KEY_AGREE_DECRYPT_PARA {
    DWORD cbSize;
    __C89_NAMELESS union {
      HCRYPTPROV hCryptProv;
      NCRYPT_KEY_HANDLE hNCryptKey;
    };
    DWORD dwKeySpec;
    PCMSG_KEY_AGREE_RECIPIENT_INFO pKeyAgree;
    DWORD dwRecipientIndex;
    DWORD dwRecipientEncryptedKeyIndex;
    CRYPT_BIT_BLOB OriginatorPublicKey;
  } CMSG_CTRL_KEY_AGREE_DECRYPT_PARA,*PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA;

  typedef struct _CMSG_CTRL_MAIL_LIST_DECRYPT_PARA {
    DWORD cbSize;
    HCRYPTPROV hCryptProv;
    PCMSG_MAIL_LIST_RECIPIENT_INFO pMailList;
    DWORD dwRecipientIndex;
    DWORD dwKeyChoice;
    __C89_NAMELESS union {
      HCRYPTKEY hKeyEncryptionKey;
      void *pvKeyEncryptionKey;
    };
  } CMSG_CTRL_MAIL_LIST_DECRYPT_PARA,*PCMSG_CTRL_MAIL_LIST_DECRYPT_PARA;

  typedef struct _CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA {
    DWORD cbSize;
    DWORD dwSignerIndex;
    CRYPT_DATA_BLOB blob;
  } CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA,*PCMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA;

  typedef struct _CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA {
    DWORD cbSize;
    DWORD dwSignerIndex;
    DWORD dwUnauthAttrIndex;
  } CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA,*PCMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA;

#define CMSG_VERIFY_COUNTER_SIGN_ENABLE_STRONG_FLAG 0x1

  WINBOOL WINAPI CryptMsgVerifyCountersignatureEncoded (HCRYPTPROV_LEGACY hCryptProv, DWORD dwEncodingType, PBYTE pbSignerInfo, DWORD cbSignerInfo, PBYTE pbSignerInfoCountersignature, DWORD cbSignerInfoCountersignature, PCERT_INFO pciCountersigner);
  WINBOOL WINAPI CryptMsgVerifyCountersignatureEncodedEx (HCRYPTPROV_LEGACY hCryptProv, DWORD dwEncodingType, PBYTE pbSignerInfo, DWORD cbSignerInfo, PBYTE pbSignerInfoCountersignature, DWORD cbSignerInfoCountersignature, DWORD dwSignerType, void *pvSigner, DWORD dwFlags, void *pvExtra);
  WINBOOL WINAPI CryptMsgCountersign (HCRYPTMSG hCryptMsg, DWORD dwIndex, DWORD cCountersigners, PCMSG_SIGNER_ENCODE_INFO rgCountersigners);
  WINBOOL WINAPI CryptMsgCountersignEncoded (DWORD dwEncodingType, PBYTE pbSignerInfo, DWORD cbSignerInfo, DWORD cCountersigners, PCMSG_SIGNER_ENCODE_INFO rgCountersigners, PBYTE pbCountersignature, PDWORD pcbCountersignature);

  typedef void *(WINAPI *PFN_CMSG_ALLOC) (size_t cb);
  typedef void (WINAPI *PFN_CMSG_FREE) (void *pv);

#define CMSG_OID_GEN_ENCRYPT_KEY_FUNC "CryptMsgDllGenEncryptKey"
#define CMSG_OID_EXPORT_ENCRYPT_KEY_FUNC "CryptMsgDllExportEncryptKey"
#define CMSG_OID_IMPORT_ENCRYPT_KEY_FUNC "CryptMsgDllImportEncryptKey"

  typedef WINBOOL (WINAPI *PFN_CMSG_GEN_ENCRYPT_KEY) (HCRYPTPROV *phCryptProv, PCRYPT_ALGORITHM_IDENTIFIER paiEncrypt, PVOID pvEncryptAuxInfo, PCERT_PUBLIC_KEY_INFO pPublicKeyInfo, PFN_CMSG_ALLOC pfnAlloc, HCRYPTKEY *phEncryptKey, PBYTE *ppbEncryptParameters, PDWORD pcbEncryptParameters);
  typedef WINBOOL (WINAPI *PFN_CMSG_EXPORT_ENCRYPT_KEY) (HCRYPTPROV hCryptProv, HCRYPTKEY hEncryptKey, PCERT_PUBLIC_KEY_INFO pPublicKeyInfo, PBYTE pbData, PDWORD pcbData);
  typedef WINBOOL (WINAPI *PFN_CMSG_IMPORT_ENCRYPT_KEY) (HCRYPTPROV hCryptProv, DWORD dwKeySpec, PCRYPT_ALGORITHM_IDENTIFIER paiEncrypt, PCRYPT_ALGORITHM_IDENTIFIER paiPubKey, PBYTE pbEncodedKey, DWORD cbEncodedKey, HCRYPTKEY *phEncryptKey);

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)

#define CMSG_DEFAULT_INSTALLABLE_FUNC_OID ((LPCSTR) 1)

  typedef struct _CMSG_CONTENT_ENCRYPT_INFO {
    DWORD cbSize;
    HCRYPTPROV_LEGACY hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    void *pvEncryptionAuxInfo;
    DWORD cRecipients;
    PCMSG_RECIPIENT_ENCODE_INFO rgCmsRecipients;
    PFN_CMSG_ALLOC pfnAlloc;
    PFN_CMSG_FREE pfnFree;
    DWORD dwEncryptFlags;
    __C89_NAMELESS union {
      HCRYPTKEY hContentEncryptKey;
      BCRYPT_KEY_HANDLE hCNGContentEncryptKey;
    };
    DWORD dwFlags;
    WINBOOL fCNG;
    BYTE *pbCNGContentEncryptKeyObject;
    BYTE *pbContentEncryptKey;
    DWORD cbContentEncryptKey;
  } CMSG_CONTENT_ENCRYPT_INFO,*PCMSG_CONTENT_ENCRYPT_INFO;

#define CMSG_CONTENT_ENCRYPT_PAD_ENCODED_LEN_FLAG 0x1

#define CMSG_CONTENT_ENCRYPT_FREE_PARA_FLAG 0x1
#define CMSG_CONTENT_ENCRYPT_FREE_OBJID_FLAG 0x2
#define CMSG_CONTENT_ENCRYPT_RELEASE_CONTEXT_FLAG 0x8000

#define CMSG_OID_GEN_CONTENT_ENCRYPT_KEY_FUNC "CryptMsgDllGenContentEncryptKey"
#define CMSG_OID_CAPI1_GEN_CONTENT_ENCRYPT_KEY_FUNC CMSG_OID_GEN_CONTENT_ENCRYPT_KEY_FUNC
#define CMSG_OID_CNG_GEN_CONTENT_ENCRYPT_KEY_FUNC "CryptMsgDllCNGGenContentEncryptKey"

  typedef WINBOOL (WINAPI *PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY) (PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo, DWORD dwFlags, void *pvReserved);

  typedef struct _CMSG_KEY_TRANS_ENCRYPT_INFO {
    DWORD cbSize;
    DWORD dwRecipientIndex;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    CRYPT_DATA_BLOB EncryptedKey;
    DWORD dwFlags;
  } CMSG_KEY_TRANS_ENCRYPT_INFO,*PCMSG_KEY_TRANS_ENCRYPT_INFO;

#define CMSG_KEY_TRANS_ENCRYPT_FREE_PARA_FLAG 0x1
#define CMSG_KEY_TRANS_ENCRYPT_FREE_OBJID_FLAG 0x2

#define CMSG_OID_EXPORT_KEY_TRANS_FUNC "CryptMsgDllExportKeyTrans"
#define CMSG_OID_CAPI1_EXPORT_KEY_TRANS_FUNC CMSG_OID_EXPORT_KEY_TRANS_FUNC
#define CMSG_OID_CNG_EXPORT_KEY_TRANS_FUNC "CryptMsgDllCNGExportKeyTrans"

  typedef WINBOOL (WINAPI *PFN_CMSG_EXPORT_KEY_TRANS) (PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo, PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO pKeyTransEncodeInfo, PCMSG_KEY_TRANS_ENCRYPT_INFO pKeyTransEncryptInfo, DWORD dwFlags, void *pvReserved);

  typedef struct _CMSG_KEY_AGREE_KEY_ENCRYPT_INFO {
    DWORD cbSize;
    CRYPT_DATA_BLOB EncryptedKey;
  } CMSG_KEY_AGREE_KEY_ENCRYPT_INFO,*PCMSG_KEY_AGREE_KEY_ENCRYPT_INFO;

  typedef struct _CMSG_KEY_AGREE_ENCRYPT_INFO {
    DWORD cbSize;
    DWORD dwRecipientIndex;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    CRYPT_DATA_BLOB UserKeyingMaterial;
    DWORD dwOriginatorChoice;
    __C89_NAMELESS union {
      CERT_ID OriginatorCertId;
      CERT_PUBLIC_KEY_INFO OriginatorPublicKeyInfo;
    };
    DWORD cKeyAgreeKeyEncryptInfo;
    PCMSG_KEY_AGREE_KEY_ENCRYPT_INFO *rgpKeyAgreeKeyEncryptInfo;
    DWORD dwFlags;
  } CMSG_KEY_AGREE_ENCRYPT_INFO,*PCMSG_KEY_AGREE_ENCRYPT_INFO;

#define CMSG_KEY_AGREE_ENCRYPT_FREE_PARA_FLAG 0x1
#define CMSG_KEY_AGREE_ENCRYPT_FREE_MATERIAL_FLAG 0x2
#define CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_ALG_FLAG 0x4
#define CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_PARA_FLAG 0x8
#define CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_BITS_FLAG 0x10
#define CMSG_KEY_AGREE_ENCRYPT_FREE_OBJID_FLAG 0x20

#define CMSG_OID_EXPORT_KEY_AGREE_FUNC "CryptMsgDllExportKeyAgree"
#define CMSG_OID_CAPI1_EXPORT_KEY_AGREE_FUNC CMSG_OID_EXPORT_KEY_AGREE_FUNC
#define CMSG_OID_CNG_EXPORT_KEY_AGREE_FUNC "CryptMsgDllCNGExportKeyAgree"

  typedef WINBOOL (WINAPI *PFN_CMSG_EXPORT_KEY_AGREE) (PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo, PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO pKeyAgreeEncodeInfo, PCMSG_KEY_AGREE_ENCRYPT_INFO pKeyAgreeEncryptInfo, DWORD dwFlags, void *pvReserved);

  typedef struct _CMSG_MAIL_LIST_ENCRYPT_INFO {
    DWORD cbSize;
    DWORD dwRecipientIndex;
    CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
    CRYPT_DATA_BLOB EncryptedKey;
    DWORD dwFlags;
  } CMSG_MAIL_LIST_ENCRYPT_INFO,*PCMSG_MAIL_LIST_ENCRYPT_INFO;

#define CMSG_MAIL_LIST_ENCRYPT_FREE_PARA_FLAG 0x1
#define CMSG_MAIL_LIST_ENCRYPT_FREE_OBJID_FLAG 0x2

#define CMSG_OID_EXPORT_MAIL_LIST_FUNC "CryptMsgDllExportMailList"
#define CMSG_OID_CAPI1_EXPORT_MAIL_LIST_FUNC CMSG_OID_EXPORT_MAIL_LIST_FUNC
#define CMSG_OID_IMPORT_KEY_TRANS_FUNC "CryptMsgDllImportKeyTrans"
#define CMSG_OID_CAPI1_IMPORT_KEY_TRANS_FUNC CMSG_OID_IMPORT_KEY_TRANS_FUNC
#define CMSG_OID_IMPORT_KEY_AGREE_FUNC "CryptMsgDllImportKeyAgree"
#define CMSG_OID_CAPI1_IMPORT_KEY_AGREE_FUNC CMSG_OID_IMPORT_KEY_AGREE_FUNC
#define CMSG_OID_IMPORT_MAIL_LIST_FUNC "CryptMsgDllImportMailList"
#define CMSG_OID_CAPI1_IMPORT_MAIL_LIST_FUNC CMSG_OID_IMPORT_MAIL_LIST_FUNC

  typedef WINBOOL (WINAPI *PFN_CMSG_EXPORT_MAIL_LIST) (PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo, PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO pMailListEncodeInfo, PCMSG_MAIL_LIST_ENCRYPT_INFO pMailListEncryptInfo, DWORD dwFlags, void *pvReserved);
  typedef WINBOOL (WINAPI *PFN_CMSG_IMPORT_KEY_TRANS) (PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm, PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA pKeyTransDecryptPara, DWORD dwFlags, void *pvReserved, HCRYPTKEY *phContentEncryptKey);
  typedef WINBOOL (WINAPI *PFN_CMSG_IMPORT_KEY_AGREE) (PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm, PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA pKeyAgreeDecryptPara, DWORD dwFlags, void *pvReserved, HCRYPTKEY *phContentEncryptKey);
  typedef WINBOOL (WINAPI *PFN_CMSG_IMPORT_MAIL_LIST) (PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm, PCMSG_CTRL_MAIL_LIST_DECRYPT_PARA pMailListDecryptPara, DWORD dwFlags, void *pvReserved, HCRYPTKEY *phContentEncryptKey);

  typedef struct _CMSG_CNG_CONTENT_DECRYPT_INFO {
    DWORD cbSize;
    CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    PFN_CMSG_ALLOC pfnAlloc;
    PFN_CMSG_FREE pfnFree;
    NCRYPT_KEY_HANDLE hNCryptKey;
    BYTE *pbContentEncryptKey;
    DWORD cbContentEncryptKey;
    BCRYPT_KEY_HANDLE hCNGContentEncryptKey;
    BYTE *pbCNGContentEncryptKeyObject;
  } CMSG_CNG_CONTENT_DECRYPT_INFO,*PCMSG_CNG_CONTENT_DECRYPT_INFO;

#define CMSG_OID_CNG_IMPORT_KEY_TRANS_FUNC "CryptMsgDllCNGImportKeyTrans"
#define CMSG_OID_CNG_IMPORT_KEY_AGREE_FUNC "CryptMsgDllCNGImportKeyAgree"
#define CMSG_OID_CNG_IMPORT_CONTENT_ENCRYPT_KEY_FUNC "CryptMsgDllCNGImportContentEncryptKey"

  typedef WINBOOL (WINAPI *PFN_CMSG_CNG_IMPORT_KEY_TRANS) (PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo, PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA pKeyTransDecryptPara, DWORD dwFlags, void *pvReserved);
  typedef WINBOOL (WINAPI *PFN_CMSG_CNG_IMPORT_KEY_AGREE) (PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo, PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA pKeyAgreeDecryptPara, DWORD dwFlags, void *pvReserved);
  typedef WINBOOL (WINAPI *PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY) (PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo, DWORD dwFlags, void *pvReserved);

#endif
#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_APP)
  typedef void *HCERTSTORE;

  typedef struct _CERT_CONTEXT {
    DWORD dwCertEncodingType;
    BYTE *pbCertEncoded;
    DWORD cbCertEncoded;
    PCERT_INFO pCertInfo;
    HCERTSTORE hCertStore;
  } CERT_CONTEXT,*PCERT_CONTEXT;

  typedef const CERT_CONTEXT *PCCERT_CONTEXT;
#endif

  typedef struct _CRL_CONTEXT {
    DWORD dwCertEncodingType;
    BYTE *pbCrlEncoded;
    DWORD cbCrlEncoded;
    PCRL_INFO pCrlInfo;
    HCERTSTORE hCertStore;
  } CRL_CONTEXT,*PCRL_CONTEXT;

  typedef const CRL_CONTEXT *PCCRL_CONTEXT;

  typedef struct _CTL_CONTEXT {
    DWORD dwMsgAndCertEncodingType;
    BYTE *pbCtlEncoded;
    DWORD cbCtlEncoded;
    PCTL_INFO pCtlInfo;
    HCERTSTORE hCertStore;
    HCRYPTMSG hCryptMsg;
    BYTE *pbCtlContent;
    DWORD cbCtlContent;
  } CTL_CONTEXT,*PCTL_CONTEXT;

  typedef const CTL_CONTEXT *PCCTL_CONTEXT;

#define CERT_KEY_PROV_HANDLE_PROP_ID 1
#define CERT_KEY_PROV_INFO_PROP_ID 2
#define CERT_SHA1_HASH_PROP_ID 3
#define CERT_MD5_HASH_PROP_ID 4
#define CERT_HASH_PROP_ID CERT_SHA1_HASH_PROP_ID
#define CERT_KEY_CONTEXT_PROP_ID 5
#define CERT_KEY_SPEC_PROP_ID 6
#define CERT_IE30_RESERVED_PROP_ID 7
#define CERT_PUBKEY_HASH_RESERVED_PROP_ID 8
#define CERT_ENHKEY_USAGE_PROP_ID 9
#define CERT_CTL_USAGE_PROP_ID CERT_ENHKEY_USAGE_PROP_ID
#define CERT_NEXT_UPDATE_LOCATION_PROP_ID 10
#define CERT_FRIENDLY_NAME_PROP_ID 11
#define CERT_PVK_FILE_PROP_ID 12
#define CERT_DESCRIPTION_PROP_ID 13
#define CERT_ACCESS_STATE_PROP_ID 14
#define CERT_SIGNATURE_HASH_PROP_ID 15
#define CERT_SMART_CARD_DATA_PROP_ID 16
#define CERT_EFS_PROP_ID 17
#define CERT_FORTEZZA_DATA_PROP_ID 18
#define CERT_ARCHIVED_PROP_ID 19
#define CERT_KEY_IDENTIFIER_PROP_ID 20
#define CERT_AUTO_ENROLL_PROP_ID 21
#define CERT_PUBKEY_ALG_PARA_PROP_ID 22
#define CERT_CROSS_CERT_DIST_POINTS_PROP_ID 23
#define CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID 24
#define CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID 25
#define CERT_ENROLLMENT_PROP_ID 26
#define CERT_DATE_STAMP_PROP_ID 27
#define CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID 28
#define CERT_SUBJECT_NAME_MD5_HASH_PROP_ID 29
#define CERT_EXTENDED_ERROR_INFO_PROP_ID 30
#define CERT_RENEWAL_PROP_ID 64
#define CERT_ARCHIVED_KEY_HASH_PROP_ID 65
#define CERT_AUTO_ENROLL_RETRY_PROP_ID 66
#define CERT_AIA_URL_RETRIEVED_PROP_ID 67
#define CERT_AUTHORITY_INFO_ACCESS_PROP_ID 68
#define CERT_BACKED_UP_PROP_ID 69
#define CERT_OCSP_RESPONSE_PROP_ID 70
#define CERT_REQUEST_ORIGINATOR_PROP_ID 71
#define CERT_SOURCE_LOCATION_PROP_ID 72
#define CERT_SOURCE_URL_PROP_ID 73
#define CERT_NEW_KEY_PROP_ID 74
#define CERT_OCSP_CACHE_PREFIX_PROP_ID 75
#define CERT_SMART_CARD_ROOT_INFO_PROP_ID 76
#define CERT_NO_AUTO_EXPIRE_CHECK_PROP_ID 77
#define CERT_NCRYPT_KEY_HANDLE_PROP_ID 78
#define CERT_HCRYPTPROV_OR_NCRYPT_KEY_HANDLE_PROP_ID 79
#define CERT_SUBJECT_INFO_ACCESS_PROP_ID 80
#define CERT_CA_OCSP_AUTHORITY_INFO_ACCESS_PROP_ID 81
#define CERT_CA_DISABLE_CRL_PROP_ID 82
#define CERT_ROOT_PROGRAM_CERT_POLICIES_PROP_ID 83
#define CERT_ROOT_PROGRAM_NAME_CONSTRAINTS_PROP_ID 84
#define CERT_SUBJECT_OCSP_AUTHORITY_INFO_ACCESS_PROP_ID 85
#define CERT_SUBJECT_DISABLE_CRL_PROP_ID 86
#define CERT_CEP_PROP_ID 87
#define CERT_SIGN_HASH_CNG_ALG_PROP_ID 89
#define CERT_SCARD_PIN_ID_PROP_ID 90
#define CERT_SCARD_PIN_INFO_PROP_ID 91
#define CERT_SUBJECT_PUB_KEY_BIT_LENGTH_PROP_ID 92
#define CERT_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID 93
#define CERT_ISSUER_PUB_KEY_BIT_LENGTH_PROP_ID 94
#define CERT_ISSUER_CHAIN_SIGN_HASH_CNG_ALG_PROP_ID 95
#define CERT_ISSUER_CHAIN_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID 96
#define CERT_NO_EXPIRE_NOTIFICATION_PROP_ID 97
#define CERT_AUTH_ROOT_SHA256_HASH_PROP_ID 98
#define CERT_NCRYPT_KEY_HANDLE_TRANSFER_PROP_ID 99
#define CERT_HCRYPTPROV_TRANSFER_PROP_ID 100
#define CERT_SMART_CARD_READER_PROP_ID 101
#define CERT_SEND_AS_TRUSTED_ISSUER_PROP_ID 102
#define CERT_KEY_REPAIR_ATTEMPTED_PROP_ID 103
#define CERT_DISALLOWED_FILETIME_PROP_ID 104
#define CERT_ROOT_PROGRAM_CHAIN_POLICIES_PROP_ID 105
#define CERT_SMART_CARD_READER_NON_REMOVABLE_PROP_ID 106

#define CERT_SHA256_HASH_PROP_ID 107

#define CERT_SCEP_SERVER_CERTS_PROP_ID 108
#define CERT_SCEP_RA_SIGNATURE_CERT_PROP_ID 109
#define CERT_SCEP_RA_ENCRYPTION_CERT_PROP_ID 110
#define CERT_SCEP_CA_CERT_PROP_ID 111
#define CERT_SCEP_SIGNER_CERT_PROP_ID 112
#define CERT_SCEP_NONCE_PROP_ID 113

#define CERT_SCEP_ENCRYPT_HASH_CNG_ALG_PROP_ID 114
#define CERT_SCEP_FLAGS_PROP_ID 115
#define CERT_SCEP_GUID_PROP_ID 116
#define CERT_SERIALIZABLE_KEY_CONTEXT_PROP_ID 117

#define CERT_ISOLATED_KEY_PROP_ID 118

#define CERT_SERIAL_CHAIN_PROP_ID 119
#define CERT_KEY_CLASSIFICATION_PROP_ID 120

#define CERT_OCSP_MUST_STAPLE_PROP_ID 121

#define CERT_DISALLOWED_ENHKEY_USAGE_PROP_ID 122
#define CERT_NONCOMPLIANT_ROOT_URL_PROP_ID 123

#define CERT_PIN_SHA256_HASH_PROP_ID 124
#define CERT_CLR_DELETE_KEY_PROP_ID 125
#define CERT_NOT_BEFORE_FILETIME_PROP_ID 126
#define CERT_NOT_BEFORE_ENHKEY_USAGE_PROP_ID 127

#define CERT_FIRST_RESERVED_PROP_ID 107
#define CERT_LAST_RESERVED_PROP_ID 0x00007fff
#define CERT_FIRST_USER_PROP_ID 0x8000
#define CERT_LAST_USER_PROP_ID 0x0000ffff

#if defined(__cplusplus) && __cplusplus >= 201103L && !defined(SORTPP_PASS)
#define WINCRYPT_DWORD_CPP_ONLY : DWORD
#else
#define WINCRYPT_DWORD_CPP_ONLY
#endif

  typedef enum CertKeyType WINCRYPT_DWORD_CPP_ONLY {
    KeyTypeOther = 0,
    KeyTypeVirtualSmartCard = 1,
    KeyTypePhysicalSmartCard = 2,
    KeyTypePassport = 3,
    KeyTypePassportRemote = 4,
    KeyTypePassportSmartCard = 5,
    KeyTypeHardware = 6,
    KeyTypeSoftware = 7,
    KeyTypeSelfSigned = 8
  } CertKeyType;

#define IS_CERT_HASH_PROP_ID(X) (CERT_SHA1_HASH_PROP_ID == (X) || CERT_MD5_HASH_PROP_ID == (X) || CERT_SIGNATURE_HASH_PROP_ID == (X))
#define IS_PUBKEY_HASH_PROP_ID(X) (CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID == (X) || CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID == (X))
#define IS_CHAIN_HASH_PROP_ID(X) (CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID == (X) || CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID == (X) || CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID == (X) || CERT_SUBJECT_NAME_MD5_HASH_PROP_ID == (X))
#define IS_STRONG_SIGN_PROP_ID(X) (CERT_SIGN_HASH_CNG_ALG_PROP_ID == (X) || CERT_SUBJECT_PUB_KEY_BIT_LENGTH_PROP_ID == (X) || CERT_PUB_KEY_CNG_ALG_BIT_LENGTH_PROP_ID == (X))

#define szOID_CERT_PROP_ID_PREFIX "1.3.6.1.4.1.311.10.11."
#define _szPROP_ID(PropId) #PropId
#define szOID_CERT_PROP_ID(PropId) szOID_CERT_PROP_ID_PREFIX _szPROP_ID (PropId)

#define __CRYPT32WTEXT(quote) L##quote
#define _CRYPT32WTEXT(quote) __CRYPT32WTEXT (quote)
#define wszOID_CERT_PROP_ID(PropId) _CRYPT32WTEXT (szOID_CERT_PROP_ID_PREFIX) _CRYPT32WTEXT (_szPROP_ID (PropId))

#define szOID_CERT_KEY_IDENTIFIER_PROP_ID "1.3.6.1.4.1.311.10.11.20"
#define szOID_CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID "1.3.6.1.4.1.311.10.11.28"
#define szOID_CERT_SUBJECT_NAME_MD5_HASH_PROP_ID "1.3.6.1.4.1.311.10.11.29"
#define szOID_CERT_MD5_HASH_PROP_ID "1.3.6.1.4.1.311.10.11.4"
#define szOID_CERT_SIGNATURE_HASH_PROP_ID "1.3.6.1.4.1.311.10.11.15"
#define szOID_DISALLOWED_HASH szOID_CERT_SIGNATURE_HASH_PROP_ID
#define szOID_CERT_DISALLOWED_FILETIME_PROP_ID "1.3.6.1.4.1.311.10.11.104"

#define CERT_ACCESS_STATE_WRITE_PERSIST_FLAG 0x1
#define CERT_ACCESS_STATE_SYSTEM_STORE_FLAG 0x2
#define CERT_ACCESS_STATE_LM_SYSTEM_STORE_FLAG 0x4
#define CERT_ACCESS_STATE_GP_SYSTEM_STORE_FLAG 0x8
#define CERT_ACCESS_STATE_SHARED_USER_FLAG 0x10

#define szOID_ROOT_PROGRAM_AUTO_UPDATE_CA_REVOCATION "1.3.6.1.4.1.311.60.3.1"
#define szOID_ROOT_PROGRAM_AUTO_UPDATE_END_REVOCATION "1.3.6.1.4.1.311.60.3.2"
#define szOID_ROOT_PROGRAM_NO_OCSP_FAILOVER_TO_CRL "1.3.6.1.4.1.311.60.3.3"

  typedef struct _CRYPT_KEY_PROV_PARAM {
    DWORD dwParam;
    BYTE *pbData;
    DWORD cbData;
    DWORD dwFlags;
  } CRYPT_KEY_PROV_PARAM,*PCRYPT_KEY_PROV_PARAM;

  typedef struct _CRYPT_KEY_PROV_INFO {
    LPWSTR pwszContainerName;
    LPWSTR pwszProvName;
    DWORD dwProvType;
    DWORD dwFlags;
    DWORD cProvParam;
    PCRYPT_KEY_PROV_PARAM rgProvParam;
    DWORD dwKeySpec;
  } CRYPT_KEY_PROV_INFO,*PCRYPT_KEY_PROV_INFO;

#define CERT_SET_KEY_PROV_HANDLE_PROP_ID 0x1
#define CERT_SET_KEY_CONTEXT_PROP_ID 0x1

#define CERT_NCRYPT_KEY_SPEC 0xffffffff

  typedef struct _CERT_KEY_CONTEXT {
    DWORD cbSize;
    __C89_NAMELESS union {
      HCRYPTPROV hCryptProv;
      NCRYPT_KEY_HANDLE hNCryptKey;
    };
    DWORD dwKeySpec;
  } CERT_KEY_CONTEXT,*PCERT_KEY_CONTEXT;

  typedef struct _ROOT_INFO_LUID {
    DWORD LowPart;
    LONG HighPart;
  } ROOT_INFO_LUID,*PROOT_INFO_LUID;

  typedef struct _CRYPT_SMART_CARD_ROOT_INFO {
    BYTE rgbCardID [16];
    ROOT_INFO_LUID luid;
  } CRYPT_SMART_CARD_ROOT_INFO,*PCRYPT_SMART_CARD_ROOT_INFO;

#define CERT_STORE_PROV_MSG ((LPCSTR) 1)
#define CERT_STORE_PROV_MEMORY ((LPCSTR) 2)
#define CERT_STORE_PROV_FILE ((LPCSTR) 3)
#define CERT_STORE_PROV_REG ((LPCSTR) 4)
#define CERT_STORE_PROV_PKCS7 ((LPCSTR) 5)
#define CERT_STORE_PROV_SERIALIZED ((LPCSTR) 6)
#define CERT_STORE_PROV_FILENAME_A ((LPCSTR) 7)
#define CERT_STORE_PROV_FILENAME_W ((LPCSTR) 8)
#define CERT_STORE_PROV_FILENAME CERT_STORE_PROV_FILENAME_W
#define CERT_STORE_PROV_SYSTEM_A ((LPCSTR) 9)
#define CERT_STORE_PROV_SYSTEM_W ((LPCSTR) 10)
#define CERT_STORE_PROV_SYSTEM CERT_STORE_PROV_SYSTEM_W
#define CERT_STORE_PROV_COLLECTION ((LPCSTR) 11)
#define CERT_STORE_PROV_SYSTEM_REGISTRY_A ((LPCSTR) 12)
#define CERT_STORE_PROV_SYSTEM_REGISTRY_W ((LPCSTR) 13)
#define CERT_STORE_PROV_SYSTEM_REGISTRY CERT_STORE_PROV_SYSTEM_REGISTRY_W
#define CERT_STORE_PROV_PHYSICAL_W ((LPCSTR) 14)
#define CERT_STORE_PROV_PHYSICAL CERT_STORE_PROV_PHYSICAL_W
#define CERT_STORE_PROV_SMART_CARD_W ((LPCSTR) 15)
#define CERT_STORE_PROV_SMART_CARD CERT_STORE_PROV_SMART_CARD_W
#define CERT_STORE_PROV_LDAP_W ((LPCSTR) 16)
#define CERT_STORE_PROV_LDAP CERT_STORE_PROV_LDAP_W
#define CERT_STORE_PROV_PKCS12 ((LPCSTR) 17)

#define sz_CERT_STORE_PROV_MEMORY "Memory"
#define sz_CERT_STORE_PROV_FILENAME_W "File"
#define sz_CERT_STORE_PROV_FILENAME sz_CERT_STORE_PROV_FILENAME_W
#define sz_CERT_STORE_PROV_SYSTEM_W "System"
#define sz_CERT_STORE_PROV_SYSTEM sz_CERT_STORE_PROV_SYSTEM_W
#define sz_CERT_STORE_PROV_PKCS7 "PKCS7"
#define sz_CERT_STORE_PROV_PKCS12 "PKCS12"
#define sz_CERT_STORE_PROV_SERIALIZED "Serialized"

#define sz_CERT_STORE_PROV_COLLECTION "Collection"
#define sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W "SystemRegistry"
#define sz_CERT_STORE_PROV_SYSTEM_REGISTRY sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W
#define sz_CERT_STORE_PROV_PHYSICAL_W "Physical"
#define sz_CERT_STORE_PROV_PHYSICAL sz_CERT_STORE_PROV_PHYSICAL_W

#define sz_CERT_STORE_PROV_SMART_CARD_W "SmartCard"
#define sz_CERT_STORE_PROV_SMART_CARD sz_CERT_STORE_PROV_SMART_CARD_W

#define sz_CERT_STORE_PROV_LDAP_W "Ldap"
#define sz_CERT_STORE_PROV_LDAP sz_CERT_STORE_PROV_LDAP_W

#define CERT_STORE_SIGNATURE_FLAG 0x1
#define CERT_STORE_TIME_VALIDITY_FLAG 0x2
#define CERT_STORE_REVOCATION_FLAG 0x4
#define CERT_STORE_NO_CRL_FLAG 0x10000
#define CERT_STORE_NO_ISSUER_FLAG 0x20000

#define CERT_STORE_BASE_CRL_FLAG 0x100
#define CERT_STORE_DELTA_CRL_FLAG 0x200

#define CERT_STORE_NO_CRYPT_RELEASE_FLAG 0x1
#define CERT_STORE_SET_LOCALIZED_NAME_FLAG 0x2
#define CERT_STORE_DEFER_CLOSE_UNTIL_LAST_FREE_FLAG 0x4
#define CERT_STORE_DELETE_FLAG 0x10
#define CERT_STORE_UNSAFE_PHYSICAL_FLAG 0x20
#define CERT_STORE_SHARE_STORE_FLAG 0x40
#define CERT_STORE_SHARE_CONTEXT_FLAG 0x80
#define CERT_STORE_MANIFOLD_FLAG 0x100
#define CERT_STORE_ENUM_ARCHIVED_FLAG 0x200
#define CERT_STORE_UPDATE_KEYID_FLAG 0x400
#define CERT_STORE_BACKUP_RESTORE_FLAG 0x800
#define CERT_STORE_READONLY_FLAG 0x8000
#define CERT_STORE_OPEN_EXISTING_FLAG 0x4000
#define CERT_STORE_CREATE_NEW_FLAG 0x2000
#define CERT_STORE_MAXIMUM_ALLOWED_FLAG 0x1000

#define CERT_SYSTEM_STORE_MASK 0xffff0000

#define CERT_SYSTEM_STORE_RELOCATE_FLAG 0x80000000

  typedef struct _CERT_SYSTEM_STORE_RELOCATE_PARA {
    __C89_NAMELESS union {
      HKEY hKeyBase;
      void *pvBase;
    };
    __C89_NAMELESS union {
      void *pvSystemStore;
      LPCSTR pszSystemStore;
      LPCWSTR pwszSystemStore;
    };
  } CERT_SYSTEM_STORE_RELOCATE_PARA,*PCERT_SYSTEM_STORE_RELOCATE_PARA;

#define CERT_SYSTEM_STORE_DEFER_READ_FLAG 0x20000000
#define CERT_SYSTEM_STORE_UNPROTECTED_FLAG 0x40000000

#define CERT_SYSTEM_STORE_LOCATION_MASK 0x00ff0000
#define CERT_SYSTEM_STORE_LOCATION_SHIFT 16

#define CERT_SYSTEM_STORE_CURRENT_USER_ID 1
#define CERT_SYSTEM_STORE_LOCAL_MACHINE_ID 2
#define CERT_SYSTEM_STORE_CURRENT_SERVICE_ID 4
#define CERT_SYSTEM_STORE_SERVICES_ID 5
#define CERT_SYSTEM_STORE_USERS_ID 6
#define CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID 7
#define CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID 8
#define CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID 9
#define CERT_SYSTEM_STORE_LOCAL_MACHINE_WCOS_ID 10

#define CERT_SYSTEM_STORE_CURRENT_USER (CERT_SYSTEM_STORE_CURRENT_USER_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_LOCAL_MACHINE (CERT_SYSTEM_STORE_LOCAL_MACHINE_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_CURRENT_SERVICE (CERT_SYSTEM_STORE_CURRENT_SERVICE_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_SERVICES (CERT_SYSTEM_STORE_SERVICES_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_USERS (CERT_SYSTEM_STORE_USERS_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY (CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY (CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE (CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
#define CERT_SYSTEM_STORE_LOCAL_MACHINE_WCOS (CERT_SYSTEM_STORE_LOCAL_MACHINE_WCOS_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)

#define CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L"Software\\Policies\\Microsoft\\SystemCertificates"

#define CERT_EFSBLOB_REGPATH CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L"\\EFS"
#define CERT_EFSBLOB_VALUE_NAME L"EFSBlob"

#define CERT_PROT_ROOT_FLAGS_REGPATH CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L"\\Root\\ProtectedRoots"
#define CERT_PROT_ROOT_FLAGS_VALUE_NAME L"Flags"
#define CERT_PROT_ROOT_DISABLE_CURRENT_USER_FLAG 0x1
#define CERT_PROT_ROOT_INHIBIT_ADD_AT_INIT_FLAG 0x2
#define CERT_PROT_ROOT_INHIBIT_PURGE_LM_FLAG 0x4
#define CERT_PROT_ROOT_DISABLE_LM_AUTH_FLAG 0x8
#define CERT_PROT_ROOT_ONLY_LM_GPT_FLAG 0x8
#define CERT_PROT_ROOT_DISABLE_NT_AUTH_REQUIRED_FLAG 0x10
#define CERT_PROT_ROOT_DISABLE_NOT_DEFINED_NAME_CONSTRAINT_FLAG 0x20
#define CERT_PROT_ROOT_DISABLE_PEER_TRUST 0x10000
#define CERT_PROT_ROOT_PEER_USAGES_VALUE_NAME L"PeerUsages"
#define CERT_PROT_ROOT_PEER_USAGES_VALUE_NAME_A "PeerUsages"
#define CERT_PROT_ROOT_PEER_USAGES_DEFAULT_A szOID_PKIX_KP_CLIENT_AUTH "\0" szOID_PKIX_KP_EMAIL_PROTECTION "\0" szOID_KP_EFS "\0"

#define CERT_TRUST_PUB_SAFER_GROUP_POLICY_REGPATH CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L"\\TrustedPublisher\\Safer"
#define CERT_LOCAL_MACHINE_SYSTEM_STORE_REGPATH L"Software\\Microsoft\\SystemCertificates"
#define CERT_TRUST_PUB_SAFER_LOCAL_MACHINE_REGPATH CERT_LOCAL_MACHINE_SYSTEM_STORE_REGPATH L"\\TrustedPublisher\\Safer"
#define CERT_TRUST_PUB_AUTHENTICODE_FLAGS_VALUE_NAME L"AuthenticodeFlags"

#define CERT_TRUST_PUB_ALLOW_TRUST_MASK 0x3
#define CERT_TRUST_PUB_ALLOW_END_USER_TRUST 0x0
#define CERT_TRUST_PUB_ALLOW_MACHINE_ADMIN_TRUST 0x1
#define CERT_TRUST_PUB_ALLOW_ENTERPRISE_ADMIN_TRUST 0x2
#define CERT_TRUST_PUB_CHECK_PUBLISHER_REV_FLAG 0x100
#define CERT_TRUST_PUB_CHECK_TIMESTAMP_REV_FLAG 0x200

#define CERT_OCM_SUBCOMPONENTS_LOCAL_MACHINE_REGPATH L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\OC Manager\\Subcomponents"
#define CERT_OCM_SUBCOMPONENTS_ROOT_AUTO_UPDATE_VALUE_NAME L"RootAutoUpdate"

#define CERT_DISABLE_ROOT_AUTO_UPDATE_REGPATH CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L"\\AuthRoot"
#define CERT_DISABLE_ROOT_AUTO_UPDATE_VALUE_NAME L"DisableRootAutoUpdate"

#define CERT_ENABLE_DISALLOWED_CERT_AUTO_UPDATE_VALUE_NAME L"EnableDisallowedCertAutoUpdate"

#define CERT_DISABLE_PIN_RULES_AUTO_UPDATE_VALUE_NAME L"DisablePinRulesAutoUpdate"

#define CERT_AUTO_UPDATE_LOCAL_MACHINE_REGPATH CERT_LOCAL_MACHINE_SYSTEM_STORE_REGPATH L"\\AuthRoot\\AutoUpdate"
#define CERT_AUTO_UPDATE_ROOT_DIR_URL_VALUE_NAME L"RootDirUrl"

#define CERT_AUTO_UPDATE_SYNC_FROM_DIR_URL_VALUE_NAME L"SyncFromDirUrl"

#define CERT_AUTH_ROOT_AUTO_UPDATE_LOCAL_MACHINE_REGPATH CERT_AUTO_UPDATE_LOCAL_MACHINE_REGPATH
#define CERT_AUTH_ROOT_AUTO_UPDATE_ROOT_DIR_URL_VALUE_NAME CERT_AUTO_UPDATE_ROOT_DIR_URL_VALUE_NAME
#define CERT_AUTH_ROOT_AUTO_UPDATE_SYNC_DELTA_TIME_VALUE_NAME L"SyncDeltaTime"
#define CERT_AUTH_ROOT_AUTO_UPDATE_FLAGS_VALUE_NAME L"Flags"
#define CERT_AUTH_ROOT_AUTO_UPDATE_DISABLE_UNTRUSTED_ROOT_LOGGING_FLAG 0x1
#define CERT_AUTH_ROOT_AUTO_UPDATE_DISABLE_PARTIAL_CHAIN_LOGGING_FLAG 0x2
#define CERT_AUTO_UPDATE_DISABLE_RANDOM_QUERY_STRING_FLAG 0x4
#define CERT_AUTH_ROOT_AUTO_UPDATE_LAST_SYNC_TIME_VALUE_NAME L"LastSyncTime"
#define CERT_AUTH_ROOT_AUTO_UPDATE_ENCODED_CTL_VALUE_NAME L"EncodedCtl"
#define CERT_AUTH_ROOT_CTL_FILENAME L"authroot.stl"
#define CERT_AUTH_ROOT_CTL_FILENAME_A "authroot.stl"
#define CERT_AUTH_ROOT_CAB_FILENAME L"authrootstl.cab"
#define CERT_AUTH_ROOT_SEQ_FILENAME L"authrootseq.txt"
#define CERT_AUTH_ROOT_CERT_EXT L".crt"

#define CERT_DISALLOWED_CERT_AUTO_UPDATE_SYNC_DELTA_TIME_VALUE_NAME L"DisallowedCertSyncDeltaTime"
#define CERT_DISALLOWED_CERT_AUTO_UPDATE_LAST_SYNC_TIME_VALUE_NAME L"DisallowedCertLastSyncTime"
#define CERT_DISALLOWED_CERT_AUTO_UPDATE_ENCODED_CTL_VALUE_NAME L"DisallowedCertEncodedCtl"
#define CERT_DISALLOWED_CERT_CTL_FILENAME L"disallowedcert.stl"
#define CERT_DISALLOWED_CERT_CTL_FILENAME_A "disallowedcert.stl"
#define CERT_DISALLOWED_CERT_CAB_FILENAME L"disallowedcertstl.cab"
#define CERT_DISALLOWED_CERT_AUTO_UPDATE_LIST_IDENTIFIER L"DisallowedCert_AutoUpdate_1"

#define CERT_PIN_RULES_AUTO_UPDATE_SYNC_DELTA_TIME_VALUE_NAME L"PinRulesSyncDeltaTime"
#define CERT_PIN_RULES_AUTO_UPDATE_LAST_SYNC_TIME_VALUE_NAME L"PinRulesLastSyncTime"
#define CERT_PIN_RULES_AUTO_UPDATE_ENCODED_CTL_VALUE_NAME L"PinRulesEncodedCtl"

#define CERT_PIN_RULES_CTL_FILENAME L"pinrules.stl"
#define CERT_PIN_RULES_CTL_FILENAME_A "pinrules.stl"

#define CERT_PIN_RULES_CAB_FILENAME L"pinrulesstl.cab"

#define CERT_PIN_RULES_AUTO_UPDATE_LIST_IDENTIFIER L"PinRules_AutoUpdate_1"

#define CERT_REGISTRY_STORE_REMOTE_FLAG 0x10000
#define CERT_REGISTRY_STORE_SERIALIZED_FLAG 0x20000
#define CERT_REGISTRY_STORE_CLIENT_GPT_FLAG 0x80000000
#define CERT_REGISTRY_STORE_LM_GPT_FLAG 0x1000000

  typedef struct _CERT_REGISTRY_STORE_CLIENT_GPT_PARA {
    HKEY hKeyBase;
    LPWSTR pwszRegPath;
  } CERT_REGISTRY_STORE_CLIENT_GPT_PARA,*PCERT_REGISTRY_STORE_CLIENT_GPT_PARA;

#define CERT_REGISTRY_STORE_ROAMING_FLAG 0x40000

  typedef struct _CERT_REGISTRY_STORE_ROAMING_PARA {
    HKEY hKey;
    LPWSTR pwszStoreDirectory;
  } CERT_REGISTRY_STORE_ROAMING_PARA,*PCERT_REGISTRY_STORE_ROAMING_PARA;

#define CERT_REGISTRY_STORE_MY_IE_DIRTY_FLAG 0x80000
#define CERT_REGISTRY_STORE_EXTERNAL_FLAG 0x100000

#define CERT_IE_DIRTY_FLAGS_REGPATH L"Software\\Microsoft\\Cryptography\\IEDirtyFlags"

#define CERT_FILE_STORE_COMMIT_ENABLE_FLAG 0x10000
#define CERT_LDAP_STORE_SIGN_FLAG 0x10000
#define CERT_LDAP_STORE_AREC_EXCLUSIVE_FLAG 0x20000
#define CERT_LDAP_STORE_OPENED_FLAG 0x40000

  typedef struct _CERT_LDAP_STORE_OPENED_PARA {
    void *pvLdapSessionHandle;
    LPCWSTR pwszLdapUrl;
  } CERT_LDAP_STORE_OPENED_PARA,*PCERT_LDAP_STORE_OPENED_PARA;

#define CERT_LDAP_STORE_UNBIND_FLAG 0x80000

WINIMPM HCERTSTORE WINAPI CertOpenStore (LPCSTR lpszStoreProvider, DWORD dwEncodingType, HCRYPTPROV_LEGACY hCryptProv, DWORD dwFlags, const void *pvPara);

  typedef void *HCERTSTOREPROV;

#define CRYPT_OID_OPEN_STORE_PROV_FUNC "CertDllOpenStoreProv"

  typedef struct _CERT_STORE_PROV_INFO {
    DWORD cbSize;
    DWORD cStoreProvFunc;
    void **rgpvStoreProvFunc;
    HCERTSTOREPROV hStoreProv;
    DWORD dwStoreProvFlags;
    HCRYPTOIDFUNCADDR hStoreProvFuncAddr2;
  } CERT_STORE_PROV_INFO,*PCERT_STORE_PROV_INFO;

  typedef WINBOOL (WINAPI *PFN_CERT_DLL_OPEN_STORE_PROV_FUNC) (LPCSTR lpszStoreProvider, DWORD dwEncodingType, HCRYPTPROV_LEGACY hCryptProv, DWORD dwFlags, const void *pvPara, HCERTSTORE hCertStore, PCERT_STORE_PROV_INFO pStoreProvInfo);

#define CERT_STORE_PROV_EXTERNAL_FLAG 0x1
#define CERT_STORE_PROV_DELETED_FLAG 0x2
#define CERT_STORE_PROV_NO_PERSIST_FLAG 0x4
#define CERT_STORE_PROV_SYSTEM_STORE_FLAG 0x8
#define CERT_STORE_PROV_LM_SYSTEM_STORE_FLAG 0x10
#define CERT_STORE_PROV_GP_SYSTEM_STORE_FLAG 0x20
#define CERT_STORE_PROV_SHARED_USER_FLAG 0x40

#define CERT_STORE_PROV_CLOSE_FUNC 0
#define CERT_STORE_PROV_READ_CERT_FUNC 1
#define CERT_STORE_PROV_WRITE_CERT_FUNC 2
#define CERT_STORE_PROV_DELETE_CERT_FUNC 3
#define CERT_STORE_PROV_SET_CERT_PROPERTY_FUNC 4
#define CERT_STORE_PROV_READ_CRL_FUNC 5
#define CERT_STORE_PROV_WRITE_CRL_FUNC 6
#define CERT_STORE_PROV_DELETE_CRL_FUNC 7
#define CERT_STORE_PROV_SET_CRL_PROPERTY_FUNC 8
#define CERT_STORE_PROV_READ_CTL_FUNC 9
#define CERT_STORE_PROV_WRITE_CTL_FUNC 10
#define CERT_STORE_PROV_DELETE_CTL_FUNC 11
#define CERT_STORE_PROV_SET_CTL_PROPERTY_FUNC 12
#define CERT_STORE_PROV_CONTROL_FUNC 13
#define CERT_STORE_PROV_FIND_CERT_FUNC 14
#define CERT_STORE_PROV_FREE_FIND_CERT_FUNC 15
#define CERT_STORE_PROV_GET_CERT_PROPERTY_FUNC 16
#define CERT_STORE_PROV_FIND_CRL_FUNC 17
#define CERT_STORE_PROV_FREE_FIND_CRL_FUNC 18
#define CERT_STORE_PROV_GET_CRL_PROPERTY_FUNC 19
#define CERT_STORE_PROV_FIND_CTL_FUNC 20
#define CERT_STORE_PROV_FREE_FIND_CTL_FUNC 21
#define CERT_STORE_PROV_GET_CTL_PROPERTY_FUNC 22

#define CERT_STORE_PROV_WRITE_ADD_FLAG 0x1

  typedef void (WINAPI *PFN_CERT_STORE_PROV_CLOSE) (HCERTSTOREPROV hStoreProv, DWORD dwFlags);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_READ_CERT) (HCERTSTOREPROV hStoreProv, PCCERT_CONTEXT pStoreCertContext, DWORD dwFlags, PCCERT_CONTEXT *ppProvCertContext);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_WRITE_CERT) (HCERTSTOREPROV hStoreProv, PCCERT_CONTEXT pCertContext, DWORD dwFlags);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_DELETE_CERT) (HCERTSTOREPROV hStoreProv, PCCERT_CONTEXT pCertContext, DWORD dwFlags);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_SET_CERT_PROPERTY) (HCERTSTOREPROV hStoreProv, PCCERT_CONTEXT pCertContext, DWORD dwPropId, DWORD dwFlags, const void *pvData);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_READ_CRL) (HCERTSTOREPROV hStoreProv, PCCRL_CONTEXT pStoreCrlContext, DWORD dwFlags, PCCRL_CONTEXT *ppProvCrlContext);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_WRITE_CRL) (HCERTSTOREPROV hStoreProv, PCCRL_CONTEXT pCrlContext, DWORD dwFlags);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_DELETE_CRL) (HCERTSTOREPROV hStoreProv, PCCRL_CONTEXT pCrlContext, DWORD dwFlags);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_SET_CRL_PROPERTY) (HCERTSTOREPROV hStoreProv, PCCRL_CONTEXT pCrlContext, DWORD dwPropId, DWORD dwFlags, const void *pvData);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_READ_CTL) (HCERTSTOREPROV hStoreProv, PCCTL_CONTEXT pStoreCtlContext, DWORD dwFlags, PCCTL_CONTEXT *ppProvCtlContext);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_WRITE_CTL) (HCERTSTOREPROV hStoreProv, PCCTL_CONTEXT pCtlContext, DWORD dwFlags);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_DELETE_CTL) (HCERTSTOREPROV hStoreProv, PCCTL_CONTEXT pCtlContext, DWORD dwFlags);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_SET_CTL_PROPERTY) (HCERTSTOREPROV hStoreProv, PCCTL_CONTEXT pCtlContext, DWORD dwPropId, DWORD dwFlags, const void *pvData);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_CONTROL) (HCERTSTOREPROV hStoreProv, DWORD dwFlags, DWORD dwCtrlType, void const *pvCtrlPara);

  typedef struct _CERT_STORE_PROV_FIND_INFO {
    DWORD cbSize;
    DWORD dwMsgAndCertEncodingType;
    DWORD dwFindFlags;
    DWORD dwFindType;
    const void *pvFindPara;
  } CERT_STORE_PROV_FIND_INFO,*PCERT_STORE_PROV_FIND_INFO;

  typedef const CERT_STORE_PROV_FIND_INFO CCERT_STORE_PROV_FIND_INFO,*PCCERT_STORE_PROV_FIND_INFO;

  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_FIND_CERT) (HCERTSTOREPROV hStoreProv, PCCERT_STORE_PROV_FIND_INFO pFindInfo, PCCERT_CONTEXT pPrevCertContext, DWORD dwFlags, void **ppvStoreProvFindInfo, PCCERT_CONTEXT *ppProvCertContext);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_FREE_FIND_CERT) (HCERTSTOREPROV hStoreProv, PCCERT_CONTEXT pCertContext, void *pvStoreProvFindInfo, DWORD dwFlags);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_GET_CERT_PROPERTY) (HCERTSTOREPROV hStoreProv, PCCERT_CONTEXT pCertContext, DWORD dwPropId, DWORD dwFlags, void *pvData, DWORD *pcbData);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_FIND_CRL) (HCERTSTOREPROV hStoreProv, PCCERT_STORE_PROV_FIND_INFO pFindInfo, PCCRL_CONTEXT pPrevCrlContext, DWORD dwFlags, void **ppvStoreProvFindInfo, PCCRL_CONTEXT *ppProvCrlContext);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_FREE_FIND_CRL) (HCERTSTOREPROV hStoreProv, PCCRL_CONTEXT pCrlContext, void *pvStoreProvFindInfo, DWORD dwFlags);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_GET_CRL_PROPERTY) (HCERTSTOREPROV hStoreProv, PCCRL_CONTEXT pCrlContext, DWORD dwPropId, DWORD dwFlags, void *pvData, DWORD *pcbData);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_FIND_CTL) (HCERTSTOREPROV hStoreProv, PCCERT_STORE_PROV_FIND_INFO pFindInfo, PCCTL_CONTEXT pPrevCtlContext, DWORD dwFlags, void **ppvStoreProvFindInfo, PCCTL_CONTEXT *ppProvCtlContext);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_FREE_FIND_CTL) (HCERTSTOREPROV hStoreProv, PCCTL_CONTEXT pCtlContext, void *pvStoreProvFindInfo, DWORD dwFlags);
  typedef WINBOOL (WINAPI *PFN_CERT_STORE_PROV_GET_CTL_PROPERTY) (HCERTSTOREPROV hStoreProv, PCCTL_CONTEXT pCtlContext, DWORD dwPropId, DWORD dwFlags, void *pvData, DWORD *pcbData);

  WINIMPM HCERTSTORE WINAPI CertDuplicateStore (HCERTSTORE hCertStore);

#define CERT_STORE_SAVE_AS_STORE 1
#define CERT_STORE_SAVE_AS_PKCS7 2
#define CERT_STORE_SAVE_AS_PKCS12 3

#define CERT_STORE_SAVE_TO_FILE 1
#define CERT_STORE_SAVE_TO_MEMORY 2
#define CERT_STORE_SAVE_TO_FILENAME_A 3
#define CERT_STORE_SAVE_TO_FILENAME_W 4
#define CERT_STORE_SAVE_TO_FILENAME CERT_STORE_SAVE_TO_FILENAME_W

#define CERT_CLOSE_STORE_FORCE_FLAG 0x1
#define CERT_CLOSE_STORE_CHECK_FLAG 0x2

  WINIMPM WINBOOL WINAPI CertSaveStore (HCERTSTORE hCertStore, DWORD dwEncodingType, DWORD dwSaveAs, DWORD dwSaveTo, void *pvSaveToPara, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CertCloseStore (HCERTSTORE hCertStore, DWORD dwFlags);
  WINIMPM PCCERT_CONTEXT WINAPI CertGetSubjectCertificateFromStore (HCERTSTORE hCertStore, DWORD dwCertEncodingType, PCERT_INFO pCertId);
  WINIMPM PCCERT_CONTEXT WINAPI CertEnumCertificatesInStore (HCERTSTORE hCertStore, PCCERT_CONTEXT pPrevCertContext);
  WINIMPM PCCERT_CONTEXT WINAPI CertFindCertificateInStore (HCERTSTORE hCertStore, DWORD dwCertEncodingType, DWORD dwFindFlags, DWORD dwFindType, const void *pvFindPara, PCCERT_CONTEXT pPrevCertContext);

#define CERT_COMPARE_MASK 0xffff
#define CERT_COMPARE_SHIFT 16
#define CERT_COMPARE_ANY 0
#define CERT_COMPARE_SHA1_HASH 1
#define CERT_COMPARE_NAME 2
#define CERT_COMPARE_ATTR 3
#define CERT_COMPARE_MD5_HASH 4
#define CERT_COMPARE_PROPERTY 5
#define CERT_COMPARE_PUBLIC_KEY 6
#define CERT_COMPARE_HASH CERT_COMPARE_SHA1_HASH
#define CERT_COMPARE_NAME_STR_A 7
#define CERT_COMPARE_NAME_STR_W 8
#define CERT_COMPARE_KEY_SPEC 9
#define CERT_COMPARE_ENHKEY_USAGE 10
#define CERT_COMPARE_CTL_USAGE CERT_COMPARE_ENHKEY_USAGE
#define CERT_COMPARE_SUBJECT_CERT 11
#define CERT_COMPARE_ISSUER_OF 12
#define CERT_COMPARE_EXISTING 13
#define CERT_COMPARE_SIGNATURE_HASH 14
#define CERT_COMPARE_KEY_IDENTIFIER 15
#define CERT_COMPARE_CERT_ID 16
#define CERT_COMPARE_CROSS_CERT_DIST_POINTS 17
#define CERT_COMPARE_PUBKEY_MD5_HASH 18
#define CERT_COMPARE_SUBJECT_INFO_ACCESS 19
#define CERT_COMPARE_HASH_STR 20
#define CERT_COMPARE_HAS_PRIVATE_KEY 21

#define CERT_FIND_ANY (CERT_COMPARE_ANY << CERT_COMPARE_SHIFT)
#define CERT_FIND_SHA1_HASH (CERT_COMPARE_SHA1_HASH << CERT_COMPARE_SHIFT)
#define CERT_FIND_MD5_HASH (CERT_COMPARE_MD5_HASH << CERT_COMPARE_SHIFT)
#define CERT_FIND_SIGNATURE_HASH (CERT_COMPARE_SIGNATURE_HASH << CERT_COMPARE_SHIFT)
#define CERT_FIND_KEY_IDENTIFIER (CERT_COMPARE_KEY_IDENTIFIER << CERT_COMPARE_SHIFT)
#define CERT_FIND_HASH CERT_FIND_SHA1_HASH
#define CERT_FIND_PROPERTY (CERT_COMPARE_PROPERTY << CERT_COMPARE_SHIFT)
#define CERT_FIND_PUBLIC_KEY (CERT_COMPARE_PUBLIC_KEY << CERT_COMPARE_SHIFT)
#define CERT_FIND_SUBJECT_NAME (CERT_COMPARE_NAME << CERT_COMPARE_SHIFT | CERT_INFO_SUBJECT_FLAG)
#define CERT_FIND_SUBJECT_ATTR (CERT_COMPARE_ATTR << CERT_COMPARE_SHIFT | CERT_INFO_SUBJECT_FLAG)
#define CERT_FIND_ISSUER_NAME (CERT_COMPARE_NAME << CERT_COMPARE_SHIFT | CERT_INFO_ISSUER_FLAG)
#define CERT_FIND_ISSUER_ATTR (CERT_COMPARE_ATTR << CERT_COMPARE_SHIFT | CERT_INFO_ISSUER_FLAG)
#define CERT_FIND_SUBJECT_STR_A (CERT_COMPARE_NAME_STR_A << CERT_COMPARE_SHIFT | CERT_INFO_SUBJECT_FLAG)
#define CERT_FIND_SUBJECT_STR_W (CERT_COMPARE_NAME_STR_W << CERT_COMPARE_SHIFT | CERT_INFO_SUBJECT_FLAG)
#define CERT_FIND_SUBJECT_STR CERT_FIND_SUBJECT_STR_W
#define CERT_FIND_ISSUER_STR_A (CERT_COMPARE_NAME_STR_A << CERT_COMPARE_SHIFT | CERT_INFO_ISSUER_FLAG)
#define CERT_FIND_ISSUER_STR_W (CERT_COMPARE_NAME_STR_W << CERT_COMPARE_SHIFT | CERT_INFO_ISSUER_FLAG)
#define CERT_FIND_ISSUER_STR CERT_FIND_ISSUER_STR_W
#define CERT_FIND_KEY_SPEC (CERT_COMPARE_KEY_SPEC << CERT_COMPARE_SHIFT)
#define CERT_FIND_ENHKEY_USAGE (CERT_COMPARE_ENHKEY_USAGE << CERT_COMPARE_SHIFT)
#define CERT_FIND_CTL_USAGE CERT_FIND_ENHKEY_USAGE
#define CERT_FIND_SUBJECT_CERT (CERT_COMPARE_SUBJECT_CERT << CERT_COMPARE_SHIFT)
#define CERT_FIND_ISSUER_OF (CERT_COMPARE_ISSUER_OF << CERT_COMPARE_SHIFT)
#define CERT_FIND_EXISTING (CERT_COMPARE_EXISTING << CERT_COMPARE_SHIFT)
#define CERT_FIND_CERT_ID (CERT_COMPARE_CERT_ID << CERT_COMPARE_SHIFT)
#define CERT_FIND_CROSS_CERT_DIST_POINTS (CERT_COMPARE_CROSS_CERT_DIST_POINTS << CERT_COMPARE_SHIFT)
#define CERT_FIND_PUBKEY_MD5_HASH (CERT_COMPARE_PUBKEY_MD5_HASH << CERT_COMPARE_SHIFT)
#define CERT_FIND_SUBJECT_INFO_ACCESS (CERT_COMPARE_SUBJECT_INFO_ACCESS << CERT_COMPARE_SHIFT)
#define CERT_FIND_HASH_STR (CERT_COMPARE_HASH_STR << CERT_COMPARE_SHIFT)
#define CERT_FIND_HAS_PRIVATE_KEY (CERT_COMPARE_HAS_PRIVATE_KEY << CERT_COMPARE_SHIFT)

#define CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG 0x1
#define CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG 0x2
#define CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG 0x4
#define CERT_FIND_NO_ENHKEY_USAGE_FLAG 0x8
#define CERT_FIND_OR_ENHKEY_USAGE_FLAG 0x10
#define CERT_FIND_VALID_ENHKEY_USAGE_FLAG 0x20

#define CERT_FIND_OPTIONAL_CTL_USAGE_FLAG CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG
#define CERT_FIND_EXT_ONLY_CTL_USAGE_FLAG CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG
#define CERT_FIND_PROP_ONLY_CTL_USAGE_FLAG CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG
#define CERT_FIND_NO_CTL_USAGE_FLAG CERT_FIND_NO_ENHKEY_USAGE_FLAG
#define CERT_FIND_OR_CTL_USAGE_FLAG CERT_FIND_OR_ENHKEY_USAGE_FLAG
#define CERT_FIND_VALID_CTL_USAGE_FLAG CERT_FIND_VALID_ENHKEY_USAGE_FLAG

  WINIMPM PCCERT_CONTEXT WINAPI CertGetIssuerCertificateFromStore (HCERTSTORE hCertStore, PCCERT_CONTEXT pSubjectContext, PCCERT_CONTEXT pPrevIssuerContext, DWORD *pdwFlags);
  WINIMPM WINBOOL WINAPI CertVerifySubjectCertificateContext (PCCERT_CONTEXT pSubject, PCCERT_CONTEXT pIssuer, DWORD *pdwFlags);
  WINIMPM PCCERT_CONTEXT WINAPI CertDuplicateCertificateContext (PCCERT_CONTEXT pCertContext);
  WINIMPM PCCERT_CONTEXT WINAPI CertCreateCertificateContext (DWORD dwCertEncodingType, const BYTE *pbCertEncoded, DWORD cbCertEncoded);
  WINIMPM WINBOOL WINAPI CertFreeCertificateContext (PCCERT_CONTEXT pCertContext);
  WINIMPM WINBOOL WINAPI CertSetCertificateContextProperty (PCCERT_CONTEXT pCertContext, DWORD dwPropId, DWORD dwFlags, const void *pvData);

  typedef struct _CRL_FIND_ISSUED_FOR_PARA {
    PCCERT_CONTEXT pSubjectCert;
    PCCERT_CONTEXT pIssuerCert;
  } CRL_FIND_ISSUED_FOR_PARA,*PCRL_FIND_ISSUED_FOR_PARA;

  typedef struct _CTL_ANY_SUBJECT_INFO {
    CRYPT_ALGORITHM_IDENTIFIER SubjectAlgorithm;
    CRYPT_DATA_BLOB SubjectIdentifier;
  } CTL_ANY_SUBJECT_INFO,*PCTL_ANY_SUBJECT_INFO;

#define CERT_SET_PROPERTY_INHIBIT_PERSIST_FLAG 0x40000000
#define CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG 0x80000000

#define CTL_ENTRY_FROM_PROP_CHAIN_FLAG 0x1

#define CRL_FIND_ANY 0
#define CRL_FIND_ISSUED_BY 1
#define CRL_FIND_EXISTING 2
#define CRL_FIND_ISSUED_FOR 3

#define CRL_FIND_ISSUED_BY_AKI_FLAG 0x1
#define CRL_FIND_ISSUED_BY_SIGNATURE_FLAG 0x2
#define CRL_FIND_ISSUED_BY_DELTA_FLAG 0x4
#define CRL_FIND_ISSUED_BY_BASE_FLAG 0x8
#define CRL_FIND_ISSUED_FOR_SET_STRONG_PROPERTIES_FLAG 0x10

#define CERT_STORE_ADD_NEW 1
#define CERT_STORE_ADD_USE_EXISTING 2
#define CERT_STORE_ADD_REPLACE_EXISTING 3
#define CERT_STORE_ADD_ALWAYS 4
#define CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES 5
#define CERT_STORE_ADD_NEWER 6
#define CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES 7

#define CERT_STORE_CERTIFICATE_CONTEXT 1
#define CERT_STORE_CRL_CONTEXT 2
#define CERT_STORE_CTL_CONTEXT 3

#define CERT_STORE_ALL_CONTEXT_FLAG (~__MSABI_LONG(0U))
#define CERT_STORE_CERTIFICATE_CONTEXT_FLAG (1 << CERT_STORE_CERTIFICATE_CONTEXT)
#define CERT_STORE_CRL_CONTEXT_FLAG (1 << CERT_STORE_CRL_CONTEXT)
#define CERT_STORE_CTL_CONTEXT_FLAG (1 << CERT_STORE_CTL_CONTEXT)

#define CTL_ANY_SUBJECT_TYPE 1
#define CTL_CERT_SUBJECT_TYPE 2

  WINIMPM PCCRL_CONTEXT WINAPI CertEnumCRLsInStore (HCERTSTORE hCertStore, PCCRL_CONTEXT pPrevCrlContext);
  WINIMPM WINBOOL WINAPI CertDeleteCRLFromStore (PCCRL_CONTEXT pCrlContext);
  WINIMPM PCCRL_CONTEXT WINAPI CertDuplicateCRLContext (PCCRL_CONTEXT pCrlContext);
  WINIMPM PCCRL_CONTEXT WINAPI CertFindCRLInStore (HCERTSTORE hCertStore, DWORD dwCertEncodingType, DWORD dwFindFlags, DWORD dwFindType, const void *pvFindPara, PCCRL_CONTEXT pPrevCrlContext);
  WINIMPM WINBOOL WINAPI CertFreeCRLContext (PCCRL_CONTEXT pCrlContext);

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP) || _WIN32_WINNT >= 0x0A00
  WINIMPM WINBOOL WINAPI CertGetCertificateContextProperty (PCCERT_CONTEXT pCertContext, DWORD dwPropId, void *pvData, DWORD *pcbData);
  WINIMPM DWORD WINAPI CertEnumCertificateContextProperties (PCCERT_CONTEXT pCertContext, DWORD dwPropId);
  WINIMPM WINBOOL WINAPI CertDeleteCertificateFromStore (PCCERT_CONTEXT pCertContext);
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)
  WINIMPM WINBOOL WINAPI CertCreateCTLEntryFromCertificateContextProperties (PCCERT_CONTEXT pCertContext, DWORD cOptAttr, PCRYPT_ATTRIBUTE rgOptAttr, DWORD dwFlags, void *pvReserved, PCTL_ENTRY pCtlEntry, DWORD *pcbCtlEntry);
  WINIMPM WINBOOL WINAPI CertSetCertificateContextPropertiesFromCTLEntry (PCCERT_CONTEXT pCertContext, PCTL_ENTRY pCtlEntry, DWORD dwFlags);
  WINIMPM PCCRL_CONTEXT WINAPI CertGetCRLFromStore (HCERTSTORE hCertStore, PCCERT_CONTEXT pIssuerContext, PCCRL_CONTEXT pPrevCrlContext, DWORD *pdwFlags);
  WINIMPM PCCRL_CONTEXT WINAPI CertCreateCRLContext (DWORD dwCertEncodingType, const BYTE *pbCrlEncoded, DWORD cbCrlEncoded);
  WINIMPM WINBOOL WINAPI CertSetCRLContextProperty (PCCRL_CONTEXT pCrlContext, DWORD dwPropId, DWORD dwFlags, const void *pvData);
  WINIMPM WINBOOL WINAPI CertGetCRLContextProperty (PCCRL_CONTEXT pCrlContext, DWORD dwPropId, void *pvData, DWORD *pcbData);
  WINIMPM DWORD WINAPI CertEnumCRLContextProperties (PCCRL_CONTEXT pCrlContext, DWORD dwPropId);
  WINIMPM WINBOOL WINAPI CertFindCertificateInCRL (PCCERT_CONTEXT pCert, PCCRL_CONTEXT pCrlContext, DWORD dwFlags, void *pvReserved, PCRL_ENTRY *ppCrlEntry);
  WINIMPM WINBOOL WINAPI CertIsValidCRLForCertificate (PCCERT_CONTEXT pCert, PCCRL_CONTEXT pCrl, DWORD dwFlags, void *pvReserved);
  WINIMPM WINBOOL WINAPI CertAddEncodedCertificateToStore (HCERTSTORE hCertStore, DWORD dwCertEncodingType, const BYTE *pbCertEncoded, DWORD cbCertEncoded, DWORD dwAddDisposition, PCCERT_CONTEXT *ppCertContext);
  WINIMPM WINBOOL WINAPI CertAddCertificateContextToStore (HCERTSTORE hCertStore, PCCERT_CONTEXT pCertContext, DWORD dwAddDisposition, PCCERT_CONTEXT *ppStoreContext);
  WINIMPM WINBOOL WINAPI CertAddSerializedElementToStore (HCERTSTORE hCertStore, const BYTE *pbElement, DWORD cbElement, DWORD dwAddDisposition, DWORD dwFlags, DWORD dwContextTypeFlags, DWORD *pdwContextType, const void **ppvContext);
  WINIMPM WINBOOL WINAPI CertAddEncodedCRLToStore (HCERTSTORE hCertStore, DWORD dwCertEncodingType, const BYTE *pbCrlEncoded, DWORD cbCrlEncoded, DWORD dwAddDisposition, PCCRL_CONTEXT *ppCrlContext);
  WINIMPM WINBOOL WINAPI CertAddCRLContextToStore (HCERTSTORE hCertStore, PCCRL_CONTEXT pCrlContext, DWORD dwAddDisposition, PCCRL_CONTEXT *ppStoreContext);
  WINIMPM WINBOOL WINAPI CertSerializeCertificateStoreElement (PCCERT_CONTEXT pCertContext, DWORD dwFlags, BYTE *pbElement, DWORD *pcbElement);
  WINIMPM WINBOOL WINAPI CertSerializeCRLStoreElement (PCCRL_CONTEXT pCrlContext, DWORD dwFlags, BYTE *pbElement, DWORD *pcbElement);
  WINIMPM PCCTL_CONTEXT WINAPI CertDuplicateCTLContext (PCCTL_CONTEXT pCtlContext);
  WINIMPM PCCTL_CONTEXT WINAPI CertCreateCTLContext (DWORD dwMsgAndCertEncodingType, const BYTE *pbCtlEncoded, DWORD cbCtlEncoded);
  WINIMPM WINBOOL WINAPI CertFreeCTLContext (PCCTL_CONTEXT pCtlContext);
  WINIMPM WINBOOL WINAPI CertSetCTLContextProperty (PCCTL_CONTEXT pCtlContext, DWORD dwPropId, DWORD dwFlags, const void *pvData);
  WINIMPM WINBOOL WINAPI CertGetCTLContextProperty (PCCTL_CONTEXT pCtlContext, DWORD dwPropId, void *pvData, DWORD *pcbData);
  WINIMPM DWORD WINAPI CertEnumCTLContextProperties (PCCTL_CONTEXT pCtlContext, DWORD dwPropId);
  WINIMPM PCCTL_CONTEXT WINAPI CertEnumCTLsInStore (HCERTSTORE hCertStore, PCCTL_CONTEXT pPrevCtlContext);
  WINIMPM PCTL_ENTRY WINAPI CertFindSubjectInCTL (DWORD dwEncodingType, DWORD dwSubjectType, void *pvSubject, PCCTL_CONTEXT pCtlContext, DWORD dwFlags);
  WINIMPM PCCTL_CONTEXT WINAPI CertFindCTLInStore (HCERTSTORE hCertStore, DWORD dwMsgAndCertEncodingType, DWORD dwFindFlags, DWORD dwFindType, const void *pvFindPara, PCCTL_CONTEXT pPrevCtlContext);

#define CTL_FIND_ANY 0
#define CTL_FIND_SHA1_HASH 1
#define CTL_FIND_MD5_HASH 2
#define CTL_FIND_USAGE 3
#define CTL_FIND_SUBJECT 4
#define CTL_FIND_EXISTING 5

#define CTL_FIND_SAME_USAGE_FLAG 0x1

#define CTL_FIND_NO_LIST_ID_CBDATA 0xffffffff
#define CTL_FIND_NO_SIGNER_PTR ((PCERT_INFO) -1)

#define CERT_STORE_CTRL_RESYNC 1
#define CERT_STORE_CTRL_NOTIFY_CHANGE 2
#define CERT_STORE_CTRL_COMMIT 3
#define CERT_STORE_CTRL_AUTO_RESYNC 4
#define CERT_STORE_CTRL_CANCEL_NOTIFY 5

#define CERT_STORE_CTRL_INHIBIT_DUPLICATE_HANDLE_FLAG 0x1

#define CERT_STORE_CTRL_COMMIT_FORCE_FLAG 0x1
#define CERT_STORE_CTRL_COMMIT_CLEAR_FLAG 0x2

#define CERT_STORE_LOCALIZED_NAME_PROP_ID 0x1000

#define CERT_CREATE_CONTEXT_NOCOPY_FLAG 0x1
#define CERT_CREATE_CONTEXT_SORTED_FLAG 0x2
#define CERT_CREATE_CONTEXT_NO_HCRYPTMSG_FLAG 0x4
#define CERT_CREATE_CONTEXT_NO_ENTRY_FLAG 0x8

#define CERT_PHYSICAL_STORE_ADD_ENABLE_FLAG 0x1
#define CERT_PHYSICAL_STORE_OPEN_DISABLE_FLAG 0x2
#define CERT_PHYSICAL_STORE_REMOTE_OPEN_DISABLE_FLAG 0x4
#define CERT_PHYSICAL_STORE_INSERT_COMPUTER_NAME_ENABLE_FLAG 0x8

  typedef struct _CTL_FIND_USAGE_PARA {
    DWORD cbSize;
    CTL_USAGE SubjectUsage;
    CRYPT_DATA_BLOB ListIdentifier;
    PCERT_INFO pSigner;
  } CTL_FIND_USAGE_PARA,*PCTL_FIND_USAGE_PARA;

  typedef struct _CTL_FIND_SUBJECT_PARA {
    DWORD cbSize;
    PCTL_FIND_USAGE_PARA pUsagePara;
    DWORD dwSubjectType;
    void *pvSubject;
  } CTL_FIND_SUBJECT_PARA,*PCTL_FIND_SUBJECT_PARA;

  typedef WINBOOL (WINAPI *PFN_CERT_CREATE_CONTEXT_SORT_FUNC) (DWORD cbTotalEncoded, DWORD cbRemainEncoded, DWORD cEntry, void *pvSort);

  typedef struct _CERT_CREATE_CONTEXT_PARA {
    DWORD cbSize;
    PFN_CRYPT_FREE pfnFree;
    void *pvFree;
    PFN_CERT_CREATE_CONTEXT_SORT_FUNC pfnSort;
    void *pvSort;
  } CERT_CREATE_CONTEXT_PARA,*PCERT_CREATE_CONTEXT_PARA;

  typedef struct _CERT_SYSTEM_STORE_INFO {
    DWORD cbSize;
  } CERT_SYSTEM_STORE_INFO,*PCERT_SYSTEM_STORE_INFO;

  typedef struct _CERT_PHYSICAL_STORE_INFO {
    DWORD cbSize;
    LPSTR pszOpenStoreProvider;
    DWORD dwOpenEncodingType;
    DWORD dwOpenFlags;
    CRYPT_DATA_BLOB OpenParameters;
    DWORD dwFlags;
    DWORD dwPriority;
  } CERT_PHYSICAL_STORE_INFO,*PCERT_PHYSICAL_STORE_INFO;

  WINIMPM WINBOOL WINAPI CertAddEncodedCTLToStore (HCERTSTORE hCertStore, DWORD dwMsgAndCertEncodingType, const BYTE *pbCtlEncoded, DWORD cbCtlEncoded, DWORD dwAddDisposition, PCCTL_CONTEXT *ppCtlContext);
  WINIMPM WINBOOL WINAPI CertAddCTLContextToStore (HCERTSTORE hCertStore, PCCTL_CONTEXT pCtlContext, DWORD dwAddDisposition, PCCTL_CONTEXT *ppStoreContext);
  WINIMPM WINBOOL WINAPI CertSerializeCTLStoreElement (PCCTL_CONTEXT pCtlContext, DWORD dwFlags, BYTE *pbElement, DWORD *pcbElement);
  WINIMPM WINBOOL WINAPI CertDeleteCTLFromStore (PCCTL_CONTEXT pCtlContext);
  WINIMPM WINBOOL WINAPI CertAddCertificateLinkToStore (HCERTSTORE hCertStore, PCCERT_CONTEXT pCertContext, DWORD dwAddDisposition, PCCERT_CONTEXT *ppStoreContext);
  WINIMPM WINBOOL WINAPI CertAddCRLLinkToStore (HCERTSTORE hCertStore, PCCRL_CONTEXT pCrlContext, DWORD dwAddDisposition, PCCRL_CONTEXT *ppStoreContext);
  WINIMPM WINBOOL WINAPI CertAddCTLLinkToStore (HCERTSTORE hCertStore, PCCTL_CONTEXT pCtlContext, DWORD dwAddDisposition, PCCTL_CONTEXT *ppStoreContext);
  WINIMPM WINBOOL WINAPI CertAddStoreToCollection (HCERTSTORE hCollectionStore, HCERTSTORE hSiblingStore, DWORD dwUpdateFlags, DWORD dwPriority);
  WINIMPM void WINAPI CertRemoveStoreFromCollection (HCERTSTORE hCollectionStore, HCERTSTORE hSiblingStore);
  WINIMPM WINBOOL WINAPI CertControlStore (HCERTSTORE hCertStore, DWORD dwFlags, DWORD dwCtrlType, void const *pvCtrlPara);
  WINIMPM WINBOOL WINAPI CertSetStoreProperty (HCERTSTORE hCertStore, DWORD dwPropId, DWORD dwFlags, const void *pvData);
  WINIMPM WINBOOL WINAPI CertGetStoreProperty (HCERTSTORE hCertStore, DWORD dwPropId, void *pvData, DWORD *pcbData);
  WINIMPM const void *WINAPI CertCreateContext (DWORD dwContextType, DWORD dwEncodingType, const BYTE *pbEncoded, DWORD cbEncoded, DWORD dwFlags, PCERT_CREATE_CONTEXT_PARA pCreatePara);
  WINIMPM WINBOOL WINAPI CertRegisterSystemStore (const void *pvSystemStore, DWORD dwFlags, PCERT_SYSTEM_STORE_INFO pStoreInfo, void *pvReserved);
  WINIMPM WINBOOL WINAPI CertRegisterPhysicalStore (const void *pvSystemStore, DWORD dwFlags, LPCWSTR pwszStoreName, PCERT_PHYSICAL_STORE_INFO pStoreInfo, void *pvReserved);
  WINIMPM WINBOOL WINAPI CertUnregisterSystemStore (const void *pvSystemStore, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI CertUnregisterPhysicalStore (const void *pvSystemStore, DWORD dwFlags, LPCWSTR pwszStoreName);

  typedef WINBOOL (WINAPI *PFN_CERT_ENUM_SYSTEM_STORE_LOCATION) (LPCWSTR pwszStoreLocation, DWORD dwFlags, void *pvReserved, void *pvArg);
  typedef WINBOOL (WINAPI *PFN_CERT_ENUM_SYSTEM_STORE) (const void *pvSystemStore, DWORD dwFlags, PCERT_SYSTEM_STORE_INFO pStoreInfo, void *pvReserved, void *pvArg);
  typedef WINBOOL (WINAPI *PFN_CERT_ENUM_PHYSICAL_STORE) (const void *pvSystemStore, DWORD dwFlags, LPCWSTR pwszStoreName, PCERT_PHYSICAL_STORE_INFO pStoreInfo, void *pvReserved, void *pvArg);

#define CERT_PHYSICAL_STORE_PREDEFINED_ENUM_FLAG 0x1

#define CERT_PHYSICAL_STORE_DEFAULT_NAME L".Default"
#define CERT_PHYSICAL_STORE_GROUP_POLICY_NAME L".GroupPolicy"
#define CERT_PHYSICAL_STORE_LOCAL_MACHINE_NAME L".LocalMachine"
#define CERT_PHYSICAL_STORE_DS_USER_CERTIFICATE_NAME L".UserCertificate"
#define CERT_PHYSICAL_STORE_LOCAL_MACHINE_GROUP_POLICY_NAME L".LocalMachineGroupPolicy"
#define CERT_PHYSICAL_STORE_ENTERPRISE_NAME L".Enterprise"
#define CERT_PHYSICAL_STORE_AUTH_ROOT_NAME L".AuthRoot"
#define CERT_PHYSICAL_STORE_SMART_CARD_NAME L".SmartCard"

  WINIMPM WINBOOL WINAPI CertEnumSystemStoreLocation (DWORD dwFlags, void *pvArg, PFN_CERT_ENUM_SYSTEM_STORE_LOCATION pfnEnum);
  WINIMPM WINBOOL WINAPI CertEnumSystemStore (DWORD dwFlags, void *pvSystemStoreLocationPara, void *pvArg, PFN_CERT_ENUM_SYSTEM_STORE pfnEnum);
  WINIMPM WINBOOL WINAPI CertEnumPhysicalStore (const void *pvSystemStore, DWORD dwFlags, void *pvArg, PFN_CERT_ENUM_PHYSICAL_STORE pfnEnum);

#define CRYPT_OID_OPEN_SYSTEM_STORE_PROV_FUNC "CertDllOpenSystemStoreProv"
#define CRYPT_OID_REGISTER_SYSTEM_STORE_FUNC "CertDllRegisterSystemStore"
#define CRYPT_OID_UNREGISTER_SYSTEM_STORE_FUNC "CertDllUnregisterSystemStore"
#define CRYPT_OID_ENUM_SYSTEM_STORE_FUNC "CertDllEnumSystemStore"
#define CRYPT_OID_REGISTER_PHYSICAL_STORE_FUNC "CertDllRegisterPhysicalStore"
#define CRYPT_OID_UNREGISTER_PHYSICAL_STORE_FUNC "CertDllUnregisterPhysicalStore"
#define CRYPT_OID_ENUM_PHYSICAL_STORE_FUNC "CertDllEnumPhysicalStore"
#define CRYPT_OID_SYSTEM_STORE_LOCATION_VALUE_NAME L"SystemStoreLocation"

#define CMSG_TRUSTED_SIGNER_FLAG 0x1
#define CMSG_SIGNER_ONLY_FLAG 0x2
#define CMSG_USE_SIGNER_INDEX_FLAG 0x4
#define CMSG_CMS_ENCAPSULATED_CTL_FLAG 0x8000

#define CMSG_ENCODE_SORTED_CTL_FLAG 0x1
#define CMSG_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG 0x2

  WINIMPM WINBOOL WINAPI CertGetEnhancedKeyUsage (PCCERT_CONTEXT pCertContext, DWORD dwFlags, PCERT_ENHKEY_USAGE pUsage, DWORD *pcbUsage);
  WINIMPM WINBOOL WINAPI CertSetEnhancedKeyUsage (PCCERT_CONTEXT pCertContext, PCERT_ENHKEY_USAGE pUsage);
  WINIMPM WINBOOL WINAPI CertAddEnhancedKeyUsageIdentifier (PCCERT_CONTEXT pCertContext, LPCSTR pszUsageIdentifier);
  WINIMPM WINBOOL WINAPI CertRemoveEnhancedKeyUsageIdentifier (PCCERT_CONTEXT pCertContext, LPCSTR pszUsageIdentifier);
  WINIMPM WINBOOL WINAPI CertGetValidUsages (DWORD cCerts, PCCERT_CONTEXT *rghCerts, int *cNumOIDs, LPSTR *rghOIDs, DWORD *pcbOIDs);
  WINIMPM WINBOOL WINAPI CryptMsgGetAndVerifySigner (HCRYPTMSG hCryptMsg, DWORD cSignerStore, HCERTSTORE *rghSignerStore, DWORD dwFlags, PCCERT_CONTEXT *ppSigner, DWORD *pdwSignerIndex);
  WINIMPM WINBOOL WINAPI CryptMsgSignCTL (DWORD dwMsgEncodingType, BYTE *pbCtlContent, DWORD cbCtlContent, PCMSG_SIGNED_ENCODE_INFO pSignInfo, DWORD dwFlags, BYTE *pbEncoded, DWORD *pcbEncoded);
  WINIMPM WINBOOL WINAPI CryptMsgEncodeAndSignCTL (DWORD dwMsgEncodingType, PCTL_INFO pCtlInfo, PCMSG_SIGNED_ENCODE_INFO pSignInfo, DWORD dwFlags, BYTE *pbEncoded, DWORD *pcbEncoded);
  WINIMPM WINBOOL WINAPI CertFindSubjectInSortedCTL (PCRYPT_DATA_BLOB pSubjectIdentifier, PCCTL_CONTEXT pCtlContext, DWORD dwFlags, void *pvReserved, PCRYPT_DER_BLOB pEncodedAttributes);
  WINIMPM WINBOOL WINAPI CertEnumSubjectInSortedCTL (PCCTL_CONTEXT pCtlContext, void **ppvNextSubject, PCRYPT_DER_BLOB pSubjectIdentifier, PCRYPT_DER_BLOB pEncodedAttributes);

  typedef struct _CTL_VERIFY_USAGE_PARA {
    DWORD cbSize;
    CRYPT_DATA_BLOB ListIdentifier;
    DWORD cCtlStore;
    HCERTSTORE *rghCtlStore;
    DWORD cSignerStore;
    HCERTSTORE *rghSignerStore;
  } CTL_VERIFY_USAGE_PARA,*PCTL_VERIFY_USAGE_PARA;

  typedef struct _CTL_VERIFY_USAGE_STATUS {
    DWORD cbSize;
    DWORD dwError;
    DWORD dwFlags;
    PCCTL_CONTEXT *ppCtl;
    DWORD dwCtlEntryIndex;
    PCCERT_CONTEXT *ppSigner;
    DWORD dwSignerIndex;
  } CTL_VERIFY_USAGE_STATUS,*PCTL_VERIFY_USAGE_STATUS;

#define CERT_VERIFY_INHIBIT_CTL_UPDATE_FLAG 0x1
#define CERT_VERIFY_TRUSTED_SIGNERS_FLAG 0x2
#define CERT_VERIFY_NO_TIME_CHECK_FLAG 0x4
#define CERT_VERIFY_ALLOW_MORE_USAGE_FLAG 0x8

#define CERT_VERIFY_UPDATED_CTL_FLAG 0x1

  WINIMPM WINBOOL WINAPI CertVerifyCTLUsage (DWORD dwEncodingType, DWORD dwSubjectType, void *pvSubject, PCTL_USAGE pSubjectUsage, DWORD dwFlags, PCTL_VERIFY_USAGE_PARA pVerifyUsagePara, PCTL_VERIFY_USAGE_STATUS pVerifyUsageStatus);

  typedef struct _CERT_REVOCATION_CRL_INFO {
    DWORD cbSize;
    PCCRL_CONTEXT pBaseCrlContext;
    PCCRL_CONTEXT pDeltaCrlContext;
    PCRL_ENTRY pCrlEntry;
    WINBOOL fDeltaCrlEntry;
  } CERT_REVOCATION_CRL_INFO,*PCERT_REVOCATION_CRL_INFO;

  typedef struct _CERT_REVOCATION_CHAIN_PARA CERT_REVOCATION_CHAIN_PARA,*PCERT_REVOCATION_CHAIN_PARA;

  typedef struct _CERT_REVOCATION_PARA {
    DWORD cbSize;
    PCCERT_CONTEXT pIssuerCert;
    DWORD cCertStore;
    HCERTSTORE *rgCertStore;
    HCERTSTORE hCrlStore;
    LPFILETIME pftTimeToUse;
#ifdef CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS
    DWORD dwUrlRetrievalTimeout;
    WINBOOL fCheckFreshnessTime;
    DWORD dwFreshnessTime;
    LPFILETIME pftCurrentTime;
    PCERT_REVOCATION_CRL_INFO pCrlInfo;
    LPFILETIME pftCacheResync;
    PCERT_REVOCATION_CHAIN_PARA pChainPara;
#endif
  } CERT_REVOCATION_PARA,*PCERT_REVOCATION_PARA;

  typedef struct _CERT_REVOCATION_STATUS {
    DWORD cbSize;
    DWORD dwIndex;
    DWORD dwError;
    DWORD dwReason;
    WINBOOL fHasFreshnessTime;
    DWORD dwFreshnessTime;
  } CERT_REVOCATION_STATUS,*PCERT_REVOCATION_STATUS;

#define CERT_CONTEXT_REVOCATION_TYPE 1

#define CERT_VERIFY_REV_CHAIN_FLAG 0x1
#define CERT_VERIFY_CACHE_ONLY_BASED_REVOCATION 0x2
#define CERT_VERIFY_REV_ACCUMULATIVE_TIMEOUT_FLAG 0x4
#define CERT_VERIFY_REV_SERVER_OCSP_FLAG 0x8
#define CERT_VERIFY_REV_NO_OCSP_FAILOVER_TO_CRL_FLAG 0x10

#define CERT_UNICODE_IS_RDN_ATTRS_FLAG 0x1
#define CERT_CASE_INSENSITIVE_IS_RDN_ATTRS_FLAG 0x2

#define CRYPT_VERIFY_CERT_SIGN_SUBJECT_BLOB 1
#define CRYPT_VERIFY_CERT_SIGN_SUBJECT_CERT 2
#define CRYPT_VERIFY_CERT_SIGN_SUBJECT_CRL 3
#define CRYPT_VERIFY_CERT_SIGN_SUBJECT_OCSP_BASIC_SIGNED_RESPONSE 4

#define CRYPT_VERIFY_CERT_SIGN_ISSUER_PUBKEY 1
#define CRYPT_VERIFY_CERT_SIGN_ISSUER_CERT 2
#define CRYPT_VERIFY_CERT_SIGN_ISSUER_CHAIN 3
#define CRYPT_VERIFY_CERT_SIGN_ISSUER_NULL 4

#define CRYPT_VERIFY_CERT_SIGN_DISABLE_MD2_MD4_FLAG 0x1
#define CRYPT_VERIFY_CERT_SIGN_SET_STRONG_PROPERTIES_FLAG 0x2
#define CRYPT_VERIFY_CERT_SIGN_RETURN_STRONG_PROPERTIES_FLAG 0x4

#define CRYPT_OID_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC "CryptDllExtractEncodedSignatureParameters"
#define CRYPT_OID_SIGN_AND_ENCODE_HASH_FUNC "CryptDllSignAndEncodeHash"
#define CRYPT_OID_VERIFY_ENCODED_SIGNATURE_FUNC "CryptDllVerifyEncodedSignature"

#define CRYPT_DEFAULT_CONTEXT_AUTO_RELEASE_FLAG 0x1
#define CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG 0x2

#define CRYPT_DEFAULT_CONTEXT_CERT_SIGN_OID 1
#define CRYPT_DEFAULT_CONTEXT_MULTI_CERT_SIGN_OID 2

  typedef struct _CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO {
    CRYPT_DATA_BLOB CertSignHashCNGAlgPropData;
    CRYPT_DATA_BLOB CertIssuerPubKeyBitLengthPropData;
  } CRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO, *PCRYPT_VERIFY_CERT_SIGN_STRONG_PROPERTIES_INFO;

  typedef WINBOOL (WINAPI *PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC) (DWORD dwCertEncodingType, PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm, void **ppvDecodedSignPara, LPWSTR *ppwszCNGHashAlgid);
  typedef WINBOOL (WINAPI *PFN_CRYPT_SIGN_AND_ENCODE_HASH_FUNC) (NCRYPT_KEY_HANDLE hKey, DWORD dwCertEncodingType, PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm, void *pvDecodedSignPara, LPCWSTR pwszCNGPubKeyAlgid, LPCWSTR pwszCNGHashAlgid, BYTE *pbComputedHash, DWORD cbComputedHash, BYTE *pbSignature, DWORD *pcbSignature);
  typedef WINBOOL (WINAPI *PFN_CRYPT_VERIFY_ENCODED_SIGNATURE_FUNC) (DWORD dwCertEncodingType, PCERT_PUBLIC_KEY_INFO pPubKeyInfo, PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm, void *pvDecodedSignPara, LPCWSTR pwszCNGPubKeyAlgid, LPCWSTR pwszCNGHashAlgid, BYTE *pbComputedHash, DWORD cbComputedHash, BYTE *pbSignature, DWORD cbSignature);

  typedef void *HCRYPTDEFAULTCONTEXT;

  typedef struct _CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA {
    DWORD cOID;
    LPSTR *rgpszOID;
  } CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA,*PCRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA;

  WINIMPM WINBOOL WINAPI CertVerifyRevocation (DWORD dwEncodingType, DWORD dwRevType, DWORD cContext, PVOID rgpvContext[], DWORD dwFlags, PCERT_REVOCATION_PARA pRevPara, PCERT_REVOCATION_STATUS pRevStatus);
  WINBOOL WINAPI CertCompareIntegerBlob (PCRYPT_INTEGER_BLOB pInt1, PCRYPT_INTEGER_BLOB pInt2);
  WINIMPM WINBOOL WINAPI CertCompareCertificate (DWORD dwCertEncodingType, PCERT_INFO pCertId1, PCERT_INFO pCertId2);
  WINIMPM WINBOOL WINAPI CertCompareCertificateName (DWORD dwCertEncodingType, PCERT_NAME_BLOB pCertName1, PCERT_NAME_BLOB pCertName2);
  WINIMPM WINBOOL WINAPI CertIsRDNAttrsInCertificateName (DWORD dwCertEncodingType, DWORD dwFlags, PCERT_NAME_BLOB pCertName, PCERT_RDN pRDN);
  WINIMPM WINBOOL WINAPI CertComparePublicKeyInfo (DWORD dwCertEncodingType, PCERT_PUBLIC_KEY_INFO pPublicKey1, PCERT_PUBLIC_KEY_INFO pPublicKey2);
  WINIMPM DWORD WINAPI CertGetPublicKeyLength (DWORD dwCertEncodingType, PCERT_PUBLIC_KEY_INFO pPublicKey);
  WINIMPM WINBOOL WINAPI CryptVerifyCertificateSignature (HCRYPTPROV_LEGACY hCryptProv, DWORD dwCertEncodingType, const BYTE *pbEncoded, DWORD cbEncoded, PCERT_PUBLIC_KEY_INFO pPublicKey);
  WINIMPM WINBOOL WINAPI CryptVerifyCertificateSignatureEx (HCRYPTPROV_LEGACY hCryptProv, DWORD dwCertEncodingType, DWORD dwSubjectType, void *pvSubject, DWORD dwIssuerType, void *pvIssuer, DWORD dwFlags, void *pvExtra);
  WINIMPM WINBOOL WINAPI CertIsStrongHashToSign (PCCERT_STRONG_SIGN_PARA pStrongSignPara, LPCWSTR pwszCNGHashAlgid, PCCERT_CONTEXT pSigningCert);
  WINIMPM WINBOOL WINAPI CryptHashToBeSigned (HCRYPTPROV_LEGACY hCryptProv, DWORD dwCertEncodingType, const BYTE *pbEncoded, DWORD cbEncoded, BYTE *pbComputedHash, DWORD *pcbComputedHash);
  WINIMPM WINBOOL WINAPI CryptHashCertificate (HCRYPTPROV_LEGACY hCryptProv, ALG_ID Algid, DWORD dwFlags, const BYTE *pbEncoded, DWORD cbEncoded, BYTE *pbComputedHash, DWORD *pcbComputedHash);
#if NTDDI_VERSION >= NTDDI_VISTA
  WINIMPM WINBOOL WINAPI CryptHashCertificate2 (LPCWSTR pwszCNGHashAlgid, DWORD dwFlags, void *pvReserved, const BYTE *pbEncoded, DWORD cbEncoded, BYTE *pbComputedHash, DWORD *pcbComputedHash);
#endif
  WINIMPM WINBOOL WINAPI CryptSignCertificate (HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey, DWORD dwKeySpec, DWORD dwCertEncodingType, const BYTE *pbEncodedToBeSigned, DWORD cbEncodedToBeSigned, PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm, const void *pvHashAuxInfo, BYTE *pbSignature, DWORD *pcbSignature);
  WINIMPM WINBOOL WINAPI CryptSignAndEncodeCertificate (HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey, DWORD dwKeySpec, DWORD dwCertEncodingType, LPCSTR lpszStructType, const void *pvStructInfo, PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm, const void *pvHashAuxInfo, BYTE *pbEncoded, DWORD *pcbEncoded);
  WINIMPM LONG WINAPI CertVerifyTimeValidity (LPFILETIME pTimeToVerify, PCERT_INFO pCertInfo);
  WINIMPM LONG WINAPI CertVerifyCRLTimeValidity (LPFILETIME pTimeToVerify, PCRL_INFO pCrlInfo);
  WINIMPM WINBOOL WINAPI CertVerifyValidityNesting (PCERT_INFO pSubjectInfo, PCERT_INFO pIssuerInfo);
  WINIMPM WINBOOL WINAPI CertVerifyCRLRevocation (DWORD dwCertEncodingType, PCERT_INFO pCertId, DWORD cCrlInfo, PCRL_INFO rgpCrlInfo[]);
  WINIMPM LPCSTR WINAPI CertAlgIdToOID (DWORD dwAlgId);
  WINIMPM DWORD WINAPI CertOIDToAlgId (LPCSTR pszObjId);
  WINIMPM PCERT_EXTENSION WINAPI CertFindExtension (LPCSTR pszObjId, DWORD cExtensions, CERT_EXTENSION rgExtensions[]);
  WINIMPM PCRYPT_ATTRIBUTE WINAPI CertFindAttribute (LPCSTR pszObjId, DWORD cAttr, CRYPT_ATTRIBUTE rgAttr[]);
  WINIMPM PCERT_RDN_ATTR WINAPI CertFindRDNAttr (LPCSTR pszObjId, PCERT_NAME_INFO pName);
  WINIMPM WINBOOL WINAPI CertGetIntendedKeyUsage (DWORD dwCertEncodingType, PCERT_INFO pCertInfo, BYTE *pbKeyUsage, DWORD cbKeyUsage);
  WINIMPM WINBOOL WINAPI CryptInstallDefaultContext (HCRYPTPROV hCryptProv, DWORD dwDefaultType, const void *pvDefaultPara, DWORD dwFlags, void *pvReserved, HCRYPTDEFAULTCONTEXT *phDefaultContext);
  WINIMPM WINBOOL WINAPI CryptUninstallDefaultContext (HCRYPTDEFAULTCONTEXT hDefaultContext, DWORD dwFlags, void *pvReserved);
  WINIMPM WINBOOL WINAPI CryptExportPublicKeyInfo (HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey, DWORD dwKeySpec, DWORD dwCertEncodingType, PCERT_PUBLIC_KEY_INFO pInfo, DWORD *pcbInfo);
  WINIMPM WINBOOL WINAPI CryptExportPublicKeyInfoEx (HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey, DWORD dwKeySpec, DWORD dwCertEncodingType, LPSTR pszPublicKeyObjId, DWORD dwFlags, void *pvAuxInfo, PCERT_PUBLIC_KEY_INFO pInfo, DWORD *pcbInfo);

#define CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FUNC "CryptDllExportPublicKeyInfoEx"
#define CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC "CryptDllExportPublicKeyInfoEx2"

  typedef WINBOOL (WINAPI *PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC) (NCRYPT_KEY_HANDLE hNCryptKey, DWORD dwCertEncodingType, LPSTR pszPublicKeyObjId, DWORD dwFlags, void *pvAuxInfo, PCERT_PUBLIC_KEY_INFO pInfo, DWORD *pcbInfo);

#if NTDDI_VERSION >= NTDDI_WIN7
#define CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC "CryptDllExportPublicKeyInfoFromBCryptKeyHandle"

  typedef WINBOOL (WINAPI *PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC) (BCRYPT_KEY_HANDLE hBCryptKey, DWORD dwCertEncodingType, LPSTR pszPublicKeyObjId, DWORD dwFlags, void *pvAuxInfo, PCERT_PUBLIC_KEY_INFO pInfo, DWORD *pcbInfo);

  WINIMPM WINBOOL WINAPI CryptExportPublicKeyInfoFromBCryptKeyHandle (BCRYPT_KEY_HANDLE hBCryptKey, DWORD dwCertEncodingType, LPSTR pszPublicKeyObjId, DWORD dwFlags, void *pvAuxInfo, PCERT_PUBLIC_KEY_INFO pInfo, DWORD *pcbInfo);
#endif

#define CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_FUNC "CryptDllImportPublicKeyInfoEx"
#define CRYPT_OID_IMPORT_PRIVATE_KEY_INFO_FUNC "CryptDllImportPrivateKeyInfoEx"
#define CRYPT_OID_EXPORT_PRIVATE_KEY_INFO_FUNC "CryptDllExportPrivateKeyInfoEx"

#define CRYPT_ACQUIRE_CACHE_FLAG 0x1
#define CRYPT_ACQUIRE_USE_PROV_INFO_FLAG 0x2
#define CRYPT_ACQUIRE_COMPARE_KEY_FLAG 0x4
#define CRYPT_ACQUIRE_NO_HEALING 0x8
#define CRYPT_ACQUIRE_SILENT_FLAG 0x40
#define CRYPT_ACQUIRE_WINDOW_HANDLE_FLAG 0x80

#define CRYPT_ACQUIRE_NCRYPT_KEY_FLAGS_MASK 0x70000
#define CRYPT_ACQUIRE_ALLOW_NCRYPT_KEY_FLAG 0x10000
#define CRYPT_ACQUIRE_PREFER_NCRYPT_KEY_FLAG 0x20000
#define CRYPT_ACQUIRE_ONLY_NCRYPT_KEY_FLAG 0x40000

#define CRYPT_FIND_USER_KEYSET_FLAG 0x1
#define CRYPT_FIND_MACHINE_KEYSET_FLAG 0x2
#define CRYPT_FIND_SILENT_KEYSET_FLAG 0x40

#define CRYPT_DELETE_KEYSET CRYPT_DELETEKEYSET

  typedef WINBOOL (WINAPI *PFN_IMPORT_PRIV_KEY_FUNC) (HCRYPTPROV hCryptProv, CRYPT_PRIVATE_KEY_INFO *pPrivateKeyInfo, DWORD dwFlags, void *pvAuxInfo);
  typedef WINBOOL (WINAPI *PFN_EXPORT_PRIV_KEY_FUNC) (HCRYPTPROV hCryptProv, DWORD dwKeySpec, LPSTR pszPrivateKeyObjId, DWORD dwFlags, void *pvAuxInfo, CRYPT_PRIVATE_KEY_INFO *pPrivateKeyInfo, DWORD *pcbPrivateKeyInfo);

#define CertRDNValueToStr __MINGW_NAME_AW(CertRDNValueToStr)
#define CertNameToStr __MINGW_NAME_AW(CertNameToStr)

  WINIMPM WINBOOL WINAPI CryptImportPublicKeyInfo (HCRYPTPROV hCryptProv, DWORD dwCertEncodingType, PCERT_PUBLIC_KEY_INFO pInfo, HCRYPTKEY *phKey);
  WINIMPM WINBOOL WINAPI CryptImportPublicKeyInfoEx (HCRYPTPROV hCryptProv, DWORD dwCertEncodingType, PCERT_PUBLIC_KEY_INFO pInfo, ALG_ID aiKeyAlg, DWORD dwFlags, void *pvAuxInfo, HCRYPTKEY *phKey);

#if NTDDI_VERSION >= NTDDI_VISTA
#define CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC "CryptDllImportPublicKeyInfoEx2"

  typedef WINBOOL (WINAPI *PFN_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC) (DWORD dwCertEncodingType, PCERT_PUBLIC_KEY_INFO pInfo, DWORD dwFlags, void *pvAuxInfo, BCRYPT_KEY_HANDLE *phKey);

  WINIMPM WINBOOL WINAPI CryptImportPublicKeyInfoEx2 (DWORD dwCertEncodingType, PCERT_PUBLIC_KEY_INFO pInfo, DWORD dwFlags, void *pvAuxInfo, BCRYPT_KEY_HANDLE *phKey);
#endif
  WINIMPM WINBOOL WINAPI CryptAcquireCertificatePrivateKey (PCCERT_CONTEXT pCert, DWORD dwFlags, void *pvParameters, HCRYPTPROV_OR_NCRYPT_KEY_HANDLE *phCryptProvOrNCryptKey, DWORD *pdwKeySpec, WINBOOL *pfCallerFreeProvOrNCryptKey);
  WINIMPM WINBOOL WINAPI CryptFindCertificateKeyProvInfo (PCCERT_CONTEXT pCert, DWORD dwFlags, void *pvReserved);
  WINIMPM WINBOOL WINAPI CryptImportPKCS8 (CRYPT_PKCS8_IMPORT_PARAMS sPrivateKeyAndParams, DWORD dwFlags, HCRYPTPROV *phCryptProv, void *pvAuxInfo);
  WINIMPM WINBOOL WINAPI CryptExportPKCS8 (HCRYPTPROV hCryptProv, DWORD dwKeySpec, LPSTR pszPrivateKeyObjId, DWORD dwFlags, void *pvAuxInfo, BYTE *pbPrivateKeyBlob, DWORD *pcbPrivateKeyBlob);
  WINIMPM WINBOOL WINAPI CryptExportPKCS8Ex (CRYPT_PKCS8_EXPORT_PARAMS *psExportParams, DWORD dwFlags, void *pvAuxInfo, BYTE *pbPrivateKeyBlob, DWORD *pcbPrivateKeyBlob);
  WINIMPM WINBOOL WINAPI CryptHashPublicKeyInfo (HCRYPTPROV_LEGACY hCryptProv, ALG_ID Algid, DWORD dwFlags, DWORD dwCertEncodingType, PCERT_PUBLIC_KEY_INFO pInfo, BYTE *pbComputedHash, DWORD *pcbComputedHash);
  WINIMPM DWORD WINAPI CertRDNValueToStrA (DWORD dwValueType, PCERT_RDN_VALUE_BLOB pValue, LPSTR psz, DWORD csz);
  WINIMPM DWORD WINAPI CertRDNValueToStrW (DWORD dwValueType, PCERT_RDN_VALUE_BLOB pValue, LPWSTR psz, DWORD csz);
  WINIMPM DWORD WINAPI CertNameToStrA (DWORD dwCertEncodingType, PCERT_NAME_BLOB pName, DWORD dwStrType, LPSTR psz, DWORD csz);
  WINIMPM DWORD WINAPI CertNameToStrW (DWORD dwCertEncodingType, PCERT_NAME_BLOB pName, DWORD dwStrType, LPWSTR psz, DWORD csz);


#define CERT_SIMPLE_NAME_STR 1
#define CERT_OID_NAME_STR 2
#define CERT_X500_NAME_STR 3
#define CERT_XML_NAME_STR 4

#define CERT_NAME_STR_DISABLE_IE4_UTF8_FLAG 0x10000
#define CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG 0x20000
#define CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG 0x40000
#define CERT_NAME_STR_FORCE_UTF8_DIR_STR_FLAG 0x80000
#define CERT_NAME_STR_FORWARD_FLAG 0x1000000
#define CERT_NAME_STR_REVERSE_FLAG 0x2000000
#define CERT_NAME_STR_COMMA_FLAG 0x4000000
#define CERT_NAME_STR_CRLF_FLAG 0x8000000
#define CERT_NAME_STR_NO_QUOTING_FLAG 0x10000000
#define CERT_NAME_STR_NO_PLUS_FLAG 0x20000000
#define CERT_NAME_STR_SEMICOLON_FLAG 0x40000000
#define CERT_NAME_STR_DISABLE_UTF8_DIR_STR_FLAG 0x100000
#define CERT_NAME_STR_ENABLE_PUNYCODE_FLAG 0x200000

#define CertStrToName __MINGW_NAME_AW(CertStrToName)
#define CertGetNameString __MINGW_NAME_AW(CertGetNameString)

  WINIMPM WINBOOL WINAPI CertStrToNameA (DWORD dwCertEncodingType, LPCSTR pszX500, DWORD dwStrType, void *pvReserved, BYTE *pbEncoded, DWORD *pcbEncoded, LPCSTR *ppszError);
  WINIMPM WINBOOL WINAPI CertStrToNameW (DWORD dwCertEncodingType, LPCWSTR pszX500, DWORD dwStrType, void *pvReserved, BYTE *pbEncoded, DWORD *pcbEncoded, LPCWSTR *ppszError);
  WINIMPM DWORD WINAPI CertGetNameStringA (PCCERT_CONTEXT pCertContext, DWORD dwType, DWORD dwFlags, void *pvTypePara, LPSTR pszNameString, DWORD cchNameString);
  WINIMPM DWORD WINAPI CertGetNameStringW (PCCERT_CONTEXT pCertContext, DWORD dwType, DWORD dwFlags, void *pvTypePara, LPWSTR pszNameString, DWORD cchNameString);

#define CERT_NAME_EMAIL_TYPE 1
#define CERT_NAME_RDN_TYPE 2
#define CERT_NAME_ATTR_TYPE 3
#define CERT_NAME_SIMPLE_DISPLAY_TYPE 4
#define CERT_NAME_FRIENDLY_DISPLAY_TYPE 5
#define CERT_NAME_DNS_TYPE 6
#define CERT_NAME_URL_TYPE 7
#define CERT_NAME_UPN_TYPE 8

#define CERT_NAME_ISSUER_FLAG 0x1
#define CERT_NAME_DISABLE_IE4_UTF8_FLAG 0x10000

#define CERT_NAME_SEARCH_ALL_NAMES_FLAG 0x2

  typedef PCCERT_CONTEXT (WINAPI *PFN_CRYPT_GET_SIGNER_CERTIFICATE) (void *pvGetArg, DWORD dwCertEncodingType, PCERT_INFO pSignerId, HCERTSTORE hMsgCertStore);

  typedef struct _CRYPT_SIGN_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgEncodingType;
    PCCERT_CONTEXT pSigningCert;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
    DWORD cMsgCert;
    PCCERT_CONTEXT *rgpMsgCert;
    DWORD cMsgCrl;
    PCCRL_CONTEXT *rgpMsgCrl;
    DWORD cAuthAttr;
    PCRYPT_ATTRIBUTE rgAuthAttr;
    DWORD cUnauthAttr;
    PCRYPT_ATTRIBUTE rgUnauthAttr;
    DWORD dwFlags;
    DWORD dwInnerContentType;
#ifdef CRYPT_SIGN_MESSAGE_PARA_HAS_CMS_FIELDS
    CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;
    void *pvHashEncryptionAuxInfo;
#endif
  } CRYPT_SIGN_MESSAGE_PARA,*PCRYPT_SIGN_MESSAGE_PARA;

#define CRYPT_MESSAGE_BARE_CONTENT_OUT_FLAG 0x1
#define CRYPT_MESSAGE_ENCAPSULATED_CONTENT_OUT_FLAG 0x2
#define CRYPT_MESSAGE_KEYID_SIGNER_FLAG 0x4
#define CRYPT_MESSAGE_SILENT_KEYSET_FLAG 0x40

  typedef struct _CRYPT_VERIFY_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgAndCertEncodingType;
    HCRYPTPROV_LEGACY hCryptProv;
    PFN_CRYPT_GET_SIGNER_CERTIFICATE pfnGetSignerCertificate;
    void *pvGetArg;
#ifdef CRYPT_VERIFY_MESSAGE_PARA_HAS_EXTRA_FIELDS
    PCCERT_STRONG_SIGN_PARA pStrongSignPara;
#endif
  } CRYPT_VERIFY_MESSAGE_PARA,*PCRYPT_VERIFY_MESSAGE_PARA;

  typedef struct _CRYPT_ENCRYPT_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgEncodingType;
    HCRYPTPROV_LEGACY hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER ContentEncryptionAlgorithm;
    void *pvEncryptionAuxInfo;
    DWORD dwFlags;
    DWORD dwInnerContentType;
  } CRYPT_ENCRYPT_MESSAGE_PARA,*PCRYPT_ENCRYPT_MESSAGE_PARA;

#define CRYPT_MESSAGE_KEYID_RECIPIENT_FLAG 0x4

  typedef struct _CRYPT_DECRYPT_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgAndCertEncodingType;
    DWORD cCertStore;
    HCERTSTORE *rghCertStore;
#ifdef CRYPT_DECRYPT_MESSAGE_PARA_HAS_EXTRA_FIELDS
    DWORD dwFlags;
#endif
  } CRYPT_DECRYPT_MESSAGE_PARA,*PCRYPT_DECRYPT_MESSAGE_PARA;

  typedef struct _CRYPT_HASH_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgEncodingType;
    HCRYPTPROV_LEGACY hCryptProv;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
  } CRYPT_HASH_MESSAGE_PARA,*PCRYPT_HASH_MESSAGE_PARA;

  typedef struct _CRYPT_KEY_SIGN_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgAndCertEncodingType;
    __C89_NAMELESS union {
      HCRYPTPROV hCryptProv;
      NCRYPT_KEY_HANDLE hNCryptKey;
    };
    DWORD dwKeySpec;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    void *pvHashAuxInfo;
    CRYPT_ALGORITHM_IDENTIFIER PubKeyAlgorithm;
  } CRYPT_KEY_SIGN_MESSAGE_PARA,*PCRYPT_KEY_SIGN_MESSAGE_PARA;

  typedef struct _CRYPT_KEY_VERIFY_MESSAGE_PARA {
    DWORD cbSize;
    DWORD dwMsgEncodingType;
    HCRYPTPROV_LEGACY hCryptProv;
  } CRYPT_KEY_VERIFY_MESSAGE_PARA,*PCRYPT_KEY_VERIFY_MESSAGE_PARA;

  typedef struct _CERT_CHAIN {
    DWORD cCerts;
    PCERT_BLOB certs;
    CRYPT_KEY_PROV_INFO keyLocatorInfo;
  } CERT_CHAIN,*PCERT_CHAIN;

#define CertOpenSystemStore __MINGW_NAME_AW(CertOpenSystemStore)
#define CertAddEncodedCertificateToSystemStore __MINGW_NAME_AW(CertAddEncodedCertificateToSystemStore)

  WINIMPM WINBOOL WINAPI CryptSignMessage (PCRYPT_SIGN_MESSAGE_PARA pSignPara, WINBOOL fDetachedSignature, DWORD cToBeSigned, const BYTE *rgpbToBeSigned[], DWORD rgcbToBeSigned[], BYTE *pbSignedBlob, DWORD *pcbSignedBlob);
  WINIMPM WINBOOL WINAPI CryptVerifyMessageSignature (PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara, DWORD dwSignerIndex, const BYTE *pbSignedBlob, DWORD cbSignedBlob, BYTE *pbDecoded, DWORD *pcbDecoded, PCCERT_CONTEXT *ppSignerCert);
  WINIMPM LONG WINAPI CryptGetMessageSignerCount (DWORD dwMsgEncodingType, const BYTE *pbSignedBlob, DWORD cbSignedBlob);
  WINIMPM HCERTSTORE WINAPI CryptGetMessageCertificates (DWORD dwMsgAndCertEncodingType, HCRYPTPROV_LEGACY hCryptProv, DWORD dwFlags, const BYTE *pbSignedBlob, DWORD cbSignedBlob);
  WINIMPM WINBOOL WINAPI CryptVerifyDetachedMessageSignature (PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara, DWORD dwSignerIndex, const BYTE *pbDetachedSignBlob, DWORD cbDetachedSignBlob, DWORD cToBeSigned, const BYTE *rgpbToBeSigned[], DWORD rgcbToBeSigned[], PCCERT_CONTEXT *ppSignerCert);
  WINIMPM WINBOOL WINAPI CryptEncryptMessage (PCRYPT_ENCRYPT_MESSAGE_PARA pEncryptPara, DWORD cRecipientCert, PCCERT_CONTEXT rgpRecipientCert[], const BYTE *pbToBeEncrypted, DWORD cbToBeEncrypted, BYTE *pbEncryptedBlob, DWORD *pcbEncryptedBlob);
  WINIMPM WINBOOL WINAPI CryptDecryptMessage (PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara, const BYTE *pbEncryptedBlob, DWORD cbEncryptedBlob, BYTE *pbDecrypted, DWORD *pcbDecrypted, PCCERT_CONTEXT *ppXchgCert);
  WINIMPM WINBOOL WINAPI CryptSignAndEncryptMessage (PCRYPT_SIGN_MESSAGE_PARA pSignPara, PCRYPT_ENCRYPT_MESSAGE_PARA pEncryptPara, DWORD cRecipientCert, PCCERT_CONTEXT rgpRecipientCert[], const BYTE *pbToBeSignedAndEncrypted, DWORD cbToBeSignedAndEncrypted, BYTE *pbSignedAndEncryptedBlob, DWORD *pcbSignedAndEncryptedBlob);
  WINIMPM WINBOOL WINAPI CryptDecryptAndVerifyMessageSignature (PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara, PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara, DWORD dwSignerIndex, const BYTE *pbEncryptedBlob, DWORD cbEncryptedBlob, BYTE *pbDecrypted, DWORD *pcbDecrypted, PCCERT_CONTEXT *ppXchgCert, PCCERT_CONTEXT *ppSignerCert);
  WINIMPM WINBOOL WINAPI CryptDecodeMessage (DWORD dwMsgTypeFlags, PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara, PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara, DWORD dwSignerIndex, const BYTE *pbEncodedBlob, DWORD cbEncodedBlob, DWORD dwPrevInnerContentType, DWORD *pdwMsgType, DWORD *pdwInnerContentType, BYTE *pbDecoded, DWORD *pcbDecoded, PCCERT_CONTEXT *ppXchgCert, PCCERT_CONTEXT *ppSignerCert);
  WINIMPM WINBOOL WINAPI CryptHashMessage (PCRYPT_HASH_MESSAGE_PARA pHashPara, WINBOOL fDetachedHash, DWORD cToBeHashed, const BYTE *rgpbToBeHashed[], DWORD rgcbToBeHashed[], BYTE *pbHashedBlob, DWORD *pcbHashedBlob, BYTE *pbComputedHash, DWORD *pcbComputedHash);
  WINIMPM WINBOOL WINAPI CryptVerifyMessageHash (PCRYPT_HASH_MESSAGE_PARA pHashPara, BYTE *pbHashedBlob, DWORD cbHashedBlob, BYTE *pbToBeHashed, DWORD *pcbToBeHashed, BYTE *pbComputedHash, DWORD *pcbComputedHash);
  WINIMPM WINBOOL WINAPI CryptVerifyDetachedMessageHash (PCRYPT_HASH_MESSAGE_PARA pHashPara, BYTE *pbDetachedHashBlob, DWORD cbDetachedHashBlob, DWORD cToBeHashed, const BYTE *rgpbToBeHashed[], DWORD rgcbToBeHashed[], BYTE *pbComputedHash, DWORD *pcbComputedHash);
  WINIMPM WINBOOL WINAPI CryptSignMessageWithKey (PCRYPT_KEY_SIGN_MESSAGE_PARA pSignPara, const BYTE *pbToBeSigned, DWORD cbToBeSigned, BYTE *pbSignedBlob, DWORD *pcbSignedBlob);
  WINIMPM WINBOOL WINAPI CryptVerifyMessageSignatureWithKey (PCRYPT_KEY_VERIFY_MESSAGE_PARA pVerifyPara, PCERT_PUBLIC_KEY_INFO pPublicKeyInfo, const BYTE *pbSignedBlob, DWORD cbSignedBlob, BYTE *pbDecoded, DWORD *pcbDecoded);
  WINIMPM HCERTSTORE WINAPI CertOpenSystemStoreA (HCRYPTPROV_LEGACY hProv, LPCSTR szSubsystemProtocol);
  WINIMPM HCERTSTORE WINAPI CertOpenSystemStoreW (HCRYPTPROV_LEGACY hProv, LPCWSTR szSubsystemProtocol);
  WINIMPM WINBOOL WINAPI CertAddEncodedCertificateToSystemStoreA (LPCSTR szCertStoreName, const BYTE *pbCertEncoded, DWORD cbCertEncoded);
  WINIMPM WINBOOL WINAPI CertAddEncodedCertificateToSystemStoreW (LPCWSTR szCertStoreName, const BYTE *pbCertEncoded, DWORD cbCertEncoded);
  HRESULT WINAPI FindCertsByIssuer (PCERT_CHAIN pCertChains, DWORD *pcbCertChains, DWORD *pcCertChains, BYTE *pbEncodedIssuerName, DWORD cbEncodedIssuerName, LPCWSTR pwszPurpose, DWORD dwKeySpec);
  WINIMPM WINBOOL WINAPI CryptQueryObject (DWORD dwObjectType, const void *pvObject, DWORD dwExpectedContentTypeFlags, DWORD dwExpectedFormatTypeFlags, DWORD dwFlags, DWORD *pdwMsgAndCertEncodingType, DWORD *pdwContentType, DWORD *pdwFormatType, HCERTSTORE *phCertStore, HCRYPTMSG *phMsg, const void **ppvContext);

#define CERT_QUERY_OBJECT_FILE 0x1
#define CERT_QUERY_OBJECT_BLOB 0x2

#define CERT_QUERY_CONTENT_CERT 1
#define CERT_QUERY_CONTENT_CTL 2
#define CERT_QUERY_CONTENT_CRL 3
#define CERT_QUERY_CONTENT_SERIALIZED_STORE 4
#define CERT_QUERY_CONTENT_SERIALIZED_CERT 5
#define CERT_QUERY_CONTENT_SERIALIZED_CTL 6
#define CERT_QUERY_CONTENT_SERIALIZED_CRL 7
#define CERT_QUERY_CONTENT_PKCS7_SIGNED 8
#define CERT_QUERY_CONTENT_PKCS7_UNSIGNED 9
#define CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED 10
#define CERT_QUERY_CONTENT_PKCS10 11
#define CERT_QUERY_CONTENT_PFX 12
#define CERT_QUERY_CONTENT_CERT_PAIR 13
#define CERT_QUERY_CONTENT_PFX_AND_LOAD 14

#define CERT_QUERY_CONTENT_FLAG_CERT (1 << CERT_QUERY_CONTENT_CERT)
#define CERT_QUERY_CONTENT_FLAG_CTL (1 << CERT_QUERY_CONTENT_CTL)
#define CERT_QUERY_CONTENT_FLAG_CRL (1 << CERT_QUERY_CONTENT_CRL)
#define CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE (1 << CERT_QUERY_CONTENT_SERIALIZED_STORE)
#define CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT (1 << CERT_QUERY_CONTENT_SERIALIZED_CERT)
#define CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL (1 << CERT_QUERY_CONTENT_SERIALIZED_CTL)
#define CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL (1 << CERT_QUERY_CONTENT_SERIALIZED_CRL)
#define CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED (1 << CERT_QUERY_CONTENT_PKCS7_SIGNED)
#define CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED (1 << CERT_QUERY_CONTENT_PKCS7_UNSIGNED)
#define CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED (1 << CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED)
#define CERT_QUERY_CONTENT_FLAG_PKCS10 (1 << CERT_QUERY_CONTENT_PKCS10)
#define CERT_QUERY_CONTENT_FLAG_PFX (1 << CERT_QUERY_CONTENT_PFX)
#define CERT_QUERY_CONTENT_FLAG_CERT_PAIR (1 << CERT_QUERY_CONTENT_CERT_PAIR)
#define CERT_QUERY_CONTENT_FLAG_PFX_AND_LOAD (1 << CERT_QUERY_CONTENT_PFX_AND_LOAD)

#define CERT_QUERY_CONTENT_FLAG_ALL (CERT_QUERY_CONTENT_FLAG_CERT | CERT_QUERY_CONTENT_FLAG_CTL | CERT_QUERY_CONTENT_FLAG_CRL | CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE | CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT | CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL | CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL | CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED | CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED | CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED | CERT_QUERY_CONTENT_FLAG_PKCS10 | CERT_QUERY_CONTENT_FLAG_PFX | CERT_QUERY_CONTENT_FLAG_CERT_PAIR)
#define CERT_QUERY_CONTENT_FLAG_ALL_ISSUER_CERT (CERT_QUERY_CONTENT_FLAG_CERT | CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE | CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT | CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED | CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED)

#define CERT_QUERY_FORMAT_BINARY 1
#define CERT_QUERY_FORMAT_BASE64_ENCODED 2
#define CERT_QUERY_FORMAT_ASN_ASCII_HEX_ENCODED 3

#define CERT_QUERY_FORMAT_FLAG_BINARY (1 << CERT_QUERY_FORMAT_BINARY)
#define CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED (1 << CERT_QUERY_FORMAT_BASE64_ENCODED)
#define CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED (1 << CERT_QUERY_FORMAT_ASN_ASCII_HEX_ENCODED)

#define CERT_QUERY_FORMAT_FLAG_ALL (CERT_QUERY_FORMAT_FLAG_BINARY | CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED | CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED)

  typedef HANDLE HCRYPTASYNC,*PHCRYPTASYNC;
  typedef VOID (WINAPI *PFN_CRYPT_ASYNC_PARAM_FREE_FUNC) (LPSTR pszParamOid, LPVOID pvParam);

  WINIMPM LPVOID WINAPI CryptMemAlloc (ULONG cbSize);
  WINIMPM LPVOID WINAPI CryptMemRealloc (LPVOID pv, ULONG cbSize);
  WINIMPM VOID WINAPI CryptMemFree (LPVOID pv);
  WINIMPM WINBOOL WINAPI CryptCreateAsyncHandle (DWORD dwFlags, PHCRYPTASYNC phAsync);
  WINIMPM WINBOOL WINAPI CryptSetAsyncParam (HCRYPTASYNC hAsync, LPSTR pszParamOid, LPVOID pvParam, PFN_CRYPT_ASYNC_PARAM_FREE_FUNC pfnFree);
  WINIMPM WINBOOL WINAPI CryptGetAsyncParam (HCRYPTASYNC hAsync, LPSTR pszParamOid, LPVOID *ppvParam, PFN_CRYPT_ASYNC_PARAM_FREE_FUNC *ppfnFree);
  WINIMPM WINBOOL WINAPI CryptCloseAsyncHandle (HCRYPTASYNC hAsync);

  typedef struct _CRYPT_BLOB_ARRAY {
    DWORD cBlob;
    PCRYPT_DATA_BLOB rgBlob;
  } CRYPT_BLOB_ARRAY,*PCRYPT_BLOB_ARRAY;

  typedef struct _CRYPT_CREDENTIALS {
    DWORD cbSize;
    LPCSTR pszCredentialsOid;
    LPVOID pvCredentials;
  } CRYPT_CREDENTIALS,*PCRYPT_CREDENTIALS;

#define CREDENTIAL_OID_PASSWORD_CREDENTIALS_A ((LPCSTR)1)
#define CREDENTIAL_OID_PASSWORD_CREDENTIALS_W ((LPCSTR)2)

#define CREDENTIAL_OID_PASSWORD_CREDENTIALS __MINGW_NAME_UAW(CREDENTIAL_OID_PASSWORD_CREDENTIALS)

  typedef struct _CRYPT_PASSWORD_CREDENTIALSA {
    DWORD cbSize;
    LPSTR pszUsername;
    LPSTR pszPassword;
  } CRYPT_PASSWORD_CREDENTIALSA,*PCRYPT_PASSWORD_CREDENTIALSA;

  typedef struct _CRYPT_PASSWORD_CREDENTIALSW {
    DWORD cbSize;
    LPWSTR pszUsername;
    LPWSTR pszPassword;
  } CRYPT_PASSWORD_CREDENTIALSW,*PCRYPT_PASSWORD_CREDENTIALSW;

  typedef __MINGW_NAME_AW(CRYPT_PASSWORD_CREDENTIALS) CRYPT_PASSWORD_CREDENTIALS;
  typedef __MINGW_NAME_AW(PCRYPT_PASSWORD_CREDENTIALS) PCRYPT_PASSWORD_CREDENTIALS;

#define SCHEME_OID_RETRIEVE_ENCODED_OBJECT_FUNC "SchemeDllRetrieveEncodedObject"
#define SCHEME_OID_RETRIEVE_ENCODED_OBJECTW_FUNC "SchemeDllRetrieveEncodedObjectW"
#define CONTEXT_OID_CREATE_OBJECT_CONTEXT_FUNC "ContextDllCreateObjectContext"

  typedef VOID (WINAPI *PFN_FREE_ENCODED_OBJECT_FUNC) (LPCSTR pszObjectOid, PCRYPT_BLOB_ARRAY pObject, LPVOID pvFreeContext);

#define CONTEXT_OID_CERTIFICATE ((LPCSTR)1)
#define CONTEXT_OID_CRL ((LPCSTR)2)
#define CONTEXT_OID_CTL ((LPCSTR)3)
#define CONTEXT_OID_PKCS7 ((LPCSTR)4)
#define CONTEXT_OID_CAPI2_ANY ((LPCSTR)5)
#define CONTEXT_OID_OCSP_RESP ((LPCSTR)6)

#define CRYPT_RETRIEVE_MULTIPLE_OBJECTS 0x1
#define CRYPT_CACHE_ONLY_RETRIEVAL 0x2
#define CRYPT_WIRE_ONLY_RETRIEVAL 0x4
#define CRYPT_DONT_CACHE_RESULT 0x8
#define CRYPT_ASYNC_RETRIEVAL 0x10
#define CRYPT_VERIFY_CONTEXT_SIGNATURE 0x20
#define CRYPT_VERIFY_DATA_HASH 0x40
#define CRYPT_KEEP_TIME_VALID 0x80
#define CRYPT_DONT_VERIFY_SIGNATURE 0x100
#define CRYPT_DONT_CHECK_TIME_VALIDITY 0x200
#define CRYPT_CHECK_FRESHNESS_TIME_VALIDITY 0x400
#define CRYPT_ACCUMULATIVE_TIMEOUT 0x800
#define CRYPT_STICKY_CACHE_RETRIEVAL 0x1000
#define CRYPT_LDAP_SCOPE_BASE_ONLY_RETRIEVAL 0x2000
#define CRYPT_OFFLINE_CHECK_RETRIEVAL 0x4000
#define CRYPT_LDAP_INSERT_ENTRY_ATTRIBUTE 0x8000
#define CRYPT_LDAP_SIGN_RETRIEVAL 0x10000
#define CRYPT_NO_AUTH_RETRIEVAL 0x20000
#define CRYPT_LDAP_AREC_EXCLUSIVE_RETRIEVAL 0x40000
#define CRYPT_AIA_RETRIEVAL 0x80000
#define CRYPT_HTTP_POST_RETRIEVAL 0x100000
#define CRYPT_PROXY_CACHE_RETRIEVAL 0x200000
#define CRYPT_NOT_MODIFIED_RETRIEVAL 0x400000
#define CRYPT_ENABLE_SSL_REVOCATION_RETRIEVAL 0x800000
#define CRYPT_OCSP_ONLY_RETRIEVAL 0x1000000
#define CRYPT_NO_OCSP_FAILOVER_TO_CRL_RETRIEVAL 0x2000000
#define CRYPT_RANDOM_QUERY_STRING_RETRIEVAL 0x4000000
#define CRYPT_ENABLE_FILE_RETRIEVAL 0x08000000
#define CRYPT_CREATE_NEW_FLUSH_ENTRY 0x10000000

  typedef struct _CRYPTNET_URL_CACHE_PRE_FETCH_INFO {
    DWORD cbSize;
    DWORD dwObjectType;
    DWORD dwError;
    DWORD dwReserved;
    FILETIME ThisUpdateTime;
    FILETIME NextUpdateTime;
    FILETIME PublishTime;
  } CRYPTNET_URL_CACHE_PRE_FETCH_INFO,*PCRYPTNET_URL_CACHE_PRE_FETCH_INFO;

#define CRYPTNET_URL_CACHE_PRE_FETCH_NONE 0
#define CRYPTNET_URL_CACHE_PRE_FETCH_BLOB 1
#define CRYPTNET_URL_CACHE_PRE_FETCH_CRL 2
#define CRYPTNET_URL_CACHE_PRE_FETCH_OCSP 3
#define CRYPTNET_URL_CACHE_PRE_FETCH_AUTOROOT_CAB 5
#define CRYPTNET_URL_CACHE_PRE_FETCH_DISALLOWED_CERT_CAB 6
#define CRYPTNET_URL_CACHE_PRE_FETCH_PIN_RULES_CAB 7

  typedef struct _CRYPTNET_URL_CACHE_FLUSH_INFO {
    DWORD cbSize;
    DWORD dwExemptSeconds;
    FILETIME ExpireTime;
  } CRYPTNET_URL_CACHE_FLUSH_INFO,*PCRYPTNET_URL_CACHE_FLUSH_INFO;

#define CRYPTNET_URL_CACHE_DEFAULT_FLUSH 0
#define CRYPTNET_URL_CACHE_DISABLE_FLUSH 0xffffffff

  typedef struct _CRYPTNET_URL_CACHE_RESPONSE_INFO {
    DWORD cbSize;
    WORD wResponseType;
    WORD wResponseFlags;
    FILETIME LastModifiedTime;
    DWORD dwMaxAge;
    LPCWSTR pwszETag;
    DWORD dwProxyId;
  } CRYPTNET_URL_CACHE_RESPONSE_INFO,*PCRYPTNET_URL_CACHE_RESPONSE_INFO;

#define CRYPTNET_URL_CACHE_RESPONSE_NONE 0
#define CRYPTNET_URL_CACHE_RESPONSE_HTTP 1

#define CRYPTNET_URL_CACHE_RESPONSE_VALIDATED 0x8000

  typedef struct _CRYPT_RETRIEVE_AUX_INFO {
    DWORD cbSize;
    FILETIME *pLastSyncTime;
    DWORD dwMaxUrlRetrievalByteCount;
    PCRYPTNET_URL_CACHE_PRE_FETCH_INFO pPreFetchInfo;
    PCRYPTNET_URL_CACHE_FLUSH_INFO pFlushInfo;
    PCRYPTNET_URL_CACHE_RESPONSE_INFO *ppResponseInfo;
    LPWSTR pwszCacheFileNamePrefix;
    LPFILETIME pftCacheResync;
    WINBOOL fProxyCacheRetrieval;
    DWORD dwHttpStatusCode;
  } CRYPT_RETRIEVE_AUX_INFO,*PCRYPT_RETRIEVE_AUX_INFO;

#define CRYPT_RETRIEVE_MAX_ERROR_CONTENT_LENGTH 0x1000

  WINIMPM WINBOOL WINAPI CryptRetrieveObjectByUrlA (LPCSTR pszUrl, LPCSTR pszObjectOid, DWORD dwRetrievalFlags, DWORD dwTimeout, LPVOID *ppvObject, HCRYPTASYNC hAsyncRetrieve, PCRYPT_CREDENTIALS pCredentials, LPVOID pvVerify, PCRYPT_RETRIEVE_AUX_INFO pAuxInfo);
  WINIMPM WINBOOL WINAPI CryptRetrieveObjectByUrlW (LPCWSTR pszUrl, LPCSTR pszObjectOid, DWORD dwRetrievalFlags, DWORD dwTimeout, LPVOID *ppvObject, HCRYPTASYNC hAsyncRetrieve, PCRYPT_CREDENTIALS pCredentials, LPVOID pvVerify, PCRYPT_RETRIEVE_AUX_INFO pAuxInfo);

#define CryptRetrieveObjectByUrl __MINGW_NAME_AW(CryptRetrieveObjectByUrl)

  typedef WINBOOL (WINAPI *PFN_CRYPT_CANCEL_RETRIEVAL) (DWORD dwFlags, void *pvArg);

  WINIMPM WINBOOL WINAPI CryptInstallCancelRetrieval (PFN_CRYPT_CANCEL_RETRIEVAL pfnCancel, const void *pvArg, DWORD dwFlags, void *pvReserved);
  WINIMPM WINBOOL WINAPI CryptUninstallCancelRetrieval (DWORD dwFlags, void *pvReserved);
  WINIMPM WINBOOL WINAPI CryptCancelAsyncRetrieval (HCRYPTASYNC hAsyncRetrieval);

#define CRYPT_PARAM_ASYNC_RETRIEVAL_COMPLETION ((LPCSTR)1)

  typedef VOID (WINAPI *PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC) (LPVOID pvCompletion, DWORD dwCompletionCode, LPCSTR pszUrl, LPSTR pszObjectOid, LPVOID pvObject);

  typedef struct _CRYPT_ASYNC_RETRIEVAL_COMPLETION {
    PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC pfnCompletion;
    LPVOID pvCompletion;
  } CRYPT_ASYNC_RETRIEVAL_COMPLETION,*PCRYPT_ASYNC_RETRIEVAL_COMPLETION;

#define CRYPT_PARAM_CANCEL_ASYNC_RETRIEVAL ((LPCSTR)2)

  typedef WINBOOL (WINAPI *PFN_CANCEL_ASYNC_RETRIEVAL_FUNC) (HCRYPTASYNC hAsyncRetrieve);

#define CRYPT_GET_URL_FROM_PROPERTY 0x1
#define CRYPT_GET_URL_FROM_EXTENSION 0x2
#define CRYPT_GET_URL_FROM_UNAUTH_ATTRIBUTE 0x4
#define CRYPT_GET_URL_FROM_AUTH_ATTRIBUTE 0x8

  typedef struct _CRYPT_URL_ARRAY {
    DWORD cUrl;
    LPWSTR *rgwszUrl;
  } CRYPT_URL_ARRAY,*PCRYPT_URL_ARRAY;

  typedef struct _CRYPT_URL_INFO {
    DWORD cbSize;
    DWORD dwSyncDeltaTime;
    DWORD cGroup;
    DWORD *rgcGroupEntry;
  } CRYPT_URL_INFO,*PCRYPT_URL_INFO;

  WINIMPM WINBOOL WINAPI CryptGetObjectUrl (LPCSTR pszUrlOid, LPVOID pvPara, DWORD dwFlags, PCRYPT_URL_ARRAY pUrlArray, DWORD *pcbUrlArray, PCRYPT_URL_INFO pUrlInfo, DWORD *pcbUrlInfo, LPVOID pvReserved);

#define URL_OID_GET_OBJECT_URL_FUNC "UrlDllGetObjectUrl"

#define URL_OID_CERTIFICATE_ISSUER ((LPCSTR) 1)
#define URL_OID_CERTIFICATE_CRL_DIST_POINT ((LPCSTR) 2)
#define URL_OID_CTL_ISSUER ((LPCSTR) 3)
#define URL_OID_CTL_NEXT_UPDATE ((LPCSTR) 4)
#define URL_OID_CRL_ISSUER ((LPCSTR) 5)
#define URL_OID_CERTIFICATE_FRESHEST_CRL ((LPCSTR) 6)
#define URL_OID_CRL_FRESHEST_CRL ((LPCSTR) 7)
#define URL_OID_CROSS_CERT_DIST_POINT ((LPCSTR) 8)
#define URL_OID_CERTIFICATE_OCSP ((LPCSTR) 9)
#define URL_OID_CERTIFICATE_OCSP_AND_CRL_DIST_POINT ((LPCSTR) 10)
#define URL_OID_CERTIFICATE_CRL_DIST_POINT_AND_OCSP ((LPCSTR) 11)
#define URL_OID_CROSS_CERT_SUBJECT_INFO_ACCESS ((LPCSTR) 12)
#define URL_OID_CERTIFICATE_ONLY_OCSP ((LPCSTR) 13)

  typedef struct _CERT_CRL_CONTEXT_PAIR {
    PCCERT_CONTEXT pCertContext;
    PCCRL_CONTEXT pCrlContext;
  } CERT_CRL_CONTEXT_PAIR,*PCERT_CRL_CONTEXT_PAIR;

  typedef const CERT_CRL_CONTEXT_PAIR *PCCERT_CRL_CONTEXT_PAIR;

  typedef struct _CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO {
    DWORD cbSize;
    int iDeltaCrlIndicator;
    LPFILETIME pftCacheResync;
    LPFILETIME pLastSyncTime;
    LPFILETIME pMaxAgeTime;
    PCERT_REVOCATION_CHAIN_PARA pChainPara;
    PCRYPT_INTEGER_BLOB pDeltaCrlIndicator;
  } CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO, *PCRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO;

  typedef WINBOOL (WINAPI *PFN_CRYPT_ENUM_KEYID_PROP) (const CRYPT_HASH_BLOB *pKeyIdentifier, DWORD dwFlags, void *pvReserved, void *pvArg, DWORD cProp, DWORD *rgdwPropId, void **rgpvData, DWORD *rgcbData);

#define TIME_VALID_OID_GET_OBJECT_FUNC "TimeValidDllGetObject"
#define CERT_CHAIN_CONFIG_REGPATH L"Software\\Microsoft\\Cryptography\\OID\\EncodingType 0\\CertDllCreateCertificateChainEngine\\Config"

#define TIME_VALID_OID_GET_CTL ((LPCSTR)1)
#define TIME_VALID_OID_GET_CRL ((LPCSTR)2)
#define TIME_VALID_OID_GET_CRL_FROM_CERT ((LPCSTR)3)

#define TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CERT ((LPCSTR)4)
#define TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CRL ((LPCSTR)5)

#define TIME_VALID_OID_FLUSH_OBJECT_FUNC "TimeValidDllFlushObject"

#define TIME_VALID_OID_FLUSH_CTL ((LPCSTR)1)
#define TIME_VALID_OID_FLUSH_CRL ((LPCSTR)2)
#define TIME_VALID_OID_FLUSH_CRL_FROM_CERT ((LPCSTR)3)
#define TIME_VALID_OID_FLUSH_FRESHEST_CRL_FROM_CERT ((LPCSTR)4)
#define TIME_VALID_OID_FLUSH_FRESHEST_CRL_FROM_CRL ((LPCSTR)5)

#define CERT_CREATE_SELFSIGN_NO_SIGN 1
#define CERT_CREATE_SELFSIGN_NO_KEY_INFO 2

#define CRYPT_KEYID_DELETE_FLAG 0x10
#define CRYPT_KEYID_MACHINE_FLAG 0x20
#define CRYPT_KEYID_SET_NEW_FLAG 0x2000
#define CRYPT_KEYID_ALLOC_FLAG 0x8000

  WINIMPM WINBOOL WINAPI CryptGetTimeValidObject (LPCSTR pszTimeValidOid, LPVOID pvPara, PCCERT_CONTEXT pIssuer, LPFILETIME pftValidFor, DWORD dwFlags, DWORD dwTimeout, LPVOID *ppvObject, PCRYPT_CREDENTIALS pCredentials, PCRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO pExtraInfo);
  WINIMPM WINBOOL WINAPI CryptFlushTimeValidObject (LPCSTR pszFlushTimeValidOid, LPVOID pvPara, PCCERT_CONTEXT pIssuer, DWORD dwFlags, LPVOID pvReserved);
  WINIMPM PCCERT_CONTEXT WINAPI CertCreateSelfSignCertificate (HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey, PCERT_NAME_BLOB pSubjectIssuerBlob, DWORD dwFlags, PCRYPT_KEY_PROV_INFO pKeyProvInfo, PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm, PSYSTEMTIME pStartTime, PSYSTEMTIME pEndTime, PCERT_EXTENSIONS pExtensions);
  WINIMPM WINBOOL WINAPI CryptGetKeyIdentifierProperty (const CRYPT_HASH_BLOB *pKeyIdentifier, DWORD dwPropId, DWORD dwFlags, LPCWSTR pwszComputerName, void *pvReserved, void *pvData, DWORD *pcbData);
  WINIMPM WINBOOL WINAPI CryptSetKeyIdentifierProperty (const CRYPT_HASH_BLOB *pKeyIdentifier, DWORD dwPropId, DWORD dwFlags, LPCWSTR pwszComputerName, void *pvReserved, const void *pvData);
  WINIMPM WINBOOL WINAPI CryptEnumKeyIdentifierProperties (const CRYPT_HASH_BLOB *pKeyIdentifier, DWORD dwPropId, DWORD dwFlags, LPCWSTR pwszComputerName, void *pvReserved, void *pvArg, PFN_CRYPT_ENUM_KEYID_PROP pfnEnum);
  WINIMPM WINBOOL WINAPI CryptCreateKeyIdentifierFromCSP (DWORD dwCertEncodingType, LPCSTR pszPubKeyOID, const PUBLICKEYSTRUC *pPubKeyStruc, DWORD cbPubKeyStruc, DWORD dwFlags, void *pvReserved, BYTE *pbHash, DWORD *pcbHash);

#define CERT_CHAIN_MAX_URL_RETRIEVAL_BYTE_COUNT_VALUE_NAME L"MaxUrlRetrievalByteCount"
#define CERT_CHAIN_MAX_URL_RETRIEVAL_BYTE_COUNT_DEFAULT (100 *1024 *1024)
#define CERT_CHAIN_CACHE_RESYNC_FILETIME_VALUE_NAME L"ChainCacheResyncFiletime"
#define CERT_CHAIN_DISABLE_MANDATORY_BASIC_CONSTRAINTS_VALUE_NAME L"DisableMandatoryBasicConstraints"
#define CERT_CHAIN_DISABLE_CA_NAME_CONSTRAINTS_VALUE_NAME L"DisableCANameConstraints"
#define CERT_CHAIN_DISABLE_UNSUPPORTED_CRITICAL_EXTENSIONS_VALUE_NAME L"DisableUnsupportedCriticalExtensions"
#define CERT_CHAIN_MAX_AIA_URL_COUNT_IN_CERT_VALUE_NAME L"MaxAIAUrlCountInCert"
#define CERT_CHAIN_MAX_AIA_URL_COUNT_IN_CERT_DEFAULT 5
#define CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_COUNT_PER_CHAIN_VALUE_NAME L"MaxAIAUrlRetrievalCountPerChain"
#define CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_COUNT_PER_CHAIN_DEFAULT 3
#define CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_BYTE_COUNT_VALUE_NAME L"MaxAIAUrlRetrievalByteCount"
#define CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_BYTE_COUNT_DEFAULT 100000
#define CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_CERT_COUNT_VALUE_NAME L"MaxAIAUrlRetrievalCertCount"
#define CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_CERT_COUNT_DEFAULT 10
#define CERT_CHAIN_OCSP_VALIDITY_SECONDS_VALUE_NAME L"OcspValiditySeconds"
#define CERT_CHAIN_OCSP_VALIDITY_SECONDS_DEFAULT (12 *60 *60)
#define CERT_CHAIN_DISABLE_SERIAL_CHAIN_VALUE_NAME L"DisableSerialChain"
#define CERT_CHAIN_SERIAL_CHAIN_LOG_FILE_NAME_VALUE_NAME L"SerialChainLogFileName"
#define CERT_CHAIN_DISABLE_SYNC_WITH_SSL_TIME_VALUE_NAME L"DisableSyncWithSslTime"
#define CERT_CHAIN_MAX_SSL_TIME_UPDATED_EVENT_COUNT_VALUE_NAME L"MaxSslTimeUpdatedEventCount"
#define CERT_CHAIN_MAX_SSL_TIME_UPDATED_EVENT_COUNT_DEFAULT 5
#define CERT_CHAIN_MAX_SSL_TIME_UPDATED_EVENT_COUNT_DISABLE 0xFFFFFFFF
#define CERT_CHAIN_SSL_HANDSHAKE_LOG_FILE_NAME_VALUE_NAME L"SslHandshakeLogFileName"
#define CERT_CHAIN_ENABLE_WEAK_SIGNATURE_FLAGS_VALUE_NAME L"EnableWeakSignatureFlags"
#define CERT_CHAIN_ENABLE_MD2_MD4_FLAG 0x1
#define CERT_CHAIN_ENABLE_WEAK_RSA_ROOT_FLAG 0x2
#define CERT_CHAIN_ENABLE_WEAK_LOGGING_FLAG 0x4
#define CERT_CHAIN_ENABLE_ONLY_WEAK_LOGGING_FLAG 0x8
#define CERT_CHAIN_MIN_RSA_PUB_KEY_BIT_LENGTH_VALUE_NAME L"MinRsaPubKeyBitLength"
#define CERT_CHAIN_MIN_RSA_PUB_KEY_BIT_LENGTH_DEFAULT 1023
#define CERT_CHAIN_MIN_RSA_PUB_KEY_BIT_LENGTH_DISABLE 0xffffffff
#define CERT_CHAIN_WEAK_RSA_PUB_KEY_TIME_VALUE_NAME L"WeakRsaPubKeyTime"
#define CERT_CHAIN_WEAK_RSA_PUB_KEY_TIME_DEFAULT 0x01ca8a755c6e0000ULL
#define CERT_CHAIN_WEAK_SIGNATURE_LOG_DIR_VALUE_NAME L"WeakSignatureLogDir"

#define CERT_CHAIN_DEFAULT_CONFIG_SUBDIR L"Default"

#define CERT_CHAIN_WEAK_PREFIX_NAME L"Weak"
#define CERT_CHAIN_WEAK_THIRD_PARTY_CONFIG_NAME L"ThirdParty"
#define CERT_CHAIN_WEAK_ALL_CONFIG_NAME L"All"
#define CERT_CHAIN_WEAK_FLAGS_NAME L"Flags"
#define CERT_CHAIN_WEAK_HYGIENE_NAME L"Hygiene"
#define CERT_CHAIN_WEAK_AFTER_TIME_NAME L"AfterTime"
#define CERT_CHAIN_WEAK_FILE_HASH_AFTER_TIME_NAME L"FileHashAfterTime"
#define CERT_CHAIN_WEAK_TIMESTAMP_HASH_AFTER_TIME_NAME L"TimestampHashAfterTime"
#define CERT_CHAIN_WEAK_MIN_BIT_LENGTH_NAME L"MinBitLength"
#define CERT_CHAIN_WEAK_SHA256_ALLOW_NAME L"Sha256Allow"

#define CERT_CHAIN_MIN_PUB_KEY_BIT_LENGTH_DISABLE 0xFFFFFFFF

#define CERT_CHAIN_ENABLE_WEAK_SETTINGS_FLAG 0x80000000
#define CERT_CHAIN_DISABLE_ALL_EKU_WEAK_FLAG 0x00010000
#define CERT_CHAIN_ENABLE_ALL_EKU_HYGIENE_FLAG 0x00020000
#define CERT_CHAIN_DISABLE_OPT_IN_SERVER_AUTH_WEAK_FLAG 0x00040000
#define CERT_CHAIN_DISABLE_SERVER_AUTH_WEAK_FLAG 0x00100000
#define CERT_CHAIN_ENABLE_SERVER_AUTH_HYGIENE_FLAG 0x00200000
#define CERT_CHAIN_DISABLE_CODE_SIGNING_WEAK_FLAG 0x00400000
#define CERT_CHAIN_DISABLE_MOTW_CODE_SIGNING_WEAK_FLAG 0x00800000
#define CERT_CHAIN_ENABLE_CODE_SIGNING_HYGIENE_FLAG 0x01000000
#define CERT_CHAIN_ENABLE_MOTW_CODE_SIGNING_HYGIENE_FLAG 0x02000000
#define CERT_CHAIN_DISABLE_TIMESTAMP_WEAK_FLAG 0x04000000
#define CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_WEAK_FLAG 0x08000000
#define CERT_CHAIN_ENABLE_TIMESTAMP_HYGIENE_FLAG 0x10000000
#define CERT_CHAIN_ENABLE_MOTW_TIMESTAMP_HYGIENE_FLAG 0x20000000
#define CERT_CHAIN_MOTW_IGNORE_AFTER_TIME_WEAK_FLAG 0x40000000
#define CERT_CHAIN_DISABLE_FILE_HASH_WEAK_FLAG 0x00001000
#define CERT_CHAIN_DISABLE_MOTW_FILE_HASH_WEAK_FLAG 0x00002000
#define CERT_CHAIN_DISABLE_TIMESTAMP_HASH_WEAK_FLAG 0x00004000
#define CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_HASH_WEAK_FLAG 0x00008000
#define CERT_CHAIN_DISABLE_WEAK_FLAGS ( CERT_CHAIN_DISABLE_ALL_EKU_WEAK_FLAG | CERT_CHAIN_DISABLE_SERVER_AUTH_WEAK_FLAG | CERT_CHAIN_DISABLE_OPT_IN_SERVER_AUTH_WEAK_FLAG | CERT_CHAIN_DISABLE_CODE_SIGNING_WEAK_FLAG | CERT_CHAIN_DISABLE_MOTW_CODE_SIGNING_WEAK_FLAG | CERT_CHAIN_DISABLE_TIMESTAMP_WEAK_FLAG | CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_WEAK_FLAG )
#define CERT_CHAIN_DISABLE_FILE_HASH_WEAK_FLAGS ( CERT_CHAIN_DISABLE_FILE_HASH_WEAK_FLAG | CERT_CHAIN_DISABLE_MOTW_FILE_HASH_WEAK_FLAG )
#define CERT_CHAIN_DISABLE_TIMESTAMP_HASH_WEAK_FLAGS ( CERT_CHAIN_DISABLE_TIMESTAMP_HASH_WEAK_FLAG | CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_HASH_WEAK_FLAG )
#define CERT_CHAIN_ENABLE_HYGIENE_FLAGS ( CERT_CHAIN_ENABLE_ALL_EKU_HYGIENE_FLAG | CERT_CHAIN_ENABLE_SERVER_AUTH_HYGIENE_FLAG | CERT_CHAIN_ENABLE_CODE_SIGNING_HYGIENE_FLAG | CERT_CHAIN_ENABLE_MOTW_CODE_SIGNING_HYGIENE_FLAG | CERT_CHAIN_ENABLE_TIMESTAMP_HYGIENE_FLAG | CERT_CHAIN_ENABLE_MOTW_TIMESTAMP_HYGIENE_FLAG )
#define CERT_CHAIN_MOTW_WEAK_FLAGS ( CERT_CHAIN_DISABLE_MOTW_CODE_SIGNING_WEAK_FLAG | CERT_CHAIN_DISABLE_MOTW_TIMESTAMP_WEAK_FLAG | CERT_CHAIN_ENABLE_MOTW_CODE_SIGNING_HYGIENE_FLAG | CERT_CHAIN_ENABLE_MOTW_TIMESTAMP_HYGIENE_FLAG | CERT_CHAIN_MOTW_IGNORE_AFTER_TIME_WEAK_FLAG)
#define CERT_CHAIN_OPT_IN_WEAK_FLAGS ( CERT_CHAIN_DISABLE_OPT_IN_SERVER_AUTH_WEAK_FLAG)

#define CERT_CHAIN_AUTO_CURRENT_USER 1
#define CERT_CHAIN_AUTO_LOCAL_MACHINE 2
#define CERT_CHAIN_AUTO_IMPERSONATED 3
#define CERT_CHAIN_AUTO_PROCESS_INFO 4
#define CERT_CHAIN_AUTO_PINRULE_INFO 5
#define CERT_CHAIN_AUTO_NETWORK_INFO 6
#define CERT_CHAIN_AUTO_SERIAL_LOCAL_MACHINE 7
#define CERT_CHAIN_AUTO_HPKP_RULE_INFO 8

#define CERT_CHAIN_AUTO_FLAGS_VALUE_NAME L"AutoFlags"

#define CERT_CHAIN_AUTO_FLUSH_DISABLE_FLAG 0x00000001
#define CERT_CHAIN_AUTO_LOG_CREATE_FLAG 0x00000002
#define CERT_CHAIN_AUTO_LOG_FREE_FLAG 0x00000004
#define CERT_CHAIN_AUTO_LOG_FLUSH_FLAG 0x00000008
#define CERT_CHAIN_AUTO_LOG_FLAGS ( CERT_CHAIN_AUTO_LOG_CREATE_FLAG | CERT_CHAIN_AUTO_LOG_FREE_FLAG | CERT_CHAIN_AUTO_LOG_FLUSH_FLAG )

#define CERT_CHAIN_AUTO_FLUSH_FIRST_DELTA_SECONDS_VALUE_NAME L"AutoFlushFirstDeltaSeconds"
#define CERT_CHAIN_AUTO_FLUSH_FIRST_DELTA_SECONDS_DEFAULT (5 * 60)
#define CERT_CHAIN_AUTO_FLUSH_NEXT_DELTA_SECONDS_VALUE_NAME L"AutoFlushNextDeltaSeconds"
#define CERT_CHAIN_AUTO_FLUSH_NEXT_DELTA_SECONDS_DEFAULT (30 * 60)
#define CERT_CHAIN_AUTO_LOG_FILE_NAME_VALUE_NAME L"AutoLogFileName"
#define CERT_CHAIN_DISABLE_AUTO_FLUSH_PROCESS_NAME_LIST_VALUE_NAME L"DisableAutoFlushProcessNameList"

#define CERT_SRV_OCSP_RESP_MIN_VALIDITY_SECONDS_VALUE_NAME L"SrvOcspRespMinValiditySeconds"
#define CERT_SRV_OCSP_RESP_MIN_VALIDITY_SECONDS_DEFAULT (10 *60)
#define CERT_SRV_OCSP_RESP_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME L"SrvOcspRespUrlRetrievalTimeoutMilliseconds"
#define CERT_SRV_OCSP_RESP_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_DEFAULT (15 *1000)
#define CERT_SRV_OCSP_RESP_MAX_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME L"SrvOcspRespMaxBeforeNextUpdateSeconds"
#define CERT_SRV_OCSP_RESP_MAX_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT (4 *60 *60)
#define CERT_SRV_OCSP_RESP_MIN_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME L"SrvOcspRespMinBeforeNextUpdateSeconds"
#define CERT_SRV_OCSP_RESP_MIN_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT (2 *60)
#define CERT_SRV_OCSP_RESP_MIN_AFTER_NEXT_UPDATE_SECONDS_VALUE_NAME L"SrvOcspRespMinAfterNextUpdateSeconds"
#define CERT_SRV_OCSP_RESP_MIN_AFTER_NEXT_UPDATE_SECONDS_DEFAULT (1 *60)
#define CERT_SRV_OCSP_RESP_MIN_SYNC_CERT_FILE_SECONDS_VALUE_NAME L"SrvOcspRespMinSyncCertFileSeconds"
#define CERT_SRV_OCSP_RESP_MIN_SYNC_CERT_FILE_SECONDS_DEFAULT 5
#define CERT_SRV_OCSP_RESP_MAX_SYNC_CERT_FILE_SECONDS_VALUE_NAME L"SrvOcspRespMaxSyncCertFileSeconds"
#define CERT_SRV_OCSP_RESP_MAX_SYNC_CERT_FILE_SECONDS_DEFAULT (1 * 60 * 60)
#define CRYPTNET_MAX_CACHED_OCSP_PER_CRL_COUNT_VALUE_NAME L"CryptnetMaxCachedOcspPerCrlCount"
#define CRYPTNET_MAX_CACHED_OCSP_PER_CRL_COUNT_DEFAULT 500
#define CRYPTNET_OCSP_AFTER_CRL_DISABLE 0xffffffff
#define CRYPTNET_URL_CACHE_DEFAULT_FLUSH_EXEMPT_SECONDS_VALUE_NAME L"CryptnetDefaultFlushExemptSeconds"
#define CRYPTNET_URL_CACHE_DEFAULT_FLUSH_EXEMPT_SECONDS_DEFAULT (28 *24 *60 *60)
#define CRYPTNET_PRE_FETCH_MIN_MAX_AGE_SECONDS_VALUE_NAME L"CryptnetPreFetchMinMaxAgeSeconds"
#define CRYPTNET_PRE_FETCH_MIN_MAX_AGE_SECONDS_DEFAULT (1 *60 *60)
#define CRYPTNET_PRE_FETCH_MAX_MAX_AGE_SECONDS_VALUE_NAME L"CryptnetPreFetchMaxMaxAgeSeconds"
#define CRYPTNET_PRE_FETCH_MAX_MAX_AGE_SECONDS_DEFAULT (14 *24 *60 *60)
#define CRYPTNET_PRE_FETCH_MIN_OCSP_VALIDITY_PERIOD_SECONDS_VALUE_NAME L"CryptnetPreFetchMinOcspValidityPeriodSeconds"
#define CRYPTNET_PRE_FETCH_MIN_OCSP_VALIDITY_PERIOD_SECONDS_DEFAULT (14 *24 *60 *60)
#define CRYPTNET_PRE_FETCH_AFTER_PUBLISH_PRE_FETCH_DIVISOR_VALUE_NAME L"CryptnetPreFetchAfterPublishPreFetchDivisor"
#define CRYPTNET_PRE_FETCH_AFTER_PUBLISH_PRE_FETCH_DIVISOR_DEFAULT 10
#define CRYPTNET_PRE_FETCH_BEFORE_NEXT_UPDATE_PRE_FETCH_DIVISOR_VALUE_NAME L"CryptnetPreFetchBeforeNextUpdatePreFetchDivisor"
#define CRYPTNET_PRE_FETCH_BEFORE_NEXT_UPDATE_PRE_FETCH_DIVISOR_DEFAULT 20
#define CRYPTNET_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME L"CryptnetPreFetchMinBeforeNextUpdatePreFetchSeconds"
#define CRYPTNET_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_DEFAULT (1 *60 *60)
#define CRYPTNET_PRE_FETCH_VALIDITY_PERIOD_AFTER_NEXT_UPDATE_PRE_FETCH_DIVISOR_VALUE_NAME L"CryptnetPreFetchValidityPeriodAfterNextUpdatePreFetchDivisor"
#define CRYPTNET_PRE_FETCH_VALIDITY_PERIOD_AFTER_NEXT_UPDATE_PRE_FETCH_DIVISOR_DEFAULT 10
#define CRYPTNET_PRE_FETCH_MAX_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME L"CryptnetPreFetchMaxAfterNextUpdatePreFetchPeriodSeconds"
#define CRYPTNET_PRE_FETCH_MAX_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_DEFAULT (4 *60 *60)
#define CRYPTNET_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME L"CryptnetPreFetchMinAfterNextUpdatePreFetchPeriodSeconds"
#define CRYPTNET_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_DEFAULT (30 *60)
#define CRYPTNET_PRE_FETCH_AFTER_CURRENT_TIME_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME L"CryptnetPreFetchAfterCurrentTimePreFetchPeriodSeconds"
#define CRYPTNET_PRE_FETCH_AFTER_CURRENT_TIME_PRE_FETCH_PERIOD_SECONDS_DEFAULT (30 *60)
#define CRYPTNET_PRE_FETCH_TRIGGER_PERIOD_SECONDS_VALUE_NAME L"CryptnetPreFetchTriggerPeriodSeconds"
#define CRYPTNET_PRE_FETCH_TRIGGER_PERIOD_SECONDS_DEFAULT (10 *60)
#define CRYPTNET_PRE_FETCH_TRIGGER_DISABLE 0xffffffff
#define CRYPTNET_PRE_FETCH_SCAN_AFTER_TRIGGER_DELAY_SECONDS_VALUE_NAME L"CryptnetPreFetchScanAfterTriggerDelaySeconds"
#define CRYPTNET_PRE_FETCH_SCAN_AFTER_TRIGGER_DELAY_SECONDS_DEFAULT 30
#define CRYPTNET_PRE_FETCH_RETRIEVAL_TIMEOUT_SECONDS_VALUE_NAME L"CryptnetPreFetchRetrievalTimeoutSeconds"
#define CRYPTNET_PRE_FETCH_RETRIEVAL_TIMEOUT_SECONDS_DEFAULT (5 *60)
#define CRYPTNET_CRL_PRE_FETCH_CONFIG_REGPATH CERT_CHAIN_CONFIG_REGPATH L"\\CrlPreFetch"
#define CRYPTNET_CRL_PRE_FETCH_PROCESS_NAME_LIST_VALUE_NAME L"ProcessNameList"
#define CRYPTNET_CRL_PRE_FETCH_URL_LIST_VALUE_NAME L"PreFetchUrlList"
#define CRYPTNET_CRL_PRE_FETCH_DISABLE_INFORMATION_EVENTS_VALUE_NAME L"DisableInformationEvents"
#define CRYPTNET_CRL_PRE_FETCH_LOG_FILE_NAME_VALUE_NAME L"LogFileName"
#define CRYPTNET_CRL_PRE_FETCH_TIMEOUT_SECONDS_VALUE_NAME L"TimeoutSeconds"
#define CRYPTNET_CRL_PRE_FETCH_TIMEOUT_SECONDS_DEFAULT (5 * 60)
#define CRYPTNET_CRL_PRE_FETCH_MAX_AGE_SECONDS_VALUE_NAME L"MaxAgeSeconds"
#define CRYPTNET_CRL_PRE_FETCH_MAX_AGE_SECONDS_DEFAULT (2 * 60 * 60)
#define CRYPTNET_CRL_PRE_FETCH_MAX_AGE_SECONDS_MIN (5 * 60)
#define CRYPTNET_CRL_PRE_FETCH_PUBLISH_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME L"PublishBeforeNextUpdateSeconds"
#define CRYPTNET_CRL_PRE_FETCH_PUBLISH_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT (1 * 60 * 60)
#define CRYPTNET_CRL_PRE_FETCH_PUBLISH_RANDOM_INTERVAL_SECONDS_VALUE_NAME L"PublishRandomIntervalSeconds"
#define CRYPTNET_CRL_PRE_FETCH_PUBLISH_RANDOM_INTERVAL_SECONDS_DEFAULT (5 * 60)
#define CRYPTNET_CRL_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME L"MinBeforeNextUpdateSeconds"
#define CRYPTNET_CRL_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT (5 * 60)
#define CRYPTNET_CRL_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_SECONDS_VALUE_NAME L"MinAfterNextUpdateSeconds"
#define CRYPTNET_CRL_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_SECONDS_DEFAULT (5 * 60)
#define CERT_GROUP_POLICY_CHAIN_CONFIG_REGPATH CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L"\\ChainEngine\\Config"
#define CERT_CHAIN_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME L"ChainUrlRetrievalTimeoutMilliseconds"
#define CERT_CHAIN_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_DEFAULT (15 *1000)
#define CERT_CHAIN_REV_ACCUMULATIVE_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME L"ChainRevAccumulativeUrlRetrievalTimeoutMilliseconds"
#define CERT_CHAIN_REV_ACCUMULATIVE_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_DEFAULT (20 *1000)
#define CERT_RETR_BEHAVIOR_INET_AUTH_VALUE_NAME L"EnableInetUnknownAuth"
#define CERT_RETR_BEHAVIOR_INET_STATUS_VALUE_NAME L"EnableInetLocal"
#define CERT_RETR_BEHAVIOR_FILE_VALUE_NAME L"AllowFileUrlScheme"
#define CERT_RETR_BEHAVIOR_LDAP_VALUE_NAME L"DisableLDAPSignAndEncrypt"
#define CRYPTNET_CACHED_OCSP_SWITCH_TO_CRL_COUNT_VALUE_NAME L"CryptnetCachedOcspSwitchToCrlCount"
#define CRYPTNET_CACHED_OCSP_SWITCH_TO_CRL_COUNT_DEFAULT 50
#define CRYPTNET_CRL_BEFORE_OCSP_ENABLE 0xffffffff
#define CERT_CHAIN_DISABLE_AIA_URL_RETRIEVAL_VALUE_NAME L"DisableAIAUrlRetrieval"
#define CERT_CHAIN_OPTIONS_VALUE_NAME L"Options"
#define CERT_CHAIN_OPTION_DISABLE_AIA_URL_RETRIEVAL 0x2
#define CERT_CHAIN_OPTION_ENABLE_SIA_URL_RETRIEVAL 0x4
#define CERT_CHAIN_CROSS_CERT_DOWNLOAD_INTERVAL_HOURS_VALUE_NAME L"CrossCertDownloadIntervalHours"
#define CERT_CHAIN_CROSS_CERT_DOWNLOAD_INTERVAL_HOURS_DEFAULT (24 *7)
#define CERT_CHAIN_CRL_VALIDITY_EXT_PERIOD_HOURS_VALUE_NAME L"CRLValidityExtensionPeriod"
#define CERT_CHAIN_CRL_VALIDITY_EXT_PERIOD_HOURS_DEFAULT 12

#define HCCE_CURRENT_USER ((HCERTCHAINENGINE)NULL)
#define HCCE_LOCAL_MACHINE ((HCERTCHAINENGINE)0x1)
#define HCCE_SERIAL_LOCAL_MACHINE ((HCERTCHAINENGINE)0x2)

#define CERT_CHAIN_CACHE_END_CERT 0x1
#define CERT_CHAIN_THREAD_STORE_SYNC 0x2
#define CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL 0x4
#define CERT_CHAIN_USE_LOCAL_MACHINE_STORE 0x8
#define CERT_CHAIN_ENABLE_CACHE_AUTO_UPDATE 0x10
#define CERT_CHAIN_ENABLE_SHARE_STORE 0x20

  typedef HANDLE HCERTCHAINENGINE;

  typedef struct _CERT_CHAIN_ENGINE_CONFIG {
    DWORD cbSize;
    HCERTSTORE hRestrictedRoot;
    HCERTSTORE hRestrictedTrust;
    HCERTSTORE hRestrictedOther;
    DWORD cAdditionalStore;
    HCERTSTORE *rghAdditionalStore;
    DWORD dwFlags;
    DWORD dwUrlRetrievalTimeout;
    DWORD MaximumCachedCertificates;
    DWORD CycleDetectionModulus;
#if NTDDI_VERSION >= NTDDI_WIN7
    HCERTSTORE hExclusiveRoot;
    HCERTSTORE hExclusiveTrustedPeople;
#endif
#if NTDDI_VERSION >= NTDDI_WIN8
    DWORD dwExclusiveFlags;
#endif
  } CERT_CHAIN_ENGINE_CONFIG,*PCERT_CHAIN_ENGINE_CONFIG;

#if NTDDI_VERSION >= NTDDI_WIN8
#define CERT_CHAIN_EXCLUSIVE_ENABLE_CA_FLAG 0x1
#endif

  WINIMPM WINBOOL WINAPI CertCreateCertificateChainEngine (PCERT_CHAIN_ENGINE_CONFIG pConfig, HCERTCHAINENGINE *phChainEngine);
  WINIMPM VOID WINAPI CertFreeCertificateChainEngine (HCERTCHAINENGINE hChainEngine);
  WINIMPM WINBOOL WINAPI CertResyncCertificateChainEngine (HCERTCHAINENGINE hChainEngine);

  typedef struct _CERT_TRUST_STATUS {
    DWORD dwErrorStatus;
    DWORD dwInfoStatus;
  } CERT_TRUST_STATUS,*PCERT_TRUST_STATUS;

#define CERT_TRUST_NO_ERROR 0x0
#define CERT_TRUST_IS_NOT_TIME_VALID 0x1
#define CERT_TRUST_IS_NOT_TIME_NESTED 0x2
#define CERT_TRUST_IS_REVOKED 0x4
#define CERT_TRUST_IS_NOT_SIGNATURE_VALID 0x8
#define CERT_TRUST_IS_NOT_VALID_FOR_USAGE 0x10
#define CERT_TRUST_IS_UNTRUSTED_ROOT 0x20
#define CERT_TRUST_REVOCATION_STATUS_UNKNOWN 0x40
#define CERT_TRUST_IS_CYCLIC 0x80
#define CERT_TRUST_INVALID_EXTENSION 0x100
#define CERT_TRUST_INVALID_POLICY_CONSTRAINTS 0x200
#define CERT_TRUST_INVALID_BASIC_CONSTRAINTS 0x400
#define CERT_TRUST_INVALID_NAME_CONSTRAINTS 0x800
#define CERT_TRUST_HAS_NOT_SUPPORTED_NAME_CONSTRAINT 0x1000
#define CERT_TRUST_HAS_NOT_DEFINED_NAME_CONSTRAINT 0x2000
#define CERT_TRUST_HAS_NOT_PERMITTED_NAME_CONSTRAINT 0x4000
#define CERT_TRUST_HAS_EXCLUDED_NAME_CONSTRAINT 0x8000
#define CERT_TRUST_IS_PARTIAL_CHAIN 0x10000
#define CERT_TRUST_CTL_IS_NOT_TIME_VALID 0x20000
#define CERT_TRUST_CTL_IS_NOT_SIGNATURE_VALID 0x40000
#define CERT_TRUST_CTL_IS_NOT_VALID_FOR_USAGE 0x80000
#define CERT_TRUST_IS_OFFLINE_REVOCATION 0x1000000
#define CERT_TRUST_NO_ISSUANCE_CHAIN_POLICY 0x2000000
#define CERT_TRUST_IS_EXPLICIT_DISTRUST 0x4000000
#define CERT_TRUST_HAS_NOT_SUPPORTED_CRITICAL_EXT 0x8000000
#define CERT_TRUST_HAS_WEAK_SIGNATURE 0x100000

#define CERT_TRUST_HAS_EXACT_MATCH_ISSUER 0x1
#define CERT_TRUST_HAS_KEY_MATCH_ISSUER 0x2
#define CERT_TRUST_HAS_NAME_MATCH_ISSUER 0x4
#define CERT_TRUST_IS_SELF_SIGNED 0x8
#define CERT_TRUST_AUTO_UPDATE_CA_REVOCATION 0x10
#define CERT_TRUST_AUTO_UPDATE_END_REVOCATION 0x20
#define CERT_TRUST_NO_OCSP_FAILOVER_TO_CRL 0x40
#define CERT_TRUST_IS_KEY_ROLLOVER 0x00000080
#define CERT_TRUST_SSL_HANDSHAKE_OCSP 0x00040000
#define CERT_TRUST_SSL_TIME_VALID_OCSP 0x00080000
#define CERT_TRUST_SSL_RECONNECT_OCSP 0x00100000

#define CERT_TRUST_HAS_PREFERRED_ISSUER 0x100
#define CERT_TRUST_HAS_ISSUANCE_CHAIN_POLICY 0x200
#define CERT_TRUST_HAS_VALID_NAME_CONSTRAINTS 0x400
#define CERT_TRUST_IS_PEER_TRUSTED 0x800
#define CERT_TRUST_HAS_CRL_VALIDITY_EXTENDED 0x1000
#define CERT_TRUST_IS_FROM_EXCLUSIVE_TRUST_STORE 0x2000
#if NTDDI_VERSION >= NTDDI_WIN8
#define CERT_TRUST_IS_CA_TRUSTED 0x00004000
#define CERT_TRUST_HAS_AUTO_UPDATE_WEAK_SIGNATURE 0x00008000
#define CERT_TRUST_HAS_ALLOW_WEAK_SIGNATURE 0x00020000
#endif
#define CERT_TRUST_IS_COMPLEX_CHAIN 0x00010000
#define CERT_TRUST_SSL_TIME_VALID 0x01000000
#define CERT_TRUST_NO_TIME_CHECK 0x02000000

  typedef struct _CERT_REVOCATION_INFO {
    DWORD cbSize;
    DWORD dwRevocationResult;
    LPCSTR pszRevocationOid;
    LPVOID pvOidSpecificInfo;
    WINBOOL fHasFreshnessTime;
    DWORD dwFreshnessTime;
    PCERT_REVOCATION_CRL_INFO pCrlInfo;
  } CERT_REVOCATION_INFO,*PCERT_REVOCATION_INFO;

  typedef struct _CERT_TRUST_LIST_INFO {
    DWORD cbSize;
    PCTL_ENTRY pCtlEntry;
    PCCTL_CONTEXT pCtlContext;
  } CERT_TRUST_LIST_INFO,*PCERT_TRUST_LIST_INFO;

  typedef struct _CERT_CHAIN_ELEMENT {
    DWORD cbSize;
    PCCERT_CONTEXT pCertContext;
    CERT_TRUST_STATUS TrustStatus;
    PCERT_REVOCATION_INFO pRevocationInfo;
    PCERT_ENHKEY_USAGE pIssuanceUsage;
    PCERT_ENHKEY_USAGE pApplicationUsage;
    LPCWSTR pwszExtendedErrorInfo;
  } CERT_CHAIN_ELEMENT,*PCERT_CHAIN_ELEMENT;

  typedef const CERT_CHAIN_ELEMENT *PCCERT_CHAIN_ELEMENT;

  typedef struct _CERT_SIMPLE_CHAIN {
    DWORD cbSize;
    CERT_TRUST_STATUS TrustStatus;
    DWORD cElement;
    PCERT_CHAIN_ELEMENT *rgpElement;
    PCERT_TRUST_LIST_INFO pTrustListInfo;
    WINBOOL fHasRevocationFreshnessTime;
    DWORD dwRevocationFreshnessTime;
  } CERT_SIMPLE_CHAIN,*PCERT_SIMPLE_CHAIN;

  typedef const CERT_SIMPLE_CHAIN *PCCERT_SIMPLE_CHAIN;

  typedef struct _CERT_CHAIN_CONTEXT CERT_CHAIN_CONTEXT,*PCERT_CHAIN_CONTEXT;
  typedef const CERT_CHAIN_CONTEXT *PCCERT_CHAIN_CONTEXT;

  struct _CERT_CHAIN_CONTEXT {
    DWORD cbSize;
    CERT_TRUST_STATUS TrustStatus;
    DWORD cChain;
    PCERT_SIMPLE_CHAIN *rgpChain;
    DWORD cLowerQualityChainContext;
    PCCERT_CHAIN_CONTEXT *rgpLowerQualityChainContext;
    WINBOOL fHasRevocationFreshnessTime;
    DWORD dwRevocationFreshnessTime;
    DWORD dwCreateFlags;
    GUID ChainId;
  };

#define USAGE_MATCH_TYPE_AND 0x0
#define USAGE_MATCH_TYPE_OR 0x1

  typedef struct _CERT_USAGE_MATCH {
    DWORD dwType;
    CERT_ENHKEY_USAGE Usage;
  } CERT_USAGE_MATCH,*PCERT_USAGE_MATCH;

  typedef struct _CTL_USAGE_MATCH {
    DWORD dwType;
    CTL_USAGE Usage;
  } CTL_USAGE_MATCH,*PCTL_USAGE_MATCH;

  typedef struct _CERT_CHAIN_PARA {
    DWORD cbSize;
    CERT_USAGE_MATCH RequestedUsage;
#ifdef CERT_CHAIN_PARA_HAS_EXTRA_FIELDS
    CERT_USAGE_MATCH RequestedIssuancePolicy;
    DWORD dwUrlRetrievalTimeout;
    WINBOOL fCheckRevocationFreshnessTime;
    DWORD dwRevocationFreshnessTime;
    LPFILETIME pftCacheResync;
    PCCERT_STRONG_SIGN_PARA pStrongSignPara;
    DWORD dwStrongSignFlags;
#endif
  } CERT_CHAIN_PARA,*PCERT_CHAIN_PARA;

#define CERT_CHAIN_STRONG_SIGN_DISABLE_END_CHECK_FLAG 0x1
#define CERT_CHAIN_DISABLE_PASS1_QUALITY_FILTERING 0x40
#define CERT_CHAIN_RETURN_LOWER_QUALITY_CONTEXTS 0x80
#define CERT_CHAIN_DISABLE_AUTH_ROOT_AUTO_UPDATE 0x100
#define CERT_CHAIN_TIMESTAMP_TIME 0x200
#define CERT_CHAIN_ENABLE_PEER_TRUST 0x400
#define CERT_CHAIN_DISABLE_MY_PEER_TRUST 0x800
#define CERT_CHAIN_DISABLE_MD2_MD4 0x1000
#define CERT_CHAIN_DISABLE_AIA 0x2000
#define CERT_CHAIN_HAS_MOTW 0x4000
#define CERT_CHAIN_ONLY_ADDITIONAL_AND_AUTH_ROOT 0x8000
#define CERT_CHAIN_OPT_IN_WEAK_SIGNATURE 0x10000
#define CERT_CHAIN_REVOCATION_CHECK_END_CERT 0x10000000
#define CERT_CHAIN_REVOCATION_CHECK_CHAIN 0x20000000
#define CERT_CHAIN_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT 0x40000000
#define CERT_CHAIN_REVOCATION_CHECK_CACHE_ONLY 0x80000000
#define CERT_CHAIN_REVOCATION_ACCUMULATIVE_TIMEOUT 0x8000000
#define CERT_CHAIN_REVOCATION_CHECK_OCSP_CERT 0x4000000

  WINIMPM WINBOOL WINAPI CertGetCertificateChain (HCERTCHAINENGINE hChainEngine, PCCERT_CONTEXT pCertContext, LPFILETIME pTime, HCERTSTORE hAdditionalStore, PCERT_CHAIN_PARA pChainPara, DWORD dwFlags, LPVOID pvReserved, PCCERT_CHAIN_CONTEXT *ppChainContext);
  WINIMPM VOID WINAPI CertFreeCertificateChain (PCCERT_CHAIN_CONTEXT pChainContext);
  WINIMPM PCCERT_CHAIN_CONTEXT WINAPI CertDuplicateCertificateChain (PCCERT_CHAIN_CONTEXT pChainContext);

  struct _CERT_REVOCATION_CHAIN_PARA {
    DWORD cbSize;
    HCERTCHAINENGINE hChainEngine;
    HCERTSTORE hAdditionalStore;
    DWORD dwChainFlags;
    DWORD dwUrlRetrievalTimeout;
    LPFILETIME pftCurrentTime;
    LPFILETIME pftCacheResync;
    DWORD cbMaxUrlRetrievalByteCount;
  };

#define REVOCATION_OID_CRL_REVOCATION ((LPCSTR)1)

  typedef struct _CRL_REVOCATION_INFO {
    PCRL_ENTRY pCrlEntry;
    PCCRL_CONTEXT pCrlContext;
    PCCERT_CHAIN_CONTEXT pCrlIssuerChain;
  } CRL_REVOCATION_INFO,*PCRL_REVOCATION_INFO;

  WINIMPM PCCERT_CHAIN_CONTEXT WINAPI CertFindChainInStore (HCERTSTORE hCertStore, DWORD dwCertEncodingType, DWORD dwFindFlags, DWORD dwFindType, const void *pvFindPara, PCCERT_CHAIN_CONTEXT pPrevChainContext);

#define CERT_CHAIN_FIND_BY_ISSUER 1

  typedef WINBOOL (WINAPI *PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK) (PCCERT_CONTEXT pCert, void *pvFindArg);

  typedef struct _CERT_CHAIN_FIND_BY_ISSUER_PARA {
    DWORD cbSize;
    LPCSTR pszUsageIdentifier;
    DWORD dwKeySpec;
    DWORD dwAcquirePrivateKeyFlags;
    DWORD cIssuer;
    CERT_NAME_BLOB *rgIssuer;
    PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK pfnFindCallback;
    void *pvFindArg;
#ifdef CERT_CHAIN_FIND_BY_ISSUER_PARA_HAS_EXTRA_FIELDS
    DWORD *pdwIssuerChainIndex;
    DWORD *pdwIssuerElementIndex;
#endif
  } CERT_CHAIN_FIND_ISSUER_PARA,*PCERT_CHAIN_FIND_ISSUER_PARA,CERT_CHAIN_FIND_BY_ISSUER_PARA,*PCERT_CHAIN_FIND_BY_ISSUER_PARA;

#define CERT_CHAIN_FIND_BY_ISSUER_COMPARE_KEY_FLAG 0x1
#define CERT_CHAIN_FIND_BY_ISSUER_COMPLEX_CHAIN_FLAG 0x2
#define CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_URL_FLAG 0x4
#define CERT_CHAIN_FIND_BY_ISSUER_LOCAL_MACHINE_FLAG 0x8
#define CERT_CHAIN_FIND_BY_ISSUER_NO_KEY_FLAG 0x4000
#define CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_FLAG 0x8000

  typedef struct _CERT_CHAIN_POLICY_PARA {
    DWORD cbSize;
    DWORD dwFlags;
    void *pvExtraPolicyPara;
  } CERT_CHAIN_POLICY_PARA,*PCERT_CHAIN_POLICY_PARA;

  typedef struct _CERT_CHAIN_POLICY_STATUS {
    DWORD cbSize;
    DWORD dwError;
    LONG lChainIndex;
    LONG lElementIndex;
    void *pvExtraPolicyStatus;
  } CERT_CHAIN_POLICY_STATUS,*PCERT_CHAIN_POLICY_STATUS;

#define CERT_CHAIN_POLICY_IGNORE_NOT_TIME_VALID_FLAG 0x1
#define CERT_CHAIN_POLICY_IGNORE_CTL_NOT_TIME_VALID_FLAG 0x2
#define CERT_CHAIN_POLICY_IGNORE_NOT_TIME_NESTED_FLAG 0x4
#define CERT_CHAIN_POLICY_IGNORE_INVALID_BASIC_CONSTRAINTS_FLAG 0x8

#define CERT_CHAIN_POLICY_IGNORE_ALL_NOT_TIME_VALID_FLAGS (CERT_CHAIN_POLICY_IGNORE_NOT_TIME_VALID_FLAG | CERT_CHAIN_POLICY_IGNORE_CTL_NOT_TIME_VALID_FLAG | CERT_CHAIN_POLICY_IGNORE_NOT_TIME_NESTED_FLAG)

#define CERT_CHAIN_POLICY_ALLOW_UNKNOWN_CA_FLAG 0x10
#define CERT_CHAIN_POLICY_IGNORE_WRONG_USAGE_FLAG 0x20
#define CERT_CHAIN_POLICY_IGNORE_INVALID_NAME_FLAG 0x40
#define CERT_CHAIN_POLICY_IGNORE_INVALID_POLICY_FLAG 0x80

#define CERT_CHAIN_POLICY_IGNORE_END_REV_UNKNOWN_FLAG 0x100
#define CERT_CHAIN_POLICY_IGNORE_CTL_SIGNER_REV_UNKNOWN_FLAG 0x200
#define CERT_CHAIN_POLICY_IGNORE_CA_REV_UNKNOWN_FLAG 0x400
#define CERT_CHAIN_POLICY_IGNORE_ROOT_REV_UNKNOWN_FLAG 0x800

#define CERT_CHAIN_POLICY_IGNORE_ALL_REV_UNKNOWN_FLAGS (CERT_CHAIN_POLICY_IGNORE_END_REV_UNKNOWN_FLAG | CERT_CHAIN_POLICY_IGNORE_CTL_SIGNER_REV_UNKNOWN_FLAG | CERT_CHAIN_POLICY_IGNORE_CA_REV_UNKNOWN_FLAG | CERT_CHAIN_POLICY_IGNORE_ROOT_REV_UNKNOWN_FLAG)

#define CERT_CHAIN_POLICY_IGNORE_PEER_TRUST_FLAG 0x1000
#define CERT_CHAIN_POLICY_IGNORE_NOT_SUPPORTED_CRITICAL_EXT_FLAG 0x2000
#define CERT_CHAIN_POLICY_TRUST_TESTROOT_FLAG 0x4000
#define CERT_CHAIN_POLICY_ALLOW_TESTROOT_FLAG 0x8000

  WINIMPM WINBOOL WINAPI CertVerifyCertificateChainPolicy (LPCSTR pszPolicyOID, PCCERT_CHAIN_CONTEXT pChainContext, PCERT_CHAIN_POLICY_PARA pPolicyPara, PCERT_CHAIN_POLICY_STATUS pPolicyStatus);

#define CRYPT_OID_VERIFY_CERTIFICATE_CHAIN_POLICY_FUNC "CertDllVerifyCertificateChainPolicy"

#define CERT_CHAIN_POLICY_BASE ((LPCSTR) 1)
#define CERT_CHAIN_POLICY_AUTHENTICODE ((LPCSTR) 2)
#define CERT_CHAIN_POLICY_AUTHENTICODE_TS ((LPCSTR) 3)
#define CERT_CHAIN_POLICY_SSL ((LPCSTR) 4)
#define CERT_CHAIN_POLICY_BASIC_CONSTRAINTS ((LPCSTR) 5)
#define CERT_CHAIN_POLICY_NT_AUTH ((LPCSTR) 6)
#define CERT_CHAIN_POLICY_MICROSOFT_ROOT ((LPCSTR) 7)
#define CERT_CHAIN_POLICY_EV ((LPCSTR) 8)
#define CERT_CHAIN_POLICY_SSL_F12 ((LPCSTR) 9)
#define CERT_CHAIN_POLICY_SSL_HPKP_HEADER ((LPCSTR) 10)
#define CERT_CHAIN_POLICY_THIRD_PARTY_ROOT ((LPCSTR) 11)
#define CERT_CHAIN_POLICY_SSL_KEY_PIN ((LPCSTR) 12)

  typedef struct _AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA {
    DWORD cbSize;
    DWORD dwRegPolicySettings;
    PCMSG_SIGNER_INFO pSignerInfo;
  } AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA, *PAUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA;

  typedef struct _AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS {
    DWORD cbSize;
    WINBOOL fCommercial;
  } AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS, *PAUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS;

  typedef struct _AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA {
    DWORD cbSize;
    DWORD dwRegPolicySettings;
    WINBOOL fCommercial;
  } AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA,*PAUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA;

#define AUTHTYPE_CLIENT 1
#define AUTHTYPE_SERVER 2

  typedef struct _HTTPSPolicyCallbackData {
    __C89_NAMELESS union {
      DWORD cbStruct;
      DWORD cbSize;
    };
    DWORD dwAuthType;
    DWORD fdwChecks;
    WCHAR *pwszServerName;
  } HTTPSPolicyCallbackData,*PHTTPSPolicyCallbackData,SSL_EXTRA_CERT_CHAIN_POLICY_PARA,*PSSL_EXTRA_CERT_CHAIN_POLICY_PARA;

#define BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_CA_FLAG 0x80000000
#define BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_END_ENTITY_FLAG 0x40000000
#define MICROSOFT_ROOT_CERT_CHAIN_POLICY_ENABLE_TEST_ROOT_FLAG 0x00010000
#define MICROSOFT_ROOT_CERT_CHAIN_POLICY_CHECK_APPLICATION_ROOT_FLAG 0x00020000
#define MICROSOFT_ROOT_CERT_CHAIN_POLICY_DISABLE_FLIGHT_ROOT_FLAG 0x00040000

  typedef struct _EV_EXTRA_CERT_CHAIN_POLICY_PARA {
    DWORD cbSize;
    DWORD dwRootProgramQualifierFlags;
  } EV_EXTRA_CERT_CHAIN_POLICY_PARA,*PEV_EXTRA_CERT_CHAIN_POLICY_PARA;

  typedef struct _EV_EXTRA_CERT_CHAIN_POLICY_STATUS {
    DWORD cbSize;
    DWORD dwQualifiers;
    DWORD dwIssuanceUsageIndex;
  } EV_EXTRA_CERT_CHAIN_POLICY_STATUS,*PEV_EXTRA_CERT_CHAIN_POLICY_STATUS;

#define SSL_F12_ERROR_TEXT_LENGTH 256
  typedef struct _SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS {
    DWORD cbSize;
    DWORD dwErrorLevel;
    DWORD dwErrorCategory;
    DWORD dwReserved;
    WCHAR wszErrorText[SSL_F12_ERROR_TEXT_LENGTH];  // Localized
  } SSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS, *PSSL_F12_EXTRA_CERT_CHAIN_POLICY_STATUS;

#define CERT_CHAIN_POLICY_SSL_F12_SUCCESS_LEVEL 0
#define CERT_CHAIN_POLICY_SSL_F12_WARNING_LEVEL 1
#define CERT_CHAIN_POLICY_SSL_F12_ERROR_LEVEL 2

#define CERT_CHAIN_POLICY_SSL_F12_NONE_CATEGORY 0
#define CERT_CHAIN_POLICY_SSL_F12_WEAK_CRYPTO_CATEGORY 1
#define CERT_CHAIN_POLICY_SSL_F12_ROOT_PROGRAM_CATEGORY 2

#define SSL_HPKP_PKP_HEADER_INDEX 0
#define SSL_HPKP_PKP_RO_HEADER_INDEX 1
#define SSL_HPKP_HEADER_COUNT 2

  typedef struct _SSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA {
    DWORD cbSize;
    DWORD dwReserved;
    LPWSTR pwszServerName;
    LPSTR rgpszHpkpValue[SSL_HPKP_HEADER_COUNT];
  } SSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA, *PSSL_HPKP_HEADER_EXTRA_CERT_CHAIN_POLICY_PARA;

  typedef struct _SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_PARA {
    DWORD cbSize;
    DWORD dwReserved;
    PCWSTR pwszServerName;
  } SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_PARA, *PSSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_PARA;

#define SSL_KEY_PIN_ERROR_TEXT_LENGTH   512
  typedef struct _SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS {
    DWORD cbSize;
    LONG lError;
    WCHAR wszErrorText[SSL_KEY_PIN_ERROR_TEXT_LENGTH];
  } SSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS, *PSSL_KEY_PIN_EXTRA_CERT_CHAIN_POLICY_STATUS;

#define CERT_CHAIN_POLICY_SSL_KEY_PIN_MISMATCH_ERROR -2
#define CERT_CHAIN_POLICY_SSL_KEY_PIN_MITM_ERROR -1
#define CERT_CHAIN_POLICY_SSL_KEY_PIN_SUCCESS 0
#define CERT_CHAIN_POLICY_SSL_KEY_PIN_MITM_WARNING 1
#define CERT_CHAIN_POLICY_SSL_KEY_PIN_MISMATCH_WARNING 2

#define CryptStringToBinary __MINGW_NAME_AW(CryptStringToBinary)
#define CryptBinaryToString __MINGW_NAME_AW(CryptBinaryToString)

  WINIMPM WINBOOL WINAPI CryptStringToBinaryA (LPCSTR pszString, DWORD cchString, DWORD dwFlags, BYTE *pbBinary, DWORD *pcbBinary, DWORD *pdwSkip, DWORD *pdwFlags);
  WINIMPM WINBOOL WINAPI CryptStringToBinaryW (LPCWSTR pszString, DWORD cchString, DWORD dwFlags, BYTE *pbBinary, DWORD *pcbBinary, DWORD *pdwSkip, DWORD *pdwFlags);
  WINIMPM WINBOOL WINAPI CryptBinaryToStringA (CONST BYTE *pbBinary, DWORD cbBinary, DWORD dwFlags, LPSTR pszString, DWORD *pcchString);
  WINIMPM WINBOOL WINAPI CryptBinaryToStringW (CONST BYTE *pbBinary, DWORD cbBinary, DWORD dwFlags, LPWSTR pszString, DWORD *pcchString);

#define CRYPT_STRING_BASE64HEADER 0x0
#define CRYPT_STRING_BASE64 0x1
#define CRYPT_STRING_BINARY 0x2
#define CRYPT_STRING_BASE64REQUESTHEADER 0x00000003
#define CRYPT_STRING_HEX 0x4
#define CRYPT_STRING_HEXASCII 0x00000005
#define CRYPT_STRING_BASE64_ANY 0x00000006
#define CRYPT_STRING_ANY 0x00000007
#define CRYPT_STRING_HEX_ANY 0x8
#define CRYPT_STRING_BASE64X509CRLHEADER 0x00000009
#define CRYPT_STRING_HEXADDR 0x0000000a
#define CRYPT_STRING_HEXASCIIADDR 0x0000000b
#define CRYPT_STRING_HEXRAW 0x0000000c
#define CRYPT_STRING_BASE64URI 0x0000000d

#define CRYPT_STRING_ENCODEMASK 0x000000ff
#define CRYPT_STRING_RESERVED100 0x00000100
#define CRYPT_STRING_RESERVED200 0x00000200

#define CRYPT_STRING_PERCENTESCAPE 0x08000000
#define CRYPT_STRING_HASHDATA 0x10000000
#define CRYPT_STRING_STRICT 0x20000000
#define CRYPT_STRING_NOCRLF 0x40000000
#define CRYPT_STRING_NOCR 0x80000000

#define szOID_PKCS_12_PbeIds "1.2.840.113549.1.12.1"
#define szOID_PKCS_12_pbeWithSHA1And128BitRC4 "1.2.840.113549.1.12.1.1"
#define szOID_PKCS_12_pbeWithSHA1And40BitRC4 "1.2.840.113549.1.12.1.2"
#define szOID_PKCS_12_pbeWithSHA1And3KeyTripleDES "1.2.840.113549.1.12.1.3"
#define szOID_PKCS_12_pbeWithSHA1And2KeyTripleDES "1.2.840.113549.1.12.1.4"
#define szOID_PKCS_12_pbeWithSHA1And128BitRC2 "1.2.840.113549.1.12.1.5"
#define szOID_PKCS_12_pbeWithSHA1And40BitRC2 "1.2.840.113549.1.12.1.6"
#define szOID_PKCS_5_PBKDF2 "1.2.840.113549.1.5.12"
#define szOID_PKCS_5_PBES2 "1.2.840.113549.1.5.13"

  typedef struct _CRYPT_PKCS12_PBE_PARAMS {
    int iIterations;
    ULONG cbSalt;
  } CRYPT_PKCS12_PBE_PARAMS;

#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP) || _WIN32_WINNT >= 0x0A00
  WINIMPM HCERTSTORE WINAPI PFXImportCertStore (CRYPT_DATA_BLOB *pPFX, LPCWSTR szPassword, DWORD dwFlags);
#endif

#if WINAPI_FAMILY_PARTITION (WINAPI_PARTITION_DESKTOP)

#define PKCS12_IMPORT_SILENT 0x40
#define CRYPT_USER_KEYSET 0x1000
#define PKCS12_PREFER_CNG_KSP 0x100
#define PKCS12_ALWAYS_CNG_KSP 0x200
#define PKCS12_ONLY_CERTIFICATES 0x00000400
#define PKCS12_ONLY_NOT_ENCRYPTED_CERTIFICATES 0x00000800
#define PKCS12_ALLOW_OVERWRITE_KEY 0x4000
#define PKCS12_NO_PERSIST_KEY 0x8000
#define PKCS12_VIRTUAL_ISOLATION_KEY 0x00010000
#define PKCS12_IMPORT_RESERVED_MASK 0xffff0000

#define PKCS12_OBJECT_LOCATOR_ALL_IMPORT_FLAGS (PKCS12_ALWAYS_CNG_KSP | PKCS12_NO_PERSIST_KEY | PKCS12_IMPORT_SILENT | PKCS12_INCLUDE_EXTENDED_PROPERTIES)

#define PKCS12_ONLY_CERTIFICATES_PROVIDER_TYPE 0
#define PKCS12_ONLY_CERTIFICATES_PROVIDER_NAME L"PfxProvider"
#define PKCS12_ONLY_CERTIFICATES_CONTAINER_NAME L"PfxContainer"

  WINIMPM WINBOOL WINAPI PFXIsPFXBlob (CRYPT_DATA_BLOB *pPFX);
  WINIMPM WINBOOL WINAPI PFXVerifyPassword (CRYPT_DATA_BLOB *pPFX, LPCWSTR szPassword, DWORD dwFlags);
  WINIMPM WINBOOL WINAPI PFXExportCertStoreEx (HCERTSTORE hStore, CRYPT_DATA_BLOB *pPFX, LPCWSTR szPassword, void *pvPara, DWORD dwFlags);

#define REPORT_NO_PRIVATE_KEY 0x1
#define REPORT_NOT_ABLE_TO_EXPORT_PRIVATE_KEY 0x2
#define EXPORT_PRIVATE_KEYS 0x4
#define PKCS12_INCLUDE_EXTENDED_PROPERTIES 0x10
#define PKCS12_PROTECT_TO_DOMAIN_SIDS 0x20
#define PKCS12_EXPORT_SILENT 0x40
#define PKCS12_EXPORT_PBES2_PARAMS 0x0080
#define PKCS12_DISABLE_ENCRYPT_CERTIFICATES 0x0100
#define PKCS12_ENCRYPT_CERTIFICATES 0x0200
#define PKCS12_EXPORT_ECC_CURVE_PARAMETERS 0x1000
#define PKCS12_EXPORT_ECC_CURVE_OID 0x2000
#define PKCS12_EXPORT_RESERVED_MASK 0xffff0000

#define PKCS12_PBKDF2_ID_HMAC_SHA1 "1.2.840.113549.2.7"
#define PKCS12_PBKDF2_ID_HMAC_SHA256 "1.2.840.113549.2.9"
#define PKCS12_PBKDF2_ID_HMAC_SHA384 "1.2.840.113549.2.10"
#define PKCS12_PBKDF2_ID_HMAC_SHA512 "1.2.840.113549.2.11"

  typedef struct _PKCS12_PBES2_EXPORT_PARAMS {
    DWORD dwSize;
    PVOID hNcryptDescriptor;
    LPWSTR pwszPbes2Alg;
  } PKCS12_PBES2_EXPORT_PARAMS, *PPKCS12_PBES2_EXPORT_PARAMS;

#define PKCS12_PBES2_ALG_AES256_SHA256 L"AES256-SHA256"
#define PKCS12_CONFIG_REGPATH L"Software\\Microsoft\\Windows\\CurrentVersion\\PFX"
#define PKCS12_ENCRYPT_CERTIFICATES_VALUE_NAME L"EncryptCertificates"

  WINIMPM WINBOOL WINAPI PFXExportCertStore (HCERTSTORE hStore, CRYPT_DATA_BLOB *pPFX, LPCWSTR szPassword, DWORD dwFlags);

#if NTDDI_VERSION >= NTDDI_VISTA
  typedef VOID *HCERT_SERVER_OCSP_RESPONSE;

  WINIMPM HCERT_SERVER_OCSP_RESPONSE WINAPI CertOpenServerOcspResponse (PCCERT_CHAIN_CONTEXT pChainContext, DWORD dwFlags, LPVOID pvReserved);

#define CERT_SERVER_OCSP_RESPONSE_ASYNC_FLAG 0x1

  WINIMPM VOID WINAPI CertAddRefServerOcspResponse (HCERT_SERVER_OCSP_RESPONSE hServerOcspResponse);
  WINIMPM VOID WINAPI CertCloseServerOcspResponse (HCERT_SERVER_OCSP_RESPONSE hServerOcspResponse, DWORD dwFlags);

  typedef struct _CERT_SERVER_OCSP_RESPONSE_CONTEXT CERT_SERVER_OCSP_RESPONSE_CONTEXT,*PCERT_SERVER_OCSP_RESPONSE_CONTEXT;
  typedef const CERT_SERVER_OCSP_RESPONSE_CONTEXT *PCCERT_SERVER_OCSP_RESPONSE_CONTEXT;

  struct _CERT_SERVER_OCSP_RESPONSE_CONTEXT {
    DWORD cbSize;
    BYTE *pbEncodedOcspResponse;
    DWORD cbEncodedOcspResponse;
  };

  typedef VOID (CALLBACK *PFN_CERT_SERVER_OCSP_RESPONSE_UPDATE_CALLBACK)(PCCERT_CHAIN_CONTEXT pChainContext, PCCERT_SERVER_OCSP_RESPONSE_CONTEXT pServerOcspResponseContext, PCCRL_CONTEXT pNewCrlContext, PCCRL_CONTEXT pPrevCrlContext, PVOID pvArg, DWORD dwWriteOcspFileError);

  typedef struct _CERT_SERVER_OCSP_RESPONSE_OPEN_PARA {
    DWORD cbSize;
    DWORD dwFlags;
    DWORD *pcbUsedSize;
    PWSTR pwszOcspDirectory;
    PFN_CERT_SERVER_OCSP_RESPONSE_UPDATE_CALLBACK pfnUpdateCallback;
    PVOID pvUpdateCallbackArg;
  } CERT_SERVER_OCSP_RESPONSE_OPEN_PARA, *PCERT_SERVER_OCSP_RESPONSE_OPEN_PARA;

#define CERT_SERVER_OCSP_RESPONSE_OPEN_PARA_READ_FLAG 0x00000001
#define CERT_SERVER_OCSP_RESPONSE_OPEN_PARA_WRITE_FLAG 0x00000002

  WINIMPM PCCERT_SERVER_OCSP_RESPONSE_CONTEXT WINAPI CertGetServerOcspResponseContext (HCERT_SERVER_OCSP_RESPONSE hServerOcspResponse, DWORD dwFlags, LPVOID pvReserved);
  WINIMPM VOID WINAPI CertAddRefServerOcspResponseContext (PCCERT_SERVER_OCSP_RESPONSE_CONTEXT pServerOcspResponseContext);
  WINIMPM VOID WINAPI CertFreeServerOcspResponseContext (PCCERT_SERVER_OCSP_RESPONSE_CONTEXT pServerOcspResponseContext);
#endif
  WINIMPM WINBOOL WINAPI CertRetrieveLogoOrBiometricInfo (PCCERT_CONTEXT pCertContext, LPCSTR lpszLogoOrBiometricType, DWORD dwRetrievalFlags, DWORD dwTimeout, DWORD dwFlags, void *pvReserved, BYTE **ppbData, DWORD *pcbData, LPWSTR *ppwszMimeType);

#define CERT_RETRIEVE_ISSUER_LOGO ((LPCSTR) 1)
#define CERT_RETRIEVE_SUBJECT_LOGO ((LPCSTR) 2)
#define CERT_RETRIEVE_COMMUNITY_LOGO ((LPCSTR) 3)

#define CERT_RETRIEVE_BIOMETRIC_PREDEFINED_BASE_TYPE ((LPCSTR) 1000)

#define CERT_RETRIEVE_BIOMETRIC_PICTURE_TYPE (CERT_RETRIEVE_BIOMETRIC_PREDEFINED_BASE_TYPE + CERT_BIOMETRIC_PICTURE_TYPE)
#define CERT_RETRIEVE_BIOMETRIC_SIGNATURE_TYPE (CERT_RETRIEVE_BIOMETRIC_PREDEFINED_BASE_TYPE + CERT_BIOMETRIC_SIGNATURE_TYPE)

#if NTDDI_VERSION >= NTDDI_WIN7
  typedef struct _CERT_SELECT_CHAIN_PARA {
    HCERTCHAINENGINE hChainEngine;
    PFILETIME pTime;
    HCERTSTORE hAdditionalStore;
    PCERT_CHAIN_PARA pChainPara;
    DWORD dwFlags;
  } CERT_SELECT_CHAIN_PARA,*PCERT_SELECT_CHAIN_PARA;

  typedef const CERT_SELECT_CHAIN_PARA *PCCERT_SELECT_CHAIN_PARA;

#define CERT_SELECT_MAX_PARA 500

  typedef struct _CERT_SELECT_CRITERIA {
    DWORD dwType;
    DWORD cPara;
    void **ppPara;
  } CERT_SELECT_CRITERIA,*PCERT_SELECT_CRITERIA;

  typedef const CERT_SELECT_CRITERIA *PCCERT_SELECT_CRITERIA;

#define CERT_SELECT_BY_ENHKEY_USAGE 1
#define CERT_SELECT_BY_KEY_USAGE 2
#define CERT_SELECT_BY_POLICY_OID 3
#define CERT_SELECT_BY_PROV_NAME 4
#define CERT_SELECT_BY_EXTENSION 5
#define CERT_SELECT_BY_SUBJECT_HOST_NAME 6
#define CERT_SELECT_BY_ISSUER_ATTR 7
#define CERT_SELECT_BY_SUBJECT_ATTR 8
#define CERT_SELECT_BY_ISSUER_NAME 9
#define CERT_SELECT_BY_PUBLIC_KEY 10
#define CERT_SELECT_BY_TLS_SIGNATURES 11
#define CERT_SELECT_BY_ISSUER_DISPLAYNAME 12
#define CERT_SELECT_BY_FRIENDLYNAME 13
#define CERT_SELECT_BY_THUMBPRINT 14

#define CERT_SELECT_LAST CERT_SELECT_BY_TLS_SIGNATURES
#define CERT_SELECT_MAX (CERT_SELECT_LAST *3)

#define CERT_SELECT_ALLOW_EXPIRED 0x1
#define CERT_SELECT_TRUSTED_ROOT 0x2
#define CERT_SELECT_DISALLOW_SELFSIGNED 0x4
#define CERT_SELECT_HAS_PRIVATE_KEY 0x8
#define CERT_SELECT_HAS_KEY_FOR_SIGNATURE 0x10
#define CERT_SELECT_HAS_KEY_FOR_KEY_EXCHANGE 0x20
#define CERT_SELECT_HARDWARE_ONLY 0x40
#define CERT_SELECT_ALLOW_DUPLICATES 0x80
#define CERT_SELECT_IGNORE_AUTOSELECT 0x00000100

  WINIMPM WINBOOL WINAPI CertSelectCertificateChains (LPCGUID pSelectionContext, DWORD dwFlags, PCCERT_SELECT_CHAIN_PARA pChainParameters, DWORD cCriteria, PCCERT_SELECT_CRITERIA rgpCriteria, HCERTSTORE hStore, PDWORD pcSelection, PCCERT_CHAIN_CONTEXT **pprgpSelection);
  WINIMPM VOID WINAPI CertFreeCertificateChainList (PCCERT_CHAIN_CONTEXT *prgpSelection);
#endif

#if NTDDI_VERSION >= NTDDI_WIN7
#define TIMESTAMP_VERSION 1

  typedef struct _CRYPT_TIMESTAMP_REQUEST {
    DWORD dwVersion;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_DER_BLOB HashedMessage;
    LPSTR pszTSAPolicyId;
    CRYPT_INTEGER_BLOB Nonce;
    WINBOOL fCertReq;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
  } CRYPT_TIMESTAMP_REQUEST,*PCRYPT_TIMESTAMP_REQUEST;

  typedef struct _CRYPT_TIMESTAMP_RESPONSE {
    DWORD dwStatus;
    DWORD cFreeText;
    LPWSTR *rgFreeText;
    CRYPT_BIT_BLOB FailureInfo;
    CRYPT_DER_BLOB ContentInfo;
  } CRYPT_TIMESTAMP_RESPONSE,*PCRYPT_TIMESTAMP_RESPONSE;

#define TIMESTAMP_STATUS_GRANTED 0
#define TIMESTAMP_STATUS_GRANTED_WITH_MODS 1
#define TIMESTAMP_STATUS_REJECTED 2
#define TIMESTAMP_STATUS_WAITING 3
#define TIMESTAMP_STATUS_REVOCATION_WARNING 4
#define TIMESTAMP_STATUS_REVOKED 5

#define TIMESTAMP_FAILURE_BAD_ALG 0
#define TIMESTAMP_FAILURE_BAD_REQUEST 2
#define TIMESTAMP_FAILURE_BAD_FORMAT 5
#define TIMESTAMP_FAILURE_TIME_NOT_AVAILABLE 14
#define TIMESTAMP_FAILURE_POLICY_NOT_SUPPORTED 15
#define TIMESTAMP_FAILURE_EXTENSION_NOT_SUPPORTED 16
#define TIMESTAMP_FAILURE_INFO_NOT_AVAILABLE 17
#define TIMESTAMP_FAILURE_SYSTEM_FAILURE 25

  typedef struct _CRYPT_TIMESTAMP_ACCURACY {
    DWORD dwSeconds;
    DWORD dwMillis;
    DWORD dwMicros;
  } CRYPT_TIMESTAMP_ACCURACY,*PCRYPT_TIMESTAMP_ACCURACY;

  typedef struct _CRYPT_TIMESTAMP_INFO {
    DWORD dwVersion;
    LPSTR pszTSAPolicyId;
    CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
    CRYPT_DER_BLOB HashedMessage;
    CRYPT_INTEGER_BLOB SerialNumber;
    FILETIME ftTime;
    PCRYPT_TIMESTAMP_ACCURACY pvAccuracy;
    WINBOOL fOrdering;
    CRYPT_DER_BLOB Nonce;
    CRYPT_DER_BLOB Tsa;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
  } CRYPT_TIMESTAMP_INFO,*PCRYPT_TIMESTAMP_INFO;

  typedef struct _CRYPT_TIMESTAMP_CONTEXT {
    DWORD cbEncoded;
    BYTE *pbEncoded;
    PCRYPT_TIMESTAMP_INFO pTimeStamp;
  } CRYPT_TIMESTAMP_CONTEXT,*PCRYPT_TIMESTAMP_CONTEXT;

  typedef struct _CRYPT_TIMESTAMP_PARA {
    LPCSTR pszTSAPolicyId;
    WINBOOL fRequestCerts;
    CRYPT_INTEGER_BLOB Nonce;
    DWORD cExtension;
    PCERT_EXTENSION rgExtension;
  } CRYPT_TIMESTAMP_PARA,*PCRYPT_TIMESTAMP_PARA;

  WINBOOL WINAPI CryptRetrieveTimeStamp (LPCWSTR wszUrl, DWORD dwRetrievalFlags, DWORD dwTimeout, LPCSTR pszHashId, const CRYPT_TIMESTAMP_PARA *pPara, const BYTE *pbData, DWORD cbData, PCRYPT_TIMESTAMP_CONTEXT *ppTsContext, PCCERT_CONTEXT *ppTsSigner, HCERTSTORE *phStore);

#define TIMESTAMP_DONT_HASH_DATA 0x1
#define TIMESTAMP_VERIFY_CONTEXT_SIGNATURE 0x20
#define TIMESTAMP_NO_AUTH_RETRIEVAL 0x20000

  WINBOOL WINAPI CryptVerifyTimeStampSignature (const BYTE *pbTSContentInfo, DWORD cbTSContentInfo, const BYTE *pbData, DWORD cbData, HCERTSTORE hAdditionalStore, PCRYPT_TIMESTAMP_CONTEXT *ppTsContext, PCCERT_CONTEXT *ppTsSigner, HCERTSTORE *phStore);
#endif

#if NTDDI_VERSION >= NTDDI_WIN8
#define CRYPT_OBJECT_LOCATOR_SPN_NAME_TYPE 1
#define CRYPT_OBJECT_LOCATOR_LAST_RESERVED_NAME_TYPE 32
#define CRYPT_OBJECT_LOCATOR_FIRST_RESERVED_USER_NAME_TYPE 33
#define CRYPT_OBJECT_LOCATOR_LAST_RESERVED_USER_NAME_TYPE 0x0000ffff

#define SSL_OBJECT_LOCATOR_PFX_FUNC "SslObjectLocatorInitializePfx"
#define SSL_OBJECT_LOCATOR_ISSUER_LIST_FUNC "SslObjectLocatorInitializeIssuerList"
#define SSL_OBJECT_LOCATOR_CERT_VALIDATION_CONFIG_FUNC "SslObjectLocatorInitializeCertValidationConfig"

#define CRYPT_OBJECT_LOCATOR_RELEASE_SYSTEM_SHUTDOWN 1
#define CRYPT_OBJECT_LOCATOR_RELEASE_SERVICE_STOP 2
#define CRYPT_OBJECT_LOCATOR_RELEASE_PROCESS_EXIT 3
#define CRYPT_OBJECT_LOCATOR_RELEASE_DLL_UNLOAD 4

  typedef WINBOOL (WINAPI *PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH) (LPVOID pContext, PCERT_NAME_BLOB *rgIdentifierOrNameList, DWORD dwIdentifierOrNameListCount);
  typedef WINBOOL (WINAPI *PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET) (LPVOID pPluginContext, PCRYPT_DATA_BLOB pIdentifier, DWORD dwNameType, PCERT_NAME_BLOB pNameBlob, PBYTE *ppbContent, DWORD *pcbContent, PCWSTR *ppwszPassword, PCRYPT_DATA_BLOB *ppIdentifier);
  typedef void (WINAPI *PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE) (DWORD dwReason, LPVOID pPluginContext);
  typedef void (WINAPI *PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD) (LPVOID pPluginContext, PCWSTR pwszPassword);
  typedef void (WINAPI *PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE) (LPVOID pPluginContext, PBYTE pbData);
  typedef void (WINAPI *PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_IDENTIFIER) (LPVOID pPluginContext, PCRYPT_DATA_BLOB pIdentifier);

  typedef struct _CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE {
    DWORD cbSize;
    PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_GET pfnGet;
    PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_RELEASE pfnRelease;
    PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_PASSWORD pfnFreePassword;
    PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE pfnFree;
    PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FREE_IDENTIFIER pfnFreeIdentifier;
  } CRYPT_OBJECT_LOCATOR_PROVIDER_TABLE,*PCRYPT_OBJECT_LOCATOR_PROVIDER_TABLE;

  typedef WINBOOL (WINAPI *PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_INITIALIZE) (PFN_CRYPT_OBJECT_LOCATOR_PROVIDER_FLUSH pfnFlush, LPVOID pContext, DWORD *pdwExpectedObjectCount, PCRYPT_OBJECT_LOCATOR_PROVIDER_TABLE *ppFuncTable, void **ppPluginContext);

  WINIMPM WINBOOL WINAPI CertIsWeakHash(DWORD dwHashUseType, LPCWSTR pwszCNGHashAlgid, DWORD dwChainFlags, PCCERT_CHAIN_CONTEXT pSignerChainContext, LPFILETIME pTimeStamp, LPCWSTR pwszFileName);

  typedef WINBOOL (WINAPI *PFN_CERT_IS_WEAK_HASH)(DWORD dwHashUseType, LPCWSTR pwszCNGHashAlgid, DWORD dwChainFlags, PCCERT_CHAIN_CONTEXT pSignerChainContext, LPFILETIME pTimeStamp, LPCWSTR pwszFileName);

#define CERT_FILE_HASH_USE_TYPE 1
#define CERT_TIMESTAMP_HASH_USE_TYPE 2

#endif
#endif

#endif

#ifdef __cplusplus
}
#endif

#ifndef _WINCRYPT_NO_DPAPI
#include <dpapi.h>
#endif
#endif
