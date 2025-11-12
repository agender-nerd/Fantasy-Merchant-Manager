cmake_minimum_required(VERSION 3.10)
project(FantasyMerchantManager VERSION 2.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.12.0
)
FetchContent_MakeAvailable(nlohmann_json)

add_executable(fmm
    src/main.cpp
    src/Inventory.cpp
    src/Item.cpp
    src/Weapon.cpp
    src/Armor.cpp
    src/Potion.cpp
)

target_include_directories(fmm
    PUBLIC
        include
)

target_link_libraries(fmm
    PRIVATE
        nlohmann_json::nlohmann_json
)