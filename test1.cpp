
#include <iostream>
#include <string>
#include <Poco/JSON/JSON.h>
#include <Poco/JSON/Parser.h>
#include <Poco/Dynamic/Var.h>
#include <gtest/gtest.h>

using namespace std;
using namespace Poco::JSON;

int GetValue(Object::Ptr aoJsonObject, const char *aszKey) {
    Poco::Dynamic::Var loVariable;
    string lsKey(aszKey);

    loVariable = aoJsonObject->get(lsKey);

    return loVariable.convert<int>();
}

TEST(poco, json) {
  string lsJson;
  Parser loParser;

    lsJson = "{\"test\":5}";

    cout << lsJson << endl;

    // Parse the JSON and get the Results
    //
    Poco::Dynamic::Var loParsedJson = loParser.parse(lsJson);
    Poco::Dynamic::Var loParsedJsonResult = loParser.result();

    // Get the JSON Object
    //
    Object::Ptr loJsonObject = loParsedJsonResult.extract<Object::Ptr>();

    // Get the values for the member variables
    //
    //
    ASSERT_TRUE(5 == GetValue(loJsonObject, "test"));
}

