#include <curl/curl.h>

#include <iostream>

bool requestGet(char *fileName)
{
    CURL *curl;
    CURLcode res;
    FILE *fp;

    if ((fp = fopen(fileName, "w")) == NULL)
    {
        return 0;
    }
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Accept: Agent-dvpr");
    curl = curl_easy_init();
    if(curl){
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, headers);
        curl_easy_setopt(curl, CURLOPT_URL, "https://dvpr.me");
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, fp);
        res = curl_easy_perform(curl);
        if(res != 0){
            curl_slist_free_all(headers);
            curl_easy_cleanup(curl);
        }
        fclose(fp);
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    std::cout << "dvpr!";
    requestGet("/tmp/dvpr");
    return 0;
}