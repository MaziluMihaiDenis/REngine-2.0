#pragma once
#include <string>
#include <fstream>

namespace RE
{
	class Filesystem
	{
	public:
		struct JSON
		{

		};

	public:
		/*
			Returns the contents of a file as a string
		*/
		static std::string GetFileContents(std::string path);
		/*
			Transforms all the texture's properties to a .import file
		*/
		static void ImportTextures(std::string folder);
		/*
			Makes a directory at the specified path with the specified name
			Returns the path to the directory
		*/
		static std::string MakeDirectory(std::string path, std::string name);
	};
};

