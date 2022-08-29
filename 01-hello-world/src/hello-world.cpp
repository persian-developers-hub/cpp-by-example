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

#include <boost/json/serialize.hpp>
#include <boost/json/value.hpp>
#include <iostream>
#include <httplib.h>
#include <boost/json/src.hpp>

using namespace std;
using namespace boost;

int main()
{
    httplib::Server server;

    // simple text answer for '/hello' path
    server.Get("/hello", [](const httplib::Request &req, httplib::Response &resp) {
        resp.set_content("Hello World!", "text/plain");
    });

    // json answer for '/hello-json' path, also using passed param (if any)
    server.Get("/hello-json", [](const httplib::Request &req, httplib::Response &resp) {
        auto name = req.get_param_value("name");
        json::value hw = {
            { "hello", name.empty() ? "no name!" : name },
            { "name", "pdh" }
        };
        resp.set_content(json::serialize(hw), "application/json");
    });

    server.listen("0.0.0.0", 8080);

    return 0;
}
