alias clang=clang-6.0
mkdir -p build/linux/
clang src/main.cpp $(< flags_linux.txt) -o build/linux/main