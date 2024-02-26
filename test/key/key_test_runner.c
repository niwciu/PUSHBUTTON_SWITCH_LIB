#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(key)
{
   /* Test cases to run */
   RUN_TEST_CASE(key, WhenKey1InitThenKey1PinStateIsHigh);
}
