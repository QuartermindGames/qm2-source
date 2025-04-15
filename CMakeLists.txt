set(QM2_SOURCES
        ${GAME_SHARED_FILES}

        qm2.c
        qm2_entity_nibble.c
)

add_executable(qm-game2 WIN32 ${QM2_SOURCES} ${CMAKE_SOURCE_DIR}/src/shells/launcher_sdl2/launcher.c)
target_link_libraries(qm-game2 ${GAME_LINK_LIBS})
target_compile_definitions(qm-game2 PRIVATE -DGAME_QM2)
set_target_properties(qm-game2 PROPERTIES FOLDER "Shells")
