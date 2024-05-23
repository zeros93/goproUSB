#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Write callback function to write the response data to a string
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t totalSize = size * nmemb;
    char **responsePtr = (char **)userp;

    // Reallocate memory to accommodate the new data
    *responsePtr = realloc(*responsePtr, strlen(*responsePtr) + totalSize + 1);
    if(*responsePtr == NULL) {
        printf("Not enough memory to allocate buffer\n");
        return 0;
    }

    // Append the new data to the response string
    strncat(*responsePtr, contents, totalSize);

    return totalSize;
}

int main(void) {
    CURL *curl;
    CURLcode res;
    char *response = malloc(1);
    response[0] = '\0'; // Initialize the response string

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://172.27.199.51:8080/gopro/camera/state");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Perform the request
        res = curl_easy_perform(curl);

        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Print the response
            printf("Response data: %s\n", response);
        }

        // Cleanup
        curl_easy_cleanup(curl);
    }

    free(response);
    curl_global_cleanup();

    return 0;
}
