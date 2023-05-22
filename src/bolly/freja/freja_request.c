/*
 * Copyright (c) 2023 Netlore Team
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * This code is part of Freja (Network caller) Component
 * of Netlore project that can be found at the github
 * repository at:
 *  - https://github.com/netlore-org/netlore
 */

#include <netlore/bolly/freja/freja_request.h>

#include <netlore/netlore.h>

void
freja_network_init()
{
    curl_global_init(CURL_GLOBAL_ALL);

    NETLORE_DEBUG("successfully initialized curl");
}

size_t
write_memory(void *contents, size_t size, size_t nmemb, void* data)
{
    size_t rl_size = size * nmemb;

    chunk_t* mem = (chunk_t*)data;
    mem->memory = netlore_realloc(mem->memory, mem->size + rl_size + 1);

    memcpy(&(mem->memory[mem->size]), contents, rl_size);
    mem->size += rl_size;
    mem->memory[mem->size] = 0;

    return rl_size;
}

request_t*
freja_request_host(const char* url)
{
    NETLORE_DEBUG("requesting host at \"%s\"", url);

    CURL* curl = curl_easy_init();

    if (curl == NULL) 
    {
        NETLORE_ERROR("\"curl_easy_init\" failed.");
        return NULL;
    }

    // NOTE: function that calls this has to clean these
    chunk_t* response_chunk = netlore_calloc(1, sizeof(chunk_t));
    chunk_t* header_chunk   = netlore_calloc(1, sizeof(chunk_t));
    request_t* request = netlore_calloc(1, sizeof(request_t));

    // these will be reallocated on demand
    response_chunk->memory = malloc(1);
    header_chunk->memory = malloc(1);

    curl_easy_setopt(curl, CURLOPT_URL,            url);
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT,      "Netlore/" NETLORE_VERSION);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,  write_memory);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA,      (void*)response_chunk);
    curl_easy_setopt(curl, CURLOPT_HEADERDATA,     (void*)header_chunk);

    CURLcode curl_res = curl_easy_perform(curl);
    if (curl_res != CURLE_OK) 
    {
        NETLORE_ERROR_NO_EXIT("something gone wrong while requesting \"%s\"", url);
        return NULL;
    }

    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE,  &request->response_code);
    curl_easy_getinfo(curl, CURLINFO_HTTP_VERSION,   &request->http_version);
    curl_easy_getinfo(curl, CURLINFO_PRIMARY_IP,     &request->site_ip);

    request->response = response_chunk;
    request->header   = header_chunk;

    curl_easy_cleanup(curl);
    return request;
}
