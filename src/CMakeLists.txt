
add_executable(bitz-server
	main.cpp
	bitz-server.cpp
	bitz/exception.cpp
	bitz/manager_exception.cpp
	bitz/config.cpp
	bitz/util.cpp
	bitz/manager.cpp
	bitz/worker.cpp
	bitz/request_handler.cpp
	bitz/options_request_handler.cpp
	bitz/reqmod_request_handler.cpp
	bitz/respmod_request_handler.cpp
	bitz/modifier.cpp
)

set_target_properties(bitz-server PROPERTIES
	ENABLE_EXPORTS on
)

target_include_directories(bitz-server PRIVATE
	${CMAKE_BINARY_DIR}/include
	${spdlog_INCLUDE_DIRS}
)

target_include_directories(bitz-server PUBLIC
	${CMAKE_SOURCE_DIR}/lib
	${psocksxx_INCLUDE_DIRS}
)

target_link_libraries(bitz-server PRIVATE
	dl pthread
	spdlog
	${psocksxx_LDFLAGS}
	${libconfig_LDFLAGS}
)

target_link_libraries(bitz-server PUBLIC
	icap
)


include(GNUInstallDirs)
install(
	TARGETS bitz-server
	RUNTIME DESTINATION ${CMAKE_INSTALL_SBINDIR}
)

install(
	FILES
		bitz/config.h
		bitz/modifier.h
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
)

