#include "webhook.h"
#include <iostream>
#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

namespace webhook {
	json send(std::string url, std::string content) {
		cpr::Response res = cpr::Post(cpr::Url{ url }, cpr::Payload{ {"content", content} });

		json json;
		if (res.text.length() != 0) {
			json = json::parse(res.text);
		}
		return json;
	}
}
