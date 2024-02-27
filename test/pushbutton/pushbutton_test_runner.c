#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(pushbutton)
{
   /* Test cases to run */
   RUN_TEST_CASE(pushbutton, WhenKey1InitThenKey1PinStateIsHigh);
   RUN_TEST_CASE(pushbutton, WhenKey2InitThenKey2PinStateIsHigh);
   RUN_TEST_CASE(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndPinStateIsStableForDebounceTimeThenChangeIncTestTimer);
   RUN_TEST_CASE(pushbutton, GivenKey2InitAndIncTimerFunctionRegisteredWhenKey2PushAndPinStateIsStableForDebounceTimeThenChangeIncTestTimer);
   RUN_TEST_CASE(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndSignalisBouncingWhenSignalIsStableExactlyDefinedTimeThenTestTimerIsIncOnlyOnce);
   RUN_TEST_CASE(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndSignalisBouncingWhenSignalIsStableLongerThenDefinedTimeThenTestTimerIsIncOnlyOnce);
   RUN_TEST_CASE(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndSignalisBouncingWhenSignalIsStableLessByOneThenDefinedTimeThenTestTimerIsNotInc);
   RUN_TEST_CASE(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedAndFirstRepetitionDelayPassThenTestTimerValueIs2);
   RUN_TEST_CASE(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedForTimeLessThenFirstRepetitionTimeThenTestTimerValueIs1);
   RUN_TEST_CASE(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedForTimeLongerThenFirstRepetitionDelayButShorterThenSecondRepetitionShouldAccourThenTestTimerValueIs2);
   // RUN_TEST_CASE(pushbutton, );
   // RUN_TEST_CASE(pushbutton, );
   // RUN_TEST_CASE(pushbutton, );
   // RUN_TEST_CASE(pushbutton, );
   // RUN_TEST_CASE(pushbutton, );
   // RUN_TEST_CASE(pushbutton, );
   // RUN_TEST_CASE(pushbutton, );
}
