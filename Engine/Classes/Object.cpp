#include "Object.h"
#include <typeindex>
#include <string>
#include <fstream>

void RE::Object::Init(){}
void RE::Object::Start() {}
void RE::Object::Loop(float deltaTime) {}
void RE::Object::Destroy(float time)
{
    if (time == 0.f)
        delete this;
}

/*
void RE::Object::Serialize(std::string filePath)
{
    std::ofstream fout(filePath);
    fout << OBJECT_FORMAT_IN(ID, Processing);
    fout.close();
}

void RE::Object::Deserialize(std::string filePath)
{
    std::ifstream fin(filePath);
    fin >> OBJECT_FORMAT_OUT(ID, Processing);
    fin.close();
}
*/