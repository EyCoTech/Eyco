VERSION NOTES
==============


V1 (No changes here as its the first release)

EyCo Quark Crytocurrency V1 Official Release.
Stable Client.



V1.1

Stake Confirmations Corrected to 66 blocks instead of 200 blocks
Shutdown process for Windows OS has been addressed
Update to Network Nodes
Updated Checkpoints
Information corrected to display properly
Some small minor changes.




UNIX BUILD NOTES
=================
Some notes on how to build Eyco in Unix.

To Build Eyco Headless 
-----------------

sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils

sudo apt-get install qt5-default qt5-qmake qtbase5-dev-tools qttools5-dev-tools build-essential libboost-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libssl-dev libdb++-dev libminiupnpc-dev 

sudo apt-get install software-properties-common	
sudo add-apt-repository ppa:bitcoin/bitcoin	
sudo apt-get update	
sudo apt-get install libdb4.8-dev libdb4.8++-dev

sudo apt-get install libqrencode-dev

git clone https://github.com/EyCoTech/Eyco.git

cd Eyco/src/secp256k1

chmod +x autogen.sh

./autogen.sh

./configure

make

sudo make install

cd

cd Eyco/src/leveldb

sudo sh build_detect_platform build_config.mk .

cd

cd Eyco/src

sudo make -f makefile.unix

strip eycod

LD_LIBRARY_PATH=/usr/local/lib

export LD_LIBRARY_PATH


To Build Eyco Qt Wallet
------------------

sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils

sudo apt-get install qt5-default qt5-qmake qtbase5-dev-tools qttools5-dev-tools build-essential libboost-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libssl-dev libdb++-dev libminiupnpc-dev 

sudo apt-get install software-properties-common	
sudo add-apt-repository ppa:bitcoin/bitcoin	
sudo apt-get update 
sudo apt-get install libdb4.8-dev libdb4.8++-dev

sudo apt-get install libqrencode-dev

git clone https://github.com/EyCoTech/Eyco.git

cd Eyco/src/secp256k1

chmod +x autogen.sh

./autogen.sh

./configure

make 

sudo make install

cd

cd Eyco/src/leveldb

sh build_detect_platform build_config.mk .

cd

cd Eyco

qmake Eyco-qt.pro

make -jnumofcoreshere


COPYRIGHT
==========

Copyright (c) 2018 The Eyco Developers
Distributed under the MIT/X11 software license, see the accompanying
file license.txt or http://www.opensource.org/licenses/mit-license.php.
This product includes software developed by the OpenSSL Project for use in
the OpenSSL Toolkit (http://www.openssl.org/).  This product includes
cryptographic software written by Eric Young (eay@cryptsoft.com) and UPnP
software written by Thomas Bernard.