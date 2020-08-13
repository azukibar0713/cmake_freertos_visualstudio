# ----------------------------
# 必要な最小バージョンを指定
# ----------------------------
cmake_minimum_required(VERSION 3.1)

# ----------------------------
# プロジェクト名, 言語(C言語)を指定.
# ----------------------------
project(freertos_project C CXX)

set(ENV{FREERTOS_CONFIG_DIR} ${PROJECT_SOURCE_DIR}/user_app/include/)
set(ENV{FREERTOS_INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/FreeRTOS/Source/include/)
set(ENV{FREERTOS_MEMMAG_DIR} ${PROJECT_SOURCE_DIR}/FreeRTOS/Source/portable/MemMag/)
set(ENV{FREERTOS_PORTABLE_DIR} ${PROJECT_SOURCE_DIR}/FreeRTOS/Source/portable/MSVC-MingW/)

# ----------------------------
# 本物 or Mock.
# ----------------------------
if (MSVC)
  set(USE_MOCK_DRIVER 1)
endif()

# ----------------------------
# コンパイルオプション.
# ----------------------------
if (MSVC)
    add_definitions(/source-charset:utf-8)
endif()
# マクロを定義する（プログラム内で#define MY_DEFINE と書くのと同じ）
# add_compile_options(-D MY_DEFINE)
# warningはcompile errorにはしない.
if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX-)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

# ----------------------------
# GoogleTest libを使ったときのruntime library不一致対策.
# ----------------------------
if(MSVC)
string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_MINSIZEREL ${CMAKE_C_FLAGS_MINSIZEREL})
string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})
string(REPLACE "/MD" "/MT" CMAKE_C_FLAGS_RELWITHDEBINFO ${CMAKE_C_FLAGS_RELWITHDEBINFO})
string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_MINSIZEREL ${CMAKE_CXX_FLAGS_MINSIZEREL})
string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE})
string(REPLACE "/MD" "/MT" CMAKE_CXX_FLAGS_RELWITHDEBINFO ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
endif(MSVC)

# ----------------------------
# include directory
#   Makefile の -include 命令や，コンパイラでの -I オプションは include_directories で代用.
# [TODO]
#   include_directoriesは下位のCMakeLists.txtに反映するのでtarget_include_directoriesを使う.
# ----------------------------
include_directories($ENV{FREERTOS_CONFIG_DIR})
include_directories($ENV{FREERTOS_INCLUDE_DIR})
include_directories($ENV{FREERTOS_MEMMAG_DIR})
include_directories($ENV{FREERTOS_PORTABLE_DIR})

# ----------------------------
# コンパイル対象のソース一覧を作成
# ----------------------------
#file(GLOB freertos_files FreeRTOS/Source/*.[ch] FreeRTOS/Source/portable/MSVC-MingW/*.[ch] FreeRTOS/Source/portable/MemMang/*.[ch])
#file(GLOB src_files ./user_app/src/*.[ch] src/Supporting_Functions/*.[ch])


if(USE_MOCK_DRIVER)
  message("Use Mock Driver")
  file(GLOB DRIVER_FILES ./gtest/mock_driver/*.cpp)
elseif(USE_MOCK_DRIVER)
  file(GLOB DRIVER_FILES ./user_app/driver/*.c)
endif(USE_MOCK_DRIVER)


# ----------------------------
# オブジェクトファイルを作るソースを指定
# ----------------------------
#add_library(freertos OBJECT ${freertos_files} ${driver_files})
#add_library(user_app OBJECT ${src_files})

# ----------------------------
# VisualStudioのFilterを作るようにする.
# ----------------------------
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


# ----------------------------
# CMakeList.txtがあるサブディレクトリ追加.
# ----------------------------
add_subdirectory(./FREERTOS)
add_subdirectory(./user_app)
add_subdirectory(./gtest)


# ----------------------------
# 実行ファイルを作る方法を指定
# ----------------------------
#add_executable(${PROJECT_NAME}
# $<TARGET_OBJECTS:freertos>
# $<TARGET_OBJECTS:user_app>
#)


