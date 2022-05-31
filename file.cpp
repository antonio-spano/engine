#include "file.hpp"

File::File() { }

File::File(std::string filepath, FileMode filemode) : filepath(filepath), filemode(filemode) { }

void File::Append()
{
	this->Reset();
}

void File::Write()
{
	this->Reset();
}

void File::Set(std::string filepath)
{
	this->filepath = filepath;
}

void File::Set(FileMode filemode)
{
	this->filemode = filemode;
}

void File::Set(std::string filepath, FileMode filemode)
{
	this->filepath = filepath;
	this->filemode = filemode;
}

///This method clears the file's content.
void File::Clear()
{
	this->Write("");
}

///This method returns the file's content.
std::string File::GetContent()
{
	if (!this->open)
	{
		if (this->filemode == FileMode::Write)
		{
			return "";
		}
		this->open = true;
		this->file.open(this->filepath, std::ios::in);
	}

	std::stringstream filestream;
	std::string content;

	filestream << this->file.rdbuf();
	content = filestream.str();

	this->open = false;
	this->file.close();
	return content;
}

void File::Reset()
{
	this->open = false;
	this->file.close();
}

File::~File()
{
	this->file.close();
}