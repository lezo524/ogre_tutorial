
add_subdirectory(init_blue_screen)
add_subdirectory(mesh_load_by_scenemanager)

file(GLOB PROPERTY_SHEETS "./*.props")
file(COPY ${PROPERTY_SHEETS} DESTINATION "./")