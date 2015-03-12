#cmake_policy(VERSION major.minor[.patch[.tweak]])
cmake_policy(VERSION 2.8)
cmake_minimum_required (VERSION 2.8)

project (OGRE_TUTORIAL)

# macro (add_executable _name)
    #invoke built-in add_executable
    # _add_executable(${ARGV})
    # if (TARGET ${_name})
		# target_link_libraries(${_name} debug OgreMain_d.lib OIS_d.lib OgreOverlay_d.lib)
        # target_link_libraries(${_name} optimized OgreMain.lib OIS.lib OgreOverlay.lib)
    # endif()
# endmacro()


set (OGRE_TUTORIAL_VERSION_MAJOR 1)
set (OGRE_TUTORIAL_VERSION_MINOR 0)

message("OGRE Tutorial v" ${OGRE_TUTORIAL_VERSION_MAJOR} "." ${OGRE_TUTORIAL_VERSION_MINOR})

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /Zm256")

if(MSVC)
  set(CMAKE_USE_RELATIVE_PATHS true)
  set(CMAKE_SUPPRESS_REGENERATION true)
  # for Unicode Project Setting
  #add_definitions(-DUNICODE -D_UNICODE)

  cmake_policy(SET CMP0021 OLD) # NEW : not allow relative path but OLD is fine.  
  include_directories(";$(BOOST_ROOT);")
  include_directories(";$(OGRE_HOME)\\include")
  include_directories(";$(OGRE_HOME)\\include\\OIS")
  include_directories(";$(OGRE_HOME)\\include\\OGRE")
  include_directories(";$(OGRE_HOME)\\include\\OGRE\\Overlay")
  
  cmake_policy(SET CMP0015 OLD) # NEW : not allow relative path but OLD is fine.  
  link_directories("$(BOOST_ROOT)\\lib" "$(OGRE_HOME)\\lib\\${ConfigurationName}")  
endif()

# Specify build paths
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ";$(ProjectDir)\\..\\..\\..\\bin") # automatic attach "Debug", "Release"
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ";$(ProjectDir)\\..\\..\\..\\bin\\debug")
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ";$(ProjectDir)\\..\\..\\..\\bin\\release")

add_subdirectory(bin)
add_subdirectory(media)
add_subdirectory(res)
add_subdirectory(src)

set(TUTORIAL_FOLDER "Tutorial")
set(ETC_FOLDER "ETC") 

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(TARGET init_blue_screen			PROPERTY FOLDER ${TUTORIAL_FOLDER})
set_property(TARGET mesh_load_by_scenemanager	PROPERTY FOLDER ${TUTORIAL_FOLDER})
#SET_PROPERTY(TARGET builder 				PROPERTY FOLDER ${GOF_CREATIONAL})
