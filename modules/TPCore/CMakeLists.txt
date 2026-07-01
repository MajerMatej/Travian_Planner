add_library(TPCore)

target_sources(TPCore
	PRIVATE
		src/TPCore.cpp
)

target_include_directories(TPCore
	PUBLIC
		include
)
