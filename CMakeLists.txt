# cmake_minimum_required(VERSION 3.0)
# project(my_project)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# add_library(my_api STATIC my_api.cpp do_another_stuff.cpp)

# add_library(standalone_fuzz_target_runner OBJECT standalone_fuzz_target_runner.cpp)

# # add_executable(do_stuff_unittest do_stuff_unittest.cpp)
# # target_link_libraries(do_stuff_unittest my_api)

# add_executable(do_stuff_fuzzer do_stuff_fuzzer.cpp)
# target_link_libraries(do_stuff_fuzzer my_api standalone_fuzz_target_runner)

# # add_executable(example_fuzzer example_fuzzer.cpp)
# # target_link_libraries(example_fuzzer my_api standalone_fuzz_target_runner)

cmake_minimum_required(VERSION 3.0)

project(do_stuff)

set(CXXFLAGS "-std=c++11")

if(NOT DEFINED ENV{LIB_FUZZING_ENGINE}) 
  set(LIB_FUZZING_ENGINE standalone_fuzz_target_runner)
endif(NOT DEFINED ENV{LIB_FUZZING_ENGINE})

add_library(my_api STATIC my_api.cpp my_api.h)
add_library(standalone_fuzz_target_runner OBJECT standalone_fuzz_target_runner.cpp)
# add_executable(do_stuff_unittest do_stuff_unittest.cpp)
# target_link_libraries(do_stuff_unittest my_api)

add_executable(do_stuff_fuzzer ${LIB_FUZZING_ENGINE} do_stuff_fuzzer.cpp)
target_compile_options(do_stuff_fuzzer PRIVATE $ENV{LIB_FUZZING_ENGINE})
target_link_libraries(do_stuff_fuzzer my_api $ENV{LIB_FUZZING_ENGINE})

# add_executable(example_fuzzer example_fuzzer.cpp)
# target_link_libraries(example_fuzzer my_api standalone_fuzz_target_runner)

add_custom_command(OUTPUT do_stuff_fuzzer_seed_corpus.zip
  COMMAND zip -q -r do_stuff_fuzzer_seed_corpus.zip do_stuff_test_data)

# add_custom_command(OUTPUT example_fuzzer_seed_corpus.zip
#   COMMAND zip -q -r example_fuzzer_corpus.zip do_stuff_test_data)

# add_custom_target(clean
#   COMMAND rm -fv *.a *.o *unittest *_fuzzer *_seed_corpus.zip crash-* *.zip)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
