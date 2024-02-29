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
   RUN_TEST_CASE(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeEqualToReachDoubleRepetitionThenTestTimerValueIs3);
   RUN_TEST_CASE(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeLessToReachDoubleRepetitionThenTestTimerValueIs2);
   RUN_TEST_CASE(pushbutton, GivenKey1InitAndIncTimerFunctionRegisteredWhenKey1PushForTimeLongerToReachDoubleRepetitionThenTestTimerValueIs3);

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
