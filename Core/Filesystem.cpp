#include "Filesystem.h"
#include <Graphics/Structs/TextureConfig.h>
#include <direct.h>
#include <filesystem>

std::string RE::Filesystem::GetFileContents(std::string path)
{
    std::ifstream fin;
    fin.open(path);

    std::string content = std::string(
        std::istreambuf_iterator<char>(fin),
        std::istreambuf_iterator<char>()
    );
    
    fin.close();

    return content;
}

void RE::Filesystem::ImportTextures(std::string folder)
{
    for (const auto& file : std::filesystem::directory_iterator(folder))
    {
        std::string fp = file.path().string();
        int flen = fp.length();

        if(fp.substr(flen - 4, 4) == ".png")
            TextureConfig::SaveConfig(file.path().string(), 0x8370, 0x1908, 0x2600);
    }
}

std::string RE::Filesystem::MakeDirectory(std::string path, std::string name)
{
    std::string fp;
    const char* cstr;

    fp = path;
    fp.append(name);
    cstr = fp.c_str();

    if (!mkdir(cstr))
        return "";
    return fp;
}
