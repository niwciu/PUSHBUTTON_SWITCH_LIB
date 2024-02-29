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


   // Cases where pushed button pass debounce phase and is in stable push state and than was released to call function on /short push release (short push done by user)
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeMaxPushTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual11);
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeMaxPushTimeWhenPushbuttonReleasedAndBouncingAndStableForDebounceTimeThenTestTimerEqual11);
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeMaxPushTimeWhenPushbuttonReleasedAndBouncingAndStableForTwiceDebounceTimeThenTestTimerEqual11);
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeLessThanMaxPushTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual11);
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeLessThanMaxPushTimeWhenPushbuttonReleasedAndBouncingAndStableForDebounceTimeThenTestTimerEqual11);
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForTimeLessThanMaxPushTimeWhenPushbuttonReleasedAndBouncingAndStableForTwiceDebounceTimeThenTestTimerEqual11);
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushBecomeStableWhenPushbuttonReleasedAndBouncingThenTestTimerEqual11);
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushBecomeStableWhenPushbuttonReleasedAndBouncingAndStableForDebounceTimeThenTestTimerEqual11);
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushBecomeStableWhenPushbuttonReleasedAndBouncingAndStableForTwiceDebounceTimeThenTestTimerEqual11);
   // Cases where pushed button didn't' pass debounce phase (short push done by disruption), and shouldnt call function on  short push or long push
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndNotStableWhenPushbuttonReleasedAndBouncingThenTestTimerEqual10);
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndNotStableWhenPushbuttonReleasedAndBouncingAndStableForDebounceTimeThenTestTimerEqual10);
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndNotStableWhenPushbuttonReleasedAndBouncingAndStableForTwiceDebounceTimeThenTestTimerEqual10);

   // Cases where pushed button pass debounce phase and is in stable push state and pushed long enough to reach long push state without repetition
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndShortenThanFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual9);
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndLongerThanFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual9);
   RUN_TEST_CASE(pushbutton_push_rel, GivenTestTimerEqual10AndKey1InitrAndNoRepetitionAndDecTimerFunctionRegisteredOnButtonReleaseAndIncFucnRegisteredOnButtonPushAndButton1PushedAndBouncingAndPushIsStableForLongerThanTimeMaxPushTimeAndLongerThanTwiceFirstRepetitionTimeWhenPushbuttonReleasedAndBouncingThenTestTimerEqual9);
   // Cases where pushed button pass debounce phase and is in stable push state and pushed long enough to reach long push state with repetition
     
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
