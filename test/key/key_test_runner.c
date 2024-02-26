#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(key)
{
   /* Test cases to run */
   RUN_TEST_CASE(key, WhenKey1InitThenKey1PinStateIsHigh);
   RUN_TEST_CASE(key, WhenKey2InitThenKey2PinStateIsHigh);
   RUN_TEST_CASE(key, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndPinStateIsStableForDebounceTimeThenChangeIncTestTimer);
   // RUN_TEST_CASE(key, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndIncTestTimerexecutedWhenPinStateHighandcheckKeyPushThenkeyDebounceTimerEqualKeyDebounceTime);
   // RUN_TEST_CASE(key, );
   // RUN_TEST_CASE(key, );
   // RUN_TEST_CASE(key, );
   // RUN_TEST_CASE(key, );
   // RUN_TEST_CASE(key, );
   // RUN_TEST_CASE(key, );
}
