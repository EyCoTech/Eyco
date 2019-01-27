// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2012 The Eyco developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef EYCO_INIT_H
#define EYCO_INIT_H

#include "wallet.h"

#include <memory>
#include <string>

namespace boost
{
class thread_group;
} // namespace boost

extern CWallet* pwalletMain;
void Interrupt();
void StartShutdown();
bool ShutdownRequested();
void Shutdown();
/**
 * Initialization sanity checks: ecc init, sanity checks, dir lock.
 * @note This can be done before daemonization. Do not call Shutdown() if this function fails.
 * @pre Parameters should be parsed and config file should be read, AppInitParameterInteraction should have been called.
 */
bool AppInitSanityChecks();

bool AppInit2(boost::thread_group& threadGroup);
std::string HelpMessage();
extern bool fOnlyTor;

#endif
