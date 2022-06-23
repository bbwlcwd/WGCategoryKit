//
//  DDViewController.m
//  WGCategoryKit
//
//  Created by apple_dboy on 06/21/2022.
//  Copyright (c) 2022 apple_dboy. All rights reserved.
//

#import "DDViewController.h"
#import "UMLog.h"


@interface DDViewController ()

@end

@implementation DDViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    NSString *version = [UMLogClient version];
    NSLog(@"log client version = %@", version);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
