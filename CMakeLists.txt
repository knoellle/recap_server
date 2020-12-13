cmake_minimum_required(VERSION 3.12)

set(SOURCES
    source/blaze/client.cpp
    source/blaze/component/associationcomponent.cpp
    source/blaze/component/authcomponent.cpp
    source/blaze/component/gamemanagercomponent.cpp
    source/blaze/component/messagingcomponent.cpp
    source/blaze/component/playgroupscomponent.cpp
    source/blaze/component/redirectorcomponent.cpp
    source/blaze/component/roomscomponent.cpp
    source/blaze/component/usersessioncomponent.cpp
    source/blaze/component/utilcomponent.cpp
    source/blaze/server.cpp
    source/blaze/tdf.cpp
    source/databuffer.cpp
    source/game/api.cpp
    source/game/config.cpp
    source/game/creature.cpp
    source/game/game.cpp
    source/game/leaderboard.cpp
    source/game/userpart.cpp
    source/game/part.cpp
    source/game/squad.cpp
    source/game/template.cpp
    source/game/user.cpp
    source/http/multipart.cpp
    source/http/router.cpp
    source/http/server.cpp
    source/http/session.cpp
    source/http/uri.cpp
    source/main.cpp
    source/network/client.cpp
    source/raknet/client.cpp
    source/raknet/server.cpp
    source/repository/userpart.cpp
    source/repository/part.cpp
    source/repository/template.cpp
    source/repository/user.cpp
    source/tcptest.cpp
    source/udptest.cpp
    source/utils/base64.cpp
    source/utils/eawebkit.cpp
    source/utils/functions.cpp
    source/utils/json.cpp
    source/utils/xml.cpp
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-D_SILENCE_ALL_CXX17_DEPRECATION_WARNINGS -D_WIN32_WINNT=0x0601 -D_CRT_SECURE_NO_WARNINGS -DWIN32_LEAN_AND_MEAN -DNOMINMAX -DBOOST_NETWORK_ENABLE_HTTPS -DRAPIDJSON_HAS_STDSTRING)

project(recap_server VERSION 1.0.0)
add_executable(recap_server ${SOURCES})
include_directories(source/)
include_directories(source/raknet)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)

# Boost
set(Boost_INCLUDE_DIR libs/boost_1_70_0)
set(Boost_LIBRARY_DIR libs/boost_1_70_0/stage/lib)
find_package(Boost 1.70.0 REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})
target_link_libraries(recap_server ${Boost_LIBRARIES} )

# pugixml
add_subdirectory(libs/pugixml-1.10)
target_link_libraries(recap_server PUBLIC pugixml)

# RapidJSON
# set(RapidJSON_INCLUDE_DIRS libs/rapidjson-1.1.0/include)
# add_subdirectory(libs/rapidjson-1.1.0)
# target_link_libraries(recap_server ${RapidJSON_LIBRARIES})
find_package(RapidJSON)
# target_link_libraries(recap_server PUBLIC RapidJSON)
include_directories(${RapidJSON_INCLUDE_DIRS})

# RakNet
add_subdirectory(libs/raknet-3.902-mod)
# include_directories(/usr/include/raknet/)
include_directories(libs/raknet-3.902-mod/Source)
# target_link_libraries(recap_server PUBLIC /home/mystery/repos/resurrection-capsule/server/libs/raknet-3.902-mod/build/Lib/DLL/libRakNetDynamic.so)
target_link_libraries(recap_server PUBLIC ../libs/raknet-3.902-mod/build/Lib/DLL/libRakNetDynamic.so)

# OpenSSL
set(OPENSSL_ROOT_DIR libs/openssl-1.1.1b)
set(OPENSSL_INCLUDE_DIR libs/openssl-1.1.1b/include)
set(OPENSSL_CRYPTO_LIBRARY libs/openssl-1.1.1b/lib)
set(OPENSSL_CRYPTO_LIBRARY /home/mystery/repos/resurrection-capsule/server/libs/openssl-1.1.1b/lib/libcrypto.so)
set(OPENSSL_SSL_LIBRARY /home/mystery/repos/resurrection-capsule/server/libs/openssl-1.1.1b/lib/libssl.so)
set(OPENSSL_FIND_VERSION 1.1.1b)
find_package(OpenSSL REQUIRED)
target_link_libraries(recap_server PUBLIC ${OPENSSL_LIBRARIES} )

# target_link_libraries(recap_server PUBLIC OpenSSL::SSL ) #${OPENSSL_LIBRARIES} )
include_directories(${OPENSSL_INCLUDE_DIR})

# Threads
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(recap_server PRIVATE Threads::Threads)
