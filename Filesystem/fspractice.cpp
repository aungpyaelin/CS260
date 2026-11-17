#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    
    fs::path currentPath = fs::current_path();

    std::cout << "Current path: " << currentPath << std::endl;

    if(fs::create_directory("my_folder")){
	    std::cout << "Folder created.\n";
    }else{
	    std::cout << "Folder already exists or could not be created.\n";
    }
    return 0;
}
