### How to run program on Ubuntu 18.04 / 19.10

Install necessary packages

```bash
sudo apt-get -y install libboost-dev
sudo apt-get -y install cmake
```

Clone repository, build and make

```bash
git clone https://github.com/janwawruszczak1998/NokiaMessenger.git
cd NokiaMessenger
mkdir build
cd build
cmake ../
make
```

In two separate terminal windows run client and server on the same port

Terminal 1:

```bash
./ServerMessenger 2137
```

Terminal 2:

```bash
./ClientMessenger 2137
```

