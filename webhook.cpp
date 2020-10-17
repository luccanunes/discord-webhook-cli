#include "webhook.h"
#include <cpr/cpr.h>
#include <iostream>

namespace webhook {
	void send(std::string url, std::string content) {
		cpr::Post(cpr::Url{ url }, cpr::Payload{ {"content", content} });
	}
}
