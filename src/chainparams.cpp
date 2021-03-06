// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Eyco developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "assert.h"

#include "chainparams.h"
#include "main.h"
#include "util.h"
#include "checkpoints.h"

#include <boost/assign/list_of.hpp>

using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"
//
// Main network
//

// Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress> &vSeedsOut, const SeedSpec6 *data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++)
    {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

class CMainParams : public CChainParams {
public:
    CMainParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xc1;
        pchMessageStart[1] = 0x63;
        pchMessageStart[2] = 0xaf;
        pchMessageStart[3] = 0xd6;
        vAlertPubKey = ParseHex("049be17f0bab053cd9f161528241bc9a2894ad5ebeb9fd13c016ed9a2f222989769417ed3a16e6fbf3bd5502367bbd551be1a4bd2d10cdb679228c91e26e26900e");
        nDefaultPort = 10827;
        nRPCPort = 10823;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 14);

        const char* pszTimestamp = "https://www.bbc.co.uk/news/world-us-canada-46150847"; // Thousand Oaks: Las Vegas shooting survivor among dead
        std::vector<CTxIn> vin;
        vin.resize(1);
        vin[0].scriptSig = CScript() << 4837915 << CBigNum(88) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        std::vector<CTxOut> vout;
        vout.resize(1);
        vout[0].SetEmpty();
        CTransaction txNew(1, 1541781433, vin, vout, 0);
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime    = 1541781433;
        genesis.nBits    = 0x1f00ffff; 
        genesis.nNonce   = 557643;

        hashGenesisBlock = genesis.GetHash();

        assert(hashGenesisBlock == uint256("0x64fa0bfdd6613ee89198d680567d858765ced5c1fb02d7312ac71609cf0ca6d5"));
        assert(genesis.hashMerkleRoot == uint256("0xc23ac15dfd0fdd3eeb684a97e6329e88e048579eb7d3d108b8678935ba5d05ee"));

        
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,29);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,58);
        base58Prefixes[SECRET_KEY] =     std::vector<unsigned char>(1,116);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x04)(0x88)(0x4B)(0xEF).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x04)(0x88)(0x9D)(0x7B).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        nPOSStartBlock = 100;
    }

    virtual const CBlock& GenesisBlock() const { return genesis; }
    virtual Network NetworkID() const { return CChainParams::MAIN; }

    virtual const vector<CAddress>& FixedSeeds() const {
        return vFixedSeeds;
    }
protected:
    CBlock genesis;
    vector<CAddress> vFixedSeeds;
};
static CMainParams mainParams;


//
// Testnet
//

class CTestNetParams : public CMainParams {
public:
    CTestNetParams() {
        // The message start string is designed to be unlikely to occur in normal data.
        // The characters are rarely used upper ASCII, not valid as UTF-8, and produce
        // a large 4-byte int at any alignment.
        pchMessageStart[0] = 0xd3;
        pchMessageStart[1] = 0x6a;
        pchMessageStart[2] = 0x05;
        pchMessageStart[3] = 0x3e;
        bnProofOfWorkLimit = CBigNum(~uint256(0) >> 12);
        vAlertPubKey = ParseHex("049be17f0bab053cd9f161528241bc9a2894ad5ebeb9fd13c016ed9a2f222989769417ed3a16e6fbf3bd5502367bbd551be1a4bd2d10cdb679228c91e26e26900e");
        nDefaultPort = 20827;
        nRPCPort = 20823;
        strDataDir = "testnet";

        // Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nBits  = 51294380; 
        genesis.nNonce = 67512;

        //assert(hashGenesisBlock == uint256(""));

        vFixedSeeds.clear();
        vSeeds.clear();

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1,30);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1,60);
        base58Prefixes[SECRET_KEY]     = std::vector<unsigned char>(1,100);
        base58Prefixes[EXT_PUBLIC_KEY] = list_of(0x06)(0x66)(0x13)(0xA4).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = list_of(0x06)(0x66)(0xA8)(0xF2).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        nPOSStartBlock = 1;

    }
    virtual Network NetworkID() const { return CChainParams::TESTNET; }
};
static CTestNetParams testNetParams;


static CChainParams *pCurrentParams = &mainParams;

const CChainParams &Params() {
    return *pCurrentParams;
}

void SelectParams(CChainParams::Network network) {
    switch (network) {
        case CChainParams::MAIN:
            pCurrentParams = &mainParams;
            break;
        case CChainParams::TESTNET:
            pCurrentParams = &testNetParams;
            break;
        default:
            assert(false && "Unimplemented network");
            return;
    }
}

bool SelectParamsFromCommandLine() {
    
    bool fTestNet = GetBoolArg("-testnet", false);
    
    if (fTestNet) {
        SelectParams(CChainParams::TESTNET);
    } else {
        SelectParams(CChainParams::MAIN);
    }
    return true;
}
