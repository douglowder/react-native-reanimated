#if !TARGET_OS_TV
#import <CoreMotion/CoreMotion.h>
#endif

#import "ReanimatedSensorType.h"

@interface ReanimatedSensor : NSObject {
#if !TARGET_OS_TV
  ReanimatedSensorType _sensorType;
  double _interval;
  double _lastTimestamp;
  CMMotionManager *_motionManager;
  void (^_setter)(double[]);
#endif
}

- (instancetype)init:(ReanimatedSensorType)sensorType interval:(int)interval setter:(void (^)(double[]))setter;
- (bool)initialize;
- (bool)initializeGyroscope;
- (bool)initializeAccelerometer;
- (bool)initializeGravity;
- (bool)initializeMagnetometer;
- (bool)initializeOrientation;
- (void)cancel;

@end
