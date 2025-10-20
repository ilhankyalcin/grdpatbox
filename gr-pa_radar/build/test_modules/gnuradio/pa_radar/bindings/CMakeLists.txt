# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT pa_radar_sources)
    MESSAGE(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT pa_radar_sources)

########################################################################
# Check for pygccxml
########################################################################
GR_PYTHON_CHECK_MODULE_RAW(
    "pygccxml"
    "import pygccxml"
    PYGCCXML_FOUND
    )

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND pa_radar_python_files
    radar_target_python.cc python_bindings.cc)

GR_PYBIND_MAKE_OOT(pa_radar
   ../../..
   gr::pa_radar
   "${pa_radar_python_files}")

# copy bindings extension for use in QA test module
add_custom_command(TARGET pa_radar_python POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:pa_radar_python>
    ${PROJECT_BINARY_DIR}/test_modules/gnuradio/pa_radar/
)

install(TARGETS pa_radar_python DESTINATION ${GR_PYTHON_DIR}/gnuradio/pa_radar COMPONENT pythonapi)
