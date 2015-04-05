
add_subdirectory(init_blue_screen)
add_subdirectory(mesh_load_by_scenemanager)
add_subdirectory(rotate_pitch_yaw_roll)
add_subdirectory(scale)
add_subdirectory(relative_translate)
add_subdirectory(relative_rotate)

file(GLOB PROPERTY_SHEETS "./*.props")
file(COPY ${PROPERTY_SHEETS} DESTINATION "./")