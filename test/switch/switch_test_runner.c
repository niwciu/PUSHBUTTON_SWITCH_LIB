#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(Switch)
{
   /* Test cases to run */
   RUN_TEST_CASE(Switch, WhenSwitchInitThenSwitchInputPinSetAsInput);
   RUN_TEST_CASE(Switch, GivenSwitchIsOffWhenSwitchInitThenInputSwitchStateEqualToSwitchOFF);
   RUN_TEST_CASE(Switch, GivenSwitchIsOffAndSW1InitAndIncTimerFunctionRegisteredToSwOnAndSW1SwitchedOnAndBouncingWhenSW1StableForDebounceTimeThenTestTimerEqual1);
   RUN_TEST_CASE(Switch, GivenSwitchIsOffAndSW1InitAndIncTimerFunctionRegisteredToSwOnAndSW1SwitchedOnAndBouncingWhenSW1StableForDebounceTimeMinus1ThenTestTimerEqual0);

   //Test when before iniw switch is in on state
   RUN_TEST_CASE(Switch, GivenSwitchIsOnWhenSwitchInitThenInputSwitchStateEqualToSwitchON);
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
