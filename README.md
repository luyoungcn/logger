# logger
[<img src="https://github.com/luyoungcn/resources/blob/master/images/c.svg" width=30/>](https://github.com/luyoungcn/logger) &amp; [<img src="https://github.com/luyoungcn/resources/blob/master/images/cpp.svg" width=30/>](https://github.com/luyoungcn/logger) wrapper of spdlog

## clone project
git clone --recursive git@github.com:luyoungcn/logger.git

## update submodule
cd logger
git submodule update


## build
mkdir build; cd build
cmake -DBUILD_SHARED_LIBS=ON -DUSE_EXTERNAL_SPDLOG=ON ..
make install
