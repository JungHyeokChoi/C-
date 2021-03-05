#include <chrono>
#include <ctime>
#include <sys/time.h>
#include <iostream>
#include <cstring>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>

#include "ActiveObjectEngine.h"
#include "SleepCommand.h"

using namespace CppUnit;
using namespace std;

class TestSleepCommand : public CppUnit :: TestFixture
{
    CPPUNIT_TEST_SUITE(TestSleepCommand);
    CPPUNIT_TEST(testSleepCommand);
    CPPUNIT_TEST_SUITE_END();
    
    protected:
        void testSleepCommand();
    
    private:
        SleepCommand *sleepCommand;
};

void TestSleepCommand :: testSleepCommand()
{
    Command *wakeUp = new Command();
    ActiveObjectEngine *e = new ActiveObjectEngine();
    SleepCommand *c = new SleepCommand(1000, e, wakeUp);
    
    e->AddCommand(c);

    time_t start = time(nullptr) * 1000;
    e->Run();
    time_t stop = time(nullptr) * 1000;

    long sleepTime = stop - start;

    CPPUNIT_ASSERT_ASSERTION_PASS_MESSAGE("SleepTime " + to_string(sleepTime) + " expected > 1000", sleepTime > 1000);
    CPPUNIT_ASSERT_ASSERTION_PASS_MESSAGE("SleepTime " + to_string(sleepTime) + " expected < 1100", sleepTime < 1100);
};


CPPUNIT_TEST_SUITE_REGISTRATION(TestSleepCommand);

int main(int argc, char* argv[])
{
    CPPUNIT_NS :: TestResult testResult;

    CPPUNIT_NS :: TestResultCollector collectedResults;
    testResult.addListener(&collectedResults);

    CPPUNIT_NS :: BriefTestProgressListener progress;
    testResult.addListener(&progress);
    CPPUNIT_NS :: TestRunner testRunner;
    testRunner.addTest(CPPUNIT_NS :: TestFactoryRegistry :: getRegistry().makeTest());
    testRunner.run(testResult);

    CPPUNIT_NS :: CompilerOutputter compileOutputter(&collectedResults, cerr);
    compileOutputter.write();

    return collectedResults.wasSuccessful() ? 0 : 1;
};