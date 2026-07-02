add_library(TPRules)

target_sources(TPRules
	PRIVATE
		src/TPRules.cpp
)

target_include_directories(TPRules
	PUBLIC
		include
)

target_link_libraries(TPRules
	PRIVATE
		TPCore
)
