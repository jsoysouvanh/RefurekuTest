#include <iostream>

#include <Misc/Filesystem.h>

#include "FileParser.h"
#include "FileGenerator.h"

void parseAndGenerate(fs::path&& exePath, fs::path&& workingDirectory)
{
	rfk::FileParser		fileParser;
	rfk::FileGenerator	fileGenerator;

	std::cout << "[WORKING DIRECTORY] " << workingDirectory.string() << std::endl;

	fs::path pathToSettingsFile = exePath.make_preferred() / "RefurekuSettings.toml";

	//Load settings
	if (fileGenerator.loadSettings(pathToSettingsFile) && fileParser.loadSettings(pathToSettingsFile))
	{
		std::cout << "[LOADED] FileGenerator settings." << std::endl;
		std::cout << "[LOADED] FileParser settings." << std::endl;

		#if KODGEN_DEV

		fs::path includeDir		= workingDirectory.make_preferred() / "Include";
		fs::path generatedDir	= includeDir / "Generated";

		fileGenerator.outputDirectory = generatedDir;
		fileGenerator.toParseDirectories.emplace(includeDir);
		fileGenerator.ignoredDirectories.emplace(generatedDir);

		#endif

		//Parse
		kodgen::FileGenerationResult genResult = fileGenerator.generateFiles(fileParser, false);

		//Result
		if (genResult.completed)
		{
			for (kodgen::ParsingError parsingError : genResult.parsingErrors)
			{
				std::cerr << parsingError << std::endl;
			}

			for (kodgen::FileGenerationError fileGenError : genResult.fileGenerationErrors)
			{
				std::cerr << fileGenError << std::endl;
			}
		}
		else
		{
			std::cerr << "Invalid FileGenerator::outputDirectory" << std::endl;
		}
	}
	else
	{
		std::cerr << "[ERROR] Failed to load the RefurekuSettings file at " << pathToSettingsFile.string() << std::endl;
	}
}

int main(int argc, char** argv)
{
	int result = EXIT_SUCCESS;

	fs::path exeDirectory = fs::path(argv[0]).parent_path();

	//Use the first argument as working directory if any
	if (argc > 1)
	{
		fs::path workingDirectory	= argv[1];

		if (fs::is_directory(workingDirectory))
		{
			parseAndGenerate(std::move(exeDirectory), std::move(workingDirectory));
		}
		else
		{
			std::cerr << "Provided working directory is not a directory or doesn't exist" << std::endl;
			result = EXIT_FAILURE;
		}
	}
	//Use the current working directory if no argument specified
	else
	{
		parseAndGenerate(std::move(exeDirectory), fs::current_path());
	}

	return result;
}