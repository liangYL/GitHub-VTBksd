//
//  STMapView.h
//  MapView
//
//  Created by steve on 14-8-27.
//  Copyright (c) 2014年 LiuGuojun. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import "XCAutoLayoutProtocol.h"

@protocol STMapViewDelegate;

@interface STMapView : UIView<MKMapViewDelegate,XCAutoLayoutProtocol>
{
    MKMapView *_mapView;
    __block UILabel *_addressLabel;
    __block id<STMapViewDelegate> _delegate;
}
@property (nonatomic,assign)id<STMapViewDelegate> delegate;
@property (nonatomic,copy) NSString *location;

@end

@protocol STMapViewDelegate <NSObject>
@optional

- (void)mapView:(MKMapView *)mapView didUpdateUserLocation:(MKUserLocation *)userLocation;
- (void)mapView:(MKMapView *)mapView didUpdateUserAddress:(CLPlacemark *)placemark;

@end
