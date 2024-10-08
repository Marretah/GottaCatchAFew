#include "Importer.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <filesystem> // Ensure this is included for std::filesystem
#include "../src/Mons.h" // Updated path for consistency

void ImportMons() {
    using json = nlohmann::json;

    // Step 1: Load JSON from a file
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    //std::ifstream file("../Data/Mons/BaseStatsMons.json"); // Adjusted relative path
    std::ifstream file("C:\\Users\\rpalm\\source\\repos\\GottaCatchAFew\\GottaCatchAFew\\Data\\Mons\\BaseStatsMons.json");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return; // Return from the function if the file cannot be opened
    }

    json jsonData;
    try {
        file >> jsonData;
    }
    catch (const json::parse_error& e) {
        std::cerr << "JSON parsing error: " << e.what() << std::endl;
        return; // Return from the function if there is a parsing error
    }

    // Step 2: Iterate over each monster in the JSON array
    for (const auto& monData : jsonData) {
        if (monData.contains("Name") && monData.contains("Hp") && monData.contains("Atk")) {
            // Extract data from JSON with default values if fields are missing
            std::string Id = monData.value("Id", "UnknownId");  // Use string for Id
            int Level = monData.value("Level", -1);
            std::string Name = monData.value("Name", "UnknownMon");
            int Hp = monData.value("Hp", -1);
            int Atk = monData.value("Atk", -1);
            int Def = monData.value("Def", -1);
            int SpAtk = monData.value("SpAtk", -1);
            int SpDef = monData.value("SpDef", -1);
            int Spe = monData.value("Spe", -1);

            // Create Mon objects using the parsed data
            Mon mon(Id, Level, Name, Hp, Atk, Def, SpAtk, SpDef, Spe, MonNature::Bold);

            // Debugging output to verify the monster's data
            std::cout << "======================" << std::endl;
            std::cout << "Id: " << Id << std::endl;
            std::cout << "Level: " << Level << std::endl;
            std::cout << "Name: " << Name << std::endl;
            std::cout << "HP: " << Hp << std::endl;
            std::cout << "Attack: " << Atk << std::endl;
            std::cout << "Defense: " << Def << std::endl;
            std::cout << "Special Attack: " << SpAtk << std::endl;
            std::cout << "Special Defense: " << SpDef << std::endl;
            std::cout << "Speed: " << Spe << std::endl;
            std::cout << "======================" << std::endl;
        }
        else {
            std::cerr << "Incomplete or invalid data for one of the monsters!" << std::endl;
        }
    }
}
