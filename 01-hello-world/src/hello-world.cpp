/**
 * @file hello-world.cpp
 * @author Hedayat Vatankhah (hedayat.fwd@gmail.com)
 * @brief Hello World!
 * @version 0.1
 * @date 2022-08-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <httplib.h>

using namespace std;

int main()
{
    httplib::Server server;

    server.Get("/hello", [](const httplib::Request &req, httplib::Response &resp) {
        resp.set_content("Hello World!", "text/plain");
    });

    server.listen("0.0.0.0", 8080);

    return 0;
}
