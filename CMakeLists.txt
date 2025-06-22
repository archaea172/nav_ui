cmake_minimum_required(VERSION 3.8)
project(nav_ui)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
set(CMAKE_AUTOMOC ON)
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclpy REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

ament_python_install_package(${PROJECT_NAME} PACKAGE_DIR src/${PROJECT_NAME})
install(PROGRAMS scripts/control_ui.py DESTINATION lib/${PROJECT_NAME})

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(qprocess_learn
  src/qprocess_learn.cpp
  include/${PROJECT_NAME}/qprocess_learn.hpp
)
target_link_libraries(qprocess_learn PRIVATE Qt6::Widgets)
ament_target_dependencies(qprocess_learn
  Qt6
)
install(
  TARGETS qprocess_learn
  DESTINATION lib/${PROJECT_NAME}
)
target_include_directories(qprocess_learn
  PRIVATE include/${PROJECT_NAME}
)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
