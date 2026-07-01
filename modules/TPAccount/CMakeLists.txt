add_library(TPAccount)

target_sources(TPAccount
	PRIVATE
		src/TPAccount.cpp
)

target_include_directories(TPAccount
	PUBLIC
		include
)

target_link_libraries(TPAccount
	PRIVATE
		TPRules
)
