#pragma once

#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>

namespace webhook {
	nlohmann::json send(std::string url, std::string content);
}


