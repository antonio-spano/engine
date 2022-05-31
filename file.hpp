#pragma once
#include <fstream>
#include <string>
#include <sstream>

enum FileMode
{
	Read,
	Write,
	All
};

class File
{
private:
	std::string filepath;
	bool open = false;
	int filemode;

	void Append();
	void Write();
	void Reset();
public:
	File();
	File(std::string filepath, FileMode filemode);

	std::fstream file;

	template<typename T, typename... Types>
	void Append(T arg1, Types... args);

	template<typename T, typename... Types>
	void Write(T arg1, Types... args);

	void Set(std::string filepath);
	void Set(FileMode filemode);
	void Set(std::string filepath, FileMode filemode);

	void Clear();

	std::string GetContent();

	~File();
};

///This method appends text to a file.
template<typename T, typename... Types>
void File::Append(T arg1, Types... args)
{
	if (!this->open) //needed to not repeat the condition afterwards
	{
		if (this->filemode == FileMode::Read)
		{
			return;
		}
		this->open = true;
		this->file.open(this->filepath, std::ios::app);
	}

	this->file << arg1;
	this->Append(args...);
}

///This method overwrites a file's content.
template<typename T, typename... Types>
void File::Write(T arg1, Types... args)
{
	if (!this->open) //needed to not repeat the condition afterwards
	{
		if (this->filemode == FileMode::Read)
		{
			return;
		}
		this->open = true;
		this->file.open(this->filepath, std::ios::out);
	}

	this->file << arg1;
	this->Write(args...);
}