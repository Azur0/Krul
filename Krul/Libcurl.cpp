#include <iostream>
#include "Libcurl.h"
#include "curl/curl.h"

static size_t WriteCallback(void* buffer, size_t size, size_t nmemb, void* param)
{
	std::string& text = *static_cast<std::string*>(param);
	size_t totalsize = size * nmemb;
	text.append(static_cast<char*>(buffer), totalsize);

	return totalsize;
}

std::string makeCurlRequest(std::string url)
{
	std::unique_ptr<CURL, deleter> curl(curl_easy_init(), deleter());
	CURLcode response;
	std::string result;

	if (curl)
	{
		curl_easy_setopt(curl.get(), CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl.get(), CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl.get(), CURLOPT_WRITEDATA, &result);

		response = curl_easy_perform(curl.get());

		if (response != CURLE_OK)
		{
			std::cerr << "CURL error: " << response << "\n";
		}
	}

	return result;
}