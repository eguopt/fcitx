include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/src/lib)
include_directories(${PROJECT_SOURCE_DIR}/src/im/pinyin)
include_directories(${PROJECT_SOURCE_DIR}/src/module/unicode)

add_executable(testconfig testconfig.c)
target_link_libraries(testconfig fcitx-config)

add_executable(testmessage testmessage.c)
target_link_libraries(testmessage fcitx-core)

add_executable(teststring teststring.c)
target_link_libraries(teststring fcitx-utils)

add_executable(testutf8 testutf8.c)
target_link_libraries(testutf8 fcitx-utils)

add_executable(testunicode testunicode.c ../src/module/unicode/charselectdata.c)
target_link_libraries(testunicode fcitx-utils fcitx-config)

add_executable(testpinyin
    ../src/im/pinyin/pyParser.c
    ../src/im/pinyin/pyMapTable.c
    ../src/im/pinyin/PYFA.c
    ../src/im/pinyin/sp.c
    testpinyin.c
)
target_link_libraries(testpinyin fcitx-config)

add_test(NAME testconfig
         COMMAND testconfig ${CMAKE_CURRENT_SOURCE_DIR}/test.desc ${CMAKE_CURRENT_SOURCE_DIR}/test.conf ${CMAKE_CURRENT_BINARY_DIR}/test.conf)

add_test(NAME testmessage
         COMMAND testmessage)

add_test(NAME testpinyin
         COMMAND testpinyin)

add_test(NAME teststring
         COMMAND teststring)

add_test(NAME testutf8
         COMMAND testutf8)

add_test(NAME testunicode
         COMMAND testunicode ${PROJECT_SOURCE_DIR}/src/module/unicode/charselectdata)