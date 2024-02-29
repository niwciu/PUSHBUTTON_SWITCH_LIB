#include "unity/fixture/unity_fixture.h"

TEST_GROUP_RUNNER(pushbutton)
{
   /* Test cases to run */
   RUN_TEST_CASE(pushbutton_push, WhenKey1InitThenKey1PinStateIsHigh);
   RUN_TEST_CASE(pushbutton_push, WhenKey2InitThenKey2PinStateIsHigh);
   RUN_TEST_CASE(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushedAndBouncingWhenPushStableForDebounceTimeThenTestTimerEqual1);
   RUN_TEST_CASE(pushbutton_push, GivenKey2InitAndIncTimerFunctionRegisteredAndKey2PushedAndBouncingWhenPushStableForDebounceTimeThenTestTimerEqual1);
   RUN_TEST_CASE(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushedAndBouncingWhenPushStableForMoreThanDebounceTimeThenTestTimerEqual1);
   RUN_TEST_CASE(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushedAndBouncingWhenPushStableForDebounceTimeMinus1ThenTestTimerEqual0);
   RUN_TEST_CASE(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedForFirstRepetitionDelayTimeThenTestTimerEqual2);
   RUN_TEST_CASE(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedForTimeFirstRepetitionTimeMinus1ThenTestTimerEqual1);
   RUN_TEST_CASE(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndBouncingAndTestTimerIncrementedOnceWhenKey1ContinueslyPushedLongerThanFirstRepetitionTimeButShorterThenSecondRepetitionShouldAccourThenTestTimerValueIs2);
   RUN_TEST_CASE(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeEqualToReachDoubleRepetitionThenTestTimerValueIs3);
   RUN_TEST_CASE(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeLessToReachTripleRepetitionThenTestTimerValueIs3);
   RUN_TEST_CASE(pushbutton_push, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeLongerToReachTripleRepetitionThenTestTimerValueIs4);

   RUN_TEST_CASE(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndReleaseAndBouncingWhenPinStateIsStableForDebounceTimeThenTestTimerEqual1);
   RUN_TEST_CASE(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndReleaseAndBouncingWhenPinStateIsStableForLessThanDebounceTimeThenTestTimerEqual0);
   RUN_TEST_CASE(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushAndReleaseAndPinBouncingThenTestTimerEqual0);
   RUN_TEST_CASE(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndReleaseAndBouncingWhenPinStayReleasedForPushButtonDebounceTimeThenTestTimerEqual1);
   RUN_TEST_CASE(pushbutton_release, GivenKey1InitAndIncTimerFunctionRegisteredAndKey1PushAndReleaseAndBouncingWhenPinStayReleasedForlongerThanPushButtonDebounceTimeThenTestTimerEqual1);
   
   RUN_TEST_CASE(pushbutton_push_rel, GivenKey1InitAndIncTimerFunctionRegisteredOnButtonReleaseAndButton1PushedAndReleasedWhenButtonStillBouncingThenThenTestTimerEqual0);
   RUN_TEST_CASE(pushbutton_push_rel, GivenKey1InitAndIncTimerFunctionRegisteredOnButtonReleaseAndButton1PushedAndReleasedWhenButtonStillBouncingThenThenTestTimerEqual0);   
   // RUN_TEST_CASE(pushbutton_push_rel, );
   // RUN_TEST_CASE(pushbutton_push_rel, );   
   // RUN_TEST_CASE(pushbutton_push_rel, );
   // RUN_TEST_CASE(pushbutton_push_rel, );   
   // RUN_TEST_CASE(pushbutton_push_rel, );
   // RUN_TEST_CASE(pushbutton_push_rel, );   
   // RUN_TEST_CASE(pushbutton_push_rel, );
   // RUN_TEST_CASE(pushbutton_push_rel, );   
   // RUN_TEST_CASE(pushbutton_push_rel, );
   // RUN_TEST_CASE(pushbutton_push_rel, );   
   // RUN_TEST_CASE(pushbutton_push_rel, );
   // RUN_TEST_CASE(pushbutton_push_rel, );   
   // RUN_TEST_CASE(pushbutton_push_rel, );
   // RUN_TEST_CASE(pushbutton_push_rel, );
}
