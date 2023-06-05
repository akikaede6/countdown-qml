cmake_minimum_required(VERSION 3.16)

project(countdown-qml VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Multimedia)

qt_standard_project_setup()

qt_add_executable(appcountdown-qml
    main.cpp
    src/CountDown.h
    src/CountDown.cpp
    src/MusicPlayer.h
    src/MusicPlayer.cpp
    music.qrc
)

qt_add_qml_module(appcountdown-qml
    URI countdown-qml
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        qml/Countdown.qml
)

set_target_properties(appcountdown-qml PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appcountdown-qml
    PRIVATE Qt6::Quick Qt6::Multimedia
)

install(TARGETS appcountdown-qml
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
