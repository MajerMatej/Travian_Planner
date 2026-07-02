add_library(TPSimulation)

target_sources(TPSimulation
	PRIVATE
		src/TPSimulation.cpp
)

target_include_directories(TPSimulation
	PUBLIC
		include
)

target_link_libraries(TPSimulation
	PRIVATE
		TPAccount
)
