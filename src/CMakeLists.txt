# Build statically
add_definitions(-DSTATICLIB)

# Add external libraries as include dirs, so we can do #include "httplib" for example
include_directories(${CMAKE_SOURCE_DIR}/external/argon2/include)

# Show cmake where the source files are
# Note, if you add remove a source file, 
# you will need to re-run cmake so it
# can find the new file
file(GLOB_RECURSE BlockchainExplorer BlockchainExplorer/*)
file(GLOB_RECURSE Common Common/*)
#file(GLOB_RECURSE ConnectivityTool ConnectivityTool/*)
file(GLOB_RECURSE Crypto crypto/*)
file(GLOB_RECURSE CryptoNoteCore CryptoNoteCore/* CryptoNoteConfig.h)
file(GLOB_RECURSE CryptoNoteProtocol CryptoNoteProtocol/*)
file(GLOB_RECURSE Daemon Daemon/*)
file(GLOB_RECURSE Http HTTP/*)
file(GLOB_RECURSE InProcessNode InProcessNode/*)
file(GLOB_RECURSE Logging Logging/*)
file(GLOB_RECURSE NodeRpcProxy NodeRpcProxy/*)
file(GLOB_RECURSE P2p P2p/*)
file(GLOB_RECURSE Rpc Rpc/*)
file(GLOB_RECURSE Serialization Serialization/*)
file(GLOB_RECURSE SimpleWallet SimpleWallet/*)

if(MSVC)
file(GLOB_RECURSE System System/* Platform/Windows/System/*)
elseif(APPLE)
file(GLOB_RECURSE System System/* Platform/OSX/System/*)
else()
file(GLOB_RECURSE System System/* Platform/Linux/System/*)
endif()
file(GLOB_RECURSE Transfers Transfers/*)
file(GLOB_RECURSE Wallet Wallet/*)
file(GLOB_RECURSE WalletLegacy WalletLegacy/*)

file(GLOB_RECURSE JsonRpcServer JsonRpcServer/*)

file(GLOB_RECURSE PaymentGate PaymentGate/*)
file(GLOB_RECURSE PaymentGateService PaymentGateService/*)
file(GLOB_RECURSE Miner Miner/*)
file(GLOB_RECURSE Mnemonics mnemonics/*)
file(GLOB_RECURSE hdwallet hdwallet/*)

# Group the files together in IDEs
source_group("" FILES $${Common} ${Crypto} ${CryptoNoteCore} ${CryptoNoteProtocol} ${Daemon} ${JsonRpcServer} ${Http} ${Logging} ${NodeRpcProxy} ${P2p} ${Rpc} ${Serialization} ${SimpleWallet} ${System} ${Transfers} ${Wallet} ${WalletLegacy} ${Mnemonics} ${hddwallet})

# Define a group of files as a library to link against
add_library(BlockchainExplorer STATIC ${BlockchainExplorer})
add_library(Common STATIC ${Common})
add_library(Crypto STATIC ${Crypto})
add_library(CryptoNoteCore STATIC ${CryptoNoteCore})
add_library(Http STATIC ${Http})
add_library(InProcessNode STATIC ${InProcessNode})
add_library(Logging STATIC ${Logging})
###
add_library(Mnemonics STATIC ${Mnemonics})
add_library(NodeRpcProxy STATIC ${NodeRpcProxy})
add_library(Rpc STATIC ${Rpc})
add_library(P2P STATIC ${CryptoNoteProtocol} ${P2p})
add_library(Serialization STATIC ${Serialization})
add_library(System STATIC ${System})
add_library(Transfers STATIC ${Transfers})
add_library(Wallet STATIC ${Wallet} ${WalletLegacy})
add_library(PaymentGate STATIC ${PaymentGate})
add_library(JsonRpcServer STATIC ${JsonRpcServer})

#add_executable(ConnectivityTool ${ConnectivityTool})
add_executable(Daemon ${Daemon})
add_executable(SimpleWallet ${SimpleWallet})
add_executable(PaymentGateService ${PaymentGateService})
add_executable(Miner ${Miner})
###
add_executable(hdwallet ${hdwallet})

if (MSVC)
  target_link_libraries(System ws2_32)
endif ()


# A bit of hackery so we don't have to do the if/else/ for every target that
# wants to use filesystem
add_library(__filesystem INTERFACE)

# Windows works out of the box
if (APPLE)
    target_link_libraries(__filesystem INTERFACE /usr/local/opt/llvm/lib/libc++fs.a)
elseif (UNIX)
    target_link_libraries(__filesystem INTERFACE stdc++fs)
endif()

# Add the dependencies we need

target_link_libraries(Daemon System CryptoNoteCore ${Boost_LIBRARIES})
target_link_libraries(Common __filesystem)
target_link_libraries(CryptoNoteCore Common Logging Crypto P2P Rpc Http Serialization System ${Boost_LIBRARIES})
target_link_libraries(Logging Common)
target_link_libraries(P2P CryptoNoteCore upnpc-static)
target_link_libraries(Rpc P2P)


#target_link_libraries(ConnectivityTool CryptoNoteCore Common Logging Crypto P2P Rpc Http Serialization System ${Boost_LIBRARIES})
target_link_libraries(Crypto argon2-static)
target_link_libraries(Daemon CryptoNoteCore P2P Rpc Serialization System Http Logging Common Crypto upnpc-static BlockchainExplorer ${Boost_LIBRARIES})
target_link_libraries(SimpleWallet Wallet NodeRpcProxy Transfers Rpc Http Serialization CryptoNoteCore System Logging Common Crypto ${Boost_LIBRARIES})
target_link_libraries(PaymentGateService PaymentGate JsonRpcServer Wallet NodeRpcProxy Transfers CryptoNoteCore Crypto P2P Rpc Http Serialization System Logging Common InProcessNode upnpc-static BlockchainExplorer ${Boost_LIBRARIES})
target_link_libraries(Miner CryptoNoteCore Rpc Serialization System Http Logging Common Crypto ${Boost_LIBRARIES})
target_link_libraries(hdwallet Mnemonics Wallet NodeRpcProxy Transfers Rpc Http CryptoNoteCore System Logging Common ${Boost_LIBRARIES} Serialization Crypto)

add_dependencies(Rpc version)

#add_dependencies(ConnectivityTool version)
add_dependencies(Daemon version)
add_dependencies(SimpleWallet version)
add_dependencies(PaymentGateService version)
add_dependencies(P2P version)
add_dependencies(hdwallet version)

#set_property(TARGET ConnectivityTool PROPERTY OUTPUT_NAME "sldt")
set_property(TARGET SimpleWallet PROPERTY OUTPUT_NAME "sldw")
set_property(TARGET PaymentGateService PROPERTY OUTPUT_NAME "sldp")
set_property(TARGET Miner PROPERTY OUTPUT_NAME "sldm")
set_property(TARGET Daemon PROPERTY OUTPUT_NAME "sldd")
set_property(TARGET hdwallet PROPERTY OUTPUT_NAME "sldwhd")

