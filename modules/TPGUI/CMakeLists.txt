add_library(TPGUI)

target_sources(TPGUI
	PRIVATE
		src/TPGUI.cpp
)

target_include_directories(TPGUI
	PUBLIC
		include
)

target_link_libraries(TPGUI
	PRIVATE
		TPSimulation
)
