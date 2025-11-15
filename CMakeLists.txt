cmake_minimum_required(VERSION 3.10)
project(poco_rpc)

# Force C++17 (IMPORTANT)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Poco REQUIRED Foundation Net JSON Util XML)

include_directories(${Poco_INCLUDE_DIRS})

add_executable(rpc_server
    src/server.cpp
    src/serialization.cpp
   
)

add_executable(rpc_client
    src/client.cpp
    src/serialization.cpp
    src/rpc_client_lib.h

)

add_executable(test_serialization
    src/test_serialization.cpp
    src/serialization.cpp
)

target_link_libraries(rpc_server PRIVATE Poco::Foundation Poco::Net Poco::JSON Poco::Util Poco::XML)
target_link_libraries(rpc_client PRIVATE Poco::Foundation Poco::Net Poco::JSON Poco::Util Poco::XML)
target_link_libraries(test_serialization PRIVATE Poco::Foundation Poco::JSON)
