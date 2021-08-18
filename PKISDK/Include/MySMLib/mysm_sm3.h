/* ====================================================================
 * Copyright (c) 2014 - 2016 The GmSSL Project.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgment:
 *    "This product includes software developed by the GmSSL Project.
 *    (http://gmssl.org/)"
 *
 * 4. The name "GmSSL Project" must not be used to endorse or promote
 *    products derived from this software without prior written
 *    permission. For written permission, please contact
 *    guanzhi1980@gmail.com.
 *
 * 5. Products derived from this software may not be called "GmSSL"
 *    nor may "GmSSL" appear in their names without prior written
 *    permission of the GmSSL Project.
 *
 * 6. Redistributions of any form whatsoever must retain the following
 *    acknowledgment:
 *    "This product includes software developed by the GmSSL Project
 *    (http://gmssl.org/)"
 *
 * THIS SOFTWARE IS PROVIDED BY THE GmSSL PROJECT ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE GmSSL PROJECT OR
 * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 * ====================================================================
 */

#ifndef MYSM_HEADER_SM3_H
#define MYSM_HEADER_SM3_H

#define MYSM_SM3_DIGEST_LENGTH	32
#define MYSM_SM3_BLOCK_SIZE		64
#define MYSM_SM3_CBLOCK			(MYSM_SM3_BLOCK_SIZE)
#define MYSM_SM3_HMAC_SIZE		(MYSM_SM3_DIGEST_LENGTH)


#include <sys/types.h>
// #include <stdint.h>
#include <string.h>

typedef unsigned int uint32_t;

#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
	uint32_t digest[8];
	int nblocks;
	unsigned char block[64];
	int num;
} mysm_sm3_ctx_t;

void mysm_sm3_init(mysm_sm3_ctx_t *ctx);
void mysm_sm3_update(mysm_sm3_ctx_t *ctx, const unsigned char* data, size_t data_len);
void mysm_sm3_final(mysm_sm3_ctx_t *ctx, unsigned char digest[MYSM_SM3_DIGEST_LENGTH]);
void mysm_sm3_compress(uint32_t digest[8], const unsigned char block[MYSM_SM3_BLOCK_SIZE]);
void mysm_sm3(const unsigned char *data, size_t datalen,
	unsigned char digest[MYSM_SM3_DIGEST_LENGTH]);


typedef struct {
	mysm_sm3_ctx_t sm3_ctx;
	unsigned char key[MYSM_SM3_BLOCK_SIZE];
} mysm_sm3_hmac_ctx_t;

void mysm_sm3_hmac_init(mysm_sm3_hmac_ctx_t *ctx, const unsigned char *key, size_t key_len);
void mysm_sm3_hmac_update(mysm_sm3_hmac_ctx_t *ctx, const unsigned char *data, size_t data_len);
void mysm_sm3_hmac_final(mysm_sm3_hmac_ctx_t *ctx, unsigned char mac[MYSM_SM3_HMAC_SIZE]);
void mysm_sm3_hmac(const unsigned char *data, size_t data_len,
	const unsigned char *key, size_t key_len, unsigned char mac[MYSM_SM3_HMAC_SIZE]);

#ifdef __cplusplus
}
#endif
#endif
