#定义了一个src——list目录包含该目录下所有源文件
aux_source_directory(. SRC_LIST)
add_executable(ChatServer ${SRC_LIST})
target_link_libraries(ChatServer muduo_net muduo_base mysqlclient pthread)