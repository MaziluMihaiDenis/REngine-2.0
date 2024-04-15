#pragma once
#include <fstream>
#include <string>

namespace RE
{
	struct TextureConfig
	{
		static void SaveConfig(std::string fp, int wrap, int format, int filter)
		{
			fp.append(".import");
			std::ofstream fout(fp);
			fout << wrap << " "
				<< format << " "
				<< filter;
			fout.close();
		}

		static void Load(std::string fp, int& wrap, int& format, int& filter)
		{
			fp.append(".import");
			std::ifstream fin(fp);
			fin >> wrap >> format >> filter;
			fin.close();
		}
	};
};