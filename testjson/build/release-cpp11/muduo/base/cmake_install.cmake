# Install script for directory: /home/wjz/CHAT/testjson/muduo-master/muduo/base

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/wjz/CHAT/testjson/build/release-install-cpp11")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/wjz/CHAT/testjson/build/release-cpp11/lib/libmuduo_base.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/muduo/base" TYPE FILE FILES
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/AsyncLogging.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/Atomic.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/BlockingQueue.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/BoundedBlockingQueue.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/Condition.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/CountDownLatch.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/CurrentThread.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/Date.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/Exception.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/FileUtil.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/GzipFile.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/LogFile.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/LogStream.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/Logging.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/Mutex.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/ProcessInfo.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/Singleton.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/StringPiece.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/Thread.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/ThreadLocal.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/ThreadLocalSingleton.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/ThreadPool.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/TimeZone.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/Timestamp.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/Types.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/WeakCallback.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/copyable.h"
    "/home/wjz/CHAT/testjson/muduo-master/muduo/base/noncopyable.h"
    )
endif()

