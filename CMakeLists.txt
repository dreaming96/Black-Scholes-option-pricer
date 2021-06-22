project(Project)

add_executable(main
main.cpp)

target_include_directories(main PUBLIC "stats/include")
target_include_directories(main PUBLIC "stats/include/static_incl")
target_include_directories(main PUBLIC "stats/include/static_incl/dens")
target_include_directories(main PUBLIC "stats/include/static_incl/misc")
target_include_directories(main PUBLIC "stats/include/static_incl/prob")
target_include_directories(main PUBLIC "stats/include/static_incl/quant")
target_include_directories(main PUBLIC "stats/include/static_incl/rand")

add_subdirectory(gcem)

target_include_directories(main PUBLIC "gcem/include")
target_include_directories(main PUBLIC "gcem/include/gcem_incl")