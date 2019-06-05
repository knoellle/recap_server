
// Include
#include "functions.h"
#include <chrono>
#include <ctime>
#include <filesystem>
#include <fstream>

// utils
namespace utils {
	uint64_t get_unix_time() {
		return std::chrono::milliseconds(std::time(nullptr)).count();
	}

	std::string get_file_text(const std::string& path) {
		std::filesystem::path fspath = path;
		std::ifstream stream(fspath.c_str(), std::ios::binary);
		if (stream.is_open()) {
			stream.seekg(0, std::ios::end);

			std::string str(stream.tellg(), '\0');
			stream.seekg(0, std::ios::beg);

			stream.read(&str[0], str.length());
			return str;
		} else {
			return "File " + path + " does not exist.";
		}
	}

	void string_replace(std::string& str, const std::string& old_str, const std::string& new_str) {
		auto position = str.find(old_str);
		if (position != std::string::npos) {
			str.replace(position, old_str.length(), new_str);
		}
	}

	std::vector<std::string> explode_string(const std::string& str, char delim, int32_t limit) {
		return detail::explode_string<const std::string&, char>(str, delim, limit);
	}

	std::vector<std::string> explode_string(const std::string& str, const std::string& delim, int32_t limit) {
		return detail::explode_string<const std::string&, const std::string&>(str, delim, limit);
	}

	std::vector<std::string_view> explode_string(std::string_view str, char delim, int32_t limit) {
		return detail::explode_string<std::string_view, char>(str, delim, limit);
	}

	std::vector<std::string_view> explode_string(std::string_view str, std::string_view delim, int32_t limit) {
		return detail::explode_string<std::string_view, std::string_view>(str, delim, limit);
	}
}
