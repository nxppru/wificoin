// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "primitives/block.h"

#include "hash.h"
#include "tinyformat.h"
#include "utilstrencodings.h"
#include "crypto/common.h"
#include "validation.h"

uint256 CBlockHeader::GetGenesisHash() const
{
	return SerializeHash(*this);
}

uint256 CBlockHeader::GetHash() const
{
	int hashSelection = (nTime > Params().GetSwitchTime())?1:0;
	switch(hashSelection) {
	case 1:
		return SerializeHashV2(BEGIN(nVersion), END(nNonce));		
	default:
		return SerializeHash(*this);
	}
}

std::string CBlock::ToString() const
{
    std::stringstream s;
    s << strprintf(
		"CBlock(hash=%s, ohash=%s, ver=0x%08x, hashPrevBlock=%s, hashMerkleRoot=%s, nTime=%u, nBits=%08x, nNonce=%u, vtx=%u, switchTime=%u, hashSelection=%d)\n",
        GetHash().ToString(),
		GetGenesisHash().ToString(),
        nVersion,
        hashPrevBlock.ToString(),
        hashMerkleRoot.ToString(),
        nTime, nBits, nNonce,
        vtx.size(),
		Params().GetSwitchTime(),
		(nTime > Params().GetSwitchTime())?1:0);
    for (const auto& tx : vtx) {
        s << "  " << tx->ToString() << "\n";
    }
    return s.str();
}
