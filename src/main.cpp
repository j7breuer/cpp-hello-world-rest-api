
// Include crow and boost for basic functionality
#include "../lib/Crow/include/crow.h"

// Start app
int main() {
    crow::SimpleApp app;

    ///////////////////
    // GET ENDPOINTS //
    ///////////////////

    // General help endpoint
    CROW_ROUTE(app, "/help")
    ([]{
        crow::json::wvalue x;
        x["message"] = "This is an API meant to conduct basic translations between 2 languages and English using various transformer based language translation models.";
        return x;
    });

    // Single help endpoint
    CROW_ROUTE(app, "/help/single")
    ([]{
        crow::json::wvalue x;
        x["message"] = "Using models from the HuggingFace community, translate text via single calls between two languages via this API endpoint.";
        return x;
    });

    // Batch help endpoint
    CROW_ROUTE(app, "/help/batch")
    ([]{
        crow::json::wvalue x;
        x["message"] = "Using models from the HuggingFace community, translate text in batch between two languages via this API call.";
        return x;
    });

    // Languages endpoint
    CROW_ROUTE(app, "/help/languages")
    ([]{
        crow::json::wvalue x;
        x["message"] = "Languages Supported: ...";
        return x;
    });

    ////////////////////
    // POST ENDPOINTS //
    ////////////////////

    // Translate single
    CROW_ROUTE(app, "/translate/single").methods("POST"_method)
    ([](const crow::request& req){

        // Define request body as 'body'
        crow::json::rvalue body = crow::json::load(req.body);

        // Throw 400 if no body
        if (!body) {
            return crow::response(400);
        }

        // Set return json
        crow::json::wvalue x;
        x["message"] = "This is a single translation endpoint returning sample text.";

        // Return
        return crow::response{x};
    });

    // Run app
    app.port(8080).multithreaded().run();
}