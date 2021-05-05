#----------------------------------------------------------------
# Generated CMake target import file for configuration "MinSizeRel".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "assimp::zlibstatic" for configuration "MinSizeRel"
set_property(TARGET assimp::zlibstatic APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(assimp::zlibstatic PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "C"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/lib/zlibstatic.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS assimp::zlibstatic )
list(APPEND _IMPORT_CHECK_FILES_FOR_assimp::zlibstatic "${_IMPORT_PREFIX}/lib/zlibstatic.lib" )

# Import target "assimp::assimp" for configuration "MinSizeRel"
set_property(TARGET assimp::assimp APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(assimp::assimp PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "${_IMPORT_PREFIX}/lib/assimp-vc142-mt.lib"
  IMPORTED_LOCATION_MINSIZEREL "${_IMPORT_PREFIX}/bin/assimp-vc142-mt.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS assimp::assimp )
list(APPEND _IMPORT_CHECK_FILES_FOR_assimp::assimp "${_IMPORT_PREFIX}/lib/assimp-vc142-mt.lib" "${_IMPORT_PREFIX}/bin/assimp-vc142-mt.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
