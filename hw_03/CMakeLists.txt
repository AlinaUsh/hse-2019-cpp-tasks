cmake_minimum_required(VERSION 3.10)
project(hw_03)

set(CMAKE_CXX_STANDARD 17)

#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address")
#set(CMAKE_LINKER_FLAGS_DEBUG"${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=address")

include_directories(include)

add_executable(hw_03 src/main.cpp src/CLI.cpp include/CLI.h src/HuffmanArchiver.cpp include/HuffmanArchiver.h src/Huffman.cpp include/Huffman.h)
add_executable(test_hw_03 test/TestMain.cpp src/CLI.cpp include/CLI.h src/HuffmanArchiver.cpp include/HuffmanArchiver.h src/Huffman.cpp include/Huffman.h test/TestHuffmanNode.cpp test/TestHuffmanTree.cpp test/TestHuffmanArchiver.cpp test/TestCLI.cpp)