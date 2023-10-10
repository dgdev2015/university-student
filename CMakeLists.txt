cmake_minimum_required(VERSION 3.10)

project(university_student)

add_executable(students
    src/main.c
)

target_include_directories(students
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)