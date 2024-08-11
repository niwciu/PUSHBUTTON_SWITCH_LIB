#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(Switch)
{
    /* Test cases to run */
    RUN_TEST_CASE(Switch, WhenSwitchInitThenSwitchInputPinSetAsInput);
    RUN_TEST_CASE(Switch, GivenSwitchIsOffWhenSwitchInitThenInputSwitchStateEqualToSwitchOFF);
    RUN_TEST_CASE(Switch, GivenSwitchIsOffAndTestTimerEqual10AndSW1InitAndIncTimerFunctionRegisteredToSwOnAndSW1SwitchedOnAndBouncingWhenSW1StableForDebounceTimeThenTestTimerEqual11);
    RUN_TEST_CASE(Switch, GivenSwitchIsOffAndTestTimerEqual10AndSW1InitAndIncTimerFunctionRegisteredToSwOnAndSW1SwitchedOnAndBouncingWhenSW1StableForDebounceTimeMinus1ThenTestTimerEqual10);
    RUN_TEST_CASE(Switch, GivenSwitchIsOffAndTestTimerEqual10AndSW1InitAndIncTimerFunctionRegisteredToSwOnAndSW1SwitchedOnAndBouncingWhenSW1StableForDebounceTimePlus1ThenTestTimerEqual11);

    // Test when before iniw switch is in on state
    RUN_TEST_CASE(Switch, GivenSwitchIsOnWhenSwitchInitThenInputSwitchStateEqualToSwitchON);
    RUN_TEST_CASE(Switch, GivenSwitchIsONAndTestTimerEqual10AndSW1InitAndDecTimerFunctionRegisteredToSwOffAndSW1SwitchedOffAndBouncingWhenSW1StableForDebounceTimeThenTestTimerEqual9);
    RUN_TEST_CASE(Switch, GivenSwitchIsONAndTestTimerEqual10AndSW1InitAndDecTimerFunctionRegisteredToSwOffAndSW1SwitchedOffAndBouncingWhenSW1StableForDebounceTimeMinus1ThenTestTimerEqual9);
    RUN_TEST_CASE(Switch, GivenSwitchIsONAndTestTimerEqual10AndSW1InitAndDecTimerFunctionRegisteredToSwOffAndSW1SwitchedOffAndBouncingWhenSW1StableForDebounceTimePlus1ThenTestTimerEqual9);
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
