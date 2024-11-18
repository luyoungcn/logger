# logger
[![c](https://github.com/luyoungcn/resources/blob/master/images/c.svg)](https://github.com/luyoungcn/logger) &amp; [![c++](https://github.com/luyoungcn/resources/blob/master/images/cpp.svg)](https://github.com/luyoungcn/logger) wrapper of spdlog

## clone project
git clone --recursive git@github.com:luyoungcn/logger.git

## update submodule
cd logger
git submodule update


## build
mkdir build; cd build
cmake -DBUILD_SHARED_LIBS=ON -DUSE_EXTERNAL_SPDLOG=ON ..
make install
