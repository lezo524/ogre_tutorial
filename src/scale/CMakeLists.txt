
set (PROJECT_NAME "scale")

# Find user and system name
#SET(SYSTEM_NAME $ENV{USERDOMAIN} CACHE STRING SystemName)
#SET(USER_NAME $ENV{USERNAME} CACHE STRING UserName)
# Configure the template file
SET(USER_FILE ${PROJECT_NAME}.vcxproj.user)
SET(OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/${USER_FILE})
CONFIGURE_FILE(${PROJECT_NAME}.vcxproj.user.in ${USER_FILE} @ONLY)

set (CPP_SRC scale.cpp)
add_executable (${PROJECT_NAME} ${CPP_SRC})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    debug OgreMain_d.lib debug OIS_d.lib debug OgreOverlay_d.lib
    optimized OgreMain.lib optimized OIS.lib optimized OgreOverlay.lib)
	