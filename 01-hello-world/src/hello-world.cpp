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

/*
 * #include is a preprocessor directive. Effectively, the contents of the
 * speicified file (which is found in compiler's 'include path') is pasted here
 * completely.
 */

 // iostream is a standard header file providing some I/O facilities
#include <iostream>

// httplib is a thirdparty library and httplib.h is its main header
#include <httplib.h>

// Boost is a well-known third-party general purpose library consisting of many
// smaller libraries. Boost Json is a relatively new addition to the boost
// collection, however it is still not present in some GNU/Linux distros;
// e.g. Ubuntu. So, we use our own copy of it for now.
#include <boost/json/serialize.hpp>
#include <boost/json/value.hpp>

// src.hpp is only needed in a single file if we are not linking to boost json
// library
#include <boost/json/src.hpp>

/*
 * 'using namespace' brings all 'names' in a 'namespace' into the current
 * namespace, so that we can use their names without the namespace prefix,
 * e.g. we can use cout instead of std::cout.
 * Should be avoided in header files unless there is a good justification for it
 * which is almost never!
 */
using namespace std;

// Create a namespace alias, so that we can use 'json' rather than 'boost::json'
namespace json = boost::json;

/*
 * Normally, every C++ 'program' needs to have a 'main' function, which is
 * called at application startup by the OS.
 */
int main()
{
    // Define an object (variable) named 'server' of type 'httplib::Server',
    // which is 'Server' class in 'httplib' namespace.
    httplib::Server server;

    /*
     * Now, we call "member functions" (methods) of the "server" object.
     */

    // simple text answer for '/hello' path
    server.Get("/hello",
        // pass a lambda as handler for the given path
        [](const httplib::Request &req, httplib::Response &resp) {
            resp.set_content("Hello World!", "text/plain");
    });

    // json answer for '/hello-json' path, also using passed param (if any)
    server.Get("/hello-json", [](const httplib::Request &req,
                                    httplib::Response &resp) {

        // 'auto' in variable definition with assignemnt: let the compiler
        // automatically detect the type using the type of the assigned value
        auto name = req.get_param_value("name");

        // 'list initialization' of hw variable
        json::value hw = {
            { "hello", name.empty() ? "no name!" : name },
            { "name", "pdh" }
        };
        resp.set_content(json::serialize(hw), "application/json");
    });


    /*
     * 'cout' is the standard "character output" object provided by C++
     * 'endl' is an 'io manipulator' to print end line and flush output buffer
     * '<<' is actually C++ "left shift" operator; however it is "overloaded"
     * as an "output operator" in iostream library
     */
    cout << "Starting the service on port 8080..." << endl;

    // Run the web server (blocking)
    server.listen("0.0.0.0", 8080);

    // Return to OS with exit code '0', which means success
    return 0;
}
