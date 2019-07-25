
// Include
#include "functions.h"
#include <chrono>
#include <ctime>
#include <filesystem>
#include <fstream>

// utils
namespace utils {
	// Time
	uint64_t get_unix_time() {
		return std::chrono::milliseconds(std::time(nullptr)).count();
	}

	// Files
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

	// Strings
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

	// XML
	void xml_add_text_node(pugi::xml_node& node, const std::string& name, const std::string& value) {
		node.append_child(name.c_str()).append_child(pugi::node_pcdata).set_value(value.c_str());
	}

	std::string xml_get_text_node(const pugi::xml_node& node, const std::string& name) {
		return node.child(name.c_str()).text().get();
	}

	// JSON
	void json_add_text_to_object(rapidjson::Value& node, const std::string& label, const std::string& value, rapidjson::Document::AllocatorType& allocator) {
		node.AddMember(rapidjson::Value{}.SetString(label.c_str(), label.length(), allocator),
					   rapidjson::Value{}.SetString(value.c_str(), value.length(), allocator), 
					   allocator);
	}

	std::string json_document_to_string(const rapidjson::Document& document) {
		rapidjson::StringBuffer buffer;
		buffer.Clear();

		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
		document.Accept(writer);

		return buffer.GetString();
	}
}
