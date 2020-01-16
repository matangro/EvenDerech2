cmake_minimum_required(VERSION 3.15)
project(EvenDerech2)

set(CMAKE_CXX_STANDARD 14)

add_executable(EvenDerech2 main.cpp Searchable.h Searcher.h State.h StateOfMetrix.h StateOfMetrix.cpp SearchableMetrix.h SearchableMetrix.cpp DfsSearcherMetrix.cpp DfsSearcherMetrix.h BfsSearcherMetrix.cpp BfsSearcherMetrix.h BestSearcherMetrix.cpp BestSearcherMetrix.h)