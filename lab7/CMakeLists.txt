# CMakeList.txt: проект CMake для lab7; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (lab7 "lab7.cpp" "lab7.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lab7 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
