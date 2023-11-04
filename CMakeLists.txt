cmake_minimum_required(VERSION 3.0)


SET(CMAKE_C_COMPILER "E:/opencv/Dev-Cpp/TDM-GCC-64/bin/gcc.exe")
SET(CMAKE_CXX_COMPILER "E:/opencv/Dev-Cpp/TDM-GCC-64/bin/g++.exe") 

# add_compile_options(-G = "Unix Makefile")

project(CPP_Cherno)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpermissive")

set(CMAKE_CXX_STANDARD 14)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# if (CMAKE_BUILD_TYPE STREQUAL "Debug")
#     set(CMAKE_DEBUG_POSTFIX "_d")
#     set(CMAKE_EXECUTABLE_SUFFIX "_d")
# endif()

message(STATUS "CMAKE_BUILD_TYPE = ${CMAKE_BUILD_TYPE}")
# set(SOURCE main.cc)

# 添加所有.cc文件到 SOURCE中
file(GLOB_RECURSE SRC_DIR_LIST src/*.cc)

# SOURCE生成库文件，SHARED 动态库(.dll)， 静态库(.a)
# add_library(MyLibrary SHARED ${SRC_DIR_LIST})
add_library(MyLibrary STATIC ${SRC_DIR_LIST})

#打印SRC_DIR_LIST中内容
message(STATUS "SRC_DIR_LIST = ${SRC_DIR_LIST}")

#头文件包含文件
# include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_path(INCLUDE_PATH test.h
          HINTS ${CMAKE_CURRENT_SOURCE_DIR}/include
          DOC "Path to my_header.h")
include_directories(${INCLUDE_PATH})
# include_directories(./include)
message(STATUS "INCLUDE_PATH = ${INCLUDE_PATH}")

#查找Opencv库
# set(OpenCV_DIR "E:\\opencv\\opencv-4.7.0\\opencv-4.7.0\\build")

find_package(OpenCV REQUIRED)

#生成可执行文件
# add_executable(${PROJECT_NAME} ${SRC_DIR_LIST})
add_executable(${PROJECT_NAME} src/P58_function_pointer.cc)
add_executable(${PROJECT_NAME}_P59 src/P59_Lambda.cc)
add_executable(${PROJECT_NAME}_P62 src/P62_thread.cc)
add_executable(${PROJECT_NAME}_P63 src/P63_timer.cc)
add_executable(${PROJECT_NAME}_P64 src/P64_sort.cc)
add_executable(P65_${PROJECT_NAME} src/P65_pointer_type.cc)
add_executable(P66_${PROJECT_NAME} src/P66_union.cc)
add_executable(P67_${PROJECT_NAME} src/P67_virtual_dtor.cc)

#添加OpenCV头文件路径
include_directories(${OpenCV_INCLUDE_DIRS})
#链接OpenCV库文件
# link_directories(${OpenCV_LIBRARY_DIRS})
# message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
# message(STATUS "OpenCV_LIBRARY_DIRS = ${OpenCV_LIBRARY_DIRS}")

#OpenCV库文件添加到项目或者动态库中
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

#自动查找头文件路径函数(没有去重)
# macro(FIND_INCLUDE_DIR result curdir)  #定义函数,2个参数:存放结果result；指定路径curdir；
#     file(GLOB_RECURSE children "${curdir}/*.hpp" "${curdir}/*.h" )	#遍历获取{curdir}中*.hpp和*.h文件列表
#     message(STATUS "children= ${children}")								#打印*.hpp和*.h的文件列表
#     set(dirlist "")														#定义dirlist中间变量，并初始化
#     foreach(child ${children})											#for循环
#         string(REGEX REPLACE "(.*)/.*" "\\1" LIB_NAME ${child})			#字符串替换,用/前的字符替换/*h
#         if(IS_DIRECTORY ${LIB_NAME})									#判断是否为路径
#             LIST(APPEND dirlist ${LIB_NAME})							#将合法的路径加入dirlist变量中
#         endif()															#结束判断
#     endforeach()														#结束for循环
#     set(${result} ${dirlist})											#dirlist结果放入result变量中
# endmacro()																#函数结束


#查找include目录下的所有*.hpp,*.h头文件,并路径列表保存到 INCLUDE_DIR_LIST 变量中
# FIND_INCLUDE_DIR(INCLUDE_DIR_LIST ${PROJECT_SOURCE_DIR} .)			#调用函数，指定参数

#将INCLUDE_DIR_LIST中路径列表加入工程		
# include_directories(   													#INCLUDE_DIR_LIST路径列表加入工程
#         ${INCLUDE_DIR_LIST}
# )

# message(STATUS "INCLUDE_DIR_LIST = ${INCLUDE_DIR_LIST}")				#打印INCLUDE_DIR_LIST中列表信息

