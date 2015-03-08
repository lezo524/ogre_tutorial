
add_subdirectory(init_blue_screen)

file(GLOB PROPERTY_SHEETS "./*.props")
file(COPY ${PROPERTY_SHEETS} DESTINATION "./")