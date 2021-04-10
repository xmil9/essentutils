//
// essentutils tests
// Tests for time utilities.
//
// Apr-2021, Michael Lindner
// MIT license
//
#include "time_util_tests.h"
#include "time_util.h"
#include "test_util.h"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;


namespace
{
///////////////////

void testTimeMeasurementDefaultCtor()
{
   {
      const std::string caseLabel = "TimeMeasurement default ctor";

      esl::TimeMeasurement m;
      VERIFY(m.length() == 0, caseLabel);
   }
}


void testTimeMeasurementStartCtor()
{
   {
      const std::string caseLabel = "TimeMeasurement start ctor";

      esl::TimeMeasurement m{esl::TimeMeasurement::Start};
      VERIFY(m.started != esl::TimeMeasurement::Clock::time_point(), caseLabel);
   }
}


void testTimeMeasurementStart()
{
   {
      const std::string caseLabel = "TimeMeasurement::start";

      esl::TimeMeasurement m;
      m.start();
      VERIFY(m.started != esl::TimeMeasurement::Clock::time_point(), caseLabel);
   }
}


void testTimeMeasurementStop()
{
   {
      const std::string caseLabel = "TimeMeasurement::stop";

      esl::TimeMeasurement m{esl::TimeMeasurement::Start};
      std::this_thread::sleep_for(5ms);
      m.stop();

      VERIFY(m.stopped != esl::TimeMeasurement::Clock::time_point(), caseLabel);
      VERIFY(m.length() > 0, caseLabel);
   }
}


void testTimeMeasurementLength()
{
   {
      const std::string caseLabel = "TimeMeasurement::length for empty measurement";

      esl::TimeMeasurement m;
      VERIFY(m.length() == 0, caseLabel);
   }
   {
      const std::string caseLabel = "TimeMeasurement::length for measured time";

      esl::TimeMeasurement m{esl::TimeMeasurement::Start};
      std::this_thread::sleep_for(5ms);
      m.stop();

      VERIFY(m.length() > 0, caseLabel);
   }
   {
      const std::string caseLabel = "TimeMeasurement::length for non-default time unit";

      esl::TimeMeasurement m{esl::TimeMeasurement::Start};
      std::this_thread::sleep_for(5ms);
      m.stop();

      VERIFY(m.length<std::chrono::nanoseconds>() > m.length<std::chrono::seconds>(),
             caseLabel);
   }
}

} // namespace


///////////////////

void testTimeUtil()
{
   testTimeMeasurementDefaultCtor();
   testTimeMeasurementStartCtor();
   testTimeMeasurementStart();
   testTimeMeasurementStop();
   testTimeMeasurementLength();
}
