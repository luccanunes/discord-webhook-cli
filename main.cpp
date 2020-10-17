#include <iostream>
#include <cpr/cpr.h>
#include <vector>
#include "webhook.h"

int main(int argc, char* argv[])
{
	if ((argc > 1 && strcmp(argv[1], "-h") == 0) || (argc > 1 && strcmp(argv[1], "--help") == 0)) {
		std::vector<std::string> commands = {
			"wh --------------------------- asks you step by step all the info it needs"
			"wh {url} {content} ---------- sends a message with {content} & {url}'s webhook",
		};
		for (std::string cmd : commands)
			std::cout << cmd << std::endl;
		return 0;
	}
	if (argc == 1) {
		std::string url;
		std::cout << "Webhook url: ";
		/*std::cin >> url;
		std::string message;
		std::cout << "What message would you like to send? ";
		std::cin >> message;
		webhook::send(url, message);*/
	}
	/*std::string url = "https://discordapp.com/api/webhooks/767033414159171594/24bloSkc6IgEDRFhq4OzBblf7imqJIOM_RB_chsEs54YzEyIKHY_8rwlC12fjVB6dkAT";
	webhook::send(url, "como vai meu caro");*/

	return 0;
}