#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(Switch)
{
   /* Test cases to run */
   RUN_TEST_CASE(Switch, WhenSwitchInitThenSwitchInputPinSetAsInput);
   RUN_TEST_CASE(Switch, GivenSwitchIsOffWhenSwitchInitThenInputSwitchStateEqualToSwitchOFF);
   RUN_TEST_CASE(Switch, GivenSwitchIsOnAndSW1InitAndIncTimerFunctionRegisteredToSwOnAndSW1SwitchedOnAndBouncingWhenSW1StableForDebounceTimeThenTestTimerEqual1);
   
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
   // RUN_TEST_CASE(Switch, );

}
