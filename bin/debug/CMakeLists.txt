
# DLL
set (DEBUG_DLL_FILES 
	"$ENV{OGRE_HOME}/bin/debug/cg.dll"
	"$ENV{OGRE_HOME}/bin/debug/OgreMain_d.dll"
	"$ENV{OGRE_HOME}/bin/debug/OgreOverlay_d.dll"
	"$ENV{OGRE_HOME}/bin/debug/OIS_d.dll"
	"$ENV{OGRE_HOME}/bin/debug/Plugin_BSPSceneManager_d.dll"
	"$ENV{OGRE_HOME}/bin/debug/Plugin_CgProgramManager_d.dll"
	"$ENV{OGRE_HOME}/bin/debug/Plugin_OctreeSceneManager_d.dll"
	"$ENV{OGRE_HOME}/bin/debug/Plugin_OctreeZone_d.dll"
	"$ENV{OGRE_HOME}/bin/debug/Plugin_ParticleFX_d.dll"
	"$ENV{OGRE_HOME}/bin/debug/Plugin_PCZSceneManager_d.dll"
	"$ENV{OGRE_HOME}/bin/debug/RenderSystem_Direct3D9_d.dll"
	"$ENV{OGRE_HOME}/bin/debug/RenderSystem_Direct3D11_d.dll"
	"$ENV{OGRE_HOME}/bin/debug/RenderSystem_GL_d.dll"
)

foreach( FILE_NAME ${DEBUG_DLL_FILES})
	file(GLOB BIN_DLL_FILES ${FILE_NAME})
	file(COPY ${BIN_DLL_FILES} DESTINATION "./")
endforeach( FILE_NAME )


# PDB
set (DEBUG_PDB_FILES
	"$ENV{OGRE_HOME}/bin/debug/OgreMain_d.pdb"
	"$ENV{OGRE_HOME}/bin/debug/OgreOverlay_d.pdb"
	"$ENV{OGRE_HOME}/bin/debug/Plugin_BSPSceneManager_d.pdb"
	"$ENV{OGRE_HOME}/bin/debug/Plugin_CgProgramManager_d.pdb"
	"$ENV{OGRE_HOME}/bin/debug/Plugin_OctreeSceneManager_d.pdb"
	"$ENV{OGRE_HOME}/bin/debug/Plugin_OctreeZone_d.pdb"
	"$ENV{OGRE_HOME}/bin/debug/Plugin_ParticleFX_d.pdb"
	"$ENV{OGRE_HOME}/bin/debug/Plugin_PCZSceneManager_d.pdb"
	"$ENV{OGRE_HOME}/bin/debug/RenderSystem_Direct3D9_d.pdb"
	"$ENV{OGRE_HOME}/bin/debug/RenderSystem_Direct3D11_d.pdb"
	"$ENV{OGRE_HOME}/bin/debug/RenderSystem_GL_d.pdb"
)

foreach( FILE_NAME ${DEBUG_PDB_FILES})
	file(GLOB BIN_PDB_FILES ${FILE_NAME})
	file(COPY ${BIN_PDB_FILES} DESTINATION "./")
endforeach( FILE_NAME )


# CFG ()plugins_d.cfg, resources_d.cfg)
file(GLOB BIN_CFG_FILES "./*.cfg")
file(COPY ${BIN_CFG_FILES} DESTINATION "./")

message("copy debug folder files done.")
