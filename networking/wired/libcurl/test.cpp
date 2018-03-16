#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "curl/curl.h"

void download_pbc2(void)
{
    FILE *fd=0;
    CURL *curl=0;
    struct curl_slist *slist = NULL;

    std::string url;
    remove("./irrh-pbc2.swa");

    url.assign("scp://").append("10.21.3.33/").append("/home/selva/irrh-pbc2.swa");

    std::cout << url << std::endl;

    fd = fopen("./irrh-pbc2.swa","w");
    if( fd != NULL)
    {
        std::cout << "irrh-pbc2.swa open success " << std::endl;
        if((curl=curl_easy_init())!=NULL)
        {
            std::cout << "curl init success " << std::endl;

            curl_easy_setopt(curl, CURLOPT_TIMEOUT, 1000L); //secs - for large snapshot files on slow connections

            // CURLOPT_CONNECTTIMEOUT is not in conjunction with CURLOPT_TIMEOUT.
            // If set to 0secs, then the timeout is defaulted to 300secs.
            curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 0L);

            curl_easy_setopt(curl,CURLOPT_SSL_VERIFYHOST,0);
            curl_easy_setopt(curl,CURLOPT_SSL_VERIFYPEER,0);

            //Rate limit to 5Mbps, the below is in bytes
            curl_easy_setopt(curl, CURLOPT_MAX_RECV_SPEED_LARGE, (curl_off_t)625000LL);
            curl_easy_setopt(curl, CURLOPT_SSH_AUTH_TYPES, CURLSSH_AUTH_ANY);
            curl_easy_setopt(curl, CURLOPT_SSH_PUBLIC_KEYFILE, "~/.ssh/id_rsa.pub");
            curl_easy_setopt(curl, CURLOPT_SSH_PRIVATE_KEYFILE, "~/.ssh/id_rsa");
            curl_easy_setopt(curl, CURLOPT_USERNAME, "root");

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fd);
            curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

            curl_easy_setopt(curl,CURLOPT_INTERFACE,"eth0");

            CURLcode _err_num = curl_easy_perform(curl);
            if(_err_num!=CURLE_OK)
            {
                std::cout << "software update failed " << std::endl;
            }
            else
            {
                std::cout << "Download of the irrh-pbc2.swa successfully" << std::endl;
            }

            curl_easy_cleanup(curl);
            curl_slist_free_all(slist);
        }
        else
        {
            std::cout << "Curl init failure" << std::endl;
        }
    }
    else
    {
        std::cout << "File open failure " << std::endl;
    }

    if(fd) fclose(fd);
}

int main ( void )
{
    download_pbc2();
    return 0;
}
