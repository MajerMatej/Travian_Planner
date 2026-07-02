add_library(TPPersistence)

target_sources(TPPersistence
	PRIVATE
		src/TPPersistence.cpp
)

target_include_directories(TPPersistence
	PUBLIC
		include
)

target_link_libraries(TPPersistence
	PRIVATE
		TPAccount
)
