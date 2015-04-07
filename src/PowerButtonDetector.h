//
//  PowerButtonDetector.h
//  BootManager
//
//  Created by Akira on 4/7/15.
//
//

#ifndef BootManager_PowerButtonDetector_h
#define BootManager_PowerButtonDetector_h

#include "ofMain.h"

static const string shutdonwScript = "osascript -e \'tell app \"System Events\" to shut down\'";

static void onPwrBtnPressed(CFNotificationCenterRef center,
                            void *observer,
                            CFStringRef name,
                            const void *object,
                            CFDictionaryRef userInfo)
{
    ofLog() << "Power Button Pressed";
    ofSystem(shutdonwScript);
}


class PowerButtonDetector : public ofThread
{
public:
    
    void setup()
    {
        state = INIT;
        startThread();
    }
    
    void exit()
    {
        waitForThread();
    }
    
protected:
    
    void threadedFunction()
    {
        while(isThreadRunning())
        {
            if (state == INIT && lock())
            {
                CFNotificationCenterRef distCenter;
                CFStringRef evtName = CFSTR("com.apple.shutdownInitiated");
                distCenter = CFNotificationCenterGetDistributedCenter();
                if (NULL == distCenter)
                    return 1;
                CFNotificationCenterAddObserver(distCenter, NULL, &onPwrBtnPressed, evtName, NULL, CFNotificationSuspensionBehaviorDeliverImmediately);
                CFRunLoopRun();
                state = RUN;
                unlock();
            }
        }
    }
    
private:
    
    enum STATE
    {
        INIT,
        RUN
    };
    STATE state;
};

#endif
