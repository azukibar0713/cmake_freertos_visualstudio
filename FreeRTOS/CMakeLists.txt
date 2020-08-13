file(GLOB FREERTOS_SOURCE_FILES ./*.[ch])

# ----------------------------
# コンパイル対象のソース一覧を作成.
# ----------------------------
file(GLOB FREERTOS_SOURCE_FILES ./Source/*.[ch] ./Source/portable/MSVC-MingW/*.[ch] ./Source/portable/MemMang/*.[ch])

#add_executable(FREERTOS ${FREERTOS_SOURCE_FILES})
# ----------------------------
# オブジェクトファイル作成.
# ----------------------------
add_library(FREERTOS OBJECT ${FREERTOS_SOURCE_FILES})


# ----------------------------
# インクルードディレクトリ.
# ----------------------------
include_directories($ENV{FREERTOS_CONFIG_DIR})
include_directories($ENV{FREERTOS_INCLUDE_DIR})
include_directories($ENV{FREERTOS_MEMMAG_DIR})
include_directories($ENV{FREERTOS_PORTABLE_DIR})
