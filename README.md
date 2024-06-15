# YAS_test
Yet Another Scheduler testing

## Windows build commands
```
mkdir build -ErrorAction SilentlyContinue
cd build
cmake -G "MinGW Makefiles" ..
cmake --build .
```

## Ubuntu Linux build commands
mkdir -p build
cd build
cmake ..
cmake --build .

## Docker commands
docker build . -t c_build
docker-compose up
docker-compose exec yas bash

