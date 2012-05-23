#-----------------------------------------------------------------------------
cmake_minimum_required(VERSION 2.8.4)
#-----------------------------------------------------------------------------

#-----------------------------------------------------------------------------
# See http://cmake.org/cmake/help/cmake-2-8-docs.html#section_Policies for details
#-----------------------------------------------------------------------------
if(POLICY CMP0017)
  cmake_policy(SET CMP0017 OLD)
endif()

#-----------------------------------------------------------------------------
# Module name
#   - Usually identique to the directory name)
#   - You shouldn't call 'project(...)'. See SlicerConfig.cmake for more details.
#-----------------------------------------------------------------------------
set(EXTENSION_NAME FacetedVisualizer)

#-----------------------------------------------------------------------------
# Prerequisites
#-----------------------------------------------------------------------------
if(NOT Slicer_SOURCE_DIR)
  set(EXTENSION_HOMEPAGE "http://www.slicer.org/slicerWiki/index.php/Slicer4:Developers:Projects:QtSlicer/Tutorials/ExtensionWriting")
  set(EXTENSION_CATEGORY "Examples")
  set(EXTENSION_STATUS "Beta")
  set(EXTENSION_DESCRIPTION "This is an example of Qt loadable module built as an extension")
  set(EXTENSION_DEPENDS CLIExtensionTemplate) # Specified as a space separated list or 'NA' if any

  find_package(Slicer REQUIRED)

  # Additional C/CXX flags - Should be defined before including Slicer_USE_FILE
  set(ADDITIONAL_C_FLAGS "" CACHE STRING "Additional ${EXTENSION_NAME} C Flags")
  set(ADDITIONAL_CXX_FLAGS "" CACHE STRING "Additional ${EXTENSION_NAME} CXX Flags")

  include(${Slicer_USE_FILE})

  set(EXTENSION_LICENSE_FILE ${Slicer_LICENSE_FILE})
  set(EXTENSION_README_FILE ${Slicer_README_FILE})

  include(SlicerEnableExtensionTesting)

endif()


# Module name (usually identique to the directory name)
#set(qt_module_name "FacetedVisualizer")
set(qt_module_title "Faceted Atlas Visualizer")

# Build module sub libraries
add_subdirectory(Logic)

set(qt_module_export_directive "Q_SLICER_QTMODULES_FACETEDVISUALIZER_EXPORT")

# Additional includes - Current_{source,binary} and Slicer_{Libs,Base} already included
set(qt_module_include_directories
  ${CMAKE_CURRENT_SOURCE_DIR}/Widgets
  ${CMAKE_CURRENT_BINARY_DIR}/Widgets
  ${CMAKE_CURRENT_SOURCE_DIR}/Logic
  ${CMAKE_CURRENT_BINARY_DIR}/Logic
  )


# Source files
set(qt_module_SRCS
  qSlicerFacetedVisualizerModule.cxx
  qSlicerFacetedVisualizerModule.h
  qSlicerFacetedVisualizerModuleWidget.cxx
  qSlicerFacetedVisualizerModuleWidget.h
  )

# Headers that should run through moc
set(qt_module_MOC_SRCS
  qSlicerFacetedVisualizerModule.h
  qSlicerFacetedVisualizerModuleWidget.h
  )

# UI files
set(qt_module_UI_SRCS
  Resources/UI/qSlicerFacetedVisualizerModule.ui
  )

# Additional Target libraries
set(qt_module_target_libraries
  vtkSlicerFacetedVisualizerModuleLogic
  )
INCLUDE_DIRECTORIES( ${VTK_SOURCE_DIR}/Utilities/vtksqlite )
# Resources
set(qt_module_resources
  Resources/qSlicerFacetedVisualizerModule.qrc
  )

slicerMacroBuildQtModule(
  NAME ${EXTENSION_NAME}
#  NAME ${qt_module_name}
  TITLE ${qt_module_title}
  EXPORT_DIRECTIVE ${qt_module_export_directive}
  INCLUDE_DIRECTORIES ${qt_module_include_directories}
  SRCS ${qt_module_SRCS}
  MOC_SRCS ${qt_module_MOC_SRCS}
  UI_SRCS ${qt_module_UI_SRCS}
  TARGET_LIBRARIES ${qt_module_target_libraries}
  RESOURCES ${qt_module_resources}
  )


if(BUILD_TESTING)
  add_subdirectory(Testing)
endif()

#-----------------------------------------------------------------------------
# Generate extension description file '<EXTENSION_NAME>.s4ext'
#-----------------------------------------------------------------------------
if(NOT Slicer_SOURCE_DIR)
  include(SlicerFunctionGenerateExtensionDescription)
  slicerFunctionGenerateExtensionDescription(
    EXTENSION_NAME ${EXTENSION_NAME}
    EXTENSION_CATEGORY ${EXTENSION_CATEGORY}
    EXTENSION_STATUS ${EXTENSION_STATUS}
    EXTENSION_HOMEPAGE ${EXTENSION_HOMEPAGE}
    EXTENSION_DESCRIPTION ${EXTENSION_DESCRIPTION}
    EXTENSION_DEPENDS ${EXTENSION_DEPENDS}
    DESTINATION_DIR ${CMAKE_CURRENT_BINARY_DIR}
    SLICER_WC_REVISION ${Slicer_WC_REVISION}
    SLICER_WC_ROOT ${Slicer_WC_ROOT}
    )
endif()

#-----------------------------------------------------------------------------
# Packaging
#-----------------------------------------------------------------------------
if(NOT Slicer_SOURCE_DIR)
  include(${Slicer_EXTENSION_CPACK})
endif()
