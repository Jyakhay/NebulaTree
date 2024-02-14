project(NebulaTree)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(ROOT_SOURCES

    "NebulaTree.h"
    "Tree.cpp"
    "Tree.h"
    "TreeParser.cpp"
    "TreeParser.h"
    "Main.cpp"

)

set(NEBULA_TREE_SOURCES

    ${ROOT_SOURCES}

)

add_executable(NebulaTree ${NEBULA_TREE_SOURCES})

set_property(TARGET NebulaTree PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${NEBULA_TREE_ROOT_DIR}")