cmake_minimum_required(VERSION 3.28)

project(TravianPlanner LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(modules/TPCore)
add_subdirectory(modules/TPRules)
add_subdirectory(modules/TPAccount)
add_subdirectory(modules/TPPersistence)
add_subdirectory(modules/TPSimulation)
add_subdirectory(modules/TPPlanning)
add_subdirectory(modules/TPGUI)

add_executable(TravianPlanner)

target_sources(TravianPlanner
	PRIVATE
		app/main.cpp
)

target_link_libraries(TravianPlanner
	PRIVATE
		TPGUI
		TPPlanning
)
