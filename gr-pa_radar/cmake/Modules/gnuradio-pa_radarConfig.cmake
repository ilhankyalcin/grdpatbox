find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_PA_RADAR gnuradio-pa_radar)

FIND_PATH(
    GR_PA_RADAR_INCLUDE_DIRS
    NAMES gnuradio/pa_radar/api.h
    HINTS $ENV{PA_RADAR_DIR}/include
        ${PC_PA_RADAR_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_PA_RADAR_LIBRARIES
    NAMES gnuradio-pa_radar
    HINTS $ENV{PA_RADAR_DIR}/lib
        ${PC_PA_RADAR_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-pa_radarTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_PA_RADAR DEFAULT_MSG GR_PA_RADAR_LIBRARIES GR_PA_RADAR_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_PA_RADAR_LIBRARIES GR_PA_RADAR_INCLUDE_DIRS)
