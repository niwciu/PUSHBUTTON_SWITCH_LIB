#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(Switch)
{
   /* Test cases to run */
   RUN_TEST_CASE(Switch, GivenSwitchIsOffWhenSwitchInitThenInputSwitchStateEqualToSwitchOFF);
   RUN_TEST_CASE(Switch, GivenSwitchIsOnWhenSwitchInitThenInputSwitchStateEqualToSwitchON);
   RUN_TEST_CASE(Switch, GivenSW1InitAndIncTimerFunctionRegisteredToSwOnAndSW1SwitchedOnAndBouncingWhenSW1StableForDebounceTimeThenTestTimerEqual1);
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );
   // RUN_TEST_CASE(Switch, );

}
