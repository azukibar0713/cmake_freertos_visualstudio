# ----------------------------
# 必要な最小バージョンを指定
# ----------------------------
cmake_minimum_required(VERSION 3.1)

# ----------------------------
# プロジェクト名, 言語(C言語)を指定.
# ----------------------------
project(freertos_project C CXX)

# 以下のFREERTOS_INCLUDE_DIRを
# include_directories($ENV{FREERTOS_INCLUDE_DIR})
# としても各pathの設定はできなかった.スペース区切りの引数を認識しない.
#set(ENV{FREERTOS_INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/src/ ${PROJECT_SOURCE_DIR}/FreeRTOS/Source/include/\ ${PROJECT_SOURCE_DIR}/FreeRTOS/Source/portable/MemMag/\ ${PROJECT_SOURCE_DIR}/FreeRTOS/Source/portable/MSVC-MingW/)
#message($ENV{FREERTOS_INCLUDE_DIR})

set(ENV{FREERTOS_CONFIG_DIR} ${PROJECT_SOURCE_DIR}/src/)
set(ENV{FREERTOS_INCLUDE_DIR} ${PROJECT_SOURCE_DIR}/FreeRTOS/Source/include/)
set(ENV{FREERTOS_MEMMAG_DIR} ${PROJECT_SOURCE_DIR}/FreeRTOS/Source/portable/MemMag/)
set(ENV{FREERTOS_PORTABLE_DIR} ${PROJECT_SOURCE_DIR}/FreeRTOS/Source/portable/MSVC-MingW/)



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
# CMakeList.txtがあるサブディレクトリ追加.
# ----------------------------
add_subdirectory(./gtest)

# ----------------------------
# include directory
#   Makefile の -include 命令や，コンパイラでの -I オプションは include_directories で代用.
# [TODO]
#   include_directoriesは下位のCMakeLists.txtに反映するのでtarget_include_directoriesを使う.
# ----------------------------
include_directories(./src)
include_directories($ENV{FREERTOS_CONFIG_DIR})
include_directories($ENV{FREERTOS_INCLUDE_DIR})
include_directories($ENV{FREERTOS_MEMMAG_DIR})
include_directories($ENV{FREERTOS_PORTABLE_DIR})

# ----------------------------
# コンパイル対象のソース一覧を作成
#   - 指定されたGLOBパターン<globbing_expressions>にマッチするファイルを探索し、その一覧をリストとして変数<variable>に格納します。
#     このとき絶対パスで格納されますが、RELATIVE <path>が指定されていると、このパスからの相対パスとなります。
#   - 以下の正規表現のメタ文字に似たものが使えます。
#       - 任意の文字の0回以上の繰り返し*
#       - 任意の文字?
#       - ブラケット内で指定された文字[ ]とその範囲
# フォーマット
#   file(WRITE <filename> [<content1> ...])
#   file(APPEND <filename> [<content1> ...])
# filenameがVCだとプロジェクト名になるみたい.
# ----------------------------
file(GLOB freertos_files FreeRTOS/Source/*.[ch] FreeRTOS/Source/portable/MSVC-MingW/*.[ch] FreeRTOS/Source/portable/MemMang/*.[ch])
file(GLOB src_files src/*.[ch] src/Supporting_Functions/*.[ch])

# ----------------------------
# オブジェクトファイルを作るソースを指定
# ----------------------------
add_library(freertos OBJECT ${freertos_files})
add_library(src OBJECT ${src_files})

# ----------------------------
# VisualStudioのFilterを作るようにする.
# ----------------------------
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


# ----------------------------
# 実行ファイルを作る方法を指定
# ----------------------------
add_executable(${PROJECT_NAME}
 $<TARGET_OBJECTS:freertos>
 $<TARGET_OBJECTS:src>
)


