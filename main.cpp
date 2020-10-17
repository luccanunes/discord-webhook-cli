#include <iostream>
#include <cpr/cpr.h>
#include <vector>
#include <nlohmann/json.hpp>
#include <strim.h>
#include "webhook.h"

using json = nlohmann::json;

void sendAndRespond(std::string url, std::string message);

int main(int argc, char* argv[])
{
	if (argc == 1) {
		std::string url;
		std::cout << "Webhook url: ";
		std::cin >> url;
		std::string message;
		std::cout << "What message would you like to send? ";
		std::cin.ignore();
		std::getline(std::cin, message);

		sendAndRespond(url, message);
		return 0;
	}
	if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
		std::vector<std::string> commands = {
			"wh -------------------------- asks you step by step all the info it needs",
			"wh {url} {content} ---------- sends a message with {content} & {url}'s webhook",
		};
		for (std::string cmd : commands)
			std::cout << cmd << std::endl;
		return 0;
	}
	std::string url = argv[1];
	std::string message = "";
	for (int i = 2; i < argc; i++) {
		message += argv[i];
		message += " ";
	}
	sendAndRespond(url, message);

	return 0;
}

void sendAndRespond(std::string url, std::string message)
{
	json res = webhook::send(url, message);
	if (res.contains("message")) {
		std::cout << "[91mError: " << strim::replace(res["message"], "\"", "") << "[0m" << std::endl;
		std::cout << "[91mCode: " << res["code"] << "[0m" << std::endl;
		std::cout << "[33mFor more info about Discord Webhooks check https://github.com/luccanunes/discord-webhook-cli[0m" << std::endl;
	}
	else {
		std::cout << "[92mSucessfully sent message![0m" << std::endl;
	}
}