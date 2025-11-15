RPC Framework in C++ using POCO
<br>
This project implements a simple Remote Procedure Call (RPC) system using C++ and the POCO libraries.
A client sends JSON-based requests, and the server processes the request and returns a JSON response.
<br>
Features
<br>
Remote method invocation using TCP
<br>
JSON request/response
<br>
Supports:
<br>
reverse(text)
<br>
add(a, b)
<br>
subtract(a, b)
<br>
Basic error handling
<br>
Clean client–server architecture
<br>
How to Build
<br>
Install POCO using vcpkg:
<br>
vcpkg install poco
<br>

Configure the project:
<br>
cmake .. -DCMAKE_BUILD_TYPE=Release

<br>
Build:
<br>
cmake --build . --config Release
<br>
How to Run
<br>
Start server:
<br>
./rpc_server.exe
<br>

Run client:
<br>
./rpc_client.exe
<br>
Example Output
<br>
Client sends:
<br>
{"method":"reverse","params":{"text":"Hello RPC"}}
<br>

Server replies:
<br>
{"result":"CPR olleH"}
<br>
Project Structure
src/
 ├── client.cpp
 ├── server.cpp
 ├── rpc_dispatcher.cpp
 ├── rpc_dispatcher.h
 ├── serialization.cpp
 ├── serialization.h
 └── test_serialization.cpp
<br>
Summary
<br>
This project demonstrates how to build a basic RPC framework using C++, handling requests, responses, JSON parsing, and TCP communication using the POCO library.
