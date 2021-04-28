cmake_minimum_required(VERSION 3.5)
project(dummy_pkg)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)


include_directories(include
	${std_msgs_INCLUDE_DIRS}
	${rclcpp_INCLUDE_DIRS}
	)

# Talker

add_executable(talker src/talker.cpp)

target_link_libraries(talker
	${std_msgs_LIBRARIES}
	)

ament_target_dependencies(talker
	"rclcpp"
	)

# Listener

add_executable(listener src/listener.cpp)

target_link_libraries(listener
	${std_msgs_LIBRARIES}
	)

ament_target_dependencies(listener
	"rclcpp"
	)

install(TARGETS talker listener DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})


ament_package()
