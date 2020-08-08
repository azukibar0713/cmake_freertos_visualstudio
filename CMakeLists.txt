# 参考サイト.
# https://wakame.hatenablog.jp/entry/2017/04/16/151226
# http://www.dcom-web.co.jp/technology/post20/
# https://qiita.com/mrk_21/items/5e7ca775b463a4141a58

cmake_minimum_required(VERSION 3.1)

# プロジェクト名, C言語
project(freertos_project C)

# include directory
# Makefile の -include 命令や，コンパイラでの -I オプションは include_directories で代用します．
include_directories(./src)
include_directories(./src/Supporting_Functions)
include_directories(./FreeRTOS/Source/include)
include_directories(./FreeRTOS/Source/portable/MemMang)
include_directories(./FreeRTOS/Source/portable/MSVC-MingW)

# コンパイル対象のソース一覧を作成
# 指定されたGLOBパターン<globbing_expressions>にマッチするファイルを探索し、その一覧をリストとして変数<variable>に格納します。
# このとき絶対パスで格納されますが、RELATIVE <path>が指定されていると、このパスからの相対パスとなります。
# add_executable()などに指定する依存ソースファイルの一覧を取得するのに使い、おそらくfile()コマンドの中でもっともよく使うことになるでしょう。
# 以下の正規表現のメタ文字に似たものが使えます。
# 任意の文字の0回以上の繰り返し*
# 任意の文字?
# ブラケット内で指定された文字[ ]とその範囲-
# file(WRITE <filename> [<content1> ...])
# file(APPEND <filename> [<content1> ...])
# filenameがVCだとプロジェクト名になるみたい.
file(GLOB freertos_files FreeRTOS/Source/*.[ch] FreeRTOS/Source/portable/MSVC-MingW/*.[ch] FreeRTOS/Source/portable/MemMang/*.[ch])
file(GLOB src_files src/*.[ch] src/Supporting_Functions/*.[ch])

# オブジェクトファイルを作るソースを指定
add_library(freertos OBJECT ${freertos_files})
add_library(src OBJECT ${src_files})

# VC Filterを作るようにする.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
#set(PrefixDir "\\FreeRTOS")
#source_group(TREE ${SrcDir} PREFIX ${PrefixDir} FILES ${SrcFiles})
#source_group(TREE ./src)
#source_group(TREE ./FreeRTOS PREFIX ${PrefixDir} FILES ${freertos_files})

# 実行ファイルを作る方法を指定
#add_executable(<name> [WIN32] [MACOSX_BUNDLE]
#               [EXCLUDE_FROM_ALL]
#               [source1] [source2 ...])
add_executable(${PROJECT_NAME}
 $<TARGET_OBJECTS:freertos>
 $<TARGET_OBJECTS:src>
)
