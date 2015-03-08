
# ZIP
set (MEDIA_ZIP_FILES 
	"$ENV{OGRE_HOME}/media/packs/Sinbad.zip"
	"$ENV{OGRE_HOME}/media/packs/SdkTrays.zip"
	"$ENV{OGRE_HOME}/media/packs/profiler.zip"
)

foreach( FILE_NAME ${MEDIA_ZIP_FILES})
	file(GLOB BIN_ZIP_FILES ${FILE_NAME})
	file(COPY ${BIN_ZIP_FILES} DESTINATION "./")
endforeach( FILE_NAME )

message("copy media packs done.")

