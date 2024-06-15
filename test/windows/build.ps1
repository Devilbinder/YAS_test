mkdir build -ErrorAction SilentlyContinue
cd build
cmake -G "MinGW Makefiles" ..
cmake --build .