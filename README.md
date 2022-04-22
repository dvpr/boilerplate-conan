# Boilerplate for Conan package manager

First, install conan and cmake

And then

```
mkdir build && cd build
conan install ..
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .
./bin/ConanFirst
```