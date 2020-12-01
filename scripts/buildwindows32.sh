cd ..
sudo apt update
sudo apt upgrade
sudo apt install build-essential libtool autotools-dev automake pkg-config bsdmainutils curl git
sudo apt-get install libqt5gui5 libqt5core5a libqt5dbus5 qttools5-dev qttools5-dev-tools libprotobuf-dev protobuf-compiler

sudo apt-get install software-properties-common
sudo add-apt-repository ppa:bitcoin/bitcoin
sudo apt-get update
sudo apt-get install libdb4.8-dev libdb4.8++-dev
sudo apt-get install libboost-system-dev libboost-filesystem-dev libboost-chrono-dev libboost-program-options-dev libboost-test-dev libboost-thread-dev
sudo apt-get install libzmq3-dev -y
sudo apt-get install libminiupnpc-dev -y
sudo apt-get install libgmp3-dev libevent-dev bsdmainutils libboost-all-dev openssl -y

sudo apt install g++-mingw-w64-i686 mingw-w64-i686-dev
sudo update-alternatives --config i686-w64-mingw32-g++
PATH=$(echo "$PATH" | sed -e 's/:\/mnt.*//g') # strip out problematic Windows %PATH% imported var
cd depends
make -j$(nproc) HOST=i686-w64-mingw32

cd ..
cd scripts
bash build-win32.sh
