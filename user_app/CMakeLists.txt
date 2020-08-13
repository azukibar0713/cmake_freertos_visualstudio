# ----------------------------
# コンパイル対象のソース一覧を作成.
# ----------------------------
file(GLOB USER_APP_SOURCE_FILES ./src/*.[ch]) # driverはgtestのプロジェクトでコンパイルする.
# ----------------------------
# オブジェクトファイル作成.
# ----------------------------
#add_executable(USER_APP ${USER_APP_SOURCE_FILES})
add_library(USER_APP OBJECT ${USER_APP_SOURCE_FILES})
