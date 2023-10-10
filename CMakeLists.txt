cmake_minimum_required(VERSION 3.10)

project(university_student)

add_executable(students
    src/main.c
    src/student.c
)

target_include_directories(students
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

add_executable(sqlite3_test
    src/test.c
)

target_include_directories(sqlite3_test
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_directories(sqlite3_test
    PRIVATE
    ${PROJECT_SOURCE_DIR}/lib
)

target_link_libraries(sqlite3_test
    PRIVATE
    sqlite3
)