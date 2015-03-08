
set (PROJECT_NAME "init_blue_screen")

# Find user and system name
#SET(SYSTEM_NAME $ENV{USERDOMAIN} CACHE STRING SystemName)
#SET(USER_NAME $ENV{USERNAME} CACHE STRING UserName)
# Configure the template file
SET(USER_FILE ${PROJECT_NAME}.vcxproj.user)
SET(OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/${USER_FILE})
CONFIGURE_FILE(${PROJECT_NAME}.vcxproj.user.in ${USER_FILE} @ONLY)

set (INIT_BLUE_SCREEN_SRC init_blue_screen.cpp)
add_executable (${PROJECT_NAME} ${INIT_BLUE_SCREEN_SRC})

TARGET_LINK_LIBRARIES(${PROJECT_NAME}
    debug OgreMain_d.lib debug OIS_d.lib debug OgreOverlay_d.lib
    optimized OgreMain.lib optimized OIS.lib optimized OgreOverlay.lib)
	