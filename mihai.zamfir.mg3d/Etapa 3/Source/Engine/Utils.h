#pragma once

using namespace std;

class Utils
{
	

	public:
		Utils();
		~Utils();

		static char* GetShaderPath();
		static char* GetTexturePath();
		static char* GetScriptPath();
		static char* Utils::GetModelPath();

		static void PrintIndent(int indentLevel);

	private:

};
