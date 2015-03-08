
# DLL
set (RELEASE_DLL_FILES 
	"$ENV{OGRE_HOME}/bin/release/cg.dll"
	"$ENV{OGRE_HOME}/bin/release/OgreMain.dll"
	"$ENV{OGRE_HOME}/bin/release/OgreOverlay.dll"
	"$ENV{OGRE_HOME}/bin/release/OIS.dll"
	"$ENV{OGRE_HOME}/bin/release/Plugin_BSPSceneManager.dll"
	"$ENV{OGRE_HOME}/bin/release/Plugin_CgProgramManager.dll"
	"$ENV{OGRE_HOME}/bin/release/Plugin_OctreeSceneManager.dll"
	"$ENV{OGRE_HOME}/bin/release/Plugin_OctreeZone.dll"
	"$ENV{OGRE_HOME}/bin/release/Plugin_ParticleFX.dll"
	"$ENV{OGRE_HOME}/bin/release/Plugin_PCZSceneManager.dll"
	"$ENV{OGRE_HOME}/bin/release/RenderSystem_Direct3D9.dll"
	"$ENV{OGRE_HOME}/bin/release/RenderSystem_Direct3D11.dll"
	"$ENV{OGRE_HOME}/bin/release/RenderSystem_GL.dll"
)

foreach( FILE_NAME ${RELEASE_DLL_FILES})
	file(GLOB BIN_DLL_FILES ${FILE_NAME})
	file(COPY ${BIN_DLL_FILES} DESTINATION "./")
endforeach( FILE_NAME )


# CFG (plugins.cfg, resources.cfg)
file(GLOB BIN_CFG_FILES "./*.cfg")
file(COPY ${BIN_CFG_FILES} DESTINATION "./")

message("copy release folder files done.")
