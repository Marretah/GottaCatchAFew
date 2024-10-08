#include "GottaCatchAFew.h"
#include <iostream>
// Include the header where ImportMons is declared
#include "Data/Importer.h"  // This ensures the ImportMons() function is properly declared

int main() {
    // Call ImportMons function
    ImportMons();  // ImportMons returns void, so no need for error handling

    std::cout << "Monsters imported successfully." << std::endl;
    return 0;
}
