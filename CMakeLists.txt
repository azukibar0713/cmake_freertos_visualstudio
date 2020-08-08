# �Q�l�T�C�g.
# https://wakame.hatenablog.jp/entry/2017/04/16/151226
# http://www.dcom-web.co.jp/technology/post20/
# https://qiita.com/mrk_21/items/5e7ca775b463a4141a58

cmake_minimum_required(VERSION 3.1)

# �v���W�F�N�g��, C����
project(freertos_project C)

# include directory
# Makefile �� -include ���߂�C�R���p�C���ł� -I �I�v�V������ include_directories �ő�p���܂��D
include_directories(./src)
include_directories(./src/Supporting_Functions)
include_directories(./FreeRTOS/Source/include)
include_directories(./FreeRTOS/Source/portable/MemMang)
include_directories(./FreeRTOS/Source/portable/MSVC-MingW)

# �R���p�C���Ώۂ̃\�[�X�ꗗ���쐬
# �w�肳�ꂽGLOB�p�^�[��<globbing_expressions>�Ƀ}�b�`����t�@�C����T�����A���̈ꗗ�����X�g�Ƃ��ĕϐ�<variable>�Ɋi�[���܂��B
# ���̂Ƃ���΃p�X�Ŋi�[����܂����ARELATIVE <path>���w�肳��Ă���ƁA���̃p�X����̑��΃p�X�ƂȂ�܂��B
# add_executable()�ȂǂɎw�肷��ˑ��\�[�X�t�@�C���̈ꗗ���擾����̂Ɏg���A�����炭file()�R�}���h�̒��ł����Ƃ��悭�g�����ƂɂȂ�ł��傤�B
# �ȉ��̐��K�\���̃��^�����Ɏ������̂��g���܂��B
# �C�ӂ̕�����0��ȏ�̌J��Ԃ�*
# �C�ӂ̕���?
# �u���P�b�g���Ŏw�肳�ꂽ����[ ]�Ƃ��͈̔�-
# file(WRITE <filename> [<content1> ...])
# file(APPEND <filename> [<content1> ...])
# filename��VC���ƃv���W�F�N�g���ɂȂ�݂���.
file(GLOB freertos_files FreeRTOS/Source/*.[ch] FreeRTOS/Source/portable/MSVC-MingW/*.[ch] FreeRTOS/Source/portable/MemMang/*.[ch])
file(GLOB src_files src/*.[ch] src/Supporting_Functions/*.[ch])

# �I�u�W�F�N�g�t�@�C�������\�[�X���w��
add_library(freertos OBJECT ${freertos_files})
add_library(src OBJECT ${src_files})

# VC Filter�����悤�ɂ���.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
#set(PrefixDir "\\FreeRTOS")
#source_group(TREE ${SrcDir} PREFIX ${PrefixDir} FILES ${SrcFiles})
#source_group(TREE ./src)
#source_group(TREE ./FreeRTOS PREFIX ${PrefixDir} FILES ${freertos_files})

# ���s�t�@�C���������@���w��
#add_executable(<name> [WIN32] [MACOSX_BUNDLE]
#               [EXCLUDE_FROM_ALL]
#               [source1] [source2 ...])
add_executable(${PROJECT_NAME}
 $<TARGET_OBJECTS:freertos>
 $<TARGET_OBJECTS:src>
)