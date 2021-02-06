//
// essentutils tests
// Tests for observable support.
//
// Feb-2021, Michael Lindner
// MIT license
//
#include "observed_tests.h"
#include "observed.h"
#include "test_util.h"

using namespace sutil;


namespace
{
///////////////////

struct MockSource : public Observed<MockSource>
{
   explicit MockSource(int id_) : id{id_} {}
   int id = 0;
};


struct EventData : public ObservedEventData
{
   explicit EventData(int v) : val{v} {}
   int val = 0;
};


struct SimpleObserver
{
   int srcId = 0;
   std::string eventId;
   int dataVal = 0;

   void onNotified(MockSource& src, std::string_view eventId_,
                   const ObservedEventData& data)
   {
      srcId = src.id;
      eventId = eventId_;
      dataVal = static_cast<const EventData&>(data).val;
   }
};


///////////////////

void testNotifyingOneObserver()
{
   SimpleObserver observer;

   MockSource observed{1};
   observed.addObserver([&observer](MockSource& src, std::string_view eventId_,
                                    const ObservedEventData& data) {
      observer.onNotified(src, eventId_, data);
   });

   observed.notify(observed, "test", EventData{100});

   const std::string caseLabel = "NotifyingOneObserver";
   VERIFY(observer.srcId == observed.id, caseLabel);
   VERIFY(observer.eventId == "test", caseLabel);
   VERIFY(observer.dataVal == 100, caseLabel);
}


void testNotifyingMultipleObserver()
{
   SimpleObserver obs[3];

   MockSource observed{1};
   observed.addObserver(
      [&obs](MockSource& src, std::string_view eventId_, const ObservedEventData& data) {
         obs[0].onNotified(src, eventId_, data);
      });
   observed.addObserver(
      [&obs](MockSource& src, std::string_view eventId_, const ObservedEventData& data) {
         obs[1].onNotified(src, eventId_, data);
      });
   observed.addObserver(
      [&obs](MockSource& src, std::string_view eventId_, const ObservedEventData& data) {
         obs[2].onNotified(src, eventId_, data);
      });

   observed.notify(observed, "test", EventData{100});

   const std::string caseLabel = "NotifyingMultipleObserver";
   for (const auto& ob : obs)
   {
      VERIFY(ob.srcId == observed.id, caseLabel);
      VERIFY(ob.eventId == "test", caseLabel);
      VERIFY(ob.dataVal == 100, caseLabel);
   }
}

} // namespace


///////////////////

void testObserved()
{
   testNotifyingOneObserver();
   testNotifyingMultipleObserver();
}
