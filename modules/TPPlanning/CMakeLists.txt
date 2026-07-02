add_library(TPPlanning)

target_sources(TPPlanning
	PRIVATE
		src/TPPlanning.cpp
)

target_include_directories(TPPlanning
	PUBLIC
		include
)

target_link_libraries(TPPlanning
	PRIVATE
		TPSimulation
)
